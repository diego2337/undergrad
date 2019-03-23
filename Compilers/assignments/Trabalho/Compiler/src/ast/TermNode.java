package ast;

import compiler.Token;

public class TermNode extends GenericNode
{
	public UnaryExpressionNode unaryExpression;
	public TermLineNode termLine;
	public TermNode(Token t, UnaryExpressionNode u, TermLineNode t2) 
	{
		super(t);
		unaryExpression = u;
		termLine = t2;
	}

}
