package ast;

import compiler.Token;

public class StatementLineNode extends GenericNode
{
	public String name;
	public VarDeclLineNode varDeclOpt;
	public StatementLineLineNode statementLineLine;
	public String equals;
	public AtribStatLineNode atribStat;
	public StatementLineLineLineNode statementLineLineLine;
	public StatementLineNode(Token t, String n, VarDeclLineNode v, StatementLineLineNode s, String p, AtribStatLineNode a, StatementLineLineLineNode s2) 
	{
		super(t);
		name = n;  
		equals = p;
		varDeclOpt = v;
		statementLineLine = s;
		atribStat = a;
		statementLineLineLine = s2;
		
	}

}
