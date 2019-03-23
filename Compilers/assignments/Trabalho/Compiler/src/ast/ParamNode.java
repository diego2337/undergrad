package ast;

import compiler.Token;

public class ParamNode extends GenericNode
{
	public TypeNode type;
	// Do paramLineNode tirei o token name, pra evitar indireçao
	String name;
	public ParamNode(Token t, TypeNode ty, String n) 
	{
		super(t);
		type = ty;
		name = n;
	}

}
