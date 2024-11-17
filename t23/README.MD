# Instrucciones para la replicación de datos

Se deben tener los archivos `archivos.cpp`, `archivos_costos.cpp`, `fuerza_bruta.cpp`, `pd.cpp` y `grafica.py` en el mismo directorio.

## Pasos para la compilación y ejecución:

1. **Compilar y ejecutar los archivos detallados a continuación con el compilador de C++:**
    ```bash
    g++ archivos_costos.cpp -o ejecutable1
    ./ejecutable1
    g++ archivos.cpp -o ejecutable2
    ./ejecutable2
    g++ fuerza_bruta.cpp -o ejecutable3
    ./ejecutable3
    g++ pd.cpp -o ejecutable4
    ./ejecutable4
    ```

2. **Para graficar los archivos resultantes:**
    - Es necesario actualizar el nombre del archivo correspondiente en la línea 9 del archivo `grafica.py`:
    ```python
    with open("nombre_del_archivo.txt", "r") as file:
    ```
    - La imagen resultante se puede guardar como `grafico_x.png`, donde `x` representa el número del gráfico.
