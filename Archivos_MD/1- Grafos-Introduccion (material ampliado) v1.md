Análisis y Diseño de Algoritmos II
Claudia Pereira - Liliana Martinez

Bibliografía
Aho, A. & Ullman, J. Foundations of Computer Science. Computer
Science Press
Cormen, T.; Lieserson, C.; Rivest, R. Introduction to Algorithms. Ed.
The MIT Press.
Horowitz, E.; Sahni, S.; Rajasekaran, S. Computer Algorithms /
C++. Silicon Press
Aho, A; Hopcroft,J y Ullman, J. Estructuras de datos y algoritmos.
Addison Wesley

UNIDAD 1- Grafos
Agenda
1. Definiciones básicas

2. Modelar problemas con grafos. Ejemplos
3. Implementación de grafos

UNIDAD 1- GRAFOS

DEFINICIONES BÁSICAS

Grafos- Definiciones
Un grafo representa una relación binaria
entre objetos
Modelo matemático

Relación binaria

Visualización
 un conjunto de puntos (nodos/vértices)
 un conjunto de líneas (aristas) o flechas (arcos)

Grafos- Definiciones

Una relación binaria R sobre dos conjuntos A y B:
es un conjunto de pares que es subconjunto de
A x B (A es el dominio y B el codominio)
Si B es igual a A

R es una relación binaria
“sobre el dominio A”

Grafos- Definiciones
Las relaciones binarias pueden representarse gráficamente:

 Un nodo para cada elemento que está en A y en B
 Un arco entre dos elementos si están relacionados

Ejemplo: Sea una relación binaria R sobre el dominio A = {1,2,3}
R  A x A

R = { (1,2), (1,3), (2,2) }

Grafos- Definiciones
Clasificación de grafos:
 Dirigidos/orientados
 No- dirigidos/ No-orientados

 Rotulados
 Multigrafos

…

Grafos dirigidos
Un grafo dirigido (orientado) G consiste de:
 un conjunto de vértices (nodos) no vacío V
 una relación binaria E sobre V que refiere al
conjunto de arcos de G

Lo denotaremos G = (V,E)

Grafos dirigidos
G = ( V, E )
V = { 0, 1, 2, 3, 4 }

u

v

E = { (0,0), (0,1), (0,2), (1,3),

(2,0), (2,1), (2,4),
(3,2), (3,4), (4,1) }

arco (u,v) :
• u es el predecesor de v;
• v es el sucesor de u

(0,1) arco
(0,0) bucle

Grafos dirigidos
Ejemplo: Grafo de llamadas

Los vértices son las funciones:
existe un arco entre fi y fj si fi llama a fj.

Los bucles indican recursión directa

Grafos dirigidos
Un camino en un grafo dirigido es
una secuencia de vértices (v1, v2, v3, … vk-1 , vk)
tal que existe un arco vi -> vi+1 para i=1,2,…,k-1

Camino simple: todos lo vértices en el son distintos

Grafos dirigidos
Un camino en un grafo dirigido es
una secuencia de vértices (v1, v2, v3, … vk)
tal que existe un arco vi -> vi+1 para i=1,2,…,k-1

La longitud del camino es k-1 (el número de arcos).

Ejemplo: (0, 1, 3) es un camino de longitud 2

Grafos dirigidos
Un camino en un grafo dirigido es
una secuencia de vértices (v1, v2, v3, … vk)
tal que existe un arco vi -> vi+1 para i=1,2,…,k-1

La longitud del camino es k-1 (el número de arcos).

El caso trivial k=1 es permitido indicando que
para cualquier vértice v podemos considerar
un camino de longitud 0 de v a v.
Ejemplo: (3) es un camino de longitud 0

Grafos dirigidos
Un ciclo en un grafo dirigido es un camino de longitud
uno o más que comienza y finaliza en el mismo vértice.
La longitud del ciclo es la longitud del camino.

