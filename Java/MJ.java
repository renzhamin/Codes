import java.sql.Connection;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;


class HelloWorld {
    public static void main(String[] args) {
        String userName,password,url,driver,sqlQuery;

        //-------------User Login Information---------------------------------------\\
        userName="monty";
        password="pass";
        //--------------------------------------------------------------------------\\


        //----------JDBC Driver-------------------------------------------------------\\
        url="jdbc:mariadb://localhost:3306/mydb";
        driver="org.mariadb.jdbc.Driver";
        //         driver = "oracle.jdbc.driver.OracleDriver";
        //         url = "jdbc:oracle:thin:@//localhost:1521/orclpdb";
        //----------------------------------------------------------------------------\\

        //----------Connection And Statement variables--------------------------------\\
        Connection con;
        Statement st;
        //----------------------------------------------------------------------------\\


        try {
            Class.forName(driver); //Registering the driver

            //----------Creating the connection-------------------------------------------\\
            con=DriverManager.getConnection(url, userName, password);
            st=con.createStatement();
            //----------------------------------------------------------------------------\\

            //             ResultSet QueryResult=st.executeQuery("select count(*) from ACCOUNT;");
            ResultSet QueryResult=st.executeQuery("select * from Student");
            QueryResult.next();
//             ResultSetMetaData rsmd=QueryResult.getMetaData();
//             for(int i = 1; i <= rsmd.getColumnCount(); i++) {
//                 System.out.print(rsmd.getColumnName(i));
//                 System.out.println(" " + rsmd.getColumnTypeName(i));
//             }
            int totalAccounts=QueryResult.getInt(1);
            QueryResult.close();

        } 

        catch (Exception e) {
            e.printStackTrace(); // printing the error messege
        }
    }

}
