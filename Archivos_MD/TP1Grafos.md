ANÁLISIS Y DISEÑO DE ALGORITMOS II
PRÁCTICO Nº 1 - GRAFOS
1.

Explore el grafo de la figura utilizando el DFS_Forest:
a) Dibuje el bosque asociado al recorrido y registre los
tiempos de descubrimiento y finalización.
b) Clasifique los arcos del grafo en función del recorrido.
c) Modifique el pseudocódigo del DFS para que imprima
cada arco del grafo junto con su tipo.
d) Implemente en C++ y calcule la complejidad temporal de
la clasificación.
e) Repita la exploración cambiando el orden en que tomó
los vértices en el recorrido anterior. ¿Obtuvo la misma
información?

2. Explore el grafo de la figura utilizando el DFS_Forest:
a) Dibuje el bosque asociado al recorrido y registre los tiempos
de descubrimiento y finalización.
b) Clasifique las aristas del grafo en función del recorrido.
Tenga en cuenta que en un grafo no dirigido (u,v) y (v,u) son
la misma arista, se considera su primer clasificación.
c) ¿Qué tipos de aristas aparecen en una exploración DFS?
d) Modifique el pseudocódigo del DFS para que imprima cada
arista del grafo junto con su tipo.
e) Implemente en C++ y calcule la complejidad temporal de la
clasificación.
f) Repita la exploración cambiando el orden en que tomó los
vértices en el recorrido anterior. ¿Obtuvo la misma información?

3.

Implemente en C++ un algoritmo que permita registrar los
caminos de longitud mínima y su longitud, entre un
vértice origen dado a todos los vértices alcanzables.
Calcule la complejidad temporal. Realice un seguimiento
del algoritmo tomando como origen el vértice r.

4. En un proyecto se ha definido la secuencia de tareas que
T5
T6
T7
deberán llevarse a cabo y se la ha representado mediante el T 3
T1
T2
grafo dirigido de la figura. Los arcos indican la secuencia en
T4
T9
que deben realizarse (por ejemplo, la tarea 6 debe realizarse T 8
antes que la 9 y la tarea 4 antes que la tarea 2). Escriba un
algoritmo basado en el DFS que permita ordenarlas temporalmente, es decir, que devuelva una
secuencia válida en la que podrían realizarse dichas tareas. Implemente el algoritmo en C++.

ANÁLISIS Y DISEÑO DE ALGORITMOS II
PRÁCTICO Nº 1 - GRAFOS
5. Implemente un algoritmo en C++ que basado en el DFS determine si un grafo dirigido tiene
algún ciclo.
6. Escribir un algoritmo que, dado un grafo dirigido rotulado y dos vértices de este grafo, devuelva
todos los caminos simples de un vértice a otro y su costo asociado.
7. Dados un grafo G con sus vértices rotulados con colores y dos vértices v1 y v2, escriba un
algoritmo que encuentre un camino entre el vértice v1 al vértice v2 tal que no pase por vértices
rotulados con el color rojo.
8. Escriba un algoritmo que devuelva una lista con todos los vértices de un grafo dirigido, a partir
de los cuales existe un camino de longitud long que termina en un vértice dado.
9. Dado un grafo no orientado que modela las rutas de la provincia de Buenos Aires, devolver todos
los caminos alternativos que se pueden tomar para ir desde la ciudad de Buenos Aires a la ciudad
de Tandil, considerando que en el tramo Las Flores-Rauch está cortado al tránsito.
10. Un grafo no dirigido puede dividirse en una o más “componentes conectadas”. Cada una de éstas
es un conjunto máximo de vértices alcanzables entre sí. Escriba un algoritmo que determine
cuántas componentes conectadas tiene el grafo y a qué componente pertenece cada vértice.
11. Un grafo dirigido G = (V, A) puede dividirse en “componentes fuertemente conectadas”. Cada
una de ellas es un conjunto máximo de vértices U  V tal que para cada par de vértices u y v en
U, existe un camino de u a v y de v a u. Escriba un algoritmo que determine cuántas componentes
conectadas tiene el grafo y a que componente pertenece cada vértice.
12. Implemente los algoritmos de Dijkstra y Floyd para encontrar el “camino más corto”.
13. Un presidente decide trasladar la Capital del país. Solicita le indiquen cuál es la ciudad que se
encuentra más cerca de todas las demás para trasladar allí la sede gubernamental. Implemente un
algoritmo que de respuesta a este problema. Sus datos serán el mapa carretero y las distancias de
cada tramo entre ciudades.
14. Desde un cierto número k de ciudades del interior de una provincia, se desean transportar
cereales hasta algún puerto perteneciente al litoral de la misma. Se pretende efectuar el
transporte con mínimo costo. Dé un algoritmo eficiente que resuelva este problema, devolviendo
los caminos en una estructura de lista.
15. Dado un grafo no orientado que modela las rutas de la provincia de Buenos Aires, devolver el
camino más corto en km. desde una ciudad origen a una ciudad destino sabiendo que el tramo
Las Flores-Rauch está cortado al tránsito.
16. Implemente los algoritmos de Prim y Kruskal para obtener el “árbol de recubrimiento de mínimo
costo”.

