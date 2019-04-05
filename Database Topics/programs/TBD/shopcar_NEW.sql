--shopcar.sql
--*---------------------------------------------------------------------------------*
--* PRIMEIRO TRABALHO DE TÓPICOS EM BANCO DE DADOS								    *
--* PROFESSOR HÉRCULES DA COSTA SANDIM											    *
--* ALUNOS: Aimée Sousa Calepso, Diego Silva Cintra e Jainor Souza Ribeiro da Cunha *
--*---------------------------------------------------------------------------------*

--*ÍNDICE:	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*
--* 	 1. CRIAÇÃO DOS NOVOS USUÁRIOS	.	.	.	.	.	.	34	*
--*		 2. CRIAÇÃO DE ESQUEMAS	.	.	.	.	.	.	.	.	42	*
--*			2.1. ALTERAR ESQUEMA CORRENTE PARA shopcar	.	.	48	*
--*		 3. CRIAÇÃO DE DOMÍNIOS	.	.	.	.	.	.	.	.	54	*
--*		 4. CRIAÇÃO DE RELAÇÕES	.	.	.	.	.	.	.	.	69	*
--*			4.1. RELAÇÃO Loja	.	.	.	.	.	.	.	.	90	*
--*			4.2. RELAÇÃO Tipo	.	.	.	.	.	.	.	.	117	*
--*			4.3. RELAÇÃO Combustível	.	.	.	.	.	.	127	*	
--*			4.4. RELAÇÃO Cor	.	.	.	.	.	.	.	.	140	*
--*			4.5. RELAÇÃO MarcaCarro	.	.	.	.	.	.	.	159	*	
--*			4.6. RELAÇÃO MarcaCaminhao	.	.	.	.	.	.	169	*
--*			4.7. RELAÇÃO MarcaOnibusVans	.	.	.	.	.	182	*
--*			4.8. RELAÇÃO MarcaTratoresRebocaveis	.	.	.	196	*
--*			4.9. RELAÇÃO Veiculo	.	.	.	.	.	.	.	205	*
--*			4.10.RELAÇÃO Opcionais	.	.	.	.	.	.	.	235	*
--*			4.11.RELAÇÃO OpcionaisVeiculo	.	.	.	.	.	246	*
--*			4.12.RELAÇÃO Usuario	.	.	.	.	.	.	.	265	*
--*			4.13.RELAÇÃO TipoAnuncio	.	.	.	.	.	.	292	*
--*			4.14.RELAÇÃO Anuncio	.	.	.	.	.	.	.	302	*
--*			4.15.RELAÇÃO AnuncioUsuario	.	.	.	.	.	.	314	*
--*			4.16.RELAÇÃO AnuncioLoja	.	.	.	.	.	.	324	*
--*		 5. TRIGGERS	.	.	.	.	.	.	.	.	.	.	337	*			
--*		 6. CRIAÇÃO DE VISÕES PARA OS NOVOS USUÁRIOS	.	.	529	*
--*	 	 7. ATRIBUIÇÃO DE PERMISSÕES AOS NOVOS USUÁRIOS	.	.	550	*
--*		 8. POVOAMENTO DE RELAÇÕES ESTÁTICAS	.	.	.	.	568	*
--*			8.1. RELAÇÃO TIPO	.	.	.	.	.	.	.	.	571	*
--*			8.2. RELAÇÃO COMBUSTÍVEL	.	.	.	.	.	.	578	*
--*			8.3. RELAÇÃO COR	.	.	.	.	.	.	.	.	591	*
--*			8.4. RELAÇÕES DE MARCA	.	.	.	.	.	.	.	628	*
--*				8.4.1. MARCAS DE CARROS	.	.	.	.	.	.	636	*
--*				8.4.2. MARCAS DE CAMINHÕES	.	.	.	.	.	730	*
--*				8.4.3. MARCAS DE ÔNIBUS/VANS	.	.	.	.	761	*
--*				8.4.4. MARCAS DE TRATORES/REBOCÁVEIS	.	.	812	*
--*			8.5. RELAÇÃO OPCIONAIS	.	.	.	.	.	.	.	871	*
--*			8.6. RELAÇÃO TipoAnuncio	.	.	.	.	.	.	913	*
--*		 9. POVOAMENTO PEDIDO PARA O BANCO	.	.	.	.	.	921	*
--*			9.1. POVOAMENTO DE VEÍCULOS	.	.	.	.	.	.		*
--*			9.2. POVOAMENTO DE LOJAS	.	.	.	.	.	.		*
--*			9.3. POVOAMENTO DE ANUNCIANTES	.	.	.	.	.		*
--*		*	*	*	*	*	*	*	*	*	*	*	*	*	*	*	*

--1. CRIAÇÃO DE USUÁRIOS
CREATE USER loja_shopcar WITH ENCRYPTED PASSWORD 'loja_adj';
CREATE USER anunciante_shopcar WITH ENCRYPTED PASSWORD 'anun_adj'; --anunciante é um usuário do site, mas que possui um anúncio.
CREATE USER usuario_shopcar WITH ENCRYPTED PASSWORD 'user_adj';
--END CRIAÇÃO DE USUÁRIOS
--OK


--2. CRIAÇÃO DE ESQUEMAS
CREATE SCHEMA IF NOT EXISTS shopcar;
CREATE SCHEMA IF NOT EXISTS loja_shopcar;
CREATE SCHEMA IF NOT EXISTS anunciante_shopcar;
CREATE SCHEMA IF NOT EXISTS usuario_site_shopcar;
	--2.1 ALTERAR ESQUEMA CORRENTE PARA shopcar
	SET search_path=shopcar;
--END CRIAÇÃO DE ESQUEMAS
--OK


--3. CRIAÇÃO DE DOMÍNIOS
CREATE DOMAIN placa_shopcar AS VARCHAR(7) NOT NULL;
CREATE DOMAIN tipocarro_shopcar AS TEXT NOT NULL;
CREATE DOMAIN uf_shopcar AS VARCHAR(2) NOT NULL DEFAULT 'AC' CONSTRAINT uf_const CHECK(VALUE IN('AC', 'AL', 'AM', 'AP', 'BA', 'CE', 'DF', 'ES', 'GO', 'MA', 'MG', 
'MS', 'MT', 'PA', 'PB', 'PE', 'PI', 'PR', 'RJ', 'RN', 'RO', 'RR', 'RS', 'SC', 'SE', 'SP', 'TO')); --isso torna a criação da tabela uf desncessária. mapeei para o dominio pois
--nao espero que adicionem estados tão cedo :P
CREATE DOMAIN combustivel_shopcar AS TEXT NOT NULL DEFAULT 'Gasolina';
CREATE DOMAIN cnpj_shopcar AS VARCHAR(15) NOT NULL;
CREATE DOMAIN cpf_shopcar AS VARCHAR(11) NOT NULL;
CREATE DOMAIN positivo AS INTEGER NOT NULL DEFAULT 0 CONSTRAINT positivo_const CHECK (VALUE >= 0);
CREATE DOMAIN ano_veiculo AS INTEGER NOT NULL DEFAULT 1995 CONSTRAINT ano_const CHECK (VALUE >= 1920 AND VALUE <= 2015);
CREATE DOMAIN reais AS DOUBLE PRECISION NOT NULL DEFAULT 0.00 CONSTRAINT reais_const CHECK (VALUE >= 0.00);
CREATE DOMAIN ano_modelo AS INT NOT NULL DEFAULT 1995 CONSTRAINT anomodelo_const CHECK(VALUE >= 1920 AND VALUE <= 2016);
--END CRIAÇÃO DE DOMÍNIOS
--OK

--4. CRIAÇÃO DE RELAÇÕES
--LOJA
	--Para aderir novas lojas ao sistema, pede-se: 
	--Razão social, Nome, CNPJ, email, website, responsavel, telefone da loja, celular do responsavel, (quantidade de anuncios), 
	--endereço(rua e numero), cep, bairro, cidade e estado 
CREATE TABLE IF NOT EXISTS Loja
(
	cnpj cnpj_shopcar,
	nome TEXT NOT NULL,
	email TEXT NOT NULL,
	website TEXT,
	responsavel TEXT NOT NULL,
	telefone_loja BIGINT,
	celular_responsavel BIGINT NOT NULL,
	endereco TEXT NOT NULL,
	cep INT NOT NULL,
	bairro TEXT NOT NULL,
	cidade TEXT NOT NULL,
	estado uf_shopcar,
	CONSTRAINT loja_shopcar_pk PRIMARY KEY(cnpj)
);
--END LOJA
--OK

--VEICULOS
	--Para cadastrar veículos, o sistema pede:
	--Tipo, Marca, Modelo, Ano de fabricação, ano do modelo, cor, combustível, quilometragem, placa, {opcionais}, preço
	--Mais opcionais(um espaço de texto, que são acessórios do veículo), descrição (texto sobre a situação geral) e
	--observações adicionais(condições de pagamento e negociação)


	--Onde Tipo pode ser: carro, onibus ou vans, caminhoes, tratores ou rebocaveis 
CREATE TABLE IF NOT EXISTS Tipo
(
	tipo_id SERIAL NOT NULL,
	nome_tipo tipocarro_shopcar,
	CONSTRAINT tipo_shopcar_pk PRIMARY KEY(tipo_id),
	CONSTRAINT tipo_unique UNIQUE(nome_tipo)
);
--OK

	--Onde combustivel pode ser: gasolina, alcool, diesel, kit gas, bicombustivel, triflex ou eletrico
