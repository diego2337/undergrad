package ast;

import compiler.Token;

public class FactorNode extends GenericNode 
{
	public String literal;
	public LValueNode lValue;
	public ExpressionNode expression;
	public FactorNode(Token t, String l, LValueNode l2, ExpressionNode e)
	{
		super(t);
		literal = l;
		lValue = l2;
		expression = e;
	}
}
