package ast;

import compiler.Token;

public class AtribStatLineNode extends GenericNode 
{
	public ExpressionNode expression;
	public AllocExpressionNode allocExpression;
	public AtribStatLineNode(Token t, ExpressionNode e, AllocExpressionNode a) 
	{
		super(t);
		expression = e;
		allocExpression = a;
	}

}
