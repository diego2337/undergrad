package ast;

import compiler.Token;

public class ExpressionNode extends GenericNode 
{
	public NumExpressionNode numExpression;
	public ExpressionLineNode expressionLine;
	public ExpressionNode(Token t, NumExpressionNode n, ExpressionLineNode e) 
	{
		super(t);
		numExpression = n;
		expressionLine = e;		
	}

}
