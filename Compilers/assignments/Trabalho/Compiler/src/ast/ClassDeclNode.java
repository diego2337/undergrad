package ast;

import compiler.Token;

public class ClassDeclNode extends GenericNode
{
    //public String name;
    public String superName;
    public ClassDeclLineNode decline;
    
    public ClassDeclNode(Token t,/* String t2,*/ String t3, ClassDeclLineNode c)
    {
        super(t);
        //name = t2;
        superName = t3;
        decline = c;
    }
}
