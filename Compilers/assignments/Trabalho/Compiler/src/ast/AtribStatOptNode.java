package ast;

import compiler.Token;

public class AtribStatOptNode extends GenericNode 
{
	AtribStatNode atribStat;
	public AtribStatOptNode(Token t, AtribStatNode a)
	{
		super(t);
		atribStat = a;
	}
}
