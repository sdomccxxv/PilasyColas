#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Pila.h"

using namespace std;

int main()
{
    PyC* pila1 = new PyC();
    int i = 1, valor = 0, min = 1, max = 90;
    
    clock_t start, diff;
    int elapsedsec;
    int sec = 2;
    int iterations = 0;

    while (iterations < 5) {
        start = clock();

        while (1) {
            diff = clock() - start;
            elapsedsec = diff / CLOCKS_PER_SEC;

            if (elapsedsec >= sec) {

                srand(time(NULL));

                for (i = 1; i <= 5; i++)
                {
                    valor = min + rand() % (max - min + 1);

                    pila1->Add(valor);
                }

                pila1->showC();
                pila1->Push(pila1->Remove());
                pila1->showC();
                pila1->show();

                iterations++;
                break;
            }
        }
    }   
    
    delete pila1;
    return 0;
}
