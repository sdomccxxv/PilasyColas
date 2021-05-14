#include <iostream>

using namespace std;

class PyC {
private:
    class Nodo {
    public:
        int valor;
        Nodo* siguiente;
    };

    Nodo* raiz;
    Nodo* inicio = NULL;
    Nodo* fin = NULL;
public:
    void Push(int x);
    int Pop();
    void show();

    void Add(int x);
    void showC();
    int Remove();
};

inline void PyC::Push(int x)
{
    Nodo* push = new Nodo();
    push->valor = x;
    if (raiz == NULL)
    {
        raiz = push;
        push->siguiente = NULL;
    }
    else
    {
        push->siguiente= raiz;
        raiz = push;
    }
}

inline void PyC::show()
{
    int suma = 0;
    Nodo* reco = raiz;
    system("cls");
    showC();
    cout << "Pila\n";
    while (reco != NULL)
    {
        cout << reco->valor << " ";
        if (reco->valor >= 0) {
            suma += reco->valor;
        }
        reco = reco->siguiente;
        
    }
    
    cout << "\n";
    cout << "La suma es " << suma << endl;
    cout << "\n";
}

inline int PyC::Pop()
{
    if (raiz != NULL)
    {
        int informacion = raiz->valor;
        Nodo* pop = raiz;
        raiz = raiz->siguiente;
        delete pop;
        return informacion;
    }
    else
    {
        return -1;
    }
}

inline void PyC::Add(int x) {
    Nodo* add = new Nodo();
    add->valor = x;
    add->siguiente = NULL;
    
    if (inicio == NULL) {
        inicio = add;
    }
    else {
        fin->siguiente = add;
    }
    fin = add;
}

inline void PyC::showC()
{
    Nodo* reco = inicio;
    int suma = 0;

    cout << "Caja 1\n";
    while (reco != NULL) 
    {
        cout << reco->valor << endl;
        reco = reco->siguiente;

    }

    cout << "\n";
}

inline int PyC::Remove() {
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
    return v;
}