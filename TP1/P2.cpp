/*
La presión, el volumen y la temperatura de una masa de aire se relacionan por la
fórmula: Masa = (presión * volumen)/ (0.37 * (temperatura + 460))
*/

#include <stdio.h>

int main() {
    float presion, volumen, temperatura, masa;

    printf("Ingresa la presion: ");
    scanf("%f", &presion);

    printf("Ingresa el volumen: ");
    scanf("%f", &volumen);

    printf("Ingresa la temperatura: ");
    scanf("%f", &temperatura);

    masa = (presion * volumen) / (0.37 * (temperatura + 460));

    printf("La masa de aire es: %.2f\n", masa);

    return 0;
}

