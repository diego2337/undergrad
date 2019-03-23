package ast;

import compiler.Token;

public class StatementsNode extends GenericNode
{
	public List<StatementNode> statement;
	public StatementsNode(Token t, List<StatementNode> s)
	{
		super(t);
		statement = s;
	}

}
