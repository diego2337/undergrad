package ast;

import compiler.Token;

public class MethodDeclListNode extends GenericNode
{
	List<MethodDeclNode> methodDecl;
	public MethodDeclListNode(Token t, List<MethodDeclNode> md) 
	{
		super(t);
		methodDecl = md;
	}
}
