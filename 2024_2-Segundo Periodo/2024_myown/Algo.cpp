#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
#include <cstring>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

void Pergunta_1(){
	
	
	
}
int main (){
	
	char* rep1;
	
	cout<<"================================"<<endl;
	cout<<"De: Ana"<<endl;
	cout<<"Para : Meu amorzinho"<<endl;
	cout<<"================================\n"<<endl;
	
	cout<<"Oi amor! Aqui e' sua namorada Ana! \n Eu tenho umas perguntas pra te fazer, preparado? ( Digite S ou N)"<<endl;
	cin >> rep1;
	
	if(strcmp(rep1, "S")){
		Pergunta_1();
	}else {
		cout<< "\n:(\n"<<endl;
	}
	
	return 0;
}
