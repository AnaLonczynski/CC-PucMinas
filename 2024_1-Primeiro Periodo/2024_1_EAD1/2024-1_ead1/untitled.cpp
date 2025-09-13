#include <iostream>
#include <cstdlib>

struct s_intStack {
	int length;
	int *data;
};

typedef s_intStack* ref_intStack;

// Função para inicializar a pilha
ref_intStack initStack() {
	ref_intStack stack = new s_intStack;
	stack->length = 0;
	stack->data = nullptr;
	return stack;
}

// Função para acrescentar valor no topo da pilha
void push(ref_intStack stack, int value) {
	// Realocar memória para o novo elemento
	stack->data = (int *)realloc(stack->data, (stack->length + 1) * sizeof(int));
	if (stack->data == nullptr) {
		std::cerr << "Erro de alocação de memória." << std::endl;
		std::exit(1);
	}
	
	// Adicionar o novo valor no topo da pilha
	stack->data[stack->length] = value;
	// Atualizar o tamanho da pilha
	stack->length++;
}

// Função para imprimir a pilha
void printStack(ref_intStack stack) {
	for (int i = 0; i < stack->length; ++i) {
		std::cout << stack->data[i] << " ";
	}
	std::cout << std::endl;
}

// Função para liberar a memória da pilha
void freeStack(ref_intStack stack) {
	free(stack->data);
	delete stack;
}

int main() {
	ref_intStack myStack = initStack();
	
	push(myStack, 10);
	push(myStack, 20);
	push(myStack, 30);
	
	printStack(myStack); // Deve imprimir: 10 20 30
	
	freeStack(myStack);
	
	return 0;
}

