
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

void Push(Nodo*&, int);
void Pop(Nodo*&);
void Add(Nodo*&, int);
void Remove(Nodo*&);
Nodo* fin = NULL;

int main()
{

    //Declaración de variables
    int i=1, valor = 0;
    Nodo* pila = NULL;
    Nodo* inicio = NULL;

    char s;
    //srand(time(NULL));

    for (i = 1; i <= 5; i++)
    {
        valor = rand() % 90+1;

        Push(pila, valor);
    }

    cout << pila->valor << endl;

    do {
        cout << "Desea sacar un valor (s/n): ";
        cin >> s;
        if (s == 's') {
            Pop(pila);
            Add(inicio, pila->valor);
            if (pila == NULL) {
                cout << "La pila esta vacia" << endl;
                s = 'n';
            }
            else {
                cout << "---------------------- peek: " << pila->valor << endl;
            }
        }


    } while ((s == 's'));

    cout << "--------------- inicio: " << inicio->valor << endl;
    cout << "--------------- fin: " << fin->valor << endl;

    system("PAUSE");

    /*while (!numero_aleatorio.empty())
    {
        cout << "    " <<numero_aleatorio.top() << "    "<< endl;
        numero_aleatorio.pop();
    }*/

    return 0;
}

void Push(Nodo*& pila, int v) {
    Nodo* push = new Nodo();
    push->valor = v;
    push->siguiente = pila;
    pila = push;
}


void Pop(Nodo*& pila) {
    int v = NULL;
    Nodo* pop = pila;
    v = pop->valor;
    pila = pop->siguiente;
    /*if(pila == NULL){
    }*/
    delete pop;
}

void Add(Nodo*& inicio, int v) {
    Nodo* add = new Nodo();
    add->valor = v;
    add->siguiente = NULL;
    if (inicio == NULL) {
        inicio = add;
    }
    else {
        fin->siguiente = add;
    }
    fin = add;
}
void Remove(Nodo*& inicio) {
    int v;
    Nodo* fin = NULL;
    v = inicio->valor;
    Nodo* cola = inicio;

    if (inicio == fin) {
        inicio = NULL;
        fin = NULL;
    }
    else {
        inicio = inicio->siguiente;
    }
    delete cola;
}