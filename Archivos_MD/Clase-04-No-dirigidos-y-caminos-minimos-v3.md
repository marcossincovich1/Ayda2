SEMANA 4 · UNIDAD 1 · GRAFOS

Grafos no dirigidos
y caminos mínimos
Componentes conexas · puntos de articulación · heap · Dijkstra · Floyd · Warshall

Análisis y Diseño de Algoritmos II — 2.º cuatrimestre 2026

Sobre material de la cátedra de Claudia Pereira y Liliana Martínez (exploración de grafos no orientados) y de Liliana Favre (clases de grafos 2025).

RITMO DE LA CLASE

Tres horas de clase, y después una hora de consultas
Bloque

Exposición

Práctica

Puesta en común: componentes fuertemente conexas

5 min

—

Franja: ¿qué estrategia y por qué?

—

P0 · 5 min

Clasificación de arcos y componentes conexas

15 min

P1 · 8 min

Puntos de articulación

25 min

P2 · 12 min

Puentes y 2-arista-conexión

5 min

—

Corte

10 min

—

Heap y su implementación con arreglos

15 min

—

Dijkstra

20 min

P3 · 12 min

Floyd y Warshall

20 min

—

Cierre: la barrera del ordenamiento

10 min

—

Después, una hora de consultas: TP1 ejercicios 12 a 15 y 18 y preguntas sobre lo de hoy.

ANTES DE EMPEZAR · 5 MIN

Cerramos el seguimiento que nos quedó
La clase pasada dejamos el paso 3 de Kosaraju para que lo terminaran.
Lo cerramos entre todos?

LA RESPUESTA

Arranque en Gᵀ

Árbol obtenido

Componente

a (f = 16)

a, e, b

{ a, b, e }

c (f = 12)

c, d

{ c, d }

g (f = 11)

g, f

{ f, g }

h (f = 6)

h

{h}

b, e, d y f no encabezan ningún árbol: cuando les toca el turno ya están negros.

CÓMO VERIFICARLO

El arreglo comp tiene que cubrir los ocho vértices, sin repetir ninguno y sin
dejar ninguno afuera.
El grafo reducido tiene que dar acíclico.

O(n+a)

PRÁCTICA 0

¿Qué estrategia usarías y por qué?
No resuelvas, sólo se trata de decidir cómo se modela y qué recorrido se usa.
a · Una red social de contactos: hay que decir cuántos grupos aislados hay.

b · Un sistema de dependencias de compilación: hay que decir en qué orden compilar.

c · Una red eléctrica: hay que decir qué subestación no puede salir de servicio sin dejar zonas a oscuras.

Pensar si:

¿la relación es simétrica? Si NO lo es, pregunta además si hace falta el traspuesto.

5'

1

Grafos no dirigidos
Cambia la simetría y cambia el recorrido: el DFS se vuelve mucho más simple.

1 · Grafos no dirigidos

En un grafo no dirigido, DFS sólo genera dos tipos de aristas
TEOREMA 4.1. Toda arista es una arista del árbol DFS o una

3 · CONSECUENCIA

arista de retroceso.

En un DFS de un grafo no dirigido, toda arista
que no pertenece al árbol DFS conecta un

2 · POR QUÉ
Sea {u,v} una arista con d[u] < d[v].
Cuando el DFS explora u, pueden ocurrir dos situaciones:
-

v está blanco cuando se examina {u,v} :
→ la arista pertenece al árbol DFS.

-

descendiente con uno de sus ancestros.
Estas aristas de retroceso permiten saber si
un subárbol puede alcanzar un ancestro sin
pasar nuevamente por su padre.
u

v ya fue descubierto durante la exploración iniciada en u:

w

arco de retroceso

→ v pertenece al subárbol de u.
v

Cormen, Leiserson, Rivest y Stein, 4.ª ed., Teorema 20.10 (3.ª ed.: Teorema 22.10). Notación d[v] / f[v] para preorden / postorden respectivamente.

1 · Grafos no dirigidos

Componentes conexas: un bosque de exploración
DEFINICIÓN 4.2. Una componente conexa es un
subgrafo conexo maximal: contiene todos los vértices
alcanzables entre sí.
Si ejecutamos DFS recorriendo todos los vértices,
cada árbol del bosque DFS corresponde exactamente a una
componente conexa.

