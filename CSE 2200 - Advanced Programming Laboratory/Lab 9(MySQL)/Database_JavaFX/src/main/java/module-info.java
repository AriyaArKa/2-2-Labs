module org.example.database_javafx {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens org.example.database_javafx to javafx.fxml;
    exports org.example.database_javafx;
}