package ast;

import compiler.Token;

public class VarDeclNode extends GenericNode 
{
	public TypeNode type;
	public VarDeclLineNode varDeclLine;
	public VarDeclNode(Token t, TypeNode ty, VarDeclLineNode vdl)
	{
		super(t);
		type = ty;
		varDeclLine = vdl;
	}
	
}
