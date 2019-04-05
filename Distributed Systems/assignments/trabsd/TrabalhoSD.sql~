-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jun 23, 2015 at 11:03 PM
-- Server version: 5.5.43-0ubuntu0.14.04.1
-- PHP Version: 5.5.9-1ubuntu4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `TrabalhoSD`
--
-- --------------------------------------------------------

--
-- Table structure for table `Usuario`
--

CREATE DATABASE IF NOT EXISTS `TrabalhoSD`;
USE `TrabalhoSD`;

CREATE TABLE IF NOT EXISTS `Usuario` (
  `u_id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `email` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `senha` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `bucket` varchar(200) COLLATE utf8_bin DEFAULT NULL,
  `size` double DEFAULT NULL,
  PRIMARY KEY (`u_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=20 ;

--
-- Dumping data for table `Usuario`
--

INSERT INTO `Usuario` (`u_id`, `login`, `email`, `senha`, `bucket`, `size`) VALUES
(1, 'superuser', NULL, '202cb962ac59075b964b07152d234b70', 'superuser558565611f9833.96946985', 0),
(18, 'toddy2', NULL, '202cb962ac59075b964b07152d234b70', 'toddy2558740846d1db2.50932502', 0),
(19, 'final', NULL, 'caf1a3dfb505ffed0d024130f58c5cfa', 'final558996f5bfb341.70487988', 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
