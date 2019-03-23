package ast;

import compiler.Token;

public class NumExpressionNode extends GenericNode 
{
	public TermNode term;
	public NumExpressionLineNode numExpressionLine;
	public NumExpressionNode(Token t, TermNode t2, NumExpressionLineNode n) 
	{
		super(t);
		term = t2;
		numExpressionLine = n;
	}

}
