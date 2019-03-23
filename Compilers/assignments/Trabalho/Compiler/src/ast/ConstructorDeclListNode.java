package ast;
import compiler.Token;

public class ConstructorDeclListNode extends GenericNode
{
	List<ConstructorDeclNode> constructorDecl;

	public ConstructorDeclListNode(Token t, List<ConstructorDeclNode> cd)
	{
		super(t);
		constructorDecl = cd;
	}

}
