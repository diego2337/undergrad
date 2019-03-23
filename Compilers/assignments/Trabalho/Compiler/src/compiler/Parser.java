package compiler;

import ast.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;

public class Parser
{
	Scanner lex;
	Token lToken;
	STEntry entrada_TS;
	SymbolTable<STEntry> globalTS;
	SymbolTable<STEntry> currentTS;
	ProgramNode syntaxTree;
        int flag;
        javax.swing.JTextArea textarea;

	public Parser(String inputFileName, javax.swing.JTextArea txtarea)
	{
		globalTS = new SymbolTable<STEntry>();
		initTable();
		lex = new Scanner(inputFileName, globalTS, txtarea, flag);
                this.flag = lex.getFlag();
		lToken = new Token(EnumToken.UNDEF);
                textarea = txtarea;
	}
	
	private void initTable()
	{
		EnumToken []reservedTokens = {EnumToken.CLASS, EnumToken.CONSTRUCTOR, EnumToken.EXTENDS, EnumToken.IF, EnumToken.ELSE, EnumToken.FOR,
				EnumToken.NEW, EnumToken.THIS, EnumToken.BREAK, EnumToken.PRINT, EnumToken.READ, EnumToken.RETURN,
				EnumToken.SUPER, EnumToken.INT, EnumToken.DOUBLE, EnumToken.STRING};
		String []reservedKeys =  {"class", "constructor", "extends", "if", "else", "for", "new", "this", "break",
				"print", "read", "return", "super", "int", "double", "string"};
		Token lToken2;
		for(int i = 0; i < 16; i++)
		{
			 lToken2 = new Token(reservedTokens[i]);
			lToken2.stPtr = new STEntry(lToken2, reservedKeys[i], true);
			globalTS.add(lToken2.stPtr);
		}
	}

