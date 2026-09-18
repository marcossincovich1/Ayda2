Análisis y Diseño de Algoritmos II
Claudia Pereira - Liliana Martinez

UNIDAD 1- Grafos
Agenda
Métodos de exploración de grafos:
•

Depth-First-Search (DFS) – Búsqueda en profundidad

•

Breath-First- Search (BFS) - Búsqueda en anchura

Exploración de grafos
Exploración de árboles:
➢ Preorder
➢ InOrder
➢ PostOrder

Exploración de grafos:
➢ DFS
➢ BFS

Búsqueda en profundidad
DFS
Recorrido sistemático de un grafo.
 Parte desde un vértice fuente explorando recursivamente sus sucesores.
 Desde el último vértice descubierto v explora en profundidad cada arco

 Cuando todos los arcos desde v han sido explorados, la búsqueda
retrocede al vértice desde el cual v fue descubierto.
 El proceso continúa hasta que todos lo vértices alcanzables desde el vértice
fuente original han sido descubiertos.
 Si restan vértices sin descubrir, uno de ellos es seleccionado como nuevo
vértice fuente y la búsqueda se repite.

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

d [origen] marca el tiempo en que comienza la
exploración de G a partir del vértice origen

Cada vértice es marcado
• Blanco (no-visitado) antes de ser
descubierto
• Gris (descubierto) entre el momento en que
es descubierto y el tiempo en que finaliza la
exploración a partir de él y
• Negro (visitado) una vez finalizada la
exploración a partir de él
f [origen] marca el tiempo en que finaliza la
exploración de G a partir de origen

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(u) = {v,x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(u) = {v,x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(u) = {v,x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(v) = {y}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(v) = {y}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady[origen]
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(y) = {x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady[origen]
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(y) = {x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(x) = {v}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(y) = {x}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(v) = {y}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(u) = {v,x}

DFS
Seguimiento
G.Ady(u) = {v,x}
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
DFS(G,u) terminó: todos los vértices alcanzables
10. f [origen] = tiempo
desde “u” han sido descubiertos

DFS
Seguimiento
Quedan vértices sin descubrir: w y z
DFS-Forest (G)
1 for each vertex v  G.Vertices()
2
marca[v] =
3
p[v] = NIL
4 tiempo = 0

5 for each vertex v  G.Vertices(),
6
if marca[v] ==
7
DFS (G, v)
// el proceso se repite hasta que
// todos los vértices hayan sido descubiertos

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(w) = {y,z}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(w) = {y,z}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(w) = {y,z}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(w) = {y,z}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(z) = {z}

DFS
Seguimiento
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
10. f [origen] = tiempo

G.Ady(z) = {z}

DFS
Seguimiento
G.Ady(w) = {y,z}
DFS (G,origen)
1. tiempo = tiempo + 1
2. d [origen] = tiempo
3. marca[origen] = Gris
4. for each v  G.Ady(origen)
5.
if marca [v] ==
6.
p [v] = origen
7.
DFS (G,v)
8. marca[origen] = Negro
9. tiempo = tiempo + 1
DFS(G,w) terminó: todos los vértices alcanzables
10. f [origen] = tiempo
desde “w” han sido descubiertos

DFS
Seguimiento
No quedan vértices por descubrir
DFS_FOREST( G)
1 for each vertex v  G.Vertices()
2
marca[v] =
3
p[v] = NIL
4 tiempo = 0

5 for each vertex v  G.Vertices(),
6
if marca[v] ==
7
DFS (G, v)
// el proceso terminó
// todos los vértices han sido descubiertos

DFS
Resultado de DFS_Forest ( G=(V,E) )

P (Predecesor)
Nil
u

u
v

Nil
w

y
x

v
y

w
z

Subgrafo Predecesor Gp = (V, Ep)

que forma un Bosque dfs
que comprende varios árboles dfs

Ep es el conjunto de arcos de árbol :
Ep = { (p[v], v ) : vV y p[v]  Nil }
El recorrido DFS puede asociarse a un árbol “implícito”.

DFS

Si comenzamos el recorrido

desde el vértice w, ¿obtenemos
Recorrido obtenido
comenzando la
exploración desde el
vértice u

el mismo bosque de exploración?

DFS
Un mismo grafo
distintos árboles/bosque
de recorrido asociados

DFS

P

-

a

b

b

d

d

a

b

c

d

e

f

P

-

c

d

-

d

d

a

b

c

d

e

f

Un mismo grafo,
distintos árboles/bosque de recorrido asociados

DFS_Forest - Complejidad temporal
DFS es llamado exactamente una vez por cada
vértice:
 Cada vértice u sobre el cual el DFS es invocado
debe ser blanco y el dfs lo pinta gris
 Durante una ejecución del DFS a partir de u, el
loop entre las líneas 4-7 itera |G.ady(u)| veces

DFS_FOREST( G)
1 for each vertex u  G.Vertices()
2
marca[u] =
3
p[u] = NIL
4 tiempo = 0
5 for each vertex u  G.Vertices(),
6
if marca[u] ==
7
DFS (G, u)
DFS ( G, u )
1. tiempo = tiempo + 1
2. d [u] = tiempo
3. marca[u] = Gris
4. for each v  G.Ady( u )
5.
if marca [v] ==
6.
p [v] = u
7.
DFS (G,v)
8. marca[u] = Negro
9. tiempo = tiempo + 1
10. f [u] = tiempo

DFS_Forest - Complejidad temporal
DFS es llamado exactamente una vez por cada
vértice:
 Cada vértice u sobre el cual el DFS es invocado
debe ser blanco y el dfs lo pinta gris

 Durante una ejecución del DFS a partir de u, el
loop entre las líneas 4-7 itera |G.ady(u)| veces
Dado G (V, E ),

|E| = e,

|V| = n

 | G.ady(u) |  O ( e )  TDFS  O ( e )
uV

DFS_FOREST( G)
1 for each vertex u  G.Vertices()
2
marca[u] =
3
p[u] = NIL
4 tiempo = 0
5 for each vertex u  G.Vertices(),
6
if marca[u] ==
7
DFS (G, u)
DFS ( G, u )
1. tiempo = tiempo + 1
2. d [u] = tiempo
3. marca[u] = Gris
4. for each v  G.Ady( u )
5.
if marca [v] ==
6.
p [v] = u
7.
DFS (G,v)
8. marca[u] = Negro
9. tiempo = tiempo + 1
10. f [u] = tiempo

DFS_Forest - Complejidad temporal
DFS es llamado exactamente una vez por cada
vértice:
 Cada vértice u sobre el cual el DFS es invocado
debe ser blanco y el dfs lo pinta gris

 Durante una ejecución del DFS a partir de u, el
loop entre las líneas 4-7 itera |G.ady(u)| veces
Dado G (V, E ),

|E| = e,

|V| = n

 | G.ady(u) |  O ( e )  TDFS  O ( e )
uV

TDFS_Forest (n,e)  O(max (n,e) )

DFS_FOREST( G)
1 for each vertex u  G.Vertices()
2
marca[u] =
3
p[u] = NIL
4 tiempo = 0
5 for each vertex u  G.Vertices(),
6
if marca[u] ==
7
DFS (G, u)
DFS ( G, u )
1. tiempo = tiempo + 1
2. d [u] = tiempo
3. marca[u] = Gris
4. for each v  G.Ady( u )
5.
if marca [v] ==
6.
p [v] = u
7.
DFS (G,v)
8. marca[u] = Negro
9. tiempo = tiempo + 1
10. f [u] = tiempo

UNIDAD 1- Grafos
Agenda
Métodos de exploración de grafos:
•

Depth-First-Search (DFS) – Búsqueda en profundidad

• Breath-First- Search (BFS) - Búsqueda en anchura

Búsqueda en anchura
BFS
 Parte de un vértice origen y recorre sistemáticamente el grafo para
descubrir cada vértice alcanzable desde él.
 Los vértices se visitan en orden de distancia creciente respecto al
vértice origen. La “distancia” es simplemente el número de
arcos/aristas incluidas en un camino más corto.

Búsqueda en anchura
BFS
 Parte de un vértice origen y recorre sistemáticamente el grafo para
descubrir cada vértice alcanzable desde él.
 Los vértices se visitan en orden de distancia creciente respecto al
vértice origen. La “distancia” es simplemente el número de
arcos/aristas incluidas en un camino más corto.

Búsqueda en anchura
BFS
 Parte de un vértice origen y recorre sistemáticamente el grafo para
descubrir cada vértice alcanzable desde él.
 Los vértices se visitan en orden de distancia creciente respecto al
vértice origen. La “distancia” es simplemente el número de
arcos/aristas incluidas en un camino más corto.

Búsqueda en anchura
BFS
 Parte de un vértice origen y recorre sistemáticamente el grafo para
descubrir cada vértice alcanzable desde él.
 Los vértices se visitan en orden de distancia creciente respecto al
vértice origen. La “distancia” es simplemente el número de
arcos/aristas incluidas en un camino más corto.

 Produce un “árbol de recorrido” cuya raíz es origen y contiene todos
los vértices alcanzables desde él.

Búsqueda en anchura BFS
BFS ( G, origen)

camino más corto

Para cada vértice v alcanzable desde el vértice origen, BFS obtiene
el camino más corto desde origen hasta v (no existe camino desde
origen hasta v que tenga menos arcos)

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS

Búsqueda en anchura BFS
Los resultados de la búsqueda en ancho dependen del orden en el que tomemos
los vértices adyacentes a un vértice dado (línea 12 del código):
Si realizamos un BFS(G, s):

El árbol del recorrido en ancho puede variar, pero las distancias calculadas por el algoritmo no cambian.

BFS - Complejidad temporal

Búsqueda en anchura BFS
Utilizado como método de exploración de un grafo:
El BosqueBFS garantiza explorar el árbol en su totalidad
BosqueBFS ( G)
{
for (int i=0; i < N; i++)
marca[i]=Blanco;

for (unsigned int j =0; j < N; j++)
if ( marca[j] == Blanco )
BFS (G, j );
}

Búsqueda en anchura
BFS ( G, origen) {
Fila F
marca[origen] = Negro
F.agregar ( origen);
while ( not F.esVacia() )
u = F.recuperar();
procesar u;
for each v ϵ G.Ady(u)
if marca [v] == Blanco
marca[v] = Negro
p [v] = u
F.agregar(v)
F.eliminar()
}

Ejercicios
Realizar los ejercicios 1. a) y 2. a) de la práctica de grafos.

Nota
Los ejemplos vistos en esta presentación para los seguimientos de los recorridos fueron
tomados del libro:
Cormen, T.; Lieserson, C.; Rivest, R.; Stein, C. Introduction to Algorithms. (Third edition).
Capítulo 22:
22.2 Breadth-ﬁrst search
22.3 Depth-ﬁrst search

Bibliografía
• Aho, A; Hopcroft,J y Ullman, J. Estructuras de datos y algoritmos.
Addison Wesley
• Aho, A. & Ullman, J. Foundations of Computer Science. Computer
Science Press
• Cormen, T.; Lieserson, C.; Rivest, R.; Stein, C. Introduction to
Algorithms. (Third edition). The MIT Press.

• Horowitz, E.; Sahni, S.; Rajasekaran, S. Computer Algorithms / C++.
Silicon Press

