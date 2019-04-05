--9.2. POVOAMENTO DE LOJAS := |cnpj| nome | email | website | responsavel | telefone loja | celular responsavel | endereco | cep | bairro | cidade | estado

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('12345678/123456', '1000Tons Veículos', '1000tonsveiculos@gmail.com', '', 'Augustus', 92513809, 96089674, 'Av. Thirson de Almeida, 1178', 79085040, 'Guanandy', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('11111111/123456', '1001 Automóveis', '1001automoveis@gmail.com', 'www.1001automoveis.com.br', 'Tiberius', 33841001, 33845961, 'Av. Bandeirantes, 1001', 79005670, 'Amabaí', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('22222222/111111', 'MC Veículos', 'mcveiculos@gmail.com', '', 'Claudius', 33426051, 81151815, 'Rua Bom Sucesso, 802', 79080280, 'Jardim Jóquei Club', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('33333333/222222', 'Center Motors', '', '', 'Nero', 33451000, 99332965, 'Av. Ernesto Geisel, 510', 79006162, 'Vila Taquarussu', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, endereco, cep, bairro, cidade, estado) VALUES ('44444444/333333', 'Dois Irmãos Automóveis', '', 'www.doisirmaosautomoveis.com.br', 'Galba', 30274008, 'Rua Alegrete, 1203', 79010800, 'Coronel Antonino', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('66666666/555555', 'Endo Car', '', 'www.grupoendo.com.br', 'Otho', 30283514, 84051009, 'Rua 14 de Julho, 1453', 79002330, 'Centro', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('66666666/666666', 'KCinco Caminhões e Ônibus', '', '', 'Vitellius', 33220800, 33220801, 'Av. Eduardo Elias Zahran, 240', 79004000, 'Vila Santa Doroteia', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('77777777/666666', 'Itanhangá Veículos', '', '', 'Vespasian', 30286040, 92203466 , 'Rua Joaquim Murtinho, 1983', 79004000, 'Vila Santa Doroteia', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('88888888/777777', 'GTrês Máquinas Rodoviárias', '', '', 'Titus', 33220800, 33220801, 'Av. Eduardo Elias Zahran, 240', 79003020, 'Itanhaguá Park', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('99999999/888888', 'Layfer Veículos', '', '', 'Domitian', 30435008, 30266608, 'Av. Brilhante, 2197', 79003020, 'Vila Bandeirantes', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('00000000/999999', 'Jatobá Caminhões', '', '', 'Nerva', 33881876, 92861460, 'Av. Guaicurus, 5497', 79062310, 'Jardim Macapá', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, celular_responsavel, endereco, cep, bairro, cidade, estado) VALUES ('01234567/123456', 'F3 Veículos', '', '', 'Trajan', 30256161, 30436151, 'Rua Spipe Calarge, 350', 79050261, 'Jardim TV Morena', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, endereco, cep, bairro, cidade, estado) VALUES ('23456789/456789', 'Discautol', '', 'www.discautol.com.br', 'Hadrian', 33229000, 'Av. Afonso Pena, 1440', 79005000, 'Centro', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, endereco, cep, bairro, cidade, estado) VALUES ('45678912/012345', 'Fiat Enzo', '', 'www.fiatenzo.com.br', 'Antoninus Pius', 33220600, 'Rua Joaquim Murtinho, 2350', 79003020, 'Miguel Couto', 'Campo Grande', 'MS');

INSERT INTO shopcar.Loja (cnpj, nome, email, website, responsavel, telefone_loja, endereco, cep, bairro, cidade, estado) VALUES ('56789123/025896', 'HC Veículos Show Room', '', '', 'Marcus Aurelius', 30431305, 'Rua Joaquim Murtinho, 1490', 79003020, 'Itanhanguá Park', 'Campo Grande', 'MS');

--END POVOAMENTO DE LOJAS

--9.1. POVOAMENTO DE VEÍCULOS := |placa | tipo | modelo | marca | cor | combustivel | ano carro | ano modelo | preco | km | mais opcionais | descricao :=> 25 carros, 15 caminhoes, 5 onibus ou vans, 5 tratores ou rebocaveis

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, mais_opcionais, descricao) VALUES ('AAA1111', 1, 'Gol 1.0 G4 4p.', 'VOLKSWAGEN', 22, 5, 2007, 2007, 15500, 70000, '', 'Carro bem conservado.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, mais_opcionais, descricao) VALUES ('BBB2222', 1, 'Gol 1.0 GIII 4p.', 'VOLKSWAGEN', 14, 1, 2005, 2005, 14500, 80000, '', 'Carro muito conservado.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('CCC33333', 1, '206 Selection 1.0 16v 4p.', 'PEUGEOT', 33, 1, 2005, 2006, 13500, 65000);

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

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km) VALUES ('OOO1515', 4, '75III', 'MICHIGAN', 1, 3, 1976, 1976, 60000, 0);

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('PPP1616', 3, '1114', 'MERCEDEZ-BENZ', 1, 3, 1989, 1989, 0, 0, 'Caminhão pronto para por caçamba. Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('QQQ1717', 3, '710', 'MERCEDEZ-BENZ', 6, 3, 2002, 2002, 0, 0, 'Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('RRR1818', 3, '12-140', 'VOLKSWAGEN', 6, 3, 1998, 1998, 0, 0, 'Documentação ok. Financiamos. Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('SSS1919', 3, '12-140 H', 'VOLKSWAGEN', 6, 3, 1993, 1994, 0, 0, 'Financiamos. Aceitamos troca. Documentação ok. Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('TTT2020', 3, '1113', 'MERCEDEZ-BENZ', 3, 3, 1978, 1978, 39000, 0, 'Toco. 6 pneus novos, carroceria nova.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('UUU2121', 3, 'Astra Sedan Elegance 2.0', 'CHEVROLET/GM', 21, 5, 2005, 2005, 19500, 0, 'Uma ótima oportunidade, com preço de ocasião.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('VVV2222', 3, 'Amarok Highline 2.0TDi 16v 4x4 C.D.', 'VOLKSWAGEN', 21, 3, 2011, 2012, 0, 78000, 'Revisado e periciado. Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('UUU2323', 3, 'Fox 1.6 4p.', 'VOLKSWAGEN', 14, 5, 2011, 2012, 0, 40000, 'Revisado e periciado. Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('VVV2424', 3, '500 Cult 1.4 Evo', 'FIAT', 14, 5, 2011, 2012, 0, 32000, 'Consulte-nos para preços.');

INSERT INTO shopcar.Veiculo (placa, tipo_id, modelo, marca, cor_id, comb_id, ano_carro, ano_modelo_veiculo, preco, km, descricao) VALUES ('XXX2525', 3, '500 Cult 1.4 Evo', 'FIAT', 33, 5, 2011, 2012, 0, 31000, 'Consulte-nos para preços.');

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

--9.3. POVOAMENTO DE ANUNCIANTES |cpf |nome |endereco |complemento |bairro |uf |cidade |telefone |email |senha

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (1, 'Ido dos Santos Ximenes', 'MS', 'Campo Grande', 
92981931, 'ido@gmail.com', 'Ido dos Santos Ximenes');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (2, 'Izauro Lino de Menezes', 'MS', 'Campo Grande', 
81013978, 'izauro@gmail.com', 'Izauro Lino de Menezes');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (3, 'Rodrigo Jose Gonçalves', 'MS', 'Campo Grande', 
99915817, 'rodrigo@gmail.com', 'Rodrigo Jose Gonçalves');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (4, 'Luciano Carlos Silveira', 'MS', 'Campo Grande', 
99265040, 'luciano@gmail.com', 'Luciano Carlos Silveira');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (5, 'Mark Pierezan', 'MS', 'Campo Grande', 
81386540, 'mark@gmail.com', 'Mark Pierezan');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (6, 'André Luis Ortega', 'MS', 'Campo Grande', 
91933178, 'andre@gmail.com', 'André Luis Ortega');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (7, 'Gil Vicente Delgado', 'MS', 'Campo Grande', 
91404797, 'gil@gmail.com', 'Gil Vicente Delgado');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (8, 'Wanessa Costa Merel', 'MS', 'Campo Grande', 
99283872, 'wanessa@gmail.com', 'Wanessa Costa Merel');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (9, 'Claudio Jacinto Alves', 'MS', 'Campo Grande', 
99226101, 'claudio@gmail.com', 'Claudio Jacinto Alves');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (10, 'Tarley do Carmomeza', 'MS', 'Campo Grande', 
99893919, 'tarley@gmail.com', 'Tarley do Carmomeza');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (11, 'Marcos Frederico', 'MS', 'Campo Grande', 
92959800, 'marcos@gmail.com', 'Marcos Frederico');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (12, 'Jeferson Mendes Martinez', 'MS', 'Campo Grande', 
92366564, 'jeferson@gmail.com', 'Jeferson Mendes Martinez');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (13, 'João Victor', 'MS', 'Campo Grande', 
91317304, 'joao@gmail.com', 'João Victor');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (14, 'César de Brito Gonçalves', 'MS', 'Campo Grande', 
99635337, 'cesar@gmail.com', 'César de Brito Gonçalves');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (15, 'João Guilherme A. Akayama', 'MS', 'Campo Grande', 
32419821, 'akayama@gmail.com', 'João Guilherme A. Akayama');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (16, 'Eduardo da Silva Sobral', 'MS', 'Campo Grande', 
92934130, 'eduardo@gmail.com', 'Eduardo da Silva Sobral');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (17, 'David Chadid Warpechowski', 'MS', 'Campo Grande', 
92373866, 'david@gmail.com', 'David Chadid Warpechowski');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (18, 'Anderson Ferreira de Souza', 'MS', 'Campo Grande', 81451703, 'anderson@gmail.com', 'Anderson Ferreira de Souza');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (19, 'Amadeu Wagner Borges', 'MS', 'Campo Grande', 99084576, 'anderson@gmail.com', 'Amadeu Wagner Borges');

INSERT INTO shopcar.Usuario (cpf, nome, uf, cidade, telefone, email, senha) VALUES (20, 'Marcelo', 'MS', 'Campo Grande', 91117325, 'marcelo@gmail.com', 'Marcelo');

--END POVOAMENTO DE ANUNCIANTES
