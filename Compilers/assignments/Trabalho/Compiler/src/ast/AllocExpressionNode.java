package ast;

import compiler.Token;

public class AllocExpressionNode extends GenericNode 
{
	ArgListOptNode argListOpt;
	TypeNode type;
	ExpressionNode exp;
	public AllocExpressionNode(Token t, ArgListOptNode a, TypeNode ty, ExpressionNode e) 
	{
		super(t);
		argListOpt = a;
		type = ty;
		exp = e;
	}

}
