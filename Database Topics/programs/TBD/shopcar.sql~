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
CREATE DOMAIN combustivel_shopcar AS TEXT NOT NULL DEFAULT 'gasolina';
CREATE DOMAIN cnpj_shopcar AS VARCHAR(15) NOT NULL;
CREATE DOMAIN cpf_shopcar AS VARCHAR(11) NOT NULL;
CREATE DOMAIN positivo AS INTEGER NOT NULL DEFAULT 0 CONSTRAINT positivo_const CHECK (VALUE >= 0);
CREATE DOMAIN ano_veiculo AS INTEGER NOT NULL DEFAULT 1995 CONSTRAINT ano_const CHECK (VALUE >= 1920 AND VALUE <= 1995);
CREATE DOMAIN reais AS DOUBLE PRECISION NOT NULL DEFAULT 0.00 CONSTRAINT reais_const CHECK (VALUE >= 0.00);
CREATE DOMAIN ano_modelo AS INT NOT NULL DEFAULT 1995 CONSTRAINT anomodelo_const CHECK(VALUE >= 1920 AND VALUE <= 1996);
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
	--OK
	
	
	--PARA anunciante_shopcar
	SET search_path=anunciante_shopcar;
	CREATE VIEW anunciante AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	CREATE VIEW selecao_anunciante_shopcar_veiculos AS SELECT tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, mais_opcionais, descricao FROM shopcar.Veiculo;
	CREATE VIEW selecao_anunciante_shopcar_lojas AS SELECT nome, website, telefone_loja, celular_responsavel, endereco, bairro, cidade, estado FROM shopcar.Loja;
	CREATE VIEW selecao_anunciante_shopcar_cor AS SELECT nome_cor FROM shopcar.Cor;
	--OK
	
	
	--PARA usuario_shopcar;
	SET search_path=usuario_site_shopcar;
	CREATE VIEW usuario_site AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf NOT IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	--OK

	--PARA usuario_shopcar;
	SET search_path=usuario_site_shopcar;
	CREATE VIEW selecao_usuario_site_anuncios AS SELECT tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, mais_opcionais, descricao FROM shopcar.Veiculo;
	CREATE VIEW selecao_usuario_site_lojas AS SELECT nome, website, telefone_loja, celular_responsavel, endereco, bairro, cidade, estado FROM shopcar.Loja;
	CREATE VIEW selecao_usuario_site_usuarios AS SELECT nome, endereco, cidade, uf, telefone FROM shopcar.Usuario;
	
	
--END CRIAÇÃO DE VIEWS PARA OS USUÁRIOS

