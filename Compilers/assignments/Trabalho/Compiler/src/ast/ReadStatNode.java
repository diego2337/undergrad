package ast;

import compiler.Token;

public class ReadStatNode extends GenericNode 
{
	LValueNode lValue;
	public ReadStatNode(Token t, LValueNode l) 
	{
		super(t);
		lValue = l;
	}

}
