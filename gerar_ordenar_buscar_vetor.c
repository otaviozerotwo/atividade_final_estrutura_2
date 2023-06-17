#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int vetor_gerado = 0;
int vetor_ordenado = 0;

void mostrar_menu(){
    char op;

    do{
        printf("Escolha uma das opcoes:\n\n");
        printf("a. Gerar vetor\n");
        printf("b. Ordenar vetor\n");
        printf("c. Busca sequencial\n");
        printf("d. Busca binaria\n");
        printf("e. Sair\n");
        scanf(" %c", &op);

        switch(op){
        case 'a':
        case 'A':
            gerar_vetor();
            break;
        case 'b':
        case 'B':
            ordenar_vetor();
            break;
        case 'c':
        case 'C':
            gerar_busca_sequencial();
            break;
        case 'd':
        case 'D':
            gerar_busca_binaria();
            break;
        case 'e':
        case 'E':
            exit(0);
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }while(op != 'e' || op != 'E');
}

int gerar_vetor(){
    int i = 0;
    int tamanho = 0;

    printf("Digite o tamanho do vetor de inteiros: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    srand(time(NULL));

    for(i = 0; i < tamanho; i++){
        vetor[i] = rand();
    }

    for(i = 0; i < tamanho; i++){
        printf("%d\n", vetor[i]);
    }

    printf("\n");

    return vetor_gerado++;
}

int ordenar_vetor(){
    if(vetor_gerado > 0){

        return vetor_ordenado++;
    }else{
        printf("Eh necessario gerar o vetor antes de ordena-lo!\n\n");

        return vetor_ordenado;
    }
}

void gerar_busca_sequencial(){
    if(vetor_gerado > 0){
        printf("%d\n", vetor_gerado);
    }else{
        printf("Eh necessario gerar o vetor antes de fazer a busca sequencial!\n\n");
    }
}

void gerar_busca_binaria(){
    if(vetor_gerado > 0 && vetor_ordenado > 0){
        printf("%d\n", vetor_gerado);
        printf("%d\n", vetor_ordenado);
    }else{
        printf("Eh necessario gerar e ordenar o vetor antes de fazer a busca binaria!\n\n");
    }
}

int main(){
    mostrar_menu();
    return 0;
}
