/*
Contato.hpp - v0.0 - 30 / 05 / 2024
Author: Ana Clara Lonczynski
*/
// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
// outras dependencias
void pause ( std::string text )
{
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )

#include "Erro.hpp"
// ---------------------------------------------- definicao de classe
/**
* Classe para tratar contatos, derivada da classe Erro.
*/

class Contato : public Erro
{
	/**
	 * atributos privados.
	 */
private:
	string nome;
	string fone;
	string fone2;
	string *fones;
	int n;
	/**
	 * definicoes publicas.
	 */
public:
	
	/**
	 * Destrutor.
	 */
	~Contato ( )
	{ }
	
	
	/**
	 * Construtor padrao.
	 */
	Contato ( )
	{
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais vazios
		nome = "";
		fone = "";
	} // end constructor (padrao)
	
	// ----------------------------------- metodos para acesso
	
	
	/**
	 * Metodo para atribuir nome.
	 * @param nome a ser atribuido
	 */
	void setNome ( std::string nome )
	{
		if ( nome.empty ( ) )
			setErro ( 1 ); // nome invalido
		else
		this->nome = nome;
	} // end setNome ( )
	
	
	/**
	 * Metodo para atribuir telefone.
	 * @param fone a ser atribuido
	 */
	void setFone ( std::string fone )
	{
		if ( fone.empty ( ) )
			setErro ( 2 ); // fone invalido
		else
		this->fone = fone;
	} // end setFone ( )
	
	void setFone2 ( std::string fone )
	{
		if ( fone.empty ( ) )
			setErro ( 2 ); // fone invalido
		else
			this->fone2 = fone2;
	} // end setFone ( )
	
	
	/**
	 * Funcao para obter nome.
	 * @return nome armazenado
	 */
	std::string getNome ( )
	{
		return ( this->nome );
	} // end getNome ( )
	
	
	/**
	 * Funcao para obter fone.
	 * @return fone armazenado
	 */
	std::string getFone ( )
	{
		return ( this->fone );
	} // end getFone ( )

	/**
	 * Funcao para obter fone.
	 * @return fone armazenado
	 */
	std::string getFone2 ( )
	{
		return ( this->fone2 );
	} // end getFone ( )
	
	
	/**
	 * Funcao para obter dados de uma pessoa.
	 * @return dados de uma pessoa
	 */
	std::string toString ( )
	{
		return ( "{ "+getNome( )+", "+getFone( )+" }" );
	} // end toString ( )
	
	/*variacao*/
	std::string toString2 ( )
	{
		return ( "{ "+getNome( )+", "+getFone( )+" , "+getFone2( )+"}" );
	}
	
	
	void readFromFile ( string filename )
	{ 
		//definir dados
		ifstream afile;
		int qnt = 0;
		string name = " ";
		//abrir arquivo
		afile.open ( filename );
		//verificar tamanho
		afile >> qnt;
		//verificar nome
		afile >> name;
		//atribuir nome
		setNome ( name );
		//verificar numeros
		string *phone = new string[qnt - 1]; // Alocação dinâmica do array
		
		for(int i = 0; i < qnt - 1; i++)
		{
			afile >> phone[i];
			
		}
		
		afile.close ( );
		
		setsize ( qnt - 1 );
		setFone ( *phone );
		
	}
	
	string writeNameToFile ( string filename, string nome){
		
		int length = nome.length();
		
		ofstream afile; // output file
		afile.open ( filename );
		
		afile << length <<endl;
		
		for ( int x = 0; x < length; x=x+1 )
		{
			afile << nome[ x ] << endl;
			cout << x <<":" << nome[x]<<endl;
		} 
		
		afile.close ( );
		return filename;
	}
	
	void writeToFile ( string fileName , int n )
	{ 
		//definir dados
		ofstream afile;
		afile.open ( fileName );
		
		//colocar tamanho
		afile << n << endl;
		//colocar o nome da pessoa no arquivo
		afile << nome << endl;
		
		
		for (int i = 0; i < n - 1; i++)
		{
			
			afile << fones[i] << endl;
			
		}
		
		afile.close ( );
		
	}
	
	bool isPhone ( )
	{
		string teste = getFone( );
		bool verificar = true;
		int i = 0;
		if(teste.length() == 12 )
		{
			while (i < 12 && verificar)
			{
				if( (teste[i] >= '0' && teste[i] <= '9') || teste[i] == '-' )
				{ 
					if (teste[7] != '-')
					{
						verificar = false;
					}
				}
				else
				{
					verificar = false;
				}
				i++;
			}
			
		}
		else 
		{
			verificar = false;
		}
		
		return (  verificar );
	}
	void removeFone ( int position )
	{
		if ( position < 0 || position > n )
			setErro ( 2 ); // fone invalido
		else
			fones[position] = " ";
		
		
	}
	
	void changeFone ( string fone , int position )
	{
		if ( position < 0 || position > n )
			setErro ( 2 ); // fone invalido
		else
			setFone ( fone );
		if ( isPhone ( )  )
			fones[position]=fone;
		else 
			fones[position]= "0";
		
	} 

	void telefonevalido (string Fone){
		
		int tamanho = Fone.length();
		
		for(int i=0;i < tamanho;i++){
			if(!(Fone[i]== '-' || !(Fone[i] < '0' && Fone[i] < '9'))){
				cout << "ERRO // Telefone invalido" << endl;
				break;
			}
		}
	}
	
	/*---------- SETSIZE */
	void setsize (int size)
	{ 
		if ( size < 0 || size > 10)
			setErro ( 3 );
		else
			n = size;
	}
	
	int getsize ()
	{ 
		return(this->n);
	}
	void printfones ( )
	{
		
		for(int i = 0; i < n; i++)
		{
			if (fones[i] == "0" )
				cout << "O telefone " << i+1 << " e invalido!" << endl;
			else
			{    
				cout << i << " : " << fones[i] << endl;
			}
		}
	}
	
	/**
	 * Construtor alternativo.
	 * @param nome_inicial a ser atribuido
	 * @param fone_inicial a ser atribuido
	 */
	Contato ( std::string nome_inicial, std::string fone_inicial )
	{
		setErro ( 0 ); // nenhum erro, ainda
		// atribuir valores iniciais
		nome = nome_inicial;
		fone = fone_inicial;
	} // end constructor (alternativo)
	/**
	 * indicar a existencia de erro.
	 */
	bool hasErro ( )
	{
		return ( getErro( ) != 0 );
	} // end hasErro ( )
	
	
	/**
	 * Construtor alternativo baseado em copia.
	 */
	Contato ( Contato const & another )
	{
		// atribuir valores iniciais por copia
		setErro ( 0 ); // copiar erro
		setNome ( another.nome ); // copiar nome
		setFone ( another.fone ); // copiar fone
	} // end constructor (alternativo)

}; // fim da classe Contato

using ref_Contato = Contato*; // similar a typedef Contato* ref_Contato;

#endif
