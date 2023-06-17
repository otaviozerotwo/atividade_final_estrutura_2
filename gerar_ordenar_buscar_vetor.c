#include<stdio.h>
#include<stdlib.h>

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
            break;
        default:
            printf("Opcao invalida!\n\n");
            break;
        }
    }while(op != 'e');
}

int gerar_vetor(){
    int tamanho = 0;

    printf("Digite o tamanho do vetor de inteiros: ");
    scanf("%d", &tamanho);

    return 0;
}

void ordenar_vetor(){

}

void gerar_busca_sequencial(){

}

void gerar_busca_binaria(){

}

int main(){

    mostrar_menu();
    return 0;
}
