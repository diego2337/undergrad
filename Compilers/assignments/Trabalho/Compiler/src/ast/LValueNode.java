package ast;

import compiler.Token;

public class LValueNode extends GenericNode 
{
	String name;
	Token type;
	LValueLineNode lValueLine;
	public LValueNode(Token t, String n, LValueLineNode l) 
	{
		super(t);
		name = n;
		lValueLine = l;
	}

}
