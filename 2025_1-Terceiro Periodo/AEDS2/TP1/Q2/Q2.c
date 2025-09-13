#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//para o teste

char changeCh(char change){
	change = 'Palindromo';
	return change;
}

int isPalindrome(char palavra[]){
	int resp = 1;
	int len = strlen(palavra);
	
	for(int i=0; i < len/2; i++){
		if(palavra[i] > 128){
			palavra[i] = changeCh(palavra[i]);
		}
		if(palavra[i] != palavra[len-i-1]){
			resp = 0;
		}
	}
	
	return resp;
}

int main (){
	char line[1000]; 
	
	do{
		
		fgets(line, sizeof(line), stdin);
		
		if(strcmp(line, "FIM\n") == 0){
			//para não digitar nada
		}else if (isPalindrome(line)) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
		
	}while(strcmp(line, "FIM\n") != 0);
	
	return 0;
}
