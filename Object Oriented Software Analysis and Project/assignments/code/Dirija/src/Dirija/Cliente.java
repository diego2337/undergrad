/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;


/**
 *
 * @authors Wellington, Jainor
 */
public class Cliente 
{
    static int numberOfAttributes = 14;
    static DBConn con = new DBConn();
    static DBQuery queryStream = new DBQuery(con.openConn());
    
    private String nome;
    private String CPF;
    private int tel;
    private String profissao;
    private String endereco_completo;
    private String bairro;
    private String data_nasc; 
    private String validade_carteira;
    private String data_cadastro;

    /* ---------- Construtor padrão ---------- */
    public Cliente()
    {
        this.nome = new String();
        this.CPF = "0";
        this.tel = 0;
        this.profissao = new String();
        this.endereco_completo = new String();
        this.bairro = new String();
        this.data_nasc = new String();
        this.validade_carteira = new String();
        this.data_cadastro = new String();
    }
    
    public Cliente(String nome_completo, String CPF, int tel,
        String profissao, String endereco_completo, String bairro,
        String data_nasc, String validade_carteira,
        String data_cadastro)
    {
           
        this.nome = nome_completo;
        this.CPF = CPF;
        this.tel = tel;
        this.profissao = profissao;
        this.endereco_completo = endereco_completo;
        this.bairro = bairro;
        this.data_nasc = data_nasc;
        this.validade_carteira = validade_carteira;
        this.data_cadastro = data_cadastro;
    }


    /*------------------ SETTERS ------------------*/

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCpf(String CPF) {
        this.CPF = CPF;
    }

    public void setTel(int tel) {
        this.tel = tel;
    }

    public void setProfissao(String profissao) {
        this.profissao = profissao;
    }

    public void setEnderecoCompleto(String endereco_completo) {
        this.endereco_completo = endereco_completo;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public void setDataNasc(String data_nasc) {
        this.data_nasc = data_nasc;
    }

    public void setValidadeCarteira(String validade_carteira) {
        this.validade_carteira = validade_carteira;
    }

    public void setDataCadastro(String data_Cadastro) {
        this.data_cadastro = data_Cadastro;
    }

   /* ------------  GETTERS ---------------   */

    public String getNome() {
        return this.nome;
    }

    public String getCpf() {
        return this.CPF;
    }

    public int getTel() {
        return this.tel;
    }

    public String getProfissao() {
        return this.profissao;
    }

    public String getEnderecoCompleto() {
        return this.endereco_completo;
    }

    public String getBairro() {
        return this.bairro;
    }

    public String getDataNasc() {
        return this.data_nasc;
    }

    public String getValidadeCarteira() {
        return this.validade_carteira;
    }

    public String getDataCadastro() {
        return this.data_cadastro;
    }

    /* ------------ MÉTODOS DA CLASSE ---------------   */
    @Override
    public String toString() {
        return "Cliente{" + "nome_completo=" + nome + ", CPF=" + CPF + ", tel=" + tel + ", profissao=" + profissao + ", endereco_completo=" + endereco_completo + ", bairro=" + bairro + ", data_nasc=" + data_nasc + ", validade_carteira=" + validade_carteira + ", data_cadastro=" + data_cadastro + '}';
    }
    
    /* Esse método vai verificar se o cliente em questão já se encontra associado a algum Aluguel */
    public boolean verificarPendencia() 
    {
        Cliente.queryStream.runSQL("SELECT * FROM Cliente INNER JOIN Aluguel "
                + "ON Cliente.CPF=Aluguel.CPF_cliente WHERE Cliente.CPF=" + this.getCpf() 
                + " AND Aluguel.situacao_servico='Em andamento'" );
        if(queryStream.contemTuplas())
        {
            return true;
        }
        else
        {
            return false;       
        }
    }

}
