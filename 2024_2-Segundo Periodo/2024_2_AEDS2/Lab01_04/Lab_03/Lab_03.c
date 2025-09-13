#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void contMaiuscula (char palavra[]){
	int contador =0;
	int i = 0;
	
	while(palavra[i] !='\0'){
		
		if (palavra[i] >= 'A' && palavra[i] <= 'Z') 
		{
			contador++;
		}
		i ++;
	}
	printf("%d\n", contador);
}

int main(){
	char palavra[1000];
	int posicao = 0;
	
	do{
		scanf("%[^\n]%*c", palavra);
		if (strcmp(palavra, "FIM") != 0) {
			contMaiuscula(palavra);
		}
	}while(strcmp(palavra, "FIM") != 0);
	
	return 0;
}
