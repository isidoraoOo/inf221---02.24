import matplotlib.pyplot as plt
import numpy as np

largo = []
distancia = []
tiempo = []

#Agregar a '.txt' el nombre del archivo que se desea graficar.
with open(".txt", "r") as file:
    for line in file:
        l, d, t = map(float, line.split())
        largo.append(l)
        distancia.append(d)
        tiempo.append(t)

plt.figure(figsize=(10, 6))
scatter = plt.scatter(largo, tiempo, c=distancia, cmap='viridis', s=50, alpha=0.7)
plt.colorbar(scatter, label="Distancia de Levenshtein")
plt.xlabel("Largo")
plt.ylabel("Tiempo de ejecución (ms)")
plt.show()