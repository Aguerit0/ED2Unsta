#include <stdio.h>
#include <windows.h>

int auxX, auxY;

struct nodo {
    int info;
    struct nodo* hijo_izq;
    struct nodo* hijo_der;
};

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void mostrarArbol(struct nodo* p, int auxY);

int main(int argc, char** argv) {
    struct nodo* raiz = (struct nodo*)malloc(sizeof(struct nodo)); // Crear un nodo raiz
    struct nodo* izq = (struct nodo*)malloc(sizeof(struct nodo));  // Crear nodos izquierdo y derecho
    struct nodo* der = (struct nodo*)malloc(sizeof(struct nodo));

    raiz->info = 4;
    raiz->hijo_izq = izq;
    raiz->hijo_der = der;

    izq->info = 3;
    der->info = 5;

    izq->hijo_izq = izq->hijo_der = NULL;
    der->hijo_izq = der->hijo_der = NULL;

    auxX = auxY = 0; // Inicializar auxX y auxY

    mostrarArbol(raiz, auxY);

    free(raiz);
    free(izq);
    free(der);

    return 0;
}

void mostrarArbol(struct nodo* p, int auxY) {
    if (p == NULL) {
        return;
    } else {
        auxX += 5;
        mostrarArbol(p->hijo_der, auxY + 1);
        gotoxy(auxX, auxY);
        printf("%d\n\n", p->info);
        mostrarArbol(p->hijo_izq, auxY + 1);
    }
}

