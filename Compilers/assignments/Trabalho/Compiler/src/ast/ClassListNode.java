package ast;

import compiler.Token;

public class ClassListNode extends GenericNode
{
    public List<ClassDeclNode> classList = new List<ClassDeclNode>();
    
    public ClassListNode(Token t, List<ClassDeclNode> cl)
    {
        super(t);
        classList = cl;
    }
}
