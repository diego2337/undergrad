package ast;

import compiler.Token;

public class ArgListLineNode extends GenericNode 
{
	ExpressionNode expression;
	ArgListLineNode argListLine;
	public ArgListLineNode(Token t, ExpressionNode e, ArgListLineNode a)
	{
		super(t);
		expression = e;
		argListLine = a;
	}

}
