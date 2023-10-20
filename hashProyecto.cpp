#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define TAMANIO_TABLA 10
#define ELIMINADO_PERSONA (persona*)(0xFFFFFFFFFFFFUL)

typedef struct {
    char nombre[20];
    int edad;
} persona;

persona *hash_tabla[TAMANIO_TABLA];

unsigned int hash(char *nombre) {
    unsigned int valor_hash = 0;
    int tamanio = strlen(nombre);
    for (int i = 0; i < tamanio; i++) {
        valor_hash = valor_hash + nombre[i];
        valor_hash = valor_hash * nombre[i] % TAMANIO_TABLA;
    }
    return valor_hash;
}

// Inicializa la tabla de hash
void iniciar_tabla_hash() {
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        hash_tabla[i] = NULL;
    }
}

// Imprime la tabla de hash de manera ordenada
void imprimir_tabla_hash() {
    printf("indice\tNombre\t\tEdad\n");
    printf("---------------------------\n");
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        if (hash_tabla[i] == NULL) {
            printf("%d\t-----\t\t-----\n", i);
        } else if (hash_tabla[i] == ELIMINADO_PERSONA) {
            printf("%d\t<eliminado>\t<eliminado>\n", i);
        } else {
            printf("%d\t%s\t\t%d\n", i, hash_tabla[i]->nombre, hash_tabla[i]->edad);
        }
    }
    printf("---------------------------\n");
}

// Inserta una persona en la tabla de hash, manejando colisiones
bool insertar_tabla_hash(persona *p) {
    if (p == NULL) {
        return false;
    }
    int index = hash(p->nombre);  // Calcula el índice en la tabla de hash utilizando la función de hash.

    for (int i = 0; i < TAMANIO_TABLA; i++) {
        int intento = (i + index) % TAMANIO_TABLA;  // Calcula un índice ajustado para manejar colisiones.

        if (hash_tabla[intento] == NULL || hash_tabla[intento] == ELIMINADO_PERSONA) {
            // Si la posición está vacía o marcada como eliminada, inserta la persona en esa posición.
            hash_tabla[intento] = p;
            return true;
        }
    }

    return false;
}

// Busca una persona en la tabla de hash
persona *buscar_tabla_hash(char *nombre) {
    int index = hash(nombre);
    for (int i = 0; i < TAMANIO_TABLA; i++) {
        int intento = (i + index) % TAMANIO_TABLA;
        if (hash_tabla[intento] == NULL) {
            continue;
        }
        if (hash_tabla[intento] == ELIMINADO_PERSONA) {
            continue;
        }
        if (strcmp(hash_tabla[intento]->nombre, nombre) == 0) {
            return hash_tabla[intento];
        }
    }
    return NULL;
}

// Elimina una persona de la tabla de hash
persona *eliminar_tabla_hash(char *nombre) {
    int index = hash(nombre);  // Calcula el índice en la tabla de hash utilizando la función de hash.

    for (int i = 0; i < TAMANIO_TABLA; i++) {
        int intento = (i + index) % TAMANIO_TABLA;  // Calcula un índice ajustado para manejar colisiones.

        if (hash_tabla[intento] == NULL) {
            continue;  // Si la posición está vacía, pasa a la siguiente iteración del bucle.
        }
        if (hash_tabla[intento] == ELIMINADO_PERSONA) {
            continue;  // Si la posición está marcada como eliminada, pasa a la siguiente iteración del bucle.
        }
        if (strcmp(hash_tabla[intento]->nombre, nombre) == 0) {
            // Si se encuentra la persona con el nombre dado, se marca como eliminada y se devuelve.
            persona *aux = hash_tabla[intento];
            hash_tabla[intento] = ELIMINADO_PERSONA;
            return aux;
        }
    }

    return NULL;
}


int main() {
    iniciar_tabla_hash();
    imprimir_tabla_hash();
    printf("\n");

	// Agrego personas
    persona p1 = {"Esteban", 20};
    persona p2 = {"Rafael", 30};
    persona p3 = {"Florencia", 12};
    persona p4 = {"Michael", 45};
    persona p5 = {"Marcos", 212};

	// Inserto las personas agregadas
    insertar_tabla_hash(&p1);
    insertar_tabla_hash(&p2);
    insertar_tabla_hash(&p3);
    insertar_tabla_hash(&p4);
    insertar_tabla_hash(&p5);

    imprimir_tabla_hash();

    // Buscar persona 1
    persona *tmb = buscar_tabla_hash("Esteban");
    if (tmb != NULL) {
        printf("Persona encontrada: %s, Edad: %d\n", tmb->nombre, tmb->edad);
    } else {
        printf("Persona no encontrada\n");
    }

    // Buscar persona que no existe
    persona *tmb2 = buscar_tabla_hash("Ejemplo");
    if (tmb2 != NULL) {
        printf("Persona encontrada: %s, Edad: %d\n", tmb2->nombre, tmb2->edad);
    } else {
        printf("Persona no encontrada\n");
    }

    // Eliminar persona 1
    persona *tmb3 = eliminar_tabla_hash("Esteban");
    if (tmb3 != NULL) {
        printf("Persona eliminada: %s, Edad: %d\n", tmb3->nombre, tmb3->edad);
        free(tmb3); // Liberar memoria de la persona eliminada
    } else {
        printf("Persona no encontrada\n");
    }

    imprimir_tabla_hash();
    

    return 0;
}

