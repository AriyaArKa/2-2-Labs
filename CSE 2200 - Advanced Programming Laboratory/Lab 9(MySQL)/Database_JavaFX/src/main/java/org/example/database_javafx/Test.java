package org.example.database_javafx;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Test {
    public static void main(String[] args) {
        System.out.println(System.getProperty("java.class.path"));
        String url = "jdbc:mysql://localhost:3307/userdb";
        String user = "root";  // Replace with your username
        String password = "nDc11705039!";  // Replace with your password

        try {
            Connection conn = DriverManager.getConnection(url, user, password);
            System.out.println("Connection successful!");
        } catch (SQLException e) {
            System.err.println("Error: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
