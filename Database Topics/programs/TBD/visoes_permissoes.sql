--6. CRIA��O DE VIEWS PARA DAR PERMISS�ES AOS USU�RIOS NOVOS // usu�rios: loja_shopcar, anunciante_shopcar e usuario_shopcar
	--PARA loja_shopcar
	SET search_path=loja_shopcar;
	CREATE VIEW loja AS SELECT * FROM shopcar.Loja;
	--OK
	
	
	--PARA anunciante_shopcar
	SET search_path=anunciante_shopcar;
	CREATE VIEW anunciante AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	--OK
	
	
	--PARA usuario_shopcar;
	SET search_path=usuario_site_shopcar;
	CREATE VIEW usuario_site AS SELECT cpf, nome, endereco, uf, email FROM shopcar.Usuario WHERE shopcar.Usuario.cpf NOT IN(SELECT cpf_usuario FROM shopcar.AnuncioUsuario);
	--OK
	
	
--END CRIA��O DE VIEWS PARA OS USU�RIOS

--7. PERMISS�ES DOS NOVOS USU�RIOS
	--PARA loja_shopcar
	SET search_path=shopcar;
	GRANT INSERT ON shopcar.Loja TO loja_shopcar;
	GRANT SELECT ON loja_shopcar.loja TO loja_shopcar;
	--OK
	
	--PARA anunciante_shopcar
	GRANT INSERT ON shopcar.Anuncio TO anunciante_shopcar;
	GRANT SELECT ON anunciante_shopcar.anunciante TO anunciante_shopcar;
	
	--PARA usuario_shopcar
	GRANT INSERT ON shopcar.Usuario TO usuario_shopcar;
	GRANT SELECT ON usuario_site_shopcar.usuario_site TO usuario_shopcar;
	
--END PERMISS�ES DOS NOVOS USU�RIOS