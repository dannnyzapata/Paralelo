#include <iostream>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define ITE 20
using namespace std;

void gotoxy (int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);

}

int main(int argc, char *argv[])
{
    int equipo1[ITE];
    int equipo2[ITE];
    int equipo3[ITE];

    int sum1 = 0, sum2 = 0, sum3 = 0;

    cout<<"Inciando la carrera (equipo-hilo)...... 3,2,1";

    #pragma omp parallel
    {
        srand(int(time(NULL))^omp_get_thread_num());
        #pragma omp for ordered
        for (int i = 0; i<ITE; ++i)
        {
            equipo1[i] = rand()%40 + 10;
            sum1 += equipo1[i];
            #pragma omp ordered
            gotoxy(i*5,2);
            cout<<"1-"<< omp_get_thread_num();
        }
        #pragma omp for ordered
        for (int i = 0; i<ITE; ++i)
        {
            equipo2[i] = rand()%40 + 10;
            sum2 += equipo2[i];
            #pragma omp ordered
            gotoxy(i*5,4);
            cout<<"2-"<< omp_get_thread_num();
        }
        #pragma omp for ordered
        for (int i = 0; i<ITE; ++i)
        {
            equipo3[i] = rand()%40 + 10;
            sum3 += equipo3[i];
            #pragma omp ordered
            gotoxy(i*5,6);
            cout<<"3-"<< omp_get_thread_num();
        }
    }
    cout<<"\n\nTiempo de la carrera del equipo 1: "<<(float)sum1/60<<" min"<<endl;
    cout<<"Tiempo de la carrera del equipo 2: "<<(float)sum2/60<<" min"<<endl;
    cout<<"Tiempo de la carrera del equipo 3: "<<(float)sum3/60<<" min"<<endl;
    return 0;
}
