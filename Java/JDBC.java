import java.sql.Connection;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.ResultSet;


class HelloWorld {
    public static void main(String[] args) {

        //------Conditions for different Categories-------------------------------------\\
        String CIP_BAL_MIN="1000000";
        String CIP_TOTAL_MIN="5000000"; 

        String VIP_BAL_MIN="500000";
        String VIP_BAL_MAX="900000";
        String VIP_TOTAL_MIN="3500000";
        String VIP_TOTAL_MAX="4500000";

        String ORD_BAL_MAX="40000";
        String ORD_TOTAL_MAX="3000000";
        //--------------------------------------------------------------------------------\\


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

            //----------Getting total number of Accounts----------------------------------\\
            ResultSet QueryResult=st.executeQuery("select count(*) from ACCOUNT;");
            QueryResult.next();
            int totalAccounts=QueryResult.getInt(1);
            QueryResult.close();
            //----------------------------------------------------------------------------\\

            //----------Conditions applied in sql-----------------------------------------\\
            String Cond_CIP=String.format("T.balance>%s and T.total>%s",CIP_BAL_MIN,CIP_TOTAL_MIN);
            String Cond_VIP=String.format("T.balance>%s and T.balance<%s and T.total>%s and T.total<%s",VIP_BAL_MIN,VIP_BAL_MAX,VIP_TOTAL_MIN,VIP_TOTAL_MAX);
            String Cond_ORD=String.format("T.balance<%s and T.total<%s", ORD_BAL_MAX,ORD_TOTAL_MAX);
            //----------------------------------------------------------------------------\\


            //---------Calling the function with statement and condition------------------\\
            int CIP=getCount(st,Cond_CIP);
            int VIP=getCount(st,Cond_VIP);
            int ORD=getCount(st,Cond_ORD);
            //----------------------------------------------------------------------------\\

            //---------Closing statement and connection-----------------------------------\\
            st.close();
            con.close();
            //----------------------------------------------------------------------------\\

            System.out.printf("Total Number of Accounts : %d\n", totalAccounts);
            System.out.printf("CIP count : %d\n",CIP);
            System.out.printf("VIP count : %d\n",VIP);
            System.out.printf("Ordinary count : %d\n",ORD);
            System.out.printf("Uncategorized : %d\n",totalAccounts-(CIP+VIP+ORD));

        } 

        catch (Exception e) {
            System.out.println("shippai"); 
            e.printStackTrace(); // printing the error messege
        }
    }

    public static int getCount(Statement st,String conditions){
        int ans=0;
        //         String sqlQuery="select count(*) ans from (select A_ID,sum(AMOUNT) total,sum(case when TYPE=0 then AMOUNT else -AMOUNT end) balance from TRANSACTIONS group by A_ID) T where " + conditions;
        // -------------Making Table T with necessary info--------------------------------\\
        String Query="""
            SELECT COUNT(*) ans FROM (
                    SELECT A_ID,
                    SUM(AMOUNT) total,
                    SUM(case when TYPE=0 then AMOUNT else -AMOUNT end) balance
                    FROM TRANSACTIONS
                    group by A_ID) T WHERE 
            """;
        // total column   = The total amount of money transferred
        // balance column = The final amount of money available in an account after all transactions
        //----------------------------------------------------------------------------\\

        Query += conditions; // adding the conditions to the query

        try {
            ResultSet QueryResult = st.executeQuery(Query);
            QueryResult.next(); // there is only one row
            ans = QueryResult.getInt("ans");
            QueryResult.close();
        } 

        catch (Exception e) {
            System.out.println("Error executing Query");
            e.printStackTrace();
        }

        return ans;
    }
}
