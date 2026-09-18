Exploración de Grafos Dirigidos
Agenda
DFS - Búsqueda en profundidad
✔

Propiedades

✔

Aplicaciones

Prof. Liliana Martínez
Prof. Claudia Pereira

DFS - Repaso
1. Parte desde un vértice fuente explorando
recursivamente sus sucesores

DFS (G,origen) {
1.

tiempo = tiempo + 1

2.

d [origen] = tiempo

3.

marca[origen] = Gris

4.

for each v ∈ G.Ady(origen)

5.

if marca [v] ==

6.

p [v] = origen

7.

DFS (G,v)

8.

marca[origen] = Negro

2. Desde el vértice origen
recién descubierto,
explora en profundidad
cada arco (origen -> v)

9. tiempo = tiempo + 1
10. f [origen] = tiempo
}

3. Cuando todos los arcos desde el origen han
sido explorados, la búsqueda retrocede al vértice
desde el cual origen fue descubierto.

DFS - Repaso
DFS_FOREST( G)
1 for each vertex v ∈
G.Vertices()
2
marca[v] =
3
p[v] =
NIL
4 tiempo = 0
5 for each vertex
v ∈ G.Vertices(),
6
if marca[v]==
7
DFS (G, v)
5. Si restan vértices sin descubrir, uno
es seleccionado como nuevo vértice
origen y la búsqueda se repite.
6. El proceso termina cuando
todos los vértices han sido
descubiertos

1. Parte desde un vértice fuente explorando
recursivamente sus sucesores

DFS (G,origen) {
1.

tiempo = tiempo + 1

2.

d [origen] = tiempo

3.

marca[origen] = Gris

4.

for each v ∈ G.Ady(origen)

5.

if marca [v] ==

6.

p [v] = origen

7.

DFS (G,v)

8.

marca[origen] = Negro

2. Desde el vértice origen
recién descubierto,
explora en profundidad
cada arco (origen -> v)

9. tiempo = tiempo + 1
10. f [origen] = tiempo
}

3. Cuando todos los arcos desde el origen han
sido explorados, la búsqueda retrocede al vértice
desde el cual origen fue descubierto.

DFS
Numeración de los vértices en
preorden y postorden

DFS - Numeración en preorden

DFS - Numeración en preorden
DFS_FOREST( G)

DFS (G,origen)

1 for each vertex v ∈ G.Vertices()
2 marca[v] = no_visitado
3 nro = 0

1. marca[origen] = visitado

4 for each vertex v ∈ G.Vertices(),

3. nroPreOrden[origen] = nro

if marca[v] == no_visitado

4. for each v ∈ G.Ady(origen)

5
6

DFS (G, v)

2. nro = nro + 1

5.
6.

if marca [v] == no_visitado
DFS (G,v)

DFS- Numeración de vértices en postorden

DFS numerando los
vértices en
postorden

DFS - Numeración en postorden
DFS_FOREST( G)

DFS (G,origen)

1 for each vertex v ∈ G.Vertices()
2 marca[v] = no_visitado
3 nro = 0

1. marca[origen] = visitado

4 for each vertex v ∈ G.Vertices(),

3.

if marca[v] == no_visitado

4.

5
6

DFS (G, v)

2. for each v ∈ G.Ady(origen)
if marca [v] == no_visitado
DFS (G,v)

5. nro = nro + 1
6. nroPostorden[origen] = nro

Propiedades de los números postorden
Sea el arco u->v, si u->v es un arco del árbol o forward =>
v es descendiente de u y postorden[v] <
postorden[u]

Propiedades de los números postorden
Sea el arco u->v, si u->v es un arco de cruce =>
v está a la izquierda de u y postorden[v] <
postorden[u]

Propiedades de los números postorden
Sea el arco u->v, si u-> v es un arco de retroceso (back) =>
postorden[v] ≥ postorden[u]
Caso particular: si u-> v es un bucle, entonces u = v , luego postorden[v] =
postorden[u]

Exploración de grafos Dirigidos
Agenda
DFS - Búsqueda en profundidad
✔

Propiedades

✔

Aplicaciones :
✔ Alcance
✔ Detección de ciclos
✔ Ordenamiento topológico (grafo dirigido
acíclico)
✔ Conectividad

Aplicaciones de DFS: Alcance
DFS resuelve el problema de conectividad desde un solo origen, permite determinar
qué vértices son alcanzados desde un vértice origen dado.
A partir del DFS podemos resolver problemas de conectividad similares:

