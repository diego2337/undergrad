/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package Dirija;

import java.util.Calendar;

/**
 *
 * @author diego
 */

/* Essa classe será responsável por tratar os eventos disparados do controller, bem como 
disparar alguns outros métodos que estejam na camada de Modelo ou tratar algumas questões através
de métodos, apresentados no diagrama de sequência de sistema (DSS). */
public class AluguelVeiculoController 
{  
    /* Esse método é responsável por identificar se um cliente está com sua carteira vencida ou se 
    ele já se encontra associado a outro aluguel */
    public int verificarPendencia(Cliente cli)
    {
        int sinal = 0;
        int anoCarteira = 0, anoAtual, mesCarteira = 0, mesAtual, 
            diaCarteira = 0, diaAtual;
        /* Para pegar a data atual */
        Calendar n = Calendar.getInstance();
        anoAtual = n.get(Calendar.YEAR);
        /* Os meses vão de 0 a 11 (herança de C) */
        mesAtual = n.get(Calendar.MONTH);
        mesAtual++;
        diaAtual = n.get(Calendar.DAY_OF_MONTH);
          
            //System.out.print(obj.getClass());
        anoCarteira = this.getDate(cli.getValidadeCarteira(), 1);
        mesCarteira = this.getDate(cli.getValidadeCarteira(), 2);
        diaCarteira = this.getDate(cli.getValidadeCarteira(), 3);
        // Se a carteira já tiver vencido, dispara-se esse sinal 
        System.out.println(mesCarteira);
        if(verificaSinais(anoCarteira, mesCarteira, diaCarteira) && 
            (anoAtual - anoCarteira > 0 || (anoAtual - anoCarteira == 0 && 
            mesAtual - mesCarteira > 0) ||
            (anoAtual - anoCarteira == 0 && mesAtual - mesCarteira == 0 && diaAtual - diaCarteira >= 0)))
        {
            sinal = 2;
        }
        else if((cli.verificarPendencia()))
        /* Como a verificação de associação de um objeto está muito associada a um Cliente,
        o tratamento da mesma será feito pelo objeto através de um método dele */
        {
            sinal = 1;
        }
        return sinal;
    }
    
    /* O seguinte método compõe também o controlador do caso de uso "Gerenciar clientes", e visto como
    os dois estão relacionados ele pode ser implementado aqui */
    public String[][] consultarClientes()
    {
        Cliente.queryStream.runSQL("SELECT * FROM Cliente");
        String[][] s = Cliente.queryStream.retLastQueryResult();
        return s;
    }
    
    /* Esse método simples tem como função informar em uma variável do tipo String qual é a data atual */
    public String informarDataAtual()
    {
        String mes, dia;
        Calendar n = Calendar.getInstance();
        int anoAtual = n.get(Calendar.YEAR);
        /* Os meses vão de 0 a 11 (herança de C) */
        int mesAtual = n.get(Calendar.MONTH);
        mesAtual++;
        if(mesAtual < 10)
        {
            mes = '0' + String.valueOf(mesAtual);
        }
        else
            mes = String.valueOf(mesAtual);
        int diaAtual = n.get(Calendar.DAY_OF_MONTH);
        if(diaAtual < 10)
        {
            dia = '0' + String.valueOf(diaAtual);
        }
        else
            dia = String.valueOf(diaAtual);
        String data = String.valueOf(anoAtual) + "-" + mes + "-" + dia;
        return data;
    }
    /* Novamente, esse método também está em outro caso de uso, porém é necessário para a finalização
    do caso de uso corrente */
    public String[][] consultarVeiculosLivres(Cliente cli)
    {
        String[][] s = null;
        String data = this.informarDataAtual();
        //String[][] s = Cliente.queryStream.retLastQueryResult();
        Veiculo.queryStream.runSQL("SELECT V.chassi, V.num_estabelecimento, V.apolice,"
                + "V.placa, V.modelo, V.fabricante, V.data_aquisicao, "
                + "V.estado_tanque, V.estado_geral, V.acessorios, V.preco_dia,"
                + "V.preco_horas_extras FROM (Cliente AS C JOIN Reserva AS R" 
                + " ON (C.Cpf = R.CPF_cliente)) JOIN Veiculo "
                + "AS V ON (V.chassi = chassi_veiculo)" 
                + " WHERE C.Cpf ='" + cli.getCpf() +  "' AND R.situacao_servico='Aberta'");
        if(Veiculo.queryStream.contemTuplas())
        {
            s = Veiculo.queryStream.retLastQueryResult();
        }
        else
        {
            Veiculo.queryStream.runSQL("SELECT V.chassi, V.num_estabelecimento, V.apolice,"
                    + " V.placa, V.modelo, V.fabricante, V.data_aquisicao,"
                    + " V.estado_tanque, V.estado_geral, V.acessorios, V.preco_dia,"
                    + " V.preco_horas_extras "
                    + " FROM Veiculo V"
                    + " WHERE V.chassi NOT IN( "
                    + " SELECT V.chassi FROM Veiculo V JOIN Aluguel A ON(V.chassi=A.chassi_veiculo)"
                    + " AND A.situacao_servico='Em andamento')"
                    + " AND V.chassi NOT IN(SELECT V.chassi FROM Veiculo V JOIN Reserva R "
                    + " ON(V.chassi=R.chassi_veiculo) AND R.situacao_servico='Aberta' AND R.data_retirada="
                    + "'"+ data +"')");
//            Veiculo.queryStream.runSQL("SELECT DISTINCT * FROM Veiculo WHERE Veiculo.chassi NOT IN "
//                    + "(SELECT Veiculo.chassi FROM Veiculo JOIN Reserva ON Veiculo.chassi=Reserva.chassi_veiculo"
//                    + " WHERE Reserva.situacao_servico='Aberta') "
//                    + "AND Veiculo.chassi NOT IN (SELECT Veiculo.chassi FROM Veiculo WHERE Veiculo.situacao='O')");
            s = Veiculo.queryStream.retLastQueryResult();
        }
        return s;
    }
    
