#include <iostream>
#include <cmath>
#include <limits>
#include <chrono>
#include <omp.h>

using namespace std;

//Para hacerlo sin paralalelismo, descomenta el primer main y comenta el segundo main
/*
int main()
{
    auto start = std::chrono::system_clock::now();

    long double a0 = 1.0, b0 = 1/sqrt(2), t0 = 1.0/4.0, p0 = 1.0;
    long double an, bn, pn, tn;
    int i = 0;
    long double pi;
    typedef std::numeric_limits<double> dbl;
    std::cout.precision(dbl::max_digits10);
    while (i<4)
    {
        an = (a0 + b0)/2.0;
        bn = sqrt(a0 * b0);
        tn = t0 - (p0 * (a0-an)*(a0-an));
        pn = 2*p0;
        a0 = an, b0 = bn, t0 = tn;
        pi = (an+bn) * (an+bn) / (4*tn);
        std::cout<<"La Aproximación de pi numero "<< i + 1 << " es: ";
        std::cout<<pi<<std::endl;
        i++;
    }

    auto end = std::chrono::system_clock:: now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;
}
*/

int main()
{
    auto start = std::chrono::system_clock::now();

    long double a0 = 1.0, b0 = 1/sqrt(2), t0 = 1.0/4.0, p0 = 1.0;
    long double an, bn, pn, tn;
    int i = 0;
    long double pi;
    #pragma omp parallel
    {
        typedef std::numeric_limits<double> dbl;
        std::cout.precision(dbl::max_digits10);
        #pragma omp while(1)
        while (i < 4)
        {
            an = (a0 + b0)/2.0;
            bn = sqrt(a0 * b0);
            tn = t0 - (p0 * (a0-an)*(a0-an));
            pn = 2*p0;
            a0 = an, b0 = bn, t0 = tn;
            pi = (an+bn) * (an+bn) / (4*tn);
            std::cout<<"\nLa Aproximación de pi numero "<< i + 1 << " es: ";
            std::cout<<pi<<std::endl;
            i++;
        }
    }
    auto end = std::chrono::system_clock:: now();
    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout<<"\nDuracion: "<< duration.count()<< "ms" << std::endl;
    return 0;
}
