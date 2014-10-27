DROP SCHEMA pnote cascade;
CREATE SCHEMA pnote;
CREATE DATABASE pnote;
\connect pnote;
CREATE TABLE pnote.user (
       ID CHAR(64) PRIMARY KEY NOT NULL,
       First_Name CHAR(64) NOT NULL,
       Last_Name CHAR(64) NOT NULL,
       Contact_Number VARCHAR NOT NULL,
       Other_Contact VARCHAR,
       Notes TEXT);

CREATE TABLE pnote.user_car(
       ID CHAR(64) PRIMARY KEY NOT NULL,
       user_ID CHAR(64) references pnote.user(id),
       CAR_PHOTO CHAR(100) NOT NULL,
       CAR_BRAND CHAR(100) NOT NULL,
       CAR_BODY_MODEL CHAR(100) NOT NULL,
       CAR_MOTOR CHAR(100),
       CAR_YEAR INT);

CREATE TABLE pnote.car_reminders(
       ID CHAR(64) PRIMARY KEY NOT NULL,
       CAR_ID CHAR(64) references pnote.user_car(id),
       DUE_DATE DATE,
       INFO TEXT);