    /* Um dos últimos métodos de outro caso de uso que também será aproveitado aqui */
    public String[][] consultarEstabelecimentos()
    {
        Estabelecimento.queryStream.runSQL("SELECT * FROM Estabelecimento");
        String[][] s = Estabelecimento.queryStream.retLastQueryResult();
        return s;
    }
    
    /* Esse método simplesmente toma como parâmetro um ano e retorna se ele é bissexto ou não */
    public int anoBissexto(int ano)
    {
        if((ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0)))
        {
            return 1;
        }
        else
            return 0;
    }
    
    /* Esse método simplesmente verifica se todos os dados foram extraídos corretamente do método getDate,
    retornando true; se algum deles não foi corretamente analisado, então o método retorna false*/
    public boolean verificaSinais(int ano, int mes, int dia)
    {
        if(ano == -1 || mes == -1 || dia == -1)
            return false;
        else
            return true;
    }
    
    /* Aqui, iremos separar da string 'd' o ano, mes e dia, de acordo com o valor de 'ymd' (1, 2 e 3, 
    respectivamente). Aqui já testamos também se o usuário não digitou uma letra (NumberFormatException)
    e se há traços entre cada um (primeiro if); no advento dessas regras não serem cumpridas, o sinal -1
    é enviado */
    public int getDate(String d, int ymd)
    {
        String ano = " ";
        int data;
        if(d == null || d.length() != 10 || d.charAt(4) != '-' || d.charAt(7) != '-')
            data = -1;
        else if(ymd == 1)
            ano = d.substring(0, 4);
        else if(ymd == 2)
            ano = d.substring(5, 7);
        else if(ymd == 3)
            ano = d.substring(8, 10);
        try
        {
            data = Integer.parseInt(ano);
        }
        catch(NumberFormatException e)
        {
            data = -1;
        }
        return data;
    }
    
    /* Nesse método, verificaremos as datas inseridas pelo usuário de retirada e entrega de um automóvel,
    respectivamente. Aqui, podemos inserir tanto uma data só (identificando a segunda como NULL) como 
    duas datas, que não só se verificará a validade delas como se a segunda (que é de entrega) não antecede
    a de retirada */
    public int verificarData(String d, String d2, Veiculo veiculo)
    {
        int anoRetirada = 0, mesRetirada = 0, diaRetirada = 0,
                anoDevolucao = 0, mesDevolucao = 0, diaDevolucao = 0, bissexto, i = 0;
        String aux = d;
        anoRetirada = this.getDate(d, 1);
        mesRetirada = this.getDate(d, 2);
        diaRetirada = this.getDate(d, 3);
        while(i < 2)
        {
            if(aux == null)
                return 4;
            bissexto = this.anoBissexto(anoRetirada);
            if(anoRetirada < 2014 || anoRetirada > 2015 || mesRetirada < 1 || mesRetirada > 12
                || diaRetirada < 1 || diaRetirada > 31)
            {
                return 4;
            }
            else if(bissexto == 1 && mesRetirada == 2 && diaRetirada > 29)
            {
                return 4;
            }
            else if(mesRetirada == 2 && diaRetirada > 28)
            {
                return 4;
            }
            else if(mesRetirada < 8)
            {
                if(mesRetirada % 2 == 0 && diaRetirada > 30)
                    return 4;
            }
            else if(mesRetirada >= 8)
            {
                if(mesRetirada % 2 != 0 && diaRetirada > 30)
                {
                    return 4;
                }
            }
            aux = d2;
            if(d2 == null)
                i = 10;
            else
            {
                i++;
                anoRetirada = this.getDate(aux, 1); 
                mesRetirada = this.getDate(aux, 2);
                diaRetirada = this.getDate(aux, 3);
            }
        }
        /* Aqui, não é xxxDevolucao e sim retirada - mudamos o xxxRetirada para Devolucao dentro do for */
        anoDevolucao = this.getDate(d, 1);
        mesDevolucao = this.getDate(d, 2);
        diaDevolucao = this.getDate(d, 3);
        if(i == 2 && anoRetirada - anoDevolucao < 0 || (anoRetirada - anoDevolucao == 0 && 
            mesRetirada - mesDevolucao < 0) || (anoRetirada - anoDevolucao == 0 && 
            mesRetirada - mesDevolucao == 0 && diaRetirada - diaDevolucao < 0))
            return 5;
        else if(veiculo != null)
        {
            Reserva res = new Reserva();
            res = Reserva.buscar(veiculo);
            if(res != null)
            {
                anoRetirada = this.getDate(res.getDataRetirada(), 1);
                mesRetirada = this.getDate(res.getDataRetirada(), 2);
                diaRetirada = this.getDate(res.getDataRetirada(), 3);
                anoDevolucao = this.getDate(d2, 1);
                mesDevolucao = this.getDate(d2, 2);
                diaDevolucao = this.getDate(d2, 3);
                if(anoRetirada - anoDevolucao < 0 || (anoRetirada - anoDevolucao == 0 && 
                    mesRetirada - mesDevolucao < 0) || (anoRetirada - anoDevolucao == 0 && 
                    mesRetirada - mesDevolucao == 0 && diaRetirada - diaDevolucao <= 0))
                {
                    return 6;
                }
                else 
                    return 0;
                
            }
        }
        return 0;
    }
    
    /* Esse método simples será encarregado de apenas exibir o modelo do veículo */
    public String exibirModeloVeiculo(Veiculo veiculo)
    {
        // Veiculo v = buscar(veiculo);
        return veiculo.getModelo();
        //return "todo";
    }
    
    /* O local de retirada é informado através desse método */
    public String informarLocalRetirada()
    {
        return "Dirija Campo Grande";
    }
    
    /* Esse método toma as datas inicial e final de um aluguel, o valor do aluguel por dia para um determinado
    veículo e retorna o montante total a ser pago */
    public float calcularValorTotal(Veiculo veiculo, String dataRetirada, String dataDevolucao)
    {
        float valor_total = 0.00f;
        int anoRetirada, anoDevolucao, mesRetirada, mesDevolucao, 
            diaRetirada, diaDevolucao, flg = 0, dias = 0;
        anoRetirada = this.getDate(dataRetirada, 1);
        mesRetirada = this.getDate(dataRetirada, 2);
        diaRetirada = this.getDate(dataRetirada, 3);
        anoDevolucao = this.getDate(dataDevolucao, 1);
        mesDevolucao = this.getDate(dataDevolucao, 2);
        diaDevolucao = this.getDate(dataDevolucao, 3);
        flg = this.anoBissexto(anoRetirada);
        /* Esse while deve, a grosso modo, verificar as reservas feitas de final de ano com 
        entrega previstas para o outro ano */
        while(anoRetirada < anoDevolucao)
        {
            /* Verifica se exatamente um ano se passou */
            if(mesDevolucao - mesRetirada == 0)
            {
                if(flg == 1)
                {
                    dias += 366;
                }
                else
                {
                    dias += 365;
                    flg = 0;
                }
            }
            while(mesRetirada <= 12)
            {
                /* Fevereiro */
                if(mesRetirada == 2)
                {
                    /* Ano bissexto */
                    if(flg == 1)
                        dias += 29;
                    else
                        dias += 28;
                }
                /* Janeiro - Agosto */
                else if(mesRetirada < 8)
                {
                    if(mesRetirada % 2 == 0)
                        dias += 31;
                    else
                        dias += 30;
                }
                /* Setembro - Dezembro */
                else
                {
                    if(mesRetirada % 2 != 0)
                        dias += 30;
                    else
                        dias += 31;
                }
                mesRetirada++;
            }
            anoRetirada++;
            mesRetirada = 1;
        }
        /* Aqui, a verificação de entrega no mesmo ano é feita */
        while(mesRetirada <= 12 && mesRetirada < mesDevolucao)
        {
            /* Fevereiro */
            if(mesRetirada == 2)
            {
                /* Ano bissexto */
                if(flg == 1)
                    dias += 29;
                else
                    dias += 28;
            }
            /* Janeiro-Julho */
            else if(mesRetirada < 8)
            {
                if(mesRetirada % 2 != 0)
                    dias += 31;
                else
                    dias += 30;
            }
            /* Agosto-Dezembro */
            else
            {
                if(mesRetirada % 2 != 0)
                    dias += 30;
                else
                    dias += 31;
            }
            if(mesRetirada == 12)
                mesRetirada = 0;
            else
                mesRetirada++;
        }
        /* Três condicionais verificam os dias - caso ele seja zero, então a devolução é para o próprio 
        dia que foi alugado, logo o valor de uma diária é cobrado; caso contrário, os condicionais seguintes
        identificam propriamente qual a quantidade de dias a ser somada */
        if(diaDevolucao-diaRetirada == 0 && dias == 0)
            dias = 1;
        else if(diaDevolucao >= diaRetirada)
            dias += Math.abs((diaRetirada-diaDevolucao));
        else if(diaDevolucao < diaRetirada)
            dias -= Math.abs((diaRetirada-diaDevolucao));
        System.out.printf("Quantidade de dias: %d\n", dias);
        valor_total = dias * veiculo.getPrecoDia();
        return valor_total;
    }
    
    /* No método abaixo temos o cálculo de quanto será cada parcela do valor total, caso o cliente desejar
    pagar à prazo. O arrendodamento empírico é justificado como um pequeno adicional devido ao pagamento 
    ser por prestações */
    public float calcularValorPrazo(float valor_total, int prestacoes)
    {
        return (float) Math.ceil(valor_total/(float)prestacoes);
    }
    
    /* Esse método tem o propósito genérico de receber um sinal e gerar diferentes avisos com base nele */
    public String gerarMensagem(int sinal)
    {
        String s = new String();
        switch(sinal)
        {
            case 1:
                s = "O cliente solicitado já se encontra em outro aluguel. "
                        + "O aluguel do veículo não pôde ser concluído.";
                break;
            case 2:
                s = "Carteira de motorista vencida.";
                break;
            case 3:
                s = "Nenhum veículo disponível para uso.";
                break;
            case 4:
                s = "Data inválida.";
                break;
            case 5: 
                s = "A data de devolução antecede a data de retirada.";
                break;
            case 6:
                s = "O veículo não pode ser alugado nesse período pois há uma reserva associada.";
            default:
                // Não faça nada
                break;
        }
        return s;
    }
    
    /* Nesse método, um objeto do tipo Aluguel é criado, seus valores são propriamente atribuídos e sua
    persistência no banco é realizada */
    public String finalizarAluguel(Cliente cli, Veiculo veiculo, String localRetirada, 
            String estabelecimentoDevolucao, String dataRetirada, String dataDevolucao, byte formaPagamento, 
            float valorTotal)
    {
        Aluguel rent = new Aluguel();
        rent.setCliente(cli);
        rent.setVeiculo(veiculo);
        rent.setLocalRetirada(localRetirada);
        rent.setEstabelecimentoDevolucao(estabelecimentoDevolucao);
        rent.setDataRetirada(dataRetirada);
        rent.setDataDevolucao(dataDevolucao);
        rent.setPagamento(formaPagamento);
        rent.setValorTotal(valorTotal);
        rent.setSituacao("Em andamento");
        Reserva res = Reserva.buscar(cli);
        String sit;
        if(res != null)
        {
            sit = res.getSituacao();
            if(sit.equals("Aberta"))
            {
                rent.setReserva(res);
            }
        }
        System.out.println(rent.getDataRetirada());
        System.out.println(rent.getDataDevolucao());
        Aluguel.queryStream.runSQL("INSERT INTO Aluguel (Aluguel.CPF_cliente,"
                + "Aluguel.chassi_veiculo, Aluguel.valor_total, Aluguel.forma_pagamento, "
                + "Aluguel.situacao_servico, Aluguel.data_retirada, Aluguel.data_devolucao,"
                + "Aluguel.localRetirada, Aluguel.estabelecimentoDevolucao) VALUES "
                + "('" + cli.getCpf() + "', '" +  veiculo.getChassi() + "', " + rent.getValorTotal() + ", '"
                + rent.getFormaPagamento() + "', " + "'Em andamento', '" + rent.getDataRetirada() + 
                "', '" + rent.getDataDevolucao() + "', '" + rent.getLocalRetirada() + "', '" 
                + rent.getEstabelecimentoDevolucao() + "')");
        Veiculo.queryStream.runSQL("UPDATE Veiculo SET Veiculo.situacao='O' WHERE Veiculo.chassi='"
                + veiculo.getChassi() + "'");
        return "Aluguel efetuado com sucesso.";
    }
}
