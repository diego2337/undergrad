package ast;

import compiler.Token;

public class StatementNode extends GenericNode 
{
	public String name;
	public String type2;
	public VarDeclLineNode varDeclLine;
	public StatementLineNode statement;
	public PrintStatNode printStat;
	public ReadStatNode readStat;
	public ReturnStatNode returnStat;
	public SuperStatNode superStat;
	public IfStatNode ifStat;
	public ForStatNode forStat;
	public StatementNode(Token t, String ty, VarDeclLineNode vdl, StatementLineNode s, PrintStatNode p, ReadStatNode r, ReturnStatNode 
			re, SuperStatNode su, IfStatNode i, ForStatNode f)
	{
		super(t);
		name = ty;
		varDeclLine = vdl;
		statement = s;
		printStat = p;
		readStat = r;
		returnStat = re;
		superStat = su;
		ifStat = i;
		forStat = f;
	}

}
