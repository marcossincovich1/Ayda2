Exploración de grafos
no dirigidos
Liliana Martinez - Claudia Pereira

Problemas sobre grafos no dirigidos
✓ Detección de caminos
✓ Componentes conexas

✓ Puntos de articulación

Problemas sobre grafos no dirigidos

✓ Detección de caminos:
✓

¿existe camino desde un vértice s a otro vértice v?
Si existe, encontrar el camino.

✓

¿existe camino desde un vértice s a otro vértice v?
Si existe, encontrar el camino más corto
(aquel con mínimo número de aristas).

Problemas sobre grafos no dirigidos

✓ Detección de caminos:
✓

¿existe camino desde un vértice s a otro vértice v?
Si existe, encontrar el camino.

✓

DFS (G, s)

¿existe camino desde un vértice s a otro vértice v?
Si existe, encontrar el camino más corto
(aquel con mínimo número de aristas).

BFS (G, s)

Problemas sobre grafos no dirigidos

✓ Detección de caminos:
✓ Componentes conexas
✓

¿existe conexión entre dos vértices dados?

✓

¿cuántas componentes conectadas tiene un grafo?

Componentes conexas: definición
•

un grafo no orientado se puede dividir en una o más componentes
conexas.

•

Cada componente es un conjunto de nodos con caminos desde
cualquier nodo de la componente a otro nodo dentro de la misma
componente.

Componentes conexas: definición

•

Las componentes conectadas son máximas, es decir, para cada
componente ningún nodo en la componente tiene un camino a otro
nodo fuera de la componente.

•

Si el grafo tiene una única componente conectada, decimos que el
grafo está conectado.

Componentes conexas: algoritmos
Algoritmos para determinar las componentes conexas:
•

Algoritmo basado en Depth-First Search o Breath-First Search

•

Algoritmo basado en la estructura de Conjuntos Disjuntos

Componentes conexas: algoritmos
•

Algoritmo basado en Depth-First Search o Breath-First Search

aplicando DFS-Forest sobre el grafo original

Cada árbol del bosque de exploración es una componente conexa.
O( max ( n, e ))

Componentes conexas: algoritmos
Algoritmos para determinar las componentes conexas:
•

Algoritmo basado en Depth-First Search o Breath-First Search

•

Algoritmo basado en la estructura de Conjuntos Disjuntos

Componentes conexas: algoritmo
Algoritmo que usa Conjuntos disjuntos para las Componentes:

