package ast;

import compiler.Token;

public abstract class GenericNode 
{
    public Token position;
    
    public GenericNode(Token t)
    {
        position = t;
    }
}