CREATE TABLE IF NOT EXISTS Combustivel
(
	comb_id SERIAL NOT NULL,
	nome_combustivel combustivel_shopcar,
	CONSTRAINT combustivel_shopcar_pk PRIMARY KEY (comb_id),
	CONSTRAINT combustivel_unique UNIQUE(nome_combustivel)
);
--OK

	--tem uma negada de opção de cor tb, poderia ser uma tripla de inteiros, pq tem função rgb no postgresql mas né, enfim, as opções são:
	--Amarela, amarela/preta, azul, bege, bordo, branca, branca/azul, branca/marrom, branca/preta, branca/vermelha, branca/roxa, branca/verde,
	--Chumbo, cinza, diversas, dourada, grafite, grena, laranja, marrom, prata, preta, preta/azul, preta/cinza, preta/prata, preta/roxa, preta/verde,
	--Preta/vermelha, rosa, roxa, verde, verde/vermelha, vinho, vinho/bege (34 cores)
CREATE TABLE IF NOT EXISTS Cor
(
	cor_id SERIAL NOT NULL,
	nome_cor TEXT NOT NULL,
	CONSTRAINT cor_pk PRIMARY KEY (cor_id),
	CONSTRAINT cor_unique UNIQUE(nome_cor)
);
--OK


	--Tem Marca adoidado. Mas ok, as marcas para todos os veículos são:
	--Citroen, fiat, ford, Chevrolet ou GM, Honda, Hyundai, Kia, Mitsubishi, Nissan, Peugeot, Renault, Toyota,
	--Volkswagen ou VW, Adamo, Agrale, Alfa Romeo, AM General, Americar, ASIA motors, Aston Martin, Audi,
	--Bentley, BMW, BRM ou Buggy, Bugatti, Bugre, Buick, Cadillac,  CBT, Chamonix, Chana, Changan, Chery,
	--Chrysler, Daewoo, Daihatsu, DKW ou Vemag, Dodge, Effa, Engesa, Envemo, Farus, Ferrari, GMC, Gurgel,
	--Hafei, Infiniti, Internacional Harvester, JAC, Jaguar, Jeep, JPX, Lada, Lamborghini, Land Rover, Lexus,
	--Lifan, Lincoln, Mahindra, Maseratti, Mazda, Mercedes-Benz, Mercury, MG, Mini, Miura, Morris, MP, Plymouth,
	--Pontiac, Porsche, Pretty, Puma, Ram, Rely, Rolls-Royce, Santa Matilde, Saturn, Seat, Shelby, Shineray, Smart,
	--SSangyong, Subaru, Suzuki, TAC, Troller, Volvo, Willys Overland e|OUTRAS|
CREATE TABLE IF NOT EXISTS MarcaCarro
(
	nome_marca TEXT NOT NULL,
	CONSTRAINT marcacarro_pk PRIMARY KEY (nome_marca)
);
--OK

	--Marcas para Caminhões:
	--Agrale, ASIA Motors, Dodge, EFFA-JMC, Engesa, FIAT, FORD, Chevrolet/GM, GMC, Hyundai, Iveco, JAC, KIA,
	--Mercedes-Benz, Navistar, PUMA, Randon, Renault, Scania, Sinotruk, Terex, Volvo, Volkswagen, |OUTRAS|
CREATE TABLE IF NOT EXISTS MarcaCaminhao
(
	nome_marca TEXT NOT NULL,
	CONSTRAINT marcacaminhao_pk PRIMARY KEY(nome_marca)

);


	--Marcas para Onibus/Vans:
	--Agrale, ASIA Motors, BUSSCAR, Caio, Chana, Changan, CICCOBUS, CIFERAL, CITROEN, COBRASMA, COMIL, EFFA,
	--FIAT, Ford, Chevrolet/GM, Hafei, Hyundai, Irizar, Iveco, JAC, Jimbei, Jotave, KIA, MAFERSA, MARCOPOLO,
	--MASCARELLO, Maxibus, Mercedes-Benz, Mitsubishi, Neobus, Nielson, Peugeot, Rely, Renault, Scania, Shineray,
	--Ssangyong, Tecnobus, Thamco, Volvo, Volkswagen, Walkbus, |OUTRAS|
CREATE TABLE IF NOT EXISTS MarcaOnibusVans
(
	nome_marca TEXT NOT NULL,
	CONSTRAINT marcaonibusvans_pk PRIMARY KEY(nome_marca)

);

	--Marcas para Tratores/Rebocáveis:
	--Agrale, Angola, Bobcat, Budny, Bueno, Case, Caterpillar, CBT, CLARK, Dambroz, Facchini, Fiatallis, FORD,
	--Galego, GUERRA, Gurgel, Halley, Huber Warco, Hyster, Hyundai, JCB, John Deere, Komatsu, Krone, Lonking,
	--MADAL, Massey Ferguson, MAXION, Michigan, Mitsubishi, Moto Kar, Muller, New Holland, Noma, Pauli, Piccin,
	--Randon, Rodoking, Schiffer, SDLG, Star Trailer, Tema Terra, Tobatta, Toyota, Tramontini, Valmet, Valtra, Volvo,
	--Wecan, Yale, Yanmar, |OUTRAS|

CREATE TABLE IF NOT EXISTS MarcaTratoresRebocaveis
(
	nome_marca TEXT NOT NULL,
	CONSTRAINT marcatratoresrebocaveis_pk PRIMARY KEY(nome_marca)

);


	--relação veículo
