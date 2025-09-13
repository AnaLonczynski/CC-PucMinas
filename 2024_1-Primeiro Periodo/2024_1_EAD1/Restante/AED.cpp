#include <iostream>


class Celula{
    private:
    int elemento;
    Celula* prox;

    public:

    Celula(){
        this->elemento = 0;
        this->prox = NULL;
    }

    Celula(int x){
        this->elemento = x;
        this->prox = NULL;
    }
}

