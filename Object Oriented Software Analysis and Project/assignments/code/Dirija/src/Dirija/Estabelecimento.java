/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;

import java.util.List;
import java.util.Vector;

/**
 *
 * @author Wellington
 */
public class Estabelecimento {
    
    static int numberOfAttributes = 10;
    static DBConn con = new DBConn();
    static DBQuery queryStream = new DBQuery(con.openConn());

    private int num_estabelecimento;
    private String cidade;
    private String endereco;
    private String bairro;
    private String cpFGerente;  /*Cada Estabelecimento contém o CPF de seu gerente*/
    private int CEP;
    private String horario_atendimento;
    private int tel;
    private int numero_veiculos_servico;
    private List<Funcionario> funcionarios;
    private List<Veiculo> veiculos;
      
    /* ---------- Construtor padrão ---------- */
    public Estabelecimento( int num_estabelecimento, String cidade,
     String endereco, String bairro, String cpFGerente, int CEP,
     String horario_atendimento, int tel, int numero_veiculos_servico){
        
      this.num_estabelecimento = num_estabelecimento;
      this.cidade = cidade;
      this.endereco = endereco;
      this.bairro = bairro;
      this.CEP = CEP;
      this.horario_atendimento  = horario_atendimento;
      this.tel = tel;
      this.numero_veiculos_servico = numero_veiculos_servico;
      
      this.funcionarios = new Vector <Funcionario>();
      this.veiculos =  new Vector <Veiculo>();
    }
   
    /* ---------- Construtor auxiliar p/teste ---------- */
      public Estabelecimento() {
      this.num_estabelecimento = 0;
      this.cidade = new String();
      this.endereco = new String();
      this.bairro = new String();
      this.CEP = 0;
      this.horario_atendimento  = new String();
      this.tel = 0;
      this.numero_veiculos_servico = 0;
      this.funcionarios = new Vector <Funcionario>();
      this.veiculos =  new Vector <Veiculo>();
    }
    
    /* ----------------GETTERS---------------- */
    
    public String getCpFGerente() {
        return cpFGerente;
    }

    public int getNumEstabelecimento() {
        return num_estabelecimento;
    }

    public String getCidade() {
        return cidade;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getBairro() {
        return bairro;
    }

    public int getCep() {
        return CEP;
    }

    public String getHorarioAtendimento() {
        return horario_atendimento;
    }

    public int getTel() {
        return tel;
    }

    public int getNumeroVeiculosServico() {
        return numero_veiculos_servico;
    }

    /* ----------------SETTERS---------------- */
    public void setCpFGerente(String cpFGerente) {
        this.cpFGerente = cpFGerente;
    }
    
    public void setNumEstabelecimento(int num_estabelecimento) {
        this.num_estabelecimento = num_estabelecimento;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public void setCep(int CEP) {
        this.CEP = CEP;
    }

    public void setHorarioAtendimento(String horario_atendimento) {
        this.horario_atendimento = horario_atendimento;
    }

    public void setTel(int tel) {
        this.tel = tel;
    }

    public void setNumeroVeiculosServico(int numero_veiculos_servico) {
        this.numero_veiculos_servico = numero_veiculos_servico;
    }
    
    
    
    /*--------------Metodos para verificação-------------------*/
    
    public void addFuncionario(Funcionario funcionario){
        this.funcionarios.add(funcionario);
    }
    
    public void addVeiculos(Veiculo veiculo){
        this.veiculos.add(veiculo);
    }
  
    public List<Funcionario> listaFuncionarios(){
        return this.funcionarios;
    }
    
    public List<Veiculo> listaVeiculos(){
        return this.veiculos;
    }
  
}
