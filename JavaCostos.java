import java.util.Scanner;

public class JavaCostos {
    // Carga la biblioteca compartida (libcostos) que contiene las funciones en C
    static {
        System.loadLibrary("costos"); // Asegúrate de que el nombre coincida con el archivo generado (.so en Linux, .dll en Windows)
    }

    // Declaración del método nativo que llama a la función C `calcularValores`
    public native void calcularValores(int meses, int mesesPronostico);

    public static void main(String[] args) {
        JavaCostos costos = new JavaCostos();
        Scanner scanner = new Scanner(System.in);

        // Solicita al usuario que ingrese la cantidad de meses con datos de ventas
        System.out.print("Ingrese la cantidad de meses con datos de ventas: ");
        int meses = scanner.nextInt();

        // Solicita al usuario que ingrese la cantidad de meses a pronosticar
        System.out.print("Ingrese la cantidad de meses que desea pronosticar: ");
        int mesesPronostico = scanner.nextInt();

        // Llamada al método nativo con los datos ingresados por el usuario
        costos.calcularValores(meses, mesesPronostico);

        scanner.close();
    }
}

