package ast;

import compiler.Token;

public class VarDeclListNode extends GenericNode
{
	List<VarDeclNode> varDecl;
	
	public VarDeclListNode(Token t, List<VarDeclNode> vd)
	{
		super(t);
		varDecl = vd;
	}
}
