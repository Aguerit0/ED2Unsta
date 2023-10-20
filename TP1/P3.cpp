/*
 Calcular el número de pulsaciones que una persona debe tener por cada 10 segundos
de ejercicio, si la fórmula es: num. Pulsaciones = (220 - edad)/10
*/

#include <stdio.h>

int main() {
    int edad;
    float numPulsaciones;

    printf("Ingresa tu edad: ");
    scanf("%d", &edad);

    numPulsaciones = (220 - edad) / 10.0;

    printf("El numero de pulsaciones por cada 10 segundos de ejercicio es: %.2f\n", numPulsaciones);

    return 0;
}

