package ast;

import compiler.Token;

public class MethodBodyNode extends GenericNode
{
	public ParamListOptNode paramListOpt;
	public StatementsNode statement;
	public MethodBodyNode(Token t, ParamListOptNode plo, StatementsNode s) 
	{
		super(t);
		paramListOpt = plo;
		statement = s;
	}
}
