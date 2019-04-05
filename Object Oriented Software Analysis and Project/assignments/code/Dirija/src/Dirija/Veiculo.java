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
public class Veiculo 
{
    static int numberOfAttributes = 12;
    static DBConn con = new DBConn();
    static DBQuery queryStream = new DBQuery(con.openConn());
   
    private String chassi;
    private String apolice;
    private String placa;
    private String modelo;
    private String fabricante;
    private String data_aquisicao;
    private String estado_tanque;
    private String estado_geral;
    private String acessorios;
    private float preco_dia;
    private float preco_horas_extras;

    
    /* ---------- Construtor padrão ---------- */
    public Veiculo() {
        this.chassi = "------";
        this.placa = new String();
        this.apolice = "-----";
        this.modelo = new String();
        this.fabricante = new String();
        this.data_aquisicao = new String();
        this.estado_tanque = new String();
        this.estado_geral = new String();
        this.acessorios = new String();
        this.preco_dia =  0;
        this.preco_horas_extras = 0;
    }
    
    public Veiculo( String placa, String chassi, String apolice, String modelo,
        String fabricante, String data_aquisicao, String estado_tanque,
        String estado_geral, String acessorios, float preco_dia,
        float preco_horas_extras) 
    {
        this.placa = placa;
        this.chassi = chassi;
        this.apolice = apolice;
        this.modelo = modelo;
        this.fabricante = fabricante;
        this.data_aquisicao = data_aquisicao;
        this.estado_tanque = estado_tanque;
        this.estado_geral = estado_geral;
        this.acessorios = acessorios;
        this.preco_dia =  preco_dia;
        this.preco_horas_extras = preco_horas_extras;
    }
    
    /* ----------- GETTERS ----------- */
    public String getPlaca() {
        return placa;
    }
        
    public String getChassi() {
        return chassi;
    }

    public String getApolice() {
        return apolice;
    }

    public String getModelo() {
        return modelo;
    }

    public String getFabricante() {
        return fabricante;
    }

    public String getDataAquisicao() {
        return data_aquisicao;
    }

    public String getEstadoTanque() {
        return estado_tanque;
    }

    public String getEstadoGeral() {
        return estado_geral;
    }

    public String getAcessorios() {
        return acessorios;
    }

    public float getPrecoDia() {
        return preco_dia;
    }

    public float getPrecoHorasExtras() {
        return preco_horas_extras;
    }
    
    /* ----------- SETTERS ----------- */
    public void setPlaca(String placa) {
        this.placa = placa;
    }
    
    public void setChassi(String chassi) {
        this.chassi = chassi;
    }

    public void setApolice(String apolice) {
        this.apolice = apolice;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setFabricante(String fabricante) {
        this.fabricante = fabricante;
    }

    public void setDataAquisicao(String data_aquisicao) {
        this.data_aquisicao = data_aquisicao;
    }

    public void setEstadoTanque(String estado_tanque) {
        this.estado_tanque = estado_tanque;
    }

    public void setEstadoGeral(String estago_geral) {
        this.estado_geral = estago_geral;
    }

    public void setAcessorios(String acessorios) {
        this.acessorios = acessorios;
    }

    public void setPrecoDia(float preco_dia) {
        this.preco_dia = preco_dia;
    }

    public void setPrecoHorasExtras(float preco_horas_extras) {
        this.preco_horas_extras = preco_horas_extras;
    }
    
}
