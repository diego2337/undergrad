package ast;

import compiler.Token;

public class ForStatNode extends GenericNode
{
	AtribStatOptNode atribStatOpt;
	ExpressionOptNode expressionOpt;
	AtribStatOptNode atribStatOpt2;
	StatementsNode statements;
	public ForStatNode(Token t, AtribStatOptNode a, ExpressionOptNode e, AtribStatOptNode a2, StatementsNode s)
	{
		super(t);
		atribStatOpt = a;
		expressionOpt = e;
		atribStatOpt2 = a2;
		statements = s;
	}

}
