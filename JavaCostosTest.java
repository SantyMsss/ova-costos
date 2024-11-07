package ejemplojni.lib;

import java.util.Scanner;

public class JavaCostosTest {

    public static void main(String[] args) {
        // Crear una instancia de JavaCostos para llamar a los métodos nativos
        JavaCostos costos = new JavaCostos();
        Scanner scanner = new Scanner(System.in);

        // Pedir al usuario los valores para calcular el pronóstico de costos
        System.out.println("=== Cálculo de Pronóstico de Costos ===");
        System.out.print("Ingresa el costo base (a): ");
        float a = scanner.nextFloat();

        System.out.print("Ingresa la tasa de crecimiento (b): ");
        float b = scanner.nextFloat();

        System.out.print("Ingresa el número de meses actuales: ");
        int meses = scanner.nextInt();

        System.out.print("Ingresa el número de meses a pronosticar: ");
        int mesesPronostico = scanner.nextInt();

        // Llamar al método nativo calcularValores con los datos ingresados
        System.out.println("\nCalculando valores de costos...");
        costos.calcularValores(a, b, meses, mesesPronostico);

        // Pedir al usuario los valores para generar el estado de resultados
        System.out.println("\n=== Generación del Estado de Resultados ===");
        System.out.print("Ingresa el total del pronóstico: ");
        float totalPronostico = scanner.nextFloat();

        System.out.print("Ingresa el precio de venta: ");
        float precioVenta = scanner.nextFloat();

        System.out.print("Ingresa el total de costo de producción: ");
        float totalCostoProduccion = scanner.nextFloat();

        // Llamar al método nativo generarEstadoResultados con los datos ingresados
        System.out.println("\nGenerando estado de resultados...");
        costos.generarEstadoResultados(totalPronostico, precioVenta, totalCostoProduccion);

        // Cerrar el escáner
        scanner.close();
    }
}

