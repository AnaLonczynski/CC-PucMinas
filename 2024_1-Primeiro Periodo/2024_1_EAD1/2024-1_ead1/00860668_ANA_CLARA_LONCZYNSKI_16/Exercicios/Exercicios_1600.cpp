/*
Exemplo1600 - v0.0. - 19 / 06 / 2024
Author: Ana Clara Lonczynski
*/
// ----------------------------------------------- preparacao
// dependências
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
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos

typedef struct s_Cell // descritor da celula
{
	int value;
	struct s_Cell *link;
}
intCell;

typedef intCell * ref_intCell;

typedef struct s_intArray 
{ 
	int length;
	int *data;
}
intArray;

typedef intArray* ref_intArray;

intCell* array_push_back(intCell* head, int value) {
	
	//Criacao de uma celula
	intCell* newCell = new intCell;
	newCell->value = value;
	newCell->link = nullptr;
	
	// Se null, retorna a celula como head
	if (head == nullptr) {
		return newCell;
	}
	
	// Percorrer a lista
	intCell* current = head;
	while (current->link != nullptr) {
		current = current->link;
	}
	
	// Adicionar a nova célula ao final
	current->link = newCell;
	
	return head;
}

void printList(intCell* head) {
	intCell* current = head;
	while (current != nullptr) {
		std::cout << current->value << " ";
		current = current->link;
	}
	std::cout << std::endl;
}

void freeList(intCell* head) {
	intCell* current = head;
	while (current != nullptr) {
		intCell* next = current->link;
		delete current;
		current = next;
	}
}

intCell* array_pop_back(intCell* head) {
	if (head == nullptr) {
		return nullptr; // Lista vazia
	}
	
	if (head->link == nullptr) {
		// Se houver apenas um elemento
		delete head;
		return nullptr;
	}
	
	// Percorrer a lista até o penúltimo nó
	intCell* current = head;
	while (current->link->link != nullptr) {
		current = current->link;
	}
	
	// Liberar o último nó
	delete current->link;
	current->link = nullptr;
	
	return head;
}

intCell* array_push_front(intCell* head, int value) {
	// Criação de uma nova célula
	intCell* newCell = new intCell;
	newCell->value = value;
	newCell->link = head;
	
	// A nova célula se torna a cabeça
	return newCell;
}

intCell* array_pop_front(intCell* head) {
	if (head == nullptr) {
		return nullptr; // Lista vazia
	}
	
	// Apontar para o segundo nó
	intCell* newHead = head->link;
	
	// Liberar a memória do nó original da cabeça
	delete head;
	
	// Retornar a nova cabeça
	return newHead;
}

intCell* array_pop_mid(intCell* head) {
	
	if (head == nullptr || head->link == nullptr) {
		delete head;
		return nullptr;
	}
	
	// Calcula o tamanho da lista
	int length = 0;
	intCell* current = head;
	while (current != nullptr) {
		length++;
		current = current->link;
	}
	
	// Encontrar a mediana
	int midIndex = length / 2;
	
	current = head;
	for (int i = 0; i < midIndex - 1; i++) {
		current = current->link;
	}
	
	intCell* temp = current->link;
	current->link = temp->link;
	delete temp;
	
	return head;
}

intCell* array_push_mid(intCell* head){
	
	
	
	return head;
}


int intArray_cmp(ref_intArray p, ref_intArray q) {
	// Comparar os comprimentos dos arranjos
	if (p->length != q->length) {
		return p->length - q->length;
	}
	
	// Comparar os elementos dos arranjos
	for (int i = 0; i < p->length; ++i) {
		if (p->data[i] != q->data[i]) {
			return p->data[i] - q->data[i];
		}
	}
	
	// Se todos os elementos forem iguais
	return 0;
}

void freeArray(ref_intArray arr) {
	delete[] arr->data;
	delete arr;
}

ref_intArray intArray_cat(ref_intArray p, ref_intArray q) {
	
	int newLength = p->length + q->length;
	int *newData = new int[newLength];
	
	for (int i = 0; i < p->length; ++i) {
		newData[i] = p->data[i];
	}
	
	for (int i = 0; i < q->length; ++i) {
		newData[p->length + i] = q->data[i];
	}
	
	ref_intArray newArray = new intArray;
	newArray->length = newLength;
	newArray->data = newData;
	
	return newArray;
}

