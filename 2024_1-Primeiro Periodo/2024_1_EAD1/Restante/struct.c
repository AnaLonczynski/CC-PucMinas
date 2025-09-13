#include <stdlib.h>
#include <stdio.h>

typedef struct BOLETO{
	int datas[3];
	float valor;
}BOLETO;

int main(){
	
	int dia, mes, ano, i, cont = 0, indice =0;
	float valor;
	
	FILE* dados = fopen("DADOS.TXT", "r");
	
	while(fscanf(dados, "%d", &dia)!= EOF && fscanf(dados, "%d", &mes)!= EOF &&
		  fscanf(dados, "%d", &ano)!= EOF&& fscanf(dados, "%f", &valor)!= EOF)
	{
		cont++;
	}
	fclose(dados);
	
	BOLETO* boleto;
	boleto = (BOLETO*)malloc(sizeof(BOLETO));
	
	while(fscanf(dados, "%d", &dia)!= EOF &&fscanf(dados, "%d", &mes)!= EOF &&
		fscanf(dados, "%d", &ano)!= EOF &&fscanf(dados, "%f", &valor)!= EOF)
	{
		i = 0;
		boleto[indice].datas[i++] = dia;
		boleto[indice].datas[i++] = mes;
		boleto[indice].datas[i] =   ano;
		boleto[indice++].valor = valor;
	}
	fclose(dados);
	
	FILE* dado = fopen("BOLETOS.TXT", "wt");
	printf("Entre com o dia:");
	scanf("%d", &dia); getchar();
	printf("Entre com o mes:");
	scanf("%d", &mes); getchar();
	printf("Entre com o ano:");
	scanf("%d", &ano); getchar();
	
	for(int i=0;i<cont;i++){
		if(boleto[i].datas[0] == dia && boleto[i].datas[1] == mes && boleto[i].datas[2] == ano ){
			fprintf(dado, "%f\n", boleto[i].valor);
			printf("%f", boleto[i].valor);
		}else{
			fprintf(dado, "%f", 0.0);
			i = cont;
		}
	}
	fclose(dado);
	return 0;
}
