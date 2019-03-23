package ast;

import compiler.Token;

public class NumExpressionLineNode extends GenericNode
{
	String pm;
	TermNode term;
	public NumExpressionLineNode(Token t, String p, TermNode t2) 
	{
		super(t);
		pm = p;
		term = t2;
	}

}
