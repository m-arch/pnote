DROP SCHEMA pnote cascade;
CREATE SCHEMA pnote;
CREATE DATABASE pnote;
\connect pnote;
CREATE TABLE pnote.user (
       ID CHAR(64) PRIMARY KEY NOT NULL,
       First_Name CHAR(64),
       Last_Name CHAR(64),
       Contact_Number VARCHAR,
       Other_Contact VARCHAR,
       Notes TEXT);

CREATE TABLE pnote.user_car(
       ID SERIAL PRIMARY KEY NOT NULL,
       VIN CHAR(17) UNIQUE NOT NULL,
       Plate_Number CHAR(10),
       user_ID CHAR(64) references pnote.user(id),
       CAR_COLOR CHAR(100),
       CAR_BRAND CHAR(100),
       CAR_BODY_MODEL CHAR(100),
       CAR_MOTOR CHAR(100),
       CAR_YEAR INT);

CREATE TABLE pnote.car_revision(
       ID CHAR(64) PRIMARY KEY NOT NULL,
       CAR_ID CHAR(64) references pnote.user_car(id),
       SCAN CHAR(64) NOT NULL,
       ON_DATE DATE NOT NULL);