ref_intArray intArray_seek(ref_intArray a, int x) {
	for (int i = 0; i < a->length; ++i) {
		if (a->data[i] == x) {
			// Alocar memória para a nova estrutura intArray
			ref_intArray result = new intArray;
			result->length = 1;
			result->data = new int[1];
			result->data[0] = x;
			return result;
		}
	}
	return nullptr;
}

ref_intArray intArray_sub(ref_intArray a, int start, int size) {
	// Verificar se os parâmetros são válidos
	if (start < 0 || start >= a->length || size <= 0 || (start + size) > a->length) {
		return nullptr;
	}
	
	int *newData = new int[size];
	
	// Copiar a subsequência de valores
	for (int i = 0; i < size; ++i) {
		newData[i] = a->data[start + i];
	}
	
	ref_intArray newArray = new intArray;
	newArray->length = size;
	newArray->data = newData;
	
	return newArray;
}


ref_intArray intArray_merge(ref_intArray p, ref_intArray q) {
	// Alocar memória para o novo arranjo
	int newLength = p->length + q->length;
	int *newData = new int[newLength];
	
	// Intercalar os elementos dos dois arranjos
	int i = 0, j = 0, k = 0;
	while (i < p->length && j < q->length) {
		newData[k++] = p->data[i++];
		newData[k++] = q->data[j++];
	}
	
	// Copiar os elementos restantes do arranjo p
	while (i < p->length) {
		newData[k++] = p->data[i++];
	}
	
	// Copiar os elementos restantes do arranjo q
	while (j < q->length) {
		newData[k++] = q->data[j++];
	}
	
	// Criar a nova estrutura intArray
	ref_intArray newArray = new intArray;
	newArray->length = newLength;
	newArray->data = newData;
	
	return newArray;
}


ref_intArray intArray_mergeUp(ref_intArray p, ref_intArray q) {
	// Alocar memória para o novo arranjo
	int newLength = p->length + q->length;
	int *newData = new int[newLength];
	
	// Intercalar os elementos dos dois arranjos em ordem crescente
	int i = 0, j = 0, k = 0;
	while (i < p->length && j < q->length) {
		if (p->data[i] < q->data[j]) {
			newData[k++] = p->data[i++];
		} else {
			newData[k++] = q->data[j++];
		}
	}
	
	// Copiar os elementos restantes do arranjo p
	while (i < p->length) {
		newData[k++] = p->data[i++];
	}
	
	// Copiar os elementos restantes do arranjo q
	while (j < q->length) {
		newData[k++] = q->data[j++];
	}
	
	// Criar a nova estrutura intArray
	ref_intArray newArray = new intArray;
	newArray->length = newLength;
	newArray->data = newData;
	
	return newArray;
}

/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )
/**
  Method_01 - Testar definicoes da classe.
 */