• Alcance desde una única fuente:
Dado un grafo dirigido y un vértice de origen u
¿Existe un camino desde u hasta un vértice de destino v dado?

• Alcance desde múltiples fuentes:
Dado un grafo dirigido y un conjunto de vértices de origen ¿Existe un camino desde
cualquier vértice en el conjunto a un determinado vértice destino v?

Aplicaciones de DFS: Alcance
Alcance desde múltiples fuentes:
Ejemplo de aplicación : se encuentra en los sistemas
típicos de administración de memoria (Ej: Java).
Memoria de un programa en ejecución se modela
con un grafo dirigido donde:
•

cada vértice representa un objeto

•

cada arco representa una referencia a un objeto

En un punto de la ejecución de un programa, se conoce que
objetos son directamente accesibles. Cualquier objeto que no sea
accesible desde ese conjunto de objetos puede devolverse a la
memoria disponible.

Exploración de grafos Dirigidos
Agenda
DFS - Búsqueda en profundidad
✔

Propiedades

✔

Aplicaciones :
✔ Alcance
✔ Detección de ciclos
✔ Ordenamiento topológico (grafo dirigido
acíclico)
✔ Conectividad

Aplicaciones de DFS: Detección de Ciclos
¿Cómo determinar si un grafo contiene ciclos?
DFS permite encontrar una solución simple a este
problema:

Detección de un arco back ⇒ ciclos

Ausencia de arcos back ⇒ grafo acíclico dirigido (DAG)

Exploración de grafos Dirigidos
Agenda
DFS - Búsqueda en profundidad
✔

Propiedades

✔

Aplicaciones :
✔ Alcance
✔ Detección de ciclos
✔ Ordenamiento topológico (grafo dirigido
acíclico)
✔ Conectividad

Ordenamiento topológico

DAG usados para indicar precedencia de eventos
¿cómo programar los eventos para que se completen respetando las
restricciones de precedencia?

Ordenamiento
topológico

Un Ordenamiento Topológico :
Una posible secuencia válida en la que pueden tomarse
los cursos, respetando las restricciones

Ordenamiento
topológico

Dado un DAG G= (V,A), un orden topológico de G
es un orden lineal de todos sus vértices,
tal que si G contiene un arco (u,v) ,
luego u aparece antes de v en el ordenamiento.

Ordenamiento topológico
Dado un DAG, ¿Cómo calculamos el ordenamiento topológico?

Orden_topológico (DAG g)
{DFS-forest (G) // Rotulando en postorden
// cuando la exploración a partir de un vértice termina,
// es insertado al frente de una lista
return lista de vértices;
}

Ordenamiento topológico
Dado un DAG, ¿Cómo calculamos el ordenamiento topológico?

1. DFS-forest
rotulando en postorden
(ponerlos al ppio de una lista)

Ordenamiento topológico
Dado un DAG, ¿Cómo calculamos el ordenamiento topológico?

1. DFS-forest
rotulando en postorden

2. Se listan los vértices según su número en postorden
de mayor a menor y obtenemos un orden topológico
satisface las restricciones de precedencia

Ordenamiento topológico
Orden_topológico (Grafo g)
{DFS-forest (G) //Para calcular tiempo de ﬁnalización de cada vértice
// cuando la exploración a partir de un vértice termina, este es insertado al frente de una
lista

return lista_de_vértices;
}

Complejidad
Temporal

O(max(n,a)) , n=|v|, a=|A|

Exploración de grafos Dirigidos
Agenda
DFS - Búsqueda en profundidad
✔

Propiedades

✔

Aplicaciones :
✔ Alcance
✔ Detección de ciclos
✔ Ordenamiento topológico (grafo dirigido
acíclico)
✔ Conectividad

Conectividad
Componentes fuertemente conexos de un grafo dirigido
Repasemos:

✔

Un componente fuertemente conexo de un grafo dirigido es un conjunto
máximo de vértices en el cual existe un camino entre cada par de vértices.

✔

Un grafo con un solo componente fuertemente
conexo se dice que está fuertemente conectado

Conectividad
Componentes fuertemente conexos de un grafo dirigido
Repasemos:

✔

Un grafo que no es conexo se puede dividir de una única forma en
un conjunto de componentes conexos.

Componentes fuertemente conexas
Dado el grafo G, cómo hallamos las componentes?
Cada región sombreada es una componente fuertemente
conectada