Grafo estático
Si conocemos todas las aristas de antemano, usamos DFS o BFS.
Construir las componentes conexas cuesta: O(n+a).

Grafo dinámico: solo inserciones
Si las aristas se agregan una a una y después de cada inserción
queremos responder si dos vértices están conectados, conviene

Durante el mismo recorrido podemos contar las componentes y
etiquetar cada vértice con su componente, manteniendo O(n+a)
a

b

e

f

h

usar conjuntos disjuntos (Union-Find).
Con compresión de caminos y unión por rango/tamaño:
O(α(n))

j

amortizado por operación.
Recalcular DFS después de cada inserción sería innecesariamente
c

d

g

i

4 componentes
Horowitz, Sahni y Rajasekaran, «Computer Algorithms / C++», §2.5. Cormen 4.ª ed., §20.3 (3.ª ed.: §22.3).

costoso.
Union-find se desarrolla completo en la clase 5, cuando veamos el algoritmo de Kruskal.

1 · Grafos no dirigidos

Componentes conexas: el algoritmo
COMPONENTES_CONEXAS(G) {

Lo único que se agrega al DFS es el contador del

for (cada vértice v de G) {
color[v] = BLANCO;
comp[v]

bucle exterior y el arreglo comp[]. El recorrido no
cambia.

= 0;

}
k = 0;

// contador de componentes

for (cada vértice v de G)
if (color[v] == BLANCO) {
k = k + 1;

Complejidad O(n + a). Cada vértice se visita una vez y
cada arista se recorre dos.

VISITAR(G, v, k);
}
return k;
}

Resuelve el ejercicio 10 del TP1.

VISITAR(G, u, k) {
color[u] = GRIS;
comp[u]

= k;

// u pertenece a la componente k

for (cada w en Ady[u])
if (color[w] == BLANCO)
VISITAR(G, w, k);
color[u] = NEGRO;
}

1 · Grafos no dirigidos

Seguimiento: cuatro componentes en un recorrido

a

b

e

f

h

j

EL BUCLE EXTERIOR
Llama a VISITAR cuatro veces: desde a, desde e,

c

d

g

desde h y desde j.

i

Las otras seis veces que el bucle mira un vértice,
ya está negro y no hace nada.
k queda en 4, y comp[] dice a qué componente
v

a

b

c

d

e

f

g

h

i

j

pertenece cada vértice: son las dos respuestas

comp[v]

1

1

1

1

2

2

2

3

3

4

que pide el ejercicio 10.

El vértice aislado j es una componente: un solo vértice, ninguna arista.

PRÁCTICA 1

TP1, ejercicio 10
Una red de n sensores. Dos sensores están unidos si se escuchan entre sí (la relación es simétrica).

a · Escribí el algoritmo que cuenta cuántos grupos aislados hay y dice, para cada sensor, a qué grupo
pertenece. Calculá su complejidad.

b · Ahora los enlaces se van habilitando de a uno y, después de cada alta, el operador pregunta si dos
sensores dados ya se escuchan. ¿Sirve el mismo algoritmo? ¿Cuánto cuesta?

c · ¿Qué estructura usarías en b y por qué? (Alcanza con nombrarla y justificar; la vemos en detalle la clase
que viene.)

10'

2

Puntos de articulación
Un vértice es crítico si al quitarlo aumenta la cantidad de componentes conexas.

2 · Puntos de articulación

Vértices críticos de una componente conexa
DEFINICIÓN 4.3. En un grafo no dirigido, un vértice v es un punto de articulación si al eliminar v y las aristas
incidentes en él, aumenta el número de componentes conexas del grafo.

Un grafo conexo con al menos tres vértices y sin puntos
de articulación es biconexo (o 2-conexo por vértices).
Si el grafo modela una red, sus puntos de articulación
son los puntos débiles: los nodos cuya caída deja zonas
punto de articulación

incomunicadas.
En una red, detectar los puntos de articulación permite
identificar vulnerabilidades y estudiar qué enlaces
adicionales podrían aportar redundancia.

Aho, Hopcroft y Ullman, «Estructuras de datos y algoritmos», cap. 7: grafos no dirigidos.

2 · Puntos de articulación

La idea: ¿puede el subárbol de un hijo de v conectarse hacia arriba sin pasar por v?
a

v

a

c

v

w

w

z

z

c

