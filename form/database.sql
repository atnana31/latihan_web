CREATE DATABASE IF NOT EXISTS form_dm;
USE form_dm;

CREATE TABLE IF NOT EXISTS kontak (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    pesan TEXT NOT NULL,
    waktu TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO kontak (nama, email, pesan) VALUES
('Andi', 'andi@example.com', 'Halo, ini pesan pertama.');
