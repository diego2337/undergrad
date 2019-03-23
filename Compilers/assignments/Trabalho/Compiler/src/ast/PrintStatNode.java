package ast;

import compiler.Token;

public class PrintStatNode extends GenericNode
{
	ExpressionNode expression;
	public PrintStatNode(Token t, ExpressionNode e) 
	{
		super(t);
		expression = e;
	}

}
