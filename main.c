#include <stdio.h>
#include <string.h>

typedef struct contato{
    char nome[101];
    char numero[10];
} Contato; //tipo contato formado por nome e número

int main(){
    Contato contatos[10]; //vetor dos contatos do tipo contato
    int quantidade = 0; //guardar a quantidade de contatos
    int opcao = 0; //isso será usado pra saber o que o usário quer fazer

    do{
        printf("Digite o dígito correspondente ao que deseja fazer: \n");
        printf("[0]: Sair\n");
        printf("[1]: Inserir contato\n");
        printf("[2]: Remover contato\n");
        printf("[3]: Buscar contato por nome\n");
        printf("[4]: Imprimir agenda\n");
        scanf("%d", &opcao); //pegar a opção

        if(opcao == 1){ //inserir contato
            printf("Insira o nome do contato: \n");
            scanf("%s", contatos[quantidade].nome); //pegar o nome
            printf("Insira o número do contato: \n");
            scanf(" %s", contatos[quantidade].numero); //pegar o número
            quantidade++; //incrementa a qtd de contatos
        } else if(opcao == 2){ //remover contato
            printf("Qual contato você deseja remover? Tecle o dígito correspondente. \n");
            for(int i = 0; i < quantidade; i++) printf("[%d]: %s - %s \n", i, contatos[i].nome, contatos[i].numero); //mostrar os contatos
            int apagar;
            scanf("%d", &apagar); //pegar o valor do contato a ser apagado
            for(int j = apagar+1; j < quantidade; j++) contatos[j-1] = contatos[j]; //para contatos maiores que o apagado. substitui o da posição atual pelo da posição anterior
            quantidade--; //decrementa a qtd já que tirou 1
        } else if(opcao == 3){ //buscar por nome
            printf("Insira o nome do contato a ser buscado: \n");
            char nome[101];
            scanf(" %s", nome);
            for(int i = 0; i < quantidade; i++){ //verificar qual dos contatos é igual e imprimir, se for
                if(strcmp(nome, contatos[i].nome) == 0){ //strcmp de 2 strings == 0 significa que elas são iguais
                    printf("[%d]: %s = %s \n", i, contatos[i].nome, contatos[i].numero);
                    break; //parar de comparar depois de achar
                }
            }
        } else{ //imprimir a agenda
            for(int i = 0; i < quantidade; i++) printf("[%d]: %s - %s \n", i, contatos[i].nome, contatos[i].numero); //imprimir cada um
        }

    } while (opcao!=0); //só enquanto a opção não for sair

    return 0;
}