Grafos dirigidos
Un ciclo en un grafo dirigido es un camino de longitud 1
o más que comienza y finaliza en el mismo vértice.
La longitud del ciclo es la longitud del camino.

Un camino trivial de longitud cero (v) no es un ciclo,
sin embargo un camino que consiste de un simple arco
v -> v es un ciclo de longitud 1.

Grafos dirigidos
Un ciclo en un grafo dirigido es un camino de longitud 1
o más que comienza y finaliza en el mismo vértice.
La longitud del ciclo es la longitud del camino.

Un camino trivial de longitud cero (v) no es un ciclo,
sin embargo un camino que consiste de un simple arco
v -> v es un ciclo de longitud 1.
Un ciclo es simple si todos los vértices, excepto el
primero y el último son distintos.
Un simple arco de v->v es un ciclo simple particular denominado bucle.

Grafos dirigidos
Ejemplos:
 (0,2,0) es un ciclo simple de longitud 2
 (1,3,2,1) es un ciclo simple de longitud 3
 (0,2,1,3,2,0) es un ciclo de longitud 5
 (0,0) es un ciclo simple de longitud 1(bucle)
Un ciclo puede escribirse comenzando por
cualquiera de sus vértices (1,3,2,1) puede
escribirse como (2,1,3,2) ó (3,2,1,3)

Grafos dirigidos
Grado de incidencia de un vértice:
número de arcos entrantes.
Ejemplo:
• grado de incidencia de 1 es 3
• grado de incidencia de 0 es 2

Grado de incidencia de un grafo:
El máximo de los grados de
incidencia de sus vértices.

Grafos dirigidos
Grado de “vecindad” de un vértice:
número de arcos salientes.
Ejemplo:
• grado de vecindad de 1 es 1
• grado de vecindad de 0 es 3
Grado de “vecindad” de un grafo:
El máximo de los grados de
“vecindad” de sus nodos.

Grafos dirigidos
Grafo dirigido acíclico
es un grafo dirigido que no tiene ciclos.

Entre otros permite representar:


Régimen de correlatividades



Estructura sintáctica de expresiones aritméticas
con subexpresiones comunes.
Ejemplo (A + B) * ( D + D * ( A + B) )

Un grafo dirigido es cíclico sí y sólo sí tiene al menos un ciclo simple.

Grafos dirigidos
Grafo dirigido completo
• Tiene un arco desde cada vértice a
todos los vértices del grafo, incluyendo
uno a sí mismo.
• Tiene n2 arcos (n = número de vértices)

Grafos dirigidos
Grafo dirigido rotulado

Grafos no dirigidos
Un grafo no-dirigido (no-orientado) G consiste de:
 un conjunto de vértices (nodos) no vacío V
 una relación binaria E sobre V que refiere al conjunto de aristas de G
Se denota G = ( V, E )
Una arista es un conjunto de dos nodos { u, v } que denota que u y v están
conectados en las dos direcciones. Decimos que u y v son adyacentes
Un grafo con aristas tiene definida una relación simétrica sobre sus arcos:
Si u está relacionado con v, luego v está relacionado con u
(existen tanto u->v como v-> u).

Grafos no dirigidos
Ejemplo: Sea C = { a, b, c, d } un conjunto de ciudades.
Se puede definir una relación R sobre C
Dos elementos de C están relacionados
si existe un camino directo entre ellos.

a

b

d

Grafo
No dirigido

c

R = { (c,a),(a,c),(a,b),(b,a),(b,d),(d,b),(a,d),(d,a) }

Grafos no dirigidos
La definición de camino es la misma para grafos dirigidos y no dirigidos:

Un camino en un grafo no dirigido es una secuencia de vértices (v1,v2,v3,…vk)
tal que existe una arista entre vi y vi+1 para i=1,2,…,k-1.

La longitud del camino es k-1 ( el número de aristas).
El caso trivial k=1 es permitido indicando que para cualquier vértice v podemos

considerar un camino de longitud 0 de v a v.