17. La compañía telefónica ADA desea realizar un tendido de
líneas para comunicar las ciudades de un grupo de islas.

ANÁLISIS Y DISEÑO DE ALGORITMOS II
PRÁCTICO Nº 1 - GRAFOS
Las líneas correrán paralelas a las rutas entre las ciudades. El costo del cableado dependerá de los
kilómetros del tendido. Se desea hallar el tendido de líneas de mínimo costo para comunicar
todas las ciudades, teniendo en cuenta que entre las islas la compañía utilizará transmisión
satelital:
a) ¿Qué algoritmos podría utilizar para resolver el problema? Siguiendo el ejemplo de la figura
muestre paso a paso cómo trabaja cada uno.
b) Para cada uno de los algoritmos mencionados en el punto a, describa qué TDAs y/o
estructuras de datos utilizaría para implementarlos eficientemente y cuál sería su complejidad
temporal.
c) Si las ciudades están conectadas todas con todas ¿qué algoritmo seleccionaría para resolver
eficientemente el problema?
18. La figura modela un mapa de vuelos, en el cual cada vértice
representa una ciudad, cada arco una ruta aérea y el rótulo del arco el
tiempo del vuelo. Se desea saber cuál es la ruta que se debe tomar
para ir de la ciudad 1 a todas las demás del mapa en el menor tiempo
posible.

1

100

10
30

2
50

5

10

60

a.

3
¿Qué algoritmo utilizaría para resolver eficientemente el
problema? Explique qué TDAs y/o estructuras de datos
utilizaría para implementar el algoritmo y cuál sería su complejidad temporal.

b.

Utilizando el ejemplo de la figura, muestre cómo trabaja el algoritmo en cada iteración para
encontrar las rutas y sus tiempos para ir de la ciudad 1 a todas las demás.

c.

Si el problema fuera encontrar el camino de la ciudad 1 a todas las restantes con la mínima
cantidad de escalas, ¿qué algoritmos podrían resolver este problema?

20

4

19. Responder V o F justificando en cada caso.
a. Si se tiene un Árbol de Recubrimiento de Costo Mínimo de un Grafo, entonces se tiene el
camino más corto entre cada par de vértices.
b. Un árbol de recubrimiento de costo mínimo puede contener ciclos.
c. Dado un grafo con n nodos, para obtener los caminos más cortos entre todo par de vértices,
puedo hacerlo aplicando n veces el algoritmo de Dijkstra.
d. En una componente fuertemente conectada de un grafo dirigido no es posible aplicar un
ordenamiento topológico.
e. En un grafo no dirigido donde sus vértices están conectados todos con todos, no es posible
aplicar recorrido DFS ya que debido a los ciclos el algoritmo no termina nunca.

