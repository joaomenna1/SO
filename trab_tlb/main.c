#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double time_diff(struct timeval *start, struct timeval *end) {
    struct timeval temp;
    if ((end->tv_usec - start->tv_usec) < 0) {
        temp.tv_sec = end->tv_sec - start->tv_sec - 1;
        temp.tv_usec = 1000000 + end->tv_usec - start->tv_usec;
    } else {
        temp.tv_sec = end->tv_sec - start->tv_sec;
        temp.tv_usec = end->tv_usec - start->tv_usec;
    }
    return (double)(temp.tv_sec * 1000000 + temp.tv_usec) / 1000000;
}

void accessPages(int P, int I) {
    struct timeval start, end;
    double total_time = 0.0;

    // Determinar o tamanho das páginas no sistema
    long pagesize = sysconf(_SC_PAGESIZE);

    // Calcular o tamanho necessário do vetor
    long vector_size = pagesize * P / sizeof(int);

    // Alocar memória para o vetor
    int* vector = (int*)malloc(vector_size * sizeof(int));

    // Acesso às páginas
    gettimeofday(&start, NULL);

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < P; j++) {
            int index = j * (pagesize / sizeof(int));
            vector[index]++;
        }
    }

    gettimeofday(&end, NULL);

    total_time = time_diff(&start, &end);

    // Calcular tempo médio por acesso
    double avg_time = total_time / (P * I);

    printf("Tempo médio por acesso: %.6f segundos\n", avg_time);

    // Liberar memória do vetor
    free(vector);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <número de páginas> <número de iterações>\n", argv[0]);
        return 1;
    }

    int P = atoi(argv[1]);
    int I = atoi(argv[2]);

    accessPages(P, I);

    return 0;
}


/*
    Neste programa, é feita a alocação de um vetor de inteiros grande o suficiente para armazenar o número necessário de páginas. 
    O tamanho das páginas é determinado usando a função sysconf(_SC_PAGESIZE), que retorna o tamanho das páginas no sistema.
    Em seguida, é realizado o acesso às páginas no vetor, de acordo com o número de páginas e iterações especificado. 
    A medição do tempo é feita utilizando a função gettimeofday para obter o tempo de início e fim do processamento. 
    O tempo total é calculado usando a função time_diff fornecida anteriormente.
    Finalmente, é calculado o tempo médio por acesso dividindo o tempo total pelo número total de acessos (P * I) e exibido na saída.
*/