#include <stdio.h>

#define MAX_MESES 12

// Se declaran las funciones
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico);
float calcular_precio_venta(float* total_costo_produccion);  
void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion);

void calcular_valores(int meses, int meses_pronostico) {
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
    
    // Llamar a la función para calcular el pronóstico de ventas
    float total_pronostico = 0.0;
    calcular_pronostico(a, b, meses, meses_pronostico , &total_pronostico);

    // Llamar a la función para calcular el precio de venta
    float total_costo_produccion = 0.0; 
    float precio_venta = calcular_precio_venta(&total_costo_produccion); 

    // Generar el estado de resultados
    generar_estado_resultados(total_pronostico, precio_venta, total_costo_produccion);
}
void calcular_pronostico(float a, float b, int meses_actuales, int meses_pronostico, float* total_pronostico) {
    const char* meses_nombres[MAX_MESES] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    printf("\n%-12s %-4s %-12s\n", "Mes", "X", "Pron. Ventas");

    *total_pronostico = 0.0;
    for (int i = 0; i < meses_pronostico; i++) {
        int mes_numero = meses_actuales + i + 1;
        float pronostico = a + b * mes_numero;
        printf("%-12s %-4d %-12.3f\n", meses_nombres[(mes_numero - 1) % MAX_MESES], mes_numero, pronostico);
        *total_pronostico += pronostico;
    }

    printf("TOTAL                %.3f\n", *total_pronostico);
}

float calcular_precio_venta(float* total_costo_produccion) {
    float materia_prima, mano_obra_directa, cif_variables, cif_fijos, porcentaje_utilidad, precio_venta;

    printf("\nPara conocer el precio de venta\n\n");

    // Ingresar los valores de costos por unidad
    printf("Ingrese el costo de Materia Prima por unidad: $");
    scanf("%f", &materia_prima);

    printf("Ingrese el costo de Mano de Obra Directa por unidad: $");
    scanf("%f", &mano_obra_directa);

    printf("Ingrese el costo de CIF Variables por unidad: $");
    scanf("%f", &cif_variables);

    printf("Ingrese el costo total de CIF Fijos: $");
    scanf("%f", &cif_fijos);

    // Calcular el costo total de producción por unidad
    *total_costo_produccion = materia_prima + mano_obra_directa + cif_variables + cif_fijos;

    // Ingresar el porcentaje de utilidad
    printf("Ingrese el porcentaje de utilidad (ejemplo: 0.20 para 20%%): ");
    scanf("%f", &porcentaje_utilidad);

    // Calcular el precio de venta por unidad
    precio_venta = *total_costo_produccion / (1 - porcentaje_utilidad);

    // Mostrar el precio de venta
    printf("\nCOSTO TOTAL\n");
    printf("M.P\t\t$%.2f\n", materia_prima);
    printf("M.O.D\t\t$%.2f\n", mano_obra_directa);
    printf("C.I.F VARIABLES\t$%.2f\n", cif_variables);
    printf("C.I.F FIJOS\t$%.2f\n", cif_fijos);
    printf("TOTAL C PRODUC\t$%.2f\n", *total_costo_produccion);
    printf("\nPRECIO VENTA\t$%.2f\n", precio_venta);

    return precio_venta;
}

void generar_estado_resultados(float total_pronostico, float precio_venta, float total_costo_produccion) {
    float ventas = total_pronostico * precio_venta;
    float costo_venta = total_pronostico * total_costo_produccion; 
    float utilidad_bruta = ventas - costo_venta;

    // Gastos Operacionales
    float gastos_variables, gastos_fijos;
    printf("\nIngrese el gasto variable (gasto de ventas): $");
    scanf("%f", &gastos_variables);
    printf("Ingrese el gasto fijo: $");
    scanf("%f", &gastos_fijos);

    float gastos_operacionales = gastos_variables + gastos_fijos;
    float utilidad_operacional = utilidad_bruta - gastos_operacionales;

    // Gastos Financieros
    float porcentaje_gastos_financieros;
    printf("Ingrese el porcentaje de gastos financieros (ejemplo: 0.05 para 5%%): ");
    scanf("%f", &porcentaje_gastos_financieros);
    float gastos_financieros = ventas * porcentaje_gastos_financieros;

    float utilidad_antes_impuesto = utilidad_operacional - gastos_financieros;

    // Mostrar el estado de resultados
    printf("\n\t\tESTADO RESULTADOS\n\n");
    printf("VENTAS\t\t\t$%.2f\n", ventas);
    printf("COSTO DE VENTA\t\t$%.2f\n", costo_venta);
    printf("UTILIDAD BRUTA\t\t$%.2f\n", utilidad_bruta);
    printf("GASTOS OPERACIONALES\n");
    printf("VARIABLES\t\t$%.2f\n", gastos_variables);
    printf("FIJOS\t\t\t$%.2f\n", gastos_fijos);
    printf("UTIL. OPERACION\t\t$%.2f\n", utilidad_operacional);
    printf("GTOS FINANCIEROS\t$%.2f\n", gastos_financieros);
    printf("UTILIDAD ANTES DE IMPTO\t$%.2f\n", utilidad_antes_impuesto);
}

int main() {
    int opcion, meses, meses_pronostico;
    char continuar;

   do {
    // Mostrar menú
    printf("Seleccione el intervalo de tiempo:\n");
    printf("1. Trimestral (3 meses)\n");
    printf("2. Semestral (6 meses)\n");
    printf("3. Anual (12 meses)\n");
    printf("Ingrese una opcion (1, 2 o 3): ");
    scanf("%d", &opcion);

    // Asignar número de meses según la opción
    switch (opcion) {
        case 1:
            meses = 3;
            meses_pronostico = 3;
            break;
        case 2:
            meses = 6;
            meses_pronostico = 6;
            break;
        case 3:
            meses = 12;
            meses_pronostico = 12;
            break;
        default:
            printf("Opcion no valida.\n");
            return 1;
    }

    // Llamar a la función para calcular los valores
    calcular_valores(meses, meses_pronostico);

    // Preguntar al usuario si desea continuar
        printf("\nDesea realizar otro calculo? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
