package ast;

import compiler.Token;

public class ArgListNode extends GenericNode
{
	ExpressionNode expression;
	ArgListLineNode argListLine;
	public ArgListNode(Token t, ExpressionNode e, ArgListLineNode a) 
	{
		super(t);
		expression = e;
		argListLine = a;
	}

}
