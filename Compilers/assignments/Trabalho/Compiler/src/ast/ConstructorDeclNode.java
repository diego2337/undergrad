package ast;

import compiler.Token;

public class ConstructorDeclNode extends GenericNode
{
	//Token constructor;
	public MethodBodyNode methodBody;
	public ConstructorDeclNode(Token t, /*Token c,*/ MethodBodyNode mb) 
	{
		super(t);
		//constructor = c;
		methodBody = mb;
	}
}
