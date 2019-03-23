package ast;

import compiler.Token;

public class TypeNode extends GenericNode 
{
	public String type;
	public TypeNode(Token t, String t2)
	{
		super(t);
		type = t2;
	}
}