El subárbol de w alcanza un antecesor de v

El subárbol de w no alcanza ningún antecesor de v

Existe una arista de retroceso desde w o alguno de sus

Si eliminamos v, el subárbol de w queda separado del

descendientes hacia un antecesor de v.

resto.

Si eliminamos v, este subárbol sigue conectado con el resto:

Entonces v es punto de articulación.

Este subárbol no hace que v sea punto de articulación.
Todo se reduce a medir hasta dónde puede ascender cada vértice.

2 · Puntos de articulación

Dos números por vértice, calculados en un recorrido DFS
DEFINICIÓN 4.4 · d[v]
Tiempo de descubrimiento de v (preorden).

bajo[v] = mínimo entre:
- d[v]
- d[z] si (v,z) es una arista de retroceso

DEFINICIÓN 4.5 · bajo[v]
El menor tiempo de descubrimiento alcanzable desde v,

- bajo[y] para cada hijo y de v

recorriendo cero o más aristas del árbol DFS hacia

Bajo[v] se inicializa al descubrir v y su valor definitivo se

descendientes y, eventualmente, una arista de retroceso

conoce al terminar de explorar su subárbol.

hacia un ancestro.

CUIDADO. bajo[v]es un número de descubrimiento, no un vértice. Indica cuán «arribaK puede conectarse el subárbol de v.

Aho, Hopcroft y Ullman, cap. 7: numeración del recorrido y función bajo.

2 · Puntos de articulación

Las dos condiciones aplicadas a un ejemplo
SEGUIMIENTO SOBRE EL EJEMPLO

TEOREMA 4.6. Raíz: la raíz de un árbol DFS es punto de

a

articulación si y sólo si tiene dos o más hijos en el árbol DFS.
b

c

TEOREMA 4.7. No raíz: un vértice v distinto de la raíz es
punto de articulación si y sólo si existe un hijo w en el árbol

d

f

DFS tal que bajo[w] ≥ d[v].
e

g

La raíz no tiene antecesores: sus subárboles solo pueden unirse
entre sí por arcos cruzados, y no existen.
Complejidad O(V + E): todo se calcula dentro del mismo
recorrido, y lo que se agrega al DFS es tiempo constante por
arista.

Aho, Hopcroft y Ullman, cap. 7: caracterización de los puntos de articulación.

PUNTOS DE ARTICULACIÓN: a, c
a: raíz con dos hijos.
c: hijo f con bajo[f]=5 ≥ d[c]=5.

v

d[v]

bajo

a

1

1

b

2

1

c

5

5

d

3

1

e

4

1

f

6

5

g

7

5

2 · Puntos de articulación

El algoritmo: un DFS con dos líneas más
PUNTOS_ARTICULACION(G) {
for (cada v) { d[v] = 0;

padre[v] = NIL;

esPunto[v] = false; }

tiempo = 0;
for (cada v)

if (d[v] == 0)

Las dos líneas nuevas son las de bajo[v]: una al
volver de un hijo y otra al ver un retroceso. Todo

DFS_PA(G, v);

}

lo demás es el DFS de siempre.

DFS_PA(G, v) {
tiempo = tiempo + 1;
d[v] = bajo[v] = tiempo;

// se marca al entrar

hijos = 0;
for (cada w en Ady[v]) {
if (w == padre[v])

continuar;

if (d[w] == 0) {

// no se vuelve por donde vino
// arco del árbol

hijos = hijos + 1;

Complejidad O(n + a). Lo agregado es tiempo

padre[w] = v;
DFS_PA(G, w);

constante por arista.

bajo[v] = mínimo(bajo[v], bajo[w]);
if (padre[v] != NIL

y

bajo[w] >= d[v])

if (bajo[w] > d[v])
} else

esPunto[v] = true;
registrar puente (v,w);

// arco de retroceso

bajo[v] = mínimo(bajo[v], d[w]);
}
if (padre[v] == NIL
}

y

hijos >= 2)

esPunto[v] = true;

Los puentes salen de la misma pasada: cambia ≥ por >.

PRÁCTICA 2

Puntos de articulación sobre un grafo de 11 vértices

12'

Recorrido en profundidad desde el vértice 1, listas de adyacencia en orden
creciente.

10
9

a · Dibujá el árbol de exploración e indicá los arcos de retroceso.

11

