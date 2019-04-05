--4. CRIA��O DE RELA��ES
--LOJA
	--Para aderir novas lojas ao sistema, pede-se: 
	--Raz�o social, Nome, CNPJ, email, website, responsavel, telefone da loja, celular do responsavel, (quantidade de anuncios), 
	--endere�o(rua e numero), cep, bairro, cidade e estado 
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
	--Para cadastrar ve�culos, o sistema pede:
	--Tipo, Marca, Modelo, Ano de fabrica��o, ano do modelo, cor, combust�vel, quilometragem, placa, {opcionais}, pre�o
	--Mais opcionais(um espa�o de texto, que s�o acess�rios do ve�culo), descri��o (texto sobre a situa��o geral) e
	--observa��es adicionais(condi��es de pagamento e negocia��o)


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

	--tem uma negada de op��o de cor tb, poderia ser uma tripla de inteiros, pq tem fun��o rgb no postgresql mas n�, enfim, as op��es s�o:
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


	--Tem Marca adoidado. Mas ok, as marcas para todos os ve�culos s�o:
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

	--Marcas para Caminh�es:
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

	--Marcas para Tratores/Reboc�veis:
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


	--rela��o ve�culo
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
	mais_opcionais TEXT NOT NULL DEFAULT 'Nenhuma informa��o adicional.', 
	descricao TEXT,
	CONSTRAINT veiculo_shopcar_pk PRIMARY KEY (placa),
	CONSTRAINT veiculo_tipo_fk FOREIGN KEY (tipo_id) REFERENCES Tipo (tipo_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	CONSTRAINT veiculo_cor_fk FOREIGN KEY (cor_id) REFERENCES Cor (cor_id) ON DELETE RESTRICT ON UPDATE CASCADE,
	CONSTRAINT veiculo_comb_fk FOREIGN KEY (comb_id) REFERENCES Combustivel (comb_id) ON DELETE RESTRICT ON UPDATE CASCADE
);
--OK


	--Opcionais, tem opcionais a dar com pau:
	--Eles s�o Air Bag, Air Bag Duplo, Alarme, Ar Condicionado, Ar Quente, Banco de Couro, B�sica,
	--B�sico, C�mbio Autom�tico, C�mbio Sequencial, Capota Mar�tima, Completa, Dire��o Hidr�ulica,
	--Completo, Computador de Bordo, Desemba�ador Traseiro, Dire��o El�trica, Disqueteira CD,
	--Engate ou Rabicho, Estribo, Farol de Neblina, Farol Xenon, Freios ABS, Kit GNV,
	--Limpaodr e Desemba�ador Traseiro, Limpador Traseiro, MP3 Player, Piloto Autom�tico,
	--Protetor de Ca�amba, Retrovisor El�trico, Rodas, Santo Ant�nio, Trava El�trica,
	--Sensor de Estacionamento, Som CD, Teto Solar, Tra��o 4X4, Vidro El�trico (38 opcionais)
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

--USU�RIOS DO SITE
	--Para cadastrar usu�rios, o sistema pede:
	--Nome Completo, CPF, Endere�o(rua), Complemento, Bairro, UF, Cidade, Telefone, email e senha

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
	--Para separar usuario_site de anunciante, criaremos a rela��o anunciante
	--Com ela, vemos a necessidade de ter: o tipo do an�ncio suportado pelo site shopcar e
	--Verificar se o an�ncio � de uma loja ou de um usu�rio
	
	
	--Onde o tipo pode ser: gr�tis, bronze, prata, ouro e at� vender (5 tipos)
	--O pre�o dos tipos �, respectivamente, 0, 20, 40, 75 e 90 reais
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
	id_anunciante TEXT NOT NULL, --pode ser um cnpj ou um cpf, somente usu�rios cadastrados podem fazer inser��o aqui.
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

--END CRIA��O DE RELA��ES