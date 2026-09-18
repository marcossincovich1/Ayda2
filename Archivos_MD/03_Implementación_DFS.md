Análisis y Diseño de Algoritmos II

Ingeniería de Sistemas
Facultad de Exactas - UNICEN

Recorrido DFS
● Breve descripción del algoritmo.
● Caso de prueba
● Decisiones de diseño
● Consideraciones finales

DFS: la idea
1

2

3

4

Parte de un origen y explora recursivamente sus sucesores.

Desde el último vértice descubierto, explora en profundidad cada

Blanco no descubierto

arco.

Gris en exploración

Cuando ya exploró todos los arcos de v, retrocede al vértice desde el

Negro terminado

que lo descubrió.
Si al terminar quedan vértices sin descubrir, elige uno nuevo y repite:
eso es DFS_Forest.

Y tres marcas por vértice
d[v]
f[v]
p[v]

Cada vértice lleva un color

cuándo se descubre (pasa a gris)
cuándo termina (pasa a negro)
desde qué vértice se lo descubrió

Los tiempos van de 1 a 2n: cada vértice consume dos.

Análisis y Diseño de Algoritmos II

Algoritmo DFS
DFS (G, origen)

1.

tiempo = tiempo + 1

2.

d[origen] = tiempo

3.

marca[origen] = Gris

4.

for each v ∈ G.Ady(origen)

5.

if marca[v] == Blanco

6.

p[v] = origen

7.

DFS (G, v)

8.

marca[origen] = Negro

9.

tiempo = tiempo + 1

10. f[origen] = tiempo

DFS_Forest (G)
1. for each v: marca[v]=Blanco; p[v]=NIL
2. tiempo = 0
3. for each v ∈ G.Vertices()

4.

if marca[v]==Blanco → DFS(G,v)

Análisis y Diseño de Algoritmos II

DFS: Caso de prueba

1

2

4

7

3

5

Análisis y Diseño de Algoritmos II

6

DFS: Decisiones de diseño
● ¿Dónde implementamos el DFS?
● ¿Hacemos una clase o un encabezado para la función
principal?

● ¿Cómo registramos el color en cada momento de cada vértice?
● ¿Cómo retorna la información del recorrido?

● No vamos a llevar el tiempo de descubrimiento en esta primera
implementación.

Análisis y Diseño de Algoritmos II

DFS: Consideraciones finales
¿Dónde implementamos el DFS?
● Dentro de la clase podemos hacerlo más eficiente (trabajamos
directamente sobre la estructura de implementación sin el costo de la
interfaz propuesta) pero esto no es necesariamente bueno:
○ Implementación completamente atada a la estructura elegida.
○ Clase Grafo que sigue creciendo con cada algoritmo a implementar.

● Fuera de la clase:
○ Mantenemos una interfaz concreta del Grafo como contenedor de
vértices y arcos, sin aplicaciones específicas.
○ El costo de los algoritmos se ve afectado por el costo de la interfaz pero
es un costo lógico.
○ Independencia de la implementación del grafo.

Elegimos la segunda alternativa.
Análisis y Diseño de Algoritmos II

DFS: Consideraciones finales
¿Hacemos una clase o un encabezado para la función principal?
● Una clase nos permitiría tener atributos de instancia.
● Elegimos un encabezado para la función, también nos permite
restringir el acceso a funciones auxiliares.
¿Cómo registramos el color en cada momento de cada vértice?
● map<int, char> colores;
● Fundamental el proceso de inicialización para usar [ ] y find.
¿Cómo retorna la información del recorrido?
● Queda como tarea, los algoritmos no deben enviar el resultado a
la salida directamente.

Análisis y Diseño de Algoritmos II

Tarea propuesta
● Modificar la implementación del DFS para que
retorne la lista de vertices (se pueden sumar los
tiempos y padres).
● Implementar el BFS
● Recomendación:
○ Utilizar los contenedores de la biblioteca STL
como estructuras auxiliares para la
implementación de los ejercicios prácticos.
○ Por ejemplo: set -> “visitados / no visitados”

Consultas: laboratorio.ayda@alumnos.exa.unicen.edu.ar
Licencia creative commons
Atribución-Compartir Obras Derivadas Igual 2.5 Argentina

http://creativecommons.org/licenses/by-sa/2.5/ar/

