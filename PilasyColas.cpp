#include <iostream>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
#include <thread>
#include <vector>
#include <chrono>

#include "Pila.h"

using namespace std;

int pilasycolas(int x);

void esperar(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    pilasycolas(n);
}

void hilos(int n) {
    vector<thread> threads(n);

    for (int i = 0; i < n; i++) {
        srand(time(0));
        threads[i] = thread(esperar, i + 1);
    }

    for (int i = 0; i < n; i++) {
        threads[i].join();
    }
}

int main()
{
    hilos(4);

    return 0;
}

int pilasycolas(int x) {
    PyC* pila1 = new PyC();
    int i = 1, valor = 0, min = 1, max = 90;

    clock_t start, diff;
    int elapsedsec, sec = 2, iterations = 0;

    srand(time(0));

    for (i = 1; i <= 200; i++)
    {
        valor = min + rand() % (max - min + 1);

        pila1->Add(valor);
    }

    pila1->showC(x);

    while (iterations <= 201) {
        start = clock();

        while (1) {
            diff = clock() - start;
            elapsedsec = diff / CLOCKS_PER_SEC;

            if (elapsedsec >= sec) {

                pila1->Push(pila1->Remove());
                pila1->show();

                iterations++;
                break;
            }
        }
    }
    delete pila1;
    return 0;
}