Componentes fuertemente conexas
Algoritmo_componentes_fuertemente_conectados ( G= (V,E) ) {
1. DFS_FOREST (G) rotulando a los vértices en postorden
2. Calcular GT , grafo transpuesto de G (se obtiene invirtiendo sus arcos)
3. DFS_FOREST ( GT ) a partir del vértice con mayor número de postorden.
4. A partir del DFS_FOREST ( GT ) armar las componentes conectados.
Cada una de ellas incluye:
• los vértices de cada árbol del DFS_FOREST (GT) y
• los arcos con inicio y ﬁn en esos vértices

}

Componentes fuertemente conexas
Algoritmo_componentes_fuertemente_conectados ( G= (V,E) ) {
1. DFS_FOREST (G) rotulando a los vértices en postorden (apilo)
b
e
a
c
d
g
h
f

Componentes fuertemente conexas
2. Calcular GT , grafo transpuesto de G (se obtiene invirtiendo sus arcos)
3. DFS_FOREST ( GT ) a partir del vértice con mayor número de postorden
b
e
a
c
d
g
h
f

Componentes fuertemente conexas
4. A partir del DFS_FOREST ( GT ) armar las componentes conectados.
Cada una de ellas incluye:
• los vértices de cada árbol del DFS_FOREST (GT) y
• los arcos con inicio y ﬁn en esos vértices

}

// fin algoritmo Algoritmo_componentes_fuertemente_conectados

Componentes fuertemente conexas
Podemos representar las interconexiones entre los componentes construyendo un
Grafo reducido de G:

✓ vértices son las componentes fuertemente conexas de G.
✓ arcos de cruces de componentes: van desde un vértice de un

componente a un vértice de

otro

El grafo reducido siempre es
un grafo acíclico dirigido

Componentes fuertemente conexas

¿ Por qué el algoritmo propuesto encuentra los
componentes fuertemente conexos de un grafo dirigido?

Componentes fuertemente conexas
Informalmente…
Si v y w pertenecen al mismo componente fuertemente conexo
⇒ existen caminos en G desde v a w y desde w a v,
⇒ por lo tanto existen caminos desde v a w y desde w a v en el Gr.
Supongamos que en el DFS(G), se inicia la búsqueda en alguna raíz x y se llega hasta v o w ,
como se alcanzan uno al otro, ambos terminan formando parte del mismo árbol con raíz x.
x
v

o

x
w

w

v

Componentes fuertemente conexas
Queremos demostrar que si v y w están en el mismo árbol del BOSQUE DFS (Gr),
pertenecen al mismo componente conectado
Sea x la raíz del árbol de exploración DFS_Forest(Gr) que contiene a v y w, como v y w son descendientes de x,
entonces: existe un camino en el Gr que va de x a v, y de x a w => existe un camino de v a x y de w a x en G.

x

o

DFS_Forest (Gr) comienza por los vértices de mayor número postorden ,
entonces

x

Postorden(x) > Postorden(v)

y Postorden(x) > Postorden(w) ,

la búsqueda a partir de v o w no pudo iniciarse en G antes que la de x

v

w

v o w sólo pueden ser alcanzables desde x en el DFS de G
Signiﬁca que en G existe un camino de x a v y un camino de x a w

w

v

Bosque resultado del DFS_Forest (Gr)

Podemos decir que en G, x, v y w están el mismo componente y
existe un camino de x a v, un camino de v a x, un camino de x a w y un
camino de w a x .

Existe un camino de v a w pasando por x y un camino de w a v pasando por x.

DFS-Aplicaciones: Ejercicios
4. En un proyecto se ha deﬁnido la secuencia de tareas que deberán llevarse a cabo y se la ha
representado mediante el grafo dirigido de la ﬁgura. Los arcos indican la secuencia en que
deben realizarse (por ejemplo, la tarea 6 debe realizarse antes que la 9 y la tarea 4 antes que la
tarea 2). Escriba un algoritmo basado en el DFS que permita ordenarlas temporalmente, es
decir, que devuelva una secuencia válida en la que podrían realizarse dichas tareas. Implemente
el algoritmo en C++.

5. Implemente un algoritmo que basado en el DFS determine si un grafo dirigido tiene algún
ciclo.

Bibliografía
Aho, A. & Ullman, J. Foundations of Computer Science.
Computer Science Press
Cormen, T.; Lieserson, C.; Rivest, R. Introduction to Algorithms.
Ed. The MIT Press.
Horowitz, E.; Sahni, S.; Rajasekaran, S. Computer Algorithms/ C++.
Silicon Press
Aho, A; Hopcroft,J y Ullman, J. Estructuras de datos y algoritmos.
Addison Wesley

