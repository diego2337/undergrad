package compiler;

public class Token {
	public EnumToken name;
    public EnumToken attribute;
    public int lines;
    public String lexema;
    public STEntry stPtr;
    
    public Token(EnumToken name)
    {
        this.name = name;
        attribute = EnumToken.UNDEF;
        this.lines = 0;
        stPtr = null;
    }
    
    public Token(EnumToken name, EnumToken attr)
    {
        this.name = name;
        attribute = attr;
        stPtr = null;
    }
    
    public EnumToken getName() {
		return name;
	}

	public void setName(EnumToken name) {
		this.name = name;
	}

	public String getLexema() {
		return lexema;
	}

	public void setLexema(String lexema) {
		this.lexema = lexema;
	}

	public STEntry getStPtr() {
		return stPtr;
	}

	public void setStPtr(STEntry stPtr) {
		this.stPtr = stPtr;
	}

}
