package ast;

import compiler.Token;

public class StatementLineLineLineNode extends GenericNode 
{
	public LValueLineNode lValueLine;
	public String equals;
	public AtribStatLineNode atribStat;
	public StatementLineLineLineNode(Token t, String e, LValueLineNode l, AtribStatLineNode a) 
	{
		super(t);
		equals = e;
		lValueLine = l;
		atribStat = a;
	}

}
