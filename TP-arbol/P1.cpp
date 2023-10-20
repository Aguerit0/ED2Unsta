/*
"Desarrolle un programa que incluya funciones para cargar, mostrar y determinar 
cuántos nodos tiene un árbol en el nivel n, con un valor de n que se ingresa 
como parámetro."
*/

#include <stdio.h>
#include <stdlib.h>

// Declaración de las funciones
struct nodo {
    int info;
    struct nodo* izq;
    struct nodo* der;
};

struct nodo* raiz = NULL;

void insertar(struct nodo** raiz, int x);
void imprimirNodos(struct nodo* reco);
int contarNodosEnNivel(struct nodo* reco, int nivel, int nivelObjetivo);

int main() {
    int opcion, numero, nivelObjetivo, nodosEnNivel;

    do {
        printf("\nMenu:\n");
        printf("1- INSERTAR UN NUMERO\n");
        printf("2- MOSTRAR TODOS LOS NODOS\n");
        printf("3- CONTAR NODOS EN UN NIVEL\n");
        printf("4- SALIR\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                printf("Ingrese un numero: ");
                scanf("%d", &numero);
                insertar(&raiz, numero);
                break;
            case 2:
                system("cls");
                printf("Mostrar todos los nodos:\n");
                imprimirNodos(raiz);
                printf("\n");
                break;
            case 3:
                system("cls");
                printf("Ingrese el nivel que desea contar: ");
                scanf("%d", &nivelObjetivo);
                nodosEnNivel = contarNodosEnNivel(raiz, 1, nivelObjetivo);
                printf("Nodos en el nivel %d: %d\n", nivelObjetivo, nodosEnNivel);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}


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

void imprimirNodos(struct nodo* reco) {
    if (reco != NULL) {
        printf("%d ", reco->info);
        imprimirNodos(reco->izq);
        imprimirNodos(reco->der);
    }
}

int contarNodosEnNivel(struct nodo* reco, int nivel, int nivelObjetivo) {
    if (reco == NULL) {
        return 0;
    }
    
    if (nivel == nivelObjetivo) {
        return 1;
    }

    return contarNodosEnNivel(reco->izq, nivel + 1, nivelObjetivo) +
           contarNodosEnNivel(reco->der, nivel + 1, nivelObjetivo);
}

