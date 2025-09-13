/*Uma empresa comercial possui um programa para controle das receitas e despesas em seus 10 projetos.
Os projetos são numerados de 0 até 9. Faça um programa C que controle a entrada e saída de recursos dos projetos. 
O programa deverá ler um conjunto de informações contendo: Número do projeto, valor, 
tipo despesa ("R" - Receita e "D" - Despesa). O programa termina quando o valor do código do projeto for igual a -1.
Sabe-se que Receita deve ser somada ao saldo do projeto e despesa subtraída do saldo do projeto. Ao final do programa, 
imprirmir o saldo final de cada projeto.

Dica: Usar uma estrutura do tipo vetor para controlar os saldos dos projetos. 
Usar o conceito de struct para agrupar as informações lidas.*/



typedef struct projeto{
	int numero;
	int valor;
	char* tipo;
	
}projeto;

int main(){
	
	
	
	
	return 0;
}
