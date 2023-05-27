#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: ./programa <número de páginas> <número de iterações>\n");
        return 1;
    }

    int num_pages = atoi(argv[1]);
    int num_iterations = atoi(argv[2]);

    access_pages(num_pages, num_iterations);

    return 0;
}


/*
    gcc programa.c -o programa
    ./programa <número de páginas> <número de iterações>

    Neste exemplo, o programa recebe o número de páginas e o número de iterações como parâmetros de linha de comando.
    A função access_pages é responsável por criar e inicializar um array de páginas e, em seguida, realizar o acesso a essas páginas. 
    O tempo é medido usando as funções gettimeofday para obter o tempo de início e fim de cada iteração. 
    O tempo total é acumulado e, no final, é calculado o tempo médio por acesso.
    Compile e execute o programa, passando o número de páginas e o número de iterações como argumentos da linha de comando:
    gcc programa.c -o programa
    ./programa <número de páginas> <número de iterações>

    Certifique-se de substituir <número de páginas> e <número de iterações> pelos valores desejados. 
    O programa imprimirá o tempo médio por acesso em milissegundos.

    Em relação ao script.py

    Neste exemplo, o script utiliza o módulo subprocess para chamar o programa em C com os diferentes tamanhos de página e obter o tempo médio por acesso. 
    O programa em C é assumido como o mesmo exemplo anterior fornecido.

    O script executa o programa com os tamanhos de página de 1 até 1000 (você pode ajustar o valor máximo conforme necessário) e calcula a média do tempo de 
    acesso para cada tamanho de página. Os resultados são armazenados em um dicionário e, em seguida, são impressos na tela.
    Certifique-se de que o programa em C esteja compilado e chamado programa no mesmo diretório em que você está executando o script Python. 
    Execute o script e ele exibirá os resultados para cada tamanho de página testado.

    Para redirecionar a saída do script Python para um arquivo, você pode usar o operador de redirecionamento > no terminal ao executar o script. 
    Aqui está um exemplo
    python script.py > output.txt

    --------------------------
    Agora você pode executar o script Python para plotar os resultados usando o seguinte comando:
    Certifique-se de fornecer o nome do arquivo de saída gerado anteriormente como argumento para o script Python. 
    Isso plotará um gráfico com os tamanhos de página no eixo x e o
    tempo médio por acesso no eixo y. A janela do gráfico será exibida, permitindo que você visualize os resultados.
    python script.py output.txt
    -------------------------
    
    main2.c
    A principal adição é a inclusão da biblioteca <sched.h> no início do código. Em seguida, dentro da função main(), um conjunto de CPU (cpu_set_t) 
    é criado e inicializado com CPU_ZERO() e CPU_SET(). Em seguida, sched_setaffinity() é usado para definir a afinidade do processo para o núcleo 0 
    usando o conjunto de CPU criado.

    Ao executar o programa agora, ele será executado sempre no mesmo núcleo da CPU, mantendo a consistência da TLB (Translation Lookaside Buffer) e 
    evitando a troca de CPU durante os escalonamentos. Isso pode ajudar a obter resultados mais consistentes em relação ao desempenho de acesso às páginas.



*/