package ast;

import compiler.Token;

public class ReturnStatNode extends GenericNode 
{
	ExpressionNode expression;
	
	public ReturnStatNode(Token t, ExpressionNode e) 
	{
		super(t);
		expression = e;
	}
}
