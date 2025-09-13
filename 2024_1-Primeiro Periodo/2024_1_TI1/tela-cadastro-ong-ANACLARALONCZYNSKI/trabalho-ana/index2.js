
const apiUrl = 'https://17888d69-e5c6-41a4-a17c-98ca11856607-00-f4ikhqwcowcp.janeway.replit.dev/ong';

async function AC_botaoCadastrarOnClick() {
	const cpnjInputValue = document.getElementById("cnpj-input").value;
	const enderecoInputValue = document.getElementById("endereco-input").value;
	const telefoneInputValue = document.getElementById("telefone-input").value;
	const emailInputValue = document.getElementById("email-input").value;
	const nomeInputValue = document.getElementById("nome-input").value;
	const senhaInputValue = document.getElementById("senha-input").value;
	const confirmarSenhaInputValue = document.getElementById("confirmar-senha-input").value;
	const logoInputValue = document.getElementById("logo-input").value;
	const id = 0;

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

	updateONG (id, objetoResultado);
}

async function updateONG (id, objetoResultado) {
	//  tentar fazer a chamada
		try
		{
		//  definir a chamada HTTP do JSON Server
			const response = await fetch (`${apiUrl}/${id}`, {
				method: 'PUT',
				headers: {
					'Content-Type': 'application/json',
				},
				body: JSON.stringify(objetoResultado),
			});
		//  mostrar resultado
			displayMessage("Sucesso ao editar comentario!");
		}
	//  chamada de erro
		catch (error)
		{
			console.error("Error:", error);
			displayMessage("Erro ao editar comentario (JSON Server indisponível).");
		}
	} // end updateComment ( )