Grafos no dirigidos
La definición de ciclo para un grafo no dirigido
es diferente que para un grafo dirigido
En un grafo no dirigido:
 (u,v,u) NO ES UN CICLO
 (v1, v2 , …, vk-1, vk, vk-1,…, v2 , v1) NO ES UN CICLO
En grafos no dirigidos, el concepto útil es sólo el de ciclo simple:
un camino de longitud 3 o más que comienza y finaliza en el mismo vértice,
y que excepto el primero, no existan vértices repetidos.

Grafos no dirigidos
Grado de un vértice
El grado de un vértice v en un grafo
no dirigido es el número de adyacentes a v.
Ejemplo:
El grado 5 es 3
El grado 0 es 2
Grado de un grafo
El grado de un grafo no dirigido es
el máximo de los grados de sus vértices.

Grafos no dirigidos
Un grafo no-dirigido completo:
 Tiene una arista entre cada par de vértices diferentes.
 Tiene (n-1) n / 2 aristas
Ejemplos: Kn denota al grafo de n vértices

Grafos no dirigidos
Un grafo es planar si es posible ubicar a sus vértices en un
plano y luego dibujar sus aristas como una línea continua de
forma tal que dos aristas no se crucen.

Grafos no dirigidos
Dos ejemplos de grafos no-orientados que no son planares:

Grafo no-dirigido bipartido
Un grafo no dirigido es bipartido si todos sus vértices se pueden
dividir en dos conjuntos disjuntos tal que todas las aristas
relacionan vértices de conjuntos distintos.

Grafos no dirigidos
Grafo no dirigido rotulado:

Grafo conexo
Un grafo es conexo si existe un camino entre cada par de vértices.

Ejemplos:

UNIDAD 1- GRAFOS

Modelado con grafos

Modelado con grafos
Ejemplo: Los siete puentes de Königsberg

Mapa de Königsberg en la época de Leonhard Euler (1707-1783)
Ciudad atravesada por el río Pregel que se bifurca formando una isla, dividiendo
el terreno en cuatro regiones, unidas por 7 puentes.

Modelado con grafos
Ejemplo: Los siete puentes de Königsberg

Modelado con grafos
Ejemplo: Los siete puentes de Konigsberg

Euler modeló el mapa con un grafo (abstracción del mapa) en el que
los vértices son las regiones terrestres y las aristas los puentes.
El grafo resultante es un multigrafo: más de una arista entre vértices

Modelado con grafos
Ejemplo: Los siete puentes de Konigsberg

El problema se reduce a decidir si existe o no un camino que salga de un
vértice pase por todos los arcos una vez y termine en el mismo vértice. Este
problema sobre grafos se lo conoce como ciclo euleriano.
Es el primer problema sobre grafos (1736): Euler determinó que los vértices
deberían tener grado par para que exista un ciclo y por lo tanto, los habitantes
de Konigsberg no podían recorrer los siete puentes bajo las restricciones
impuestas.

Modelado con grafos
Ejemplo : Un laberinto

Modelado con grafos
Ejemplo: Identificar patrones de texto
Reconocer cadenas sobre el alfabeto {a,b} que tengan una cantidad
impar de a y de b

Autómata Finito determinístico
Grafo dirigido con un vértice distinguido como inicial
y un conjunto de vértices como finales

Modelado con grafos
Aplicación

Objeto

Conexión

Mapas

Intersección o Ciudad

Rutas

Contenido Web

Página

Link

Circuitos Eléctricos

Dispositivos

Cables

Planificación

Tareas

Restricciones

Redes de computadoras Sitios

Conexiones

Software

Método

Llamada

Red social

Persona

Amistad

UNIDAD 1- GRAFOS

Implementación de grafos

Implementación de grafos
Representaciones
• Lista de adyacentes
• Matriz de adyacencia

Implementación de grafos dirigidos
Lista de adyacentes

Implementación de grafos dirigidos
Matriz de adyacencia

