--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'WIN1252';
SET standard_conforming_strings = off;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET escape_string_warning = off;

SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: automoveis; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE automoveis (
    codigo integer NOT NULL,
    fabricante character varying(128) NOT NULL,
    modelo character varying(64) NOT NULL,
    ano integer NOT NULL,
    pais character varying(32) NOT NULL,
    preco_tabela double precision NOT NULL,
    CONSTRAINT automoveis_chk CHECK ((preco_tabela > (0)::double precision))
);


ALTER TABLE public.automoveis OWNER TO postgres;

SET default_with_oids = true;

--
-- Name: consumidores; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE consumidores (
    identidade character varying(64) NOT NULL,
    nome character varying(128) NOT NULL,
    sobrenome character varying(128) NOT NULL,
    sexo character(1) NOT NULL,
    CONSTRAINT consumidores_chk CHECK ((sexo = ANY (ARRAY['M'::bpchar, 'F'::bpchar])))
);


ALTER TABLE public.consumidores OWNER TO postgres;

--
-- Name: negocios; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE negocios (
    identidade_consumidor character varying(64) NOT NULL,
    cgc_revenda integer NOT NULL,
    codigo_auto integer NOT NULL,
    ano_auto integer NOT NULL,
    data timestamp without time zone DEFAULT now() NOT NULL,
    preco double precision NOT NULL,
    CONSTRAINT negocios_chk CHECK ((preco > (0)::double precision))
);


ALTER TABLE public.negocios OWNER TO postgres;

--
-- Name: revendedoras; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE revendedoras (
    cgc integer NOT NULL,
    nome character varying(128) NOT NULL,
    nome_proprietario character varying(128) NOT NULL,
    cidade character varying(128) NOT NULL,
    estado "char" NOT NULL
);


ALTER TABLE public.revendedoras OWNER TO postgres;

--
-- Data for Name: automoveis; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY automoveis (codigo, fabricante, modelo, ano, pais, preco_tabela) FROM stdin;
1	FIAT	147	1814	BRASIL	10000
2	VW	FUSCA	1815	BRASIL	11000
4	VW	WARIANT	2014	ALEMANHA	150000
\.


--
-- Data for Name: consumidores; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY consumidores (identidade, nome, sobrenome, sexo) FROM stdin;
ZZZZZ SSP/SP	ALAN RAFAEL	DEMSCHINSKI	M
YYYYY SSP/MS	RAFAEL	DELAGO FABR�CIO	M
XXXXX SSP/RJ	HERCULES	DA COSTA SANDIM	M
\.


--
-- Data for Name: negocios; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY negocios (identidade_consumidor, cgc_revenda, codigo_auto, ano_auto, data, preco) FROM stdin;
YYYYY SSP/MS	3	4	2014	2014-04-09 20:14:21	140000
ZZZZZ SSP/SP	2	2	1815	2014-04-09 20:12:49	25000
XXXXX SSP/RJ	1	1	1814	2014-04-09 20:13:59	20000
\.


--
-- Data for Name: revendedoras; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY revendedoras (cgc, nome, nome_proprietario, cidade, estado) FROM stdin;
1	FIAT ENZO	SR. JOAO	CAMPO GRANDE	M
2	AUTOBEL	SRA. MARIA	CAMPO GRANDE	M
3	DISCAUTOL	SR. WILLIAN	CAMPO GRANDE	M
\.


--
-- Name: automoveis_idx; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY automoveis
    ADD CONSTRAINT automoveis_idx PRIMARY KEY (codigo, ano);


--
-- Name: consumidores_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY consumidores
    ADD CONSTRAINT consumidores_pkey PRIMARY KEY (identidade);


--
-- Name: negocios_idx; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_idx PRIMARY KEY (ano_auto, codigo_auto, cgc_revenda, identidade_consumidor);


--
-- Name: revendedoras_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY revendedoras
    ADD CONSTRAINT revendedoras_pkey PRIMARY KEY (cgc);


--
-- Name: negocios_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_fk FOREIGN KEY (identidade_consumidor) REFERENCES consumidores(identidade) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: negocios_fk1; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_fk1 FOREIGN KEY (cgc_revenda) REFERENCES revendedoras(cgc) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: negocios_fk2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY negocios
    ADD CONSTRAINT negocios_fk2 FOREIGN KEY (codigo_auto, ano_auto) REFERENCES automoveis(codigo, ano) ON UPDATE CASCADE ON DELETE RESTRICT;


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

