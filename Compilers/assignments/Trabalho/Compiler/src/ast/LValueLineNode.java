package ast;

import compiler.Token;

public class LValueLineNode extends GenericNode
{
	LValueCompNode lValueComp;
	ExpressionNode expression;
	public LValueLineNode(Token t, LValueCompNode l, ExpressionNode e) 
	{
		super(t);
		lValueComp = l;
		expression = e;
	}
}
