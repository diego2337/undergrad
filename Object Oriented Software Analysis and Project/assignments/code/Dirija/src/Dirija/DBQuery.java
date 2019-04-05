/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Jainor
 */
public class DBQuery 
{
    private Statement queryStream;
    private Connection repos;
    private ResultSet lastExecutedQueryResult;
    // CONSTRUTOR
    DBQuery(Connection con)
    {
        try
        {   
            setRepos(con);
            setQueryStream(con.createStatement());
            //System.out.println("Stream de consultas criada com sucesso!");
    
        }   catch(SQLException ex) 
            {
                Logger lgr = Logger.getLogger(Dirija.class.getName());
                lgr.log(Level.SEVERE, ex.getMessage(), ex);
            }
    }
    
    public String checkQuery(String query)
    {
        String type = "";
        int i = 0;
        while(query.charAt(i) != ' ')
        {
            type = type + query.charAt(i);
            i++;
        }
        
        
        return type;
    }
    
    public void runSELECT(Statement queryStream, String query)
    {
        ResultSet result = null;
        
        try
        {
             result = queryStream.executeQuery(query);
             
        }   catch(SQLException ex) 
            {
                Logger lgr = Logger.getLogger(Dirija.class.getName());
                lgr.log(Level.SEVERE, ex.getMessage(), ex);
            }
        
        setLastExecutedQueryResult(result);
        printQueryResult(result);
    }
    
    public void runUPDATE(Statement queryStream, String query)
    {
        try
        {
            queryStream.executeUpdate(query);
        }   catch(SQLException ex) 
            {
                Logger lgr = Logger.getLogger(Dirija.class.getName());
                lgr.log(Level.SEVERE, ex.getMessage(), ex);
            }
        
        
    }
    
    public void runSQL(String query)
    {
        
            String type = checkQuery(query);
       
            if(!type.equals("SELECT"))
                runUPDATE(getQueryStream(), query);
               
            else
                runSELECT(getQueryStream(), query);
             
         
    }
    
    static ResultSetMetaData retMetaData(ResultSet results)
    {
        ResultSetMetaData ret = null;
        try
        {
             ret = results.getMetaData();
    
        }   catch(SQLException ex)
            {
                System.out.println("deu pau, cara");
            }
        return ret;
    }
    
    
    public void printQueryResult(ResultSet queryResult)
    {
        try
        {   
            int numberOfColumns = retMetaData(queryResult).getColumnCount();
            while(queryResult.next())
            {
                for(int i = 1; i <= numberOfColumns; i++)
                {
                    if(i > 1)
                        System.out.print(", ");
                    System.out.print(retMetaData(queryResult).getColumnName(i) + 
                                        ": " + queryResult.getString(i));
                    if(i == numberOfColumns)
                        System.out.println("");
                
                }    
            }
        }   catch(SQLException ex) 
            {
                Logger lgr = Logger.getLogger(Dirija.class.getName());
                lgr.log(Level.SEVERE, ex.getMessage(), ex);
            }
    }
    
    public String[][] retLastQueryResult()
    {
        String[][] str = null;
        int rows = 0;
        if(this.contemTuplas())
        {
            try
            {
                lastExecutedQueryResult.beforeFirst();
                int numberOfColumns = retMetaData(lastExecutedQueryResult).getColumnCount();
                while(lastExecutedQueryResult.next())
                {
                    rows++;
                }
                lastExecutedQueryResult.beforeFirst();
                str = new String[numberOfColumns][rows];
                int j = 0;
                while(lastExecutedQueryResult.next())
                {
                    for(int i = 1; i <= numberOfColumns; i++)
                    {
                        str[i-1][j] = lastExecutedQueryResult.getString(i);
                    }    
                    j++;
                }
    //            for(int i = 0; i < numberOfColumns; i++)
    //            {
    //                for(j = 0; j < rows; j++)
    //                {
    //                    System.out.print(str[i][j]);
    //                    System.out.print(" ");
    //                }
    //                System.out.print("\n");
    //            }
            }
            catch(SQLException ex)
            {
                return null;
            }
        }
        return str;
    }
    
    public boolean contemTuplas()
    {
        boolean b = false;
        try
        {
            lastExecutedQueryResult.beforeFirst();
            if(lastExecutedQueryResult.isBeforeFirst())
            {
                b = true;
                lastExecutedQueryResult.first();
            }
        }
        catch(SQLException ex)
        {
            b = false;
        }
        return b;
    }
    
    
    
    // GETTERS AND SETTERS
    public Statement getQueryStream() 
    {
        return this.queryStream;
    }

    public void setQueryStream(Statement queryStream) 
    {
        this.queryStream = queryStream;
    }
    
    public Connection getRepos()
    {
        return this.repos;
    }
    
    public void setRepos(Connection repos)
    {
        this.repos = repos;
    }

    public ResultSet getLastExecutedQueryResult() 
    {
        return lastExecutedQueryResult;
    }

    public void setLastExecutedQueryResult(ResultSet lastExecutedQuery) 
    {
        this.lastExecutedQueryResult = lastExecutedQuery;
    }
 
    
    
    
}