--7. PERMISSÕES DOS NOVOS USUÁRIOS
	--PARA loja_shopcar
	SET search_path=shopcar;
	GRANT USAGE ON SCHEMA loja_shopcar TO loja_shopcar;
	GRANT INSERT ON shopcar.Loja TO loja_shopcar;
	GRANT INSERT ON shopcar.Anuncio TO loja_shopcar;
	GRANT SELECT ON loja_shopcar.loja TO loja_shopcar;
	--OK
	
	--PARA anunciante_shopcar
	GRANT USAGE ON SCHEMA anunciante_shopcar TO anunciante_shopcar;
	GRANT INSERT ON shopcar.Anuncio TO anunciante_shopcar;
	GRANT SELECT ON anunciante_shopcar.anunciante TO anunciante_shopcar;
	
	--PARA usuario_shopcar
	GRANT USAGE ON SCHEMA usuario_site_shopcar TO usuario_shopcar;
	GRANT INSERT ON shopcar.Usuario TO usuario_shopcar;
	GRANT SELECT ON usuario_site_shopcar.usuario_site TO usuario_shopcar;
	GRANT SELECT ON selecao_usuario_site TO usuario_shopcar;
	
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
	INSERT INTO Cor(nome_cor) VALUES ('Amrela e Preta');
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
	INSERT INTO shopcar.Veiculo VALUES ('AAA1111', 1, 'Uno Mille Fire 1.0 4p.', 'FIAT', 31, 5, 2006, 2007, 16900, 70000, 'Quatro portas', 'Super conservado, revisado.');
	INSERT INTO shopcar.Veiculo VALUES ('BBB2222', 1, 'FUSION', 'FORD', 1, 1, 1994, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('CCC3333', 1, 'e', 'HONDA', 1, 1, 1993, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('DDD4444', 1, 'asd', 'HYUNDAI', 1, 1, 1992, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('EEE5555', 1, 'ggas', 'TOYOTA', 2, 3, 1991, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('FFF6666', 1, 'ONIX', 'CHEVROLET/GM', 4, 5, 1990, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('GGG7777', 1, 'A6', 'BMW', 6, 7, 1989, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('HHH8888', 1, 'sadde', 'CITROEN', 8, 5, 1988, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('III9999', 1, 'asdf', 'RENAULT', 10, 1, 1987, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('JJJ1010', 1, 'afs', 'LAND ROVER', 11, 6, 1986, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('KKK1111', 1, 'RAM', 'DODGE', 15, 5, 1985, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('LLL1212', 1, 'qwe', 'AUDI', 16, 4, 1984, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('MMM1313', 1, 'thd', 'CADILLAC', 17, 3, 1983, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('NNN1414', 1, 'daffa', 'JAC', 18, 2, 1982, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('OOO1515', 1, 'OMEGA', 'CHEVROLET/GM', 19, 1, 1981, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('PPP1616', 1, 'saffsa', 'PONTIAC', 1, 1, 1980, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('QQQ1717', 1, 'sfasfa', 'MITSUBISHI', 2, 2, 1979, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('RRR1818', 1, 'asd', 'NISSAN', 3, 3, 1978, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('SSS1919', 1, 'fgq', 'PEUGEOT', 4, 4, 1977, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('TTT2020', 1, 'PALIO', 'FIAT', 5, 5, 1976, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('UUU2121', 1, 'qwe', 'FORD', 6, 6, 1975, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('VVV2222', 1, 'CIVIC', 'HONDA', 7, 7, 1974, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('WWW2323', 1, 'CELTA', 'CHEVROLET/GM', 8, 7, 1973, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('XXX2424', 1, 'GOL', 'VOLKSWAGEN', 9, 6, 1972, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('YYY2525', 1, 'a', 'VOLKSWAGEN', 10, 5, 1971, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('ZZZ2626', 3, 'b', '|OUTRAS|', 2, 2, 1970, 1995, 10000, 0, '', 'd');
	INSERT INTO shopcar.Veiculo VALUES ('ABC1234', 3, 'c', '|OUTRAS|', 1, 1, 1971, 1994, 10000, 0, '', 'abc');
	INSERT INTO shopcar.Veiculo VALUES ('DEF4567', 3, 'd', 'RANDON', 1, 1, 1972, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('GHI8910', 3, 'e', 'RANDON', 9, 4, 1973, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('JKL1112', 3, 'f', 'RANDON', 10, 1, 1974, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('MNO1314', 3, 'g', 'RANDON', 20, 1, 1975, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('PQR1516', 3, 'h', 'RANDON', 17, 2, 1976, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('TUV1718', 3, 'i', 'RANDON', 16, 1, 1977, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('WXY1920', 3, 'h', 'RANDON', 7, 3, 1978, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('ZAB2122', 3, 'j', 'RANDON', 6, 1, 1979, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('CDE2324', 3, 'k', 'RANDON', 10, 2, 1980, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('FGH2526', 3, 'l', 'RANDON', 11, 1, 1981, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('AEB3333', 3, 'm', 'RANDON', 12, 1, 1982, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('DAJ1111', 3, 'n', 'RANDON', 13, 3, 1983, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('IIA2222', 3, 'o', 'RANDON', 14, 2, 1984, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('EMI3333', 2, 'A', 'MARCOPOLO', 7, 1, 1985, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('GEN4444', 2, 'B', 'MARCOPOLO', 5, 1, 1986, 1991, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('OEO5555', 2, 'C', 'MARCOPOLO', 2, 1, 1987, 1992, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('DAR6666', 2, 'D', 'MARCOPOLO', 1, 1, 1988, 1993, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('IIJ7777', 2, 'E', 'MARCOPOLO', 1, 1, 1989, 1994, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('EMA8888', 4, 'F', 'YANMAR', 1, 1, 1990, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('GEI9999', 4, 'G', 'YANMAR', 1, 1, 1991, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('OEN1010', 4, 'H', 'YANMAR', 1, 1, 1992, 1996, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('DAO1111', 4, 'I', 'YANMAR', 1, 1, 1993, 1995, 10000, 0, '', '');
	INSERT INTO shopcar.Veiculo VALUES ('IIN1212', 4, 'J', 'YANMAR', 1, 1, 1994, 1994, 10000, 0, '', '');
	
	
	--END POVOAMENTO DE VEÍCULOS
	
	--9.2. POVOAMENTO DE LOJAS := |cnpj| nome | email | website | responsavel | telefone loja | celular responsavel | endereco | cep | bairro | cdd | estado
	INSERT INTO shopcar.Loja VALUES('12345678/123456', 'Medusa', 'a@a.com', '', 'postgres', 111, 1, 'abc', 11, 'zx', 'a', 'MS');
	INSERT INTO shopcar.Loja VALUES('11111111/123456', 'Nemeia', 'b@b.com', '', 'postgres', 222, 1, 'def', 22, 'cv', 'b', 'SP');
	INSERT INTO shopcar.Loja VALUES('22222222/111111', 'Harpia', 'c@c.com', '', 'postgres', 333, 1, 'ghi', 33, 'asd', 'c', 'RJ');
	INSERT INTO shopcar.Loja VALUES('33333333/222222', 'Hercules', 'd@d.com', '', 'postgres', 444, 1, 'jkl', 44, 'vcx', 'd', 'AC');
	INSERT INTO shopcar.Loja VALUES('44444444/333333', 'Zeus', 'e@e.com', '', 'postgres', 555, 1, 'mno', 55, 'qwer', 'e', 'AM');
	INSERT INTO shopcar.Loja VALUES('55555555/444444', 'Poseidon', 'f@f.com', '', 'postgres', 666, 1, 'pqr', 66, 'fd', 'f', 'AP');
	INSERT INTO shopcar.Loja VALUES('66666666/555555', 'Hera', 'g@g.com', '', 'postgres', 777, 1, 'stu', 77, 'hg', 'g', 'PA');
	INSERT INTO shopcar.Loja VALUES('77777777/666666', 'Afrodite', 'h@h.com', '', 'postgres', 888, 1, 'vwx', 88, 'mnj', 'h', 'PR');
	INSERT INTO shopcar.Loja VALUES('88888888/777777', 'Hermes', 'i@i.com', '', 'postgres', 999, 1, 'yza', 99, 'sad', 'i', 'PE');
	INSERT INTO shopcar.Loja VALUES('99999999/888888', 'Hefesto', 'j@j.com', '', 'postgres', 101, 1, 'bcd', 111, 'eqe', 'j', 'CE');
	INSERT INTO shopcar.Loja VALUES('00000000/999999', 'Hades', 'k@k.com', '', 'postgres', 112, 1, 'efg', 222, 'reds', 'k', 'RS');
	INSERT INTO shopcar.Loja VALUES('01234567/123456', 'Artemis', 'l@l.com', '', 'postgres', 123, 1, 'jie', 333, 'qwet', 'l', 'RN');
	INSERT INTO shopcar.Loja VALUES('23456789/456789', 'Apollo', 'm@m.com', '', 'postgres', 134, 1, 'qrr', 4444, 'tuu', 'm', 'MG');
	INSERT INTO shopcar.Loja VALUES('45678912/012345', 'Ares', 'n@n.com', '', 'postgres', 145, 1, 'qss', 5555, 'foo', 'n', 'ES');
	INSERT INTO shopcar.Loja VALUES('56789123/025896', 'Athena', 'o@o.com', '', 'postgres', 156, 1, 'qww', 77777, 'bar', 'o', 'GO');
	
	
	--END POVOAMENTO DE LOJAS
	
	--9.3. POVOAMENTO DE ANUNCIANTES |cpf |nome |endereco |complemento |bairro |uf |cdd |telefone |email |senha
	INSERT INTO shopcar.Usuario VALUES('1', 'Jainor', 'a', '', 'aa', 'MS', 'cg', 1, 'j@j.com', 'a');
	INSERT INTO shopcar.Usuario VALUES('2', 'Diego', 'b', '', 'bb', 'MS', 'cg', 2, 'd@d.com', 'b');
	INSERT INTO shopcar.Usuario VALUES('3', 'Aimee', 'c', '', 'cc', 'MS', 'cg', 3, 'a@a.com', 'c');
	INSERT INTO shopcar.Usuario VALUES('4', 'Nicolas', 'd', '', 'dd', 'MS', 'cg', 4, 'n@n.com', 'd');
	INSERT INTO shopcar.Usuario VALUES('5', 'Mariana', 'e', '', 'ee', 'MS', 'cg', 5, 'm@m.com', 'e');
	INSERT INTO shopcar.Usuario VALUES('6', 'Ricardo', 'f', '', 'ff', 'MS', 'cg', 6, 'r@r.com', 'f');
	INSERT INTO shopcar.Usuario VALUES('7', 'Edson', 'g', '', 'gg', 'MS', 'cg', 7, 'e@e.com', 'g');
	INSERT INTO shopcar.Usuario VALUES('8', 'Espeon', 'h', '', 'hh', 'MS', 'cg', 8, 'es@es.com', 'h');
	INSERT INTO shopcar.Usuario VALUES('9', 'Umbreon', 'i', '', 'ii', 'MS', 'cg', 9, 'u@u.com', 'i');
	INSERT INTO shopcar.Usuario VALUES('10', 'Venomoth', 'j', '', 'jj', 'MS', 'cg', 10, 'v@v.com', 'j');
	
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'AAA1111', '12345678/123456');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'BBB2222', '11111111/123456');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'CCC3333', '22222222/111111');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'DDD4444', '33333333/222222');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'EEE5555', '44444444/333333');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'FFF6666', '1');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'GGG7777', '2');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'HHH8888', '3');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'III9999', '4');
	INSERT INTO shopcar.Anuncio(tipo_anuncio, placa, id_anunciante) VALUES(1, 'JJJ1010', '5');
	
	--END POVOAMENTO DE ANUNCIANTES


--END POVOAMENTO PEDIDO PARA O BANCO

--END shopcar.sql














