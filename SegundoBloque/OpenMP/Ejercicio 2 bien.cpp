#include <iostream>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(int argc, char *argv[]){
    int arrl[10];
    int sum = 0;
    #pragma omp parallel shared (arrl)
    {
        #pragma omp for schedule (static,3) ordered reduction (+:sum)
        for (int i=0; i<100;i++){
            arrl[i] = rand()%10;
            #pragma omp critical
            sum+=arrl[i];
            #pragma omp ordered
            cout <<"El valor de arr1["<<i<<"]es: " << arr1[i] << endl << "impreso desde el hilo..."<< omp_get_thread_num () << endl;
            cout <<"la suma parcial del arreglo es de: " <<sum << endl<<endl;
        }
    }
     cout<< " La suma total es:" << sum <<endl;
}
