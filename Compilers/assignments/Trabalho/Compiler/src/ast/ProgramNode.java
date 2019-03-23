package ast;

import compiler.Token;
public class ProgramNode extends GenericNode 
{
	public ClassListNode classList;
	public ProgramNode(Token t, ClassListNode cl)
	{
		super(t);
		classList = cl;
	}

}