Componentes-Conexas ( G(V,E) )
{
ConstruirComponentes(n);

// n Conjuntos inicializados con los vértices de G
// cada vértice está en un conjunto

for c/ arista {u,v} perteneciente a E
if ( Rep_u = EncontrarComponente(u)

{
≠

Rep_v = EncontrarComponente(v) )

{
unionComponentes ( Rep_u, Rep_v );
}
}

Componentes conexas: algoritmo (seguimiento)
G=

Una estructura de datos para representar las
componentes conexas

Conjuntos disjuntos

Conjuntos disjuntos

Conjuntos disjuntos
Algunas aplicaciones necesitan agrupar n elementos distintos en una
colección de conjuntos disjuntos.
Operaciones que pueden realizarse sobre los conjuntos:

 Encontrar el único conjunto que contiene un elemento dado
 Unir dos conjuntos

Desafío: encontrar una representación para almacenar los conjuntos
disjuntos de forma tal que las operaciones sean eficientes

Conjuntos disjuntos
Asumamos:

 Que los elementos de los conjuntos están numerados 1,2,3,..n.
 Los conjuntos son disjuntos.
 n = 10 y los elementos están particionados en:
S1= {1,7,8,9},

S2 = {2,5,10}

y

S3 ={3,4,6}

Conjuntos disjuntos
Asumamos:

 Que los elementos de los conjuntos están numerados 1,2,3,..n.
 Los conjuntos son disjuntos.
 n = 10 y los elementos están particionados en:
S1= {1,7,8,9},

S2 = {2,5,10}

y

S3 ={3,4,6}

Una posible representación para estos conjuntos es un bosque de árboles:

Conjuntos disjuntos
Operaciones
Unión de conjuntos disjuntos: si Si y Sj son dos conjuntos disjuntos 
Si  Sj = todos los elementos x : x  Si o x  Sj 
Ejemplo:

S1 U S2

Conjuntos disjuntos
Operaciones
Unión de conjuntos disjuntos: si Si y Sj son dos conjuntos disjuntos 
Si  Sj = todos los elementos x : x  Si o x  Sj 
Ejemplo:

S1 U S2

Conjuntos disjuntos
Operaciones
Unión de conjuntos disjuntos: si Si y Sj son dos conjuntos disjuntos 
Si  Sj = todos los elementos x : x  Si o x  Sj 
Ejemplo:

S1 U S2

Conjuntos disjuntos
 Find (i): dado el elemento i, encontrar el conjunto al cual pertenece.
Ejemplo: el elemento 4 está en el conjunto S3 y 9 está en S1.
Find (9)  S1
Find (10)  S2

Conjuntos disjuntos
A los conjuntos se los puede identificar por las raíces de los árboles que los representan.
Como los elementos de los conjuntos están numerados de 1..n, representamos los nodos
del árbol usando un arreglo p[1..n], donde n es el número máximo de elementos

p[i] padre de i

p

-1

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

P[i]= -1  i es
la raíz del árbol

Conjuntos disjuntos
Clase Sets con algoritmos simples para los métodos Union y Find:
class Sets {
private:
int *p;
public:
Sets (int n)
{ p= new int[n+1];
for (int i=0; i<=n; i++) p[i]= -1;
}
~ Sets () {delete []p;}
void SimpleUnion (int i, int j);
int SimpleFind (int j);
};

Conjuntos disjuntos
Algoritmos simples para Union y Find

SimpleUnion (1, 5)

Conjuntos disjuntos
Algoritmos simples para Union y Find
p

-1

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

SimpleUnion (1, 5)

p

5

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

Conjuntos disjuntos
Algoritmos simples para Union y Find
p

-1

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

void Sets::SimpleUnion (int i, int j)
{ // el primer árbol se vuelve subárbol del segundo
p[i] = j;
}

SimpleUnion (1, 5)

p

5

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

Conjuntos disjuntos
Algoritmos simples para Union y Find
int Sets::SimpleFind (int i)
{

//comenzamos en i hasta alcanzar el nodo con valor del padre -1

while (p[i] >= 0)

SimpleFind( 9 )

i = p[i];
return i;
}

p

5

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

Conjuntos disjuntos
Algoritmos simples para Union y Find
int Sets::SimpleFind (int i)
{

// comenzamos en i hasta alcanzar el nodo con valor del padre -1

while (p[i] >= 0)

SimpleFind( 9 )

i = p[i];
return i;
}

p

5

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

Conjuntos disjuntos
Algoritmos simples para Union y Find
int Sets::SimpleFind (int i)
{

// comenzamos en i hasta alcanzar el nodo con valor del padre -1

while (p[i] >= 0)

SimpleFind( 9 )

i = p[i];
return i;
}

return 5
p

5

5

-1

3

-1

3

1

1

1

5

1

2

3

4

5

6

7

8

9

10

Conjuntos disjuntos
Los algoritmos son simples pero su desempeño no es muy bueno.
Ejemplo:  supongamos n elementos, cada uno en su propio conjunto
 supongamos la siguiente secuencia de operaciones

Union (1,2)

Conjuntos disjuntos
Los algoritmos son simples pero su desempeño no es muy bueno.
Ejemplo:  supongamos n elementos, cada uno en su propio conjunto
 supongamos la siguiente secuencia de operaciones

Union (1,2)
Union (2,3)

Conjuntos disjuntos
Los algoritmos son simples pero su desempeño no es muy bueno.
Ejemplo:  supongamos n elementos, cada uno en su propio conjunto
 supongamos la siguiente secuencia de operaciones

Union (1,2)
Union (2,3)
Union (3,4)
.....
Union (n-1,n)

árbol degenerado

Conjuntos disjuntos
Los algoritmos son simples pero su desempeño no es muy bueno.
Ejemplo:  supongamos n elementos, cada uno en su propio conjunto
 supongamos la siguiente secuencia de operaciones

Union (1,2)
Union (2,3)
Union (3,4)
.....
Union (n-1,n)
Find(1)
Find(2)
...
Find(n)

árbol degenerado

Conjuntos disjuntos
Union (1,2)  O(1)
Union (2,3)
Union (3,4)
.....
Union (n-1,n)
Find(1)
Find(2)
...
Find(n)

n veces Union  O(n)

Conjuntos disjuntos
Union (1,2)  O(1)
Union (2,3)
Union (3,4)
.....
Union (n-1,n)
Find(1)
Find(2)
...
Find(n)

n veces Union  O(n)

Find de un elemento en el nivel i  O(i)
n Find 

𝑛-1
𝑖=0

𝑖+1

ϵ O( n2 )

Conjuntos disjuntos
Union (1,2)
Union (2,3)
Union (3,4)
.....
Union (n-1,n)
Find(1)
Find(2)
...
Find(n)

El ejemplo representa la peor situación

Podemos mejorar el desempeño de los
algoritmos Union y Find evitando la creación
de árboles degenerados

Regla del peso para Union (i, j)

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Si el número de nodos en el árbol i es menor o igual al número de nodos en j, haremos j
padre de i, de lo contrario haremos i padre de j.

Este ejemplo representa la mejor situación

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Implementación  necesitamos conocer cuántos nodos tiene cada árbol

p

-1

-1

1

5

5 es raíz del árbol => p[5] = -1, un número negativo indica que 5 es la raíz del árbol

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Implementación  necesitamos conocer cuántos nodos tiene cada árbol

p

-4

-3

1

5

5 es raíz del árbol => p[5] = -3, un número negativo indica que 5 es la raíz del árbol
| p[5] | = 3, cantidad de nodos del árbol

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Implementación

p

-4

-3

1

5

void Sets::Union (int i, int j)
{
int temp = p[i] + p[j];
if ( p[i] > p[j]) {
p[i] = j ; // i tiene menos nodos
p [j] = temp; }
else {
p[j] = i ; // j tiene menos nodos
p [i] = temp;
}
}
O (1)

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Union (1,5)

p

-7

1

1

5

void Sets::Union (int i, int j)
{
int temp = p[i] + p[j];
if ( p[i] > p[j]) {
p[i] = j ; // i tiene menos nodos
p [j] = temp; }
else {
p[j] = i ; // j tiene menos nodos
p [i] = temp;
}
}
O (1)

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…
dada la configuración inicial:

y la siguiente secuencia de uniones:

Union(1, 2), Union(3, 4), Union(5, 6), Union(7, 8),
Union(1, 3), Union(5, 7), Union(1, 5)

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…

Árboles iniciales de 1 (20) nodo,
altura 0

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…

Árboles iniciales de 1 (20) nodo,
altura 0

Union(1, 2), Union(3, 4), Union(5, 6), Union(7, 8)
Árboles de 2 (21) nodos, altura 1

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…

Árboles iniciales de 1 (20) nodo,
altura 0

Union(1, 3), Union(5, 7)
Árboles de 4 (22) nodos, altura 2

Union(1, 2), Union(3, 4), Union(5, 6), Union(7, 8)
Árboles de 2 (21) nodos, altura 1

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…

Árboles iniciales de 1 (20) nodo,
altura 0

Union(1, 3), Union(5, 7)
Árboles de 4 (22) nodos, altura 2

Union(1, 2), Union(3, 4), Union(5, 6), Union(7, 8)
Árboles de 2 (21) nodos, altura 1

Union(1, 5)
Árboles de 8 (23) nodos, altura 3

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…
Este ejemplo ilustra el peor caso: los tamaños de los árboles que se
unen son siempre iguales y potencia de 2 (n= 2k).
Los árboles resultantes tienen la siguiente propiedad:
la altura de un árbol de 2k nodos es k.
Cuando unimos dos árboles de 2k nodos, obtenemos un árbol de 2k+1
nodos, y aumentamos la altura del árbol a k + 1.

A partir de esta observación podemos probar que la unión por peso
produce árboles que en el peor de los casos tienen una altura log n.
Luego, podemos afirmar que la profundidad de cualquier nodo en
un bosque de n nodos construido con la unión por pesos, es a lo
sumo log n.

Conjuntos disjuntos
Regla del peso para la Union(i, j):
Analicemos el comportamiento de la regla del peso…

Si La profundidad de cualquier nodo en un bosque de n
nodos construido con la unión por pesos, es a lo sumo log n.

El tiempo de procesar un Find ϵ O (log n) si hay n nodos en el árbol.

Conjuntos disjuntos
Existe una mejora adicional !
Modificar el algoritmo FIND usando compresión de camino (Collapsing rule)

Si j es un nodo que está en el
camino desde i hasta su raíz,
hacemos que p[j] sea igual a raíz[i],
es decir, p[j] = Find(i)

Conjuntos disjuntos
Existe una mejora adicional !
Modificar el algoritmo FIND usando compresión de camino (Collapsing rule)
int Sets::Find (int i)
{ int r = i;
while (p[r] >= 0)
r = p[r] // encuentra la raíz
while ( i != r) {
// cuelga cada nodo en el camino
// de i a la raíz de la raíz
temp = p[i];
p[i] = r;
i= temp; }
return r;
}

Conjuntos disjuntos
Por lo tanto, utilizando:
 la regla del peso en la Union y

 compresión de camino en el Find
dada la secuencia intercalada de n-1 UNION y m FIND
tiempo en el peor de los casos será: O (max (n , m α(n) ))

∗ 𝛼 : inversa de la función de Ackermann, función que no es constante y
crece más lentamente que log n

Conjuntos disjuntos
class Sets {
private:
int *p;
int count; // almacena la cantidad de conjuntos
public:

Sets (int n);
~ Sets ();
int Count ( );

bool Connected (int i, int j);
void Union (int i, int j);
int Find (int j);
};

Conjuntos disjuntos
Sets::Sets (int n) {
p= new int[n+1];
for (int i=0; i<=n; i++)
p[i]= -1;
count = n;
}

Sets::~Sets () {
delete []p;
}
int Sets::Count () {
return count; //devuelve la cantidad de conjuntos
}
bool Sets::Connected (int i, int j) {
return Find(i) == Find(j); // true si i y j están en la misma componente
}
// false en otro caso

Conjuntos disjuntos
void Sets::Union (int i, int j) {
assert (p[i]<0 && p[j]<0);
// i y j deben ser raíces de conjuntos
int temp = p[i] + p[j];
if ( p[i] > p[j])
// i tiene menos nodos
{ p[i] = j ; p [j] = temp; }
else
// j tiene menos nodos
{ p[j] = i ; p [i] = temp; }
count--;
}
int Sets::Find (int i)
{ int r = i, temp;
while (p[r] >= 0)
r = p[r];
// encuentra la raíz
while ( i != r) {
// cuelga cada nodo en el camino de i a la raíz de la raíz
temp = p[i]; p[i] = r; i= temp;
}
return r;
}

Componentes conexas

Algoritmo que usa el TDA Sets (Conjuntos disjuntos)
para obtener las componentes conexas

Componentes conexas: algoritmo
Algoritmo que usa el TDA Sets (Conjuntos disjuntos) para los Componentes:

Componentes-Conexas ( G(V,E) )
{
Sets Componentes(n);

// Conjuntos disjuntos inicializados con los vértices de G

for c/ arista {u,v} perteneciente a

E

{

if ( componente_u= Componentes.find(u)

≠

componente_v= Componentes.find(v))

{
Componentes.union (componente_u, componente_v);
}
}

Componentes conexas: algoritmo
Algoritmo que usa el TDA Sets (Conjuntos disjuntos) para los Componentes:
Componentes-Conexas ( G(V,E) )
{
Sets Componentes(n);

//

O(n)

for c/ arista {u,v} perteneciente a

E

{

if ( componente_u= Componentes.find(u)
{

//
≠

O(e)

componente_v= Componentes.find(v))

// find(i) ϵ O(α (n))
Componentes.union (componente_u, componente_v);

//

O(1)

}
}

O ( e α (n))

Componentes conexas: algoritmos
Comparación de los algoritmos:
• Algoritmo basado en Depth-First Search o Breath-First Search
Cuando las aristas del grafo son estáticas, es decir, no cambian en el tiempo.

O( max ( n, e ))
• Algoritmo basado en la estructura de Conjuntos Disjuntos
Cuando las aristas son adheridas dinámicamente y necesitamos mantener las componentes
conectadas. Usar Conjuntos Disjuntos es más eficiente que correr el DFS-Forest cada vez que
se agregue una nueva arista.

O ( e α (n))

Problemas sobre grafos no dirigidos


Detección de caminos



Componentes conexas



Puntos de articulación

Puntos de articulación
Un punto de articulación de un grafo no dirigido es un vértice v,
tal que cuando se elimina junto con todas las aristas que inciden en él,
se divide un componente conexo en dos o más partes.

Puntos de articulación

Supongamos que el grafo modela una red de comunicaciones
Detectar puntos de articulación permite identificar puntos débiles

Puntos de articulación
Puntos de articulación: a y c

Si se elimina a

Puntos de articulación
Puntos de articulación: a y c

Si se elimina c

Puntos de articulación

Un grafo está biconectado si sigue estando conectado después de eliminarse
uno cualquiera de sus vértices y las aristas que inciden en ese vértice.

Luego:
Un grafo está biconectado  No tiene puntos de articulación

Puntos de articulación
Un grafo es bicoherente si cada uno de sus puntos de articulación está unido
mediante al menos dos aristas con cada una de las componentes del grafo

que quedarían al eliminar el vértice punto de articulación.

Si el grafo que modela una red de comunicaciones es bicoherente, la red sigue
funcionando aunque falle una línea (arista)

Puntos de articulación

¿Cómo obtener los puntos de articulación
de un grafo no orientado?

Puntos de articulación
Podemos encontrar los puntos de articulación con un DFS

Sea G el grafo original

En el árbol de exploración del DFS (G)
aparecen 2 tipos de arcos:

➢ arcos del árbol
➢ arcos de retroceso

Puntos de articulación
dos tipos de caminos entre los nodos del árbol de exploración

➢ caminos a través de los arcos del árbol hacia los padres
➢ caminos alternativos a través de los arcos de retroceso

Puntos de articulación

Puntos de articulación

v es un punto de articulación

Puntos de articulación
Si se elimina el nodo b

sus descendientes tienen caminos alternativos, es decir,
pueden “ascender” hasta alguno de los antecesores de b en el árbol.

Puntos de articulación
Si se elimina el nodo c

punto de articulación

sus descendientes NO tienen caminos alternativos, es decir,
no pueden “ascender” hasta alguno de los antecesores de c en el árbol.

Puntos de articulación
Si se elimina el nodo a

punto de articulación

(raíz del árbol de exploración)

sus dos subárboles quedan desconectados ( no hay arcos cruzados )

Puntos de articulación
El algoritmo que determina cuáles son los puntos de articulación de un grafo no
dirigido se basa en el cálculo de caminos alternativos.

Para cada vértice :
averiguar hasta dónde puede retroceder
en el árbol siguiendo arcos del árbol y
arcos de retroceso

Puntos de articulación
Algoritmo para calcular los puntos de articulación basado en DFS:
1. Calcular para todo vértice v:
preorden [v] → es el número de preorden en el recorrido
(marcar el vértice v en el momento de su descubrimiento)

Puntos de articulación
preorden [a] =1
preorden [b] =2

preorden [d] =3

preorden [e] =4

Puntos de articulación
Algoritmo para calcular los puntos de articulación basado en DFS:

2. Calcular para todo vértice v:
bajo [v] → representa el vértice hasta dónde puede retroceder
el vértice v en el árbol de exploración
(marcar el vértice v en el momento de finalizar la exploración a
partir de él)

Puntos de articulación
preorden [a] =1
preorden [b] =2

preorden [d] =3

preorden [e] =4
bajo [e] = 1

bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [e] = Mínimo { 4, 2, 1 }

Puntos de articulación
preorden [a] =1
preorden [b] =2

preorden [d] =3
bajo [d] = 1

preorden [e] =4
bajo [e] = 1

bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [d] = Mínimo { 3, 1, 1 }

Puntos de articulación
preorden [a] =1

preorden [b] =2
bajo [b] = 1

preorden [d] =3
bajo [d] = 1

preorden [e] =4
bajo [e] = 1

bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [b] = Mínimo { 2, 1 }

Puntos de articulación
preorden [a] =1

preorden [b] =2
bajo [b] = 1

preorden [d] =3
bajo [d] = 1

preorden [e] =4
bajo [e] = 1

Puntos de articulación
preorden [a] =1

preorden [b] =2
bajo [b] = 1

preorden [d] =3
bajo [d] = 1

preorden [e] =4
bajo [e] = 1

preorden [c] =5

preorden [f] =6

preorden [g] =7

Puntos de articulación
preorden [a] =1
preorden [c] =5

preorden [f] =6
bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [g] = Mínimo { 7, 5 }

preorden [g] =7
bajo [g] = 5

Puntos de articulación
preorden [a] =1
preorden [c] =5

preorden [f] =6
bajo [f] = 5
bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [f] = Mínimo { 6, 5 }

preorden [g] =7
bajo [g] = 5

Puntos de articulación
preorden [a] =1
preorden [c] =5

Punto de Articulación
bajo [f]  preorden [c]

preorden [f] =6
bajo [f] = 5

preorden [g] =7
bajo [g] = 5

Puntos de articulación
preorden [a] =1
preorden [c] =5
bajo [c] = 5

preorden [f] =6
bajo [f] = 5
bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [c] = Mínimo { 5, 5 }

preorden [g] =7
bajo [g] = 5

Puntos de articulación
preorden [a] =1
bajo [a] = 1
preorden [b] =2
bajo [b] = 1

bajo [v] = Mínimo
{ preorden [v],
preorden [z] (∀ z :  un arco back (v, z)
bajo [y] (∀ y  hijos de v en ARBOLDFS)
}
bajo [b] = Mínimo {1, 1, 5 }

preorden [c] =5
bajo [c] = 5

Puntos de articulación
Punto de Articulación
La raíz tiene dos hijos,
si se elimina, el grafo
queda dividido en
dos componentes
(no existen arcos cruzados)

preorden [a] =1
bajo [a] = 1

Puntos de articulación
preorden [b] =2
bajo [b] = 1

preorden [a] =1
bajo [a] = 1
preorden [c] =5
bajo [c] = 5

preorden [d] =3
bajo [d] = 1

preorden [f] =6
bajo [f] = 5

preorden [e] =4
bajo [e] = 1

preorden [g] =7
bajo [g] = 5

Puntos de Articulación:

➢ la raíz del árbol porque tiene más de un hijo
➢ vértice c porque tiene un hijo f cuyo bajo[f]  preorden[c]

Puntos de articulación
Algoritmo para calcular los puntos de articulación basado en DFS:
3. Obtener los puntos de articulación:

➢la raíz del árbol de exploración es un punto de articulación
si, y sólo si, tiene dos o más hijos
(no hay aristas cruzadas, la eliminación de la raíz desconecta los subárboles)

➢Un vértice v distinto de la raíz es un punto de articulación
si, y sólo si, hay un hijo w de v tal que bajo[w] ≥ preorden[v]
(la eliminación de v desconecta a w y a sus descendientes del resto del árbol)

Puntos de articulación
El algoritmo para calcular los puntos de articulación de un grafo no dirigido

1. Calcula preorden[v], para todo vértice v
2. Calcula bajo[v] , para todo vértice v
3. Obtiene los puntos de articulación

• Todos los cálculos se realizan dentro del
mismo recorrido en profundidad

• Cálculos añadidos al DFS se pueden
hacer en tiempo constante

Complejidad temporal O(max(n , a))

Ejercicios
Dado el grafo no dirigido de la figura:
1.

Realice un seguimiento del recorrido en
profundidad para determinar los puntos de
articulación.

2.

Modifique el pseudocódigo del recorrido en
profundidad para determinar los puntos de
articulación.

3.

Implemente en C++ un algoritmo que
determine los puntos de articulación.

Circuito euleriano
Ciclo euleriano
Un ciclo euleriano en un grafo no dirigido es un ciclo que pasa
por todas las aristas exactamente una vez, regresando al punto
de partida.

Camino euleriano

Un camino euleriano en un grafo G no dirigido es un camino
que pasa por cada arista una y sólo una vez.

Circuito euleriano
Si G= (V, E ) es un grafo no-dirigido conectado euleriano =>

• todo vértice v  V tiene grado par

Circuito euleriano (1,2,3,4,5,8,7,3,6,5,3,1)

• las aristas de G pueden particionarse en circuitos
Circuito euleriano = (5,4,3,6,5,8,7,3,1,2,3,5)

Circuito euleriano: Algoritmo
Entrada: G= (V,E) no-dirigido conexo,  v  V, v tiene grado par
Salida: circuito euleriano de G

1 Construir un ciclo C1 que incluye un conjunto E1 de aristas a partir de un vértice v.
2 while (E != E1)
{

elegir un vértice w tal que exista (w,u)  E1 y (w,z)  E - E1;

desde w construir un ciclo C2 que incluya un conjunto de E2 aristas,
tal que E2  E1 = Ø;
C1= unir C1 y C2 a través de w; E1= E1  E2;

}

Circuito euleriano
Ejercicio:
Dado G= (V, E ), un grafo no-dirigido conectado euleriano,

implementar un algoritmo de complejidad temporal O(e) para encontrar
un circuito euleriano

Bibliografía
• Aho, A. & Ullman, J. Foundations of Computer Science. Computer Science Press
• Cormen, T.; Lieserson, C.; Rivest, R. Introduction to Algorithms. Ed. The MIT Press.
• Horowitz, E.; Sahni, S.; Rajasekaran, S. Computer Algorithms / C++. Silicon Press
• Aho, A; Hopcroft,J y Ullman, J. Estructuras de datos y algoritmos. Addison Wesley
Nota:
Conjuntos disjuntos fue tomado del libro Computer Algorithms (Horowitz, E.; Sahni, S.;
Rajasekaran, S.) Capítulo 2.5: Sets and disjoint set union, página 101.
Puntos de articulación, ejemplo tomado del libro Estructuras de datos y algoritmos (Aho, A;
Hopcroft,J y Ullman) Capítulo 7: grafos no dirigidos.

