#include <iostream>
#include <chrono>
#include <omp.h>
using namespace std;
//Para hacerlo sin paralalelismo, descomenta el primer main y comenta el segundo main
/*
int main()
{

    int loop_num = 0;
    cout << "Cuantos digitos de Pi quieres?: ";
    cin >> loop_num;

    auto start = std::chrono::system_clock::now();

    double nu_pi = 4.0;

    bool chequeo = false;

    int den =  3;

    for (int i = 0; i < loop_num; i++){
        if (chequeo){
            nu_pi += (4.0/den);
            chequeo = false;
            den += 2;
        }else{
            nu_pi -= (4.0/den);
            chequeo = true;
            den += 2;
        }

    }

    cout << "El calculo de PI es: "<< nu_pi << endl;

    auto end = std::chrono::system_clock:: now();

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;
}

*/

int main()
{

    int loop_num = 0;
    cout << "Cuantos digitos de Pi quieres?: ";
    cin >> loop_num;

    auto start = std::chrono::system_clock::now();

    double nu_pi = 4.0;

    bool chequeo = false;

    int den =  3;
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < loop_num; i++){
            if (chequeo){
                nu_pi += (4.0/den);
                chequeo = false;
                den += 2;
            }else{
                nu_pi -= (4.0/den);
                chequeo = true;
                den += 2;
            }

        }
    }

    cout << "El calculo de PI es: "<< nu_pi << endl;

    auto end = std::chrono::system_clock:: now();

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;
}
