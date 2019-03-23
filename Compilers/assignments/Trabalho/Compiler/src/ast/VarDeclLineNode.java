package ast;
import compiler.Token;

public class VarDeclLineNode extends GenericNode
{
	List<VarDeclOptNode> varDeclOpt;
	// Fiz uma lista de vdo pois nao queria construir uma lista de tokens (teria que alterar o construtor e tudo mais)
	public VarDeclLineNode(Token t, List<VarDeclOptNode> vdo) 
	{
		super(t);
		varDeclOpt = vdo;
	}
}
