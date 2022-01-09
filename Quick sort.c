/*
A ideia básica é dividir o problema de ordenar um conjunto com n itens em dois problemas menores. 
Os problemas menores são ordenados independentemente e os resultados são combinados para produzir a solução final.

Basicamente a operação do algoritmo pode ser resumida na seguinte estratégia: divide 
sua lista de entrada em duas sub-listas a partir de um pivô, para em seguida realizar 
o mesmo procedimento nas duas listas menores até uma lista unitária.

é o método de ordenação interna mais rápido que se conhece para uma ampla variedade de situações.
Provavelmente é o mais utilizado. Possui complexidade C(n) = O(n²) no pior caso e C(n) = O(n log n) no melhor e médio caso e não é um algoritmo estável.

*/

#include <stdio.h>

void quick_sort(int vetor[], int tam){
    int i, j, grupo, troca;

    //Critério de parada da recursividade!
    if(tam < 2){
        return; //sai da função
    }else{
    	grupo = vetor[tam / 2];
    }

    //Fazendo um loop único se comportar como dois
    //Veja que estamos utilizando tanto a variável 'i'
    //quanto a variável 'j'.
    //Veja que não temos critério de parada aqui...
    for(i = 0, j = tam - 1;; i++, j--){

    	//Fazemos a movimentação dos elementos no vetor
        while(vetor[i] < grupo){
            i++;
        }

        //Fazemos a movimentação dos elementos no vetor
        while(grupo < vetor[j]){
            j--;
        }
        //Critério de parada do loop
        if(i >= j){
            break;
        }else{
        	//Onde ocorre as trocas
			troca = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = troca;
        }
    }
    //Usando recursividade para ordenar os grupos
    quick_sort(vetor, i);
    quick_sort(vetor + i, tam - i);
}

int main() {
   int vetor[6] = {8, 3, 1, 42, 12, 5};

   //Aplicando a ordenação;
   quick_sort(vetor, 6);

   //Apresentando o vetor ordenado
   for(int i = 0; i < 6; i++){
	   printf("%d\n", vetor[i]);
   }

}
