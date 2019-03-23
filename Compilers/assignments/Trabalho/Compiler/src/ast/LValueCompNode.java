package ast;

import compiler.Token;

public class LValueCompNode extends GenericNode
{
	String name;
	LValueLineNode lValue;
	public LValueCompNode(Token t, String n, LValueLineNode l) 
	{
		super(t);
		name = n;
		lValue = l;
	}

}
