#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int contMaiuscula (char palavra[], int pos){
	int resp =0;
	int tamanho = strlen(palavra);
	
	if(pos < tamanho){
		if(palavra[pos] >= 'A' && palavra[pos] <= 'Z'){
			resp = contMaiuscula(palavra, pos+1)+1;
		}else{
			resp= contMaiuscula(palavra,pos+1);
		}
	}
	return resp;
}

int main(){
	char palavra[1000];
	int posicao = 0;
	
	do{
		scanf("%[^\n]%*c", palavra);
		if (strcmp(palavra, "FIM") != 0) {
			int resultado = contMaiuscula(palavra, 0);
			printf("%d\n", resultado);
		}
	}while(strcmp(palavra, "FIM") != 0);
	
	return 0;
}
