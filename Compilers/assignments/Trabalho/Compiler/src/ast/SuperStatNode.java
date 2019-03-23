package ast;

import compiler.Token;

public class SuperStatNode extends GenericNode
{
	ArgListOptNode argListOpt;
	public SuperStatNode(Token t, ArgListOptNode a) 
	{
		super(t);
		argListOpt = a;
	}
}
