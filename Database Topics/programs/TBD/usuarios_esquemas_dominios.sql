--1. CRIA��O DE USU�RIOS
CREATE USER loja_shopcar WITH ENCRYPTED PASSWORD 'loja_adj';
CREATE USER anunciante_shopcar WITH ENCRYPTED PASSWORD 'anun_adj'; --anunciante � um usu�rio do site, mas que possui um an�ncio.
CREATE USER usuario_shopcar WITH ENCRYPTED PASSWORD 'user_adj';
--END CRIA��O DE USU�RIOS
--OK


--2. CRIA��O DE ESQUEMAS
CREATE SCHEMA IF NOT EXISTS shopcar;
CREATE SCHEMA IF NOT EXISTS loja_shopcar;
CREATE SCHEMA IF NOT EXISTS anunciante_shopcar;
CREATE SCHEMA IF NOT EXISTS usuario_site_shopcar;
	--2.1 ALTERAR ESQUEMA CORRENTE PARA shopcar
	SET search_path=shopcar;
--END CRIA��O DE ESQUEMAS
--OK


--3. CRIA��O DE DOM�NIOS
CREATE DOMAIN placa_shopcar AS VARCHAR(7) NOT NULL;
CREATE DOMAIN tipocarro_shopcar AS TEXT NOT NULL;
CREATE DOMAIN uf_shopcar AS VARCHAR(2) NOT NULL DEFAULT 'AC' CONSTRAINT uf_const CHECK(VALUE IN('AC', 'AL', 'AM', 'AP', 'BA', 'CE', 'DF', 'ES', 'GO', 'MA', 'MG', 
'MS', 'MT', 'PA', 'PB', 'PE', 'PI', 'PR', 'RJ', 'RN', 'RO', 'RR', 'RS', 'SC', 'SE', 'SP', 'TO')); --isso torna a cria��o da tabela uf desncess�ria. mapeei para o dominio pois
--nao espero que adicionem estados t�o cedo :P
CREATE DOMAIN combustivel_shopcar AS TEXT NOT NULL DEFAULT 'gasolina';
CREATE DOMAIN cnpj_shopcar AS VARCHAR(15) NOT NULL;
CREATE DOMAIN cpf_shopcar AS VARCHAR(11) NOT NULL;
CREATE DOMAIN positivo AS INTEGER NOT NULL DEFAULT 0 CONSTRAINT positivo_const CHECK (VALUE >= 0);
CREATE DOMAIN ano_veiculo AS INTEGER NOT NULL DEFAULT 1995 CONSTRAINT ano_const CHECK (VALUE >= 1920 AND VALUE <= 1995);
CREATE DOMAIN reais AS DOUBLE PRECISION NOT NULL DEFAULT 0.00 CONSTRAINT reais_const CHECK (VALUE >= 0.00);
CREATE DOMAIN ano_modelo AS INT NOT NULL DEFAULT 1995 CONSTRAINT anomodelo_const CHECK(VALUE >= 1920 AND VALUE <= 1996);
--END CRIA��O DE DOM�NIOS
--OK