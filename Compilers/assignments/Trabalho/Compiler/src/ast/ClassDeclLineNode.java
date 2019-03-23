package ast;
import compiler.Token;

/* TODO - fazer um nó para cada producao que cuida da fatoraçao nao ira causar muita indireção? 
 * R: Acho melhor manter todas as produçoes pra facilitar o retorno no parser... */
public class ClassDeclLineNode extends GenericNode
{
	public ClassBodyNode body;
	//Token extendsname;
	String name = null;
	public ClassBodyNode getBody() {
		return body;
	}
	public void setBody(ClassBodyNode body) {
		this.body = body;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public ClassDeclLineNode(Token t, /*Token t2,*/ String t3, ClassBodyNode b)
	{
		super(t);
		//extendsname = t2;
		name = t3;
		body = b;
	}

}
