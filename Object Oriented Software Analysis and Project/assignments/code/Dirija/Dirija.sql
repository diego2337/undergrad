-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 05, 2014 at 03:39 PM
-- Server version: 5.5.38
-- PHP Version: 5.3.10-1ubuntu3.13

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `Dirija`
--

-- --------------------------------------------------------

--
-- Table structure for table `Aluguel`
--

CREATE TABLE IF NOT EXISTS `Aluguel` (
  `cod_identificador` int(11) NOT NULL AUTO_INCREMENT,
  `CPF_cliente` varchar(11) DEFAULT NULL,
  `CPF_funcionario` varchar(11) DEFAULT NULL,
  `chassi_veiculo` varchar(17) DEFAULT NULL,
  `valor_total` double DEFAULT NULL,
  `forma_pagamento` varchar(50) DEFAULT NULL,
  `situacao_servico` varchar(100) DEFAULT NULL,
  `data_retirada` date DEFAULT NULL,
  `data_devolucao` date DEFAULT NULL,
  `localRetirada` varchar(100) DEFAULT NULL,
  `estabelecimentoDevolucao` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_identificador`),
  KEY `CPF_funcionario` (`CPF_funcionario`),
  KEY `chassi_veiculo` (`chassi_veiculo`),
  KEY `Aluguel_ibfk_1` (`CPF_cliente`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=20 ;

--
-- Dumping data for table `Aluguel`
--

INSERT INTO `Aluguel` (`cod_identificador`, `CPF_cliente`, `CPF_funcionario`, `chassi_veiculo`, `valor_total`, `forma_pagamento`, `situacao_servico`, `data_retirada`, `data_devolucao`, `localRetirada`, `estabelecimentoDevolucao`) VALUES
(11, '55555555555', NULL, 'IXGT0RF2SPU1VFZTD', 510, '1', 'Finalizado', '2014-02-28', '2014-03-03', 'Dirija Campo Grande', 'Campo Grande'),
(13, '22222222222', NULL, 'V77QWMF4JX5RKR6TA', 3000, '1', 'Finalizado', '2014-10-12', '2014-11-11', 'Dirija Campo Grande', 'Campo Grande'),
(15, '55555555555', NULL, 'IXGT0RF2SPU1VFZTD', 3570, '1', 'Em andamento', '2014-10-22', '2014-11-12', 'Dirija Campo Grande', 'Campo Grande'),
(17, '22222222222', NULL, 'MX0I77UFR58KX0CB1', 1100, '1', 'Finalizado', '2014-11-11', '2014-11-22', 'Dirija Campo Grande', 'Campo Grande');

-- --------------------------------------------------------

--
-- Table structure for table `Cliente`
--

CREATE TABLE IF NOT EXISTS `Cliente` (
  `CPF` varchar(11) NOT NULL,
  `nome_inicial` varchar(20) DEFAULT NULL,
  `nome_meio` varchar(20) DEFAULT NULL,
  `nome_final` varchar(20) DEFAULT NULL,
  `tel` varchar(10) DEFAULT NULL,
  `profissao` varchar(50) DEFAULT NULL,
  `rua` varchar(50) DEFAULT NULL,
  `bairro` varchar(50) DEFAULT NULL,
  `numero_endereco` int(11) DEFAULT NULL,
  `CEP` varchar(11) DEFAULT NULL,
  `cidade` varchar(50) DEFAULT NULL,
  `data_nasc` date DEFAULT NULL,
  `validade_carteira` date DEFAULT NULL,
  `data_cadastro` date DEFAULT NULL,
  PRIMARY KEY (`CPF`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Cliente`
--

INSERT INTO `Cliente` (`CPF`, `nome_inicial`, `nome_meio`, `nome_final`, `tel`, `profissao`, `rua`, `bairro`, `numero_endereco`, `CEP`, `cidade`, `data_nasc`, `validade_carteira`, `data_cadastro`) VALUES
('22222222222', 'Jainor', 'Souza', 'da Cunha', '17379576', 'Estudante', 'Rua perto do Rádio Clube', 'Rita Vieira', 72, '11111111', 'Campo Grande', '1994-11-01', '2015-04-22', '2014-10-22'),
('33333333333', 'Diego', 'Silva', 'Cintra', '10584936', 'Estudante', 'Rua perto do beco', 'Monte Castelo', 98, '44444444', 'Campo Grande', '1994-10-05', '2015-04-20', '2014-10-22'),
('44444444444', 'Nícolas', 'Roque', 'dos Santos', '26782954', 'Estudante', 'Rua do HU', 'Vila universitária', 24, '33333333', 'Campo Grande', '1994-04-01', '2015-02-22', '2014-10-22'),
('55555555555', 'Ricardo', 'Masao', 'Kondo', '96493782', 'Estudante', 'Rua das Panelas', 'Vila universitária', 34, '22222222', 'Campo Grande', '1992-06-10', '2015-09-10', '2014-10-22'),
('66666666666', 'Wellington', 'Oliveira', 'dos Santos', '9999999', 'Estudante', 'Rua Américo Carlos da Costa', 'São Bento', 301, '8888888', 'Campo Grande', '1992-05-22', '2015-10-22', '2014-10-22');

-- --------------------------------------------------------

--
-- Table structure for table `Estabelecimento`
--

CREATE TABLE IF NOT EXISTS `Estabelecimento` (
  `num_estabelecimento` int(11) NOT NULL AUTO_INCREMENT,
  `CPF_funcionario` varchar(11) DEFAULT NULL,
  `cidade` varchar(50) DEFAULT NULL,
  `rua` varchar(50) DEFAULT NULL,
  `bairro` varchar(50) DEFAULT NULL,
  `numero_endereco` int(11) DEFAULT NULL,
  `CEP` varchar(11) DEFAULT NULL,
  `horario_atendimento` varchar(200) DEFAULT NULL,
  `tel` varchar(10) DEFAULT NULL,
  `numero_veiculos_servico` int(11) DEFAULT NULL,
  PRIMARY KEY (`num_estabelecimento`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `Estabelecimento`
--

INSERT INTO `Estabelecimento` (`num_estabelecimento`, `CPF_funcionario`, `cidade`, `rua`, `bairro`, `numero_endereco`, `CEP`, `horario_atendimento`, `tel`, `numero_veiculos_servico`) VALUES
(1, '99999999999', 'Campo Grande', 'Avenida afonso pena', 'Centro', 4000, '77777777', '7:00 às 17:00', '55555555', 15);

-- --------------------------------------------------------

--
-- Table structure for table `Funcionario`
--

CREATE TABLE IF NOT EXISTS `Funcionario` (
  `CPF` varchar(11) NOT NULL,
  `num_estabelecimento` int(11) DEFAULT NULL,
  `nome_inicial` varchar(20) DEFAULT NULL,
  `nome_meio` varchar(20) DEFAULT NULL,
  `nome_final` varchar(20) DEFAULT NULL,
  `cidade` varchar(50) DEFAULT NULL,
  `rua` varchar(50) DEFAULT NULL,
  `bairro` varchar(50) DEFAULT NULL,
  `numero_endereco` int(11) DEFAULT NULL,
  `data_nasc` date DEFAULT NULL,
  `data_contratacao` date DEFAULT NULL,
  `tel` varchar(10) DEFAULT NULL,
  `salario` float DEFAULT NULL,
  `sexo` char(1) DEFAULT NULL,
  `horas_extras` int(11) DEFAULT NULL,
  PRIMARY KEY (`CPF`),
  KEY `num_estabelecimento` (`num_estabelecimento`),
  KEY `sexo` (`sexo`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Funcionario`
--

INSERT INTO `Funcionario` (`CPF`, `num_estabelecimento`, `nome_inicial`, `nome_meio`, `nome_final`, `cidade`, `rua`, `bairro`, `numero_endereco`, `data_nasc`, `data_contratacao`, `tel`, `salario`, `sexo`, `horas_extras`) VALUES
('22222222222', 1, 'Diego', 'Silva', 'Cintra', 'Campo Grande', 'Avenida Afonso Pena', 'Centro', 4000, '1994-10-13', '2014-10-22', '66443355', 3000, 'M', 15);

-- --------------------------------------------------------

--
-- Table structure for table `Reserva`
--

CREATE TABLE IF NOT EXISTS `Reserva` (
  `cod_identificador` int(11) NOT NULL AUTO_INCREMENT,
  `chassi_veiculo` varchar(17) DEFAULT NULL,
  `CPF_funcionario` varchar(11) DEFAULT NULL,
  `CPF_cliente` varchar(11) DEFAULT NULL,
  `valor_total` double DEFAULT NULL,
  `forma_pagamento` varchar(50) DEFAULT NULL,
  `situacao_servico` varchar(100) DEFAULT NULL,
  `data_retirada` date DEFAULT NULL,
  `data_devolucao` date DEFAULT NULL,
  `tempo_retirada` int(11) DEFAULT NULL,
  `localRetirada` varchar(100) DEFAULT NULL,
  `estabelecimentoDevolucao` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_identificador`),
  KEY `CPF_funcionario` (`CPF_funcionario`),
  KEY `chassi_veiculo` (`chassi_veiculo`),
  KEY `Reserva_ibfk_3` (`CPF_cliente`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `Reserva`
--

INSERT INTO `Reserva` (`cod_identificador`, `chassi_veiculo`, `CPF_funcionario`, `CPF_cliente`, `valor_total`, `forma_pagamento`, `situacao_servico`, `data_retirada`, `data_devolucao`, `tempo_retirada`, `localRetirada`, `estabelecimentoDevolucao`) VALUES
(1, '1D4GP25B03B100775', NULL, '44444444444', 3500, '1', 'Aberta', '2014-11-05', '2014-11-22', 5, NULL, NULL),
(2, 'V77QWMF4JX5RKR6TA', NULL, '22222222222', 1700, '1', 'Aberta', '2014-11-14', '2014-11-17', 10, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `Veiculo`
--

CREATE TABLE IF NOT EXISTS `Veiculo` (
  `chassi` varchar(17) NOT NULL,
  `num_estabelecimento` int(11) DEFAULT NULL,
  `apolice` varchar(17) DEFAULT NULL,
  `placa` varchar(8) DEFAULT NULL,
  `modelo` varchar(50) DEFAULT NULL,
  `fabricante` varchar(50) DEFAULT NULL,
  `data_aquisicao` date DEFAULT NULL,
  `estado_tanque` varchar(100) DEFAULT NULL,
  `estado_geral` varchar(255) DEFAULT NULL,
  `acessorios` varchar(255) DEFAULT NULL,
  `preco_dia` float DEFAULT NULL,
  `preco_horas_extras` float DEFAULT NULL,
  `situacao` char(1) DEFAULT 'L',
  PRIMARY KEY (`chassi`),
  KEY `num_estabelecimento` (`num_estabelecimento`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `Veiculo`
--

INSERT INTO `Veiculo` (`chassi`, `num_estabelecimento`, `apolice`, `placa`, `modelo`, `fabricante`, `data_aquisicao`, `estado_tanque`, `estado_geral`, `acessorios`, `preco_dia`, `preco_horas_extras`, `situacao`) VALUES
('1D4GP25B03B100775', 1, '5770013052418617', 'HHH8888', 'Gol', 'VW', '2014-02-01', 'Cheio', 'Bom', 'Neon, rebaixado, som', 150, 90, 'O'),
('IXGT0RF2SPU1VFZTD', 1, '2213540437414949', 'JJJ9999', 'Fit', 'Honda', '2014-02-01', 'Vazio', 'Bom', 'Som, câmbio automático', 170, 80, 'O'),
('MX0I77UFR58KX0CB1', 1, '2010041970778642', 'GGG4444', 'Palio', 'Fiat', '2014-02-01', 'Cheio', 'Ruim', 'som', 100, 60, 'O'),
('V77QWMF4JX5RKR6TA', 1, '8650530770226128', 'MMM0000', 'Mille', 'Fiat', '2014-02-01', 'Vazio', 'Ruim', '', 100, 50, 'O');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Aluguel`
--
ALTER TABLE `Aluguel`
  ADD CONSTRAINT `Aluguel_ibfk_1` FOREIGN KEY (`CPF_cliente`) REFERENCES `Cliente` (`CPF`),
  ADD CONSTRAINT `Aluguel_ibfk_2` FOREIGN KEY (`CPF_funcionario`) REFERENCES `Funcionario` (`CPF`),
  ADD CONSTRAINT `Aluguel_ibfk_3` FOREIGN KEY (`chassi_veiculo`) REFERENCES `Veiculo` (`chassi`);

--
-- Constraints for table `Funcionario`
--
ALTER TABLE `Funcionario`
  ADD CONSTRAINT `Funcionario_ibfk_1` FOREIGN KEY (`num_estabelecimento`) REFERENCES `Estabelecimento` (`num_estabelecimento`);

--
-- Constraints for table `Reserva`
--
ALTER TABLE `Reserva`
  ADD CONSTRAINT `Reserva_ibfk_1` FOREIGN KEY (`CPF_funcionario`) REFERENCES `Funcionario` (`CPF`),
  ADD CONSTRAINT `Reserva_ibfk_2` FOREIGN KEY (`chassi_veiculo`) REFERENCES `Veiculo` (`chassi`),
  ADD CONSTRAINT `Reserva_ibfk_3` FOREIGN KEY (`CPF_cliente`) REFERENCES `Cliente` (`CPF`);

--
-- Constraints for table `Veiculo`
--
ALTER TABLE `Veiculo`
  ADD CONSTRAINT `Veiculo_ibfk_1` FOREIGN KEY (`num_estabelecimento`) REFERENCES `Estabelecimento` (`num_estabelecimento`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