b · Calculá d[v] y bajo[v] para todo v. Presentalos en una tabla.

1
2

c · Determiná los puntos de articulación y justificá cada uno con la
3

condición que lo hace serlo.

5

6

d · Proponé una sola arista para agregar que elimine la mayor cantidad
posible de puntos de articulación.

4

7

8

2 · Puntos de articulación

Cambiando ≥ por >: puentes
TEOREMA 4.8. Una arista del árbol (v, w) es un puente si y sólo si bajo[w] > d[v]: ningún descendiente de w alcanza a
v ni a sus antecesores por otro camino.

Un puente es una arista cuya eliminación aumenta el número
de componentes.

CUIDADO: LOS DOS CONCEPTOS NO
COINCIDEN
Un extremo de un puente puede no ser punto de
articulación (si tiene grado 1), y un punto de

Un grafo conexo sin puentes es 2-arista-conexo: sigue

articulación puede no tener ningún puente

funcionando aunque falle una línea.

incidente: alcanza con que dos ciclos compartan un
solo vértice.

Mismo recorrido, mismo costo: los puentes salen del DFS que
ya calculamos, cambiando una comparación.

Cormen 4.ª ed., problema 20-2 (3.ª ed.: 22-2). El material histórico de la cátedra llama «bicoherente» a la 2-arista-conexión, siguiendo a Aho, Hopcroft y Ullman.

punto de articulación,
ninguna arista es puente

DESPUÉS DEL CORTE · BLOQUE 3

Caminos mínimos
Heap y cola de prioridad · Dijkstra · Floyd · Warshall · la barrera del ordenamiento

Esta parte se apoya en la lectura previa. Lo que se expone en clase es lo que no
se aprende leyendo: el invariante, los seguimientos y el criterio para elegir.

Análisis y Diseño de Algoritmos II — 2.º cuatrimestre 2026

3 · CAMINOS MÍNIMOS

Cuando los arcos/aristas tienen pesos diferentes
Hasta ahora, BFS suponía implícitamente que todos los arcos/aristas
tenían el mismo costo y encontraba un camino con el mínimo número de
arcos. Cuando cada arco/arista tiene un peso —distancia, costo, tiempo—,
minimizar la cantidad de arcos ya no necesariamente minimiza el costo
total.

Del vértice 3 a todos los demás
1

2

200
2

El peso de un camino

1

20

es la suma de los rótulos de sus arcos/aristas.
Un camino mínimo entre u y v es un camino cuyo peso total es
mínimo. Su valor se denota δ(u,v).

3

10
5

Subestructura óptima
Todo subcamino de un camino mínimo es, a su vez, un camino
mínimo.
Si hubiera un tramo mejor entre dos vértices intermedios, reemplazándolo
obtendríamos un camino total más corto. Contradicción.

6

6

30

4

3 → 1 → 2

30

peso 220, tres arcos

3 → 4 → 5 → 2 peso 41, cuatro arcos

5

3 · DIJKSTRA

Origen único, con estrategia greedy
Otro problema distinto: los caminos mínimos desde un solo origen
a todos los demás. Y una condición: todos los pesos deben ser no
negativos.

Invariante.

Dijkstra (G, origen)

Para todo u 𝞊 S, dist[u] = δ(origen,u): su distancia mínima ya es
definitiva.
Para todo v ∉ S, dist[v] es la menor longitud conocida de un camino
desde el origen hasta v cuyos vértices internos pertenecen a S.

1. for each v: dist[v] = ∞;

Relajar el arco (u, v)
si dist[u] + peso(u,v) < dist[v] entonces
dist[v] = dist[u] + peso(u,v)
padre[v] = u.

Relajar una arista (u,v) significa preguntar si llegar a v pasando por u mejora
la mejor distancia conocida.
Esta operación es central en Dijkstra; Floyd-Warshall utiliza una idea análoga
sobre pares de vértices.

padre[v] = NIL

2. dist[origen] = 0
3. S = ∅
4. while S ≠ V
5.

u = vértice de V−S con dist[u] mínima

6.

S = S ∪ {u}

7.

for each v ∈ G.Ady(u)

// dist[u] es definitivo

8.

if dist[u] + peso(u,v) < dist[v]

9.

dist[v] = dist[u] + peso(u,v)

10.

padre[v] = u
Complejidad: O(n2)

