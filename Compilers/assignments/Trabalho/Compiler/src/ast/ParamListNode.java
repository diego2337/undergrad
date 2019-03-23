package ast;

import compiler.Token;

public class ParamListNode extends GenericNode
{
	public List<ParamNode> param;
	public ParamListNode(Token t, List<ParamNode> p) 
	{
		super(t);
		param = p;
	}

}
