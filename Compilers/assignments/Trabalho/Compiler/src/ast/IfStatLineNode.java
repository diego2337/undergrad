package ast;

import compiler.Token;

public class IfStatLineNode extends GenericNode
{
	StatementsNode statements;
	public IfStatLineNode(Token t, StatementsNode s)
	{
		super(t);
		statements = s;
	}

}
