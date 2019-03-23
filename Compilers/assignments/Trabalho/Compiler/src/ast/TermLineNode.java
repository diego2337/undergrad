package ast;

import compiler.Token;

public class TermLineNode extends GenericNode 
{
	String op;
	UnaryExpressionNode unaryExpression = null;
	public TermLineNode(Token t, String o, UnaryExpressionNode u)
	{
		super(t);
		op = o;
		unaryExpression = u;
	}

}