Implementación de grafos no-dirigidos
rotulados: Matriz de adyacencia

Implementación de grafos dirigidos
rotulados. Lista de adyacencia

Grafos: Comparando implementaciones
Espacio
Matriz de adyacencia
Para un grafo de n nodos
espacio requerido: n x n (matriz)
( + n rótulos si el grafo es rotulado)

Lista de adyacencia
Para un grafo con n nodos y a arcos/aristas,
espacio requerido:

• grafo dirigido: n nodos más a arcos
• grafo no dirigido: n nodos más 2a aristas

Grafos: Comparando implementaciones
Espacio
Matriz de adyacencia
Para un grafo de n nodos
espacio requerido: n x n (matriz)
( + n rótulos si el grafo es rotulado)

Conviene para grafos densos
(número de arcos tiende a
n2 para un grafo de n nodos).

Lista de adyacencia
Para un grafo con n nodos y a arcos/aristas,
espacio requerido:

• grafo dirigido: n nodos más a arcos
• grafo no dirigido: n nodos más 2a aristas

Conviene para grafos ralos (el número de arcos
es mínimo). Esta representación ahorra
memoria.

Grafos: Comparando implementaciones
Operación: buscar un arco/arista (u,v)
Matriz de adyacencia

Lista de adyacencia

Consultar una posición de

Buscar u en el arreglo: O(1)

la Matriz  O(1)

Buscar v en la lista de adyacencia de u:
O (número de sucesores de u)
Para un grafo de n nodos y a arcos/aristas
En promedio O(a/n)
-

Si a es cercano a n2  O(n)

-

Si a está dentro de un factor constante de n  O(1)

Grafos: Comparando implementaciones
Operación: hallar sucesores de un nodo u
Matriz de adyacencia

Lista de adyacencia

Recorrer la fila entera de u

Recorrer la lista de adyacentes de u

O(n) para un grafo de n nodos

O(número de sucesores de u)
En promedio O(a/n)
-

Si a es cercano a n2  O(n)

-

Si a está dentro de un factor constante de
n  O(1)

Grafos: Comparando implementaciones
Operación: hallar predecesores de un nodo v
Matriz de adyacencia

Lista de adyacencia

Recorrer la columna entera de v

Recorrer la lista de adyacentes de cada
nodo u para saber si esa lista incluye a v.

O(n) , para un grafo de n nodos

O(a) Para un grafo de a arcos.
Es costoso hallar los predecesores de un nodo

Para resolver…
1. Dado el grafo de la figura:

a) ¿Cuántos arcos tiene?
b) ¿ Cuántos caminos simples hay entre
el vértice a y el vértice d? ¿Cuáles son?
c) ¿Cuáles son lo predecesores y los sucesores del vértice b?
d) ¿Cuántos ciclos simple tiene? Listarlos

Para resolver…
2) Para el grafo que resulta de reemplazar cada arco (u,v) en el grafo
del Ej. 1 por una arista {u,v}
a) Encontrar todos los caminos de a a b que no repitan vértices
b) ¿Cuántos ciclos simples que incluyan 6 vértices existen?
Listarlos
c) ¿Cuáles son los sucesores del nodo a?

3) Si un grafo dirigido tiene 10 nodos, cuáles son los números
máximo y mínimo de arcos que puede tener?
4) Si un grafo no dirigido tiene 10 nodos, cuáles son los números
máximo y mínimo de arcos que puede tener?

Para resolver…
5) Describa algunos problemas se pueden modelar con grafos…
a) dirigidos

b) dirigidos rotulados
c) no dirigidos

d) no dirigidos rotulados
e) bipartitos

Para resolver…
6) Representre el grafo dirigido de la figura utilizando:
a) Listas de adyacencia
b) Una matriz de adyacencia

7) Repita el ejercicio 6, suponiendo ahora que el grafo
de la figura es no dirigido (es decir, tuviera aristas en
lugar de arcos)

