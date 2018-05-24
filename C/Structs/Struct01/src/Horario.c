#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void RemoveEnter(char* texto){
	size_t ln = strlen(texto)-1;
	if(texto[ln] == '\n') texto[ln] = '\0';
}

typedef struct {
	int hora;
	int minuto;
	int segundo;
} Horario;

typedef struct{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct{
	Data data;
	Horario horario;
	char descricao[200];
} Compromisso;

Horario CHorario(int h, int m, int s){
	Horario H;
	H.hora = h;
	H.minuto = m;
	H.segundo = s;

	return H;
}

Data CData(int d, int m, int a){
	Data D;
	D.dia = d;
	D.mes = m;
	D.ano = a;

	return D;
}

Compromisso CComp(Data d, Horario h, char* descricao){
	Compromisso C;
	C.data = d;
	C.horario = h;
	strcpy(C.descricao,descricao);

	return C;
}

void ExibeData(Data d){
	printf("%d/%d/%d\n",d.dia,d.mes,d.ano);
}

void ExibeHora(Horario h){
	printf("%d:%d:%d\n",h.hora,h.minuto,h.segundo);
}

void ExibeComp(Compromisso C){
	ExibeData(C.data);
	ExibeHora(C.horario);
	printf("Descricao: %s",C.descricao);
}

int main(void){

	int dia, mes, ano, hora, minuto, segundo;
	char descricao[200];

	printf("Entre com o dia:");
	scanf("%d",&dia);
	printf("Entre com o mes:");
	scanf("%d",&mes);
	printf("Entre com o ano:");
	scanf("%d",&ano);

	Data D;

	D = CData(dia,mes,ano);

	ExibeData(D);

	Horario H;

	printf("Entre com a hora:");
	scanf("%d",&hora);
	printf("Entre com o minuto:");
	scanf("%d",&minuto);
	printf("Entre com o segundo:");
	scanf("%d",&segundo);

	H = CHorario(hora,minuto,segundo);

	ExibeHora(H);

	printf("Digite uma descrição para o compromisso:\n");
	fgets(descricao,sizeof(descricao),stdin);

	RemoveEnter(descricao);

	Compromisso C = CComp(D,H,descricao);

	ExibeComp(C);




	return 0;
}
