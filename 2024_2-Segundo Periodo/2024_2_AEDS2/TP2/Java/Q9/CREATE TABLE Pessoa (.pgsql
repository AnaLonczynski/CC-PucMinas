CREATE TABLE Pessoa (
    id serial PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    senha VARCHAR(255) NOT NULL,
);

INSERT INTO Pessoa (nome, email, senha)
VALUES ('João Silva', 'joao.silva@email.com', 'senha123'),
       ('Maria Oliveira', 'maria.oliveira@email.com', 'senha456'),
       ('Carlos Souza', 'carlos.souza@email.com', 'senha789');

SELECT * FROM Pessoa;
