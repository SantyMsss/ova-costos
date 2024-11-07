package ejemplojni.lib;

public class JavaCostos {
    // Declaración de métodos nativos
    public native void calcularValores(float a, float b, int meses, int meses_pronostico);
    public native void generarEstadoResultados(float total_pronostico, float precio_venta, float total_costo_produccion);

    // Cargar la librería nativa
    static {
        System.loadLibrary("costos"); // Carga la biblioteca nativa `libcostos.so`
    }
}