CREATE TABLE IF NOT EXISTS Veiculo
(
	placa placa_shopcar,
	tipo_id INTEGER NOT NULL,
	modelo TEXT NOT NULL DEFAULT 'modelo default',
	marca TEXT NOT NULL,
	cor_id INTEGER NOT NULL,
	comb_id INTEGER NOT NULL,
	ano_carro ano_veiculo,
	ano_modelo_veiculo ano_modelo,
	preco reais,
	km positivo,
	mais_opcionais TEXT NOT NULL DEFAULT 'Nenhuma informação adicional.', 
	descricao TEXT,
	CONSTRAINT veiculo_shopcar_pk PRIMARY KEY (placa),
	CONSTRAINT veiculo_tipo_fk FOREIGN KEY (tipo_id) REFERENCES Tipo (tipo_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	CONSTRAINT veiculo_cor_fk FOREIGN KEY (cor_id) REFERENCES Cor (cor_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	CONSTRAINT veiculo_comb_fk FOREIGN KEY (comb_id) REFERENCES Combustivel (comb_id) ON DELETE RESTRICT ON UPDATE CASCADE
);
--OK


	--Opcionais, tem opcionais a dar com pau:
	--Eles são Air Bag, Air Bag Duplo, Alarme, Ar Condicionado, Ar Quente, Banco de Couro, Básica,
	--Básico, Câmbio Automático, Câmbio Sequencial, Capota Marítima, Completa, Direção Hidráulica,
	--Completo, Computador de Bordo, Desembaçador Traseiro, Direção Elétrica, Disqueteira CD,
	--Engate ou Rabicho, Estribo, Farol de Neblina, Farol Xenon, Freios ABS, Kit GNV,
	--Limpaodr e Desembaçador Traseiro, Limpador Traseiro, MP3 Player, Piloto Automático,
	--Protetor de Caçamba, Retrovisor Elétrico, Rodas, Santo Antônio, Trava Elétrica,
	--Sensor de Estacionamento, Som CD, Teto Solar, Tração 4X4, Vidro Elétrico (38 opcionais)
CREATE TABLE IF NOT EXISTS Opcionais
(
	id SERIAL NOT NULL,
	nome_opcional TEXT NOT NULL,
	CONSTRAINT opcionais_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT opcionais_unique UNIQUE(nome_opcional)

);
--OK

	--Juntando opcionais aos veiculos
CREATE TABLE IF NOT EXISTS OpcionaisVeiculo
(
	id SERIAL NOT NULL,
	placa placa_shopcar,
	id_opcional INT NOT NULL,
	CONSTRAINT opcionaisveiculo_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT opcionaisveiculo_veiculo_fk FOREIGN KEY(placa) REFERENCES Veiculo(placa) ON UPDATE CASCADE ON DELETE RESTRICT,
	CONSTRAINT opcionaisveiculo_opcionais_fk FOREIGN KEY(id_opcional) REFERENCES Opcionais(id) ON UPDATE CASCADE ON DELETE RESTRICT,
	CONSTRAINT opcionaisveiculo_placa_unique UNIQUE(placa)
);
--OK


--END VEICULOS

--USUÁRIOS DO SITE
	--Para cadastrar usuários, o sistema pede:
	--Nome Completo, CPF, Endereço(rua), Complemento, Bairro, UF, Cidade, Telefone, email e senha

CREATE TABLE IF NOT EXISTS Usuario
(
	cpf cpf_shopcar,
	nome TEXT NOT NULL,
	endereco TEXT NOT NULL,
	complemento TEXT DEFAULT 'Sem complementos.',
	bairro TEXT NOT NULL,
	uf uf_shopcar,
	cidade TEXT NOT NULL,
	telefone BIGINT NOT NULL,
	email TEXT NOT NULL,
	senha TEXT NOT NULL,
	CONSTRAINT usuario_shopcar_pk PRIMARY KEY(cpf),
	CONSTRAINT usuario_email_unique UNIQUE(email)
);
--OK

--END USUARIOS DO SITE

--Anunciante
	--Para separar usuario_site de anunciante, criaremos a relação anunciante
	--Com ela, vemos a necessidade de ter: o tipo do anúncio suportado pelo site shopcar e
	--Verificar se o anúncio é de uma loja ou de um usuário
	
	
	--Onde o tipo pode ser: grátis, bronze, prata, ouro e até vender (5 tipos)
	--O preço dos tipos é, respectivamente, 0, 20, 40, 75 e 90 reais
CREATE TABLE IF NOT EXISTS TipoAnuncio
(
	id SERIAL NOT NULL,
	nome_tipo TEXT NOT NULL,
	preco reais,
	CONSTRAINT tipoanuncio_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT tipoanuncio_nome_unique UNIQUE(nome_tipo)

);	

CREATE TABLE IF NOT EXISTS Anuncio
(
	id SERIAL NOT NULL,
	tipo_anuncio INT NOT NULL,
	placa placa_shopcar,
	id_anunciante TEXT NOT NULL, --pode ser um cnpj ou um cpf, somente usuários cadastrados podem fazer inserção aqui.
	CONSTRAINT anuncio_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT anuncio_tipoanuncio_fk FOREIGN KEY(tipo_anuncio) REFERENCES TipoAnuncio(id) ON UPDATE CASCADE ON DELETE RESTRICT,
	CONSTRAINT anuncio_veiculo_fk FOREIGN KEY(placa) REFERENCES Veiculo(placa) ON UPDATE CASCADE ON DELETE RESTRICT

);

CREATE TABLE IF NOT EXISTS AnuncioUsuario
(
	id SERIAL NOT NULL,
	anuncio_id INT NOT NULL,
	cpf_usuario cpf_shopcar,
	CONSTRAINT anunciousuario_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT anunciousuario_anuncio_fk FOREIGN KEY(anuncio_id) REFERENCES Anuncio(id) ON UPDATE CASCADE ON DELETE RESTRICT,
	CONSTRAINT anunciousuario_usuario_fk FOREIGN KEY(cpf_usuario) REFERENCES Usuario(cpf) ON UPDATE CASCADE ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS AnuncioLoja
(
	id SERIAL NOT NULL,
	anuncio_id INT NOT NULL,
	cnpj_loja cnpj_shopcar,
	CONSTRAINT anuncioloja_shopcar_pk PRIMARY KEY(id),
	CONSTRAINT anuncioloja_anuncio_fk FOREIGN KEY(anuncio_id) REFERENCES Anuncio(id) ON UPDATE CASCADE ON DELETE RESTRICT,
	CONSTRAINT anuncioloja_loja_fk FOREIGN KEY(cnpj_loja) REFERENCES Loja(cnpj) ON UPDATE CASCADE ON DELETE RESTRICT
);

--END CRIAÇÃO DE RELAÇÕES


--5. TRIGGERS
	--CHECAR @ EM Usuario.email
	CREATE OR REPLACE FUNCTION checa_email() RETURNS TRIGGER AS $BODY$
		DECLARE arroba_pos INT;
		DECLARE com_pos INT;
		BEGIN
			arroba_pos = position('@' IN NEW.email);
			com_pos = position('.com' IN NEW.email);
			IF(arroba_pos = 0 OR arroba_pos = char_length(NEW.email) OR
			   arroba_pos = 1 OR com_pos = 0 OR arroba_pos = com_pos-1) AND TG_OP = 'INSERT' THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: % eh um email invalido!', TG_NAME, TG_TABLE_NAME, NEW.email 
									 USING HINT = 'Por favor cheque o email inserido.';
			
			ELSIF(arroba_pos = 0 OR arroba_pos = char_length(NEW.email) OR
				  arroba_pos = 1 OR com_pos = 0 OR arroba_pos = com_pos-1) AND TG_OP = 'UPDATE' THEN
					RAISE NOTICE 'TRIGGER %, DA RELACAO %: % eh um email invalido!', TG_NAME, TG_TABLE_NAME, NEW.email 
								  USING HINT = 'Por favor cheque o email inserido. O email antigo foi mantido.';
					
					NEW.email = OLD.email;
			END IF;
			RETURN NEW;
		END;
	$BODY$ LANGUAGE 'plpgsql';
		
	CREATE TRIGGER checar_email BEFORE INSERT OR UPDATE ON shopcar.Usuario FOR EACH ROW EXECUTE PROCEDURE checa_email();
	CREATE TRIGGER checar_email_loja BEFORE INSERT OR UPDATE ON shopcar.Loja FOR EACH ROW EXECUTE PROCEDURE checa_email();
	--END CHECAR @ EM Usuario.email
	--OK
	
	
	--CHECAR SE Veiculo.placa TEM 3 LETRAS SEGUIDAS DE 4 NÚMEROS ### 65..90 = ascii para letras maiusculas, 97..122 = ascii para letras minusculas, 48..57 = ascii para 0 a 9
	CREATE OR REPLACE FUNCTION checa_placa() RETURNS TRIGGER AS $$
		DECLARE placa_tam INT;
		DECLARE placa_arr TEXT[];
		BEGIN
			placa_tam = char_length(NEW.placa);
			placa_arr = regexp_split_to_array(NEW.placa, E'');
			IF placa_tam < 7 AND TG_OP = 'INSERT' THEN
				RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: atualmente, as placas brasileiras possuem sete caracteres, desconsiderando o hifen(-)!', TG_NAME, TG_TABLE_NAME 
								 USING HINT = 'A placa informada possui menos que sete caracteres!';
			
			ELSIF placa_tam < 7 AND TG_OP = 'UPDATE' THEN
				RAISE NOTICE 'TRIGGER %, DA RELACAO %: a nova placa nao possui sete caracteres. A placa antiga foi mantida.';
				NEW.placa = OLD.placa;
			
			END IF;
			
			
			FOR i IN 1..7 LOOP
				IF (i <= 3) AND ((ascii(placa_arr[i]) < 65 ) OR (ascii(placa_arr[i]) > 90)) AND ((ascii(placa_arr[i]) < 97) OR ( ascii(placa_arr[i]) > 122)) AND TG_OP = 'INSERT' THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: a placa inserida nao eh valida!', TG_NAME, TG_TABLE_NAME
									 USING HINT = 'O modelo de placas eh XXXAAAA, onde X eh uma letra e A eh um numero. Cheque sua placa.';
					
				ELSIF (i <= 3) AND ((ascii(placa_arr[i]) < 65 ) OR (ascii(placa_arr[i]) > 90)) AND ((ascii(placa_arr[i]) < 97) OR ( ascii(placa_arr[i]) > 122)) AND  TG_OP = 'UPDATE' THEN
					RAISE NOTICE 'TRIGGER %, DA RELACAO %: a nova placa nao eh valida!', TG_NAME, TG_TABLE_NAME
								  USING HINT='O modelo de placas eh XXXAAAA, onde X eh uma letra e A eh um numero. A placa antiga foi mantida.';
					NEW.placa = OLD.placa;
				
				
				ELSIF (i > 3) AND ((ascii(placa_arr[i]) < 48) OR (ascii(placa_arr[i]) > 57)) AND TG_OP = 'INSERT' THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: a placa inserida não é valida!', TG_NAME, TG_TABLE_NAME
									 USING HINT = 'O modelo de placas eh XXXAAAA, onde X eh uma letra e A eh um numero. Cheque sua placa.';
				
				ELSIF (i > 3) AND ((ascii(placa_arr[i]) < 48) OR (ascii(placa_arr[i]) > 57)) AND TG_OP = 'UPDATE' THEN
					RAISE NOTICE 'TRIGGER %, DA RELACAO %: a nova placa nao eh valida!', TG_NAME, TG_TABLE_NAME
								  USING HINT='O modelo de placas eh: XXXAAAA, onde X eh uma letra e A eh um numero. A placa antiga foi mantida.';
					NEW.placa = OLD.placa;
				
				END IF;

			END LOOP;
			RETURN NEW;
		END;
	$$ LANGUAGE 'plpgsql';
	
	CREATE TRIGGER checar_placa_veiculo BEFORE INSERT OR UPDATE OF placa ON shopcar.Veiculo FOR EACH ROW EXECUTE PROCEDURE checa_placa();
	CREATE TRIGGER checar_placa_anuncio BEFORE INSERT ON shopcar.Anuncio FOR EACH ROW EXECUTE PROCEDURE checa_placa();
	
	--END CHECAR Veiculo.placa
	--OK!!! :-)
	
	
	--VERIFICAR Veiculo.marca DE ACORDO COM Veiculo.tipo E, se a marca=|OUTRAS|, o campo descricao deve conter qual.
	CREATE OR REPLACE FUNCTION checa_marca() RETURNS TRIGGER AS $$
		DECLARE tipo_nome TEXT;
		BEGIN
			SELECT Tipo.nome_tipo FROM shopcar.Veiculo JOIN shopcar.Tipo ON (Veiculo.tipo_id=Tipo.tipo_id) WHERE Veiculo.tipo_id=NEW.tipo_id INTO tipo_nome;
			IF tipo_nome='Carro' THEN
				IF NEW.marca NOT IN (SELECT nome_marca FROM MarcaCarro) THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: Marca de Carro inexistente.', TG_NAME, TG_TABLE_NAME;
				
				END IF;
				
			ELSIF tipo_nome='Ônibus ou Vans' THEN
				IF NEW.marca NOT IN(SELECT nome_marca FROM MarcaOnibusVans) THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELAÇAO %: Marca de Onibus/Vans inexistente.', TG_NAME, TG_TABLE_NAME;
				
				END IF;
				
			ELSIF tipo_nome='Caminhões' THEN
				IF NEW.marca NOT IN(SELECT nome_marca FROM MarcaCaminhao) THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: Marca de Caminhoes inexistente.', TG_NAME, TG_TABLE_NAME;
				END IF;
			
			ELSIF tipo_nome='Tratores ou Rebocáveis' THEN
				IF NEW.marca NOT IN(SELECT nome_marca FROM MarcaTratoresRebocaveis) THEN
					RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: Marca de Tratores/Rebocaveis inexistente.', TG_NAME, TG_TABLE_NAME;
				END IF;
			
			END IF;
			IF NEW.marca = '|OUTRAS|' AND (NEW.descricao IS NULL OR NEW.descricao='') THEN
				RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: Se a marca = |OUTRAS|, voce deve especificar qual no campo descricao!', TG_NAME, TG_TABLE_NAME USING HINT = 'Sua descrição está vazia!';
		
			END IF;
			RETURN NEW;
		END;
	$$ LANGUAGE 'plpgsql';
	
	CREATE TRIGGER checar_marca BEFORE INSERT ON shopcar.Veiculo FOR EACH ROW EXECUTE PROCEDURE checa_marca();
	
	--END CHECAR MARCA
	--OK

	--CHECAR '/' EM Loja.cnpj
	CREATE OR REPLACE FUNCTION checa_cnpj() RETURNS TRIGGER AS $BODY$
		DECLARE slash_pos INT;
		BEGIN
			slash_pos = position('/' IN NEW.cnpj);
			IF slash_pos <> 9 AND TG_OP = 'INSERT' THEN
				RAISE EXCEPTION 'TRIGGER %, DA RELACAO %: O CNPJ de sua Loja deve nao possuir pontos, mas deve possuir a "/" separadora!', TG_NAME, TG_TABLE_NAME
								 USING HINT = 'Por favor verifique o CNPJ inserido.';
			
			ELSIF slash_pos <> 9 AND TG_OP = 'UPDATE' THEN
				RAISE NOTICE 'TRIGGER %, DA RELACAO %: O CNPJ de sua Loja deve nao possuir pontos, mas deve possuir a "/" separadora!', TG_NAME, TG_TABLE_NAME
							  USING HINT = 'O CPNJ novo não condiz com o formato. O CNPJ antigo foi mantido.';
				NEW.cnpj = OLD.cnpj;
			END IF;
			RETURN NEW;
		END;
	$BODY$ LANGUAGE 'plpgsql';
	
	CREATE TRIGGER checar_cnpj BEFORE INSERT OR UPDATE OF cnpj ON shopcar.Loja FOR EACH ROW EXECUTE PROCEDURE checa_cnpj();
	
	--END CHECAR Loja.cnpj
	--OK
	
	--INSERIR ANÚNCIOS DE USUÁRIOS OU LOJAS NA DEVIDA RELAÇÃO
	CREATE OR REPLACE FUNCTION checa_anuncio() RETURNS TRIGGER AS $BODY$
		BEGIN
			IF current_user='loja_shopcar' THEN
				IF NEW.id_anunciante IN(SELECT Loja.cnpj FROM Loja WHERE Loja.cnpj=NEW.id_anunciante) THEN
					INSERT INTO shopcar.AnuncioLoja(anuncio_id, cnpj_loja) VALUES (NEW.id, NEW.id_anunciante);
				
				ELSE 
					RAISE EXCEPTION 'CNPJ nao encontrado no sistema.';
				
				END IF;
				
			ELSIF current_user='anunciante_shopcar' THEN
				IF NEW.id_anunciante IN (SELECT Usuario.cpf FROM Usuario WHERE Usuario.cpf=NEW.id_anunciante) THEN
					INSERT INTO shopcar.AnuncioUsuario(anuncio_id, cpf_usuario) VALUES(NEW.id, NEW.id_anunciante);
				ELSE
					RAISE EXCEPTION 'CPF nao encontrado no sistema.';
				END IF;
			
			ELSIF current_user='postgres' THEN
				IF NEW.id_anunciante IN(SELECT Loja.cnpj FROM Loja WHERE Loja.cnpj=NEW.id_anunciante) THEN
					INSERT INTO shopcar.AnuncioLoja(anuncio_id, cnpj_loja) VALUES (NEW.id, NEW.id_anunciante);
				ELSIF NEW.id_anunciante IN (SELECT Usuario.cpf FROM Usuario WHERE Usuario.cpf=NEW.id_anunciante) THEN
					INSERT INTO shopcar.AnuncioUsuario(anuncio_id, cpf_usuario) VALUES(NEW.id, NEW.id_anunciante);
				ELSE
					RAISE EXCEPTION 'Loja ou Usuarios nao encontrados no sistema.' USING HINT='Cheque o cpf/cnpj inseridos.';
				END IF;
			END IF;
			RETURN NEW;
		END;
	$BODY$ LANGUAGE 'plpgsql';
	
	CREATE TRIGGER checar_anuncio AFTER INSERT ON shopcar.Anuncio FOR EACH ROW EXECUTE PROCEDURE checa_anuncio();
	--END INSERIR ANÚNCIOS EM AnuncioLoja OU AnuncioUsuario, DE ACORDO COM CPF OU CNPJ INSERIDOS
	--OK
	
	--FAZER MD5 EM Usuario.senha
	CREATE OR REPLACE FUNCTION md5_senha() RETURNS TRIGGER AS $BODY$
		BEGIN
			NEW.senha = md5(NEW.senha);
			RETURN NEW;
		END;
	$BODY$ LANGUAGE 'plpgsql';
	
	CREATE TRIGGER md5_senha_usuario BEFORE INSERT ON shopcar.Usuario FOR EACH ROW EXECUTE PROCEDURE md5_senha();
	
	--END FAZER MD5 EM Usuario.senha
	--OK
	
	
	
--END TRIGGERS



--6. CRIAÇÃO DE VIEWS PARA DAR PERMISSÕES AOS USUÁRIOS NOVOS // usuários: loja_shopcar, anunciante_shopcar e usuario_shopcar
	--PARA loja_shopcar
	SET search_path=loja_shopcar;
	CREATE VIEW loja AS SELECT * FROM shopcar.Loja;
	CREATE VIEW loja_veiculo_de_loja AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Loja.nome, shopcar.Loja.website, shopcar.Loja.telefone_loja, shopcar.Loja.celular_responsavel, shopcar.Loja.endereco, shopcar.Loja.cidade, shopcar.Loja.estado FROM (shopcar.AnuncioLoja JOIN shopcar.Anuncio ON(shopcar.AnuncioLoja.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Loja ON(cnpj_loja=shopcar.Loja.cnpj) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	CREATE VIEW loja_veiculo_de_anunciante AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Usuario.nome, shopcar.Usuario.endereco, shopcar.Usuario.cidade, shopcar.Usuario.uf, shopcar.Usuario.telefone FROM (shopcar.AnuncioUsuario JOIN shopcar.Anuncio ON(shopcar.AnuncioUsuario.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Usuario ON(cpf_usuario=shopcar.Usuario.cpf) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	--OK
	
	
	--PARA anunciante_shopcar
	SET search_path=anunciante_shopcar;
	CREATE VIEW anunciante AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	CREATE VIEW anunciante_veiculo_de_loja AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Loja.nome, shopcar.Loja.website, shopcar.Loja.telefone_loja, shopcar.Loja.celular_responsavel, shopcar.Loja.endereco, shopcar.Loja.cidade, shopcar.Loja.estado FROM (shopcar.AnuncioLoja JOIN shopcar.Anuncio ON(shopcar.AnuncioLoja.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Loja ON(cnpj_loja=shopcar.Loja.cnpj) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	CREATE VIEW anunciante_veiculo_de_anunciante AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Usuario.nome, shopcar.Usuario.endereco, shopcar.Usuario.cidade, shopcar.Usuario.uf, shopcar.Usuario.telefone FROM (shopcar.AnuncioUsuario JOIN shopcar.Anuncio ON(shopcar.AnuncioUsuario.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Usuario ON(cpf_usuario=shopcar.Usuario.cpf) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	--OK
	
	
	--PARA usuario_shopcar;
	SET search_path=usuario_site_shopcar;
	CREATE VIEW usuario_site AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf NOT IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	CREATE VIEW usuario_veiculo_de_loja AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Loja.nome, shopcar.Loja.website, shopcar.Loja.telefone_loja, shopcar.Loja.celular_responsavel, shopcar.Loja.endereco, shopcar.Loja.cidade, shopcar.Loja.estado FROM (shopcar.AnuncioLoja JOIN shopcar.Anuncio ON(shopcar.AnuncioLoja.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Loja ON(cnpj_loja=shopcar.Loja.cnpj) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	CREATE VIEW usuario_veiculo_de_anunciante AS SELECT shopcar.Tipo.nome_tipo, shopcar.Veiculo.modelo, shopcar.Veiculo.marca, shopcar.Cor.nome_cor, shopcar.Combustivel.nome_combustivel, shopcar.Veiculo.ano_carro, shopcar.Veiculo.ano_modelo_veiculo, shopcar.Veiculo.preco, shopcar.Veiculo.km, shopcar.Veiculo.descricao, shopcar.Usuario.nome, shopcar.Usuario.endereco, shopcar.Usuario.cidade, shopcar.Usuario.uf, shopcar.Usuario.telefone FROM (shopcar.AnuncioUsuario JOIN shopcar.Anuncio ON(shopcar.AnuncioUsuario.anuncio_id=shopcar.Anuncio.id)) AS r1 JOIN shopcar.Veiculo ON (r1.placa=shopcar.Veiculo.placa)  JOIN shopcar.Usuario ON(cpf_usuario=shopcar.Usuario.cpf) JOIN shopcar.Tipo ON(shopcar.Veiculo.tipo_id=shopcar.Tipo.tipo_id) JOIN shopcar.Combustivel ON(shopcar.Veiculo.comb_id=shopcar.Combustivel.comb_id) JOIN shopcar.Cor ON (shopcar.Veiculo.cor_id=shopcar.Cor.cor_id);
	--OK

	
--END CRIAÇÃO DE VIEWS PARA OS USUÁRIOS

--7. PERMISSÕES DOS NOVOS USUÁRIOS
	--PARA loja_shopcar
	SET search_path=shopcar;
	GRANT USAGE ON SCHEMA loja_shopcar TO loja_shopcar;
	GRANT INSERT ON shopcar.Loja TO loja_shopcar;
	GRANT INSERT ON shopcar.Anuncio TO loja_shopcar;
	GRANT SELECT ON loja_shopcar.loja TO loja_shopcar;
	GRANT SELECT ON loja_shopcar.loja_veiculo_de_loja TO loja_shopcar;
	GRANT SELECT ON loja_shopcar.loja_veiculo_de_anunciante TO loja_shopcar;
	--OK
	
	--PARA anunciante_shopcar
	GRANT USAGE ON SCHEMA anunciante_shopcar TO anunciante_shopcar;
	GRANT INSERT ON shopcar.Anuncio TO anunciante_shopcar;
	GRANT SELECT ON anunciante_shopcar.anunciante TO anunciante_shopcar;
	GRANT SELECT ON anunciante_shopcar.anunciante_veiculo_de_loja TO loja_shopcar;
	GRANT SELECT ON anunciante_shopcar.anunciante_veiculo_de_anunciante TO loja_shopcar;
	
	--PARA usuario_shopcar
	GRANT USAGE ON SCHEMA usuario_site_shopcar TO usuario_shopcar;
	GRANT INSERT ON shopcar.Usuario TO usuario_shopcar;
	GRANT SELECT ON usuario_site_shopcar.usuario_site TO usuario_shopcar;
	GRANT SELECT ON selecao_usuario_site TO usuario_shopcar;
	GRANT SELECT ON usuario_site_shopcar.usuario_veiculo_de_loja TO loja_shopcar;
	GRANT SELECT ON usuario_site_shopcar.usuario_veiculo_de_anunciante TO loja_shopcar;
	
--END PERMISSÕES DOS NOVOS USUÁRIOS


--8. POVOAMENTO DE RELAÇÕES ESTÁTICAS AUXILIARES (DE ACORDO COM O SITE)

	--8.1. RELAÇÃO Tipo || Onde Tipo pode ser: carro, onibus ou vans, caminhoes, tratores ou rebocaveis 
	INSERT INTO Tipo(nome_tipo) VALUES ('Carro');
	INSERT INTO Tipo(nome_tipo) VALUES ('Ônibus ou Vans');
	INSERT INTO Tipo(nome_tipo) VALUES ('Caminhões');
	INSERT INTO Tipo(nome_tipo) VALUES ('Tratores ou Rebocáveis');
	
	
	--8.2. RELAÇÃO Combustível || Onde combustivel pode ser: gasolina, alcool, diesel, kit gas, bicombustivel, triflex, eletrico
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Gasolina');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Álcool');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Diesel');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Kit Gás');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Bicombustível');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Triflex');
	INSERT INTO Combustivel(nome_combustivel) VALUES ('Elétrico');
	
	
	
	--8.3. RELAÇÃO Cor ||Amarela, amarela/preta, azul, bege, bordo, branca, branca/azul, branca/marrom, branca/preta, branca/vermelha, branca/roxa, branca/verde,
	--Chumbo, cinza, diversas, dourada, grafite, grena, laranja, marrom, prata, preta, preta/azul, preta/cinza, preta/prata, preta/roxa, preta/verde,
	--Preta/vermelha, rosa, roxa, verde, verde/vermelha, vinho, vinho/bege (34 cores)
	INSERT INTO Cor(nome_cor) VALUES ('Amarela');
	INSERT INTO Cor(nome_cor) VALUES ('Amarela e Preta');
	INSERT INTO Cor(nome_cor) VALUES ('Azul');
	INSERT INTO Cor(nome_cor) VALUES ('Bege');
	INSERT INTO Cor(nome_cor) VALUES ('Bordo');
	INSERT INTO Cor(nome_cor) VALUES ('Branca');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Azul');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Marrom');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Preta');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Vermelha');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Roxa');
	INSERT INTO Cor(nome_cor) VALUES ('Branca e Verde');
	INSERT INTO Cor(nome_cor) VALUES ('Chumbo');
	INSERT INTO Cor(nome_cor) VALUES ('Cinza');
	INSERT INTO Cor(nome_cor) VALUES ('Diversas');
	INSERT INTO Cor(nome_cor) VALUES ('Dourada');
	INSERT INTO Cor(nome_cor) VALUES ('Grafite');
	INSERT INTO Cor(nome_cor) VALUES ('Grena');
	INSERT INTO Cor(nome_cor) VALUES ('Laranja');
	INSERT INTO Cor(nome_cor) VALUES ('Marrom');
	INSERT INTO Cor(nome_cor) VALUES ('Prata');
	INSERT INTO Cor(nome_cor) VALUES ('Preta');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Azul');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Cinza');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Prata');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Roxa');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Verde');
	INSERT INTO Cor(nome_cor) VALUES ('Preta e Vermelha');
	INSERT INTO Cor(nome_cor) VALUES ('Rosa');
	INSERT INTO Cor(nome_cor) VALUES ('Roxa');
	INSERT INTO Cor(nome_cor) VALUES ('Verde');
	INSERT INTO Cor(nome_cor) VALUES ('Verde e Vermelha');
	INSERT INTO Cor(nome_cor) VALUES ('Vinho');
	INSERT INTO Cor(nome_cor) VALUES ('Vinho e Bege');
	
	
	
	--8.4. RELAÇÕES DE MARCA || Citroen, fiat, ford, Chevrolet ou GM, Honda, Hyundai, Kia, Mitsubishi, Nissan, Peugeot, Renault, Toyota,
	--Volkswagen ou VW, Adamo, Agrale, Alfa Romeo, AM General, Americar, ASIA motors, Aston Martin, Audi,
	--Bentley, BMW, BRM ou Buggy, Bugatti, Bugre, Buick, Cadillac,  CBT, Chamonix, Chana, Changan, Chery,
	--Chrysler, Daewoo, Daihatsu, DKW ou Vemag, Dodge, Effa, Engesa, Envemo, Farus, Ferrari, GMC, Gurgel,
	--Hafei, Infiniti, Internacional Harvester, JAC, Jaguar, Jeep, JPX, Lada, Lamborghini, Land Rover, Lexus,
	--Lifan, Lincoln, Mahindra, Maseratti, Mazda, Mercedes-Benz, Mercury, MG, Mini, Miura, Morris, MP, Plymouth,
	--Pontiac, Porsche, Pretty, Puma, Ram, Rely, Rolls-Royce, Santa Matilde, Saturn, Seat, Shelby, Shineray, Smart,
	--SSangyong, Subaru, Suzuki, TAC, Troller, Volvo, Willys Overland e |OUTROS|
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CITROEN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('FIAT');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('FORD');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHEVROLET/GM');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('HONDA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('HYUNDAI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('KIA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MITSUBISHI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('NISSAN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PEUGEOT');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('RENAULT');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('TOYOTA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('VOLKSWAGEN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ADAMO');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('AGRALE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ALFA ROMEO');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('AM GENERAL');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('AMERICAR');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ASIA MOTORS');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ASTON MARTIN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('AUDI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BENTLEY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BMW');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BRM/BUGGY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BUGATTI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BUGRE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('BUICK');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CADILLAC');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CBT');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHAMONIX');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHANA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHANGAN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHERY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('CHRYSLER');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('DAEWOO');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('DAIHATSU');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('DKW/VEMAG');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('DODGE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('EFFA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ENGESA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ENVEMO');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('FARUS');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('FERRARI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('GMC');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('GURGEL');
	INSERT INTO MarcaCarro(nome_marca) VALUES('HAFEI');
	INSERT INTO MarcaCarro(nome_marca) VALUES('INFINITI');
	INSERT INTO MarcaCarro(nome_marca) VALUES('INTERNACIONAL HARVESTER');
	INSERT INTO MarcaCarro(nome_marca) VALUES('JAC');
	INSERT INTO MarcaCarro(nome_marca) VALUES('JAGUAR');
	INSERT INTO MarcaCarro(nome_marca) VALUES('JEEP');
	INSERT INTO MarcaCarro(nome_marca) VALUES('JPX');
	INSERT INTO MarcaCarro(nome_marca) VALUES('LADA');
	INSERT INTO MarcaCarro(nome_marca) VALUES('LAMBORGHINI');
	INSERT INTO MarcaCarro(nome_marca) VALUES('LAND ROVER');
	INSERT INTO MarcaCarro(nome_marca) VALUES('LEXUS');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('LIFAN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('LINCOLN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MAHINDRA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MASERATTI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MAZDA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MERCEDES-BENZ');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MERCURY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MG');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MINI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MIURA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MORRIS');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('MP');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PLYMOUTH');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PONTIAC');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PORSCHE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PRETTY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('PUMA');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('RAM');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('RELY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('ROLLS-ROYCE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SANTA MATILDE');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SATURN');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SEAT');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SHELBY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SHINERAY');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SMART');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SSANGYONG');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SUBARU');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('SUZUKI');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('TAC');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('TROLLER');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('VOLVO');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('WILLYS OVERLAND');
	INSERT INTO MarcaCarro(nome_marca) VALUES ('|OUTRAS|');
	
	--Marcas para Caminhões:
	--Agrale, ASIA Motors, Dodge, EFFA-JMC, Engesa, FIAT, FORD, Chevrolet/GM, GMC, Hyundai, Iveco, JAC, KIA,
	--Mercedes-Benz, Navistar, PUMA, Randon, Renault, Scania, Sinotruk, Terex, Volvo, Volkswagen, |OUTRAS|
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('AGRALE');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('ASIA MOTORS');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('DODGE');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('EFFA-JMC');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('ENGESA');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('FIAT');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('FORD');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('CHEVROLET/GM');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('GMC');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('HYUNDAI');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('IVECO');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('JAC');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('KIA');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('MERCEDES-BENZ');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('NAVISTAR');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('PUMA');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('RANDON');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('RENAULT');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('SCANIA');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('SINOTRUK');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('TEREX');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('VOLVO');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('Volkswagen');
	INSERT INTO MarcaCaminhao(nome_marca) VALUES ('|OUTRAS|');
	
	
	--Marcas para Onibus/Vans:
	--Agrale, ASIA Motors, BUSSCAR, Caio, Chana, Changan, CICCOBUS, CIFERAL, CITROEN, COBRASMA, COMIL, EFFA,
	--FIAT, Ford, Chevrolet/GM, Hafei, Hyundai, Irizar, Iveco, JAC, Jimbei, Jotave, KIA, MAFERSA, MARCOPOLO,
	--MASCARELLO, Maxibus, Mercedes-Benz, Mitsubishi, Neobus, Nielson, Peugeot, Rely, Renault, Scania, Shineray,
	--Ssangyong, Tecnobus, Thamco, Volvo, Volkswagen, Walkbus, |OUTRAS|
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('AGRALE');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('ASIA MOTORS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('BUSSCAR');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CAIO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CHANA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CHANGAN');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CICCOBUS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CIFERAL');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CITROEN');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('COBRASMA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('COMIL');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('EFFA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('FIAT');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('FORD');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('CHEVROLET/GM');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('HAFEI');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('HYUNDAI');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('IRIZAR');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('IVECO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('JAC');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('JIMBEI');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('JOTAVE');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('KIA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MAFERSA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MARCOPOLO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MASCARELLO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MAXIBUS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MERCEBES-BENZ');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('MITSUBISHI');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('NEOBUS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('NIELSON');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('PEUGEOT');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('RELY');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('RENAULT');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('SCANIA');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('SHINERAY');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('SSANGYONG');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('TECNOBUS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('THAMCO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('VOLVO');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('VOLKSWAGEN');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('WALKBUS');
	INSERT INTO MarcaOnibusVans(nome_marca) VALUES ('|OUTRAS|');
	
	
	--Marcas para Tratores/Rebocáveis:
	--Agrale, Angola, Bobcat, Budny, Bueno, Case, Caterpillar, CBT, CLARK, Dambroz, Facchini, Fiatallis, FORD,
	--Galego, GUERRA, Gurgel, Halley, Huber Warco, Hyster, Hyundai, JCB, John Deere, Komatsu, Krone, Lonking,
	--MADAL, Massey Ferguson, MAXION, Michigan, Mitsubishi, Moto Kar, Muller, New Holland, Noma, Pauli, Piccin,
	--Randon, Rodoking, Schiffer, SDLG, Star Trailer, Tema Terra, Tobatta, Toyota, Tramontini, Valmet, Valtra, Volvo,
	--Wecan, Yale, Yanmar, |OUTRAS|
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('AGRALE');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('ANGOLA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('BOBCAT');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('BUDNY');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('CASE');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('CATERPILLAR');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('CBT');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('CLARK');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('DAMBROZ');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('FACCHINI');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('FIATALLIS');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('FORD');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('GALEGO');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('GUERRA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('GURGEL');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('HALLEY');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('HUBER WARCO');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('HYSTER');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('HYUNDAI');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('JCB');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('JOHN DEERE');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('KOMATSU');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('KRONE');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('LONKING');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MADAL');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MASSEY FERGUSON');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MAXION');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MICHIGAN');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MITSUBISHI');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MOTO KAR');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('MULLER');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('NEW HOLLAND');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('NOMA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('PAULI');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('PICCIN');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('RANDON');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('RODOKING');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('SCHIFFER');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('SDLG');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('STAR TRAILER');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('TEMA TERRA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('TOBATTA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('TOYOTA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('TRAMONTINI');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('VALMET');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('VALTRA');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('VOLVO');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('WECAN');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('YALE');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('YANMAR');
	INSERT INTO MarcaTratoresRebocaveis(nome_marca) VALUES ('|OUTRAS|');
	
	--8.5. RELAÇÃO Opcionais || Eles são Air Bag, Air Bag Duplo, Alarme, Ar Condicionado, Ar Quente, Banco de Couro, Básica,
	--Básico, Câmbio Automático, Câmbio Sequencial, Capota Marítima, Completa, Direção Hidráulica,
	--Completo, Computador de Bordo, Desembaçador Traseiro, Direção Elétrica, Disqueteira CD,
	--Engate ou Rabicho, Estribo, Farol de Neblina, Farol Xenon, Freios ABS, Kit GNV,
	--Limpador e Desembaçador Traseiro, Limpador Traseiro, MP3 Player, Piloto Automático,
	--Protetor de Caçamba, Retrovisor Elétrico, Rodas, Santo Antônio, Trava Elétrica,
	--Sensor de Estacionamento, Som CD, Teto Solar, Tração 4X4, Vidro Elétrico 
	INSERT INTO Opcionais(nome_opcional) VALUES ('Air Bag');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Air Bag Duplo');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Alarme');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Ar Condicionado');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Ar Quente');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Banco de Couro');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Básica');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Básico');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Câmbio Automático');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Câmbio Sequencial');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Capota Marítima');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Copleta');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Direção Hidráulica');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Completo');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Computador de Bordo');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Desembaçador Traseiro');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Direção Elétrica');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Disqueteira CD');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Engate/Rabicho');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Estribo');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Farol de Neblina');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Farol Xenon');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Freios ABS');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Kit GNV');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Limpador e Desembaçador Traseiro');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Limpador Traseiro');
	INSERT INTO Opcionais(nome_opcional) VALUES ('MP3 Player');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Piloto Automático');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Protetor de Caçamba');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Retrovisor Elétrico');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Rodas');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Santo Antônio');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Trava Elétrica');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Sensor de Estacionamento');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Som CD');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Teto Solar');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Tração 4X4');
	INSERT INTO Opcionais(nome_opcional) VALUES ('Vidro Elétrico');
	
	
	--8.6. RELAÇÃO TipoAnuncio || Onde o tipo pode ser: grátis, bronze, prata, ouro e até vender (5 tipos)
	--O preço dos tipos é, respectivamente, 0, 20, 40, 75 e 90 reais
	INSERT INTO TipoAnuncio(nome_tipo, preco) VALUES ('Grátis', 0);
	INSERT INTO TipoAnuncio(nome_tipo, preco) VALUES ('Bronze', 20);
	INSERT INTO TipoAnuncio(nome_tipo, preco) VALUES ('Prata', 40);
	INSERT INTO TipoAnuncio(nome_tipo, preco) VALUES ('Ouro', 75);
	INSERT INTO TipoAnuncio(nome_tipo, preco) VALUES ('Até Vender', 90);
	
