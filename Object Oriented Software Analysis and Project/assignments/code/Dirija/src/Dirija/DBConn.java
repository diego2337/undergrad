/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Scanner;

/**
 *
 * @author jainor
 */
public class DBConn 
{
    static String user = "root";
    static String pass = "morenaossw";
    static String DBloc = "jdbc:mysql://localhost/Dirija";
    
    // 2 argument constructor
    DBConn()
    {
      //System.out.println("Objeto de conexão com o BD instanciado.");
    }
    
    
    // método que abrirá a conexão com o BD
    public Connection openConn()
    {
        Connection con = null;
        try 
        {
                con = DriverManager.getConnection(DBloc, user, pass);
        
        }   catch(SQLException ex) 
            {
               Logger lgr = Logger.getLogger(Dirija.class.getName());
               lgr.log(Level.SEVERE, ex.getMessage(), ex);
            }
        
        if(con == null)
        {
            System.out.println("Houve um erro na abertura da conexão ao banco"
                    + " de dados " + DBConn.DBloc);
            System.exit(1);
        }
        return con;
    }
    
    // método que fecha a conexão criada por openConn
    public void closeConn(Connection con)
    {
        try
        {
            if(con != null)
                con.close();
        
        }   catch(SQLException ex)
            {
                System.out.println("Houve um problema de código " + 
                        ex.getErrorCode() + " no estado " + ex.getSQLState());
            }
    }
}
