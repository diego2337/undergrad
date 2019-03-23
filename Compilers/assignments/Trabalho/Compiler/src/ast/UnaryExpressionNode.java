package ast;

import compiler.Token;

public class UnaryExpressionNode extends GenericNode 
{
	public String unary;
	public FactorNode factor;
	public UnaryExpressionNode(Token t, String u, FactorNode f) 
	{
		super(t);
		unary = u;
		factor = f;
	}
}
