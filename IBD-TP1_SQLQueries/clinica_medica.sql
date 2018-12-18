CREATE DATABASE  IF NOT EXISTS `clinica_medica` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `clinica_medica`;
-- MySQL dump 10.13  Distrib 5.5.61, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: clinica_medica
-- ------------------------------------------------------
-- Server version	5.5.61-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `AgendaMedica`
--

DROP TABLE IF EXISTS `AgendaMedica`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `AgendaMedica` (
  `diaDaSemana` varchar(3) NOT NULL,
  `horario` varchar(5) NOT NULL,
  `idMedico` int(11) NOT NULL,
  PRIMARY KEY (`idMedico`,`horario`,`diaDaSemana`),
  KEY `fk_AgendaMedica_1_idx` (`idMedico`),
  CONSTRAINT `fk_AgendaMedica_1` FOREIGN KEY (`idMedico`) REFERENCES `Medico` (`crm`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `AgendaMedica`
--

LOCK TABLES `AgendaMedica` WRITE;
/*!40000 ALTER TABLE `AgendaMedica` DISABLE KEYS */;
INSERT INTO `AgendaMedica` VALUES ('wed','10:00',15124),('wed','10:30',15124),('fri','11:00',15124),('mon','12:00',15124),('thu','12:30',15124),('tue','12:30',15124),('wed','14:00',15124),('tue','16:30',15124),('wed','17:00',15124),('mon','19:30',15124),('fri','12:30',15267),('mon','14:00',15267),('tue','14:00',15267),('thu','14:30',15267),('thu','16:00',15267),('mon','16:30',15267),('thu','17:00',15267),('fri','17:30',15267),('tue','10:30',15720),('tue','13:30',15720),('mon','15:30',15720),('fri','16:30',15720),('thu','18:00',15720),('wed','18:30',15720),('wed','08:00',16153),('tue','09:30',16153),('fri','10:30',16153),('fri','12:30',16153),('tue','12:00',16988),('wed','19:00',16988),('thu','13:30',17248),('fri','16:00',17248),('thu','16:30',17248),('tue','20:00',17248),('fri','09:30',19790),('wed','10:30',19790),('wed','17:30',19790),('thu','08:00',19999),('fri','09:00',19999),('thu','12:30',19999),('mon','13:00',19999),('tue','13:00',19999),('tue','15:00',19999),('tue','16:00',19999),('tue','20:00',19999),('fri','11:30',25886),('thu','12:00',25886),('thu','15:30',25886),('thu','17:00',25886),('thu','15:00',25951),('thu','19:30',25951),('wed','08:30',27144),('mon','09:30',27343),('fri','15:00',27343),('thu','19:30',27343),('thu','12:00',27488),('fri','14:00',27488),('wed','15:00',27488),('fri','16:30',27488),('fri','17:30',27488),('wed','08:30',27887),('wed','09:00',27887),('wed','10:00',27887),('mon','13:00',27887),('tue','13:00',27887),('fri','13:30',27887),('fri','15:30',27887),('thu','11:30',28482),('mon','12:00',28482),('tue','13:00',28482),('thu','15:00',28482),('thu','15:30',28482),('tue','17:30',28482),('tue','08:00',28903),('fri','09:30',28903),('tue','09:30',28903),('wed','11:00',28903),('wed','17:00',28903),('mon','18:00',28903),('tue','19:30',28903),('fri','20:00',28903),('wed','09:00',29027),('thu','11:00',29027),('fri','15:30',29027),('wed','18:00',29027),('thu','13:00',29409),('tue','14:00',29409),('wed','14:30',29409),('thu','16:30',29409),('mon','20:00',29409),('tue','12:00',29897),('fri','13:30',29897),('wed','13:30',29897),('thu','14:00',29897),('wed','18:30',29897),('fri','19:00',29897);
/*!40000 ALTER TABLE `AgendaMedica` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Consulta`
--

DROP TABLE IF EXISTS `Consulta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Consulta` (
  `idConsulta` int(11) NOT NULL AUTO_INCREMENT,
  `crmMedico` int(11) NOT NULL,
  `idPaciente` int(11) NOT NULL,
  `data_agendamento` date DEFAULT NULL,
  `queixa_paciente` varchar(45) DEFAULT NULL,
  `parecer_medico` varchar(45) DEFAULT NULL,
  `status` char(1) DEFAULT NULL,
  PRIMARY KEY (`idConsulta`),
  KEY `fk_Consulta_1_idx` (`crmMedico`),
  KEY `fk_Consulta_2_idx` (`idPaciente`),
  CONSTRAINT `fk_Consulta_1` FOREIGN KEY (`crmMedico`) REFERENCES `Medico` (`crm`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Consulta_2` FOREIGN KEY (`idPaciente`) REFERENCES `Paciente` (`idPaciente`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=201 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Consulta`
--

LOCK TABLES `Consulta` WRITE;
/*!40000 ALTER TABLE `Consulta` DISABLE KEYS */;
INSERT INTO `Consulta` VALUES (1,29409,7584,'2019-08-31','Aliquam erat','ligula. Aliquam erat volutpat.','C'),(2,29409,8553,'2017-05-20','a',' aliquet vel',''),(3,25951,7574,'2009-03-13','aliquam adipiscing lacus. Ut nec urna et arcu','lacinia orci',''),(4,27343,7573,'2012-01-31','sodales.','ac libero nec ligula consectetuer rhoncus. Nu',''),(5,19999,7517,'2016-11-11','quam','imperdiet ornare. In faucibus. Morbi vehicula','O'),(6,15975,7557,'2016-09-22','odio tristique pharetra. Quisque ac libero ne','vehicula risus. Nulla eget metus eu erat semp','C'),(7,29027,7514,'2013-01-19','Phasellus elit pede',' malesuada vel',''),(8,15720,7511,'2012-02-18','aliquet odio. Etiam ligula','nunc. In at pede. Cras vulputate velit','O'),(9,16988,8533,'2011-04-30','consequat enim diam vel arcu. Curabitur ut od','euismod mauris eu elit. Nulla facilisi.','C'),(10,27887,7541,'2019-07-17','pellentesque a','','i'),(11,29409,8549,'2010-03-22','erat vel pede blandit congue.','dictum ultricies','C'),(12,28482,7590,'2009-06-18','mus. Proin vel nisl. Quisque fringilla euismo','massa. Integer vitae nibh. Donec est mauris',''),(13,28903,7585,'2011-12-11','Cras sed leo. Cras vehicula aliquet libero.','magna. Suspendisse tristique','O'),(14,19999,7526,'2016-12-23','Lorem ipsum dolor sit amet',' consectetuer adipiscing elit.','v'),(15,16988,8521,'2015-04-21','blandit mattis. Cras eget nisi dictum augue m','fringilla',''),(16,29409,7516,'2016-01-03','fames ac turpis egestas. Aliquam fringilla cu','amet ante. Vivamus non lorem vitae','C'),(17,17248,7517,'2015-11-12','et',' rutrum eu',''),(18,29027,8596,'2008-02-18','Aliquam fringilla cursus','sit amet ante. Vivamus non','O'),(19,15975,8526,'2010-02-11','facilisis. Suspendisse commodo tincidunt nibh','metus. In nec orci. Donec nibh. Quisque nonum','O'),(20,15124,7519,'2014-08-02','pharetra. Nam ac nulla.','ipsum primis in faucibus orci luctus et ultri','O'),(21,15720,8527,'2010-12-25','ligula consectetuer rhoncus. Nullam velit dui',' semper et',''),(22,28903,7558,'2005-11-06','risus. Quisque libero lacus',' varius et',''),(23,27488,7509,'2006-09-28','gravida mauris ut mi. Duis risus odio',' auctor vitae',''),(24,29409,7560,'2007-04-25','aliquet odio. Etiam ligula','lacinia at',''),(25,27887,8563,'2010-03-28','libero et tristique','nonummy ut',''),(26,28482,8516,'2006-07-13','magna et ipsum cursus vestibulum.','adipiscing',''),(27,27343,8529,'2018-08-23','hendrerit','interdum. Curabitur dictum. Phasellus in feli','C'),(28,17248,7541,'2006-03-16','Suspendisse eleifend. Cras sed leo. Cras vehi','ornare. In faucibus. Morbi vehicula. Pellente','C'),(29,15267,8540,'2012-06-12','scelerisque neque','neque. In ornare sagittis felis. Donec tempor',''),(30,15975,7580,'2015-11-28','rhoncus. Proin nisl sem',' consequat nec',''),(31,15124,8591,'2007-08-20','nec enim. Nunc ut erat. Sed','lacus vestibulum lorem',''),(32,29409,7512,'2010-01-20','velit eget laoreet posuere',' enim nisl elementum','m'),(33,16153,8532,'2017-06-19','Vestibulum ante ipsum primis in faucibus orci','sapien imperdiet ornare. In faucibus. Morbi v','O'),(34,15720,8506,'2012-09-14','dui augue eu tellus. Phasellus elit pede',' malesuada vel',''),(35,19999,7591,'2008-03-16','mauris','amet luctus vulputate',''),(36,25951,7579,'2016-09-17','vel',' faucibus id',''),(37,25886,7590,'2009-06-20','nec urna et arcu imperdiet ullamcorper. Duis ','Cras dolor dolor',''),(38,15267,7501,'2005-10-03','viverra. Donec tempus',' lorem fringilla ornare placerat',''),(39,29027,8564,'2017-11-03','Donec nibh.','vel quam dignissim pharetra. Nam ac nulla. In','O'),(40,25886,7532,'2010-01-31','imperdiet non','','d'),(41,27488,7597,'2015-05-13','In nec','Duis a mi fringilla mi lacinia mattis. Intege','O'),(42,15267,7521,'2016-07-25','porttitor tellus non magna. Nam ligula elit',' pretium et',''),(43,28903,8549,'2014-10-24','magna. Ut tincidunt orci quis lectus.','non arcu. Vivamus sit amet risus. Donec egest','C'),(44,16153,7513,'2016-11-08','Phasellus','justo. Proin non massa non','C'),(45,27488,7571,'2012-12-27','vitae','','p'),(46,15975,8508,'2013-09-11','ipsum cursus vestibulum. Mauris magna. Duis d','in consequat enim','O'),(47,16153,7504,'2008-03-11','semper',' dui lectus rutrum urna',''),(48,28903,7524,'2007-01-22','neque. Nullam nisl. Maecenas malesuada fringi','Suspendisse sed dolor. Fusce mi lorem',''),(49,16153,8504,'2006-03-03','commodo ipsum. Suspendisse non leo. Vivamus','natoque penatibus','C'),(50,19999,7583,'2009-06-30','Suspendisse ac metus vitae velit','semper rutrum.','C'),(51,19790,8586,'2010-12-02','Nullam scelerisque neque sed sem egestas blan','','v'),(52,16988,8529,'2007-03-15','euismod','enim. Sed nulla ante',''),(53,16153,8529,'2014-11-19','dui. Fusce aliquam',' enim nec','e'),(54,27887,8587,'2015-11-01','metus. In lorem. Donec elementum',' lorem ut','s'),(55,16153,8544,'2012-05-24','mauris sagittis placerat.','lorem','O'),(56,27488,8541,'2016-04-02','ipsum','elit. Nulla facilisi. Sed','O'),(57,29027,7519,'2010-01-11','placerat. Cras dictum ultricies ligula. Nulla','','v'),(58,29027,8550,'2016-09-22','ut erat. Sed nunc est',' mollis non',''),(59,15975,7508,'2015-01-16','non magna. Nam ligula','cubilia Curae',''),(60,25886,7597,'2014-04-07','aliquam eu',' accumsan sed',''),(61,28903,8583,'2013-02-22','a','','v'),(62,15975,7510,'2015-09-11','Cum sociis natoque penatibus et magnis','quis','C'),(63,15975,7540,'2015-07-16','gravida.','Suspendisse ac metus vitae velit egestas laci',''),(64,15124,8598,'2010-10-30','risus quis diam luctus lobortis. Class aptent','nibh. Aliquam ornare',''),(65,29897,7576,'2015-10-26','mauris',' rhoncus id',''),(66,29027,7571,'2009-05-07','Nunc mauris. Morbi non','eu dui. Cum sociis natoque penatibus','O'),(67,16988,7521,'2007-02-28','varius. Nam porttitor scelerisque neque.','non',''),(68,29897,7536,'2014-08-12','lorem',' luctus ut',''),(69,29027,8556,'2014-11-18','non','Duis gravida. Praesent eu nulla at sem molest','O'),(70,16153,7539,'2005-09-26','ac risus. Morbi metus. Vivamus euismod urna. ','hendrerit consectetuer',''),(71,16988,7528,'2011-04-19','tristique','dolor',''),(72,15720,7554,'2009-04-25','semper.','felis purus ac tellus.','O'),(73,29409,8531,'2008-09-29','nulla at sem','non',''),(74,17248,7531,'2005-10-16','molestie tellus. Aenean egestas hendrerit','eu','O'),(75,29409,7510,'2006-07-06','nunc id enim. Curabitur massa.','lacus. Quisque purus sapien',''),(76,27488,8525,'2006-08-05','scelerisque neque. Nullam nisl. Maecenas','metus facilisis lorem tristique','C'),(77,15124,7599,'2009-05-08','vel lectus. Cum sociis natoque penatibus','Aenean','C'),(78,17248,7596,'2018-04-07','auctor. Mauris vel turpis. Aliquam adipiscing','arcu. Vestibulum ante ipsum primis in faucibu','O'),(79,16153,7588,'2005-11-17','et magnis dis parturient','eleifend',''),(80,27488,8586,'2008-09-05','enim. Mauris quis turpis vitae purus gravida ','at',''),(81,29409,8589,'2015-09-16','egestas rhoncus. Proin nisl sem',' consequat nec',''),(82,27144,8575,'2014-08-13','montes',' nascetur ridiculus mus. Aenean eget','v'),(83,25951,7599,'2011-02-28','eleifend vitae',' erat. Vivamus nisi.','A'),(84,15720,8553,'2006-09-09','elit',' a feugiat tellus lorem eu metus. In lorem.','D'),(85,15975,8581,'2014-05-26','nisl sem',' consequat nec',''),(86,15720,8561,'2016-04-30','ipsum. Suspendisse non leo. Vivamus','feugiat tellus lorem eu metus.','C'),(87,17248,7556,'2015-05-15','Proin eget odio. Aliquam vulputate ullamcorpe','Quisque tincidunt pede','O'),(88,27488,7532,'2018-05-18','euismod enim. Etiam gravida molestie arcu. Se','dapibus ligula. Aliquam erat volutpat. Nulla ','C'),(89,29027,8595,'2007-01-22','dolor. Donec fringilla. Donec feugiat','tellus. Phasellus elit pede',''),(90,17248,8516,'2018-08-26','Cum sociis natoque penatibus et magnis dis pa',' nascetur','a'),(91,27488,8592,'2006-08-09','adipiscing',' enim mi','f'),(92,28903,7550,'2005-12-25','mauris eu elit. Nulla facilisi. Sed neque. Se','odio. Aliquam vulputate','O'),(93,29409,7593,'2012-03-10','Proin nisl sem',' consequat nec',''),(94,15720,7547,'2010-11-16','quis accumsan convallis',' ante lectus convallis est',''),(95,17248,7528,'2017-01-27','gravida sit amet',' dapibus id',''),(96,29027,8556,'2018-04-20','ipsum dolor sit amet','','s'),(97,25886,7585,'2015-06-26','tempus non',' lacinia at',''),(98,15267,8504,'2018-10-06','Mauris vel turpis. Aliquam adipiscing loborti','sem mollis dui',''),(99,15720,8532,'2013-11-06','eu',' placerat eget',''),(100,27488,7583,'2006-01-21','imperdiet','erat nonummy ultricies ornare',''),(101,27488,8527,'2017-06-04','diam. Proin dolor. Nulla semper tellus id nun','est ac mattis semper',''),(102,25886,7555,'2010-07-13','enim','purus',''),(103,29027,7562,'2010-03-28','auctor ullamcorper',' nisl arcu iaculis enim',''),(104,16988,7508,'2011-12-11','ipsum dolor sit amet','','m'),(105,15975,7520,'2009-05-18','arcu. Vestibulum ut eros non enim commodo hen','nec',''),(106,16153,8513,'2012-08-10','vel',' convallis in',''),(107,28903,8536,'2008-10-26','et magnis dis parturient montes','','n'),(108,27144,7576,'2015-08-05','sem. Pellentesque ut ipsum ac mi eleifend ege','','s'),(109,29897,7517,'2006-03-21','eu elit.','lorem',''),(110,29409,7593,'2008-02-19','magna. Sed eu','magna. Nam','O'),(111,19790,7541,'2016-03-20','Proin mi. Aliquam gravida','eu augue','O'),(112,19790,8576,'2008-04-05','eget tincidunt dui augue eu tellus.','Morbi quis urna. Nunc quis arcu vel quam dign','C'),(113,19999,8539,'2012-09-05','turpis. In condimentum.','dignissim tempor arcu. Vestibulum','O'),(114,19999,8543,'2005-11-24','Pellentesque ultricies dignissim lacus.','justo faucibus lectus',''),(115,28903,7562,'2019-06-25','vestibulum massa','ipsum. Suspendisse non leo. Vivamus nibh dolo',''),(116,15267,8567,'2019-03-10','dignissim','vitae','O'),(117,27343,8555,'2009-11-02','Lorem ipsum dolor sit amet',' consectetuer adipiscing','e'),(118,19790,7524,'2018-09-14','lobortis','sagittis felis. Donec tempor',''),(119,15975,7526,'2009-11-10','pretium aliquet',' metus urna convallis erat',''),(120,15975,8524,'2014-09-12','Sed nunc est','','q'),(121,27144,7544,'2019-06-10','ipsum','arcu eu odio tristique pharetra. Quisque','C'),(122,19790,7534,'2011-10-22','adipiscing','Aliquam ornare',''),(123,28482,8597,'2009-05-20','malesuada augue','non dui nec urna suscipit nonummy. Fusce ferm','O'),(124,19999,7576,'2011-02-16','enim. Suspendisse aliquet','','p'),(125,27488,7536,'2015-07-07','eget mollis lectus pede et risus. Quisque','augue ac ipsum. Phasellus vitae mauris sit am','C'),(126,15267,8508,'2017-03-22','Maecenas libero','risus. Donec egestas. Aliquam nec enim. Nunc ','O'),(127,28482,8553,'2010-05-10','Donec nibh. Quisque nonummy ipsum non','nec metus facilisis lorem tristique aliquet. ','O'),(128,27144,7527,'2013-11-26','rhoncus. Nullam velit dui','','c'),(129,16988,8561,'2009-03-27','dolor','','l'),(130,27488,7596,'2019-03-02','facilisi. Sed neque. Sed eget lacus. Mauris n','inceptos hymenaeos. Mauris ut quam vel sapien','O'),(131,29409,7586,'2015-08-13','Nunc ut erat. Sed','mauris',''),(132,15267,8526,'2008-04-21','Donec tincidunt. Donec vitae erat vel pede bl','ipsum. Suspendisse non leo. Vivamus nibh dolo',''),(133,15124,8549,'2019-08-10','et netus et malesuada fames ac turpis egestas','hendrerit id',''),(134,29409,8505,'2019-02-15','Integer mollis. Integer','a',''),(135,29897,7525,'2016-07-01','Nulla semper tellus','Duis elementum',''),(136,19790,7510,'2012-05-02','quam. Pellentesque habitant morbi tristique s','lacus vestibulum lorem',''),(137,29409,8526,'2009-06-24','vitae','litora torquent per conubia nostra',''),(138,29409,8586,'2016-11-17','mollis dui',' in sodales','D'),(139,25951,8574,'2011-06-20','eu','consectetuer mauris id sapien. Cras dolor dol',''),(140,19999,7576,'2009-04-11','faucibus id',' libero. Donec consectetuer mauris id','F'),(141,15975,8539,'2016-10-19','Nam ligula elit',' pretium et',''),(142,19790,7503,'2007-11-07','arcu ac orci.','malesuada. Integer','C'),(143,15124,8513,'2017-11-11','nec',' leo. Morbi','m'),(144,19790,8548,'2019-08-02','suscipit nonummy. Fusce fermentum fermentum a','imperdiet','C'),(145,27144,8523,'2017-03-02','felis','','n'),(146,19999,8515,'2011-01-04','turpis. Aliquam adipiscing lobortis','diam. Duis','C'),(147,15267,7525,'2006-10-17','lacus. Ut nec','Phasellus dapibus quam','O'),(148,27144,8542,'2012-07-05','Mauris eu turpis. Nulla aliquet.','semper rutrum. Fusce dolor quam',''),(149,29409,7575,'2018-02-11','faucibus id','','e'),(150,25886,7591,'2012-11-17','vitae diam. Proin dolor. Nulla semper','est',''),(151,27887,8576,'2010-07-28','ac mattis velit justo nec','purus ac','O'),(152,15975,7508,'2019-09-21','amet lorem semper auctor. Mauris vel turpis. ','Vestibulum ut eros non enim commodo hendrerit','C'),(153,15124,7507,'2010-08-30','in faucibus orci','non',''),(154,19999,8574,'2007-12-03','est. Mauris eu','sit amet',''),(155,15267,7522,'2010-11-10','Sed congue','','e'),(156,19790,8522,'2005-10-26','eu eros. Nam consequat dolor vitae dolor.','facilisis facilisis',''),(157,28482,7567,'2014-03-26','parturient montes',' nascetur','r'),(158,27144,7588,'2015-01-17','volutpat ornare',' facilisis eget',''),(159,17248,7577,'2012-12-27','Duis cursus',' diam at pretium','N'),(160,15267,7576,'2017-02-26','Ut tincidunt orci quis lectus. Nullam suscipi','','e'),(161,27887,8564,'2017-03-24','lacus.','tincidunt vehicula','O'),(162,27144,7557,'2009-04-07','semper tellus id nunc interdum feugiat. Sed','Duis gravida. Praesent eu','C'),(163,16988,8566,'2017-02-11','elit. Curabitur sed tortor. Integer aliquam a','ut aliquam iaculis',''),(164,28482,8571,'2010-10-31','netus et malesuada','aliquam adipiscing lacus. Ut','C'),(165,29027,7511,'2011-02-11','egestas. Sed pharetra',' felis eget','n'),(166,15720,8547,'2007-02-26','ligula','mi eleifend egestas. Sed pharetra',''),(167,15124,7503,'2018-04-15','aptent','nibh','O'),(168,27144,8569,'2017-12-25','ac mattis velit justo nec ante. Maecenas','elit',''),(169,17248,7521,'2006-07-29','In','Duis','C'),(170,16988,7568,'2015-02-20','imperdiet non',' vestibulum nec',''),(171,27144,8532,'2011-12-22','rutrum eu',' ultrices sit','a'),(172,16153,7540,'2013-12-29','dolor sit amet',' consectetuer','q'),(173,29409,7584,'2015-03-21','est mauris',' rhoncus id',''),(174,15720,8534,'2015-12-25','ultrices. Duis volutpat','Cras vulputate','C'),(175,15720,8595,'2006-01-05','Quisque tincidunt pede ac','nascetur ridiculus mus.','C'),(176,19790,7517,'2017-01-24','interdum enim non nisi.','diam.','O'),(177,25886,8543,'2014-05-28','tristique ac','','s'),(178,28903,8556,'2016-05-14','suscipit',' est ac facilisis facilisis',''),(179,15720,8561,'2018-05-24','tellus id nunc','nec',''),(180,15124,8589,'2013-06-20','mi. Duis risus odio',' auctor vitae',''),(181,27488,8546,'2006-10-17','blandit viverra. Donec tempus',' lorem fringilla ornare placerat',''),(182,17248,8546,'2006-02-22','vulputate',' posuere vulputate',''),(183,29027,8532,'2006-09-12','ac orci. Ut semper pretium neque. Morbi quis ','cubilia Curae',''),(184,15975,7546,'2015-05-18','mauris sit amet lorem semper auctor.','ornare egestas ligula. Nullam feugiat placera','O'),(185,28482,7501,'2014-06-25','magna. Ut tincidunt orci quis lectus.','nulla. Integer urna.','O'),(186,27144,7544,'2009-02-14','ac','eget mollis lectus pede et risus. Quisque lib','O'),(187,29897,7556,'2009-01-21','ut odio vel est tempor bibendum. Donec','Aliquam auctor',''),(188,17248,7574,'2009-09-08','bibendum ullamcorper. Duis cursus','','u'),(189,19790,7523,'2009-09-06','sit amet diam eu dolor egestas rhoncus. Proin','quis','C'),(190,29027,7594,'2005-09-14','Vestibulum','odio semper','O'),(191,25886,8515,'2012-12-06','neque. Sed','dapibus gravida. Aliquam tincidunt',''),(192,27144,8538,'2014-11-09','placerat',' orci lacus vestibulum lorem',''),(193,19790,8545,'2009-12-30','dapibus gravida. Aliquam tincidunt',' nunc ac mattis','i'),(194,29027,8593,'2016-07-28','Suspendisse aliquet molestie tellus. Aenean e','malesuada malesuada. Integer id magna et ipsu','O'),(195,27488,8527,'2014-12-27','leo. Vivamus nibh','eget',''),(196,25886,7585,'2009-10-12','consequat',' lectus sit amet luctus','n'),(197,15720,8566,'2007-06-09','varius. Nam porttitor scelerisque neque.','ut dolor dapibus gravida. Aliquam tincidunt',''),(198,28903,8531,'2014-12-06','sit amet',' consectetuer adipiscing elit. Curabitur sed ','D'),(199,19999,8519,'2009-12-10','Sed nunc est',' mollis','V'),(200,16153,8548,'2006-09-13','vel quam dignissim pharetra. Nam ac','fermentum fermentum arcu.','C');
/*!40000 ALTER TABLE `Consulta` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Convenio`
--

DROP TABLE IF EXISTS `Convenio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Convenio` (
  `idConvenio` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) DEFAULT NULL,
  `porcentagemCorbetura` double DEFAULT NULL,
  PRIMARY KEY (`idConvenio`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Convenio`
--

LOCK TABLES `Convenio` WRITE;
/*!40000 ALTER TABLE `Convenio` DISABLE KEYS */;
INSERT INTO `Convenio` VALUES (1,'Aliquam LLC',98),(2,'Egestas Ligula Inc.',67),(3,'Dictum Placerat Foundation',37),(4,'Tellus Suspendisse Ltd',12),(5,'Ante Company',57),(6,'Aliquam Fringilla PC',77),(7,'Ultrices Posuere Cubilia Corp.',87),(8,'Massa Suspendisse Eleifend Corporation',14),(9,'Velit Industries',59),(10,'Nec Enim Consulting',95),(11,'Augue Corp.',39),(12,'Quis Pede Limited',33),(13,'Vivamus Rhoncus LLC',85),(14,'Orci Sem Eget Ltd',20),(15,'Sed Ltd',82),(16,'Erat Vel Pede Consulting',54),(17,'Mollis Inc.',69),(18,'Non Lobortis Consulting',96),(19,'Vehicula PC',85),(20,'Sapien Cursus In Consulting',74);
/*!40000 ALTER TABLE `Convenio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Especialidade`
--

DROP TABLE IF EXISTS `Especialidade`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Especialidade` (
  `idEspecialidade` int(11) NOT NULL,
  `nome_especialidade` varchar(45) DEFAULT NULL,
  `preco` double DEFAULT NULL,
  PRIMARY KEY (`idEspecialidade`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Especialidade`
--

LOCK TABLES `Especialidade` WRITE;
/*!40000 ALTER TABLE `Especialidade` DISABLE KEYS */;
INSERT INTO `Especialidade` VALUES (1,' Family medicine',100),(2,' Internal medicine',250),(3,' Hospitalist',400),(4,' Psychiatry',250),(5,' Emergency medicine',400),(6,' Pediatrics',400),(7,' Obstetrics and gynecology',250),(8,' General surgery',700),(9,' Neurology',350),(10,' Nurse practitioner',150),(11,' Orthopedic surgery',500),(12,' Physician assistant',200),(13,' Hematology and/or oncology',250),(14,' Otolaryngology',400),(15,' Cardiology',350),(16,' Gastroenterology',500),(17,' Urology',350),(18,' Pulmonolgy',400),(19,' Dermatology',250),(20,' Geriatrics',350);
/*!40000 ALTER TABLE `Especialidade` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Exame`
--

DROP TABLE IF EXISTS `Exame`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Exame` (
  `idExame` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) DEFAULT NULL,
  `preco` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idExame`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Exame`
--

LOCK TABLES `Exame` WRITE;
/*!40000 ALTER TABLE `Exame` DISABLE KEYS */;
INSERT INTO `Exame` VALUES (1,'Complete Blood Count','45.5'),(2,'Prothrombin Time','55.4'),(3,'Basic Metabolic Panel','90'),(4,'Comprehensive Metabolic Panel','78.5'),(5,'Lipid Panel','60'),(6,'Liver Panel','75'),(7,'Thyroid Stimulating Hormone','89.5'),(8,'Hemoglobin A1C','130'),(9,'Urinalysis','45'),(10,'Cultures','50');
/*!40000 ALTER TABLE `Exame` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Medico`
--

DROP TABLE IF EXISTS `Medico`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Medico` (
  `crm` int(11) NOT NULL,
  `nome` varchar(45) DEFAULT NULL,
  `idEspecialidade` int(11) DEFAULT NULL,
  `celular` varchar(45) DEFAULT NULL,
  `email` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`crm`),
  KEY `fk_Medico_1_idx` (`idEspecialidade`),
  CONSTRAINT `fk_Medico_1` FOREIGN KEY (`idEspecialidade`) REFERENCES `Especialidade` (`idEspecialidade`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Medico`
--

LOCK TABLES `Medico` WRITE;
/*!40000 ALTER TABLE `Medico` DISABLE KEYS */;
INSERT INTO `Medico` VALUES (15124,'Christopher Avery',4,'(039337) 497929','Donec.fringilla.Donec@mipedenonummy.com'),(15267,'Nigel Meadows',1,'(038266) 540832','dapibus@cursusNuncmauris.co.uk'),(15720,'Kyle Snyder',4,'(035347) 143028','odio@ullamcorpereu.net'),(15975,'Hu Boyer',4,'(031719) 802062','nec@aarcu.ca'),(16153,'Allistair Roberts',3,'(031660) 668551','In.ornare.sagittis@Donecestmauris.ca'),(16988,'Chadwick Santiago',10,'(0685) 54035950','posuere@cursus.org'),(17248,'Hyatt Bush',9,'(034238) 538757','ridiculus.mus@ProindolorNulla.edu'),(19790,'Gregory Levine',2,'(038367) 522934','vitae@aliquet.com'),(19999,'Baxter Miranda',3,'(078) 52758349','malesuada.vel.convallis@metus.net'),(25886,'Tara Osborne',2,'(01276) 7065817','Nulla@Duis.edu'),(25951,'Paloma William',3,'(030557) 911674','mollis@convallisligulaDonec.co.uk'),(27144,'Nadine Collier',12,'(033172) 809786','pede.blandit.congue@eunequepellentesque.edu'),(27343,'Beverly Curry',13,'(0406) 88320108','risus.Donec@nasceturridiculusmus.co.uk'),(27488,'Isadora Key',1,'(087) 05784993','neque.sed@volutpatnuncsit.edu'),(27887,'Olivia Osborn',18,'(0868) 18056171','tristique@Intincidunt.edu'),(28482,'Diana Little',12,'(0012) 20370187','eget@aliquetvel.net'),(28903,'Charlotte Foreman',17,'(030164) 184801','scelerisque.lorem@neque.net'),(29027,'Demetria Hurley',4,'(027) 50993326','turpis@eumetusIn.co.uk'),(29409,'Eleanor Rocha',20,'(00268) 4851498','iaculis.enim@pedePraesent.ca'),(29897,'Juliet Fuller',10,'(013) 43991372','sem@velitAliquam.co.uk');
/*!40000 ALTER TABLE `Medico` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Paciente`
--

DROP TABLE IF EXISTS `Paciente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Paciente` (
  `idPaciente` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(45) DEFAULT NULL,
  `data_nascimento` date DEFAULT NULL,
  `idConvenio` int(11) DEFAULT NULL,
  `sexo` char(1) DEFAULT NULL,
  PRIMARY KEY (`idPaciente`),
  KEY `fk_convenio_idx` (`idConvenio`),
  CONSTRAINT `fk_convenio` FOREIGN KEY (`idConvenio`) REFERENCES `Convenio` (`idConvenio`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=8600 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Paciente`
--

LOCK TABLES `Paciente` WRITE;
/*!40000 ALTER TABLE `Paciente` DISABLE KEYS */;
INSERT INTO `Paciente` VALUES (7500,'Akeem Booker','1991-02-14',10,'M'),(7501,'Avram Ewing','1967-09-25',8,'M'),(7502,'Dane Dickerson','1972-06-02',3,'M'),(7503,'Thane Gibbs','1970-01-03',19,'M'),(7504,'Chester Vargas','1981-04-27',6,'M'),(7505,'Gabriel Coffey','1971-12-18',10,'M'),(7506,'Randall Camacho','1976-10-21',7,'M'),(7507,'Jelani Oneil','1994-10-20',14,'M'),(7508,'Ferdinand Park','2003-05-11',14,'M'),(7509,'Oleg Palmer','1983-06-26',20,'M'),(7510,'Phelan Peters','1968-06-13',7,'M'),(7511,'Marshall Bonner','1982-11-05',10,'M'),(7512,'Vaughan Schultz','1996-01-19',16,'M'),(7513,'Paul Wallace','2002-04-03',18,'M'),(7514,'Gavin Rush','1971-11-06',20,'M'),(7515,'Colorado Mckay','2003-03-19',4,'M'),(7516,'Cole Jensen','2005-07-22',6,'M'),(7517,'Clark Flynn','1989-08-25',6,'M'),(7518,'Leroy Little','1975-06-25',8,'M'),(7519,'Nolan Alexander','1992-03-18',10,'M'),(7520,'Abbot Meadows','1999-06-29',18,'M'),(7521,'Nissim Everett','1997-03-29',15,'M'),(7522,'Barclay Tyler','1992-08-05',19,'M'),(7523,'Moses Goff','2005-04-05',12,'M'),(7524,'Mannix Booker','2000-08-21',11,'M'),(7525,'Kennan Davis','2000-03-20',17,'M'),(7526,'Camden Larson','1971-10-03',6,'M'),(7527,'Beck Fleming','1985-12-12',16,'M'),(7528,'Keefe Curry','1970-04-08',8,'M'),(7529,'Griffin Wilkins','1993-05-28',10,'M'),(7530,'Macaulay Sweet','1981-09-26',19,'M'),(7531,'Rashad Barnes','1989-01-04',9,'M'),(7532,'Kibo Haynes','1989-03-31',8,'M'),(7533,'Driscoll Levine','1995-10-09',13,'M'),(7534,'Reece Wolf','2002-02-11',14,'M'),(7535,'Vaughan Mcmillan','2002-03-30',6,'M'),(7536,'Travis Ortega','1970-12-02',7,'M'),(7537,'Hoyt Curry','1986-01-29',7,'M'),(7538,'Conan Merritt','1984-06-30',12,'M'),(7539,'Damian Rollins','1970-04-19',16,'M'),(7540,'Brian Mckenzie','1996-08-05',11,'M'),(7541,'Dustin Hopper','1982-02-27',3,'M'),(7542,'Aristotle Ramos','1995-03-22',11,'M'),(7543,'Ivor Mcclure','1975-01-12',2,'M'),(7544,'Brandon Herring','1992-10-27',4,'M'),(7545,'Roth Serrano','1983-08-30',4,'M'),(7546,'Oleg Howell','1998-01-19',5,'M'),(7547,'Philip Lancaster','2002-01-26',18,'M'),(7548,'Berk Alexander','1995-10-26',16,'M'),(7549,'Brent Wilson','1991-04-29',13,'M'),(7550,'Cairo Melendez','1999-08-05',11,'M'),(7551,'Bradley Evans','1996-01-19',8,'M'),(7552,'Lucius Mcdaniel','1989-02-19',4,'M'),(7553,'Jonas Barker','1999-04-18',1,'M'),(7554,'Raphael Robbins','1995-07-08',19,'M'),(7555,'Timothy Pearson','1996-04-06',16,'M'),(7556,'Nolan Sears','2003-01-10',12,'M'),(7557,'Aaron Preston','2005-05-27',16,'M'),(7558,'Cody Norris','2003-01-28',12,'M'),(7559,'Dustin Manning','1997-10-15',18,'M'),(7560,'Rogan Eaton','1977-04-18',17,'M'),(7561,'Thor Tanner','1990-09-10',8,'M'),(7562,'Silas Tucker','2000-08-13',19,'M'),(7563,'Elmo Rogers','1988-07-11',6,'M'),(7564,'Kermit Barrett','1981-07-04',4,'M'),(7565,'David Burt','1992-02-22',16,'M'),(7566,'Dustin Shelton','1986-12-31',11,'M'),(7567,'Axel Rowe','1986-03-28',19,'M'),(7568,'James Stone','1982-04-02',7,'M'),(7569,'Benjamin Griffin','1970-11-15',3,'M'),(7570,'Howard Forbes','1990-11-19',19,'M'),(7571,'Clayton Oconnor','1993-08-26',3,'M'),(7572,'Wesley Salas','1968-04-10',7,'M'),(7573,'Berk Levy','1988-12-26',5,'M'),(7574,'Troy Barker','1998-11-30',11,'M'),(7575,'Hamish Mcneil','1992-02-13',15,'M'),(7576,'Holmes Bass','1986-07-08',11,'M'),(7577,'Magee Walton','1993-11-22',11,'M'),(7578,'Cole Michael','1981-06-26',17,'M'),(7579,'Harrison Campbell','1970-01-24',11,'M'),(7580,'Mufutau Ward','1968-05-04',20,'M'),(7581,'Ira Hansen','1970-07-11',5,'M'),(7582,'Zane Maddox','1978-07-08',20,'M'),(7583,'Kenneth Bond','2005-01-31',11,'M'),(7584,'Carson Reilly','1990-09-04',2,'M'),(7585,'Paul Joyner','1995-03-01',4,'M'),(7586,'Emerson Alexander','1971-03-15',9,'M'),(7587,'Clayton Wright','1998-12-29',11,'M'),(7588,'Bernard Aguirre','1996-11-02',15,'M'),(7589,'Maxwell Matthews','1997-04-23',2,'M'),(7590,'Demetrius Santana','1980-03-21',20,'M'),(7591,'Brent Huber','1990-05-16',11,'M'),(7592,'Wayne Morrison','1998-01-12',2,'M'),(7593,'Lamar Sawyer','2000-05-05',1,'M'),(7594,'Ishmael Kline','1992-01-17',11,'M'),(7595,'Dale Martin','1982-08-24',2,'M'),(7596,'Callum York','1989-04-14',10,'M'),(7597,'Barrett Barrett','1976-12-03',8,'M'),(7598,'Reuben Mason','1995-04-15',6,'M'),(7599,'Zeph Ayers','1997-08-15',16,'M'),(8500,'Galena Mcfarland','1968-03-26',15,'F'),(8501,'TaShya Bennett','1973-07-26',3,'F'),(8502,'Ifeoma Dean','1992-11-27',17,'F'),(8503,'Evelyn Charles','2003-01-21',11,'F'),(8504,'Germane Pierce','1979-10-08',19,'F'),(8505,'Gisela Kent','1978-11-02',14,'F'),(8506,'Frances Franks','1984-07-19',12,'F'),(8507,'Chantale Craft','1992-10-13',18,'F'),(8508,'Caryn Grant','1996-03-17',11,'F'),(8509,'Lillith Rios','1998-01-10',20,'F'),(8510,'Eugenia Pate','1994-04-18',13,'F'),(8511,'Orli Mcmahon','1977-09-02',4,'F'),(8512,'Amanda Mcbride','2004-10-03',6,'F'),(8513,'Vanna Hubbard','1975-01-19',1,'F'),(8514,'Anika Woodward','1998-01-29',1,'F'),(8515,'Kaitlin Spencer','1985-09-04',19,'F'),(8516,'Nina Ferguson','1969-10-31',15,'F'),(8517,'Chantale Bentley','1986-03-21',16,'F'),(8518,'Hanae Simpson','1979-05-20',13,'F'),(8519,'Aretha Wilder','1971-09-25',3,'F'),(8520,'Tanya Donaldson','1991-02-09',5,'F'),(8521,'Marah Gonzales','1974-09-20',9,'F'),(8522,'Donna Sosa','2002-09-27',17,'F'),(8523,'Hannah Mcdowell','1979-05-10',14,'F'),(8524,'Mari Cotton','1996-03-14',19,'F'),(8525,'Nyssa Perkins','1993-12-17',1,'F'),(8526,'Dara Evans','1981-01-27',4,'F'),(8527,'Idona Mathis','1999-03-16',5,'F'),(8528,'Ava Hunter','1967-11-08',7,'F'),(8529,'Deborah Nielsen','1983-04-30',2,'F'),(8530,'Sara Page','1970-05-29',19,'F'),(8531,'Maia Cobb','1974-05-24',4,'F'),(8532,'Ingrid Rutledge','1997-12-19',7,'F'),(8533,'Charlotte Pate','1971-07-30',11,'F'),(8534,'Uta Marks','1995-01-14',10,'F'),(8535,'Raven Charles','1992-05-30',14,'F'),(8536,'Ariel Cortez','1988-08-17',6,'F'),(8537,'Barbara Huffman','1991-06-23',19,'F'),(8538,'Xaviera Hansen','1979-11-30',4,'F'),(8539,'Keely Curtis','1980-06-09',9,'F'),(8540,'Violet Stark','1992-07-27',5,'F'),(8541,'Roary Rodriquez','1981-08-29',11,'F'),(8542,'Daria Stark','1979-04-24',12,'F'),(8543,'Ursa Forbes','1983-07-30',2,'F'),(8544,'Charissa Avila','1969-08-12',18,'F'),(8545,'Sheila Gregory','1974-01-06',10,'F'),(8546,'Lydia Terrell','1972-09-29',5,'F'),(8547,'Briar Waters','1982-10-16',15,'F'),(8548,'Kaden Randall','1998-04-11',6,'F'),(8549,'Sopoline Hutchinson','1989-04-05',6,'F'),(8550,'Pascale Lott','1997-03-13',6,'F'),(8551,'Echo Bass','1992-03-17',2,'F'),(8552,'Emerald Craft','1999-11-23',9,'F'),(8553,'Natalie Golden','1979-03-30',16,'F'),(8554,'Mary Miller','1980-02-19',11,'F'),(8555,'Susan Page','1996-12-27',14,'F'),(8556,'Charity Castro','1993-05-31',1,'F'),(8557,'Hanae Michael','2002-11-21',11,'F'),(8558,'Ruby Baker','1973-04-06',11,'F'),(8559,'Jael Walton','1986-11-06',5,'F'),(8560,'Serina Garrett','1993-08-08',3,'F'),(8561,'Imani Johnson','2003-10-15',14,'F'),(8562,'Rylee Joyner','1983-09-24',6,'F'),(8563,'Pascale Flynn','2004-07-13',18,'F'),(8564,'Hedwig Robinson','1972-03-01',5,'F'),(8565,'Ashely Gray','1997-01-07',20,'F'),(8566,'Rae Anthony','1991-04-02',4,'F'),(8567,'Clementine Walton','1995-08-18',20,'F'),(8568,'Yoko Workman','1999-03-23',12,'F'),(8569,'Josephine Leon','2005-03-02',19,'F'),(8570,'Jane Mercado','1968-02-18',2,'F'),(8571,'Cathleen Ball','1995-01-19',1,'F'),(8572,'September Carlson','2003-05-27',7,'F'),(8573,'Jorden Woodard','1984-03-23',14,'F'),(8574,'Wynter Leach','1982-04-03',9,'F'),(8575,'Charissa Sampson','1972-09-19',4,'F'),(8576,'Caryn Justice','1999-08-13',7,'F'),(8577,'Dawn Stout','1989-11-12',19,'F'),(8578,'Juliet Cobb','1996-07-07',15,'F'),(8579,'Zoe Green','1971-12-05',14,'F'),(8580,'Michelle Robles','2001-04-30',9,'F'),(8581,'September Obrien','1990-04-24',10,'F'),(8582,'Tanya Holcomb','1989-10-01',4,'F'),(8583,'Heather Hampton','2002-01-04',6,'F'),(8584,'Audrey Freeman','1971-07-09',3,'F'),(8585,'Sierra Stephenson','2002-05-01',20,'F'),(8586,'Deborah Pugh','1973-06-11',9,'F'),(8587,'Nichole Reeves','1968-03-31',3,'F'),(8588,'Xaviera Hebert','1973-04-02',13,'F'),(8589,'Nevada Mcleod','1996-03-05',7,'F'),(8590,'Shannon Odom','1978-05-28',19,'F'),(8591,'Chiquita Patton','1968-05-04',19,'F'),(8592,'Mariam Chavez','1970-07-03',6,'F'),(8593,'Maya Gould','1994-08-28',9,'F'),(8594,'Rhona Gould','1974-07-24',10,'F'),(8595,'Colleen Kirk','1981-03-06',3,'F'),(8596,'Daryl Sosa','1986-08-05',14,'F'),(8597,'Priscilla Skinner','1969-10-08',1,'F'),(8598,'Uma Cash','1998-03-03',11,'F'),(8599,'Tallulah Hoover','1989-01-22',3,'F');
/*!40000 ALTER TABLE `Paciente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PedidoExame`
--

DROP TABLE IF EXISTS `PedidoExame`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PedidoExame` (
  `idPedidoExame` int(11) NOT NULL,
  `idConsulta` int(11) DEFAULT NULL,
  `idExame` int(11) DEFAULT NULL,
  PRIMARY KEY (`idPedidoExame`),
  KEY `fk_PedidoExame_1_idx` (`idConsulta`),
  KEY `fk_PedidoExame_2_idx` (`idExame`),
  CONSTRAINT `fk_PedidoExame_1` FOREIGN KEY (`idConsulta`) REFERENCES `Consulta` (`idConsulta`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_PedidoExame_2` FOREIGN KEY (`idExame`) REFERENCES `Exame` (`idExame`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PedidoExame`
--

LOCK TABLES `PedidoExame` WRITE;
/*!40000 ALTER TABLE `PedidoExame` DISABLE KEYS */;
INSERT INTO `PedidoExame` VALUES (1,15,10),(2,16,8),(3,17,7),(4,18,4),(5,19,3),(6,20,6),(7,21,7),(8,22,4),(9,23,1),(10,24,1),(11,25,8),(12,26,4),(13,27,8),(14,28,7),(15,29,8),(16,30,10),(17,31,2),(18,32,4),(19,33,10),(20,34,4),(21,35,1),(22,36,9),(23,37,10),(24,38,2),(25,39,7),(26,40,10),(27,41,2),(28,42,3),(29,43,9),(30,44,4),(31,45,3),(32,46,6),(33,47,1),(34,48,6),(35,49,4),(36,50,8),(37,51,8),(38,52,10),(39,53,6),(40,54,7),(41,55,4),(42,56,5),(43,57,4),(44,58,1),(45,59,1),(46,60,6),(47,61,6),(48,62,7),(49,63,1),(50,64,8),(51,65,1),(52,66,3),(53,67,4),(54,68,7),(55,69,5),(56,70,1),(57,71,3),(58,72,6),(59,73,9),(60,74,1),(61,75,4),(62,76,1),(63,77,10),(64,78,9),(65,79,10),(66,80,9),(67,81,9),(68,82,1),(69,83,4),(70,84,7),(71,85,7),(72,86,5),(73,87,1),(74,88,7),(75,89,7),(76,90,3),(77,91,7),(78,92,10),(79,93,10),(80,94,9),(81,95,9),(82,96,5),(83,97,3),(84,98,8),(85,99,4),(86,100,8),(87,101,1),(88,102,10),(89,103,9),(90,104,1),(91,105,6),(92,106,8),(93,107,8),(94,108,7),(95,109,6),(96,110,10),(97,111,9),(98,112,2),(99,113,3),(100,114,3);
/*!40000 ALTER TABLE `PedidoExame` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Receita`
--

DROP TABLE IF EXISTS `Receita`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Receita` (
  `idConsulta` int(11) NOT NULL,
  `descricao` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idConsulta`),
  CONSTRAINT `fk_Receita_1` FOREIGN KEY (`idConsulta`) REFERENCES `Consulta` (`idConsulta`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Receita`
--

LOCK TABLES `Receita` WRITE;
/*!40000 ALTER TABLE `Receita` DISABLE KEYS */;
INSERT INTO `Receita` VALUES (87,' Lisinopril (brand names include Prinivil and'),(88,' Generic Prilosec (omeprazole)'),(89,' Generic Synthroid (levothyroxine sodium)'),(90,' Generic Norvasc (amlodipine besylate)'),(91,' Azithromycin (brand names include Z-Pak and '),(92,' Generic Synthroid (levothyroxine sodium)'),(93,' Generic Zocor (simvastatin)'),(94,' Generic Zocor (simvastatin)'),(95,' Azithromycin (brand names include Z-Pak and '),(96,' Generic Zocor (simvastatin)'),(97,' Generic Zocor (simvastatin)'),(98,' Amoxicillin (various brand names)'),(99,' Generic Norvasc (amlodipine besylate)'),(100,' Generic Norvasc (amlodipine besylate)'),(101,' Hydrochlorothiazide (various brand names)'),(102,' Azithromycin (brand names include Z-Pak and '),(103,' Amoxicillin (various brand names)'),(104,' Hydrochlorothiazide (various brand names)'),(105,' Amoxicillin (various brand names)'),(106,' Hydrochlorothiazide (various brand names)'),(107,' Hydrochlorothiazide (various brand names)'),(108,' Azithromycin (brand names include Z-Pak and '),(109,' Azithromycin (brand names include Z-Pak and '),(110,' Generic Glucophage (metformin)'),(111,'Hydrocodone (combined with acetaminophen) -- '),(112,' Hydrochlorothiazide (various brand names)'),(113,'Hydrocodone (combined with acetaminophen) -- '),(114,' Generic Zocor (simvastatin)'),(115,' Lisinopril (brand names include Prinivil and'),(116,' Azithromycin (brand names include Z-Pak and '),(117,' Generic Norvasc (amlodipine besylate)'),(118,'Hydrocodone (combined with acetaminophen) -- '),(119,'Hydrocodone (combined with acetaminophen) -- '),(120,' Generic Zocor (simvastatin)'),(121,' Generic Glucophage (metformin)'),(122,' Amoxicillin (various brand names)'),(123,' Lisinopril (brand names include Prinivil and'),(124,' Hydrochlorothiazide (various brand names)'),(125,' Generic Prilosec (omeprazole)'),(126,' Azithromycin (brand names include Z-Pak and '),(127,'Hydrocodone (combined with acetaminophen) -- '),(128,' Generic Synthroid (levothyroxine sodium)'),(129,'Hydrocodone (combined with acetaminophen) -- '),(130,' Amoxicillin (various brand names)'),(131,' Hydrochlorothiazide (various brand names)'),(132,' Lisinopril (brand names include Prinivil and'),(133,' Generic Zocor (simvastatin)'),(134,' Amoxicillin (various brand names)'),(135,' Amoxicillin (various brand names)'),(136,' Generic Norvasc (amlodipine besylate)'),(137,' Generic Synthroid (levothyroxine sodium)'),(138,' Azithromycin (brand names include Z-Pak and '),(139,'Hydrocodone (combined with acetaminophen) -- '),(140,' Generic Glucophage (metformin)'),(141,' Generic Synthroid (levothyroxine sodium)'),(142,' Amoxicillin (various brand names)'),(143,' Generic Synthroid (levothyroxine sodium)'),(144,' Generic Zocor (simvastatin)'),(145,' Generic Zocor (simvastatin)'),(146,'Hydrocodone (combined with acetaminophen) -- '),(147,' Generic Norvasc (amlodipine besylate)'),(148,' Azithromycin (brand names include Z-Pak and '),(149,' Generic Prilosec (omeprazole)'),(150,' Lisinopril (brand names include Prinivil and'),(151,' Generic Zocor (simvastatin)'),(152,' Generic Glucophage (metformin)'),(153,' Generic Zocor (simvastatin)'),(154,' Generic Prilosec (omeprazole)'),(155,' Generic Synthroid (levothyroxine sodium)'),(156,' Generic Glucophage (metformin)'),(157,' Amoxicillin (various brand names)'),(158,' Generic Prilosec (omeprazole)'),(159,' Amoxicillin (various brand names)'),(160,' Lisinopril (brand names include Prinivil and'),(161,' Generic Zocor (simvastatin)'),(162,' Generic Prilosec (omeprazole)'),(163,' Amoxicillin (various brand names)'),(164,' Azithromycin (brand names include Z-Pak and '),(165,' Generic Glucophage (metformin)'),(166,' Generic Norvasc (amlodipine besylate)'),(167,' Generic Synthroid (levothyroxine sodium)'),(168,' Hydrochlorothiazide (various brand names)'),(169,' Generic Synthroid (levothyroxine sodium)'),(170,' Generic Prilosec (omeprazole)'),(171,' Hydrochlorothiazide (various brand names)'),(172,' Generic Zocor (simvastatin)'),(173,' Generic Glucophage (metformin)'),(174,' Generic Prilosec (omeprazole)'),(175,' Generic Prilosec (omeprazole)'),(176,' Amoxicillin (various brand names)'),(177,' Lisinopril (brand names include Prinivil and'),(178,' Generic Synthroid (levothyroxine sodium)'),(179,' Generic Norvasc (amlodipine besylate)'),(180,' Generic Norvasc (amlodipine besylate)'),(181,' Azithromycin (brand names include Z-Pak and '),(182,' Azithromycin (brand names include Z-Pak and '),(183,' Azithromycin (brand names include Z-Pak and '),(184,' Generic Synthroid (levothyroxine sodium)'),(185,' Generic Prilosec (omeprazole)'),(186,' Lisinopril (brand names include Prinivil and');
/*!40000 ALTER TABLE `Receita` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-09-27 17:38:45
