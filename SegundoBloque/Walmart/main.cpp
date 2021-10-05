#include <iostream>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    srand (int(time(NULL)));
    int numDeProd = rand()&100 + 100, i =0, sum = 0, temp = 0, c = 7;
    int precio[numDeProd];

    cout<<"Iniciando el cobro"<<endl;
    cout<<"\nNumero de Productos:"<< numDeProd<<endl;

    #pragma omp parallel
    {
        for(i=0; i<numDeProd; ++i)
        {
            precio[i] = rand()%50 + 50;
            sum += precio[i];
            if (i==c)
            {
                cout<<"Productos de 8 en 8: "<< sum-temp<<", cobrado por cajero: "<< omp_get_thread_num() << endl;
                c += 8;
                temp = sum;
            }
        }
    }
    cout<< "\n\n\nPrecio final de todos los productos: "<< sum << endl;
    return 0;
}