	public ProgramNode Program()
	{
		lToken = lex.nextToken();
		ClassListNode cNode = null;
                List<ClassDeclNode> nNode = new List<ClassDeclNode>();
		if(lToken.name == EnumToken.CLASS)
		{
			ClassList(nNode);
			cNode = new ClassListNode(lToken, nNode);
		}
		else if(lToken.name == EnumToken.EOF)
		{
			/* else do nothing */
		}
                else
		{
                    textarea.append("Erro na linha " + lToken.lines +": Token 'class' esperado para definição de classe. Pulando para a próxima classe (caso haja).\n");
                    while(lToken.name != EnumToken.CLASS && lToken.name != EnumToken.EOF)
                        advance();  
                    if(lToken.name == EnumToken.CLASS)
                    {
                        ClassList(nNode);
                        cNode = new ClassListNode(lToken, nNode);
                    }
		}
		ProgramNode pNode = new ProgramNode(lToken, cNode);
		return pNode;
	}
	public void ClassList(List<ClassDeclNode> nNode)
	{
			nNode.add(ClassDecl());
			ClassListLine(nNode);
	}
	// ClassListLine == ClassList
	public void ClassListLine(List<ClassDeclNode> nNode)
	{
		if(lToken.name == EnumToken.CLASS)
		{
			ClassList(nNode);
		}
		else if(lToken.name == EnumToken.EOF)
		{
			/* else do nothing */
		}
                else
		{
                    textarea.append("Erro na linha " + lToken.lines +": Token 'class' esperado para definição de classe. Pulando para a próxima classe (caso haja).\n");
                    while(lToken.name != EnumToken.CLASS && lToken.name != EnumToken.EOF)
                        advance();
                    if(lToken.name == EnumToken.CLASS)
                        ClassList(nNode);
		}
	}
	public ClassDeclNode ClassDecl()
	{
		match(EnumToken.CLASS);
		entrada_TS = new STEntry(lToken, lToken.lexema, false);
		if(lToken.lexema != null && !globalTS.add(entrada_TS))
		{
			textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de classes.\n");
		}
		String aux = lToken.lexema;
		match(EnumToken.ID);
		ClassDeclNode cNode = new ClassDeclNode(lToken, aux, ClassDeclLine());
		return cNode;
	}
	public ClassDeclLineNode ClassDeclLine()
	{
		ClassBodyNode cNode = null;
		String aux = null;
		if(lToken.name == EnumToken.LBRCE)
		{
			cNode = ClassBody();
		}
		else if(lToken.name == EnumToken.EXTENDS)
		{
			advance();
			aux = lToken.lexema;
			match(EnumToken.ID);
			cNode = ClassBody();
		}
		else
		{
			System.out.printf("Erro na linha %d.\n", lToken.lines);
			System.exit(1);
		}
		ClassDeclLineNode classDeclLine = new ClassDeclLineNode(lToken, aux, cNode);
		return classDeclLine;
	}
	public ClassBodyNode ClassBody()
	{
		List<VarDeclNode> varDecl = new List<VarDeclNode>();
		List<ConstructorDeclNode> constDecl = new List<ConstructorDeclNode>();
		List<MethodDeclNode> methodDecl = new List<MethodDeclNode>();
		currentTS = new SymbolTable<STEntry>(globalTS);
		lex.setTS(currentTS);
                /* Apesar da produçao parecer ambigua, podemos resolve-la simplesmente dando um match na chave nessa parte */
		match(EnumToken.LBRCE);
                ClassBodyLine(varDecl, constDecl, methodDecl);
		match(EnumToken.RBRCE);
		currentTS = currentTS.parent;
		ClassBodyNode classBody = new ClassBodyNode(lToken, varDecl, constDecl, methodDecl);
		return classBody;
	}
        public void ClassBodyLine(List<VarDeclNode> varDecl, List<ConstructorDeclNode> constDecl, List<MethodDeclNode> methodDecl)
        {
            String aux = null;
            if(lToken.name == EnumToken.CONSTRUCTOR)
            {
                ConstructDeclList(constDecl);
                MethodDeclList(methodDecl);
            }
            else if(lToken.name == EnumToken.INT || lToken.name == EnumToken.DOUBLE || lToken.name == EnumToken.STRING || lToken.name == EnumToken.ID)
            {
                aux = Type();
                if(lToken.name == EnumToken.ID)
                {
                    entrada_TS = new STEntry(lToken, lToken.lexema, false);
                    if(lToken.lexema != null && !currentTS.add(entrada_TS))
                    {
                        textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
                    }
                    match(EnumToken.ID);
                    ListsLine(aux, varDecl, constDecl, methodDecl);
                }
                else if(lToken.name == EnumToken.LBRCKT)
                {
                    match(EnumToken.LBRCKT);
                    match(EnumToken.RBRCKT);
                    entrada_TS = new STEntry(lToken, lToken.lexema, false);
                    if(lToken.lexema != null && !currentTS.add(entrada_TS))
                    {
                        textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
                    }
                    match(EnumToken.ID);
                    ListsLine(aux, varDecl, constDecl, methodDecl);
                }
                /* else do nothing */
            }
        }
        public void ListsLine(String name, List<VarDeclNode> varDecl, List<ConstructorDeclNode> constDecl, List<MethodDeclNode> methodDecl)
        {
            List<VarDeclOptNode> varDeclOpt = new List<VarDeclOptNode>();
            MethodBodyNode methodBody = null;
            if(lToken.name == EnumToken.COMMA)
            {
                VarDeclOpt(varDeclOpt, name);
                match(EnumToken.SCOLON);
                ClassBodyLine(varDecl, constDecl, methodDecl);
            }
            else if(lToken.name == EnumToken.LPRTHS)
            {
                methodBody = MethodBody();
                MethodDeclList(methodDecl);
            }
            else if(lToken.name == EnumToken.SCOLON)
            {
                match(EnumToken.SCOLON);
                ClassBodyLine(varDecl, constDecl, methodDecl);
            }
        }
	public VarDeclNode VarDecl()
	{
		TypeNode type = new TypeNode(lToken, Type());
		VarDeclLineNode varDeclLine = new VarDeclLineNode(lToken, VarDeclLine(type.type));
		VarDeclNode varDecl = new VarDeclNode(lToken, type, varDeclLine);
		return varDecl;
	}
	public List<VarDeclOptNode> VarDeclLine(String name)
	{
		List<VarDeclOptNode> varDeclOpt = new List<VarDeclOptNode>();
		if(lToken.name == EnumToken.ID)
		{
			lToken.attribute = toEnum(name);
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
			}
			advance();
			VarDeclOpt(varDeclOpt, name);
			match(EnumToken.SCOLON);
		}
		else
		{
			match(EnumToken.LBRCKT);
			match(EnumToken.RBRCKT);
			lToken.attribute = EnumToken.ARRAY;
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
			}
			match(EnumToken.ID);
			VarDeclOpt(varDeclOpt, name);
			match(EnumToken.SCOLON);
		}
		return varDeclOpt;
	}
	public void VarDeclOpt(List<VarDeclOptNode> varDeclOpt, String name)
	{
		String aux = null;
		if(lToken.name == EnumToken.COMMA)
		{
			advance();
			lToken.attribute = toEnum(name);
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			aux = lToken.lexema;
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
			}
                        match(EnumToken.ID);
			VarDeclOptNode varDeclOptAux = new VarDeclOptNode(lToken, aux);
			varDeclOpt.add(varDeclOptAux);
			VarDeclOpt(varDeclOpt, name);
		}
		/* else do nothing */
	}
	public String Type()
	{
		String aux = null;
		if(lToken.name == EnumToken.INT || lToken.name == EnumToken.DOUBLE 
				|| lToken.name == EnumToken.STRING)
		{
			aux = lToken.lexema;
			advance();
		}
		else if(lToken.name == EnumToken.ID)
		{
			aux = lToken.lexema;
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.search(lToken.lexema))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": O identificador " + lToken.lexema + " não pode ser usado como tipo.\n");
			}
			advance();
		}
		return aux;
	}
	public void ConstructDeclList(List<ConstructorDeclNode> constructDecl)
	{
		if(lToken.name == EnumToken.CONSTRUCTOR)
		{
			constructDecl.add(ConstructDecl());
			ConstructDeclList(constructDecl);
		}
		/* else do nothing */
	}
	public ConstructorDeclNode ConstructDecl()
	{
		match(EnumToken.CONSTRUCTOR);
		lex.setTS(currentTS);
		ConstructorDeclNode constDecl = new ConstructorDeclNode(lToken, MethodBody());
		return constDecl;
	}
	public void MethodDeclList(List<MethodDeclNode> methodDecl)
	{
		if(lToken.name == EnumToken.INT || lToken.name == EnumToken.DOUBLE || 
				lToken.name == EnumToken.STRING || lToken.name == EnumToken.ID)
		{
			methodDecl.add(MethodDecl());
			MethodDeclList(methodDecl);
		}
		/* else do nothing */
	}
	public MethodDeclNode MethodDecl()
	{
		TypeNode type = new TypeNode(lToken, Type());
		MethodDeclNode methodDecl = new MethodDeclNode(lToken, type, MethodDeclLine());
		return methodDecl;
	}
	public MethodDeclLineNode MethodDeclLine()
	{
		MethodBodyNode mb = null;
		String aux = null;
		if(lToken.name == EnumToken.ID)
		{
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de nome de método.\n");
			}
			aux = lToken.lexema;
			advance();
			mb = MethodBody();
		}
		else
		{
			match(EnumToken.LBRCKT);
			match(EnumToken.RBRCKT);
			aux = lToken.lexema;
			match(EnumToken.ID);
			mb = MethodBody();
		}
		MethodDeclLineNode methodDeclLine = new MethodDeclLineNode(lToken, aux, mb);
		return methodDeclLine;
	}
	public MethodBodyNode MethodBody()
	{
		ParamListOptNode paramList = null;
		StatementsNode statements = null;
		List<StatementNode> statementList = new List<StatementNode>();
		currentTS = new SymbolTable<STEntry>(currentTS);
		lex.setTS(currentTS);
		match(EnumToken.LPRTHS);
		paramList = ParamListOpt();
		match(EnumToken.RPRTHS);
		match(EnumToken.LBRCE);
		statements = Statements(statementList);
		match(EnumToken.RBRCE);
		currentTS = currentTS.parent;
		MethodBodyNode methodBody = new MethodBodyNode(lToken, paramList, statements);
		return methodBody;
	}
	public ParamListOptNode ParamListOpt()
	{
		if(lToken.name == EnumToken.INT || lToken.name == EnumToken.DOUBLE || 
				lToken.name == EnumToken.STRING || lToken.name == EnumToken.ID)
		{
			ParamListOptNode param = new ParamListOptNode(lToken, ParamList());
			return param;
		}
		/* else do nothing */
		return null;
	}
	public ParamListNode ParamList()
	{
		List<ParamNode> param = new List<ParamNode>();
		param.add(Param());
		ParamListLine(param);
		ParamListNode param2 = new ParamListNode(lToken, param);
		return param2;
	}
	public void ParamListLine(List<ParamNode> param)
	{
		if(lToken.name == EnumToken.COMMA)
		{
			advance();
			param.add(Param());
			ParamListLine(param);
		}
		/* else do nothing */
	}
	public ParamNode Param()
	{
		TypeNode ty = new TypeNode(lToken, Type());
		ParamNode param = new ParamNode(lToken, ty, ParamLine());
		return param;
	}
	public String ParamLine()
	{
		String aux = null;
		if(lToken.name == EnumToken.ID)
		{
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de parâmetros.\n");
			}
			aux = lToken.lexema;
			advance();
		}
		else
		{
			match(EnumToken.LBRCE);
			match(EnumToken.RBRCE);
			aux = lToken.lexema;
			match(EnumToken.ID);
		}
		return aux;
	}
	public StatementsNode Statements(List<StatementNode> statementList)
	{
		if(lToken.name == EnumToken.INT || lToken.name == EnumToken.DOUBLE || lToken.name == EnumToken.STRING
				|| lToken.name == EnumToken.ID || lToken.name == EnumToken.PRINT || lToken.name == EnumToken.READ
				|| lToken.name == EnumToken.RETURN || lToken.name == EnumToken.SUPER || lToken.name == EnumToken.IF
				|| lToken.name == EnumToken.FOR || lToken.name == EnumToken.BREAK || lToken.name == EnumToken.SCOLON)
		{
			statementList.add(Statement());
			Statements(statementList);
		}
		/* else do nothing */
		StatementsNode stmnts = new StatementsNode(lToken, statementList);
		return stmnts;
	}
	public StatementNode Statement()
	{
		String aux = lToken.lexema;
		List<VarDeclOptNode> varDeclLine = new List<VarDeclOptNode>();
		VarDeclLineNode vdl = new VarDeclLineNode(lToken, varDeclLine);
		StatementLineNode statementLine = null;
		PrintStatNode printStat = null;
		ReadStatNode readStat = null;
		ReturnStatNode returnStat = null;
		SuperStatNode superStat = null;
		IfStatNode ifStat = null;
		ForStatNode forStat = null;
		if(lToken.name == EnumToken.INT)
		{
			advance();
			varDeclLine = VarDeclLine("int");
		}
		else if(lToken.name == EnumToken.DOUBLE)
		{
			advance();
			varDeclLine = VarDeclLine("double");
		}
		else if(lToken.name == EnumToken.STRING)
		{
			advance();
			varDeclLine = VarDeclLine("string");
		}
		else if(lToken.name == EnumToken.ID)
		{
			Token temp = lToken;
			advance();
			statementLine = StatementLine(lToken.lexema);
			/* Caso 1 - Atribuição */
			if(statementLine.equals != null)
			{
				if(temp.lexema != null && !currentTS.search(temp.lexema))
				{
					textarea.append("Erro sintático na linha " + temp.lines + ": Identificador " + temp.lexema + " não declarado.\n");
				}
			}
			/* Caso 2 - Declaração */
			else if(statementLine.equals == null && statementLine.statementLineLine == null && statementLine.statementLineLineLine == null)
			{
				if(temp.lexema != null && !currentTS.search(temp.lexema))
				{
					textarea.append("Erro sintático na linha " + temp.lines + ": O identificador " + temp.lexema + " não pode ser"
							+ " usado como tipo.\n");
				}
				
			}
		}
		else if(lToken.name == EnumToken.PRINT)
		{
			printStat = PrintStat();
			match(EnumToken.SCOLON);
		}
		else if(lToken.name == EnumToken.READ)
		{
			readStat = ReadStat();
			match(EnumToken.SCOLON);
		}
		else if(lToken.name == EnumToken.RETURN)
		{
			returnStat = ReturnStat();
			match(EnumToken.SCOLON);
		}
		else if(lToken.name == EnumToken.SUPER)
		{
			superStat = SuperStat();
			match(EnumToken.SCOLON);
		}
		else if(lToken.name == EnumToken.IF)
		{
			ifStat = IfStat();
		}
		else if(lToken.name == EnumToken.FOR)
		{
			forStat = ForStat();
		}
		else if (lToken.name == EnumToken.BREAK)
		{
			aux = lToken.lexema;
			advance();
			match(EnumToken.SCOLON);
		}
		else
		{
			aux = lToken.lexema;
			match(EnumToken.SCOLON);
		}
		StatementNode statement = new StatementNode(lToken, aux, vdl, statementLine, printStat, readStat, returnStat, superStat, ifStat, forStat);
		return statement;
	}
	
	public StatementLineNode StatementLine(String name)
	{
		List<VarDeclOptNode> varDeclOpt = new List<VarDeclOptNode>();
		StatementLineLineLineNode stmntlll = null;
		StatementLineLineNode stmntll = null;
		AtribStatLineNode atribStatl = null;
		VarDeclLineNode vNode = new VarDeclLineNode(lToken, varDeclOpt);
		String aux = null;
		String aux2 = null;
		if(lToken.name == EnumToken.ID)
		{
			aux = lToken.lexema;
			lToken.attribute = toEnum(name);
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
			}
			match(EnumToken.ID);
			VarDeclOpt(varDeclOpt, name);
			match(EnumToken.SCOLON);
		}
		else if(lToken.name == EnumToken.INVOKER)
		{
			advance();
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.search(lToken.lexema))
			{
				/* tratamento de exceçao, o ID NÃO se encontra*/
				textarea.append("Erro sintático na linha " + lToken.lines + ": Método " + lToken.lexema + " não declarado.\n");
			}
			match(EnumToken.ID);
			stmntlll = StatementLineLineLine();
		}
		else if(lToken.name == EnumToken.ATT)
		{
			aux2 = "=";
			advance();
			atribStatl = AtribStatLine();
			match(EnumToken.SCOLON);
		}
		else
		{
			match(EnumToken.LBRCKT);
			stmntll = StatementLineLine(name);
		}
		StatementLineNode stmntl = new StatementLineNode(lToken, aux, vNode, stmntll, aux2, atribStatl, stmntlll);
		return stmntl;
	}
	
	public StatementLineLineLineNode StatementLineLineLine()
	{
		AtribStatLineNode atribStatl = null;
		LValueLineNode lValuel = null;
		String aux = null;
		if(lToken.name == EnumToken.ATT)
		{
			aux = lToken.lexema;
			advance();
			atribStatl = AtribStatLine();
		}
		else
		{
			lValuel = LValueLine();
			match(EnumToken.ATT);
			atribStatl = AtribStatLine();
		}
		StatementLineLineLineNode stmntlll = new StatementLineLineLineNode(lToken, aux, lValuel, atribStatl);
		match(EnumToken.SCOLON);
		return stmntlll;
	}
	
	public StatementLineLineNode StatementLineLine(String name)
	{
		List<VarDeclOptNode> varDeclOpt = new List<VarDeclOptNode>();
		VarDeclLineNode vNode = new VarDeclLineNode(lToken, varDeclOpt);
		LValueCompNode lValueC = null;
		StatementLineLineLineNode stmntlll = null;
		ExpressionNode exp = null;
		String aux = null;
		if(lToken.name == EnumToken.RBRCKT)
		{
			advance();
			aux = lToken.lexema;
			lToken.attribute = EnumToken.ARRAY;
                        entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.add(entrada_TS))
			{
				textarea.append("Erro sintático na linha " + lToken.lines + ": Declaração duplicada de variáveis.\n");
			}
			match(EnumToken.ID);
			VarDeclOpt(varDeclOpt, name);
			match(EnumToken.SCOLON);
		}
		else
		{
			exp = Expression();
			match(EnumToken.RBRCKT);
			lValueC = LValueComp();
			stmntlll = StatementLineLineLine();
		}
		StatementLineLineNode stmnll = new StatementLineLineNode(lToken, aux, vNode, exp, lValueC, stmntlll);
		return stmnll;
	}
	
	public AtribStatNode AtribStat()
	{
		LValueNode lValue = null;
		AtribStatLineNode atribStatl = null;
		String aux = null;
		if(lToken.name == EnumToken.ID)
		{
			lValue = LValue();
			aux = lToken.lexema;
			match(EnumToken.ATT);
			atribStatl = AtribStatLine();
		}
		AtribStatNode atribStat = new AtribStatNode(lToken, lValue, aux, atribStatl);
		return atribStat;
	}

	public AtribStatLineNode AtribStatLine()
	{
		ExpressionNode exp = null;
		AllocExpressionNode alloc = null;
		if(lToken.name == EnumToken.PLUS)
		{
			exp = Expression();
		}
		else
		{
			alloc = AllocExpression();
		}
		AtribStatLineNode atribStatl = new AtribStatLineNode(lToken, exp, alloc);
		return atribStatl;
	}
	public PrintStatNode PrintStat()
	{
		match(EnumToken.PRINT);
		PrintStatNode printStat = new PrintStatNode(lToken, Expression());
		return printStat;
	}
	public ReadStatNode ReadStat()
	{
		match(EnumToken.READ);
		ReadStatNode readStat = new ReadStatNode(lToken, LValue());
		return readStat;
	}
	public ReturnStatNode ReturnStat()
	{
		match(EnumToken.RETURN);
		ReturnStatNode returnStat = new ReturnStatNode(lToken, Expression());
		return returnStat;
	}
	public SuperStatNode SuperStat()
	{
		match(EnumToken.SUPER);
		match(EnumToken.LPRTHS);
		SuperStatNode superStat = new SuperStatNode(lToken, ArgListOpt());
		match(EnumToken.RPRTHS);
		return superStat;
	}
	public IfStatNode IfStat()
	{
		ExpressionNode exp = null;
		List<StatementNode> sNode = new List<StatementNode>();
		StatementsNode stmnts = new StatementsNode(lToken, sNode);
		IfStatLineNode ifStatl = null;
		match(EnumToken.IF);
		match(EnumToken.LPRTHS);
		exp = Expression();
		match(EnumToken.RPRTHS);
		currentTS = new SymbolTable<STEntry>(currentTS);
		lex.setTS(currentTS);
		match(EnumToken.LBRCE);
		stmnts = Statements(sNode);
		match(EnumToken.RBRCE);
		currentTS = currentTS.parent;
		ifStatl = IfStatLine();
		IfStatNode ifStat = new IfStatNode(lToken, exp, stmnts, ifStatl);
		return ifStat;
	}
	public IfStatLineNode IfStatLine()
	{
		List<StatementNode> sNode = new List<StatementNode>();
		StatementsNode stmnts = new StatementsNode(lToken, sNode);
		if(lToken.name == EnumToken.ELSE)
		{
			advance();
			currentTS = new SymbolTable<STEntry>(currentTS);
			lex.setTS(currentTS);
			match(EnumToken.LBRCE);
			stmnts = Statements(sNode);
			match(EnumToken.RBRCE);
			currentTS = currentTS.parent;
		}
		IfStatLineNode ifStat = new IfStatLineNode(lToken, stmnts);
		return ifStat;
		/* else do nothing */
	}
	public ForStatNode ForStat()
	{
		AtribStatOptNode atribStatOpt = null;
		AtribStatOptNode atribStatOpt2 = null;
		ExpressionOptNode expOpt = null;
		List<StatementNode> sNode = new List<StatementNode>();
		StatementsNode stmnts = new StatementsNode(lToken, sNode);
		match(EnumToken.FOR);
		currentTS = new SymbolTable<STEntry>(currentTS);
		lex.setTS(currentTS);
		match(EnumToken.LPRTHS);
		atribStatOpt = AtribStatOpt();
		match(EnumToken.SCOLON);
		expOpt = ExpressionOpt();
		match(EnumToken.SCOLON);
		atribStatOpt2 = AtribStatOpt();
		match(EnumToken.RPRTHS);
		match(EnumToken.LBRCE);
		stmnts = Statements(sNode);
		match(EnumToken.RBRCE);
		currentTS = currentTS.parent;
		ForStatNode forStat = new ForStatNode(lToken, atribStatOpt, expOpt, atribStatOpt2, stmnts);
		return forStat;
	}
	public AtribStatOptNode AtribStatOpt()
	{
		AtribStatNode atribStat = null;
		if(lToken.name == EnumToken.ID);
		{
			atribStat = AtribStat();
		}
		AtribStatOptNode atribStatOpt = new AtribStatOptNode(lToken, atribStat);
		return atribStatOpt;
		/* else do nothing */
	}
	public ExpressionOptNode ExpressionOpt()
	{
		ExpressionNode exp = null;
		if(lToken.name == EnumToken.PLUS || lToken.name == EnumToken.MINUS)
		{
			exp = Expression();
		}
		ExpressionOptNode expOpt = new ExpressionOptNode(lToken, exp);
		return expOpt;
		/* else do nothing */
	}
	public ExpressionNode Expression()
	{
		ExpressionNode exp = new ExpressionNode(lToken, NumExpression(), ExpressionLine());
		return exp;
	}
	public LValueNode LValue()
	{
		String aux = null;
		if(lToken.lexema != null && !currentTS.search(lToken.lexema))
		{
			/* o ID NÃO se encontra */
			textarea.append("Erro sintático na linha " + lToken.lines + ": Identificador " + lToken.lexema + " não declarado.\n");
		}
		aux = lToken.lexema;
		match(EnumToken.ID);
		LValueNode lValue = new LValueNode(lToken, aux, LValueLine());
		return lValue;
	}
	public LValueLineNode LValueLine()
	{
		ExpressionNode exp = null;
		LValueCompNode lValueComp = null;
		if(lToken.name == EnumToken.LBRCKT)
		{
			advance();
			exp = Expression();
			match(EnumToken.RBRCKT);
			lValueComp = LValueComp();
		}
		else
		{
			lValueComp = LValueComp();
		}
		LValueLineNode lValuel = new LValueLineNode(lToken, lValueComp, exp);
		return lValuel;
	}
	public LValueCompNode LValueComp()
	{
		String aux = null;
		LValueLineNode lValuel = null;
		if(lToken.name == EnumToken.INVOKER)
		{
			
			advance();
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			if(lToken.lexema != null && !currentTS.search(lToken.lexema))
			{
				/* o ID NÃO se encontra */
				textarea.append("Erro sintático na linha " + lToken.lines + ": Método " + lToken.lexema + " não declarado.\n");
			}
			aux = lToken.lexema;
			match(EnumToken.ID);
			lValuel = LValueLine();
		}
		LValueCompNode lValueComp = new LValueCompNode(lToken, aux, lValuel);
		return lValueComp;
		/* else do nothing */
	}
	public ExpressionLineNode ExpressionLine()
	{
		NumExpressionNode numExp = null;
		String aux = null;
		if(lToken.name == EnumToken.RELOP)
		{
			aux = lToken.lexema;
			advance();
			numExp = NumExpression();
		}
		ExpressionLineNode expLine = new ExpressionLineNode(lToken, aux, numExp);
		return expLine;
		// else Do nothing
	}
	
	public AllocExpressionNode AllocExpression()
	{
		ArgListOptNode argListOpt = null;
		ExpressionNode exp = null;
		TypeNode type = null;
		if(lToken.name == EnumToken.NEW)
		{
			advance();
			entrada_TS = new STEntry(lToken, lToken.lexema, false);
			match(EnumToken.ID);
			match(EnumToken.LPRTHS);
			argListOpt = ArgListOpt();
			match(EnumToken.RPRTHS);
		}
		else
		{
			type = new TypeNode(lToken, Type());
			match(EnumToken.LBRCKT);
			exp = Expression();
			match(EnumToken.RBRCKT);
		}
		AllocExpressionNode allocExp = new AllocExpressionNode(lToken, argListOpt, type, exp);
		return allocExp;
	}
	
	public NumExpressionNode NumExpression()
	{
		NumExpressionNode numExp = new NumExpressionNode(lToken, Term(), NumExpressionLine());
		return numExp;
	}
	public NumExpressionLineNode NumExpressionLine()
	{
		String aux = null;
		TermNode term = null;
		if(lToken.name == EnumToken.PLUS)
		{
			aux = lToken.lexema;
			advance();
			term = Term();
		}
		else if(lToken.name == EnumToken.MINUS)
		{
			aux = lToken.lexema;
			advance();
			term = Term();
		}
		NumExpressionLineNode numExpLine = new NumExpressionLineNode(lToken, aux, term);
		return numExpLine;
		/* else do nothing */
	}
	public TermNode Term()
	{
		TermNode term = new TermNode(lToken, UnaryExpression(), TermLine());
		return term;
	}
	
	public TermLineNode TermLine()
	{
		String aux = null;
		UnaryExpressionNode unary = null;
		if(lToken.name == EnumToken.MULT)
		{
			aux = lToken.lexema;
			advance();
			unary = UnaryExpression();
		}
		else if(lToken.name == EnumToken.DIV)
		{
			aux = lToken.lexema;
			advance();
			unary = UnaryExpression();
		}
		else if(lToken.name == EnumToken.MOD)
		{
			aux = lToken.lexema;
			advance();
			unary = UnaryExpression();
		}
		TermLineNode termLine = new TermLineNode(lToken, aux, unary);
		return termLine;
		// else - Do nothing		
	}
	
	public UnaryExpressionNode UnaryExpression()
	{
		FactorNode fact = null;
		String aux = null;
		if(lToken.name == EnumToken.PLUS)
		{
			aux = lToken.lexema;
			advance();
			fact = Factor();
		}
		else if(lToken.name == EnumToken.MINUS)
		{
			aux = lToken.lexema;
			advance();
			fact = Factor();
		}
		UnaryExpressionNode unary = new UnaryExpressionNode(lToken, aux, fact);
		return unary;
	}
	
	public FactorNode Factor()
	{
		String aux = null;
		LValueNode lValue = null;
		ExpressionNode exp = null;
		if(lToken.name == EnumToken.INTEGER_LITERAL || lToken.name == EnumToken.DOUBLE_LITERAL || lToken.name == EnumToken.STRING_LITERAL || lToken.name == EnumToken.PLUS || lToken.name == EnumToken.MINUS)
		{
			aux = lToken.lexema;
			advance();
		}
		else if(lToken.name == EnumToken.ID)
		{
			aux = lToken.attribute.toString();
			lValue = LValue();
		}
		else
		{
			match(EnumToken.LPRTHS);
			exp = Expression();
			match(EnumToken.RPRTHS);
		}
		FactorNode fact = new FactorNode(lToken, aux, lValue, exp);
		return fact;
	}
	public ArgListOptNode ArgListOpt()
	{
		ArgListNode argList = null;
		if(lToken.name == EnumToken.INTEGER_LITERAL || lToken.name == EnumToken.DOUBLE_LITERAL || lToken.name == EnumToken.STRING_LITERAL || lToken.name == EnumToken.PLUS || lToken.name == EnumToken.MINUS)
		{
			argList = ArgList();
		}
		ArgListOptNode argListOpt = new ArgListOptNode(lToken, argList);
		return argListOpt;
		/* else do nothing */
	}
	public ArgListNode ArgList()
	{
		ArgListNode argList = new ArgListNode(lToken, Expression(), ArgListLine());
		return argList;
	}
	public ArgListLineNode ArgListLine()
	{
		ArgListLineNode argListLine = null;
		if(lToken.name == EnumToken.COMMA)
		{
			advance();
			argListLine = new ArgListLineNode(lToken, Expression(), ArgListLine());
		}
		return argListLine;
		/* else do nothing */
	}
	public void advance()
	{
		lToken = lex.nextToken();
	}
	public void match(EnumToken tok)
	{
		if(tok == lToken.name)
		{
			advance();
		}
		else
		{
			panic();
		}
	}
	public void panic()
	{
		
		textarea.append("ERRO: Token faltando/inesperado na linha " + lToken.lines + ".\n");
                while(lToken.name != EnumToken.SCOLON && lToken.name != EnumToken.EOF)
                    advance();  
	}

	
	public EnumToken toEnum(String name)
	{
		if(name == "int")
		{
			return EnumToken.INTEGER_LITERAL;
		}
		else if(name == "double")
		{
			return EnumToken.DOUBLE_LITERAL;
		}
		else if(name == "string")
		{
			return EnumToken.STRING_LITERAL;
		}
		else
		{
			return EnumToken.ID;
		}
	}
}