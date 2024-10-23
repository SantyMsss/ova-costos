#include <stdio.h>

#define MAX_MESES 12

void calcular_valores(int meses) {
    int X[MAX_MESES];
    float Y[MAX_MESES];
    int X2[MAX_MESES];
    float Y2[MAX_MESES];
    float XY[MAX_MESES];

    // Asignar valores de X según el número de meses seleccionado
    for (int i = 0; i < meses; i++) {
        X[i] = i + 1;
    }

    // Ingresar los valores de Y (ventas)
    for (int i = 0; i < meses; i++) {
        printf("Ingrese el valor de ventas (Y) para el mes %d: ", X[i]);
        scanf("%f", &Y[i]);
    }

    // Calcular X^2, Y^2 y X * Y
    for (int i = 0; i < meses; i++) {
        X2[i] = X[i] * X[i];
        Y2[i] = Y[i] * Y[i];
        XY[i] = X[i] * Y[i];
    }

    // Mostrar resultados
    printf("\n%-5s %-12s %-6s %-12s %-8s\n", "Mes", "Ventas (Y)", "X^2", "Y^2", "X * Y");
    for (int i = 0; i < meses; i++) {
        printf("%-5d %-12.2f %-6d %-12.2f %-8.2f\n", X[i], Y[i], X2[i], Y2[i], XY[i]);
    }

    // Calcular sumas
    int sumaX = 0, sumaX2 = 0;
    float sumaY = 0, sumaY2 = 0, sumaXY = 0;
    for (int i = 0; i < meses; i++) {
        sumaX += X[i];
        sumaY += Y[i];
        sumaX2 += X2[i];
        sumaY2 += Y2[i];
        sumaXY += XY[i];
    }

    // Mostrar sumas
    printf("\nSumas totales:\n");
    printf("Suma de X: %d\n", sumaX);
    printf("Suma de Y: %.2f\n", sumaY);
    printf("Suma de X^2: %d\n", sumaX2);
    printf("Suma de Y^2: %.2f\n", sumaY2);
    printf("Suma de X * Y: %.2f\n", sumaXY);

    // Calcular el valor de b y a usando las fórmulas
    float b = (meses * sumaXY - sumaX * sumaY) / (meses * sumaX2 - sumaX * sumaX);
    float a = (sumaY - b * sumaX) / meses;

    // Mostrar los valores de a y b
    printf("\nEl valor de b es: %.6f\n", b);
    printf("El valor de a es: %.6f\n", a);
}

int main() {
    int opcion, meses;

    // Mostrar menú
    printf("Seleccione el intervalo de tiempo:\n");
    printf("1. Trimestral (3 meses)\n");
    printf("2. Semestral (6 meses)\n");
    printf("3. Anual (12 meses)\n");
    printf("Ingrese una opción (1, 2 o 3): ");
    scanf("%d", &opcion);

    // Asignar número de meses según la opción
    switch (opcion) {
        case 1:
            meses = 3;
            break;
        case 2:
            meses = 6;
            break;
        case 3:
            meses = 12;
            break;
        default:
            printf("Opción no válida.\n");
            return 1;
    }

    // Llamar a la función para calcular los valores
    calcular_valores(meses);

    return 0;
}
