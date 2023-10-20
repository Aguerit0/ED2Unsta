/*
En un hospital existen tres áreas: Ginecología, Pediatría, Traumatología. El
presupuesto anual del hospital se reparte conforme a la sig. tabla:
Área Porcentaje del presupuesto
Ginecología 40%
Traumatología 30%
Pediatría 30%
Obtener la cantidad de dinero que recibirá cada área, para cualquier monto presupuestal
*/
#include <stdio.h>

int main() {
    float presupuestoTotal;
    float ginecologia, traumatologia, pediatria;

    printf("Ingresa el monto del presupuesto anual: ");
    scanf("%f", &presupuestoTotal);

    ginecologia = presupuestoTotal * 0.40; // 40%
    traumatologia = presupuestoTotal * 0.30; // 30%
    pediatria = presupuestoTotal * 0.30; // 30%

    printf("Cantidad para Ginecologia: %.2f\n", ginecologia);
    printf("Cantidad para Traumatologia: %.2f\n", traumatologia);
    printf("Cantidad para Pediatria: %.2f\n", pediatria);

    return 0;
}