Elección greedy: entre los vértices aún no resueltos, hacer
definitivo el que tiene menor distancia tentativa.

3 · DIJKSTRA

Por qué la elección greedy es segura
ELECCIÓN GREEDY:
elegimos fuera de S el vértice u con menor dist[ u].

Un pequeño contraejemplo
a

Si existiera un camino mejor hacia u, consideremos
el primer vértice w de ese camino que todavía está
fuera de S. Su predecesor ya fue procesado, por la
que dist[w] ya refleja ese posible acceso.
Como
dist[w] ≥ dist[u]
y los pesos restantes son ≥0, continuar desde w
nunca puede producir un camino hasta u menor que
dist[u].
Por eso dist[u] puede hacerse definitiva.

1

s

−4
4

b

Dijkstra cierra a con dist[a] = 1, porque 1 < 4.
Pero el camino s → b → a pesa 4 − 4 = 0.
La elección que parecía definitiva era incorrecta.

3 · Caminos mínimos

Seguimiento de Dijkstra desde s
a

7

4

s

2
1

b

d

3

2

c
6

Los valores en naranja son decrementos. a entra con 4 y
después baja a 3, porque llegar por b sale más barato.

padre[ ]

distancias[ ]
S={}

s

a

b

c

d

s

a

b

c

d

{s}

0

4

1*

∞

∞

—

s

s

s

s

{s,b}

0

3*

1

7

∞

—

b

s

b

s

{s,b,a}

0

3

1

6*

10

0

b

s

a

a

{s,b,a,c}

0

3

1

6

8*

0

b

s

a

c

{s,b,a,c,d}

0

3

1

6

8

0

b

s

a

c

Caminos mínimos:

s→b = 1 · s→b→a = 3 ·

s→b→a→c = 6 · s→b→a→c→d = 8

Podemos reducir la complejidad si usamos un Heap para
extraer el mínimo pero necesitamos una operación
adicional para estos decrementos.

Complejidad: O(n2)

PRÁCTICA 3

TP1, variación del ejercicio 18 — mapa de vuelos

12'

a. Corré Dijkstra desde el vértice 3 y armá la tabla de seguimiento: en
1

cada iteración, qué vértice entra a S y cómo quedan las distancias.

2

200
2

b. Escribí el camino mínimo de 3 a 6 usando el vector padre, sin mirar el

1

20

dibujo.

3

6

6

30

10
5

4

30

5

c. Ahora la pregunta cambia: se busca ir de 3 a los demás con la MÍNIMA
CANTIDAD DE ESCALAS. ¿Sirve el mismo algoritmo? ¿Da el mismo
resultado?

d. ¿Qué algoritmo usarías si necesitaras las distancias entre TODOS los
pares? ¿Y si el grafo tuviera 2000 vértices y 4000 arcos?

3 · MIN-HEAP

Min-heap: un árbol que vive dentro de un arreglo
DEFINICIÓN 4.9. Un min-heap es un árbol binario completo que satisface la propiedad de heap: la clave de cada
nodo es menor o igual que la de sus hijos.
LA REPRESENTACIÓN: NO HAY PUNTEROS

Accesos a los hijos y al padre

3

hijo izquierdo de i → 2i

[1]

7

5

hijo derecho de i → 2i + 1

[2]

[3]

padre de i → i div 2

12

9

8

No hace falta guardar ningún puntero: la estructura del árbol está en

[4]

[5]

[6]

los índices. Por ser un árbol completo, un heap se representa
habitualmente mediante un arreglo, sin necesidad de almacenar

i

1

2

3

4

5

6

punteros.

A[i]

3

7

5

12

9

8

Que el árbol sea completo es lo que hace que el arreglo
no tenga huecos. Al ser completo, su altura es O(log n).

Cormen, 4.ª ed., §6.1 (3.ª ed.: §6.1). Horowitz, Sahni y Rajasekaran, cap. 2.

3 · DIJKSTRA

Las operaciones, y por qué Dijkstra necesita una más
POR QUÉ necesitamos un heap indexado para
decrementar una clave?

¿De dónde sale el log n?
Al ser un árbol completo, el heap tiene altura O(log n).
●

al insertar, el nuevo elemento puede subir desde una hoja hacia la raíz;

Cuando una relajación mejora dist[v], debemos

●

