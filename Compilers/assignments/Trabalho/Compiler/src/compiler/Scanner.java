package compiler;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.StringCharacterIterator;

public class Scanner {
	
	 private static String input;
	 private StringBuilder sb;
	 private StringCharacterIterator inputIt;
	 private STEntry entry;
	 private int lines;
         private int flag;
         javax.swing.JTextArea textarea;
	 private SymbolTable<STEntry> TS;
	   
	 public Scanner(String inputFileName, SymbolTable<STEntry> s, javax.swing.JTextArea txtarea, int flag)
	 {
		 File inputFile = new File(inputFileName);
	     sb = new StringBuilder();
	     entry = new STEntry();
	     TS = new SymbolTable<STEntry>();
	     lines = 1;
             textarea = txtarea;
	     try
	     {
	    	 FileReader fr = new FileReader(inputFile);
	           
	         int size = (int)inputFile.length();            
	         char[] buffer = new char[size];
	        
	         fr.read(buffer, 0, size);
	            
	         input = new String(buffer);
	            
	         inputIt = new StringCharacterIterator(input);
	         fr.close();
	     }
	     catch(FileNotFoundException e)
	     {
                textarea.append("Arquivo não encontrado\n");
                this.flag = flag = 1;
	     }
	     catch(IOException e)
	     {
                textarea.append("Erro na leitura do arquivo\n");
                this.flag = flag = 1;
	     }
	     setTS(s);
	 }

    public int getFlag() {
        return flag;
    }
         
	public SymbolTable<STEntry> getTS() {
		return TS;
	}
	public void setTS(SymbolTable<STEntry> tS) {
		TS = tS;
	}
	
