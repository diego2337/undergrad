package ast;

import compiler.Token;

public class ClassBodyNode extends GenericNode
{
    public List<VarDeclNode> variableList;
    public List<ConstructorDeclNode> constructorList;
    public List<MethodDeclNode> methodList;
    
    public ClassBodyNode(Token t, List<VarDeclNode> vl, List<ConstructorDeclNode> cl, 
    		List<MethodDeclNode> ml)
    {
        super(t);
        variableList = vl;
        constructorList = cl;
        methodList = ml;
    }
}