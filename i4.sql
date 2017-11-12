DROP DATABASE IF EXISTS song_library;
CREATE DATABASE song_library;
CREATE TABLE songs ( 
song_id int PRIMARY KEY AUTO_INCREMENT,
title varchar(50),
artist varchar(50),
album varchar(50),
genre varchar(50),
year_released YEAR,
length_seconds int);
INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES("Hypnotised","Coldplay","Kaleidoscope","Rock",2017,355);
INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES("Demons","Imagine Dragons","Night Visions","Pop Rock",2013,177);
INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES("Battle Cry","Imagine Dragons","Battle Cry","Rock",2014,152);
INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES("Don't Look Back in Anger","Oasis","(What's the Story) Morning Glory?","Brit Pop",1996,287);
INSERT INTO songs (title, artist, album, genre, year_released, length_seconds) VALUES("Run","Snow Patrol","Final Straw","Alternative Rock",2004,356);
