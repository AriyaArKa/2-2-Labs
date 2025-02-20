package org.example.database_javafx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.sql.*;



public class HelloApplication extends Application {

    private static final String DB_URL = "jdbc:mysql://localhost:3307/userdb";
    private static final String DB_USER = "root";  // Replace with your MySQL username
    private static final String DB_PASSWORD = "nDc11705039!"; // Replace with your MySQL password

    private TextField nameField;
    private TextField emailField;
    private TextArea resultArea;
    @Override
    public void start(Stage stage) throws IOException {
        stage.setTitle("JavaFX MySQL Example");

        // UI Components
        Label nameLabel = new Label("Name:");
        nameField = new TextField();

        Label emailLabel = new Label("Email:");
        emailField = new TextField();

        Button insertButton = new Button("Insert");
        Button fetchButton = new Button("Fetch");
        Button loginButton = new Button("Login");
        Button deleteButton = new Button("Delete");

        resultArea = new TextArea();
        resultArea.setEditable(false);

        insertButton.setOnAction(e -> insertData());
        fetchButton.setOnAction(e -> fetchData());
        loginButton.setOnAction(e -> login());
        deleteButton.setOnAction(e -> deleteUser());

        VBox layout = new VBox(10);
        layout.setStyle("-fx-padding: 20;");
        layout.getChildren().addAll(nameLabel, nameField, emailLabel, emailField, insertButton, fetchButton, loginButton,deleteButton,resultArea);

        stage.setScene(new Scene(layout, 400, 400));
        stage.show();
    }

    public static void main(String[] args) {

        launch();
    }

    private void insertData() {
        String name = nameField.getText();
        String email = emailField.getText();

        if (name.isEmpty() || email.isEmpty()) {
            resultArea.setText("Name and Email must not be empty!");
            return;
        }

        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String query = "INSERT INTO users (username, password) VALUES (?, ?)";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, name);
            statement.setString(2, email);

            int rows = statement.executeUpdate();
            resultArea.setText(rows + " row(s) inserted successfully!");
        } catch (SQLException e) {
            resultArea.setText("Error: " + e.getMessage());
        }
    }
    private void fetchData() {
        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String query = "SELECT * FROM users";
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query);

            StringBuilder results = new StringBuilder();
            while (resultSet.next()) {
                results.append("ID: ").append(resultSet.getInt("id")).append(", ")
                        .append("Name: ").append(resultSet.getString("username")).append(", ")
                        .append("Email: ").append(resultSet.getString("password")).append("\n");
            }
            resultArea.setText(results.toString());
        } catch (SQLException e) {
            resultArea.setText("Error: " + e.getMessage());
        }
    }
    private void login() {
        String email = emailField.getText(); // Use the emailField for login
        String password = nameField.getText(); // Repurpose nameField for password input

        if (email.isEmpty() || password.isEmpty()) {
            resultArea.setText("Email and Password must not be empty!");
            return;
        }

        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            String query = "SELECT * FROM users WHERE username = ? AND password = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, email);
            statement.setString(2, password);

            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                resultArea.setText("Login successful! Welcome, " + resultSet.getString("username") + "!");
            } else {
                resultArea.setText("Invalid email or password.");
            }
        } catch (SQLException e) {
            resultArea.setText("Error: " + e.getMessage());
        }
    }

    private void deleteUser() {
        String email = emailField.getText(); // Use emailField for email input
        String password = nameField.getText(); // Use nameField for password input

        if (email.isEmpty() || password.isEmpty()) {
            resultArea.setText("Email and Password must not be empty!");
            return;
        }

        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD)) {
            // Query to delete user where email and password match
            String query = "DELETE FROM users WHERE username = ? AND password = ?";
            PreparedStatement statement = connection.prepareStatement(query);
            statement.setString(1, email);
            statement.setString(2, password);

            int rowsDeleted = statement.executeUpdate(); // Execute delete query

            if (rowsDeleted > 0) {
                resultArea.setText("User deleted successfully!");
            } else {
                resultArea.setText("Invalid email or password. No user deleted.");
            }
        } catch (SQLException e) {
            resultArea.setText("Error: " + e.getMessage());
        }
    }


}