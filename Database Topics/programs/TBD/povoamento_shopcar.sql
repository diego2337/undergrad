--9. POVOAMENTO PEDIDO PARA O BANCO "Alimentar seu banco de dados com, no mínimo, 50 veículos, 15 lojas e 10 anunciantes."

	--9.1. POVOAMENTO DE VEÍCULOS := |placa | tipo | modelo | marca | cor | combustivel | ano carro | ano modelo | preco | km | mais opcionais | descricao :=> 25 carros, 15 caminhoes, 5 onibus ou vans, 5 tratores ou rebocaveis
	INSERT INTO shopcar.Veiculo VALUES ('AAA1111', 1, 'UNO', 'FIAT', 1, 1, 1995, 1996, 10000, 0, 'asd', ' dassad');
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