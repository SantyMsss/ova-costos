#include <stdio.h>
#include "JavaCostos.h"

#define MAX_MESES 12

// Declaración de las funciones originales
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico);
float calcular_precio_venta(float* total_costo_produccion);
void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion);
void calcular_valores(int meses, int meses_pronostico);

// Implementación de la función JNI
JNIEXPORT void JNICALL Java_JavaCostos_calcularValores(JNIEnv *env, jobject obj, jint meses, jint mesesPronostico) {
    calcular_valores((int)meses, (int)mesesPronostico);
}

// Implementación de calcular_valores
void calcular_valores(int meses, int meses_pronostico) {
    int X[MAX_MESES];
    float Y[MAX_MESES];
    int X2[MAX_MESES];
    float Y2[MAX_MESES];
    float XY[MAX_MESES];

    for (int i = 0; i < meses; i++) {
        X[i] = i + 1;
    }

    for (int i = 0; i < meses; i++) {
        printf("Ingrese el valor de ventas (Y) para el mes %d: ", X[i]);
        scanf("%f", &Y[i]);
    }

    for (int i = 0; i < meses; i++) {
        X2[i] = X[i] * X[i];
        Y2[i] = Y[i] * Y[i];
        XY[i] = X[i] * Y[i];
    }

    printf("\n%-5s %-12s %-6s %-12s %-8s\n", "Mes", "Ventas (Y)", "X^2", "Y^2", "X * Y");
    for (int i = 0; i < meses; i++) {
        printf("%-5d %-12.2f %-6d %-12.2f %-8.2f\n", X[i], Y[i], X2[i], Y2[i], XY[i]);
    }

    int sumaX = 0, sumaX2 = 0;
    float sumaY = 0, sumaY2 = 0, sumaXY = 0;
    for (int i = 0; i < meses; i++) {
        sumaX += X[i];
        sumaY += Y[i];
        sumaX2 += X2[i];
        sumaY2 += Y2[i];
        sumaXY += XY[i];
    }

    printf("\nSumas totales:\n");
    printf("Suma de X: %d\n", sumaX);
    printf("Suma de Y: %.2f\n", sumaY);
    printf("Suma de X^2: %d\n", sumaX2);
    printf("Suma de Y^2: %.2f\n", sumaY2);
    printf("Suma de X * Y: %.2f\n", sumaXY);

    float b = (meses * sumaXY - sumaX * sumaY) / (meses * sumaX2 - sumaX * sumaX);
    float a = (sumaY - b * sumaX) / meses;

    printf("\nEl valor de b es: %.6f\n", b);
    printf("El valor de a es: %.6f\n", a);
    
    float total_pronostico = 0.0;
    calcular_pronostico(a, b, meses, meses_pronostico , &total_pronostico);

    float total_costo_produccion = 0.0; 
    float precio_venta = calcular_precio_venta(&total_costo_produccion); 

    generar_estado_resultados(total_pronostico, precio_venta, total_costo_produccion);
}

// Implementación de calcular_pronostico
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico) {
    *total_pronostico = 0.0;
    for (int i = 1; i <= meses_pronostico; i++) {
        float pronostico = a + b * (meses_actuales + i);
        *total_pronostico += pronostico;
        printf("Pronóstico para el mes %d: %.2f\n", meses_actuales + i, pronostico);
    }
    printf("Total pronóstico de ventas para los próximos %d meses: %.2f\n", meses_pronostico, *total_pronostico);
}

// Implementación de calcular_precio_venta
float calcular_precio_venta(float* total_costo_produccion) {
    printf("Ingrese el costo de producción total: ");
    scanf("%f", total_costo_produccion);

    float margen_utilidad;
    printf("Ingrese el margen de utilidad (porcentaje): ");
    scanf("%f", &margen_utilidad);

    float precio_venta = *total_costo_produccion * (1 + margen_utilidad / 100);
    printf("Precio de venta calculado: %.2f\n", precio_venta);
    return precio_venta;
}

// Implementación de generar_estado_resultados
void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion) {
    float ingresos_totales = total_pronostico * precio_venta;
    float costo_ventas = total_costo_produccion;
    float utilidad_bruta = ingresos_totales - costo_ventas;

    printf("\nEstado de Resultados:\n");
    printf("Ingresos Totales: %.2f\n", ingresos_totales);
    printf("Costo de Ventas: %.2f\n", costo_ventas);
    printf("Utilidad Bruta: %.2f\n", utilidad_bruta);
}

