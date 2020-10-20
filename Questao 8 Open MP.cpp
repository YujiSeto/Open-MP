// Aluno Rodrigo Yuji

#include <iostream>
#include <omp.h> 
#include <stdio.h>

int main(int argc, char* argv[])
{
    int nthreads, i, tid;
    float total;

    #pragma omp parallel shared(nthreads) private(i,tid,total)
    {
        tid = omp_get_thread_num();
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Numero de threads = %d\n", nthreads);
        }
        printf("Thread %d executando...\n", tid);
        #pragma omp barrier 
        total = 0.0;
        #pragma omp for schedule(dynamic,10) 
        for (i = 0; i < 1000000; i++) {
            total = total + i * 1.0;
        }
        printf("Thread %d terminou! Total= %e\n", tid, total);
    }
    return 0;
}