-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 14, 2013 at 10:53 PM
-- Server version: 5.5.32
-- PHP Version: 5.3.10-1ubuntu3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `Pokedex`
--
CREATE DATABASE `Pokedex` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE `Pokedex`;

-- --------------------------------------------------------

--
-- Table structure for table `Ataque`
--

CREATE TABLE IF NOT EXISTS `Ataque` (
  `nome_ataque` varchar(25) COLLATE utf8_bin NOT NULL DEFAULT '',
  `tipo_ataque` varchar(20) COLLATE utf8_bin NOT NULL,
  `quantidade` int(11) NOT NULL,
  `poder` int(11) NOT NULL,
  `precisao` int(11) NOT NULL,
  `efeito` varchar(200) COLLATE utf8_bin DEFAULT NULL,
  `uso_fora_da_batalha` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`nome_ataque`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `Item`
--

CREATE TABLE IF NOT EXISTS `Item` (
  `nome_item` varchar(20) COLLATE utf8_bin NOT NULL,
  `funcao` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `codigo_item` int(11) NOT NULL DEFAULT '0',
  `preco` float DEFAULT NULL,
  PRIMARY KEY (`codigo_item`),
  KEY `nome_item` (`nome_item`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `Pokemart_vende_item`
--

CREATE TABLE IF NOT EXISTS `Pokemart_vende_item` (
  `local_pokemart` varchar(50) COLLATE utf8_bin NOT NULL DEFAULT '',
  `codigo_item` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`local_pokemart`,`codigo_item`),
  KEY `codigo_item` (`codigo_item`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `Pokemon`
--

CREATE TABLE IF NOT EXISTS `Pokemon` (
  `nome_pokemon` varchar(70) COLLATE utf8_bin NOT NULL,
  `numero_pokemon` int(11) NOT NULL DEFAULT '0',
  `tipo` varchar(20) COLLATE utf8_bin NOT NULL,
  `regiao` varchar(40) COLLATE utf8_bin DEFAULT NULL,
  `nivel` int(11) NOT NULL,
  `descricao` varchar(300) COLLATE utf8_bin DEFAULT NULL,
  `imagem` varchar(50) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`numero_pokemon`),
  KEY `nome_pokemon` (`nome_pokemon`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `Pokemon`
--

INSERT INTO `Pokemon` (`nome_pokemon`, `numero_pokemon`, `tipo`, `regiao`, `nivel`, `descricao`, `imagem`) VALUES
('Bulbasaur', 1, 'Planta', 'Kanto', 1, 'Bulbasaur. Ele carrega a semente de uma planta em suas costas desde o nascimento. A semente se desenvolve lentamente. Os pesquisadores nÃ£o tÃªm certeza se classificam Bulbasaur como uma planta ou animal. Bulbasaur Ã© extremamente calmo e muito difÃ­cil de capturar na natureza.', 'Bulbasaur.png'),
('Ivysaur', 2, 'Planta', 'Kanto', 16, 'A semente PokÃ©mon, Ivysaur, forma evoluÃ­da de Bulbasaur. O bulbo em suas costas absorve nutrientes e floresce em uma grande flor.', 'Ivysaur.png'),
('Venusaur', 3, 'Planta', 'Kanto', 32, 'Venusaur, a forma final da evoluÃ§Ã£o Bulbasaur. Este PokÃ©mon semente absorve os raios do sol como fonte de energia.', 'Venusaur.png'),
('Charmander', 4, 'Fogo', 'Kanto', 1, 'Charmander, quando nasce traz uma chama que continua a arder na ponta da sua cauda. Diz-se que se a chama se apagar, o Charmander morre.', 'Charmander.png'),
('Charmeleon', 5, 'Fogo', 'Kanto', 16, 'Charmeleon, o PokÃ©mon de Chamas. Tem garras afiadÃ­ssimas e a sua cauda Ã© muito forte.', 'Charmeleon.png'),
('Charizard', 6, 'Fogo', 'Kanto', 36, 'Charizard, o PokÃ©mon Chama. Charizard Ã© do tipo Fogo e Voador. Ao competir em batalhas intensas, a chama de Charizard se torna mais intensa tambÃ©m.', 'Charizard.png'),
('Squirtle', 7, 'Agua', 'Kanto', 1, 'Squirtle. Esta pequena Tartaruga PokÃ©mon mete o seu longo pescoÃ§o dentro da carapaÃ§a para lanÃ§ar ataques aquÃ¡ticos com uma velocidade e precisÃ£o incrÃ­veis.', 'Squirtle.png'),
('Wartortle', 8, 'Agua', 'Kanto', 16, 'Wartortle, o PokÃ©mon Tartaruga. A forma evoluÃ­da de Squirtle. Sua longa cauda peluda Ã© um sÃ­mbolo de sua idade e sabedoria.', 'Wartortle.png'),
('Blastoise', 9, 'Agua', 'Kanto', 36, 'Blastoise, o PokÃ©mon CrustÃ¡ceo. A forÃ§a do Blastoise, esta forma evoluÃ­da do Wartortle, reside no seu poder e nÃ£o na sua velocidade. A sua carapaÃ§a parece uma armadura e os ataques do hidro canhÃ£o que tem nas costas sÃ£o praticamente inelutÃ¡veis.', 'Blastoise.png'),
('Caterpie', 10, 'Inseto', 'Kanto', 1, 'Caterpie, o PokÃ©mon Lagarta. O Caterpie usa as ventosas das patas para trepar Ã s Ã¡rvores e alimentar-se das folhas.', 'Caterpie.png'),
('Metapod', 11, 'Inseto', 'Kanto', 7, 'Metapod, o PokÃ©mon Casulo. O Metapod Ã© a forma evoluÃ­da do Caterpie. AtravÃ©s de um casulo que lhe protege o corpo, o Metapod prepara-se para a prÃ³xima evoluÃ§Ã£o.', 'Metapod.png'),
('Butterfree', 12, 'Inseto', 'Kanto', 10, 'Butterfree, o PokÃ©mon Borboleta. O Butterfree Ã© forma evoluÃ­da do Metapod. As escamas que envolvem as asas ajudam-no a espalhar Ã¡gua.', 'Butterfree.png'),
('Weedle', 13, 'Inseto', 'Kanto', 1, 'Weedle. O ferrÃ£o na cabeÃ§a deste pokÃ©mon garante que qualquer atacante Ã© espetado no sÃ­tio certo.', 'Weedle.png'),
('Kakuna', 14, 'Inseto', 'Kanto', 7, 'Kakuna, uma transiÃ§Ã£o entre Weedle e Beedrill. As Kakuna permanecem inactivas atÃ© se transformarem em Beedrill mortÃ­feras.', 'Kakuna.png'),
('Beedrill', 15, 'Inseto', 'Kanto', 10, 'Beedrill. SÃ£o formas evoluÃ­das de Weedle, a seguir ao estÃ¡gio de casulo. O seu ferrÃ£o Ã© muito venenoso.', 'Beedrill.png'),
('Pidgey', 16, 'Normal', 'Kanto', 1, 'Os Pidgey sÃ£o PokÃ©mon voadores e dentre todos os PokÃ©mon voadores sÃ£o os mais mansos e fÃ¡ceis de apanhar. SÃ£o alvos perfeitos para treinadores principiantes testarem as habilidades de seus PokÃ©mon. Os Pidgey tÃªm o poder de criar tornados, tambÃ©m atacam com areia.', 'Pidgey.png'),
('Pidgeotto', 17, 'Normal', 'Kanto', 18, 'Pidgeotto Ã© uma forma evoluida do Pidgey. Tem garras afiadas e mergulha do cÃ©u para capturar a presa. Ao contrÃ¡rio do manso Pidgey, o Pidgeotto pode ser perigoso. Deve-se aproximar-se com cautela.', 'Pidgeotto.png'),
('Pidgeot', 18, 'Normal', 'Kanto', 36, 'Pidgeot, o PokÃ©mon PÃ¡ssaro. A forma evoluÃ­da do Pidgeotto, pode voar ao dobro da velocidade do solo com uma altitude de um quilÃ³metro e meio.', 'Pidgeot.png'),
('Rattata', 19, 'Normal', 'Kanto', 1, 'O PokÃ©mon Rattata da floresta. Gosta de queijo, nozes, fruta e bagas. TambÃ©m anda em campos abertos para roubar comida aos viajantes estÃºpidos.', 'Rattata.png'),
('Raticate', 20, 'Normal', 'Kanto', 20, 'Raticate Ã© um grande Roedor PokÃ©mon. Embora seja muitas vezes representado sobre as patas traseiras, Ã© um quadrÃºpede. Tem grandes incisivos que crescem constantemente. Estes dentes sÃ£o fortes o suficiente para roer aÃ§o.', 'Raticate.png'),
('Spearow', 21, 'Normal', 'Kanto', 1, 'Ao contrÃ¡rio dos Pidgey, os Spearow sÃ£o extremamente maus. SÃ£o muito selvagens e por vezes atacam outros PokÃ©mon e humanos.', 'Spearow.png'),
('Fearow', 22, 'Normal', 'Kanto', 20, 'Fearow, o PokÃ©mon de Bico. A forma evoluÃ­da do Spearow. As suas grandes e poderosas asas permitem que ele voe durante um dia inteiro. O poder esmagador do seu bico Ã© tremendo.', 'Fearow.png'),
('Ekans', 23, 'Venenoso', 'Kanto', 1, 'Ekans enrola-se em uma espiral enquanto ele descansa. Assumindo esta posiÃ§Ã£o permite responder rapidamente a uma ameaÃ§a de qualquer direÃ§Ã£o com um olhar de sua cabeÃ§a erguida.', 'Ekans.png'),
('Arbok', 24, 'Venenoso', 'Kanto', 22, 'Este PokÃ©mon Ã© terrivelmente forte, a fim de comprimir as coisas com o seu corpo. Ele ainda pode achatar tambores de Ã³leo de aÃ§o. Uma vez que Arbok envolve seu corpo em torno de seu inimigo, escapar de seu abraÃ§o esmagador Ã© impossÃ­vel.', 'Arbok.png'),
('Pikachu', 25, 'ElÃ©trico', 'Kanto', 1, 'Pikachu, o PokÃ©mon Rato. Pode gerar ataques elÃ©ctricos a partir de bolsas localizadas nas suas bochechas.', 'Pikachu.png'),
('Raichu', 26, 'ElÃ©trico', 'Kanto', 1, 'Raichu, um Rato PokÃ©mon do elemento elÃ©ctrico. Raichu Ã© a forma evoluÃ­da do Pikachu (evolui por meio da Thunder Stone). Pode dar um choque de mais 100.000 volts, pode pÃ´r um Dragonite inconsciente. ', 'Raichu.png'),
('Sandshrew', 27, 'Terrestre', 'Kanto', 1, 'Sandshrew, o PokÃ©mon Rato. O Sandshrew nÃ£o gosta de sÃ­tios Ãºmidos e vive em buracos que escava em terrenos secos. Protege-se curvando-se e fazendo uma bola.', 'Sandshrew.png'),
('Sandslash', 28, 'Terrestre', 'Kanto', 22, 'Sandslash, o PokÃ©mon Rato. A forma evoluÃ­da do Sandshrew. Ataca os adversÃ¡rios com os espinhos das costas.', 'Sandslash.png'),
('Nidoran â™€', 29, 'Venenoso', 'Kanto', 1, 'Nidoran â™€. O seu pico envenenado Ã© bastante poderoso para o seu tamanho, mas o seu corno Ã© mais pequeno que o do macho.', 'Nidoran â™€.png'),
('Nidorina', 30, 'Venenoso', 'Kanto', 16, 'Nidorina, o PokÃ©mon de EspigÃ£o Envenenado. A forma evoluÃ­da da fÃªmea Nidoran. Emite ondas supersÃ³nicas da boca para confundir os seus inimigos.', 'Nidorina.png'),
('Nidoqueen', 31, 'Venenoso', 'Kanto', 16, 'Nidoqueen, o PokÃ©mon Broca. Nidoqueen tem uma espessa camada de pele que reveste o seu corpo, protegendo-o de qualquer tÃ©cnica de Ã¡gua usada contra si. (Evolui por meio da Moon Stone).', 'Nidoqueen.png'),
('Nidoran â™‚', 32, 'Venenoso', 'Kanto', 1, 'Nidoran â™‚. O seu chifre Ã© maior que o da fÃªmea e o seu Ataque de Chifre Ã© bastante poderoso.', 'Nidoran â™‚.png'),
('Nidorino', 33, 'Venenoso', 'Kanto', 16, 'Nidorino, o PokÃ©mon de EspigÃ£o Envenenado. A forma evoluÃ­da do macho Nidoran. O seu chifre altamente desenvolvido Ã© extremamente poderoso.', 'Nidorino.png'),
('Nidoking', 34, 'Venenoso', 'Kanto', 16, 'Nidoking, o PokÃ©mon Broca. Com um golpe da sua poderosa cauda consegue arrancar um poste telefÃ³nico como se tratasse de um fÃ³sforo (Evolui por meio da Moon Stone).', 'Nidoking.png'),
('Clefairy', 35, 'Normal', 'Kanto', 1, 'Clefairy. Este PokÃ©mon irrequieto Ã© amigÃ¡vel e dÃ³cil. Acredita-se que viva dentro de cavernas embora poucos tenham sido avistados por humanos.', 'Clefairy.png'),
('Clefable', 36, 'Normal', 'Kanto', 1, 'Clefable, uma forma avanÃ§ada das Clefairy. Estas criaturinhas sÃ£o dos mais raros PokÃ©mon do mundo (Evoluir por meio da Moon Stone).', 'Clefable.png'),
('Vulpix', 37, 'Fogo', 'Kanto', 1, 'Vulpix, um PokÃ©mon Raposa. As suas seis caudas sÃ£o maravilhosas. Quando evolui crescem-lhe mais caudas.', 'Vulpix.png'),
('Ninetales', 38, 'Fogo', 'Kanto', 1, 'Ninetales, o PokÃ©mon Raposa. A forma evoluÃ­da do Vulpix. Tem nove caudas e pÃªlo brilhante e dourado. Os Ninetales tÃªm vidas muito longas (Evolui por meio da Fire Stone).', 'Ninetales.png'),
('Jigglypuff', 39, 'Normal', 'Kanto', 1, 'Jigglypuff, um PokÃ©mon BalÃ£o. Tem olhos grandes e amigÃ¡veis e canta uma canÃ§Ã£o bastante agradÃ¡vel.', 'Jigglypuff.png'),
('Wigglytuff', 40, 'Normal', 'Kanto', 1, 'Wigglytuff tem olhos grandes. As superfÃ­cies dos seus olhos sÃ£o sempre cobertas com uma fina camada de lÃ¡grimas. Caso o pÃ³ entre nos olhos deste PokÃ©mon, estes sÃ£o rapidamente lavados (evolui por meio da Moon Stone).', 'Wigglytuff.png'),
('Zubat', 41, 'Venenoso', 'Kanto', 1, 'Zubat, um PokÃ©mon voador com poderes supersÃ³nicos. Vive em cavernas e detesta voar Ã  luz do dia.', 'Zubat.png'),
('Golbat', 42, 'Venenoso', 'Kanto', 22, 'Golbat. Este PokÃ©mon ataca com as suas presas afiadas, pode sugar 300 centÃ­metros cÃºbicos de sangue por dentada.', 'Golbat.png'),
('Oddish', 43, 'Planta', 'Kanto', 1, 'Oddish, este PokÃ©mon Ã© tipicamente encontrado a passear pela floresta, espalha pÃ³len ao andar.', 'Oddish.png'),
('Gloom', 44, 'Planta', 'Kanto', 21, 'Gloom, o PokÃ©mon Erva. O Gloom liberta um cheiro muito desagradÃ¡vel. Ao passo que Ã© forte contra pokÃ©mon do tipo de Ã¡gua, o Gloom Ã© fraco contra tipos de fogo e voador.', 'Gloom.png'),
('Vileplume', 45, 'Planta', 'Kanto', 21, 'Vileplume, o PokÃ©mon Flor. Ao usar as maiores pÃ©talas do mundo, ele espalha grandes nuvens de polÃ©n que causam reacÃ§Ãµes alÃ©rgicas (evolui por meio da Leaf Stone).', 'Vileplume.png'),
('Paras', 46, 'Inseto', 'Kanto', 1, 'Paras, um PokÃ©mon Cogumelo. Nascem-lhe cogumelos raros nas costas.', 'Paras.png'),
('Parasect', 47, 'Inseto', 'Kanto', 24, 'Parasect, o PokÃ©mon Cogumelo. Luta usando esferas venenosas que saltam do cogumelo nas suas costas.', 'Parasect.png'),
('Venonat', 48, 'Inseto', 'Kanto', 1, 'Venonat, um PokÃ©mon Inseto. Os seus olhos funcionam como radar podendo assim ver no escuro.', 'Venonat.png'),
('Venomoth', 49, 'Inseto', 'Kanto', 31, 'Venomoth, uma forma evoluÃ­da do Venonat. As pequenas escamas nas suas asas largam vÃ¡rios esporos quando se abrem.', 'Venomoth.png'),
('Diglett', 50, 'Terrestre', 'Kanto', 1, 'Diglett. O movimento destes PokÃ©mon subterrÃ¢neos pode ser detectado pelo seu rasto de terra revolvida.', 'Diglett.png'),
('Dugtrio', 51, 'Terrestre', 'Kanto', 26, 'Dugtrio, formado quando trÃªs Diglett se juntam. Este pokÃ©mon Ã© capaz de cavar atÃ© por baixo da superfÃ­cie da terra.', 'Dugtrio.png'),
('Meowth', 52, 'Normal', 'Kanto', 1, 'Meowth, o PokÃ©mon Gato. O Meowth adora ronronar durante a noite para ganhar moedas e objetos que brilhem, mas passa a maior parte do dia a dormir.', 'Meowth.png'),
('Persian', 53, 'Normal', 'Kanto', 28, 'Persian, o PokÃ©mon gato elegante Ã© a forma evoluÃ­da de Meowth. Persian pode andar silenciosamente graÃ§as a seus mÃºsculos Ã¡geis. Ele se lanÃ§a sobre sua presa na velocidade da luz.', 'Persian.png'),
('Psyduck', 54, 'Agua', 'Kanto', 1, 'Psyduck, o PokÃ©mon Pato. O Psyduck sofre de enxaquecas frequentes e pode fazer ataques estranhos quanto estas se tornam muito intensas.', 'Psyduck.png'),
('Golduck', 55, 'Agua', 'Kanto', 33, 'Golduck, o PokÃ©mon Pato. A forma evoluÃ­da do Psyduck. O Golduck usa muito bem os seus pÃ©s e mÃ£os palmÃ­pedes, sendo assim o pokÃ©mon nadador mais rÃ¡pido de todos.', 'Golduck.png'),
('Mankey', 56, 'Lutador', 'Kanto', 1, 'Mankey, um PokÃ©mon Primata do estilo lutador. Conhecido pelos seus magnÃ­ficos pontapÃ©s, dÃ¡ murros muito fortes.', 'Mankey.png'),
('Primeape', 57, 'Lutador', 'Kanto', 28, 'Se estabelecerem contato com o Primeape, forma evoluÃ­da do Mankey, ele perseguir-vos-Ã¡ para sempre.', 'Primeape.png'),
('Growlithe', 58, 'Fogo', 'Kanto', 1, 'Growlithe, um PokÃ©mon BebÃ© bem comportado e muito esforÃ§ado. Afasta os inimigos com latidos e mordidas.', 'Growlithe.png'),
('Arcanine', 59, 'Fogo', 'Kanto', 1, 'Arcanine, o PokÃ©mon LendÃ¡rio. O Arcanine move-se de forma tÃ£o suave que quase parece voar e Ã© conhecido pelo seu som majestoso (evolui por meio da Fire Stone).', 'Arcanine.png'),
('Poliwag', 60, 'Agua', 'Kanto', 1, 'Poliwag, o PokÃ©mon Sapo. NÃ£o tem braÃ§os, mas a sua cauda faz dele um bom nadador.', 'Poliwag.png'),
('Poliwhirl', 61, 'Agua', 'Kanto', 25, 'Poliwhirl, o PokÃ©mon Sapo. Os seus mÃºsculos altamente desenvolvidos permitem ao Poliwhirl mexer-se eficientemente em terra, mas Ã© ainda mais Ã¡gil na Ã¡gua.', 'Poliwhirl.png'),
('Poliwrath', 62, 'Agua', 'Kanto', 25, 'Poliwrath, o PokÃ©mon Sapo. O Poliwrath Ã© um nadador excelente e os seus poderosos mÃºsculos tornam os seus ataques extremamente eficientes (evolui por meio da Water Stone).', 'Poliwrath.png'),
('Abra', 63, 'Psiquico', 'Kanto', 1, 'Abra, um PokÃ©mon de Poderes PsÃ­quicos. Dorme dezoito horas por dia, mas usa a telequinese mesmo a dormir.', 'Abra.png'),
('Kadabra', 64, 'Psiquico', 'Kanto', 16, 'Kadabra, um PokÃ©mon PsÃ­quico. A forma evoluÃ­da do Abra. Usa ataques telequinÃ©ticos poderosos.', 'Kadabra.png'),
('Alakazam', 65, 'Psiquico', 'Kanto', 16, 'Alakazam, o PokÃ©mon PsÃ­quico e a forma evoluÃ­da do Kadabra. Com o cÃ©rebro semelhante a um super computador, possui vÃ¡rios poderes sobrenaturais (evolui por meio da troca de pokÃ©mon).', 'Alakazam.png'),
('Machop', 66, 'Lutador', 'Kanto', 1, 'Machop, o PokÃ©mon Superpoderoso. Machop tem mÃºsculos incansÃ¡veis independentemente do nÃ­vel de exercÃ­cio. Tem forÃ§a suficiente para atirar ao ar cem adultos de estatura mÃ©dia.', 'Machop.png'),
('Machoke', 67, 'Lutador', 'Kanto', 28, 'Machoke, o PokÃ©mon Superpoder. Com a sua forÃ§a consegue levantar um caminhÃ£o sÃ³ com uma mÃ£o, os Machoke sÃ£o muitas vezes usados em trabalhos pesados.', 'Machoke.png'),
('Machamp', 68, 'Lutador', 'Kanto', 28, 'Machamp tem o poder de lanÃ§ar qualquer coisa. No entanto, ao tentar fazer qualquer trabalho que requer cuidado e destreza faz com que seus braÃ§os fiquem emaranhados. Este PokÃ©mon tende a entrar em aÃ§Ã£o antes de pensar (evolui por meio da troca de pokÃ©mon).', 'Machamp.png'),
('Bellsprout', 69, 'Planta', 'Kanto', 1, 'O corpo fino e flexÃ­vel de um Bellsprout deixa dobrar e balanÃ§ar para evitar qualquer ataque, por mais forte que seja. De sua boca, ele vaza um lÃ­quido que derrete atÃ© ferro.', 'Bellsprout.png'),
('Weepinbell', 70, 'Planta', 'Kanto', 21, 'Weepinbell tem um grande gancho na sua extremidade posterior. Ã€ noite, o PokÃ©mon se engancha em um galho de Ã¡rvore e vai dormir. Se ele se mover enquanto dorme, pode acordar no chÃ£o.', 'Weepinbell.png'),
('Victreebel', 71, 'Planta', 'Kanto', 21, 'Victreebel tem uma longa videira que se estende desde a sua cabeÃ§a. Esta videira Ã© ondulada e balanÃ§a como se fosse um animal para atrair presas. Quando uma presa inocente se aproxima, este PokÃ©mon o engole inteiro (evolui por meio da Leaf Stone).', 'Victreebel.png'),
('Tentacool', 72, 'Agua', 'Kanto', 1, 'Tentacool, uma Alforreca PokÃ©mon. 99% do seu corpo Ã© composto por Ã¡gua.', 'Tentacool.png'),
('Tentacruel', 73, 'Agua', 'Kanto', 30, 'Tentacruel, uma Alforreca PokÃ©mon. Uma forma evoluÃ­da de Tentacool. Os seus numerosos tentÃ¡culos sÃ£o uma arma poderosa. Ã‰ tambÃ©m conhecido como â€œGangster do Marâ€.', 'Tentacruel.png'),
('Geodude', 74, 'Pedra', 'Kanto', 1, 'Geodude, o PokÃ©mon Rocha. O Geodude tem um poder defensivo incrÃ­vel, tornando-o virtualmente resistente a qualquer ataque fÃ­sico.', 'Geodude.png'),
('Graveler', 75, 'Pedra', 'Kanto', 25, 'Graveler cresce se alimentando de rochas. Aparentemente, ele prefere comer pedras que sÃ£o cobertas de musgo.', 'Graveler.png'),
('Golem', 76, 'Pedra', 'Kanto', 25, 'Golem, um PokÃ©mon de uma Mega Tonelada. Uma vez por ano parte a sua carapaÃ§a de pedra e cresce mais (evolui por meio de troca de pokÃ©mon).', 'Golem.png'),
('Ponyta', 77, 'Fogo', 'Kanto', 1, 'Ponyta, um Cavalo de Fogo PokÃ©mon. A sua crina Ã© constituÃ­da por chamas intensas.', 'Ponyta.png'),
('Rapidash', 78, 'Fogo', 'Kanto', 40, 'Rapidash geralmente pode ser visto casualmente galopando nos campos e planÃ­cies. No entanto, quando este PokÃ©mon fica sÃ©rio, a sua crina arde em chama e fogo, uma vez que galopa seu caminho em atÃ© 240 km/h.', 'Rapidash.png'),
('Slowpoke', 79, 'Agua', 'Kanto', 1, 'Slowpoke, o PokÃ©mon Palerma. NinguÃ©m sabe o que o Slowpoke pensa, se Ã© que pensa sequer. A sua especialidade Ã© pescar com a cauda.', 'Slowpoke.png'),
('Slowbro', 80, 'Agua', 'Kanto', 37, 'Slowbro, o PokÃ©mon Eremita Hibernado. O Slowbro tem fortes ataques psÃ­quicos mas geralmente prefere evitar conflitos.', 'Slowbro.png'),
('Magnemite', 81, 'ElÃ©trico', 'Kanto', 1, 'Magnemite, o PokÃ©mon MagnÃ©tico. Consegue flutuar pelo ar e emite ondas de trovÃ£o atravÃ©s das suas unidades em forma de Ã­man localizadas nos seus lados.', 'Magnemite.png'),
('Magneton', 82, 'ElÃ©trico', 'Kanto', 30, 'Magneton, o PokÃ©mon MagnÃ©tico. A forma evoluÃ­da do Magnemite. A sua forÃ§a anti gravitacional permite que ele flutue, e emita campos magnÃ©ticos e elÃ©tricos poderosos.', 'Magneton.png'),
('Farfetchâ€™d', 83, 'Normal', 'Kanto', 1, 'Farfetchâ€™d, um PokÃ©mon Pato Selvagem. DÃ¡ uma deliciosa refeiÃ§Ã£o, especialmente quando cozinhado com alho francÃªs. Por causa disto, estÃ¡ quase extinto.', 'Farfetchâ€™d.png'),
('Doduo', 84, 'Normal', 'Kanto', 1, 'Doduo, o PokÃ©mon Ave GÃ©meas. Quando as duas cabeÃ§as comeÃ§am a lutar, o Doduo fica incapacitado.', 'Doduo.png'),
('Dodrio', 85, 'Normal', 'Kanto', 31, 'Dodrio, uma Ave PokÃ©mon de TrÃªs CabeÃ§as que corre mais depressa do que voa. As suas trÃªs cabeÃ§as representam alegria, tristeza e fÃºria.', 'Dodrio.png'),
('Seel', 86, 'Agua', 'Kanto', 1, 'Seel caÃ§a presas no mar gelado sob camadas de gelo. Quando precisa respirar, ele perfura um buraco no gelo com a seÃ§Ã£o nitidamente saliente de sua cabeÃ§a.', 'Seel.png'),
('Dewgong', 87, 'Agua', 'Kanto', 34, 'Dewgong, o PokÃ©mon LeÃ£o-Marinho. A forma evoluÃ­da de Seel. Este pokÃ©mon de Ãgua e Gelo consegue resistir a temperaturas extremamente baixas.', 'Dewgong.png'),
('Grimer', 88, 'Venenoso', 'Kanto', 1, 'Grimer, um PokÃ©mon do Esgoto. Nascidos no esgoto, estes pokÃ©mon especializam-se em ataques de esgoto.', 'Grimer.png'),
('Muk', 89, 'Venenoso', 'Kanto', 38, 'Muk, a forma evoluÃ­da do Grimer. HÃ¡ que ter extremo cuidado pois a sua forma pegajosa contÃ©m veneno.', 'Muk.png'),
('Shellder', 90, 'Agua', 'Kanto', 1, 'Ã€ noite, este PokÃ©mon usa a sua lÃ­ngua ampla para cavar um buraco na areia do fundo marinho e depois dormir no buraco. Enquanto ele estÃ¡ dormindo, Shellder fecha sua concha, mas deixa a sua lÃ­ngua de fora.', 'Shellder.png'),
('Cloyster', 91, 'Agua', 'Kanto', 1, 'Cloyster, um PokÃ©mon Bivalve. A sua concha Ã© incrivelmente forte e resiste atÃ© a uma bomba. A sua concha sÃ³ abre quando ataca (evolui por meio da Water Stone).', 'Cloyster.png'),
('Gastly', 92, 'Fantasma', 'Kanto', 1, 'Gastly, um PokÃ©mon Fantasma. Normalmente Ã© invisÃ­vel. A sua especialidade Ã© a Hipnose.', 'Gastly.png'),
('Haunter', 93, 'Fantasma', 'Kanto', 25, 'Haunter, o PokÃ©mon Gasoso. Depois de evoluÃ­do, pode aprender o Comedor de Sonhos e ataques psÃ­quicos.', 'Haunter.png'),
('Gengar', 94, 'Fantasma', 'Kanto', 25, 'Gengar, o PokÃ©mon Sombra. O Gengar Ã© a fase final de evoluÃ§Ã£o do Gastly. Consegue absorver todo o calor que o rodeia, provocando um gelo sÃºbdito (evolui por meio da troca de pokÃ©mon).', 'Gengar.png'),
('Onix', 95, 'Pedra', 'Kanto', 1, 'Onix, o PokÃ©mon Cobra das Rochas. Circula pelo subsolo que estremece quando este emite o seu rugido estrondoso. Pode circular pelo subsolo a oitenta quilÃ³metros por hora.', 'Onix.png'),
('Drowzee', 96, 'Psiquico', 'Kanto', 1, 'Drowzee, supostamente Ã© descendente do comedor de sonhos tapir. Foi o primeiro PokÃ©mon a usar uma combinaÃ§Ã£o de ataques de Hipnose e Comedor de Sonhos.', 'Drowzee.png'),
('Hypno', 97, 'Psiquico', 'Kanto', 26, 'Hypno, um PokÃ©mon de Hipnose. Traz com ele um aparelho parecido com um pÃªndulo e executa ataques hipnÃ³ticos.', 'Hypno.png'),
('Krabby', 98, 'Agua', 'Kanto', 1, 'Krabby. Vive perto da terra. O seu tamanho normal Ã© cerca de 40 centÃ­metros.', 'Krabby.png'),
('Kingler', 99, 'Agua', 'Kanto', 28, 'Kingler, um PokÃ©mon com PinÃ§as. A forma evoluÃ­da do Krabby. As suas garras esmagadoras fazem dele um adversÃ¡rio poderoso.', 'Kingler.png'),
('Voltorb', 100, 'ElÃ©trico', 'Kanto', 1, 'Voltorb. A identidade desta criatura Ã© desconhecida. Tem uma personalidade extrema, usa ataques elÃ©ctricos, e por vezes auto-destrÃ³i-se.', 'Voltorb.png'),
('Electrode', 101, 'ElÃ©trico', 'Kanto', 30, 'Electrode, a forma evoluÃ­da do Voltorb. Energia elÃ©trica altamente concentrada provoca a explosÃ£o imprevisÃ­vel deste PokÃ©mon. TambÃ©m Ã© conhecido como a bola bomba.', 'Electrode.png'),
('Exeggcute', 102, 'Planta', 'Kanto', 1, 'Exeggcute, um PokÃ©mon Ovo. Apesar de ser parecido com um ovo, Ã© na realidade parente da semente de uma planta.', 'Exeggcute.png'),
('Exeggutor', 103, 'Planta', 'Kanto', 1, 'Exeggutor, um PokÃ©mon Coqueiro. TambÃ©m conhecido como a floresta tropical andante. Cada coco tem uma cara diferente e o seu prÃ³prio carÃ¡ter. O seu ataque especial Ã© a Hipnose (evolui por meio da Leaf Stone).', 'Exeggutor.png'),
('Cubone', 104, 'Terrestre', 'Kanto', 1, 'Cubone, um PokÃ©mon terrestre. O Cubone ganhou a alcunha de PokÃ©mon SolitÃ¡rio, porque normalmente se preocupa apenas com ele prÃ³prio.', 'Cubone.png'),
('Marowak', 105, 'Terrestre', 'Kanto', 28, 'Marowak, o PokÃ©mon GuardiÃ£o do Osso. Apesar do seu reduzido tamanho, a sua forÃ§a de ataque e defesa sÃ£o impressionantes.', 'Marowak.png'),
('Hitmonlee', 106, 'Lutador', 'Kanto', 1, 'Hitmonlee, o PokÃ©mon PontapÃ©. O Hitmonlee consegue estender e retrair as patas para pontear o adversÃ¡rio de qualquer distÃ¢ncia.', 'Hitmonlee.png'),
('Hitmonchan', 107, 'Lutador', 'Kanto', 1, 'Hitmonchan, o PokÃ©mon Soco. O Hitmonchan Ã© especialista em ataques de soco. Move-se ainda mais rÃ¡pido que o olhar.', 'Hitmonchan.png'),
('Lickitung', 108, 'Normal', 'Kanto', 1, 'Lickitung, um PokÃ©mon Lambedor. Usa a sua lÃ­ngua que tem mais do dobro do comprimento do seu corpo para lutar, e para recolher alimentos.', 'Lickitung.png'),
('Koffing', 109, 'Venenoso', 'Kanto', 1, 'Koffing, o PokÃ©mon gÃ¡s venenoso. Koffing paira no ar, graÃ§as aos gases venenosos que ele contÃ©m, que tÃªm um odor fÃ©tido e podem explodir.', 'Koffing.png'),
('Weezing', 110, 'Venenoso', 'Kanto', 35, 'Weezing ama os gases emitidos pelo lixo podre da cozinha. Este PokÃ©mon vai encontrar uma casa suja e descuidada e tornar como sua. Ã€ noite, quando as pessoas da casa estÃ£o dormindo, ele vai passar pelo lixo.', 'Weezing.png'),
('Rhyhorn', 111, 'Terrestre', 'Kanto', 1, 'Rhyhorn, o PokÃ©mon com Picos. Ã‰ conhecido pela sua forÃ§a fÃ­sica e as suas considerÃ¡veis capacidades de batalha ofensivas e defensivas.', 'Rhyhorn.png'),
('Rhydon', 112, 'Terrestre', 'Kanto', 42, 'Rhydon, a forma evoluÃ­da do Rhyhorn. Ã‰ conhecido como um PokÃ©mon Broca. O seu grande chifre dÃ¡-lhe um poder de ataque formidÃ¡vel.', 'Rhydon.png'),
('Chansey', 113, 'Normal', 'Kanto', 1, 'Chansey, o PokÃ©mon Ovo. A Chansey Ã© o tipo de pokÃ©mon que partilha o seu ovo com quem estÃ¡ doente ou ferido.', 'Chansey.png'),
('Tangela', 114, 'Planta', 'Kanto', 1, 'Tangela, um PokÃ©mon de Heras. O seu corpo estÃ¡ coberto de heras. O resto da sua forma estÃ¡ escondido sob estas heras.', 'Tangela.png'),
('Kangaskhan', 115, 'Normal', 'Kanto', 1, 'Kangaskhan, um PokÃ©mon Progenitor. Outrora quase extinto, agora Ã© protegido pelo Estado e vive na Zona Safari. Aproximar-se com muito cuidado. O Kangaskhan Ã© um pokÃ©mon raro que cria os filhos na bolsa. Ataca ferozmente e sem aviso se pressentir que as crias estÃ£o a ser ameaÃ§adas.', 'Kangaskhan.png'),
('Horsea', 116, 'Agua', 'Kanto', 1, 'Horsea, um DragÃ£o PokÃ©mon. Esta espÃ©cie de pokÃ©mon Ã© Ãºnica, choca mil ovos a cada primavera, e o macho cria-os sozinho.', 'Horsea.png'),
('Seadra', 117, 'Agua', 'Kanto', 32, 'Seadra, o PokÃ©mon DragÃ£o. A forma evoluÃ­da do Horsea. Seadra tem um temperamento violento, e as cerdas que cobrem o seu corpo podem pÃ´r a sua vÃ­tima inconsciente.', 'Seadra.png'),
('Goldeen', 118, 'Agua', 'Kanto', 1, 'Goldeen Ã© um PokÃ©mon muito bonito com barbatanas que ondulam com elegÃ¢ncia na Ã¡gua. No entanto, nÃ£o deve-se baixar a guarda em torno deste PokÃ©mon - que poderia bater poderosamente com seu chifre.', 'Goldeen.png'),
('Seaking', 119, 'Agua', 'Kanto', 33, 'Seaking, o PokÃ©mon Dourado. O Seaking Ã© a forma evoluÃ­da do Goldeen. O seu chifre afiado em forma de broca tem a capacidade de esmagar pedras.', 'Seaking.png'),
('Staryu', 120, 'Agua', 'Kanto', 1, 'Staryu. O centro deste PokÃ©mon de Ã¡gua possui um arco-Ã­ris de sete cores, centro este que Ã© classificado por alguns como uma jÃ³ia.', 'Staryu.png'),
('Starmie', 121, 'Agua', 'Kanto', 1, 'A seÃ§Ã£o central da Starmie - o nÃºcleo - brilha intensamente em sete cores. Devido Ã  sua natureza luminosa, este PokÃ©mon foi dado o apelido de "a jÃ³ia do mar" (evolui por meio da Water Stone).', 'Starmie.png'),
('Mr. Mime', 122, 'Psiquico', 'Kanto', 1, 'Mr. Mime, o PokÃ©mon Barreira. Movendo rapidamente os dedos, o Mr. Mime consegue usar as molÃ©culas do ar para criar um escudo invisÃ­vel.', 'Mr. Mime.png'),
('Scyther', 123, 'Inseto', 'Kanto', 1, 'Scyther, o PokÃ©mon Louva-a-Deus. As suas garras sÃ£o afiadas como espadas, e Ã© um voador poderoso. Este pokÃ©mon raramente Ã© visto pelos homens e quase nunca Ã© capturado.', 'Scyther.png'),
('Jynx', 124, 'Gelo', 'Kanto', 1, 'Jynx, o PokÃ©mon Forma Humana. A Jynx Ã© famosa por expressar as suas diferentes emoÃ§Ãµes danÃ§ando em movimentos circulares e graciosos.', 'Jynx.png'),
('Electabuzz', 125, 'ElÃ©trico', 'Kanto', 1, 'Electabuzz, o PokÃ©mon ElÃ©trico. Aparece junto a postes de alta tensÃ£o, e como se alimenta de eletricidade pode causar apagÃµes.', 'Electabuzz.png'),
('Magmar', 126, 'Fogo', 'Kanto', 1, 'Magmar, o PokÃ©mon que Cospe Fogo. O seu corpo Ã© como uma fornalha, que faz dele um inferno vivo. SÃ³ existe ao pÃ© de vulcÃµes ativos.', 'Magmar.png'),
('Pinsir', 127, 'Inseto', 'Kanto', 1, 'Pinsir. Este temÃ­vel pokÃ©mon usa as suas poderosas pinÃ§as para imobilizar os adversÃ¡rios.', 'Pinsir.png'),
('Tauros', 128, 'Normal', 'Kanto', 1, 'Tauros, um PokÃ©mon Selvagem. A chicotada das suas trÃªs caudas Ã© possuidora de uma forÃ§a destrutiva.', 'Tauros.png'),
('Magikarp', 129, 'Agua', 'Kanto', 1, 'Magikarp, o PokÃ©mon Peixe. O Magikarp consegue viver nas Ã¡guas mais turvas. Salta muito e pode evoluir para um Gyarados.', 'Magikarp.png'),
('Gyarados', 130, 'Agua', 'Kanto', 20, 'Gyarados. Este PokÃ©mon tem um temperamento violento, hÃ¡ que ter extremo cuidado. As suas presas podem esmagar pedras e as escamas sÃ£o mais duras do que aÃ§o.', 'Gyarados.png'),
('Lapras', 131, 'Agua', 'Kanto', 1, 'Lapras. Este PokÃ©mon intelectualmente avanÃ§ado percebe a linguagem humana. Com o seu temperamento calmo, a Lapras prefere carregar humanos Ã s costas, em vez de entrar em batalhas pokÃ©mon.', 'Lapras.png'),
('Ditto', 132, 'Normal', 'Kanto', 1, 'Ditto, um PokÃ©mon de TransformaÃ§Ã£o. Consegue reorganizar as cÃ©lulas do seu corpo e assumir qualquer forma. O seu Ãºnico ataque Ã© a TransformaÃ§Ã£o.', 'Ditto.png'),
('Eevee', 133, 'Normal', 'Kanto', 1, 'Eevee, o PokÃ©mon da EvoluÃ§Ã£o. Tem potencial para evoluir para qualquer um dos trÃªs pokÃ©mon diferentes.', 'Eevee.png'),
('Vaporeon', 134, 'Agua', 'Kanto', 1, 'Vaporeon, o PokÃ©mon Jacto de Bolhas, a forma evoluÃ­da de Eevee. A composiÃ§Ã£o das suas cÃ©lulas Ã© semelhante Ã s molÃ©culas de Ã¡gua, e por isso consegue dissolver-se nela (evolui por meio da Water Stone).', 'Vaporeon.png'),
('Jolteon', 135, 'ElÃ©trico', 'Kanto', 1, 'Jolteon, o PokÃ©mon RelÃ¢mpago. Quando zangado ou assustado, os pÃªlos do seu corpo tornam-se agulhas que sÃ£o disparadas contra os seus adversÃ¡rios. Absorve Ã¡tomos carregados e consegue produzir 10.000 volts de eletricidade (evolui por meio da Thunder Stone).', 'Jolteon.png'),
('Flareon', 136, 'Fogo', 'Kanto', 1, 'Flareon, o PokÃ©mon Chama. O Flareon Ã© a forma evoluÃ­da do Eevee. O ar que inala entra em igniÃ§Ã£o atravÃ©s de uma chama e Ã© expelido em fogo (evolui por meio da Fire Stone).', 'Flareon.png'),
('Porygon', 137, 'Normal', 'Kanto', 1, 'Porygon Ã© capaz de reverter-se inteiramente de volta para os dados do programa e entrando no ciberespaÃ§o. Este PokÃ©mon estÃ¡ protegido contra cÃ³pia por isso nÃ£o pode ser repetido por cÃ³pia.', 'Porygon.png'),
('Omanyte', 138, 'Pedra', 'Kanto', 1, 'Omanyte, o PokÃ©mon Espiral. CrÃª-se que tenha vivido hÃ¡ dois milhÃµes de anos atrÃ¡s. Pesquisas recentes indicam que ele controlava a sua capacidade de flutuar ao guardar e largar ar na concha.', 'Omanyte.png'),
('Omastar', 139, 'Pedra', 'Kanto', 40, 'Omastar, a forma evoluÃ­da do Omanyte. CrÃª-se que este PokÃ©mon extinto tenha usado as suas presas afiadas para se alimentar de conchas.', 'Omastar.png'),
('Kabuto', 140, 'Pedra', 'Kanto', 1, 'Kabuto, o Antigo PokÃ©mon. Acredita-se que este PokÃ©mon estÃ¡ extinto, mas tinha uma concha dura que lhe protegia o corpo e parece que era um vigoroso nadador.', 'Kabuto.png'),
('Kabutops', 141, 'Pedra', 'Kanto', 40, 'Kabutops nadou debaixo d''Ã¡gua para caÃ§ar sua presa nos tempos antigos. O PokÃ©mon aparentemente foi evoluindo ao passar de um morador-aquÃ¡tico para morador-terrestre, como Ã© evidente desde o inÃ­cio da mudanÃ§a em suas guelras e pernas.', 'Kabutops.png'),
('Aerodactyl', 142, 'Pedra', 'Kanto', 1, 'Aerodactyl, o PokÃ©mon voador extinto. As suas fortes presas sugerem que era carnÃ­voro. As suas garras afiadas deviam ser usadas para capturar presas.', 'Aerodactyl.png'),
('Snorlax', 143, 'Normal', 'Kanto', 1, 'Snorlax, um PokÃ©mon Dorminhoco. O Snorlax sÃ³ acorda para comer.', 'Snorlax.png'),
('Articuno', 144, 'Gelo', 'Kanto', 50, 'Articuno, o PokÃ©mon Gelo. O Articuno vive em zonas montanhosas, e diz-se que tem a capacidade de voar ao abanar graciosamente a sua cauda.', 'Articuno.png'),
('Zapdos', 145, 'ElÃ©trico', 'Kanto', 50, 'Zapdos, o PokÃ©mon ElÃ©trico. O Zapdos Ã© um pokÃ©mon do tipo ElÃ©trico e Voador, e pode criar relÃ¢mpagos.', 'Zapdos.png'),
('Moltres', 146, 'Fogo', 'Kanto', 50, 'Moltres, o famoso lendÃ¡rio PokÃ©mon Chama. TÃ£o poderoso, que atÃ© as cinzas poderiam levar calor a terras Ãºmidas.', 'Moltres.png'),
('Dratini', 147, 'DragÃ£o', 'Kanto', 1, 'Dratini, o PokÃ©mon DragÃ£o. HÃ¡ medida que vai crescendo o Dratini muda a sua pele, fazendo-o muitas vezes atrÃ¡s das cascatas.', 'Dratini.png'),
('Dragonair', 148, 'DragÃ£o', 'Kanto', 30, 'Dragonair, um PokÃ©mon DragÃ£o. Um PokÃ©mon lendÃ¡rio que faz chover ou nevar conforme a sua vontade. Embora nÃ£o tenha asas, consegue voar.', 'Dragonair.png'),
('Dragonite', 149, 'DragÃ£o', 'Kanto', 55, 'Dragonite, o PokÃ©mon DragÃ£o. Esta criatura extremamente rara e altamente inteligente consegue voar mais rÃ¡pido que qualquer PokÃ©mon conhecido.', 'Dragonite.png'),
('Mewtwo', 150, 'Psiquico', 'Kanto', 70, 'Mewtwo Ã© um PokÃ©mon que foi criado por manipulaÃ§Ã£o genÃ©tica. No entanto, apesar de o poder cientÃ­fico dos humanos criar o corpo deste PokÃ©mon, eles nÃ£o conseguiram dotar Mewtwo com um coraÃ§Ã£o compassivo.', 'Mewtwo.png'),
('Mew', 151, 'Psiquico', 'Kanto', 1, 'Mew Ã© dito possuir a composiÃ§Ã£o genÃ©tica de todos os PokÃ©mon. Ele Ã© capaz de tornar-se invisÃ­vel Ã  vontade, de modo que evita inteiramente ser avistado, mesmo se ele se aproximar pessoas.', 'Mew.png'),
('Chikorita', 152, 'Planta', 'Johto', 1, 'Chikorita, o PokÃ©mon folha. Suas folhas tem um aroma agradÃ¡vel e permitem com que ele verifique a humidade e temperatura locais.', 'Chikorita.png'),
('Bayleef', 153, 'Planta', 'Johto', 16, 'Bayleef, o PokÃ©mon folha, e a forma evoluÃ­da de Chikorita. As folhas em volta de seu pescoÃ§o liberam um aroma que funciona como um estimulante para quem quer que o cheire. ', 'Bayleef.png'),
('Meganium', 154, 'Planta', 'Johto', 32, 'Meganium, o PokÃ©mon erva, e a forma evoluÃ­da de Bayleef. Ele Ã© capaz de reviver plantas e gramas mortas apenas com seu cheiro.', 'Meganium.png'),
('Cyndaquil', 155, 'Fogo', 'Johto', 1, 'Cyndaquil, o PokÃ©mon de fogo. Normalmente calmo e equilibrado, ele dispara chamas das costas ao ser surpreendido ou irritado.', 'Cyndaquil.png'),
('Quilava', 156, 'Fogo', 'Johto', 14, 'Quilava, o PokÃ©mon vulcÃ£o, e a forma evoluÃ­da de Cyndaquil. Esse PokÃ©mon Ã© totalmente coberto por uma pele nÃ£o inflamÃ¡vel, e pode resistir a qualquer tipo de ataque de fogo.', 'Quilava.png'),
('Typhlosion', 157, 'Fogo', 'Johto', 36, 'Typhlosion, o PokÃ©mon vulcÃ£o, e a forma evoluÃ­da de Quilava. Se ele chegar ao pico de sua raiva, seu corpo fica tÃ£o quente que qualquer coisa em que encostar instantaneamente ficarÃ¡ em chamas.', 'Typhlosion.png'),
('Totodile', 158, 'Agua', 'Johto', 1, 'Totodile pode ser pequeno, mas Ã© bastante perigos - sua mandÃ­bula bem desenvolvida Ã© capaz de esmagar qualquer coisa.', 'Totodile.png'),
('Croconaw', 159, 'Agua', 'Johto', 18, 'Croconaw, a forma evoluÃ­da de Totodile. Caso ele perca uma presa, outra nova cresce no lugar. JÃ¡ existem 48 presas na sua boca.', 'Croconaw.png'),
('Feraligatr', 160, 'Agua', 'Johto', 30, 'Feraligatr, a forma evoluÃ­da de Croconaw. Quando esse PokÃ©mon segura seu oponente com suas presas, ele nÃ£o solta atÃ© que o adversÃ¡rio desmaie.', 'Feraligatr.png'),
('Sentret', 161, 'Normal', 'Johto', 1, 'Sentret, o PokÃ©mon sentinela. Ele se apoia em sua cauda para poder enxergar longe. Quando avista um inimigo, ele grita ruidosamente para alertar sua espÃ©cie.', 'Sentret.png'),
('Furret', 162, 'Normal', 'Johto', 15, 'Furret, a forma evoluÃ­da de Sentret. Ele faz um ninho que agrade seu longo e peludo corpo. Apesar de suas pernas serem pequenas, ele Ã© bastante rÃ¡pido para caÃ§ar.', 'Furret.png'),
('Hoothoot', 163, 'Voador', 'Johto', 1, 'Hoothoot, o PokÃ©mon coruja. Ele tem uma perfeita percepÃ§Ã£o de tempo. O que quer que aconteÃ§a, ele mantÃ©m o compasso balanÃ§ando sua cabeÃ§a. ', 'Hoothoot.png'),
('Noctowl', 164, 'Voador', 'Johto', 20, 'Noctowl, a forma evoluÃ­da de Hoothoot. Seus olhos sÃ£o especialmente adaptados para permitir sua visÃ£o no ambiente mais escuro que existir.', 'Noctowl.png'),
('Ledyba', 165, 'Inseto', 'Johto', 1, 'Ledyba, o PokÃ©mon joaninha. Ã‰ bastante tÃ­mido, e tem medo de se locomover sozinho. Prefere mover-se se estiver em grupo.', 'Ledyba.png'),
('Ledian', 166, 'Inseto', 'Johto', 18, 'Ledian, a forma evoluÃ­da de Ledyba. Os padrÃµes de estrela nas suas costas crescem ou diminuem, dependendo do nÃºmero de estrelas presentes no cÃ©u durante a noite.', 'Ledian.png'),
('Spinarak', 167, 'Inseto', 'Johto', 1, 'Spinarak, o PokÃ©mon aranha. Ele permanece imÃ³vel por dias em sua teia, esperando uma presa distraÃ­da se aproximar.', 'Spinarak.png'),
('Ariados', 168, 'Inseto', 'Johto', 22, 'Ariados, a forma evoluÃ­da de Spinarak. Ariados Ã© capaz de girar teias extremamente longas e grudentas para aprisionar seus adversÃ¡rios.', 'Ariados.png'),
('Crobat', 169, 'Venenoso', 'Johto', 22, 'Crobat, o PokÃ©mon morcego. Ele voa tÃ£o silenciosamente na escuridÃ£o com suas quatro asas que, algumas vezes, ele passa despercebido, mesmo estando prÃ³ximo.', 'Crobat.png'),
('Chinchou', 170, 'Agua', 'Kanto', 1, 'Chinchou, o PokÃ©mon tamboril. Na escuridÃ£o do fundo do oceano, sua Ãºnica forma de comunicaÃ§Ã£o Ã© pelo constante lampejo de suas antenas.', 'Chinchou.png'),
('Lanturn', 171, 'Agua', 'Johto', 27, 'Lanturn, a forma evoluÃ­da de Chinchou. A luz que ele emite Ã© tÃ£o clara que pode iluminar a superfÃ­cie do mar de uma profundidade de atÃ© 4,8 Km.', 'Lanturn.png'),
('Pichu', 172, 'ElÃ©trico', 'Johto', 1, 'Pichu, o PokÃ©mon rato. Ele nÃ£o Ã© habilidoso em armazenar eletricidade, e pode soltar um pouco dela se sentir-se assustado ou divertido.', 'Pichu.png'),
('Cleffa', 173, 'Normal', 'Johto', 1, 'Por causa de sua silhueta de estrela incomum, pesquisadores acreditam que ele veio em um meteoro. ', 'Cleffa.png'),
('Igglybuff', 174, 'Normal', 'Johto', 1, 'Igglybuff, o PokÃ©mon balÃ£o. Seu corpo extremamente elÃ¡stico e mole faz ele saltar constantemente - a qualquer hora, em qualquer lugar.', 'Igglybuff.png'),
('Togepi', 175, 'Normal', 'Johto', 1, 'Seu casco parece estar cheio de alegria. Ã‰ dito que o Togepi Ã© capaz de compartilhar boa sorte quando Ã© tratado com carinho.', 'Togepi.png'),
('Togetic', 176, 'Voador', 'Johto', 1, 'Togetic, a forma evoluÃ­da de Togepi. Dizem que ele aparece para pessoas bondosas, fazendo a felicidade chover sobre elas.', 'Togetic.png'),
('Natu', 177, 'Psiquico', 'Johto', 1, 'Como suas asas ainda nÃ£o cresceram completamente, ele tem de pular para se mover. Natu estÃ¡ sempre olhando fixamente para alguma coisa.', 'Natu.png'),
('Xatu', 178, 'Psiquico', 'Johto', 25, 'Xatu, a forma evoluÃ­da de Natu. Na amÃ©rica do Sul, Ã© dito que seu olho direito vÃª o futuro e o seu esquerdo vÃª o passado; por isso ele permanece parado e silencioso.', 'Xatu.png'),
('Mareep', 179, 'ElÃ©trico', 'Johto', 1, 'Se eletricidade estÃ¡tica crescer em seu corpo, sua lÃ£ dobra em volume. No verÃ£o, essa lÃ£ Ã© completamente tosada, mas em uma semana ela cresce novamente em seu volume original.', 'Mareep.png'),
('Flaffy', 180, 'ElÃ©trico', 'Johto', 15, 'Flaffy, a forma evoluÃ­da de Mareep. Sua fofa lÃ£ facilmente armazena eletricidade, e sua pele enrubescida o protege de se autoeletrocutar.', 'Flaffy.png'),
('Ampharos', 181, 'ElÃ©trico', 'Johto', 30, 'Ampharos, a forma evoluÃ­da de Flaffy. A clara luz de sua cauda pode ser vista de muito longe, e desde tempos antigos, ele foi usado como um farol.', 'Ampharos.png'),
('Bellossom', 182, 'Planta', 'Kanto', 21, 'Bellossom gosta de danÃ§ar e, quando o faz, suas pÃ©talas se esfregam e produzem um som agradÃ¡vel. Ã‰ dito que a danÃ§a Ã© um ritual para invocar o sol.', 'Bellossom.png'),
('Marill', 183, 'Agua', 'Johto', 1, 'Marill, a forma evoluÃ­da de Azurill. A ponta de sua cauda serve como uma boia que impede que ele se afogue, atÃ© mesmo em uma forte correnteza.', 'Marill.png'),
('Azumarill', 184, 'Agua', 'Johto', 18, 'Azumarill, a forma evoluÃ­da de Marill. Ao se manter imÃ³vel e ouvindo atentamente, ele consegue saber o que estÃ¡ em rios, atÃ© os com forte correnteza.', 'Azumarill.png'),
('Sudowoodo', 185, 'Pedra', 'Johto', 1, 'Sudowoodo se finge de Ã¡rvore para evitar confrontos, porÃ©m sua composiÃ§Ã£o celular Ã© mais prÃ³xima de uma pedra do que de uma planta.', 'Sudowoodo.png'),
('Politoed', 186, 'Agua', 'Johto', 25, 'Politoed, a forma evoluÃ­da de Poliwhirl. Se trÃªs ou mais desses se reÃºnem, eles cantam em uma voz muito alta, que soa como um berro.', 'Politoed.png'),
('Hoppip', 187, 'Planta', 'Johto', 1, 'Hoppip, o PokÃ©mon de algodÃ£o. Seu corpo Ã© tÃ£o leve que ele deve se agarrar firmemente com seus pÃ©s para evitar ser levado pelo vento.', 'Hoppip.png'),
('Skiploom', 188, 'Planta', 'Johto', 18, 'Skiploom, a forma evoluÃ­da de Hoppip. A flor no topo de sua cabeÃ§a abre e fecha quando a temperatura esquenta ou esfria, respectivamente.', 'Skiploom.png'),
('Jumpluff', 189, 'Planta', 'Johto', 27, 'Jumpluff, a forma evoluÃ­da de Skiploom. Ele vaga por ventos sazonais e espalha seus esporos tipo algodÃ£o por todo o mundo, para aumentar a prole.', 'Jumpluff.png'),
('Aipom', 190, 'Normal', 'Johto', 1, 'Ele vive no topo de Ã¡rvores muito altas. Ao pular de galho em galho, Aipom habilmente usa sua cauda para manter-se equilibrado.', 'Aipom.png'),
('Sunkern', 191, 'Planta', 'Johto', 1, 'Ele se alimenta somente do orvalho debaixo das folhas das plantas. Quando atacado, Sunkern sacode suas folhas violentamente.', 'Sunkern.png'),
('Sunflora', 192, 'Planta', 'Johto', 1, 'Sunflora, a forma evoluÃ­da de Sunkern. Ele converte a luz do sol em energia para si. Depois do pÃ´r-do-sol, Sunflora fecha suas pÃ©talas e fica imÃ³vel.', 'Sunflora.png'),
('Yanma', 193, 'Inseto', 'Johto', 1, 'Yanma, o PokÃ©mon libÃ©lula. Seus grandes olhos podem examinar atÃ© 360 graus, procurando um inseto como presa.', 'Yanma.png'),
('Wooper', 194, 'Agua', 'Johto', 1, 'Esse PokÃ©mon vive em Ã¡guas frias. Quando estÃ¡ em terra firme, ele envolve seu corpo com uma pegajosa e venenosa membrana.', 'Wooper.png'),
('Quagsire', 195, 'Agua', 'Johto', 20, 'Quagsire, a forma evoluÃ­da de Wooper. Devido a sua atitude relaxada e despreocupada, ele frequentemente colide sua cabeÃ§a em pedras e em cascos de barcos enquanto nada.', 'Quagsire.png'),
('Espeon', 196, 'Psiquico', 'Johto', 1, 'Espeon, a forma evoluÃ­da de Eevee. Ele usa seu pÃªlo para ler correntes de ar e prever a temperatura ou o ataque de um oponente.', 'Espeon.png'),
('Umbreon', 197, 'Noturno', 'Johto', 1, 'Umbreon, a forma evoluÃ­da de Eevee. Quando a noite cai, os anÃ©is no corpo dele comeÃ§am a brilhar. Ao se sentir ameaÃ§ado, Umbreon se protege liberando um suor venenoso de seus poros.', 'Umbreon.png'),
('Murkrow', 198, 'Noturno', 'Johto', 1, 'Temido e odiado por muitos, acredita-se que mÃ¡ sorte cairÃ¡ sobre aqueles que o verem a noite. ', 'Murkrow.png'),
('Slowking', 199, 'Agua', 'Johto', 1, 'Slowking, a forma evoluÃ­da de Slowpoke. Possui um incrÃ­vel intelecto e intuiÃ§Ã£o. NÃ£o importa qual a situaÃ§Ã£o, ele permanece calmo.', 'Slowking.png'),
('Misdreavus', 200, 'Fantasma', 'Johto', 1, 'Misdreavus gosta de pregar peÃ§as, como guinchar e chorar para assustar as pessoas Ã  noite.', 'Misdreavus.png'),
('Unown', 201, 'Psiquico', 'Johto', 1, 'Sua forma se assemelha com hierÃ³glifos de antigas escrituras, e ele sempre estÃ¡ encostado nas paredes. Ã‰ dito que sua relaÃ§Ã£o com essa escrita tem algum significado misterioso.', 'Unown.png'),
('Wobbuffet', 202, 'Psiquico', 'Johto', 15, 'Wobbuffet, a forma evoluÃ­da de Wynaut. Ele odeia a luz, e vive silenciosamente na escuridÃ£o. Wobbuffet jamais ataca primeiro.', 'Wobbuffet.png'),
('Girafarig', 203, 'Psiquico', 'Johto', 1, 'Sua cauda, que contÃ©m um pequeno cÃ©rebro, pode morder por si prÃ³pria ao sentir um cheiro diferente.', 'Girafarig.png'),
('Pineco', 204, 'Inseto', 'Johto', 1, 'Ele gosta de engrossar seu casco adicionando camadas de casca das Ã¡rvores. Fica imÃ³vel, a espera de um inseto se aproximar.', 'Pineco.png'),
('Forretress', 205, 'Inseto', 'Johto', 31, 'Forretress, a forma evoluÃ­da de Pineco. Seu corpo inteiro Ã© protegido por um casco feito de um tipo muito duro de aÃ§o. O que hÃ¡ dentro da armadura Ã© um mistÃ©rio total.', 'Forretress.png'),
('Dunsparce', 206, 'Normal', 'Johto', 1, 'Dunsparce, o PokÃ©mon cobra. Quando visto, ele foge escavando com sua cauda. Ele pode flutuar por um curto perÃ­odo de tempo, com suas asas.', 'Dunsparce.png'),
('Gligar', 207, 'Terrestre', 'Kanto', 1, 'Gligar, o PokÃ©mon escorpiÃ£o voador. Ele geralmente mantÃ©m-se em penhascos. Ao ver sua presa, abre suas asas e plana em sua direÃ§Ã£o.', 'Gligar.png'),
('Steelix', 208, 'Terrestre', 'Johto', 1, 'Steelix, a forma evoluÃ­da de Onix. Seu corpo foi comprimido no fundo da terra. Como resultado, seu corpo Ã© mais duro que um diamante.', 'Steelix.png'),
('Snubbull', 209, 'Normal', 'Johto', 1, 'Snubbull pode parecer assustador, mas na verdade Ã© gentil e carinhoso. Ã‰ bastante popular entre mulheres.', 'Snubbull.png'),
('Granbull', 210, 'Normal', 'Johto', 23, 'Granbull, a forma evoluÃ­da de Snubbull. Ã‰ bastante tÃ­mido. Como suas presas sÃ£o muito pesadas, sua cabeÃ§a sempre fica abaixada. PorÃ©m, sua mordida Ã© muito forte.', 'Granbull.png'),
('Qwilfish', 211, 'Venenoso', 'Johto', 1, 'Os espinhos que cobrem seu corpo se desenvolverem de escamas. Eles injetam uma toxina que gera desmaios.', 'Qwilfish.png'),
('Scizor', 212, 'Inseto', 'Johto', 1, 'Scizor, a forma evoluÃ­da de Scyther. Suas asas nÃ£o foram feitas para voar - elas batem em alta velocidade para neutralizar a temperatura corporal dele.', 'Scizor.png'),
('Shuckle', 213, 'Pedra', 'Johto', 1, 'Ele guarda Berries dentro de seu casco. Para evitar ataques, ele se esconde entre as pedras e permanece completamente imÃ³vel.', 'Shuckle.png'),
('Heracross', 214, 'Lutador', 'Johto', 1, 'Heracross, o PokÃ©mon besouro. Geralmente dÃ³cil, quando perturbado, persegue seu oponente com seu chifre.', 'Heracross.png'),
('Sneasel', 215, 'Gelo', 'Kanto', 1, 'Naturalmente agressivo, suas patas escondem garras afiadas, que ele usa para assustar alguÃ©m que tente atacÃ¡-lo.', 'Sneasel.png'),
('Teddiursa', 216, 'Normal', 'Johto', 1, 'Teddiursa, o PokÃ©mon urso. Ele sempre estÃ¡ lambendo suas patas porque elas estÃ£o cheias de mel. Antes do inverno, Teddiursa armazena comida em muitos esconderijos.', 'Teddiursa.png'),
('Ursaring', 217, 'Normal', 'Johto', 30, 'Ursaring, a forma evoluÃ­da de Teddiursa. GraÃ§as a sua habilidade de distinguir qualquer aroma, ele sempre encontra qualquer comida escondida no chÃ£o.', 'Ursaring.png'),
('Slugma', 218, 'Fogo', 'Johto', 1, 'Slugma, o PokÃ©mon de lava. Ele Ã© tipicamente encontrado em Ã¡reas vulcÃ¢nicas, onde lentamente se arrasta em busca de lugares quentes.', 'Slugma.png'),
('Magcargo', 219, 'Fogo', 'Johto', 38, 'Magcargo, a forma evoluÃ­da de Slugma. O casco em suas costas Ã© sua pele, que resfriou e endureceu. Ocasionalmente o casco esguicha chamas que circulam pelo corpo de Magcargo.', 'Magcargo.png'),
('Swinub', 220, 'Gelo', 'Johto', 1, 'Swinub, o PokÃ©mon porco. Ele esfrega o focinho no chÃ£o, a procura de comida. Se ele cheira alguma comida, rapidamente corre em direÃ§Ã£o Ã  origem do odor.', 'Swinub.png'),
('Piloswine', 221, 'Gelo', 'Johto', 33, 'Piloswine, a forma evoluÃ­da de Swinub. Devido Ã  espessa camada de pÃªlos que obstruem sua visÃ£o, ele Ã© muito sensÃ­vel ao som.', 'Piloswine.png'),
('Corsola', 222, 'Pedra', 'Johto', 1, 'Corsola, o PokÃ©mon coral. Em uma naÃ§Ã£o no mar do sul, as pessoas vivem em comunidades construÃ­das sobre eles. Corsola cresce constantemente. ', 'Corsola.png'),
('Remoraid', 223, 'Agua', 'Johto', 1, 'Tem uma precisÃ£o incrÃ­vel. A Ã¡gua que ele atira pode atingir uma presa em movimento a 91 metros. Usando sua barbatana dorsal como um amortecedor, ele se segura na parte de baixo de um Mantine, procurando sobras de comida.', 'Remoraid.png'),
('Octillery', 224, 'Agua', 'Johto', 25, 'Octillery, a forma evoluÃ­da de Remoraid. Instintivamente penetra em buracos rochosos. Frequentemente rouba os ninhos de outros para dormir.', 'Octillery.png'),
('Delibird', 225, 'Gelo', 'Johto', 1, 'Delibird, o PokÃ©mon de entregas. Ele carrega comida o dia todo em sua sacola. Existem histÃ³rias de desaparecidos que foram salvos pela comida que ele tinha.', 'Delibird.png'),
('Mantine', 226, 'Voador', 'Johto', 1, 'Mantine, o PokÃ©mon pipa. Nadando livremente no mar aberto, ocasionalmente ele voa fora da Ã¡gua e sobre as ondas caso ele acumule velocidade suficiente.', 'Mantine.png'),
('Skarmory', 227, 'Voador', 'Johto', 1, 'Suas robustas asas podem parecer pesadas, mas na verdade elas sÃ£o ocas e leves, permitindo com que ele voe livremente no cÃ©u.', 'Skarmory.png'),
('Houndour', 228, 'Noturno', 'Johto', 1, 'Houndoum, o PokÃ©mon, sombrio. Para encurralar uma presa, eles emitem latidos diferentes, que somente eles podem entender.', 'Houndour.png'),
('Houndoom', 229, 'Noturno', 'Johto', 24, 'Houndoom, a forma evoluÃ­da de Houndour. Ao ouvirem seus uivos, outros PokÃ©mon tremem e se escondem em seus ninhos. Caso alguÃ©m seja queimado pela chama que ele solta pela boca, a dor nunca mais passarÃ¡.', 'Houndoom.png'),
('Phanpy', 231, 'Terrestre', 'Johto', 1, 'Phanpy, o PokÃ©mon elefante. Phanpy balance seu focinho em sinal de carinho, mas como ele Ã© muito forte, pode ser perigoso.', 'Phanpy.png'),
('Donphan', 232, 'Terrestre', 'Johto', 25, 'Donphan, a forma evoluÃ­da de Phanpy. Tem uma presa afiada e uma pele Ã¡spera. Um ataque seu Ã© forte o suficiente para derrubar uma casa.', 'Donphan.png'),
('Porygon2', 233, 'Normal', 'Johto', 1, 'Porygon2, a forma evoluÃ­da de Porygon. Essa atualizaÃ§Ã£o de Porygon foi designada para exploraÃ§Ã£o no espaÃ§o. Algumas vezes, pode exibir comportamentos que nÃ£o foram programados. Ele nÃ£o pode voar, todavia.', 'Porygon2.png'),
('Stantler', 234, 'Normal', 'Johto', 1, 'Sua galhada curva sutilmente muda a direÃ§Ã£o das correntes de ar, criando um estranho espaÃ§o onde a realidade Ã© distorcida. ', 'Stantler.png'),
('Smeargle', 235, 'Normal', 'Johto', 1, 'Smeargle, o PokÃ©mon pintor. Um fluido especial escoa da ponta de sua cauda. Ele usa esse fluido para pintar lugares, marcando seu territÃ³rio.', 'Smeargle.png'),
('Tyrogue', 236, 'Lutador', 'Johto', 20, 'Ele estÃ¡ sempre cheio de energia. Para ficar mais forte, ele continua a lutar, mesmo perdendo.', 'Tyrogue.png');
INSERT INTO `Pokemon` (`nome_pokemon`, `numero_pokemon`, `tipo`, `regiao`, `nivel`, `descricao`, `imagem`) VALUES
('Hitmontop', 237, 'Lutador', 'Johto', 20, 'Hitmontop, a forma evoluÃ­da de Tyrogue. Ele chuta enquanto estÃ¡ girando de cabeÃ§a para baixo. Caso gire rÃ¡pido demais, Ã© capaz de cavar um buraco na terra.', 'Hitmontop.png'),
('Smoochum', 238, 'Gelo', 'Johto', 1, 'Seus lÃ¡bios sÃ£o a parte mais sensÃ­vel de seu corpo. Ele sempre usa a boca primeiro para examinar qualquer coisa.', 'Smoochum.png'),
('Elekid', 239, 'ElÃ©trico', 'Johto', 1, 'Elekid gira seus braÃ§os para gerar eletricidade, mas se cansa rapidamente, entÃ£o ele recarrega as energias por um curto perÃ­odo de tempo. Ele fica feliz se um trovÃ£o estrona no cÃ©u durante chuvas.', 'Elekid.png'),
('Magby', 240, 'Fogo', 'Johto', 1, 'Ele Ã© encontrado em crateras vulcÃ¢nicas, onde sua temperatura corporal chega a 1100 graus. Toda vez que ele inspira e espira, cinzas saem de sua boca e suas narinas.  ', 'Magby.png'),
('Miltank', 241, 'Normal', 'Johto', 1, 'Miltank, o PokÃ©mon vaca. Seu leite Ã© cheio de nutrientes, transformando-o na melhor bebida para os doentes e exaustos.', 'Miltank.png'),
('Blissey', 242, 'Normal', 'Johto', 1, 'Blissey, a forma evoluÃ­da de Chansey. Tem uma atitude muito complacente. Ao ver um PokÃ©mon doente, vai tratar dele e recuperar sua saÃºde. ', 'Blissey.png'),
('Raikou', 243, 'ElÃ©trico', 'Johto', 1, 'Raikou, o PokÃ©mon lendÃ¡rio. Juntamente com Entei e Suicune, ele Ã© uma das bestas lendÃ¡rias criadas por Ho-Oh apÃ³s o incÃªndio da torre Brass. As nuvens de chuva que carrega permitem com que ele atire trovÃµes Ã  vontade. Ele corre pela terra enquanto emite um latido que soa como um raio atingin', 'Raikou.png'),
('Entei', 244, 'Fogo', 'Johto', 1, 'Entei, o PokÃ©mon lendÃ¡rio. Juntamente com Raikou e Suicune, ele Ã© uma das bestas lendÃ¡rias criadas por Ho-Oh apÃ³s o incÃªndio da torre Brass. Ao seu latido, vulcÃµes entram em erupÃ§Ã£o - acredita-se que o mesmo nasceu da erupÃ§Ã£o de um. Incapaz de controlar seu poder incrÃ­vel, ele corre pela', 'Entei.png'),
('Suicune', 245, 'Agua', 'Johto', 1, 'Suicune, o PokÃ©mon lendÃ¡rio. Juntamente com Raikou e Entei, ele Ã© uma das bestas lendÃ¡rias criadas por Ho-Oh apÃ³s o incÃªndio da torre Brass. Ele representa as Ã¡guas que extinguiram esse incÃªndio. Dito ser a reincarnaÃ§Ã£o dos ventos do norte, Suicune tem o poder de purificar Ã¡gua contaminad', 'Suicune.png'),
('Larvitar', 246, 'Pedra', 'Johto', 1, 'Larvitar nasce das profundezas da terra, e sÃ³ emerge se alimentando do solo. Depois de comer uma montanha grande o suficiente, ele dorme para poder crescer.', 'Larvitar.png'),
('Pupitar', 247, 'Pedra', 'Johto', 30, 'Pupitar, a forma evoluÃ­da de Larvitar. Mesmo preso dentro de um casco tÃ£o duro quanto pedra, ele pode se mover livremente. Tem um poder destrutivo imenso - sua debulha pode derrubar uma montanha.', 'Pupitar.png'),
('Tyranitar', 248, 'Noturno', 'Johto', 55, 'Tyranitar, a forma evoluÃ­da de Pupitar. Esse monstruoso PokÃ©mon tem um corpo que Ã© invulnerÃ¡vel a qualquer ataque, o que provoca nele um anseio em desafiar os inimigos. Sua atitude, consequentemente, Ã© de extrema insolÃªncia e egoÃ­smo.', 'Tyranitar.png'),
('Lugia', 249, 'Psiquico', 'Johto', 1, 'Lugia, o PokÃ©mon lendÃ¡rio. Lugia Ã© o guardiÃ£o dos mares, e permanece dormente no mesmo para conter seu enorme poder. Ã‰ capaz de acalmar a mais furiosa das tempestades, mas, ao emergir, ele inicia uma tempestade que pode durar mais de um mÃªs.', 'Lugia.png'),
('Ho-Oh', 250, 'Fogo', 'Johto', 1, 'Ho-Oh, o PokÃ©mon lendÃ¡rio. Ho-Oh Ã© o guardiÃ£o dos cÃ©us, e ocasionalmente visto, junto com Lugia, como uma dupla. Diz a lenda que seu corpo brilha as cores do arco-Ã­ris, e que ele constantemente voa pelos cÃ©us do mundo, formando um arco-Ã­ris aonde ele voa.', 'Ho-Oh.png'),
('Celebi', 251, 'Psiquico', 'Johto', 1, 'Celebi, o PokÃ©mon lendÃ¡rio. Celebi Ã© o guardiÃ£o da floresta Ilex, e viaja atravÃ©s do tempo. Plantas e Ã¡rvores florescem aonde quer que ele apareÃ§a. Ao desaparecer, nas profundezas da floresta, Ã© dito que ele deixa um ovo que trouxe do futuro.', 'Celebi.png'),
('Treecko', 252, 'Planta', 'Hoenn', 1, 'Treecko, o PokÃ©mon rÃ©ptil. Treecko tem uma grande cauda verde escuro com dois lÃ³bulos separados. Ele a usa para sentir a umidade e, portanto, prever o tempo do dia seguinte.  ', 'Treecko.png'),
('Grovyle', 253, 'Planta', 'Hoenn', 16, 'Grovyle, o PokÃ©mon bÃ­pede, e a forma evoluÃ­da de Treecko. Grovyle possui folhas em seus pulsos, cabeÃ§a, alÃ©m da duas caudas com aparÃªncia semelhante a uma folha. Dessa forma, Grovyle se torna um exÃ­mio na arte de camuflar.', 'Grovyle.png'),
('Sceptile', 254, 'Planta', 'Hoenn', 36, 'Sceptile, o PokÃ©mon reptiliano bÃ­pede, e a forma evoluÃ­da de Grovyle. As sementes em suas costas contÃªm nutrientes capazes de revitalizar Ã¡rvores. Ã‰ capaz de saltar livremente de galho em galho e regula a temperatura do seu corpo atravÃ©s do sol.', 'Sceptile.png'),
('Torchic', 255, 'Fogo', 'Hoenn', 1, 'Torchic, o PokÃ©mon pintinho. Possui um saco de chamas em seu estÃ´mago que queima perpetuamente. Aquele que o abraÃ§ar sentirÃ¡ o calor que ele possui. Ele segue os passos de seu treinador cambaleando o corpo.', 'Torchic.png'),
('Combusken', 256, 'Fogo', 'Hoenn', 16, 'Combusken, o PokÃ©mon frango jovem, e a forma evoluÃ­da de Torchic. Possui chutes de poder incrivelmente destrutivo. Consegue dar dez chutes por segundo. Durante as batalhas, a temperatura de seu corpo aumenta bastante.', 'Combusken.png'),
('Blaziken', 257, 'Fogo', 'Hoenn', 36, 'Blaziken, o PokÃ©mon chama, e a forma evoluida do Combusken. Em batalha, os pulsos de Blaziken queimam um fogo ardente que dÃ¡ forÃ§a para atacar o oponente. TambÃ©m possui pernas bastante fortes, que lhe permitem pular bem alto.', 'Blaziken.png'),
('Mudkip', 258, 'Agua', 'Hoenn', 1, 'Mudkip, o PokÃ©mon peixe de lama. A barbatana na cabeÃ§a de Mudkip age como um radar de alta sensibilidade. Ele pode determinar o que acontece em sua volta sem precisar olhar. Embora seja pequeno, Ã© bem forte e consegue esmagar rochas.', 'Mudkip.png'),
('Marshtomp', 259, 'Agua', 'Hoenn', 16, 'Marshtomp, o PokÃ©mon peixe de lama, e a forma evoluÃ­da de Mudkip. Suas coxas desenvolveram-se de forma que ele conseguisse andar sobre duas patas. Ele adquiriu uma pele mais viscosa. Utiliza a lama para hidratar a pele.', 'Marshtomp.png'),
('Swampert', 260, 'Agua', 'Hoenn', 36, 'Swampert, o PokÃ©mon peixe de lama, e a forma evoluÃ­da do Marshtomp. Sua visÃ£o Ã© tÃ£o aguÃ§ada que lhe permite enxergar mesmo em Ã¡guas poluÃ­das. Ele pode prever tempestades sentindo o vento e os sons das ondas com suas barbatanas. Ele junta grandes pedras para se proteger de tempestades.', 'Swampert.png'),
('Poochyena', 261, 'Noturno', 'Hoenn', 1, 'Poochyena, o PokÃ©mon mordida. Intimida os adversÃ¡rios arrepiando os pelos de sua cauda. Gosta de rosnar mostrando os dentes e atacar com mordidas. Ele corre atrÃ¡s de suas presas atÃ© ficarem exaustas.', 'Poochyena.png'),
('Mightyena', 262, 'Noturno', 'Hoenn', 18, 'Mightyena, o PokÃ©mon mordida, e a forma evoluÃ­da de Poochyena. Quando selvagens, vivem em bando. Eles nunca desafiarÃ£o as ordens do lÃ­der do bando, atacando sempre em equipe. SÃ³ respeitam treinadores que consideram fortes. ', 'Mightyena.png'),
('Zigzagoon', 263, 'Normal', 'Hoenn', 1, 'Zigzagoon, o PokÃ©mon mini guazinim. Os pelos de seu corpo estÃ£o sempre eriÃ§ados. Esperto, este PokÃ©mon pode fingir-se de morto para enganar os seus inimigos. Ã‰ muito curioso, gosta de fuÃ§ar tudo o que vÃª pelo caminho.', 'Zigzagoon.png'),
('Linoone', 264, 'Normal', 'Hoenn', 20, 'Linoose, o PokÃ©mon apressado, e a forma evoluÃ­da de Zigzagoon. Se um Linoone correr em linha reta poderÃ¡ alcanÃ§ar a velocidade de 90 km/h. Ele tem dificuldade para correr em percursos curvos. Procura sempre desviar dos obstÃ¡culos em seu caminho num Ã¢ngulo reto.', 'Linoone.png'),
('Wurmple', 265, 'Inseto', 'Hoenn', 1, 'Wurmple, o PokÃ©mon verme. Os PokÃ©mons pÃ¡ssaros sÃ£o os seus principais predadores. Para se defender, ele se vira e aponta os espinhos de seu rabo no inimigo. Esses espinhos podem injetar veneno.', 'Wurmple.png'),
('Silcoon', 266, 'Inseto', 'Hoenn', 7, 'Silcoon, o PokÃ©mon casulo, e uma das formas evoluÃ­das de Wurmple. Ele usa a seda de seu corpo para amarrar-se em Ã¡rvores. Acredita-se que nÃ£o coma nada atÃ© evoluir novamente, sobrevivendo apenas com a Ã¡gua da chuva que cair sobre a seda.', 'Silcoon.png'),
('Beautifly', 267, 'Inseto', 'Hoenn', 10, 'Beautifly, o PokÃ©mon borboleta, e a forma evoluÃ­da de Silcoon. Beautifly possui uma boca comprida, no formato de uma agulha em espiral. Esse formato facilita muito para colher o pÃ³len das flores. Pode atacar ferozmente se irritado.', 'Beautifly.png'),
('Cascoon', 268, 'Inseto', 'Hoenn', 7, 'Cascoon, o PokÃ©mon casulo, e uma das formas evoluÃ­das de Wurmple. Uma vez que tenha envolvido seu corpo com seda, ela endurece. Ele se prepara para a evoluÃ§Ã£o dentro do casulo. Ele nÃ£o esquecerÃ¡ dos golpes que receber enquanto casulo, indo dar o troco depois que evoluir.', 'Cascoon.png'),
('Dustox', 269, 'Inseto', 'Hoenn', 10, 'Dustox, o PokÃ©mon mariposa venenosa, e a forma evoluÃ­da de Cascoon. Ao bater as usas asas, deixa cair um pÃ³ pelo caminho que contÃ©m um forte veneno. Ele usa as antenas como radar para procurar comida. Se sente altamente atraÃ­do pelas luzes.', 'Dustox.png'),
('Lotad', 270, 'Agua', 'Hoenn', 1, 'Lotad, o PokÃ©mon erva daninha d''Ã¡gua. Lotad era um pokÃ©mon que vivia em terra firme. Com o tempo, a folha de sua cabeÃ§a ficou grande e pesada. Agora ele vive flutuando nas Ã¡guas. Se ele fica sem beber Ã¡gua por muito tempo, sua folha irÃ¡ murchar.', 'Lotad.png'),
('Lombre', 271, 'Agua', 'Hoenn', 14, 'Lombre, o PokÃ©mon alegre, e a forma evoluÃ­da de Lotad. Ã‰ um PokÃ©mon de hÃ¡bitos noturnos. Gosta de aprontar puxando as linhas das varas dos pescadores para o fundo das Ã¡guas. Se alimenta de musgos que nascem nas margens dos rios. ', 'Lombre.png'),
('Ludicolo', 272, 'Agua', 'Hoenn', 14, 'Ludicolo, o PokÃ©mon despreocupado, e a forma evoluÃ­da de Lombre atravÃ©s da Water Stone. Ludiculo comeÃ§a a danÃ§ar assim que ouve uma mÃºsica alegre e festiva. Ele usa os movimentos de sua danÃ§a para aumentar seu poder. Mesmo em batalha ele nÃ£o hesita em danÃ§ar.', 'Ludicolo.png'),
('Seedot', 273, 'Planta', 'Hoenn', 1, 'Seedot, o PokÃ©mon bolota. Gosta de fincar-se em galhos de Ã¡rvores usando o gancho em sua cabeÃ§a. Ele absorve os nutrientes da Ã¡rvore por esse gancho. Ele assusta muitos PokÃ©mons que o confundem com uma noz. ', 'Seedot.png'),
('Nuzleaf', 274, 'Planta', 'Hoenn', 14, 'Nuzleaf, o PokÃ©mon astuto, e a forma evoluÃ­da de Seedot. Um pokÃ©mon que vive nas profundezas das florestas. Com a folha de sua cabeÃ§a e faz uma flauta cujo som deixa apreensivo aqueles que o escutam. O seu nariz grande e pontiagudo Ã© o seu ponto fraco.', 'Nuzleaf.png'),
('Shiftry', 275, 'Planta', 'Hoenn', 14, 'Shiftry, o PokÃ©mon perverso, e a forma evoluÃ­da de Nuzleaf atravÃ©s da Leaf Stone. Diz-se que este pokÃ©mon misterioso vive no topo de Ã¡rvores gigantes que existem hÃ¡ mais de mil anos. Ele pode criar terrÃ­veis tempestades de vento ao girar as folhas de sua mÃ£o.', 'Shiftry.png'),
('Taillow', 276, 'Voador', 'Hoenn', 1, 'Taillow, o PokÃ©mon mini andorinha. Possui um espÃ­rito corajoso e nÃ£o teme enfrentar adversÃ¡rios difÃ­ceis. Voa junto com seu bando em busca de climas quentes. Ã‰ um dos principais predadores de Wurmple.', 'Taillow.png'),
('Swellow', 277, 'Voador', 'Hoenn', 22, 'Swellow, o PokÃ©mon andorinha, e a forma evoluÃ­da de Taillow. Fica revoando os cÃ©us em busca de suas presas. Quando encontra uma, mergulha na direÃ§Ã£o dela. Se as duas penas de sua cauda estiverem alinhadas Ã© sinal de boa saÃºde.', 'Swellow.png'),
('Wingull', 278, 'Agua', 'Hoenn', 1, 'Wingull, o PokÃ©mon gaivota do mar. Ele voa sobre correntes de ar sem precisar bater as asas. ConstrÃ³is os seus ninhos Ã  beira-mar. Possui o hÃ¡bito de carregar seus alimentos dentro do bico.', 'Wingull.png'),
('Pelipper', 279, 'Agua', 'Hoenn', 25, 'Pelipper, o PokÃ©mon pÃ¡ssaro d''Ã¡gua, e a forma evoluÃ­da de Wingull. Ã‰ um mensageiro dos cÃ©us. Ele carrega ovos e pequenos pokÃ©mons em seguranÃ§a dentro de seu bico. Fica surfando sobre as ondas quando quer descansar as asas. ', 'Pelipper.png'),
('Ralts', 280, 'Psiquico', 'Hoenn', 1, 'Ralts, o PokÃ©mon sensÃ­vel.  Tem a capacidade de sentir as emoÃ§Ãµes. Se o seu chifre captar sentimentos quente de pessoas ou PokÃ©mons, seu prÃ³prio corpo irÃ¡ se aquecer.', 'Ralts.png'),
('Kirlia', 281, 'Psiquico', 'Hoenn', 20, 'Kirlia, o PokÃ©mon emoÃ§Ã£o, e a forma evoluÃ­da de Ralts. Caso o seu treinador esteja feliz, Kirlia transborda de alegria e comeÃ§a a danÃ§ar alegremente enquanto gira. Seu poder psÃ­quico lhe permite distorcer o espaÃ§o ao redor e ter visÃµes do futuro.', 'Kirlia.png'),
('Gardevoir', 282, 'Psiquico', 'Hoenn', 30, 'Gardevoir, o PokÃ©mon abraÃ§o, e a forma evoluÃ­da de Kirlia. Para proteger seu treinador, ele Ã© capaz de entregar sua vida, gastando todo o seu poder psÃ­quico para criar um pequeno buraco negro. Aparentemente ele nÃ£o sente a gravidade pois se sustenta no ar com seus poderes psÃ­quicos.', 'Gardevoir.png'),
('Surskit', 283, 'Inseto', 'Hoenn', 1, 'Surskit, o PokÃ©mon patinador de lagoa. Ele anda como se estivesse patinando na Ã¡gua. Eles podem excretar um aroma doce da ponta de sua cabeÃ§a. Vive sobre as plantas aquÃ¡ticas.', 'Surskit.png'),
('Masquerain', 284, 'Inseto', 'Hoenn', 22, 'Masquerain, o PokÃ©mon globo ocular, e a forma evoluÃ­da de Surskit. Suas antenas possuem marcas de um olho desenhado que intimida os seus inimigos. Na chuva, elas ficam tÃ£o pesadas que o incapacitam de voar. Suas quatro asas lhe permitem pairar no ar e voar para qualquer direÃ§Ã£o.', 'Masquerain.png'),
('Shroomish', 285, 'Planta', 'Hoenn', 1, 'Shroomish, o PokÃ©mon cogumelo. Quando estÃ¡ em perigo, ele pode chacoalhar o seu corpo e lanÃ§ar esporos venenosos a partir do topo de sua cabeÃ§a. Prefere viver em lugares Ãºmidos.\r\n', 'Shroomish.png'),
('Breloom', 286, 'Planta', 'Hoenn', 23, 'Breloom, o PokÃ©mon cogumelo, e a forma evoluÃ­da de Shroomish. Os braÃ§os curtos que possui podem esticar ao lanÃ§ar movimentos de boxeador. As sementes que possui em sua cauda sÃ£o altamente tÃ³xicas. Ele golpeia seus adversÃ¡rios enquanto estÃ£o atordoados com seus esporos.', 'Breloom.png'),
('Slakoth', 287, 'Normal', 'Hoenn', 1, 'Slakoth, o PokÃ©mon preguiÃ§a. Este PokÃ©mon dorme 20 horas por dia. Seu coraÃ§Ã£o bate apenas uma vez por minuto. Raramente Ã© visto em movimento. Ele pode tornar qualquer um sonolento apenas por ser visto.', 'Slakoth.png'),
('Virgoroth', 288, 'Normal', 'Hoenn', 18, 'Virgoroth, o PokÃ©mon macaco selvagem, e a forma evoluÃ­da de Slakoth. Seu coraÃ§Ã£o bate num ritmo acelerado, de forma que nÃ£o consegue ficar parado, mesmo que esteja comendo ou dormindo. O seu nÃ­vel de estresse aumenta caso ele nÃ£o se mantenha em movimento constantemente. Muito estresse o farÃ¡', 'Virgoroth.png'),
('Slaking', 289, 'Normal', 'Hoenn', 36, 'Slaking, o PokÃ©mon preguiÃ§oso, e a forma evoluÃ­da de Vigoroth. O PokÃ©mon mais preguiÃ§oso do mundo. Ele passa o dia deitado debaixo de Ã¡rvores esperando frutos maduros caÃ­rem. Ele para e fica descansando atÃ© mesmo enquanto batalha. No entanto, enquanto descansa, ele reÃºne energia para contra', 'Slaking.png'),
('Nincada', 290, 'Inseto', 'Hoenn', 1, 'Nincada, o PokÃ©mon estagiÃ¡rio. Ele vive no subterrÃ¢neo e absorve os nutrientes das raÃ­zes de Ã¡rvores. Seus olhos sÃ£o praticamente cegos, por isso sente as coisas usando suas antenas. Evita muito a luz solar.', 'Nincada.png'),
('Ninjask', 291, 'Inseto', 'Hoenn', 20, 'Ninjask, o PokÃ©mon Ninja, e a forma evoluÃ­da de Nincada. Por se mover muito rÃ¡pido, muitas vezes fica invisÃ­vel, pois olhos comuns nÃ£o conseguem acompanhar seus movimentos. Gosta de comer seiva de Ã¡rvores.', 'Ninjask.png'),
('Shedinja', 292, 'Inseto', 'Hoenn', 20, 'Shedinja, o PokÃ©mon vertido, e a forma evoluÃ­da de Nincada. O corpo de Shedinja nÃ£o dÃ¡ sequer uma contraÃ§Ã£o muscular, ele Ã© duro e imÃ³vel. Acredita-se que Ã© um casco oco do Nincada recÃ©m evoluÃ­do em Ninjask. Dizem que ele roubarÃ¡ o espÃ­rito daquele que olhar o rombo em suas costas.', 'Shedinja.png'),
('Whismur', 293, 'Normal', 'Hoenn', 1, 'Whismur, o PokÃ©mon sussurro. Geralmente ele comunica-se sussurrando. Quando pressente o perigo, dÃ¡ um grito tÃ£o alto quanto o motor de um aviÃ£o a jato. Ele respira atravÃ©s de canais em suas orelhas, permitindo-o a dar longos gritos sem precisar parar para recuperar o fÃ´lego.', 'Whismur.png'),
('Loudred', 294, 'Normal', 'Hoenn', 20, 'Loundred, o PokÃ©mon grande voz, e a forma evoluÃ­da de Whismur. Possui orelhas redondas que funcionam como auto-falantes. Consegue derrubar uma casa de madeira com o poder ultra-sÃ´nico de seus berros. Quando termina de berrar, torna-se incapaz de ouvir qualquer coisa por um tempo. ', 'Loudred.png'),
('Exploud', 295, 'Normal', 'Hoenn', 40, 'Exploud, o PokÃ©mon barulhento, e a forma evoluÃ­da de Loudred. Exploud comunica-se com os outros soltando alguns apitos que consegue emitir atravÃ©s dos tubos que hÃ¡ em seu corpo. Os sons que ele emite podem ser ouvidos de grandes distÃ¢ncias, alÃ©m de serem capazes de causar terremotos.', 'Exploud.png'),
('Makuhita', 296, 'Lutador', 'Hoenn', 1, 'Makuhita, o PokÃ©mon coragem. Makuhita tem um espÃ­rito incansÃ¡vel, nunca perde a esperanÃ§a. Ele come um monte de comida, fica cheio de sono, depois treina com muito rigor. Vivendo dessa maneira, este PokÃ©mon armazena energia em seu corpo.', 'Makuhita.png'),
('Hariyama', 297, 'Lutador', 'Hoenn', 24, 'Hariyama, o PokÃ©mon empurrÃ£o de braÃ§o, e a forma evoluÃ­da de Makuhita. Gosta de medir sua forÃ§a com PokÃ©mons de grande massa corporal. Ele pode arremessar um caminhÃ£o para longe e parar trens em movimento com as mÃ£os.', 'Hariyama.png'),
('Azurill', 298, 'Normal', 'Hoenn', 1, 'Azurill, o PokÃ©mon bolinhas. Sua cauda salta como uma bola de borracha. Ele estica a cauda quando enfrenta inimigos maiores que ele. Ele pode girar a cauda como um laÃ§o de vaqueiro e entÃ£o lanÃ§Ã¡-la para longe, fazendo seu corpo voar.', 'Azurill.png'),
('Nosepass', 299, 'Pedra', 'Hoenn', 1, 'Nosepass, o PokÃ©mon bÃºssola. Quando estÃ¡ em perigo, aumenta o magnetismo de seu corpo e se protege atraindo objetos metÃ¡licos para perto de si. Seu nariz estÃ¡ sempre apontando para o norte. Se dois Nosepass se encontram, nÃ£o conseguirÃ£o ficar um de frente para o outro pois seus narizes se rep', 'Nosepass.png'),
('Skitty', 300, 'Normal', 'Hoenn', 1, 'Skitty, o PokÃ©mon gatinho. Fica facilmente fascinado por objetos em movimento, por isso fica perseguindo-os. Muitas vezes fica girando tentando pegar o prÃ³prio rabo atÃ© ficar tonto. Ã‰ difÃ­cil para alguÃ©m conquistar sua confianÃ§a.', 'Skitty.png'),
('Delcatty', 301, 'Normal', 'Hoenn', 1, 'Delcatty, o PokÃ©mon vaidoso, e a forma evoluÃ­da de Skitty atravÃ©s da Moon Stone. Delcatty come e dorme na hora que quiser, nÃ£o mantÃ©m um horÃ¡rio certo para isso. Suas rotinas diÃ¡rias sÃ£o completamente aleatÃ³rias. Mesmo que seja perturbado enquanto dorme, nunca irÃ¡ atacar. ', 'Delcatty.png'),
('Sableye', 302, 'Noturno', 'Hoenn', 1, 'Sableye, o PokÃ©mon escuridÃ£o. Vive tranquilamente nas profundezas de cavernas. Ele cava o chÃ£o Ã  procura de pedras para comer. SÃ£o temidos por muitos pois acredita-se que aquele que vir as jÃ³ias de seus olhos brilharem na escuridÃ£o terÃ¡ seu espÃ­rito roubado.', 'Sableye.png'),
('Mawile', 303, 'Noturno', 'Hoenn', 1, 'Mawile, o PokÃ©mon enganador. Anexado a sua cabeÃ§a existe um conjunto de mandÃ­bulas capazes de roer vigas de metal. Suas mandÃ­bulas na verdade sÃ£o chifres metÃ¡licos. Ele distrai os inimigos com sua aparÃªncia dÃ³cil e depois abocanhÃ¡-los de surpresa.', 'Mawile.png'),
('Aron', 304, 'Pedra', 'Hoenn', 1, 'Aron, o PokÃ©mon armadura de ferro. Com sua forÃ§a, Aron pode demolir um pesado caminhÃ£o. ApÃ³s isso, o caminhÃ£o torna-se a sua refeiÃ§Ã£o. Assim que evolui, joga fora sua antiga carcaÃ§a de aÃ§o e desenvolve uma nova.', 'Aron.png'),
('Lairon', 305, 'Pedra', 'Hoenn', 32, 'Lairon, o PokÃ©mon armadura de ferro, e a forma evoluÃ­da de Aron. 	Lairon se alimenta do ferro contido nas rochas. Faz seu ninho nas montanhas onde Ã© encontrado o minÃ©rio de ferro. Ele combate com outros de sua espÃ©cie para disputar territÃ³rio. ', 'Lairon.png'),
('Aggron', 306, 'Pedra', 'Hoenn', 42, 'Aggron, o PokÃ©mon armadura de ferro, e a forma evoluÃ­da de Lairon. Muito zeloso com o seu territÃ³rio, Aggron defende seu ambiente de invasores. Caso seu territÃ³rio seja incendiado ou destruÃ­do por um deslizamento de rochas, ele irÃ¡ cuidar do solo, plantar Ã¡rvores e restaurar o lugar. ', 'Aggron.png'),
('Meditite', 307, 'Lutador', 'Hoenn', 1, 'Meditite, o PokÃ©mon meditaÃ§Ã£o. Ele medita para flutuar e aumentar seu poder interior. Sobrevive comendo apenas uma fruta por dia. Ele costuma fazer os seus treinamentos mentais em profundas montanhas.', 'Meditite.png'),
('Medicham', 308, 'Lutador', 'Hoenn', 37, 'Medicham, o PokÃ©mon meditaÃ§Ã£o, e a forma evoluÃ­da de Meditite. Devido a sua meditaÃ§Ã£o, o 6Âº sentido deste PokÃ©mon Ã© bem aguÃ§ado. Ele pode sentir o que os outros estÃ£o pensando. TambÃ©m pode prever os movimentos do adversÃ¡rio e ficar dias sem comer.', 'Medicham.png'),
('Electrike', 309, 'ElÃ©trico', 'Hoenn', 1, 'Electrike, o PokÃ©mon relÃ¢mpago. Ele armazena eletricidade em sua pele. Quando o clima estÃ¡ muito seco, seu corpo comeÃ§a a soltar faÃ­scas. Ele estimula os seus mÃºsculos com eletricidade, tornando-o muito veloz.', 'Electrike.png'),
('Manectric', 310, 'ElÃ©trico', 'Hoenn', 26, 'Manectric, o PokÃ©mon descargar elÃ©trica. Manectric descarrega eletricidade atravÃ©s de sua juba. A energia pode criar uma nuvem de raios sobre sua cabeÃ§a. Raramente se mostra diante de pessoas.', 'Manectric.png'),
('Plusle', 311, 'ElÃ©trico', 'Hoenn', 1, 'Plusle, o PokÃ©mon animador. Este PokÃ©mon estÃ¡ sempre a animar seus parceiros de equipe nas batalhas, soltando faÃ­scas das bochechas. EstÃ¡ sempre absorvendo a eletricidade de postes telefÃ´nicos.', 'Plusle.png'),
('Minum', 312, 'ElÃ©trico', 'Hoenn', 1, 'Minum, o PokÃ©mon animador. Se chove, Minun procura logo um abrigo. Dizem que estar exposto simultaneamente Ã s eletricidades de Plusle e Minun trarÃ¡ uma boa circulaÃ§Ã£o sanguÃ­nea e um aumento de vitalidade.', 'Minum.png'),
('Volbeat', 313, 'Inseto', 'Hoenn', 1, 'Volbeat, o PokÃ©mon vaga-lume. Utiliza a luz piscante de seu rabo para comunicar-se. Ã‰ atraÃ­do pelo aroma doce de Illumise. Ã€ noite, faz belos desenhos geomÃ©tricos com luz. SÃ³ vive onde em lagos nÃ£o poluÃ­dos.', 'Volbeat.png'),
('Illumise', 314, 'Inseto', 'Hoenn', 1, 'Illumise, o PokÃ©mon vaga-lume. Com o seu doce aroma, guia os Volbeats para fazerem sinais de luz no cÃ©u noturno. Para poder conquistÃ¡-la, os Volbeats precisam fazer no cÃ©u desenhos bem complexos.', 'Illumise.png'),
('Roselia', 315, 'Planta', 'Hoenn', 1, 'Roselia, o PokÃ©mon espinho. Quanto mais saudÃ¡vel Ã© o Roselia, mais cheirosas sÃ£o as suas flores. A fragÃ¢ncia delas pode deixar o oponente desatento. Os espinhos de sua cabeÃ§a sÃ£o venenosos.', 'Roselia.png'),
('Gulpin', 316, 'Venenoso', 'Hoenn', 1, 'Gulpin, o PokÃ©mon estÃ´mago. Praticamente, todo o corpo Gulpin Ã© o seu estÃ´mago. Como resultado, pode engolir algo que tenha seu prÃ³prio tamanho. O estÃ´mago dele possui enzimas especiais que dissolvem qualquer coisa.', 'Gulpin.png'),
('Swalot', 317, 'Venenoso', 'Hoenn', 26, 'Swalot, o PokÃ©mon saco de veneno, e a forma evoluÃ­da de Gulpin. Como nÃ£o possui dentes, engole tudo o que come. Sua boca fica enorme quando totalmente aberta. Ele ejacula um lÃ­quido Ã¡cido para enfraquecer as suas presas.', 'Swalot.png'),
('Carvanha', 318, 'Agua', 'Hoenn', 1, 'Carvanha, o PokÃ©mon selvagem. Carvanha possui dentes fortemente desenvolvidos. Ele morde cascos de barcos, fazendo-os afundar. Um cardume inteiro irÃ¡ atacar caso tenha seu territÃ³rio invadido. No entanto, sozinho ele Ã© tÃ­mido.', 'Carvanha.png'),
('Sharpedo', 319, 'Agua', 'Hoenn', 30, 'Sharpedo, o PokÃ©mon brutal, e a forma evoluÃ­da de Carvanha. O grande perigo dos mares, Sharpedo pode atacar violentamente aquele que cruzar o seu caminho. Apesar de ser desprovido de cauda, pode nadar em alta velocidade, percorrendo longas distÃ¢ncias.  ', 'Sharpedo.png'),
('Wailmer', 320, 'Agua', 'Hoenn', 1, 'Wailmer, o PokÃ©mon baleia-bola. Enchendo o seu corpo de Ã¡gua, Wailmer transforma-se numa bola a saltar pelo chÃ£o. Suas narinas ficam sobre a sua cabeÃ§a. Ele assusta as pessoas jorrando a Ã¡gua de seu corpo pelas narinas. ', 'Wailmer.png'),
('Wailord', 321, 'Agua', 'Hoenn', 40, 'Wailord, o PokÃ©mon baleia flutuante, e a forma evoluÃ­da de Wailmer. O maior PokÃ©mon que existe. Pode ingerir uma grande quantidade de comida com sua boca grande. Com apenas um fÃ´lego, consegue mergulhar a 3 km de profundidade.', 'Wailord.png'),
('Numel', 322, 'Fogo', 'Hoenn', 1, 'Numel, o PokÃ©mon entorpecido. O corpo deste PokÃ©mon parece ser um caldeirÃ£o fervente de magma. Quando Ã© molhado, o magma esfria e endurece, tornando-o mais lento.', 'Numel.png'),
('Camerupt', 323, 'Fogo', 'Hoenn', 33, 'Camerupt, o PokÃ©mon erupÃ§Ã£o, e a forma evoluÃ­da de Numel. Camerupt possui um vulcÃ£o dentro do corpo. Quando estÃ¡ nervoso, as corcovas em suas costas entram em erupÃ§Ã£o, jorrando lava fervente. Ele vive em crateras de vulcÃµes.', 'Camerupt.png'),
('Torkoal', 324, 'Fogo', 'Hoenn', 1, 'Torkoal, o PokÃ©mon CarvÃ£o. Torkoal cava o solo de montanhas em busca de carvÃ£o. Se encontra algum, guarda dentro de seu casco. Seu corpo gera energia queimando o carvÃ£o. Quando estÃ¡ em apuros, a fumaÃ§a que solta Ã© negra.  ', 'Torkoal.png'),
('Spoink', 325, 'Psiquico', 'Hoenn', 1, 'Spoink, o PokÃ©mon pulo. O impacto que seu rabo dÃ¡ no chÃ£o enquanto estÃ¡ pulando faz o seu coraÃ§Ã£o bater. Por esta razÃ£o, Spoink estÃ¡ sempre pulando. A pÃ©rola que possui sobre a cabeÃ§a ajuda a ampliar seus poderes psÃ­quicos.', 'Spoink.png'),
('Grumpig', 326, 'Psiquico', 'Hoenn', 32, 'Grumpig, o PokÃ©mon manipulador, e a forma evoluÃ­da de Spoink. Grumpig usa as pÃ©rolas negras de seu corpo para amplificar as ondas de seus poderes psÃ­quicos e ganhar assim um controle total sobre seu inimigo. Quando usa os seus poderes, comeÃ§a a dar estranhos passos de danÃ§a. ', 'Grumpig.png'),
('Spinda', 327, 'Normal', 'Hoenn', 1, 'Spinda, o PokÃ©mon panda de manchas. Todos os Spindas existentes no mundo possuem manchas Ãºnicas pela cara. Dois Spindas nunca terÃ£o manchas idÃªnticas. O seu jeito desengonÃ§ado de caminhar deixa os inimigos tontos.', 'Spinda.png'),
('Trapinch', 328, 'Terrestre', 'Hoenn', 1, 'Trapinch, o PokÃ©mon formiga escavadora. Suas mandÃ­bulas sÃ£o capazes de quebrar pedras. Ele cava poÃ§os na areia onde espera sua presa passar e cair no buraco. Por causa de sua cabeÃ§ona, tem dificuldades de se endireitar quando cai de costas.', 'Trapinch.png'),
('Vibrava', 329, 'Terrestre', 'Hoenn', 35, 'Vibrava, o PokÃ©mon vibraÃ§Ã£o, e a forma evoluÃ­da de Trapinch. Ao vibrar as suas asas, Vibrava cria ondas ultra-sÃ´nicas para atacar seus adversÃ¡rios. Essas ondas sÃ£o tÃ£o fortes que podem trazer dores de cabeÃ§a para as pessoas. Suas asas ainda estÃ£o em fase de crescimento, por isso voa curtas', 'Vibrava.png'),
('Flygon', 330, 'DragÃ£o', 'Hoenn', 45, 'Flygon, o PokÃ©mon mÃ­stico, e a forma evoluÃ­da de Vibrava. Ele gera tempestades de areia com o seu bater de asas. Ao fazer isso, o barulho que suas asas fazem parece um canto. Por esta razÃ£o, esconde-se atrÃ¡s das nuvens de areia para nÃ£o ser detectado pelo  adversÃ¡rio.', 'Flygon.png'),
('Cacnea', 331, 'Planta', 'Hoenn', 1, 'Cacnea, o PokÃ©mon cacto.  Este PokÃ©mon vive em locais Ã¡ridos, principalmente em desertos. Ele solta um cheiro forte de sua flor para atrair suas presas e depois atacar com seus espinhos. Ele armazena Ã¡gua em seu corpo e sobrevive um mÃªs sem beber nada.', 'Cacnea.png'),
('Cacturne', 332, 'Planta', 'Hoenn', 32, 'Cacturne, o PokÃ©mon espantalho, e a forma evoluÃ­da de Cacnea. ApÃ³s viver milhares de anos no deserto, seu sangue passou a ter as mesmas substÃ¢ncias que a areia. De manhÃ£ ele permanece imÃ³vel para nÃ£o perder Ã¡gua com o calor do sol. Ã€ noite, quando a temperatura cai, ele sai para caÃ§ar.', 'Cacturne.png'),
('Swablu', 333, 'Voador', 'Hoenn', 1, 'Swablu, o PokÃ©mon pÃ¡ssaro de algodÃ£o. Se Swablu vir algo sujo, irÃ¡ polir usando as suas asas de algodÃ£o. Ao sujar as asas, vai logo limpÃ¡-las em algum riacho. Quando chega a primavera, um bando de Swablus voam para a cidade. ', 'Swablu.png'),
('Altaria', 334, 'DragÃ£o', 'Hoenn', 35, 'Altaria, o PokÃ©mon cantor, e a forma evoluÃ­da de Swablu. Altaria possui uma voz soprano e reproduz um canto maravilhoso. Suas asas sÃ£o como nuvens de algodÃ£o. Ele lanÃ§a de sua boca bolas de fogo de intenso calor.', 'Altaria.png'),
('Zangoose', 335, 'Normal', 'Hoenn', 1, 'Zangoose, o PokÃ©mon gato furÃ£o. Geralmente anda sobre as quatro patas, mas fica de pÃ© quando estende suas garras para atacar. Durante vÃ¡rias geraÃ§Ãµes este PokÃ©mon vÃª Seviper como seu inimigo mortal.', 'Zangoose.png'),
('Seviper', 336, 'Venenoso', 'Hoenn', 1, 'Seviper, o PokÃ©mon presas de cobra. Possui um rabo no formato de espada que, alÃ©m de cortar o inimigo, infecta-o com o seu veneno. Ele se esconde atrÃ¡s da moita para atacar suas vÃ­timas de surpresa com suas presas venenosas. Desde os tempos remotos ele Ã© arqui-rival de Zangoose.', 'Seviper.png'),
('Lunatone', 337, 'Psiquico', 'Hoenn', 1, 'Lunatone, o PokÃ©mon meteorito. Este PokÃ©mon foi descoberto num local onde havia caÃ­do um meteorito. Por causa disso, muitos acreditam que ele veio do espaÃ§o. Entretanto, ninguÃ©m pode provar essa teoria. Ele flutua no ar atravÃ©s de telecinese e torna-se mais ativos em tempos de lua cheia.', 'Lunatone.png'),
('Solrock', 338, 'Psiquico', 'Hoenn', 1, 'Solrock, o PokÃ©mon meteorito. A luz do sol Ã© a fonte do poder de Solrock. Em dias ensolarados, se expÃµe ao sol para absorver suas energias. Ele tem o poder de ler as emoÃ§Ãµes dos outros. Ele emite um calor intenso enquanto gira o corpo. ', 'Solrock.png'),
('Barboach', 339, 'Agua', 'Hoenn', 1, 'Barboach, o PokÃ©mon bigode. Os bigodes sensÃ­veis de Barboach servem como um Ã³timo sistema de radar. Ao se esconder na lama, deixa apenas seus dois bigodes expostos enquanto aguarda sua presa. Sua pele viscosa torna-o impossÃ­vel de se segurar. ', 'Barboach.png'),
('Whiscash', 340, 'Agua', 'Hoenn', 30, 'Whiscash, o PokÃ©mon bigode, e a forma evoluÃ­da de Barboach. Ao entrar numa raiva selvagem, Whiscash desencadeia um grande tremor ao seu redor. Ele possui a habilidade de prever terremotos. Ã‰ extremamente protetor de seu territÃ³rio, se algum inimigo se aproxima dele, ataca-o com tremores. ', 'Whiscash.png'),
('Corphish', 341, 'Agua', 'Hoenn', 1, 'Corphish, o PokÃ©mon bandido. Ele agarra os seus alimentos utilizando-se de suas pinÃ§as afiadas. Ele nÃ£o tem preferÃªncia por um tipo de comida, come qualquer coisa. Ã‰ um PokÃ©mon destemido que pode procriar em qualquer ambiente.', 'Corphish.png'),
('Crawdaunt', 342, 'Agua', 'Hoenn', 30, 'Crawdaunt, o PokÃ©mon trapaceiro, e a forma evoluÃ­da de Corphish. Ele muda de casco continuamente. Possui um temperamento violento e desafia qualquer um para uma batalha. Outros PokÃ©mons evitam viver no mesmo local onde vivem Crawdaunts. ', 'Crawdaunt.png'),
('Baltoy', 343, 'Psiquico', 'Hoenn', 1, 'Baltoy, o PokÃ©mon boneco de argila. Ele se locomove girando o seu corpo. Pinturas em paredes de antigas ruÃ­nas mostram esse PokÃ©mon vivendo entre as pessoas. Ele dorme enquanto se equilibra em seu Ãºnico pÃ©.', 'Baltoy.png'),
('Claydol', 344, 'Psiquico', 'Hoenn', 36, 'Claydol, o PokÃ©mon boneco de argila, e a forma evoluÃ­da de Baltoy. Dizem que Claydols sÃ£o bonecos de barro que foram feitos por uma antiga civilizaÃ§Ã£o e que foram trazidos a vida por um raio misterioso. Consegue disparar raios de ambos os braÃ§os. ', 'Claydol.png'),
('Lileep', 345, 'Planta', 'Hoenn', 1, 'Lileep, o PokÃ©mon lÃ­rio do mar. Este PokÃ©mon fica permanentemente ancorado a uma rocha. Se camufla entre as algas marinhas para capturar suas presas. Ficou extinto hÃ¡ cem milhÃµes de anos. ', 'Lileep.png'),
('Cradily', 346, 'Planta', 'Hoenn', 40, 'Cradily, o PokÃ©mon percevejo, e a forma evoluÃ­da de Lileep. Ele vive vagando no fundo do mar em busca de comida. Ele ataca soltando um Ã¡cido de seus tentÃ¡culos. Seu corpo Ã© bem aderente, impedindo-o de ser arrastado por correntezas quando se agarra em algo.  ', 'Cradily.png'),
('Anorith', 347, 'Inseto', 'Hoenn', 1, 'Anorith, o PokÃ©mon camarÃ£o velho. Estudos dizem que, no passado, as oito patas que este PokÃ©mon possuÃ­a transformaram-se em asas que o ajudavam a nadar. Vivia em Ã¡guas quentes e usava suas garras para sobreviver. ', 'Anorith.png'),
('Armaldo', 348, 'Inseto', 'Hoenn', 40, 'Armaldo, o PokÃ©mon lÃ¢mina, e a forma evoluÃ­da de Anorith. A armadura resistente do corpo de Armaldo consegue repelir diversos ataques. Ele pode recolher e retirar suas garras de dentro de seu corpo atravÃ©s dos buracos que tem no peito.', 'Armaldo.png'),
('Feebas', 349, 'Agua', 'Hoenn', 1, 'Feebas, o PokÃ©mon peixe. Por ter uma aparÃªncia feia e esfolada, Ã© ignorado atÃ© mesmo por pesquisadores. Apesar disso, Ã© forte e consegue viver tanto em Ã¡gua doce quanto em Ã¡gua salgada. ', 'Feebas.png'),
('Milotic', 350, 'Agua', 'Hoenn', 1, 'Milotic, o PokÃ©mon afetuoso, e a forma evoluÃ­da de Feebas atravÃ©s de troca. Conhecido como "o mais belo de todos os PokÃ©mons". Dizem que sua beleza Ã© capaz de acalmar os coraÃ§Ãµes violentos e cheios de discÃ³rdia. Muitos artistas tentam reproduzir sua beleza.', 'Milotic.png'),
('Castform', 351, 'Normal', 'Hoenn', 1, 'Castform, o PokÃ©mon clima. Castform usa os elementos da natureza para proteger o seu corpinho frÃ¡gil. Ele muda de aparÃªncia conforme o tempo. Sua estrutura celular irÃ¡ mudar conforme o clima do ambiente.', 'Castform.png'),
('Kecleon', 352, 'Normal', 'Hoenn', 1, 'Kecleon, o PokÃ©mon camaleÃ£o. Especialista em camuflagem, consegue mudar as cores de seu corpo Ã  vontade para se misturar com as cores do ambiente, permitindo que fique invisÃ­vel. O Ãºnico detalhe que nÃ£o consegue mudar Ã© a faixa em forma de ziguezague de sua barriga.', 'Kecleon.png'),
('Shuppet', 353, 'Fantasma', 'Hoenn', 1, 'Shuppet, o PokÃ©mon fantoche. O chifre de Shuppet pode captar sentimentos de inveja e vinganÃ§a. Se alguÃ©m desenvolve fortemente esses sentimentos, conseguirÃ¡ atrair um bando deles.', 'Shuppet.png'),
('Banette', 354, 'Fantasma', 'Hoenn', 37, 'Banette, o PokÃ©mon marionete, e a forma evoluÃ­da de Shuppet. A energia maligna que permanece em bonecos de vodu abandonados ganha uma nova vida no corpo de Banette. Ele fura seu prÃ³prio corpo com agulhas para gerar fortes maldiÃ§Ãµes. Se abrir a boca, sua energia maligna escaparÃ¡.', 'Banette.png'),
('Duskull', 355, 'Fantasma', 'Kanto', 1, 'Duskull, o PokÃ©mon fÃºnebre. Este PokÃ©mon vagueia na escuridÃ£o da meia-noite. Ele pode atravessar grossas paredes sem problemas. Ele faz seu Ãºnico olho brilhar para dar sustos nos outros. Dizem que ele vem tirar a alma de crianÃ§as que desobedecem seus pais.', 'Duskull.png'),
('Dusclops', 356, 'Fantasma', 'Hoenn', 37, 'Dusclops, o PokÃ©mon aceno, e a forma evoluÃ­da de Duskull. O interior do corpo de Dusclops Ã© completamente oco. Muitos creem que existe um buraco negro lÃ¡. Com a boca, ele pode absorver qualquer coisa, nÃ£o importa o tamanho. Uma vez absorvida, esta coisa nunca mais sairÃ¡ dele. Ele hipnotiza os ', 'Dusclops.png'),
('Tropius', 357, 'Planta', 'Hoenn', 1, 'Tropius, o PokÃ©mon fruto. As pencas de frutas que nascem no pescoÃ§o de Tropius sÃ£o muito adoradas por crianÃ§as. Ele gosta tanto de frutas que seu organismo se desenvolveu para produzi-las. Para voar, utiliza-se das folhas de suas costas como asas. ', 'Tropius.png'),
('Chimecho', 358, 'Psiquico', 'Hoenn', 1, 'Chimecho, o PokÃ©mon melodia do ventos. Em dias com fortes ventos, Chimecho adora prender-se em um lugar e ficar cantando enquanto seu rabo abana. Seu canto ecoa dentro do corpo como o som de um sino. Quando se sente ofendido, dÃ¡ um grito super-sÃ´nico. ', 'Chimecho.png'),
('Absol', 359, 'Noturno', 'Hoenn', 1, 'Absol, o PokÃ©mon desastre. Sempre que Absol se mostra diante de humanos Ã© sinal que algum desastre estÃ¡ prestes a acontecer. O prÃ³prio PokÃ©mon pode pressentir quando uma catÃ¡strofe natural se aproxima.', 'Absol.png'),
('Wynaut', 360, 'Psiquico', 'Hoenn', 1, 'Wynaut, o PokÃ©mon brilhante. Em noites de luar estes PokÃ©mons se reÃºnem para brincar. Eles usam as orelhas como mÃ£os. A expressÃ£o que possuem Ã© sempre alegre. Quando estÃ£o com raiva, ficam batendo seus rabos no chÃ£o.', 'Wynaut.png'),
('Snorunt', 361, 'Gelo', 'Hoenn', 1, 'Snorunt, o PokÃ©mon chapÃ©u de neve. Vivem em regiÃµes gÃ©lidas. Nas estaÃ§Ãµes sem neve, como primavera e verÃ£o, ele sai para viver entre estalactites e estalagmites de cavernas congeladas. Ã‰ dito que ele traz prosperidade aos lugares que visita. ', 'Snorunt.png'),
('Glalie', 362, 'Gelo', 'Hoenn', 42, 'Glalie, o PokÃ©mon rosto, e a forma evoluÃ­da do Snorunt. Um Glalie tem o poder de congelar instantaneamente a umidade na atmosfera. Uma nuvem brilhante de cristais de gelo se forma em torno de seu corpo congelado. Sua armadura de gelo nunca derrete. ', 'Glalie.png'),
('Spheal', 363, 'Gelo', 'Hoenn', 1, 'Spheal, o PokÃ©mon aplauso. Spheal se locomove bem mais rÃ¡pido rolando o corpo do que andando. Sua pele felpuda o protege do frio. Quando um grupo desses PokÃ©mons estÃ¡ comendo, comeÃ§am a bater palmas para demonstrar satisfaÃ§Ã£o.', 'Spheal.png'),
('Sealeo', 364, 'Gelo', 'Hoenn', 32, 'Sealeo, o PokÃ©mon bola rolante, e a forma evoluÃ­da de Spheal. Gosta muito de equilibrar objetos com o focinho. Enquanto faz isso, fareja o objeto para examinÃ¡-lo. De vez em quando ele brinca girando um Spheal na sua cabeÃ§a.  ', 'Sealeo.png'),
('Walrein', 365, 'Gelo', 'Hoenn', 44, 'Walrein, o PokÃ©mon quebra gelo, e a forma evoluÃ­da de Sealeo. As presas maciÃ§amente desenvolvidas de Walrein sÃ£o capazes de quebrar um bloco de gelo de dez toneladas com apenas um golpe. Sua espessa camada de gordura permite que aguente temperaturas abaixo de zero. ', 'Walrein.png'),
('Clamperl', 366, 'Agua', 'Hoenn', 1, 'Clamperl, o PokÃ©mon pÃ©rola. O casco resistente de Clamperl nÃ£o funciona apenas como proteÃ§Ã£o como tambÃ©m pode ser usado para agarrar seus adversÃ¡rios. Ele consegue fabricar uma pÃ©rola magnÃ­fica uma vez na vida. ', 'Clamperl.png'),
('Huntail', 367, 'Agua', 'Hoenn', 1, 'Huntail, o PokÃ©mon mar profundo, e uma das formas evoluÃ­das de Clamperl atravÃ©s de troca. A existÃªncia deste PokÃ©mon passou despercebida por um longo tempo pelo fato de viver nas profundezas do mar. A ponta de seu rabo tem a aparÃªncia de um pequeno peixe, com olhos que acendem.', 'Huntail.png'),
('Gorebyss', 368, 'Agua', 'Hoenn', 1, 'Gorebyss, o PokÃ©mon mar do sul, e uma das formas evoluÃ­das de Clamperl atravÃ©s de troca. Embora possua uma aparÃªncia elegante ao nadar, pode ser muito cruel. Ele enfia sua boca fina no corpo de suas presas e suga seus nutrientes como uma seringa. Seu corpo fica com cores mais vivas apÃ³s aliment', 'Gorebyss.png'),
('Relicanth', 369, 'Agua', 'Hoenn', 1, 'Relicanth, o PokÃ©mon longevidade. Este PokÃ©mon existe na Terra hÃ¡ cem milhÃµes de anos. Ele resiste Ã  enorme pressÃ£o de Ã¡gua das profundezas do oceano. Seu corpo Ã© coberto de escamas que sÃ£o duras como rochas.', 'Relicanth.png'),
('Luvdisc', 370, 'Agua', 'Hoenn', 1, 'Luvdisc, o PokÃ©mon cupido. O corpo em forma de coraÃ§Ã£o deste PokÃ©mon Ã© um sÃ­mbolo de amor e romance. Diz-se que casais que encontram esse PokÃ©mon terÃ£o um bom relacionamento durante toda a vida. ', 'Luvdisc.png'),
('Bagon', 371, 'DragÃ£o', 'Hoenn', 1, 'Bagon, o PokÃ©mon cabeÃ§a de rocha. Com a pretensÃ£o de voar, Bagon atira-se de penhascos. Depois de muitas tentativas frustradas, sua cabeÃ§a desenvolveu-se dura para resistir aos impactos de suas quedas. ', 'Bagon.png'),
('Shelgon', 372, 'DragÃ£o', 'Hoenn', 30, 'Shelgon, o PokÃ©mon resistÃªncia, e a forma evoluÃ­da de Bagon. Seu corpo estÃ¡ encoberto por um caso duro que serve como um escudo. LÃ¡ dentro, suas cÃ©lulas estÃ£o passando por uma transformaÃ§Ã£o. Possui movimentos vagarosos devido ao casco pesado.', 'Shelgon.png'),
('Salamence', 373, 'DragÃ£o', 'Hoenn', 50, 'Salamence, o PokÃ©mon dragÃ£o, e a forma evoluÃ­da de Shelgon. O enorme desejo de querer voar fez esse PokÃ©mon sofrer uma mutaÃ§Ã£o para ganhar um par de asas. Se enfurecido, perde a razÃ£o e sai descontroladamente destruindo tudo.', 'Salamence.png'),
('Beldum', 374, 'Psiquico', 'Hoenn', 1, 'Beldum, o PokÃ©mon bola de ferro. Em vez de sangue, uma poderosa forÃ§a magnÃ©tica corre pelo corpo deste PokÃ©mon. Ele consegue se manter flutuando no ar repelindo o magnetismo natural da Terra.', 'Beldum.png'),
('Metang', 375, 'Psiquico', 'Hoenn', 20, 'Metang, o PokÃ©mon garra de ferro, e a forma evoluÃ­da de Beldum.  Um Metang Ã© formado pela fusÃ£o de dois Beldum. Os cÃ©rebros dos Beldum se unem por um sistema nervoso magnÃ©tico. Isso permite que Metang tenha vastos poderes psicocinÃ©ticos. Dobrando os braÃ§os para trÃ¡s, consegue viajar em alta', 'Metang.png'),
('Metagross', 376, 'Psiquico', 'Hoenn', 45, 'Metagross, o PokÃ©mon perna de ferro, e a forma evoluÃ­da de Metang. Resultando da uniÃ£o de dois Metang, este PokÃ©mon possui quatro cÃ©rebros. Por esta razÃ£o, dizem que Ã© capaz de pensar mais rÃ¡pido do que um super computador. Ele abocanha suas presas com a boca de seu estÃ´mago. ', 'Metagross.png'),
('Regirock', 377, 'Pedra', 'Hoenn', 1, 'Regirock, o PokÃ©mon LendÃ¡rio pico de rocha. Ã‰ inteiramente composto de rochas sem nenhum sinal de cÃ©rebro ou coraÃ§Ã£o. Ã‰ um mistÃ©rio atÃ© mesmo para os cientistas modernos. Dizem que quando seu corpo Ã© danificado, consegue reparÃ¡-lo usando pedras. ', 'Regirock.png'),
('Regice', 378, 'Gelo', 'Hoenn', 1, 'Regice, o PokÃ©mon LendÃ¡rio icebergue. Diz-se ter um corpo feito do gelo do polo sul. Cientistas acreditam que Ã© o mesmo gelo que havia na Era do Gelo. Seu corpo nÃ£o pode ser derretido, mesmo por magma fervente. Consegue manipular ares frios de atÃ© -200ÂºC.', 'Regice.png'),
('Registeel', 379, 'Normal', 'Hoenn', 1, 'Registeel, o PokÃ©mon LendÃ¡rio de ferro. Estudos dizem que seu corpo Ã© oco e mais duro que qualquer tipo de metal. Ele endureceu devido Ã  pressÃ£o subterrÃ¢nea ao longo de dezenas de milhares de anos. E nÃ£o Ã© sÃ³ duro, como tambÃ©m muito flexÃ­vel. ', 'Registeel.png'),
('Latias', 380, 'DragÃ£o', 'Hoenn', 1, 'Latias, o PokÃ©mon LendÃ¡rio da eternidade. Pode comunicar-se atravÃ©s de telepatia. Sua pelugem especial Ã© capaz de refletir a luz, deixando-a invisÃ­vel. Raramente de mostra diante de humanos. A figura de seu peito Ã© da mesma cor de Latios. ', 'Latias.png'),
('Latios', 381, 'DragÃ£o', 'Hoenn', 1, 'Latios, o PokÃ©mon LendÃ¡rio da eternidade. Um PokÃ©mon muito inteligente. Dobrando suas asas para trÃ¡s, Ã© capaz de voar mais rÃ¡pido que aviÃµes a jato. Possui a habilidade de visÃ£o compartilhada, permitindo qualquer um ver algo que viu ou estÃ¡ vendo, ainda que esteja distante. ', 'Latios.png'),
('Kyogre', 382, 'Agua', 'Hoenn', 1, 'Kyogre, o PokÃ©mon LendÃ¡rio do mar. Diz a lenda que ele foi o responsÃ¡vel por expandir os mares causando chuvas torrenciais e fortes tsunamis. Ã‰ o salvador de povoados que sofriam com fortes secas. ', 'Kyogre.png'),
('Groudon', 383, 'Terrestre', 'Hoenn', 1, 'Groudon, o PokÃ©mon LendÃ¡rio da terra. Diz a lenda que ele foi o responsÃ¡vel por expandir os continentes causando erupÃ§Ãµes e fortes raios de sol. Ã‰ o salvador de povoados que sofriam com enormes inundaÃ§Ãµes. ', 'Groudon.png'),
('Rayquaza', 384, 'Voador', 'Hoenn', 1, 'Rayquaza, o PokÃ©mon LendÃ¡rio do cÃ©u. Vive voando acima das nuvens, na camada de ozÃ´nio. Por esta razÃ£o, demorou para ser descoberto. Dizem que desceu Ã  Terra a fim de parar a batalha titÃ¢nica de Kyogre e Groudon quando causavam um cataclismo com seus poderes. ', 'Rayquaza.png'),
('Jirachi', 385, 'Psiquico', 'Hoenn', 1, 'Jirachi, o PokÃ©mon LendÃ¡rio do desejo. A cada mil anos, Jirachi desperta de seu sono durante uma semana. Quem escreveu desejos nas notas de sua cabeÃ§a irÃ¡ tÃª-los realizados quando Jirachi despertar. Enquanto estÃ¡ adormecido, um casco duro e cristalino envolve seu corpo para protegÃª-lo de inim', 'Jirachi.png'),
('Deoxys', 386, 'Psiquico', 'Hoenn', 1, 'Deoxyx, o PokÃ©mon DNA LendÃ¡rio. Um vÃ­rus alienÃ­gena que caiu na terra em um meteoro passou por uma mutaÃ§Ã£o de DNA para se tornar este PokÃ©mon. Ele aparece onde auroras sÃ£o vistas. O Ã³rgÃ£o cristalino em seu peito Ã© aparentemente o seu cÃ©rebro. AlÃ©m da sua forma normal, possui mais trÃªs ', 'Deoxys.png');

-- --------------------------------------------------------

--
-- Table structure for table `Pokemon_center`
--

CREATE TABLE IF NOT EXISTS `Pokemon_center` (
  `local_pokecenter` varchar(50) COLLATE utf8_bin NOT NULL DEFAULT '',
  PRIMARY KEY (`local_pokecenter`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `Pokemon_mart`
--

CREATE TABLE IF NOT EXISTS `Pokemon_mart` (
  `local_pokemart` varchar(50) COLLATE utf8_bin NOT NULL DEFAULT '',
  `qtd_itens` int(11) DEFAULT NULL,
  PRIMARY KEY (`local_pokemart`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `Pokemon_mart`
--

INSERT INTO `Pokemon_mart` (`local_pokemart`, `qtd_itens`) VALUES
('Fuchsia', 20);

-- --------------------------------------------------------

--
-- Table structure for table `Treinador`
--

CREATE TABLE IF NOT EXISTS `Treinador` (
  `id_treinador` int(11) NOT NULL AUTO_INCREMENT,
  `nome_treinador` varchar(70) COLLATE utf8_bin NOT NULL,
  `num_insignas` int(11) NOT NULL,
  `qtd_pokemons_capturados` int(11) DEFAULT NULL,
  `qtd_pokemons_vistos` int(11) DEFAULT NULL,
  `sexo` char(1) COLLATE utf8_bin DEFAULT NULL,
  `login` varchar(20) COLLATE utf8_bin NOT NULL,
  `senha` varchar(200) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`id_treinador`),
  UNIQUE KEY `login` (`login`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=24 ;

--
-- Dumping data for table `Treinador`
--

INSERT INTO `Treinador` (`id_treinador`, `nome_treinador`, `num_insignas`, `qtd_pokemons_capturados`, `qtd_pokemons_vistos`, `sexo`, `login`, `senha`) VALUES
(23, 'Professor', 10, 0, 386, 'M', 'professor', '3ba558c4435917c0e60e8a4a99a38d96');

-- --------------------------------------------------------

--
-- Table structure for table `Treinador_item`
--

CREATE TABLE IF NOT EXISTS `Treinador_item` (
  `id_treinador` int(11) NOT NULL DEFAULT '0',
  `codigo_item` int(11) NOT NULL DEFAULT '0',
  `quantidade` int(11) NOT NULL,
  PRIMARY KEY (`id_treinador`,`codigo_item`),
  KEY `codigo_item` (`codigo_item`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `Treinador_possui_Pokemon`
--

CREATE TABLE IF NOT EXISTS `Treinador_possui_Pokemon` (
  `id_pokemon` int(11) NOT NULL AUTO_INCREMENT,
  `id_treinador` int(11) DEFAULT NULL,
  `numero_pokemon` int(11) DEFAULT NULL,
  `apelido` varchar(20) COLLATE utf8_bin DEFAULT NULL,
  `level` int(11) NOT NULL,
  PRIMARY KEY (`id_pokemon`),
  KEY `id_treinador` (`id_treinador`),
  KEY `numero_pokemon` (`numero_pokemon`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=29 ;

-- --------------------------------------------------------

--
-- Table structure for table `Treinador_treina_Pokemon`
--

CREATE TABLE IF NOT EXISTS `Treinador_treina_Pokemon` (
  `id_pokemon` int(11) NOT NULL DEFAULT '0',
  `nome_ataque` varchar(15) COLLATE utf8_bin NOT NULL DEFAULT '',
  `level_aprendido` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_pokemon`,`nome_ataque`),
  KEY `nome_ataque` (`nome_ataque`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Pokemart_vende_item`
--
ALTER TABLE `Pokemart_vende_item`
  ADD CONSTRAINT `Pokemart_vende_item_ibfk_1` FOREIGN KEY (`local_pokemart`) REFERENCES `Pokemon_mart` (`local_pokemart`),
  ADD CONSTRAINT `Pokemart_vende_item_ibfk_2` FOREIGN KEY (`codigo_item`) REFERENCES `Item` (`codigo_item`);

--
-- Constraints for table `Treinador_item`
--
ALTER TABLE `Treinador_item`
  ADD CONSTRAINT `Treinador_item_ibfk_1` FOREIGN KEY (`id_treinador`) REFERENCES `Treinador` (`id_treinador`),
  ADD CONSTRAINT `Treinador_item_ibfk_2` FOREIGN KEY (`codigo_item`) REFERENCES `Item` (`codigo_item`);

--
-- Constraints for table `Treinador_possui_Pokemon`
--
ALTER TABLE `Treinador_possui_Pokemon`
  ADD CONSTRAINT `Treinador_possui_Pokemon_ibfk_1` FOREIGN KEY (`id_treinador`) REFERENCES `Treinador` (`id_treinador`),
  ADD CONSTRAINT `Treinador_possui_Pokemon_ibfk_2` FOREIGN KEY (`numero_pokemon`) REFERENCES `Pokemon` (`numero_pokemon`);

--
-- Constraints for table `Treinador_treina_Pokemon`
--
ALTER TABLE `Treinador_treina_Pokemon`
  ADD CONSTRAINT `Treinador_treina_Pokemon_ibfk_1` FOREIGN KEY (`nome_ataque`) REFERENCES `Ataque` (`nome_ataque`),
  ADD CONSTRAINT `Treinador_treina_Pokemon_ibfk_2` FOREIGN KEY (`id_pokemon`) REFERENCES `Treinador_possui_Pokemon` (`id_pokemon`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
