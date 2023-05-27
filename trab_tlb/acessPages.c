#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void access_pages(int num_pages, int num_iterations) {
    int i, j;
    int *pages = malloc(num_pages * sizeof(int));

    // Inicializa as páginas
    for (i = 0; i < num_pages; i++) {
        pages[i] = i;
    }

    struct timeval start, end;
    float total_time = 0.0f;

    for (i = 0; i < num_iterations; i++) {
        gettimeofday(&start, NULL);

        // Acessa todas as páginas
        for (j = 0; j < num_pages; j++) {
            int page = pages[j];
            // Faz algo com a página
            // ...
        }

        gettimeofday(&end, NULL);
        float iteration_time = time_diff(&start, &end);
        total_time += iteration_time;
    }

    float avg_time = total_time / num_iterations;
    printf("Tempo médio por acesso: %.2f ms\n", avg_time);

    free(pages);
}