void method_01 ( )
{
// definir dados
// identificar
	cout << "\nMethod_01 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	// Imprimir os valores da lista encadeada
	
	cout<<"Lista com valores advindos de push_back: ";
	printList(head);
	
	// Liberar a memória alocada
	freeList(head);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02
 */
void method_02 ( )
{
// definir dados
// identificar
	cout << "\nMethod_02 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	cout<<"Lista com valores advindos de push_back: ";
	printList(head);
	
	//retirar ultimo elemento
	head = array_pop_back(head);
	
	cout<<endl<<"Apos retirar ultimo valor:"<<endl;
	printList(head);
	
	// Liberar a memória alocada
	freeList(head);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03
 */
void method_03 ( )
{
// identificar
	cout << "\nMethod_03 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	cout<<"Lista com valores advindos de push_back: ";
	printList(head);
	
	// Adicionar valores no inicio da lista encadeada
	head = array_push_front(head, 0);
	head = array_push_front(head, -1);
	
	// Imprimir os valores da lista
	std::cout << "Lista apos adicionar ao inicio: ";
	printList(head);
	
	// Liberar a memória alocada
	freeList(head);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04
 */
void method_04 ( )
{
// identificar
	cout << "\nMethod_04 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	cout<<"Lista com valores advindos de push_back: ";
	printList(head);
	
	// Adicionar valores no inicio da lista encadeada
	head = array_push_front(head, 0);
	head = array_push_front(head, -1);
	
	// Imprimir os valores da lista
	std::cout << "Lista apos adicionar ao inicio: ";
	printList(head);
	
	for(int i=1;i<=2;i++){
		head = array_pop_front(head);
	}
	
	// Imprimir os valores da lista
	std::cout << "Lista apos retirar do inicio: ";
	printList(head);
	
	// Liberar a memoria alocada
	freeList(head);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05
 */
void method_05 ( )
{
	// identificar
	cout << "\nMethod_05 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	cout<<"Lista com valores advindos de push_back:" ;
	printList(head);
	
	// Adicionar valores no inicio da lista encadeada
	head = array_push_front(head, 0);
	head = array_push_front(head, -1);
	
	// Imprimir os valores da lista
	cout<<endl << "Lista apos adicionar ao inicio: ";
	printList(head);
	
	array_push_mid(head);
	
	// Imprimir os valores da lista
	cout << endl << "Lista apos adicionar no meio: ";
	printList(head);
	
	// Liberar a memoria alocada
	freeList(head);
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06
 */
void method_06 ( )
{
// definir dados
// identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	
	intCell* head = nullptr;
	
	// efetuar push_back
	head = array_push_back(head, 1);
	head = array_push_back(head, 2);
	head = array_push_back(head, 3);
	
	cout<<"Lista com valores advindos de push_back:" ;
	printList(head);
	
	// Adicionar valores no inicio da lista encadeada
	head = array_push_front(head, 0);
	head = array_push_front(head, -1);
	
	// Imprimir os valores da lista
	cout<<endl << "Lista apos adicionar ao inicio: ";
	printList(head);
	
	array_pop_mid(head);
	
	// Imprimir os valores da lista
	cout<<endl << "Lista apos retirar do meio: ";
	printList(head);
	
	// Liberar a memoria alocada
	freeList(head);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07
 */
void method_07 ( )
{
	// identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	
	// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 5;
	int j = 1;
	int k = 1;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	cout << endl<<"[arr2]: " <<endl;
	
	ref_intArray arr2;
	arr2 = (ref_intArray)malloc(sizeof(intArray));
	arr2->length = 5;
	arr2->data = (int*)malloc(arr2->length * sizeof(int));
	
	for(int x = 0;x < arr2->length; x++){
		arr2->data[x] = k;
		k++;
		cout << "["
		<< x <<"] = "<< arr2->data[x]<<endl;
	}
	
	int result = intArray_cmp(arr1, arr2);
	cout<<endl;
	
	// Imprimir o resultado da comparação
	if (result == 0) {
		cout << "Os arranjos sao iguais." << endl;
	} else if (result < 0) {
		cout << "O primeiro arranjo e' menor que o segundo." << endl;
	} else {
		cout << "O primeiro arranjo e' maior que o segundo." << endl;
	}
	
	freeArray(arr1);
	freeArray(arr2);
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08
 */
void method_08 ( )
{
// identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	
// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 5;
	int j = 1;
	int k = 1;
	int l = 1;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	cout << endl<<"[arr2]: " <<endl;
	
	ref_intArray arr2;
	arr2 = (ref_intArray)malloc(sizeof(intArray));
	arr2->length = 5;
	arr2->data = (int*)malloc(arr2->length * sizeof(int));
	
	for(int x = 0;x < arr2->length; x++){
		arr2->data[x] = k;
		k++;
		cout << "["
		<< x <<"] = "<< arr2->data[x]<<endl;
	}

	ref_intArray concatenatedArray = intArray_cat(arr1, arr2);
	
	// Imprimir o arranjo concatenado
	cout << endl << "Arranjo concatenado: "<<endl;
	
	for (int i = 0; i < concatenatedArray->length; ++i) {
		cout << "["
		<< i <<"] = "<< concatenatedArray->data[i]<<endl;
	}
	
	// Liberar a memória alocada
	freeArray(arr1);
	freeArray(arr2);
	freeArray(concatenatedArray);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09
 */
void method_09 ( )
{
// identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 5;
	int j = 1;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	int value = 0;
	cout<<endl<<"Insira o valor procurado:";
	cin>>value;
	
	ref_intArray foundArray = intArray_seek(arr1, value);
	
	if (foundArray != nullptr) {
		cout << "Valor " << value << " esta' na array " <<endl;
	} else {
		cout << "Valor " << value<< " nao encontrado." << endl;
	}
	
	// Liberar a memória alocada
	freeArray(arr1);
	freeArray(foundArray);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10
 */
void method_10 ( )
{
// identificar
	cout << "\nMethod_10 - v0.0\n" << endl;
	
// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 10;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	int j = 1;
	int start, size;
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	cout<<endl<<"Insira a posicao:";
	cin>>start;
	
	cout<<endl<<"Insira o tamanho:";
	cin>>size;
	
	ref_intArray subArray = intArray_sub(arr1, start, size);
	
	if (subArray != nullptr) {
		cout << "Subsequecia a partir da posicao " << start << " com tamanho " << size << ": "<<endl;
		for (int i = 0; i < subArray->length; ++i) {
			cout << "["
			<< i <<"] = "<< subArray->data[i]<<endl;
		}
	} else {
		cout << "//ERRO// tamanho maior do que o possivel" << endl;
	}
	
// Liberar a memória alocada
	freeArray(arr1);
	freeArray(subArray);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/**
  Method_E1 
 */
void method_E1 ( )
{
// identificar
	cout << "\nMethod_E1 - v0.0\n" << endl;
	
// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 5;
	int j = 1;
	int k = 6;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	cout << endl<<"[arr2]: " <<endl;
	
	ref_intArray arr2;
	arr2 = (ref_intArray)malloc(sizeof(intArray));
	arr2->length = 5;
	arr2->data = (int*)malloc(arr2->length * sizeof(int));
	
	for(int x = 0;x < arr2->length; x++){
		arr2->data[x] = k;
		k++;
		cout << "["
		<< x <<"] = "<< arr2->data[x]<<endl;
	}
	
	// Intercalar os arranjos
	ref_intArray mergedArray = intArray_merge(arr1, arr2);
	
	// Imprimir o arranjo intercalado
	cout << endl<< "Arranjo intercalado: ";
	for (int i = 0; i < mergedArray->length; ++i) {
		cout << "["
		<< i <<"] = "<< mergedArray->data[i]<<endl;
	}
	
	// Liberar a memória alocada
	freeArray(arr1);
	freeArray(arr2);
	freeArray(mergedArray);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_E1 ( )

/**
  Method_E2 
 */
void method_E2 ( )
{
// identificar
	cout << "\nMethod_E2 - v0.0\n" << endl;
	
// definir dados
	intArray* arr1;
	arr1 = (intArray*)malloc(sizeof(intArray));
	arr1->length = 5;
	int j = 6;
	int k = 1;
	arr1->data = (int*)malloc(arr1->length * sizeof(int));
	
	cout << "[arr1]: " <<endl;
	
	for(int i = 0; i < arr1->length; i++){
		arr1->data[i] = j;
		j++;
		cout << "["<< i <<"] = "<< arr1->data[i]<<endl;
	}
	
	cout << endl<<"[arr2]: " <<endl;
	
	ref_intArray arr2;
	arr2 = (ref_intArray)malloc(sizeof(intArray));
	arr2->length = 5;
	arr2->data = (int*)malloc(arr2->length * sizeof(int));
	
	for(int x = 0;x < arr2->length; x++){
		arr2->data[x] = k;
		k++;
		cout << "["
		<< x <<"] = "<< arr2->data[x]<<endl;
	}
	
	ref_intArray mergedArray = intArray_mergeUp(arr1, arr2);
	
	cout << endl << "Arranjo intercalado em ordem crescente: "<<endl;
	
	for (int i = 0; i < mergedArray->length; ++i) {
		cout << "["
		<< i <<"] = "<< mergedArray->data[i]<<endl;
	}
	
	// Liberar a memória alocada
	freeArray(arr1);
	freeArray(arr2);
	freeArray(mergedArray);
	
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_E2 ( )

// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do
	{
		// identificar
		cout << "EXEMPLO1600 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << "  0 - Method 0 " << endl;
		cout << "  1 - Method 1 " << endl;
		cout << "  2 - Method 2 " << endl;
		cout << "  3 - Method 3 " << endl;
		cout << "  4 - Method 4 " << endl;
		cout << "  5 - Method 5 " << endl;
		cout << "  6 - Method 6 " << endl;
		cout << "  7 - Method 7 " << endl;
		cout << "  8 - Method 8 " << endl;
		cout << "  9 - Method 9 " << endl;
		cout << " 10 - Method 10 " << endl;
		cout << " 11 - Method E1 " << endl;
		cout << " 12 - Method E2 " << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
		case 0:
			method_00 ( );
			break;
		case 1:
			method_01 ( );
			break;
		case 2:
			method_02 ( );
			break;
		case 3:
			method_03 ( );
			break;
		case 4:
			method_04 ( );
			break;
		case 5:
			method_05( );
			break;
		case 6:
			method_06 ( );
			break;
		case 7:
			method_07 ( );
			break;
		case 8:
			method_08 ( );
			break;
		case 9:
			method_09 ( );
			break;
		case 10:
			method_10 ( );
			break;
		case 11:
			method_E1 ( );
			break;
		case 12:
			method_E2 ( );
			break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )

