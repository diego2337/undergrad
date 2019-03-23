package ast;

import compiler.Token;

public class VariableDeclNode extends GenericNode
{
	TypeNode type;
	VarDeclLineNode varDeclLine;
	public VariableDeclNode(Token t, TypeNode t2, VarDeclLineNode v) 
	{
		super(t);
		type = t2;
		varDeclLine = v;
	}
	
}
