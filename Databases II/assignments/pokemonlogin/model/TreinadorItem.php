<?php



class TreinadorItem
{
    
    private $id_treinador;
    private $codigo_item;
    private $quantidade;
    private $nome_item;
    private $preco;
    
    public function getNome_item() {
        return $this->nome_item;
    }

    public function setNome_item($nome_item) {
        $this->nome_item = $nome_item;
    }

    public function getPreco() {
        return $this->preco;
    }

    public function setPreco($preco) {
        $this->preco = $preco;
    }

        
    public function getId_treinador() {
        return $this->id_treinador;
    }

    public function setId_treinador($id_treinador) {
        $this->id_treinador = $id_treinador;
    }

    public function getCodigo_item() {
        return $this->codigo_item;
    }

    public function setCodigo_item($codigo_item) {
        $this->codigo_item = $codigo_item;
    }

    public function getQuantidade() {
        return $this->quantidade;
    }

    public function setQuantidade($quantidade) {
        $this->quantidade = $quantidade;
    }


    
    
}
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>
