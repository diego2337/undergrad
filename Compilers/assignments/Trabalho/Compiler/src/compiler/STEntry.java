package compiler;

public class STEntry 
{
    public Token token;
    public String lexeme;
    public boolean reserved;
    
    public STEntry()
    {}
    
    public STEntry(Token tok, String lex)
    {
        token = tok;
        lexeme = lex;
        reserved = false;
    }
    
    public STEntry(Token tok, String lex, boolean res)
    {
        token = tok;
        lexeme = lex;
        reserved = res;
    }
}