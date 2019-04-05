/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;

/**
 *
 * @author diego
 */
public class Aluguel 
{
    static int numberOfAttributes = 11;
    static DBConn con = new DBConn();
    static DBQuery queryStream = new DBQuery(con.openConn());
    
    private Cliente cli;
    private Veiculo veiculo;
    private String  dataRetirada;
    private String dataDevolucao;
    private String localRetirada;
    private String estabelecimentoDevolucao;
    private byte formaPagamento;
    private float valorTotal;
    private String situacao;
    private Reserva reserva;

    public Cliente getCli() {
        return cli;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public String getDataRetirada() {
        return dataRetirada;
    }

    public String getDataDevolucao() {
        return dataDevolucao;
    }

    public String getLocalRetirada() {
        return localRetirada;
    }

    public String getEstabelecimentoDevolucao() {
        return estabelecimentoDevolucao;
    }

    public byte getFormaPagamento() {
        return formaPagamento;
    }

    public float getValorTotal() {
        return valorTotal;
    }

    public String getSituacao() {
        return situacao;
    }

    public Reserva getReserva() {
        return reserva;
    }
    void setCliente(Cliente cli) {
        this.cli = cli;
    }

    void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    void setLocalRetirada(String localRetirada) {
        this.localRetirada = localRetirada;
    }

    void setEstabelecimentoDevolucao(String estabelecimentoDevolucao) {
        this.estabelecimentoDevolucao = estabelecimentoDevolucao;
    }

    void setDataRetirada(String data_retirada) {
        this.dataRetirada = data_retirada;
    }

    void setDataDevolucao(String data_devolucao) {
        this.dataDevolucao = data_devolucao;
    }

    void setPagamento(byte forma_pagamento) {
        this.formaPagamento = forma_pagamento;
    }

    void setValorTotal(float valorTotal) {
        this.valorTotal = valorTotal;
    }

    void setSituacao(String situacao) {
        this.situacao = situacao;
    }

    void setReserva(Reserva res) {
        this.reserva = res;
    }
    
    @Override
    public String toString() {
        return "Aluguel{" + "cli=" + cli + ", veiculo=" + veiculo + ", dataRetirada=" + dataRetirada + ", dataDevolucao=" + dataDevolucao + ", localRetirada=" + localRetirada + ", estabelecimentoDevolucao=" + estabelecimentoDevolucao + ", formaPagamento=" + formaPagamento + ", valorTotal=" + valorTotal + ", situacao=" + situacao + ", reserva=" + reserva + '}';
    }
    
}
