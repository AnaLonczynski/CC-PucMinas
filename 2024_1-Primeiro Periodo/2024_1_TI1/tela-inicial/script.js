//CNPJ
{
function obterCNPJ() {
    // Recupera o objeto JSON do localStorage
    const pessoaJSON = localStorage.getItem("DadosONG");
    console.log(pessoaJSON);
    // Verifica se o objeto JSON existe no localStorage
    if (pessoaJSON) {
        // Converte o JSON de volta para um objeto JavaScript
        const pessoa = JSON.parse(pessoaJSON);

        // Retorna o nome do objeto
        if (pessoa.cnpj) {
            return pessoa.cnpj;
        } else {
            return "Nome não encontrado";
        }
    } else {
        // Caso o objeto JSON não exista, retorna uma string padrão
        return "/ERRO/";
    }
}

function mostrarCNPJ() {
    // Obtém o elemento <span> pelo id
    var elementoCNPJ = document.getElementById("CNPJONG");
    // Define o conteúdo do elemento <span> com o resultado da função obterNome
    elementoCNPJ.innerHTML= obterCNPJ();
}

// Chama a função mostrarNome quando o script for carregado
document.addEventListener("DOMContentLoaded", mostrarCNPJ);
}
//Nome 
{
function obternome() {
    
    const pessoaJSON = localStorage.getItem("DadosONG");
    console.log(pessoaJSON);
    
    if (pessoaJSON) {
        // Converte o JSON de volta para um objeto JavaScript
        const pessoa = JSON.parse(pessoaJSON);

        // Retorna o nome do objeto
        if (pessoa.nome) {
            return pessoa.nome;
        } else {
            return "Nome não encontrado";
        }
    } else {
        return "/ERRO/";
    }
}

function mostrarnome() {
    var elementoCNPJ = document.getElementById("nomeONG");
    elementoCNPJ.innerHTML= obternome();
}

// Chama a função mostrarNome quando o script for carregado
document.addEventListener("DOMContentLoaded", mostrarnome);
}
//Endereco
{
function obterendereco() {
    const pessoaJSON = localStorage.getItem("DadosONG");
    console.log(pessoaJSON);
    if (pessoaJSON) {
        const pessoa = JSON.parse(pessoaJSON);
        if (pessoa.endereco) {
            return pessoa.endereco;
        } else {
            return "Nome não encontrado";
        }
    } else {
        return "/ERRO/";
    }
}

function mostrarendereco() {
    var elementoCNPJ = document.getElementById("enderecoONG");
    elementoCNPJ.innerHTML= obterendereco();
}

document.addEventListener("DOMContentLoaded", mostrarendereco);
}
//Telefone
{
function obtertelefone() {
    // Recupera o objeto JSON do localStorage
    const pessoaJSON = localStorage.getItem("DadosONG");
    console.log(pessoaJSON);
    if (pessoaJSON) {
        const pessoa = JSON.parse(pessoaJSON);
            return pessoa.telefone;
    } else {
        // Caso o objeto JSON não exista, retorna uma string padrão
        return "/ERRO/";
    }
}

function mostrartelefone() {
    // Obtém o elemento <span> pelo id
    var elementoCNPJ = document.getElementById("telefoneONG");
    elementoCNPJ.innerHTML= obtertelefone();
}
document.addEventListener("DOMContentLoaded", mostrartelefone);
}
//email
{
function obteremail() {
    // Recupera o objeto JSON do localStorage
    const pessoaJSON = localStorage.getItem("DadosONG");
    console.log(pessoaJSON);
    if (pessoaJSON) {
        const pessoa = JSON.parse(pessoaJSON);
         return pessoa.email;
    } else {
        // Caso o objeto JSON não exista, retorna uma string padrão
        return "/ERRO/";
    }
}

function mostraremaileimagem() {
    var elementoCNPJ = document.getElementById("emailONG");
    elementoCNPJ.innerHTML= obteremail();

    var elementoImagem = document.getElementById("imagem");
    // Define o atributo src do elemento <img> com o resultado da função obterImagem
    var imagemSrc = obterImagem();
    if (imagemSrc !== "Imagem não encontrada" && imagemSrc !== "Erro ao converter JSON") {
        elementoImagem.src = imagemSrc;
    } else {
        // Caso a imagem não seja encontrada ou haja erro, remove a imagem do display
        elementoImagem.style.display = "none";
    }
}
document.addEventListener("DOMContentLoaded", mostraremaileimagem);
}
function obterImagem() {
    const pessoaJSON = localStorage.getItem("DadosONG");

    // Verifica se a string JSON existe no localStorage
    if (pessoaJSON) {
        try {
            const pessoa = JSON.parse(pessoaJSON);
            return pessoa.logo;
        } catch (error) {
            // Em caso de erro na conversão do JSON, retorna uma mensagem de erro
            console.error("Erro ao converter JSON:", error);
            return "Erro ao converter JSON";
        }
    } else {
        // Caso a string JSON não exista, retorna uma string padrão
        console.warn("Nenhum JSON encontrado no localStorage");
        return "Imagem não encontrada";
    }
}
//história
{
    function obterhistoria() {
        // Recupera o objeto JSON do localStorage
        const pessoaJSON = localStorage.getItem("DadosONG");
        console.log(pessoaJSON);
        if (pessoaJSON) {
            const pessoa = JSON.parse(pessoaJSON);
                return pessoa.historia;
        } else {
            // Caso o objeto JSON não exista, retorna uma string padrão
            return "/ERRO/";
        }
    }
    
    function mostrarhistoria() {
        // Obtém o elemento <span> pelo id
        var elementoCNPJ = document.getElementById("historiaONG");
        elementoCNPJ.innerHTML= obterhistoria();
    }
    document.addEventListener("DOMContentLoaded", mostrarhistoria);
}