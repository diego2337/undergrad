package ast;

import compiler.Token;

public class ExpressionOptNode extends GenericNode
{
	ExpressionNode expression;
	public ExpressionOptNode(Token t, ExpressionNode e) 
	{
		super(t);
		expression = e;
	}
}