al extraer el mínimo, el elemento llevado a la raíz puede bajar hacia una hoja;

disminuir la clave asociada a v dentro del heap.

●

al decrementar una clave, el elemento puede subir hacia la raíz.

Para hacerlo en O(log n), necesitamos conocer

LO QUE CUESTA CADA OPERACIÓN

directamente la posición de v en el arreglo del heap.

Operación

Costo

ver el mínimo

O(1)

insertar

O(log n)

extraer el mínimo

O(log n)

decrementar una clave

O(log n)

construir el heap con n elementos
O(n)
En Dijkstra: n extracciones y hasta a decrementos
→ O((n + a)·log n) en lugar de O(n²).

Mantenemos:
pos[v] = posición actual de v en el heap
y actualizamos pos cada vez que intercambiamos 2
elementos.
Sin pos[] hay que buscar el vértice recorriendo todo
el heap, y decrementar pasa a costar O(n): la mejora
se pierde.

3 · IMPLEMENTACIÓN

Dijkstra: el algoritmo
Dijkstra combina dos ideas:
DIJKSTRA(G, origen) {
for (cada v) { dist[v] = INFINITO;

padre[v] = NIL; }

●

seleccionar como definitivo el vértice con menor distancia
tentativa;

dist[origen] = 0;

●
Q = cola de prioridad con todos los vértices, con clave dist[v];

El heap acelera la primera operación y permite actualizar
eficientemente las prioridades cuando una relajación mejora una

while (Q no está vacía) {
u = Q.extraerMinimo();

relajar las aristas que salen de él.

// O(log n)

distancia.

for (cada arco (u,w) con peso p) {
if (dist[u] + p < dist[w]) {
dist[w]

// relajación

= dist[u] + p;

padre[w] = u;
Q.decrementarClave(w, dist[w]);

// O(log n)

}
}
}
}

La mejor implementación depende de la densidad del
grafo

n extracciones y hasta a decrementos:
O((n + a)·log n) con heap binario

●

Grafos dispersos → Heap

●

Grafos densos → selección lineal ( a ≈ n²).
La estructura se elige mirando la densidad, no por
Ejercicios 12, 15 y 18 del TP1.

la costumbre.

3 · IMPLEMENTACIÓN

La línea 5 decide la complejidad
Todo el costo de Dijkstra está en cómo se implementa «elegir el vértice de menor dist[·] fuera de S». El resto del algoritmo es el mismo.

Estructura

Extraer mínimo

Relajar un arco

Total

Arreglo, búsqueda lineal

O(n), n veces

O(1), a veces

O(n² + a) = O(n²)

Heap binario

O(log n), n veces

O(log n) por
decrease-key

O((n + a) · log n)

Heap de Fibonacci

O(log n) amortizado

O(1) amortizado

O(n · log n + a)

Grafo denso, a ≈ n²

Grafo ralo, a ≈ n

Arreglo: n². Heap: n² log n. Gana el arreglo — el

Arreglo: n². Heap: n log n. Gana el heap, y por

heap paga un log de más por cada arco.

mucho. Es el caso habitual en redes reales.

Tercera vez en la materia que la estructura de datos decide la complejidad del mismo algoritmo. El TDA Heap y el
heap modificado se implementan en el laboratorio del viernes.

3 · FLOYD-WARSHALL

Floyd-Warshall: todos los pares con programación dinámica
Con Dijkstra fijábamos un origen. Ahora queremos responder, de una sola vez, cuál es la distancia mínima entre cualquier par (i,j). El estado de la
programación dinámica será una matriz.
Floyd (G)

La idea es restringir los vértices intermedios

1. d = matriz de adyacencia de G
// d[i][i]=0, d[i][j]=peso o ∞

dk[i][j] = peso del camino mínimo de i a j cuyos vértices intermedios

2. for k = 1 to n

pertenecen al conjunto {1, …, k}.

3.
4.

Con k = 0 no se permite ningún intermedio: es el arco directo, o infinito.

for i = 1 to n
for j = 1 to n

5.

if d[i][k] + d[k][j] < d[i][j]

6.

d[i][j] = d[i][k] + d[k][j]

7.

p[i][j] = p[k][j]

La recurrencia
dk[i][j]= mín( dk−1[i][j] , dk−1[i][k]+dk−1[k][j])

