package mariadb;
import java.sql.*;

class HelloWorld {
    public static void main(String[] args) {
        String userName,password,url,driver;
        Connection con;
        Statement st;
        userName="monty";
        password="pass";
        url="jdbc:mariadb://localhost:3306/stud";
        driver="org.mariadb.jdbc.Driver";
        try {
            Class.forName(driver);
            con=DriverManager.getConnection(url, userName, password);
            st=con.createStatement();
            System.out.println("Connection is successful");
        } catch (Exception e) {
            e.printStackTrace();
        }


    }
}

// public class Demu {
//     String userName,password,url,driver;
//     Connection con;
//     Statement st;
// 
//     public void ConnectionDemo() {
//         userName="monty";
//         password="pass";
//         url="jdbc:mariadb://localhost:3306/stud";
//         driver="org.mariadb.jdbc.Driver";
//         try {
//             Class.forName(driver);
//             con=DriverManager.getConnection(url, userName, password);
//             st=con.createStatement();
//             System.out.println("Connection is successful");
//         } catch (Exception e) {
//             e.printStackTrace();
//         }
//     }
// }
