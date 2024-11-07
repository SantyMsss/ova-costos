#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "ejemplojni_lib_JavaCostos.h"

// Definición de la constante MAX_MESES
#define MAX_MESES 12

// Prototipos de las funciones auxiliares
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico);
float calcular_precio_venta(float* total_costo_produccion);
void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion);

// Implementación de la función nativa que Java llamará
JNIEXPORT void JNICALL Java_ejemplojni_lib_JavaCostos_calcularValores
  (JNIEnv *env, jobject obj, jfloat a, jfloat b, jint meses, jint meses_pronostico) {

    float total_pronostico = 0;
    float total_costo_produccion = 0;
    float precio_venta = 0;

    // Llamada a las funciones auxiliares
    calcular_pronostico(a, b, meses, meses_pronostico, &total_pronostico);
    precio_venta = calcular_precio_venta(&total_costo_produccion);
    
    // Llamar a la función generar_estado_resultados con los valores calculados
    generar_estado_resultados(total_pronostico, precio_venta, total_costo_produccion);
}

// Implementación de la función nativa generarEstadoResultados
JNIEXPORT void JNICALL Java_ejemplojni_lib_JavaCostos_generarEstadoResultados
  (JNIEnv *env, jobject obj, jfloat total_pronostico, jfloat precio_venta, jfloat total_costo_produccion) {
    
    generar_estado_resultados(total_pronostico, precio_venta, total_costo_produccion);
}

// Función para calcular el pronóstico
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico) {
    const char* meses_nombres[MAX_MESES] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    // Lógica para calcular el pronóstico
    for (int i = 0; i < meses_pronostico; i++) {
        *total_pronostico += (a * b);  // Ejemplo de cálculo, modifica según la lógica real
        printf("Pronóstico para %s: %.2f\n", meses_nombres[i % MAX_MESES], *total_pronostico);
    }
}

// Función para calcular el precio de venta
float calcular_precio_venta(float* total_costo_produccion) {
    float precio_venta = *total_costo_produccion * 1.2;  // Ejemplo de margen de ganancia del 20%
    return precio_venta;
}

// Función para generar el estado de resultados
void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion) {
    printf("Estado de Resultados:\n");
    printf("Total pronóstico: %.2f\n", total_pronostico);
    printf("Precio de venta: %.2f\n", precio_venta);
    printf("Total costo de producción: %.2f\n", total_costo_produccion);
}