	 public Token nextToken()
	 {
		 Token tok = new Token(EnumToken.UNDEF);
	        if (inputIt.getIndex() >= inputIt.getEndIndex())            
	            tok.name = EnumToken.EOF;
	        else /* Todas as definiçoes regulares possiveis da linguagem devem ser tratadas aqui */
	        {
	        	// ESTADO 0
	        	if(inputIt.current() == '{')
	        	{
	        		// ESTADO 1 -> ESTADO 2
	        		inputIt.next();
	        		tok.name = EnumToken.LBRCE;
        			tok.attribute = EnumToken.LBRCE;
	        	}
	        	else if(inputIt.current() == '}')
	        	{
	        		// ESTADO 3 -> ESTADO 4
	        		inputIt.next();
	        		tok.name = EnumToken.RBRCE;
        			tok.attribute = EnumToken.RBRCE;
	        	}
	        	else if(inputIt.current() == '(')
	        	{
	        		// ESTADO 5 -> ESTADO 6
	        		inputIt.next();
	        		tok.name = EnumToken.LPRTHS;
        			tok.attribute = EnumToken.LPRTHS;
	        	}
	        	else if(inputIt.current() == ')')
	        	{
	        		// ESTADO 7 -> ESTADO 8
	        		inputIt.next();
	        		tok.name = EnumToken.RPRTHS;
        			tok.attribute = EnumToken.RPRTHS;
	        	}
	        	else if(inputIt.current() == '[')
	        	{
	        		// ESTADO 9 -> ESTADO 10
	        		inputIt.next();
	        		tok.name = EnumToken.LBRCKT;
        			tok.attribute = EnumToken.LBRCKT;
	        	}
	        	else if(inputIt.current() == ']')
	        	{
	        		// ESTADO 11 -> ESTADO 12
	        		inputIt.next();
	        		tok.name = EnumToken.RBRCKT;
        			tok.attribute = EnumToken.RBRCKT;
	        	}
	        	else if(inputIt.current() == '+')
	        	{
	        		/* ESTADO 39 -> ESTADO 40 */
	        		inputIt.next();
	        		tok.name = EnumToken.PLUS;
	        		tok.attribute = EnumToken.PLUS;
	        	}
	        	else if(inputIt.current() == '-')
	        	{
	        		/* ESTADO 41 -> ESTADO 42 */
	        		inputIt.next();
	        		tok.name = EnumToken.MINUS;
	        		tok.attribute = EnumToken.MINUS;
	        	}
	        	else if(inputIt.current() == '*')
	        	{
	        		/* ESTADO 42 -> ESTADO 43 */
	        		inputIt.next();
	        		tok.name = EnumToken.MULT;
	        		tok.attribute = EnumToken.MULT;
	        	}
	        	else if(inputIt.current() == '/')
	        	{
	        		/* ESTADO 44 -> ESTADO 45 */
	        		inputIt.next();
	        		if(Character.isDigit(inputIt.current()) || inputIt.current() == '-' || inputIt.current() == '+')
	        		{
	        			tok.name = EnumToken.DIV;
		        		tok.attribute = EnumToken.DIV;
	        		}
	        		else
	        		{
	        			/* ESTADO 34 */
	        			if(inputIt.current() == '/')
		        		{
		        			/* ESTADO 35 */
		        			inputIt.next();
		        			while(inputIt.current() != '\n')
		        			{
		        				/* Ignora o que esta escrito nos comentarios */
		        				inputIt.next();
		        			}
                                                lines++;
		        			inputIt.next();
		        			// EOL - volta a execuçao do scanner
		        			tok = nextToken();
		        		}
	        			else if(inputIt.current() == '*')
		        		{
		        			/* ESTADO 36 */
		        			inputIt.next();
		        			int a = 0;
		        			while(a < 2 && (inputIt.getIndex() < inputIt.getEndIndex()))
		        			{
		        				/* Ignora o que esta escrito nos comentarios */
		        				inputIt.next();
		        				a = 0;
		        				if(inputIt.current() == '*')
		        				{
		        					/* ESTADO 37 */
		        					a++;
		        					inputIt.next();
		        					if(inputIt.current() == '/')
		        					{
		        						inputIt.next();
		        						a++;
		        					}
		        				}
		        				else if(inputIt.current() == '\n')
		        				{
		        					lines++;
		        				}
		        			}
		        			tok = nextToken();
		        		}
	        		}
	        	}
	        	else if(inputIt.current() == '"')
        		{
        			/* ESTADO 38 */
        			sb.append(inputIt.current());
        			inputIt.next();
        			while(inputIt.current() != '"')
        			{
        				sb.append(inputIt.current());
        				inputIt.next();
        			}
        			inputIt.next();
        			tok.lexema = sb.toString();
		        	tok.name = EnumToken.STRING_LITERAL;
			        tok.attribute = EnumToken.STRING_LITERAL;
		        	sb.setLength(0);
        		}
	        	else if(inputIt.current() == '%')
	        	{
	        		/* ESTADO 46 -> ESTADO 47 */
	        		inputIt.next();
	        		tok.name = EnumToken.MOD;
	        		tok.attribute = EnumToken.MOD;
	        	}
	        	else if(inputIt.current() == '.')
	        	{
	        		/* ESTADO 48 -> ESTADO 49 */
	        		inputIt.next();
	        		tok.name = EnumToken.INVOKER;
	        		tok.attribute = EnumToken.INVOKER;
	        	}
	        	else if(inputIt.current() == '\n')
	        	{
	        		/* ESTADO 50 -> ESTADO 51 */
	        		lines++;
	        		inputIt.next();
	        		tok = nextToken();
	        	}
	        	else if(inputIt.current() == '<')
	        	{
	        		/* ESTADO 13 */
	        		inputIt.next();
	        		if(inputIt.current() == '=')
	        		{
	        			/* ESTADO 14 */
	        			inputIt.next();
	        			tok.name = EnumToken.RELOP;
	        			tok.attribute = EnumToken.LE;
	        		}
	        		else
	        		{
	        			/* ESTADO 15 */
	        			tok.name = EnumToken.RELOP;
	        			tok.attribute = EnumToken.LT;
	        		}		
	        	}
	        	else if(inputIt.current() == '=')
	        	{
	        		/* ESTADO 16 */
	        		inputIt.next();
	        		if(inputIt.current() == '=')
	        		{
	        			/* ESTADO 17 */
	        			tok.name = EnumToken.EQ;
		        		tok.attribute = EnumToken.EQ;
	        		}
	        		else
	        		{
	        			/* ESTADO 18 */
	        			inputIt.next();
	        			tok.name = EnumToken.ATT;
		        		tok.attribute = EnumToken.ATT;
	        		}
	        	}
	        	else if(inputIt.current() == '>')
	        	{
	        		/* ESTADO 19 */
	        		inputIt.next();
	        		if(inputIt.current() == '=')
	        		{
	        			/* ESTADO 20 */
		        		inputIt.next();
	        			tok.name = EnumToken.RELOP;
		        		tok.attribute = EnumToken.GE;
	        		}
	        		else
	        		{
	        			/* ESTADO 21 */
	        			inputIt.next();
	        			tok.name = EnumToken.RELOP;
		        		tok.attribute = EnumToken.GT;
	        		}
	        	}
	        	else if(inputIt.current() == ';')
	        	{
	        		/* ESTADO 22 -> ESTADO 23 */
	        		inputIt.next();
	        		tok.name = EnumToken.SCOLON;
	        		tok.attribute = EnumToken.SCOLON;
	        	}
	        	else if(inputIt.current() == ',')
	        	{
	        		inputIt.next();
	        		tok.name = EnumToken.COMMA;
	        		tok.attribute = EnumToken.COMMA;
	        	}
	        	else if(Character.isLetter(inputIt.current()) || inputIt.current() == '_')
	        	{
	        		/* ESTADO 24 */
	        		sb.append(inputIt.current());
	        		inputIt.next();
	        		while(Character.isLetter(inputIt.current()) || Character.isDigit(inputIt.current())
	        				|| inputIt.current() == '_')
	        		{
	        			// (letter | digit) *
	        			sb.append(inputIt.current());
	        			inputIt.next();
	        		}
	        		/* ESTADO 25 */
	        		tok.lexema = sb.toString();
	        		entry = TS.get(tok.lexema);
		        	if(entry == null)
		        	{
		        		tok.name = EnumToken.ID;
			        	tok.attribute = EnumToken.ID;
		        	}
		        	else
		        	{
		        		tok.name = entry.token.name;
		        	}
		        	sb.setLength(0);
	        	}
	        	else if(Character.isWhitespace((inputIt.current())))
	        	{
	        		/* ESTADO 26 */
	        		while(Character.isWhitespace((inputIt.current())))
	        		{
	        			inputIt.next();
	        			while(Character.isWhitespace(inputIt.current()))
                                        {
	    	        		/* ESTADO 50 -> ESTADO 51 */
	        				if(inputIt.current() == '\n')
	        				{
                                                    lines++;
                                                    inputIt.next();
                                                    break;
	        				}
	        				inputIt.next();
                                        }
	        		}
	        		/* ESTADO 27 */
	        		tok = nextToken();
	        	}
	        	else if(Character.isDigit(inputIt.current()))
	        	{
	        		/* ESTADO 28 */
	        		sb.append(inputIt.current());
	        		inputIt.next();
	        		while(Character.isDigit(inputIt.current()))
	        		{
	        			sb.append(inputIt.current());
	        			inputIt.next();
	        		}
	        		if(inputIt.current() == '.')
	        		{
	        			/* ESTADO 29 */
	        			sb.append(inputIt.current());
	        			inputIt.next();
	        			if(Character.isDigit(inputIt.current()))
	        			{
	        				/* ESTADO 30 */
	        				sb.append(inputIt.current());
	        				inputIt.next();
	        				while(Character.isDigit(inputIt.current()))
	    	        		{
	        					sb.append(inputIt.current());
	    	        			inputIt.next();
	    	        		}
	        				if(inputIt.current() == 'e' || inputIt.current() == 'E')
	        				{
	        					/* ESTADO 31 */
	        					sb.append(inputIt.current());
	        					inputIt.next();
	        					if(inputIt.current() == '+' || inputIt.current() == '-')
	        					{
	        						sb.append(inputIt.current());
	        						inputIt.next();
	        					}
	        					/* precisa ter um número depois do expoente, pelo menos*/
	        					if(Character.isDigit(inputIt.current()))
	        					{
	        						/* ESTADO 32 */
	        						sb.append(inputIt.current());
	        						inputIt.next();
	        						while(Character.isDigit(inputIt.current()))
	        						{
	        							sb.append(inputIt.current());
	        							inputIt.next();
	        						}
	        						tok.lexema = sb.toString();
	        			        	tok.name = EnumToken.DOUBLE_LITERAL;
		        			        tok.attribute = EnumToken.DOUBLE_LITERAL;
	        			        	sb.setLength(0);
	        					}
	        				}
	        				else
	        				{
	        					tok.lexema = sb.toString();
        			        	tok.name = EnumToken.DOUBLE_LITERAL;
	        			        tok.attribute = EnumToken.DOUBLE_LITERAL;
        			        	sb.setLength(0);
	        				}
	        			}
	        			else if(inputIt.current() == 'e' || inputIt.current() == 'E')
	        			{
	        				sb.append(inputIt.current());
		        			inputIt.next();
	        				/* ESTADO 31 */
        					if(inputIt.current() == '+' || inputIt.current() == '-')
        					{
        						sb.append(inputIt.current());
        						inputIt.next();
        					}
        					/* precisa ter um número depois do expoente, pelo menos*/
        					if(Character.isDigit(inputIt.current()))
        					{
        						/* ESTADO 32*/
        						sb.append(inputIt.current());
        						inputIt.next();
        						while(Character.isDigit(inputIt.current()))
        						{
        							sb.append(inputIt.current());
        							inputIt.next();
        						}
        						tok.lexema = sb.toString();
        			        	tok.name = EnumToken.DOUBLE_LITERAL;
	        			        tok.attribute = EnumToken.DOUBLE_LITERAL;
        			        	sb.setLength(0);
        					}
	        			}
	        		}
	        		else
	        		{
	        			/* ESTADO 33 */
	        			tok.lexema = sb.toString();
			        	tok.name = EnumToken.INTEGER_LITERAL;
    			        tok.attribute = EnumToken.INTEGER_LITERAL;
			        	sb.setLength(0);
	        		}
	        	}
	        	else
	        	{
	        		textarea.append("ERRO léxico na linha " + lines + ": Token indefinido.\n");
                                inputIt.next();
                                tok = nextToken();
	        	}
	        } // End of else
	        tok.lines = lines;
	        return tok;
	 }
}
