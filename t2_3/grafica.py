import matplotlib.pyplot as plt
import numpy as np

eje_x = []
eje_y = []
i = 1 

# length edit_distace tiempo
# Repetir para todos los archivos

#Grafico edit_distance vs tiempo (milisegundos)
with open("11.txt", "r") as file:
    for line in file:
        lista = line.split()
        x_value = float(lista[2])
        y_value = float(lista[1])

        if x_value in eje_x:
            last_y = eje_y[-1]
            eje_y.pop()
            averaged_y = (last_y * (i - 1) + y_value) / i  
            eje_y.append(averaged_y)
        else:

            eje_x.append(x_value)
            eje_y.append(y_value)
            i = 1 

        i += 1 


plt.plot(eje_x, eje_y)
plt.xlabel("Tiempo (milisegundos)")
plt.ylabel("Distancia de Levenshtein")
plt.title("Distancia de Levenshtein vs Tiempo")
plt.show()


#Grafico largo vs tiempo (milisegundos)
with open("11.txt", "r") as file:
    for line in file:
        lista = line.split()
        x_value = float(lista[2])
        y_value = float(lista[0])

        if x_value in eje_x:
            last_y = eje_y[-1]
            eje_y.pop()
            averaged_y = (last_y * (i - 1) + y_value) / i  
            eje_y.append(averaged_y)
        else:

            eje_x.append(x_value)
            eje_y.append(y_value)
            i = 1 

        i += 1 


plt.plot(eje_x, eje_y)
plt.xlabel("Tiempo (milisegundos)")
plt.ylabel("Largo")
plt.title("Largo vs Tiempo")
plt.show()
