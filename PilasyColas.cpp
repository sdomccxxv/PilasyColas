#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include "Pila.h"

using namespace std;

int main()
{
    PyC* pila1 = new PyC();
    int i = 1, valor = 0, min = 1, max = 90;
    /*time_t t;

    t = time(NULL);
    Sleep(2000);*/

    srand(time(NULL));

    for (i = 1; i <= 5; i++)
    {
        valor = min + rand()%(max-min+1);

        pila1->Add(valor);
    }

    pila1->showC();
    
    char s;
    do {
        cout << "Desea sacar un valor (s/n): ";
        cin >> s;
        if (s == 's') {
            pila1->Push(pila1->Remove());
        }
    } while ((s == 's'));
    
    pila1->showC();
    pila1->show();
    
    delete pila1;
    return 0;
}