--END POVOAMENTO DE RELAÇÕES ESTÁTICAS AUXILIARES

--9. POVOAMENTO PEDIDO PARA O BANCO "Alimentar seu banco de dados com, no mínimo, 50 veículos, 15 lojas e 10 anunciantes."

	--9.1. POVOAMENTO DE VEÍCULOS := |placa | tipo | modelo | marca | cor | combustivel | ano carro | ano modelo | preco | km | mais opcionais | descricao :=> 25 carros, 15 caminhoes, 5 onibus ou vans, 5 tratores ou rebocaveis

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, mais_opcionais, descricao) VALUES ('AAA1111', 1, 'Gol 1.0 G4 4p.', 'VOLKSWAGEN', 22, 5, 2007, 2007, 15500, 70000, '', 'Carro bem conservado.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, mais_opcionais, descricao) VALUES ('BBB2222', 1, 'Gol 1.0 GIII 4p.', 'VOLKSWAGEN', 14, 1, 2005, 2005, 14500, 80000, '', 'Carro muito conservado.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('CCC3333', 1, '206 Selection 1.0 16v 4p.', 'PEUGEOT', 33, 1, 2005, 2006, 13500, 65000);

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('DFV0277', 1, 'A3 1.8 20v 2p.', 'AUDI', 22, 1, 2001, 2002, 19000, 100000);

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('HSJ6184', 1, 'C3 Hatch GLX 1.4', 'CITROEN', 21, 5, 2007, 2008, 0, 10000, 'Consulte-nos');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('HRG3669', 1, 'Civic LX 1.7 16v', 'HONDA', 14, 1, 2001, 2002, 16800, 20000);

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('DDD4444', 1, 'Camaro SS 6.2 V8 32v', 'CHEVROLET/GM', 1, 1, 2011, 2011, 145000, 30000, 'Financio com as melhores taxas. Manual chave reserva.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('EEE5555', 1, 'Clio Hatch RT 1.6 4p.', 'RENAULT', 14, 1, 1998, 1999, 9000, 100000, 'Trocamos e financiamos.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('FFF6666', 1, 'F250 XLT 4.2TD 18v C.D.', 'FORD', 22, 3, 2004, 2004, 95000, 83903, 'Impecável, estepe sem uso, 04 pneus bf novos rodados 1000 km,rodas originais, raridade. Trava carneiro, frente da moderna original, forração carpete.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('GGG7777', 1, 'Palio Way 1.0 Fire 4p.', 'FIAT', 6, 5, 2014, 2015, 0, 14343, 'Veiculo em estado de novo, sem detalhes. Estepe nunca usado. ');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('HHH8888', 1, 'City LX 1.5 16v i-VTEC', 'HONDA', 21, 5, 2013, 2013, 49000, 14000, 'Veículo revisado e com 1 ano de garantia, motor e câmbio.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('III9999', 1, 'Civic EXR 2.0 16v i-VTEC', 'HONDA', 14, 5, 2014, 2014, 74000, 16000, 'Veiculo consignado, favor agendar visita.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('JJJ1010', 3, '10000 4.8', 'AGRALE', 33, 3, 2015, 2015, 0, 0, 'Equipado com motor cummins, transmissão eaton e eixo meritor. Consulte-nos para ver preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('KKK1111', 3, '10000 4.8', 'AGRALE', 20, 3, 2015, 2015, 0, 0, 'Equipado com motor cummins, transmissão eaton e eixo meritor. Consulte-nos para ver preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('LLL1212', 3, '1113', 'MERCEDES-BENZ', 3, 3, 1965, 1965, 0, 0, 'Consulte-nos para ver preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('MMM1313', 3, '1113', 'MERCEDES-BENZ', 6, 3, 1976, 1976, 0, 0, 'Turbo. Caçamba conservada, bom de cabina, bom de chassi. Consulte-nos para ver preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('NNN1414', 4, '12E', 'CATERPILLAR', 1, 3, 1969, 1969, 45000, 0, 'Equipamento pronto para trabalhar.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('OOO1515', 4, '75III', 'MICHIGAN', 1, 3, 1976, 1976, 60000, 0);

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('UUU4747', 4, '55C', 'MICHIGAN', 1, 3, 1989, 1989, 95000, 0);

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('PPP1616', 3, '1114', 'MERCEDES-BENZ', 1, 3, 1989, 1989, 0, 0, 'Caminhão pronto para por caçamba. Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('QQQ1717', 3, '710', 'MERCEDES-BENZ', 6, 3, 2002, 2002, 0, 0, 'Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('RRR1818', 3, '12-140', 'Volkswagen', 6, 3, 1998, 1998, 0, 0, 'Documentação ok. Financiamos. Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('SSS1919', 3, '12-140 H', 'Volkswagen', 6, 3, 1993, 1994, 0, 0, 'Financiamos. Aceitamos troca. Documentação ok. Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('TTT2020', 3, '1113', 'MERCEDES-BENZ', 3, 3, 1978, 1978, 39000, 0, 'Toco. 6 pneus novos, carroceria nova.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('UUU2121', 3, 'Astra Sedan Elegance 2.0', 'CHEVROLET/GM', 21, 5, 2005, 2005, 19500, 0, 'Uma ótima oportunidade, com preço de ocasião.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('VVV2222', 3, 'Amarok Highline 2.0TDi 16v 4x4 C.D.', 'Volkswagen', 21, 3, 2011, 2012, 0, 78000, 'Revisado e periciado. Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('UUU2323', 1, 'Fox 1.6 4p.', 'VOLKSWAGEN', 14, 5, 2011, 2012, 0, 40000, 'Revisado e periciado. Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('VVV2424', 1, '500 Cult 1.4 Evo', 'FIAT', 14, 5, 2011, 2012, 0, 32000, 'Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('XXX2525', 1, '500 Cult 1.4 Evo', 'FIAT', 33, 5, 2011, 2012, 0, 31000, 'Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('ZZZ2626', 2, 'Ideale 770', 'MARCOPOLO', 6, 3, 2015, 2015, 0, 0, 'Consulte-nos para preços.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('AAA2727', 1, '116i 1.6T 16v VVT', 'BMW', 6, 1, 2014, 2014, 88000, 23000, 'Todas as revisões feitas na concessionária, IPVA pago, pastilhas de freios trocadas recentemente.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('BBB2828', 1, '208 Allure 1.5', 'PEUGEOT', 6, 5, 2013, 2014, 42000, 21000, 'Revisões feitas todas dentro da concessionaria, manual e chave reserva, único dono.');


	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('CCC2929', 1, 'A3 1.8 20v 4p.', 'AUDI', 14, 1, 2003, 2003, 19900, 120000, 'Trocados recentemente: pastilhas, amortecedores, filtros, velas e óleos. Valor para pagamento em dinheiro.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('DDD3030', 1, 'A4 2.0 TFSi 16v Ambiente', 'AUDI', 22, 1, 2013, 2013, 98900, 220000, 'Multimídia instalado pela própria concessionária AUDI totalizando 2 sistemas multimídias.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('EEE3131', 1, 'Agile LTZ 1.4', 'CHEVROLET/GM', 33, 5, 2010, 2010, 23990, 740000, 'Único dono. Carro de mulher.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, descricao) VALUES ('FFF3232', 1, 'Astra Sedan Expression 2.0', 'CHEVROLET/GM', 21, 1, 2002, 2002, 17500, 'Foi um carro dos Salesianos de Mato Grosso, portanto muito bem cuidado. Segundo dono.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('GGG3333', 1, 'ASX 2.0 16v D-VVT AWD', 'MITSUBISHI', 22, 1, 2010, 2011, 61500, 760000, 'Manual do proprietário, todas as revisões feitas na concessionaria. Chave Reserva.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, descricao) VALUES ('HHH3434', 1, 'C 180 1.8T 16v CGI', 'MERCEDES-BENZ', 21, 1, 2011, 2012, 81900, 'Pneus novos, estepe nunca usado. Veículo sem detalhes. Para pessoas com perfil exigente. Não aceito troca, todas as revisões realizadas na concessionária.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('III3535', 1, 'C3 Hatch GLX 1.4', 'CITROEN', 6, 5, 2011, 2012, 25500, 48000, 'Manual e chave reserva. Documento 2015 pago.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('JJJ3636', 1, 'C3 Hatch GLX 1.4', 'CITROEN', 22, 5, 2012, 2012, 27500, 36000, 'Único dono, manual e chave reserva, todas as revisões feitas na concessionaria. Não aceito troca.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, descricao) VALUES ('KKK3737', 1, 'Caravan Diplomata 4.1 SL/E', 'CHEVROLET/GM', 16, 2, 1985, 1985, 15000, '2º Dono, relíquia.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('LLL3838', 1, 'Cerato EX 1.6 16v CVVT', 'KIA', 22, 1, 2010, 2011, 39800, 29865, 'Único dono.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('MMM3939', 1, 'Cerato SX 1.6 16v CVVT', 'KIA', 22, 1, 2010, 2011, 33000, 78000, 'Venda direto com o proprietário. Único dono. Todas as revisões feitas na concessionária. Garantia de fábrica até outubro de 2015.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, descricao) VALUES ('NNN4040', 1, 'Civic EXS 1.8 16v i-VTEC', 'HONDA', 14, 5, 2008, 2008, 35000, 'Carro impecável, somente venda.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('OOO4141', 1, 'Civic EXS 1.8 16v i-VTEC', 'HONDA', 22, 5, 2011, 2012, 54500, 62000, 'Confira.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('PPP4242', 1, 'Civic LXL 1.8 16v i-VTEC', 'HONDA', 14, 5, 2010, 2010, 39000, 83000, 'Revisões na concessionária. Manual e chave reserva. Pneus traseiros novos Bridgstone Turanza, dianteiros semi novos. IPVA quitado.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('QQQ4343', 1, 'Corolla SE-G 1.8 16v VVT-i', 'TOYOTA', 14, 5, 2010, 2010, 52500, 53000, '2º dono, todas as revisões feitas na concessionária. Ipva e licenciamento 2015 pagos.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('RRR4444', 1, 'Corolla XEi 1.8 16v', 'TOYOTA', 21, 1, 2006, 2006, 30000, 200000, 'Todo revisado.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('SSS4545', 1, 'Corolla XEi 2.0 16v D-VVT-i', 'TOYOTA', 21, 5, 2012, 2013, 63000, 54300, 'Muito conservado.');

	INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, descricao) VALUES ('TTT4646', 1, 'Corsa Sedan Classic Life 1.0 VHC', 'CHEVROLET/GM', 21, 5, 2008, 2008, 15500, 'Lindo e bem conservado. Único dono. Veículo de não fumante.');

	--END POVOAMENTO DE VEÍCULOS
	
	--9.2. POVOAMENTO DE LOJAS := |cnpj| nome | email | website | responsavel | telefone loja | celular responsavel | endereco | cep | bairro | cidade | estado

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('12345678/123456', '1000Tons Veículos', '1000tonsveiculos@gmail.com', '', 'Augustus', 92513809, 96089674, 'Av. Thirson de Almeida, 1178', 79085040, 'Guanandy', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('11111111/123456', '1001 Automóveis', '1001automoveis@gmail.com', 'www.1001automoveis.com.br', 'Tiberius', 33841001, 33845961, 'Av. Bandeirantes, 1001', 79005670, 'Amabaí', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('22222222/111111', 'MC Veículos', 'mcveiculos@gmail.com', '', 'Claudius', 33426051, 81151815, 'Rua Bom Sucesso, 802', 79080280, 'Jardim Jóquei Club', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('33333333/222222', 'Center Motors', 'centermotors@gmail.com', '', 'Nero', 33451000, 99332965, 'Av. Ernesto Geisel, 510', 79006162, 'Vila Taquarussu', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('44444444/333333', 'Dois Irmãos Automóveis', 'doisirmaos@gmail.com', 'www.doisirmaosautomoveis.com.br', 'Galba', 30274008, 30274008, 'Rua Alegrete, 1203', 79010800, 'Coronel Antonino', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('66666666/555555', 'Endo Car', 'grupoendo@gmail.com', 'www.grupoendo.com.br', 'Otho', 30283514, 84051009, 'Rua 14 de Julho, 1453', 79002330, 'Centro', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('66666666/666666', 'KCinco Caminhões e Ônibus', 'kcinco@gmail.com', '', 'Vitellius', 33220800, 33220801, 'Av. Eduardo Elias Zahran, 240', 79004000, 'Vila Santa Doroteia', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('77777777/666666', 'Itanhangá Veículos', 'itanhanga@gmail.com', '', 'Vespasian', 30286040, 92203466 , 'Rua Joaquim Murtinho, 1983', 79004000, 'Vila Santa Doroteia', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('88888888/777777', 'GTrês Máquinas Rodoviárias', 'gtres@gmail.com', '', 'Titus', 33220800, 33220801, 'Av. Eduardo Elias Zahran, 240', 79003020, 'Itanhaguá Park', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('99999999/888888', 'Layfer Veículos', 'layfer@gmail.com', '', 'Domitian', 30435008, 30266608, 'Av. Brilhante, 2197', 79003020, 'Vila Bandeirantes', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('00000000/999999', 'Jatobá Caminhões', 'jatoba@gmail.com', '', 'Nerva', 33881876, 92861460, 'Av. Guaicurus, 5497', 79062310, 'Jardim Macapá', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('01234567/123456', 'F3 Veículos', 'ftres@gmail.com', '', 'Trajan', 30256161, 30436151, 'Rua Spipe Calarge, 350', 79050261, 'Jardim TV Morena', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('23456789/456789', 'Discautol', 'discautol@gmail.com', 'www.discautol.com.br', 'Hadrian', 33229000, 33229000, 'Av. Afonso Pena, 1440', 79005000, 'Centro', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('45678912/012345', 'Fiat Enzo', 'enzo@gmail.com', 'www.fiatenzo.com.br', 'Antoninus Pius', 33220600, 33220600, 'Rua Joaquim Murtinho, 2350', 79003020, 'Miguel Couto', 'Campo Grande', 'MS');

	INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('56789123/025896', 'HC Veículos Show Room', 'hcveiculos@gmail.com', '', 'Marcus Aurelius', 30431305, 30431305, 'Rua Joaquim Murtinho, 1490', 79003020, 'Itanhanguá Park', 'Campo Grande', 'MS');

	--END POVOAMENTO DE LOJAS
	
	--9.3. POVOAMENTO DE ANUNCIANTES |cpf |nome |endereco |complemento |bairro |uf |cidade |telefone |email |senha

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (1, 'Ido dos Santos Ximenes', 'Rua A', 'Bairro A', 'MS', 'Campo Grande', 92981931, 'ido@gmail.com', 'Ido dos Santos Ximenes');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (2, 'Izauro Lino de Menezes', 'Rua B', 'Bairro B', 'MS', 'Campo Grande', 81013978, 'izauro@gmail.com', 'Izauro Lino de Menezes');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (3, 'Rodrigo Jose Gonçalves', 'Rua C', 'Bairro C', 'MS', 'Campo Grande', 99915817, 'rodrigo@gmail.com', 'Rodrigo Jose Gonçalves');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (4, 'Luciano Carlos Silveira', 'Rua D', 'Bairro D', 'MS', 'Campo Grande', 99265040, 'luciano@gmail.com', 'Luciano Carlos Silveira');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (5, 'Mark Pierezan', 'Rua E', 'Bairro E', 'MS', 'Campo Grande', 81386540, 'mark@gmail.com', 'Mark Pierezan');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (6, 'André Luis Ortega', 'Rua F', 'Bairro F', 'MS', 'Campo Grande', 91933178, 'andre@gmail.com', 'André Luis Ortega');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (7, 'Gil Vicente Delgado', 'Rua G', 'Bairro G', 'MS', 'Campo Grande', 91404797, 'gil@gmail.com', 'Gil Vicente Delgado');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (8, 'Wanessa Costa Merel', 'Rua H', 'Bairro H', 'MS', 'Campo Grande', 99283872, 'wanessa@gmail.com', 'Wanessa Costa Merel');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (9, 'Claudio Jacinto Alves', 'Rua I', 'Bairro I', 'MS', 'Campo Grande', 99226101, 'claudio@gmail.com', 'Claudio Jacinto Alves');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (10, 'Tarley do Carmomeza', 'Rua J', 'Bairro J', 'MS', 'Campo Grande', 99893919, 'tarley@gmail.com', 'Tarley do Carmomeza');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (11, 'Marcos Frederico', 'Rua K', 'Bairro K', 'MS', 'Campo Grande', 92959800, 'marcos@gmail.com', 'Marcos Frederico');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (12, 'Jeferson Mendes Martinez', 'Rua L', 'Bairro L', 'MS', 'Campo Grande', 92366564, 'jeferson@gmail.com', 'Jeferson Mendes Martinez');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (13, 'João Victor', 'Rua M', 'Bairro M', 'MS', 'Campo Grande', 91317304, 'joao@gmail.com', 'João Victor');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (14, 'César de Brito Gonçalves', 'Rua N', 'Bairro N', 'MS', 'Campo Grande', 99635337, 'cesar@gmail.com', 'César de Brito Gonçalves');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (15, 'João Guilherme A. Akayama', 'Rua O', 'Bairro O', 'MS', 'Campo Grande', 32419821, 'akayama@gmail.com', 'João Guilherme A. Akayama');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (16, 'Eduardo da Silva Sobral', 'Rua P', 'Bairro P', 'MS', 'Campo Grande', 92934130, 'eduardo@gmail.com', 'Eduardo da Silva Sobral');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (17, 'David Chadid Warpechowski', 'Rua Q', 'Bairro Q', 'MS', 'Campo Grande', 92373866, 'david@gmail.com', 'David Chadid Warpechowski');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (18, 'Anderson Ferreira de Souza', 'Rua R', 'Bairro R', 'MS', 'Campo Grande', 81451703, 'anderson@gmail.com', 'Anderson Ferreira de Souza');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (19, 'Amadeu Wagner Borges', 'Rua S', 'Bairro S', 'MS', 'Campo Grande', 99084576, 'amadeu@gmail.com', 'Amadeu Wagner Borges');

	INSERT INTO shopcar.Usuario (cpf, nome, endereco, bairro, uf, cidade, telefone, email, senha) VALUES (20, 'Marcelo', 'Rua T', 'Bairro T', 'MS', 'Campo Grande', 91117325, 'marcelo@gmail.com', 'Marcelo');

	--END POVOAMENTO DE ANUNCIANTES


	--9.4. POVOAMENTO DE ANUNCIOS
		
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'TTT4646', '20');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'SSS4545', '1');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'RRR4444', '2');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'QQQ4343', '3');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(4, 'PPP4242', '4');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(5, 'OOO4141', '5');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'NNN4040', '6');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'MMM3939', '7');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'LLL3838', '8');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'KKK3737', '9');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'JJJ3636', '10');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'AAA1111', '12345678/123456');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'BBB2222', '12345678/123456');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(4, 'CCC3333', '11111111/123456');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'DFV0277', '11111111/123456');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'HSJ6184', '22222222/111111');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'HRG3669', '22222222/111111');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'DDD4444', '33333333/222222');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'EEE5555', '33333333/222222');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'FFF6666', '66666666/555555');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(4, 'GGG7777', '66666666/555555');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'HHH8888', '77777777/666666');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(3, 'III9999', '77777777/666666');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(4, 'JJJ1010', '88888888/777777');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(5, 'KKK1111', '88888888/777777');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'LLL1212', '00000000/999999');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'MMM1313', '00000000/999999');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'NNN1414', '01234567/123456');
		INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(2, 'OOO1515', '01234567/123456');
	--END POVOAMENTO DE ANUNCIOS

--END POVOAMENTO PEDIDO PARA O BANCO

--END shopcar.sql














