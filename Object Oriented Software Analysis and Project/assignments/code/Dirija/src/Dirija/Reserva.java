/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;

import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author diego
 */
class Reserva 
{
    static int numberOfAttributes = 12;
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
    private int tempoRetirada;

    public Reserva()
    {
        
    }
    
    public Cliente getCli() {
        return cli;
    }

    public void setCli(Cliente cli) {
        this.cli = cli;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    public String getDataRetirada() {
        return dataRetirada;
    }

    public void setDataRetirada(String dataRetirada) {
        this.dataRetirada = dataRetirada;
    }

    public String getDataDevolucao() {
        return dataDevolucao;
    }

    public void setDataDevolucao(String dataDevolucao) {
        this.dataDevolucao = dataDevolucao;
    }

    public String getLocalRetirada() {
        return localRetirada;
    }

    public void setLocalRetirada(String localRetirada) {
        this.localRetirada = localRetirada;
    }

    public String getEstabelecimentoDevolucao() {
        return estabelecimentoDevolucao;
    }

    public void setEstabelecimentoDevolucao(String estabelecimentoDevolucao) {
        this.estabelecimentoDevolucao = estabelecimentoDevolucao;
    }

    public byte getFormaPagamento() {
        return formaPagamento;
    }

    public void setFormaPagamento(byte formaPagamento) {
        this.formaPagamento = formaPagamento;
    }

    public float getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(float valorTotal) {
        this.valorTotal = valorTotal;
    }

    public int getTempoRetirada() {
        return tempoRetirada;
    }

    public void setTempoRetirada(int tempoRetirada) {
        this.tempoRetirada = tempoRetirada;
    }

    public String getSituacao() {
        return situacao;
    }

    public void setSituacao(String situacao) {
        this.situacao = situacao;
    }
    
    static Reserva buscar(Object obj) 
    {
        Reserva res = new Reserva();
        if(obj instanceof Cliente)
        {
            Cliente cli = (Cliente)obj;
            int cod = 0;
            Reserva.queryStream.runSQL("SELECT Reserva.cod_identificador, Reserva.chassi_veiculo, Reserva.CPF_cliente, "
                    + "Reserva.valor_total, Reserva.forma_pagamento, Reserva.situacao_servico, "
                    + "Reserva.data_retirada, Reserva.data_devolucao, Reserva.tempo_retirada "
                    + "FROM Reserva INNER JOIN Cliente ON Cliente.CPF=Reserva.CPF_cliente "
                    + "WHERE Cliente.CPF=" + cli.getCpf());
            if(queryStream.contemTuplas())
            {         
                try 
                {
                    cod = Reserva.queryStream.getLastExecutedQueryResult().getInt(1);
                    res.setSituacao(Reserva.queryStream.getLastExecutedQueryResult().getString(6));
                }
                catch (SQLException ex) 
                {
                    Logger.getLogger(Reserva.class.getName()).log(Level.SEVERE, null, ex);
                }
                if(res.getSituacao().equals("Aberta"))
                {
                    Reserva.queryStream.runSQL("UPDATE Reserva SET Reserva.situacao_servico='Finalizada' "
                        + "WHERE Reserva.cod_identificador = " + cod);   
                }
            }
            else
                res = null;
        }
        else if(obj instanceof Veiculo)
        {
            Veiculo veiculo = (Veiculo)obj;
            Reserva.queryStream.runSQL("SELECT Reserva.data_retirada FROM Reserva JOIN Veiculo "
                    + "ON Veiculo.chassi= Reserva.chassi_veiculo WHERE Veiculo.chassi='"
                    +veiculo.getChassi()+"' AND Reserva.situacao_servico='Aberta'");
            if(queryStream.contemTuplas())
            {
                try
                {
                    res.setDataRetirada(Reserva.queryStream.getLastExecutedQueryResult().getString(1));
                }
                catch(SQLException ex)
                {
                    Logger.getLogger(Reserva.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
            else
                res = null;
        }
        return res;
    }

}
