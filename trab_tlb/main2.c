#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sched.h>

float time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000.0f + (end->tv_usec - start->tv_usec) / 1000.0f;
}

void access_pages(int num_pages, int num_iterations) {
    int i, j;
    int *pages = malloc(num_pages * sizeof(int));

    for (i = 0; i < num_pages; i++) {
        pages[i] = i;
    }

    struct timeval start, end;
    float total_time = 0.0f;

    for (i = 0; i < num_iterations; i++) {
        gettimeofday(&start, NULL);

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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: ./programa <número de páginas> <número de iterações>\n");
        return 1;
    }

    int num_pages = atoi(argv[1]);
    int num_iterations = atoi(argv[2]);

    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask);
    sched_setaffinity(0, sizeof(cpu_set_t), &mask);

    access_pages(num_pages, num_iterations);

    return 0;
}