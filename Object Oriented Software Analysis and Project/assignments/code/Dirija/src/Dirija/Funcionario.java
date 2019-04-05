/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;

/**
 *
 * @author Wellington
 */
public class Funcionario {
    
    static int numberOfAttributes = 15;
    static DBConn con = new DBConn();
    static DBQuery queryStream = new DBQuery(con.openConn());

    private String nome_completo;
    private String CPF;
    private String data_nasc;
    private String data_contratacao;
    private int tel;
    private String endereco_completo;
    private float salario;
    private byte sexo;
    private float horas_extras;

    /* ---------- Construtor padrão ---------- */
    public Funcionario() {
        this.nome_completo = new String();
        this.CPF = new String();
        this.data_nasc = new String();
        this.data_contratacao = new String();
        this.tel = 0;
        this.endereco_completo = new String();
        this.salario = 0;
        this.sexo = 0xF;
        this.horas_extras = 0;
    }

    /* ---------- Construtor auxiliar p/teste ---------- */
    public Funcionario(String nome_completo, String CPF, String data_nasc,
            String data_contratacao, int tel, String endereco_completo,
            float salario, byte sexo, float horas_extras) {

        this.nome_completo = nome_completo;
        this.CPF = CPF;
        this.data_nasc = data_nasc;
        this.data_contratacao = data_contratacao;
        this.tel = tel;
        this.endereco_completo = endereco_completo;
        this.salario = salario;
        this.sexo = sexo;
        this.horas_extras = horas_extras;
    }

    /* ------------ GETTERS ------------ */
    public String getNomeCompleto() {
        return nome_completo;
    }

    public String getCPF() {
        return CPF;
    }

    public String getDataNasc() {
        return data_nasc;
    }

    public String getDataContratacao() {
        return data_contratacao;
    }

    public int getTel() {
        return tel;
    }

    public String getEnderecoCompleto() {
        return endereco_completo;
    }

    public float getSalario() {
        return salario;
    }

    public byte getSexo() {
        return sexo;
    }

    public float getHorasExtras() {
        return horas_extras;
    }

    /* ------------ SETTERS ------------ */
    public void setNomeCompleto(String nome_completo) {
        this.nome_completo = nome_completo;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }

    public void setDataNasc(String data_nasc) {
        this.data_nasc = data_nasc;
    }

    public void setDataContratacao(String data_contratacao) {
        this.data_contratacao = data_contratacao;
    }

    public void setTel(int tel) {
        this.tel = tel;
    }

    public void setEnderecoCompleto(String endereco_completo) {
        this.endereco_completo = endereco_completo;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }

    public void setSexo(byte sexo) {
        this.sexo = sexo;
    }

    public void setHorasExtras(float horas_extras) {
        this.horas_extras = horas_extras;
    }
}