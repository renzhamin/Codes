import java.sql.*;


class JDBCTest {
    public static void main(String[] args) {
        String userName,password,url,driver;
        Connection con;
        Statement st;

        userName = "boltu";
        password = "mair";
        driver = "oracle.jdbc.driver.OracleDriver";
        url = "jdbc:oracle:thin:@//localhost:1521/orclpdb";
        
        // again if your pluggable database name is different than replace orclpdb with that


        try {
            Class.forName(driver);
            con=DriverManager.getConnection(url, userName, password);
            st=con.createStatement();
            
            ResultSet res=st.executeQuery("select count(*) from dummy");
            res.next();
            int noOfRecords=res.getInt(1);
            res.close();
            st.close();
            con.close();

            System.out.println(noOfRecords);
            
        } 
        catch (Exception e) {

        }
    }
}

