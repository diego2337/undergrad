package ast;

import compiler.Token;

public class StatementLineLineNode	extends GenericNode 
{
	public String name;
	public VarDeclLineNode varDeclOpt;
	public ExpressionNode expression;
	public LValueCompNode lValueComp;
	public StatementLineLineLineNode statementLineLineLine;
	public StatementLineLineNode(Token t, String n, VarDeclLineNode v, ExpressionNode e, LValueCompNode l, StatementLineLineLineNode stmntlll) 
	{
		super(t);
		name = n;
		varDeclOpt = v;
		expression = e;
		lValueComp = l;
		statementLineLineLine = stmntlll;
	}

}