Complejidad: Θ(n³) siempre, mejor y peor caso. Espacio Θ(n²). La

o no uso k, o lo uso.
Si lo uso, el camino se divide en i ⇝ k y k ⇝ j, dos problemas que ya
fueron resueltos usando sólo vértices 1,..., ,k-1.

matriz p permite reconstruir los caminos, no sólo sus pesos. El orden de
los ciclos no es intercambiable: k tiene que ir afuera.

3 · FLOYD-WARSHALL

Floyd-Warshall: todos contra todos, por vértices intermedios
d(k)[i][j] = mín ( d(k−1)[i][j] , d(k−1)[i][k] + d(k−1)[k][j] )
El estado de la programación dinámica se define por los vértices que se permiten como intermedios.
En la etapa k, decidimos si el camino mínimo de i a j usa o no al vértice k.
Programación dinámica: tres bucles anidados, Θ(n³), matriz de
adyacencia.
Admite pesos negativos mientras no haya ciclos de peso
negativo — y los detecta: aparece un valor negativo en la
diagonal.
Una matriz adicional permite reconstruir los caminos, no solo
los costos.

¿DIJKSTRA O FLOYD?
●

Una fuente, grafo ralo → Dijkstra.

●

Todas las parejas,
○

grafo denso → Floyd-Warshall, Θ(n³).

○

grafo ralo y pesos no negativos → n veces
Dijkstra, O(n·a·log n), que puede ser mejor que
O(n³).

¿Hay pesos negativos? De estos dos, sólo Floyd-Warshall
sirve, siempre que no haya ciclos negativos.
Cormen, 4.ª ed., §23.2 (3.ª ed.: §25.2).

PARA RESOLVER FUERA DE CLASE

Para completar: Floyd paso a paso
8
1

2
3
5

7

2

2
1

4

3

D⁰ · sin intermedios
1
2
3

4

D⁴ · resultado final
1
2
3

4

1

0

3

∞

7

1

0

3

5

6

2

8

0

2

∞

2

5

0

2

3

3

5

∞

0

1

3

3

6

0

1

4

2

∞

∞

0

4

2

5

7

0

Consigna. Completen D¹, D² y D³ y verifiquen que llegan a D⁴. En clase calculamos una sola celda; el resto es
mecánico y se hace mejor con tiempo. Las matrices intermedias las pueden mandar al foro.
En naranja, las celdas que cambiaron respecto de D⁰. Ninguna empeora: la recurrencia solo toma mínimos. Si les da otra
cosa, el error casi siempre es el orden de los bucles.

3 · WARSHALL

Warshall: la misma recurrencia, otra pregunta
a(k)[i][j] = a(k−1)[i][j] ó ( a(k−1)[i][k] y a(k−1)[k][j] )
La matriz es booleana: a[i][j] vale verdadero si hay camino de i a j. El mínimo pasa a ser un ó, y la suma un y.

Responde «¿existe camino de i a j?» para todos los pares a la

CUÁNDO CONVIENE?

vez. El resultado se llama clausura transitiva del grafo.
●

Alcance desde un solo vértice → un DFS, O(n+a).

●

Alcance entre todos los pares,

Θ(n³), igual que Floyd, y con la misma estructura de tres

○

grafo denso → Warshall, Θ(n³).

bucles anidados con k afuera.

○

grafo ralo → n recorridos, O(n·(n+a)) que
puede ser mucho mejor que O(n³).

Floyd es Warshall con pesos: donde Warshall pone «ó», Floyd
pone mínimo; donde pone «y», suma.
Warshall, «A theorem on Boolean matrices», JACM 9(1), 1962 · Cormen, 4.ª ed., §23.2.

CIERRE

¿Es Dijkstra óptimo?
Con un heap adecuado, Dijkstra resuelve caminos mínimos con origen único en O(a + n·log n). Ese n·log n viene de
ordenar: el algoritmo produce, como subproducto, los vértices ordenados por distancia. Durante sesenta años se creyó
que ese costo era inevitable.

2024 — Dijkstra SÍ es óptimo

2025 — Dijkstra NO es óptimo

Haeupler, Hladík, Rozhoň, Tarjan y Tětek probaron en
FOCS 2024 que si se exige devolver los vértices
ordenados por distancia, no existe nada mejor.

