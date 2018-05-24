/*
 ============================================================================
 Name        : Struct01.c
 Author      : Alan Barros
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[50];
} Seguradora;

typedef struct{
	char fabricante[50];
	char modelo[50];
	int ano;
	Seguradora seguradora;
} Carro;

Seguradora CriaSeguradora(char* nome ){
	Seguradora s;
	strcpy(s.nome,nome);
	return s;
}

Carro CriaCarro(char* fab, char* mod, int ano, Seguradora *seg){
	Carro c;

	strcpy(c.fabricante,fab);
	strcpy(c.modelo,mod);
	c.ano = ano;
	c.seguradora = *seg;

	return c;
}

void ExibeCarro(Carro c){
	printf("Fabricante: %s\n",c.fabricante);
	printf("Modelo: %s\n",c.modelo);
	printf("Ano: %d\n",c.ano);
	printf("Seguradora: %s\n",c.seguradora.nome);
}

void ExibeSeg(Seguradora s){
	printf("%s\n",s.nome);
}

int main1(void) {

	Seguradora seg;
	Carro car;

	seg = CriaSeguradora("Text");
	car = CriaCarro("GM","Cruize",2017,&seg);

	ExibeSeg(seg);
	ExibeCarro(car);

	return EXIT_SUCCESS;
}
