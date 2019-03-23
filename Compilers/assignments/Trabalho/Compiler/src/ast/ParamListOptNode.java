package ast;

import compiler.Token;

public class ParamListOptNode extends GenericNode 
{
	public ParamListNode paramListNode;
	public ParamListOptNode(Token t, ParamListNode pln) 
	{
		super(t);
		paramListNode = pln;
	}

}
