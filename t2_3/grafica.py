import matplotlib.pyplot as plt
import numpy as np

eje_x = []
eje_y = []
i = 1  # Inicializamos i para contar ocurrencias

with open("11.txt", "r") as file:
    for line in file:
        lista = line.split()
        x_value = float(lista[1])
        y_value = float(lista[0])

        # Si el valor de x ya existe en eje_x, calculamos el promedio acumulado en eje_y
        if x_value in eje_x:
            last_y = eje_y[-1]
            eje_y.pop()
            averaged_y = (last_y * (i - 1) + y_value) / i  # Promedio acumulado
            eje_y.append(averaged_y)
        else:
            # Si x_value es nuevo, simplemente añadimos x e y
            eje_x.append(x_value)
            eje_y.append(y_value)
            i = 1  # Reiniciamos el contador cuando encontramos un nuevo valor en eje_x

        i += 1  # Incrementamos i para el próximo promedio

# Graficamos los valores procesados
plt.plot(eje_x, eje_y)
plt.xlabel("Eje X")
plt.ylabel("Eje Y")
plt.title("Gráfico de datos de 11.txt con promedios acumulados")
plt.show()
