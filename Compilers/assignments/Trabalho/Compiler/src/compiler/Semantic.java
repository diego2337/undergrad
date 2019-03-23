package compiler;
import ast.*;
import java.util.*;

public class Semantic
{
	public ProgramNode ast;
	public SymbolTable<STEntry> globalTS;
	public Token aux;
        public javax.swing.JTextArea textarea;
	public Semantic(ProgramNode root, SymbolTable<STEntry> parse, javax.swing.JTextArea txtarea)
	{
		ast = root;
		globalTS = parse;
                textarea = txtarea;
	}
	public void analyze()
	{
		
		/* Vamos percorrer a lista de declaraçoes de classes */
                if(ast.classList != null)
                {
                    Iterator<ClassDeclNode> it = ast.classList.classList.iterator();
                    while(it.hasNext())
                    {
			ClassDeclNode element = it.next();
			//System.out.print(element);
			/* Indica que temos extends, portanto devemos verificar se a classe herdada foi declarada */
			if(element.decline.getName() != null)
			{
				aux = new Token(EnumToken.ID);
				aux.stPtr = globalTS.get(element.decline.getName());
				/* Se o ponteiro para a tabela de simbolos for nulo entao o elemento nao esta inserido na tabela */
				if(aux.stPtr == null)
				{
					textarea.append("Erro semântico na linha " + element.position.lines + ": A classe estendida não foi declarada.\n");
				}
				/* Caso a classe estenda ela mesma */
				else if(element.superName == aux.stPtr.lexeme)
				{
					textarea.append("Erro semântico na linha " + element.position.lines + ": A classe em questão não pode estender a si mesma.\n");
				}
			}
                    }
                }
	}
}