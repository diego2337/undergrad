package ast;

import compiler.Token;

public class VarDeclOptNode extends GenericNode
{
	String name;
	public VarDeclOptNode(Token t, String n) 
	{
		super(t);
		name = n;
	}

}
