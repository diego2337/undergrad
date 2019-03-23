package ast;

import compiler.Token;

public class IfStatNode extends GenericNode 
{
	ExpressionNode expression;
	StatementsNode statements;
	IfStatLineNode ifStatLine;
	public IfStatNode(Token t, ExpressionNode e, StatementsNode s, IfStatLineNode i3) 
	{
		super(t);
		expression = e;
		statements = s;
		ifStatLine = i3;
	}

}
