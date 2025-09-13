// Erro.hpp
#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

/**
 * Classe para tratar erro.
 */
class Erro
{
private:
	int erro;
	
public:
	/**
	 * Destrutor.
	 */
	~Erro() {}
	
	/**
	 * Construtor padrao.
	 */
	Erro() : erro(0) {}
	
	/**
	 * Constante da classe.
	 */
	static const std::string NO_ERROR;
	
	/**
	 * Funcao para obter o codigo de erro.
	 * @return codigo de erro guardado
	 */
	int getErro() const
	{
		return erro;
	}
	
	/**
	 * Funcao para testar se ha' erro.
	 * @return true, se houver; false, caso contrario
	 */
	bool hasError() const
	{
		return erro != 0;
	}
	
	/**
	 * Funcao para obter mensagem
	 * relativa ao código de erro.
	 * @return mensagem sobre o erro
	 */
	virtual std::string getErroMsg() const
	{
		return "";
	}
	
protected:
	/**
	 * Metodo para estabelecer novo codigo de erro.
	 * @param codigo a ser guardado
	 */
	void setErro(int codigo)
	{
		erro = codigo;
	}
};

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro.";

#endif // _ERRO_H_

