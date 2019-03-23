package ast;

import compiler.Token;

public class AtribStatNode extends GenericNode
{
	public LValueNode lValue;
	public String equals;
	public AtribStatLineNode atribStatLine;
	public AtribStatNode(Token t, LValueNode l, String e, AtribStatLineNode a)
	{
		super(t);
		lValue = l;
		equals = e;
		atribStatLine = a;
	}

}
