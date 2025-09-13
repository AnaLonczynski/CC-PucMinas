
function botaoCadastrarOnClick() {
	const cpnjInputValue = document.getElementById("cnpj-input").value;
	const enderecoInputValue = document.getElementById("endereco-input").value;
	const telefoneInputValue = document.getElementById("telefone-input").value;
	const emailInputValue = document.getElementById("email-input").value;
	const nomeInputValue = document.getElementById("nome-input").value;
	const senhaInputValue = document.getElementById("senha-input").value;
	const confirmarSenhaInputValue = document.getElementById("confirmar-senha-input").value;
	const logoInputValue = document.getElementById("input-logo").value;
	const HistoriaInputValue = document.getElementById("historia-input").value;

	let ONGdados = localStorage.getItem('DadosONG');

	if (!ONGdados) {
		ONGdados = [];
	} else {
		// Caso contrário, faz o parse do JSON existente para um array
		ONGdados = JSON.parse(ONGdados);
	

	if (senhaInputValue != confirmarSenhaInputValue) {
		document.getElementById("confirmar-senha-msg-erro").style.display = "block";
	} else {
		document.getElementById("confirmar-senha-msg-erro").style.display = "none";

		const objetoResultado = {
				nome: nomeInputValue,
				cnpj: cpnjInputValue,
				endereco: enderecoInputValue,
				telefone: telefoneInputValue,
				email: emailInputValue,
				senha: senhaInputValue,
				logo: logoInputValue,
				historia: HistoriaInputValue
		}
		// Armazena o JSON atualizado no localStorage
		localStorage.setItem('DadosONG', JSON.stringify(objetoResultado));
		alert ("Cadatro efetuado com sucesso!");
		console.log(objetoResultado);
	}
}
}

/*function AC_botaoCadastrarOnClick() {
    const cpnjInputValue = document.getElementById("cnpj-input").value;
    const enderecoInputValue = document.getElementById("endereco-input").value;
    const telefoneInputValue = document.getElementById("telefone-input").value;
    const emailInputValue = document.getElementById("email-input").value;
    const nomeInputValue = document.getElementById("nome-input").value;
    const senhaInputValue = document.getElementById("senha-input").value;
    const confirmarSenhaInputValue = document.getElementById("confirmar-senha-input").value;
    const logoInputValue = document.getElementById("logo-input").value;

    if (senhaInputValue != confirmarSenhaInputValue) {
        document.getElementById("confirmar-senha-msg-erro").style.display = "block";
    } else {
        document.getElementById("confirmar-senha-msg-erro").style.display = "none";

        const objetoResultado = {
            ong: {
                nome: nomeInputValue,
                cnpj: cpnjInputValue,
                endereco: enderecoInputValue,
                telefone: telefoneInputValue,
                email: emailInputValue,
                senha: senhaInputValue,
                logo: logoInputValue
            }
        }
        console.log(objetoResultado)
    }
}
  ]*/