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