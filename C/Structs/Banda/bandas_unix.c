#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LimparTela(){
    system("clear");
}

//Limpa o buffer do teclado
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void RemoverEnterDoFim(char *p){
    size_t ln = strlen(p) - 1;
    if (p[ln] == '\n') p[ln] = '\0';
}

typedef struct
{
        char nome[20];
        char tipoMusica[20];
        int numIntergrantes;
        int posicao;
} Banda;

void Menu(int *escolha){
    printf("\nMenu\n");
    printf("1 - Adicionar Banda\n");
    printf("2 - Listar Bandas\n");
    printf("3 - Buscar Banda pelo Estilo\n");
    printf("4 - Buscar Banda pela Ranking\n");
    printf("5 - Buscar Banda pelo Nome\n");
    printf("0 - Sair\n");
    scanf("%d",escolha);
    getchar();
    LimparTela();
}

void Exibe(Banda b)
{
    printf("\nNome da banda: %s\n", b.nome);
    printf("Genero da banda: %s\n", b.tipoMusica);
    printf("Numero de integrantes: %d\n", b.numIntergrantes);
    printf("Posicao no ranking: %d\n", b.posicao);
}

void Preenche(Banda *b)
{
    printf("Digite o nome da banda:\n");
    fgets(b->nome, sizeof(b->nome), stdin);
    RemoverEnterDoFim(b->nome);

    printf("Digite o gênero da banda:\n");
    fgets(b->tipoMusica, sizeof(b->tipoMusica), stdin);
    RemoverEnterDoFim(b->tipoMusica);

    printf("Digite o número de integrantes\n");
    scanf("%d",&b->numIntergrantes);
    flush_in();

    printf("Digite a posicao\n");
    scanf("%d",&b->posicao);
    flush_in();
}

void BuscarEstilo(Banda *b, int count){

    if(count > 0){
        char estilo[30];

        printf("Numero de bandas: %d\n",count);

        printf("Informe o estilo:\n");
        fgets(estilo, sizeof(estilo), stdin);
        RemoverEnterDoFim(estilo);

        for(int i = 0; i < count; i++){
            int encontrado = 0;
            if(strcmp(b[i].tipoMusica,estilo)==0){
                encontrado++;
                if(encontrado == 1){
                    printf("Bandas localizadas: \n");
                }
                Exibe(b[i]);
            } else {
                printf("Nao existe nenhum\n");
            }
        }
    } else {
        printf("Antes, cadastre ao menos uma banda\n");
    }
}

void BuscarNome(Banda *b, int count){

    if(count > 0){
        char nome[30];

        printf("Numero de bandas: %d\n",count);

        printf("Informe o nome:\n");
        fgets(nome, sizeof(nome), stdin);
        RemoverEnterDoFim(nome);

        for(int i = 0; i < count; i++){
            if(strcmp(b[i].nome,nome)==0){
                Exibe(b[i]);
            } else {
                printf("Nao existe nenhum\n");
            }
        }
    } else {
        printf("Antes, cadastre ao menos uma banda\n");
    }
}

void BuscarPosicao(Banda *b, int count){
    if(count > 0){
        int posicao;

        printf("Numero de bandas: %d\n",count);

        printf("Informe a posicao:\n");
        scanf("%d",&posicao);
        flush_in();

        for(int i = 0; i < count; i++){
            if(b[i].posicao == posicao){
                Exibe(b[i]);
            } else {
                printf("Nao existe nenhum\n");
            }
        }
    } else {
        printf("Antes, cadastre ao menos uma banda\n");
    }
}

int main()
{
    LimparTela();

    Banda banda[5];

    int escolha = 0;
    int count = 0;
    do{
        Menu(&escolha);
        switch(escolha){
            case 1:
                Preenche(&banda[count]);
                count++;
            break;
            case 2:
                printf("Bandas: \n");
                for (int i = 0; i < count; i++){
                    Exibe(banda[i]);
                }
                printf("\n------------------\n");
            break;
            case 3:
                BuscarEstilo(banda, count);
            break;
            case 4:
                BuscarPosicao(banda, count);
            break;
            case 5:
                BuscarNome(banda, count);
            break;
            case 0:
                printf("Obrigado por usar este programa, ate mais!\n");
            break;
            default:
                printf("Opcao invalida, tente novamente...\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}