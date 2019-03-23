package ast;

import compiler.Token;

public class ArgListOptNode extends GenericNode 
{
	ArgListNode argList;
	public ArgListOptNode(Token t, ArgListNode a)
	{
		super(t);
		argList = a;
	}

}
