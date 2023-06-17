#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int tamanho_vetor = 0;
int vetor_gerado = 0;
int vetor_ordenado = 0;

void mostrar_menu(int vetor[]){
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
            gerar_vetor(vetor);
            break;
        case 'b':
        case 'B':
            ordenar_vetor(vetor);
            break;
        case 'c':
        case 'C':
            gerar_busca_sequencial(vetor);
            break;
        case 'd':
        case 'D':
            gerar_busca_binaria(vetor);
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

int pegar_tamanho_vetor(){
    printf("Digite o tamanho do vetor de inteiros: ");
    scanf("%d", &tamanho_vetor);

    return tamanho_vetor;
}

int gerar_vetor(int vetor[]){
    pegar_tamanho_vetor();

    srand(time(NULL));

    for(int i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand();
    }

    vetor_gerado++;

    return tamanho_vetor;
}

void mostrar_vetor(int vetor[]){
    for(int i = 0; i < tamanho_vetor; i++){
        printf("%d\n", vetor[i]);
    }

    printf("\n");
}

void insertion_sort(int vetor[]){
    for(int i = 1; i < tamanho_vetor; i++){
        int x = vetor[i], j;

        for(j = i - 1; j >= 0 && x < vetor[j]; j--){
            vetor[j + 1] = vetor[j];
        }
        vetor[j + 1] = x;
    }
    printf("Vetor ordenado com Insertion Sort\n\n");
}

void ordenar_vetor(int vetor[]){
    if(vetor_gerado > 0){
        char op;

        do{
            printf("Escolha uma opcao:\n\n");
            printf("I. Insertion Sort\n");
            printf("M. Merge Sort\n");
            printf("V. Voltar ao menu anterior\n\n");
            scanf(" %c", &op);

            if(op == 'I' || op == 'i'){
                insertion_sort(vetor);
                mostrar_vetor(vetor);
            }else if(op == 'M' || op == 'm'){
                printf("Merge\n\n");
            }else if(op == 'V' || op == 'v'){
                break;
            }else{
                printf("Opcao invalida\n\n");
            }
        }while(op != 'V' || op != 'v');

        vetor_ordenado++;
    }else{
        printf("Eh necessario gerar o vetor antes de ordena-lo!\n\n");
    }
}

void gerar_busca_sequencial(int vetor[]){
    if(vetor_gerado > 0){
        int numero = 0;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        printf("%d\n\n", numero);
    }else{
        printf("Eh necessario gerar o vetor antes de fazer a busca sequencial!\n\n");
    }
}

void gerar_busca_binaria(int vetor[]){
    if(vetor_gerado > 0 && vetor_ordenado > 0){
        int numero = 0;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        printf("%d\n\n", numero);
    }else{
        printf("Eh necessario gerar e ordenar o vetor antes de fazer a busca binaria!\n\n");
    }
}

int main(){
    int vet[] = {};

    mostrar_menu(vet);

    return 0;
}
