#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <omp.h>

using namespace std;

//Para hacerlo sin paralalelismo, descomenta el primer main y comenta el segundo main
/*
int main()
{
    ofstream labell ("salida.dat");
    long long int n;
    int i;

    double sum = 0;

    cout<<"Numero de Terminos de la serie: ";
    cin >> n;

    auto start = std::chrono::system_clock::now();

    labell.setf(ios::fixed);
    labell.precision(10);

    cout.setf(ios::fixed);
    cout.precision(10);

    for (i=0; i < n; i++){
        sum = sum + pow(-1,i) * (4.0/(2.0*i+1));
    }

    cout<< sum<< "\n";

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;
}
*/

int main(){
    ofstream labell ("salida.dat");
    long long int n;
    int i;

    double sum = 0;

    cout<<"Numero de Terminos de la serie: ";
    cin >> n;
    auto start = std::chrono::system_clock::now();

    #pragma omp parallel
    {
        labell.setf(ios::fixed);
        labell.precision(10);

        cout.setf(ios::fixed);
        cout.precision(10);

        #pragma omp for
        for (i=0; i < n; i++){
            sum = sum + pow(-1,i) * (4.0/(2.0*i+1));
        }
    }
    cout<< sum<< "\n";

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;

}
