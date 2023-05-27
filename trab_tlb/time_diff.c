#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Função para calcular a diferença de tempo em milissegundos
float time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000.0f + (end->tv_usec - start->tv_usec) / 1000.0f;
}