Duan, Mao, Mao, Shu y Yin obtuvieron un algoritmo
determinístico en O(a · log^(2/3) n), mejor en grafos
dispersos. Premio al mejor trabajo en STOC 2025.

No se contradicen. Uno exige el orden de los vértices; el otro sólo pide las distancias. La cota inferior no es una
propiedad del algoritmo: es una propiedad de lo que se le exige producir. Cambiar el enunciado del problema cambió la
respuesta.

CÓMO SE RESUELVE UN EJERCICIO DEL TP

Ejercicio 14, resuelto

Enunciado. Desde k ciudades del interior se quieren transportar cereales hasta algún puerto del litoral, con mínimo
costo. Dar un algoritmo eficiente que devuelva los caminos en una lista.
1

Modelar

Vértices: ciudades. Aristas: tramos, con peso el costo. El grafo es no dirigido y ponderado.

2

Leer bien qué se pide

No es de una ciudad a un puerto: es de CADA una de las k ciudades a CUALQUIERA de los

La idea

puertos. El destino no está fijo.
Agregar un vértice ficticio S unido a todos los puertos con peso 0. Un camino de S a una

El algoritmo

ciudad tiene el mismo costo que el camino de esa ciudad al puerto más barato.
Un único Dijkstra desde S. dist[c] es el costo mínimo de la ciudad c a algún puerto, y

Justificar el costo

padre[] reconstruye el camino.
O((n + a)·log n) con heap. Correr Dijkstra k veces, una por ciudad, costaría k veces más y

Devolver lo pedido

no hace falta.
Para cada una de las k ciudades, recorrer padre[] hasta S y armar la lista. O(longitud del

3
4
5
6

camino) cada una.
El paso 3 es el que se evalúa. Los otros cinco son mecánica; ese es el que distingue una respuesta buena de una que
corre k veces Dijkstra.

Última hora

Consultas y práctica

60'

El viernes se implementa Dijkstra en el laboratorio y siguen con los ejercicios de implementación del TP1.
1

Ejercicio 14 resuelto en el pizarrón

Los seis pasos de la lámina anterior, con ellos proponiendo.
Diez minutos.

2

TP1: ejercicio 12

3

Completar Floyd: D¹, D² y D³

Implementar Dijkstra y Floyd. Es por donde hay que arrancar.
La consigna de la lámina de Floyd. Mecánico, y se hace mejor
con alguien al lado.

4

TP1: ejercicios 18, 15, 13 y 14

5

Consultas

En ese orden. El 18 es el mismo Dijkstra de hoy con otro grafo.
Cualquier cosa de hoy o de las clases anteriores.

BIBLIOGRAFÍA DE LA CLASE

De dónde sale cada cosa
Tema

Fuente

Clasificación de arcos y componentes conexas

Cormen, 4.ª ed., §20.3 y Teorema 20.10 (3.ª ed.: §22.3, Teorema 22.10)

Conjuntos disjuntos (union-find)

Horowitz, Sahni y Rajasekaran, §2.5, p. 101 · se desarrolla en la clase 5

Puntos de articulación, biconectividad y puentes

Aho, Hopcroft y Ullman, cap. 7 · Cormen, 4.ª ed., problema 20-2

Heap y colas de prioridad

Cormen, 4.ª ed., cap. 6 · Horowitz, Sahni y Rajasekaran, cap. 2

Dijkstra

Cormen, 4.ª ed., §22.3 (3.ª ed.: §24.3)

Floyd-Warshall y clausura transitiva

Cormen, 4.ª ed., §23.2 (3.ª ed.: §25.2) · Warshall, JACM 9(1), 1962

La barrera del ordenamiento

Duan, Mao, Mao, Shu y Yin, arXiv:2504.17033, 2025

Material de la cátedra

Pereira y Martínez, «Exploración de grafos no orientados» · Favre, clases de grafos 2025

Ediciones. Cormen, Leiserson, Rivest y Stein, «Introduction to Algorithms», 4.ª ed., MIT Press, 2022 (entre paréntesis, la numeración de la 3.ª ed.). Aho,
Hopcroft y Ullman, «Estructuras de datos y algoritmos», Addison-Wesley. Horowitz, Sahni y Rajasekaran, «Computer Algorithms / C++», Silicon Press. Aho,
Hopcroft y Ullman, «Estructuras de datos y algoritmos», Addison-Wesley.

