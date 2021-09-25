#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>


int main(){
    srand(time(NULL));
    int arreglof[10];
    int arreglos[10];
	int numt; //hilos
	int i;
	int tam = sizeof(arreglof) / sizeof(arreglof[0]);

	#pragma omp parallel
	{
        int tnum;

		tnum=omp_get_thread_num();

            #pragma omp parallel for
            for (i = 0; i<tam; i++){
                arreglof[i] = rand();
            }

            #pragma omp parallel for
            for (i = 0; i<tam; i++){
                printf("Elemento #%d del hilo %d\n", arreglof[i], tnum);
            }


            #pragma omp parallel for
                for (i = 0; i<tam; i++){
                    arreglos[i] = rand();
                }

                #pragma omp parallel for
                for (i = 0; i<tam; i++){
                    printf("Elemento #%d del hilo %d\n", arreglos[i], tnum);
                }

	}

	return 0;
}
