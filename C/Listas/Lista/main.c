#include <stdio.h>
#include <stdlib.h>

const int MAXTAM = 1000;

int Frente, Tras;

int Lista[MAXTAM];

void Lista_Contrutor(){
    Frente=0;
    Tras=-1;
}

bool Lista_Vazia(){
    if(Frente>Tras)
        return true;
    else
        return false;
}

bool Lista_Cheia(){
    if(Tras==MAXTAM-1)
        return true;
    else
        return false;
}

int Lista_Tamanho(){
    return Tras-1;
}

bool Lista_Inserir_Inicio( int valor){
    if(Lista_Cheia()){
        return false;
    } else {
        Lista[Tras]=valor;
        Tras++;
        return true;
    }


}

bool Lista_Inserir_Fim(int valor){
    if(Lista_Cheia()){
        return false;
    } else {
        Lista[Tras]=valor;
        return true;
    }

}

bool Lista_Inserir(int valor, int Posicao){

}



int main()
{
    printf("Hello world!\n");
    return 0;
}
