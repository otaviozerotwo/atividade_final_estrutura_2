#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int tamanho_vetor = 0;
int vetor_gerado = 0;
int vetor_ordenado = 0;

int pegar_tamanho_vetor(){
    printf("Digite o tamanho do vetor de inteiros: ");
    scanf("%d", &tamanho_vetor);

    return tamanho_vetor;
}

void gerar_vetor(int vetor[]){
    pegar_tamanho_vetor();

    srand(time(NULL));

    for(int i = 0; i < tamanho_vetor; i++){
        vetor[i] = rand();
    }

    vetor_gerado++;
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
    printf("Vetor ordenado com Insertion Sort:\n\n");
}

void merge(int vetor[], int inicio, int meio, int fim){
    int temp[fim - inicio + 1];
    int i = inicio, j = meio + 1, k = 0;

    while(i <= meio && j <= fim){
        if(vetor[i] <= vetor[j]){
            temp[k++] = vetor[i++];
        }else{
            temp[k++] = vetor[j++];
        }
    }

    while(i <= meio){
        temp[k++] = vetor[i++];
    }

    while(j <= fim){
        temp[k++] = vetor[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        vetor[i] = temp[k];
    }
}

void merge_sort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }

    printf("Vetor ordenado com Merge Sort:\n\n");
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
                merge_sort(vetor, 0, (tamanho_vetor - 1));
                mostrar_vetor(vetor);
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

void busca_sequencial(int vetor[]){
    if(vetor_gerado > 0){
        int numero = 0;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        int resultado = -1;

        for(int i = 0; i < tamanho_vetor; i++){
            if(vetor[i] == numero){
                resultado = i;
            }
        }

        if(resultado != -1){
            printf("Numero encontrado na posicao: %d\n\n", resultado);
        }else{
            printf("Numero nao encontrado.\n\n");
        }
    }else{
        printf("Eh necessario gerar o vetor antes de fazer a busca sequencial!\n\n");
    }
}

void busca_binaria(int vetor[]){
    if(vetor_gerado > 0 && vetor_ordenado > 0){
        int numero = 0;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        int inicio = 0, fim = tamanho_vetor - 1;
        int resultado = -1;

        while(inicio <= fim){
            int meio = (inicio + fim) / 2;

            if(numero == vetor[meio]){
                resultado = meio;
                break;
            }else if(numero < vetor[meio]){
                fim = meio - 1;
            }else if(numero > vetor[meio]){
                inicio = meio + 1;
            }
        }

        if(resultado != -1){
            printf("Numero encontrado na posicao: %d\n\n", resultado);
        }else{
            printf("Numero nao encontrado.\n\n");
        }
    }else{
        printf("Eh necessario gerar e ordenar o vetor antes de fazer a busca binaria!\n\n");
    }
}

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
            busca_sequencial(vetor);
            break;
        case 'd':
        case 'D':
            busca_binaria(vetor);
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

int main(){
    int vet[] = {};

    mostrar_menu(vet);

    return 0;
}
