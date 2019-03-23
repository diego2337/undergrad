package ast;

import compiler.Token;

public class MethodDeclNode extends GenericNode
{
	public TypeNode type;
	public MethodDeclLineNode methodDeclLine;
	public MethodDeclNode(Token t, TypeNode ty, MethodDeclLineNode mdl)
	{
		super(t);
		type = ty;
		methodDeclLine = mdl;
	}

}
