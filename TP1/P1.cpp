/*
Dada una cantidad en pesos, obtener la equivalencia en d�lares, asumiendo que la
unidad cambiar�a es un dato desconocido.
*/
#include <stdio.h>

int main() {
    float cantidadPesos, tasaCambio, cantidadDolares;
    
    printf("Ingresa la cantidad en pesos: ");
    scanf("%f", &cantidadPesos);

    printf("Ingresa la tasa de cambio (pesos por dolar): ");
    scanf("%f", &tasaCambio);

    cantidadDolares = cantidadPesos / tasaCambio;
    printf("%.2f pesos equivalen a %.2f dolares\n", cantidadPesos, cantidadDolares);

    return 0;
}

