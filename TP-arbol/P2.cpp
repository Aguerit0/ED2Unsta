/*
"Desarrolle un problema que permita cargar un �rbol de b�squeda binaria, pero que
permita ingresar claves repetidas. El criterio de inserci�n en el �rbol debe ser 
que las claves menores se coloquen a la izquierda y las claves mayores o iguales 
a la derecha. Luego, muestre el �rbol resultante."
*/

#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int info;
    struct nodo* izq;
    struct nodo* der;
};

struct nodo* raiz = NULL;

// Funci�n para insertar una clave en el �rbol
void insertar(struct nodo** raiz, int x) {
    if (*raiz == NULL) {
        struct nodo* nuevo = (struct nodo*)malloc(sizeof(struct nodo));
        nuevo->info = x;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        *raiz = nuevo;
    } else {
        if (x < (*raiz)->info) {
            insertar(&((*raiz)->izq), x);
        } else {
            insertar(&((*raiz)->der), x);
        }
    }
}

// Funci�n para imprimir el �rbol en orden
void imprimirEnOrden(struct nodo* reco) {
    if (reco != NULL) {
        imprimirEnOrden(reco->izq);
        printf("%i-", reco->info);
        imprimirEnOrden(reco->der);
    }
}

int main() {
    int opcion, numero;

    do {
        printf("\nMenu:\n");
        printf("1- INSERTAR UNA CLAVE\n");
        printf("2- MOSTRAR EN ORDEN\n");
        printf("3- SALIR\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                printf("Ingrese una clave: ");
                scanf("%d", &numero);
                insertar(&raiz, numero);
                break;
            case 2:
                system("cls");
                printf("Arbol en orden: ");
                imprimirEnOrden(raiz);
                printf("\n");
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

