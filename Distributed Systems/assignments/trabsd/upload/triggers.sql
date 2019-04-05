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
			IF NEW.id_anunciante IN(SELECT Loja.cnpj FROM Loja WHERE Loja.cnpj=NEW.id_anunciante) THEN
				INSERT INTO shopcar.AnuncioLoja(anuncio_id, cnpj_loja) VALUES (NEW.id, NEW.id_anunciante);
			ELSIF NEW.id_anunciante IN (SELECT Usuario.cpf FROM Usuario WHERE Usuario.cpf=NEW.id_anunciante) THEN
				INSERT INTO shopcar.AnuncioUsuario(anuncio_id, cpf_usuario) VALUES(NEW.id, NEW.id_anunciante);
			ELSE
				RAISE EXCEPTION 'Loja ou Usuarios nao encontrados no sistema.' USING HINT='Cheque o cpf/cnpj inseridos.';
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