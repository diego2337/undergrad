package ast;

import compiler.Token;

public class MethodDeclLineNode extends GenericNode
{
	// Lembrar que o token que ele passa é diferente, pq pode ser um tipo ou um vetor daquele tipo
	public String name;
	public MethodBodyNode methodBody;
	public MethodDeclLineNode(Token t, String n, MethodBodyNode mb) 
	{
		super(t);
		name = n;
		methodBody = mb;
	}

}
