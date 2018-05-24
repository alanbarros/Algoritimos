#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct banda {
	char nome_banda[20];
	char estilo_musical[15];
	int n_integrantes;
	int position_ranking;
} banda;

void limpaBuffer(void){
	char c;
	while(c=getchar()!='\n' && c !=EOF);
}

void preferencia(banda *pt){
	int i;
	int cont;

	for(cont=0;cont<3;cont++){
		fflush(stdin);
		do{
			system("cls");
			printf("\nNome da banda: ");
			gets(pt[cont].nome_banda);
			i = strlen(pt[cont].nome_banda);
			if(i>19)
			pt==(NULL);
		} while(i>19);

		printf("\nEstilo musical: ");
		gets(pt[cont].estilo_musical);
		fflush(stdin);

		printf("\nNumero de integrantes: ");
		scanf("%d",&pt[cont].n_integrantes);

		printf("\nPosicao no ranking: ");
		scanf("%d",&pt[cont].position_ranking);
	}
}

void exibe_preferencia(banda *exib){
	int cont;
	for(cont=0;cont<3;cont++){
		printf("\n\nBanda: %s",exib[cont].nome_banda);
		printf("\nEstilo: %s",exib[cont].estilo_musical);
		printf("\nIntegrantes: %d",exib[cont].n_integrantes);
		printf("\nPosicao: %d",exib[cont].position_ranking);
	}
}

void procura(banda *busca){
	fflush(stdin);
	char musica2[50];
	int compara=0,cont;

	printf("\nInforme seu tipo de musica: ");
	gets(musica2);
	fflush(stdin);

	for(cont=0;cont<100;cont++){
		if(strcmp(busca[cont].estilo_musical,musica2)==0){
			compara=1;
			printf("\nBanda: %s",busca[cont].nome_banda);
		}
		if(busca[cont].nome_banda=='\0')
		break;
	}
	if(compara==1)
	printf("\nencontrado");
	else
	printf("\nausente");
}


main(){
	banda p[3];//variavel do tipo banda.
	char musica[15];

	preferencia(p);
	procura(p);
	exibe_preferencia(p);

	getch();
	return 0;
}