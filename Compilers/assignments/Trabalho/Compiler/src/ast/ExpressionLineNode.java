package ast;

import compiler.Token;

public class ExpressionLineNode extends GenericNode 
{
	String relop;
	NumExpressionNode numExpression;
	public ExpressionLineNode(Token t, String r, NumExpressionNode n) 
	{
		super(t);
		relop = r;
		numExpression = n;
	}

}
