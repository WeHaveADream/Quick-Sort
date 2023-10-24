#include <stdio.h>
#include<stdlib.h>

//função de ordenação, recebe o vetor, o inicio e o fim do vetor
void quickSort(int *vetor, int inicio, int fim) {

    //o pivo vai receber o começo do vetor como parametro
    int pivot = vetor[inicio];

    //variavel temporaria pra trocas
    int temp;

    //i recebe o inicio e f recebe o final do vetor
    int i = inicio;
    int f = fim;

    //enquanto o inicio for menor ou igual o fim
    while (i <= f) {

        //enquanto o vetor no inicio for menor que o pivo e inicio menor que o fim
        while ((vetor[i] < pivot) && (i < fim)) {
            //o parametro anda pra frente
            i++;
        }

        //encontrou em cima** -> enquanto o vetor no fim for maior que o pivo e o fim maior que o começo
        while ((vetor[f] > pivot) && f > inicio) {
            // o segundo parametro anda
            f--;
        }

        //se o começo for menor ou igual o fim
        if (i <= f) {

            //o temporario recebe o começo
            temp = vetor[i];

            //o começo recebe o ultimo
            vetor[i] = vetor[f];

            //o ultimo recebe o temporario finalizando a troca
            vetor[f] = temp;

            //todos os dois parametros andam pra finalizar a troca
            i++;
            f--;
        }
    }

    //chama recursão
    if (inicio < f) {
        quickSort(vetor, inicio, f);
    }

    if (i < fim) {
        quickSort(vetor, i, fim);
    }
}

int main(){

    // cria vetor
    int vetor[5];

    //recebe valores do vetor
    for(int i = 0; i<5; i++){
        printf("insira um numero: ");
        fflush(stdin);
        scanf("%d", &vetor[i]);
    }

    //printa ele antes da ordenação
	printf("\n\nVetor antes: ");

	for(int i = 0; i < 5; i++){
        printf("\nvetor [%d]: %d ", i, vetor[i]);
	}

	//ordena enviando o vetor recebido, o começo e o fim
	quickSort(vetor, 0, 4);

	//printa ele depois da ordenação
	printf("\n\nVetor depois: ");

	for(int i = 0; i < 5; i++){
        printf("\nvetor [%d]: %d ", i, vetor[i]);
	}
}
