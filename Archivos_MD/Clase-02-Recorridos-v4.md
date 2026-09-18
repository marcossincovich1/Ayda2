ANÁLISIS Y DISEÑO DE ALGORITMOS II

Recorridos
DFS, BFS y clasificación de arcos
Unidad 1 · Clase 2 | Teórico-práctico · 4 horas · cinco instancias de práctica

Sobre material de Claudia Pereira y Liliana Martínez.
Seguimientos según Cormen, 4.ª ed. (2022), cap. 20 — cap. 22 en la 3.ª ed. (2009).

CLASE 2

Cómo vamos a trabajar hoy
Bloque

Exposición

Práctica

DFS: idea, colores, tiempos y algoritmo

25 min

P1 · 25 min

El bosque de recorrido y la complejidad

20 min

P2 · 15 min

Clasificación de arcos

25 min

P3 · 20 min

BFS: cola, distancias y camino más corto

25 min

P4 · 20 min

Bipartición: dos colores por niveles

10 min

P5 · 15 min

Franja «¿Qué estrategia y por qué?»

—

10 min

1 · BÚSQUEDA EN PROFUNDIDAD

DFS: la idea
En árboles ya saben recorrer. En grafos aparece un

Cada vértice lleva un color

problema nuevo: un vértice puede alcanzarse por

Blanco no descubierto

varios caminos y puede haber ciclos. Sin marcar lo

Gris en exploración

visitado, el recorrido no termina.

Negro terminado

1
2
3
4

Parte de un origen y explora recursivamente sus
sucesores.
Desde el último vértice descubierto, explora en
profundidad cada arco.
Cuando ya exploró todos los arcos de v, retrocede

Y tres marcas por vértice
d[v]
f[v]
p[v]

cuándo se descubre (pasa a gris)
cuándo termina (pasa a negro)
desde qué vértice se lo descubrió

al vértice desde el que lo descubrió.
Si al terminar quedan vértices sin descubrir, elige
uno nuevo y repite: eso es DFS_Forest.

Los tiempos van de 1 a 2n: cada vértice consume dos.

1 · BÚSQUEDA EN PROFUNDIDAD

El algoritmo
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

Qué hace cada parte
Líneas 1–3
Descubrir: marcar el tiempo de llegada y pintar de gris.
Línea 5
La única diferencia con un recorrido de árbol. Sólo se recursiona
sobre los blancos: ahí está la garantía de terminación y de que cada
vértice se procesa una vez.

10. f[origen] = tiempo

Líneas 8–10
DFS_Forest (G)

Terminar: pintar de negro y marcar el tiempo de salida.

1. for each v: marca[v]=Blanco; p[v]=NIL
2. tiempo = 0
3. for each v ∈ G.Vertices()
4.

if marca[v]==Blanco → DFS(G,v)

DFS_Forest
Llama a DFS desde cada vértice que siga blanco. Ningún
vértice queda sin visitar, sea o no conexo el grafo.

⏱ 25 MINUTOS

PRÁCTICA 1

Corré el DFS a mano
u

v

w

a. Ejecutá DFS_Forest sobre este grafo empezando por u,
tomando los adyacentes en orden alfabético. Anotá d y f de
cada vértice.
b. Marcá con qué color estaba cada vértice al mirar el arco
x→v. ¿Y al mirar z→z?

x

y

z

c. Dibujá el bosque que resulta: qué arcos quedaron dentro.
d. Repetilo empezando por w. ¿Obtuviste lo mismo?

2 · BOSQUE Y COMPLEJIDAD

Lo que el recorrido deja
El subgrafo predecesor

El bosque del recorrido desde u

Gp = (V, Ep)
Ep = { (p[v], v) : p[v] ≠ NIL }

u

w

v

z

Es un bosque: varios árboles DFS. No se construye, se
deduce del vector p. Una estructura gratis que el recorrido
deja como subproducto.

Complejidad temporal
DFS se llama una vez por vértice, y el ciclo de las líneas
4–7 itera |G.Ady(u)| veces. Sumando sobre todos:
TDFS_Forest(n, a) ∈ O( max(n, a) )
con lista de adyacencia.
Con matriz pasa a O(n²): la representación vuelve a
decidir.

y

x

p[·]

u

v

w

x

y

z

–

u

–

y

v

w

PRÁCTICA 2

⏱ 15 MINUTOS

Complejidad y variantes

a. Verificá sobre tu recorrido de la Práctica 1 que cada arco se examinó exactamente una vez.
b. Si el grafo se representa con matriz de adyacencia, ¿cuál sería la complejidad? Justificá contando.
c. Escribí el vector p de tu recorrido y usalo para reconstruir el camino de u a x sin mirar el dibujo.
d. Un grafo de 1000 vértices sin ningún arco: ¿cuánto cuesta DFS_Forest? ¿Por qué la cota es el máximo y no la
suma?

3 · CLASIFICACIÓN DE ARCOS

Los cuatro tipos
De árbol

De retroceso

El arco por el que se descubrió el vértice. Forma el

Va a un antecesor: al mirarlo, el destino está gris. El

bosque.

bucle cuenta acá.

De avance

Cruzado

Va a un descendiente ya terminado, sin ser de árbol.

Une ramas distintas, o árboles distintos del bosque.

Clasificamos el arco (u, v) cuando el DFS lo examina desde u. En ese momento u está gris, siempre ( por eso solo miramos el color de v).

Tipo

Color de v al
examinar el arco

Intervalos, al terminar el recorrido

De árbol

Blanco

d[u] < d[v] < f[v] < f[u], y además p[v] = u

De retroceso

Gris

d[v] < d[u] < f[u] < f[v] — el intervalo de u está dentro del de v

De avance

Negro

igual que el de árbol, pero p[v] ≠ u

Cruzado

Negro

f[v] < d[u] — el de v terminó antes de que empezara el de u

⏱ 20 MINUTOS

PRÁCTICA 3

TP1, ejercicio 1
a. Corré DFS_Forest sobre este grafo desde a y registrá d y f.
b. Clasificá cada arco: de árbol, de retroceso, de avance o
cruzado.
c. ¿Hay algún arco de retroceso? ¿Qué te dice eso sobre el
grafo?
d. Modificá el pseudocódigo del DFS para que imprima cada
arco junto con su tipo. ¿Cambia la complejidad?

4 · BÚSQUEDA EN ANCHURA

BFS: una cola en lugar de la recursión
BFS (G, origen)
1.

Fila F

Los mismos tres colores que DFS

2.

marca[origen] = Gris

3.

F.agregar(origen)

4.

while (not F.esVacia())

Gris al encolar (descubierto, todavía en la cola), Negro
al terminar de mirar sus adyacentes. La semántica del
color no cambia entre los dos recorridos.

5.

u = F.recuperar()

6.

procesar u

7.

for each v ∈ G.Ady(u)

El error clásico
Se marca al encolar, no al desencolar. Si se marcara al
procesar, un mismo vértice podría entrar dos veces a la
cola.

8.

if marca[v] == Blanco

9.

marca[v] = Gris

Para la corrección alcanzan dos

10.

p[v] = u

11.

F.agregar(v)

Lo único que decide el algoritmo es blanco / no blanco.
El negro es contabilidad: sirve para razonar y para el
seguimiento, no cambia el resultado.

12.

marca[u] = Negro

13.

F.eliminar()

Complejidad: la misma que DFS. Cada vértice entra a la cola una vez y cada arco se examina una vez ⟹ O(max(n, a)).

4 · BÚSQUEDA EN ANCHURA

BFS paso a paso: qué hace la cola
Sobre el mismo grafo, desde u, tomando los adyacentes en orden alfabético. Se marca al encolar.
Paso

Se desencola

Se encolan (blancos)

0

—

u

[ u ]

1

u

v, x

[ v, x ]

d(v)=1, d(x)=1

2

v

y

[ x, y ]

d(y)=2

3

x

ninguno: v ya marcado

[ y ]

—

4

y

ninguno: x ya marcado

[ ]

—

5

—

w y z siguen blancos

—

no alcanzables desde u

Paso 3: v ya estaba marcado al encolarse en el paso 1.
Si se marcara al desencolar, entraría dos veces.

Cola al terminar

Distancias fijadas
d(u)=0

Comparar con DFS: allá x se descubrió a través de y,
con distancia 3 en el árbol. Acá está a distancia 1.

PRÁCTICA 4

⏱ 25 MINUTOS

BFS y comparación

a. Corré BFS desde a sobre el grafo del ejercicio 1 y anotá la distancia de cada vértice.
b. Compará el árbol BFS con el bosque DFS que obtuviste. ¿Coinciden en algún arco?
c. Volvé a la Práctica 2 de la clase 1: ¿existe camino de d a b? Justificá ahora con un algoritmo, no
enumerando caminos.

5 · UNA APLICACIÓN INMEDIATA DE BFS

Grafos bipartitos
Un grafo no dirigido es bipartido si todos sus vértices se pueden dividir en dos conjuntos disjuntos tal que todas
las aristas relacionan vértices de conjuntos distintos.
¿Se pueden repartir los vértices en dos grupos de modo que todo arco vaya de un grupo al otro?
Probá correr BFS y pintar cada vértice según la
paridad de su nivel: nivel par un color, nivel impar el
otro.
El grafo no es bipartito si al examinar el arco (u,v), si
nivel [u] y nivel [v] tienen la misma paridad es un
arco que cierra un ciclo de longitud impar.
El grafo es bipartito si y solo si no tiene ciclos de
longitud impar.
Cuesta lo mismo que el BFS: O(max(n, a)). Decidir si dos colores alcanzan es un problema fácil: no hay que probar todas las
asignaciones posibles, el recorrido la construye. Con tres colores no se conoce ningún algoritmo polinomial: ese salto es el
tema de la Unidad 2.

⏱ 15 MINUTOS

PRÁCTICA 5

Dos turnos de laboratorio
La cátedra tiene que repartir a ocho alumnos en dos turnos. Dos alumnos que comparten proyecto no pueden ir al mismo
turno. Comparten proyecto: A-B, A-C, B-D, C-D, D-E, E-F, F-G, G-E, G-H.
a.

Modelá la situación: ¿qué son los vértices y qué son los arcos? ¿Dirigido o no dirigido?

b.

Corré BFS desde A pintando por paridad de nivel. ¿Alcanza con dos turnos?

c.

Si no alcanza, señalá el ciclo de longitud impar que lo impide. Si alcanza, escribí los dos turnos.

d.

Sacá el conflicto F-G y repetí. ¿Cambia la respuesta? ¿Qué te dice eso sobre la propiedad?

Dibujá el grafo antes de correr nada: el modelado es parte del ejercicio, no un paso previo.

FRANJA SEMANAL · PRIMERA EDICIÓN

¿Qué estrategia y por qué?
Una línea por caso. No hay que resolver nada: hay que elegir y justificar.
El vuelo con menos escalas entre dos ciudades.
¿La red de dependencias entre módulos tiene un ciclo?
¿Se pueden repartir los turnos en dos grupos?

Armen la siguiente tabla
Dos columnas, DFS y BFS: qué estructura usa cada uno, qué registra, qué problema resuelve mejor.

⏱ 10 MINUTOS

SÍNTESIS

Lo que hay que llevarse
La marca es lo que hace posible el recorrido
sin ella no termina; con ella, cada vértice y cada arco se procesan una sola vez.
DFS deja dos tiempos por vértice
y con d y f se clasifica cada arco y se decide si el grafo tiene ciclos.
BFS da el camino con menos arcos
el árbol depende del orden de los adyacentes, las distancias no.
Y con los niveles del BFS, la bipartición
decidir si dos colores alcanzan es fácil; con tres, cambia todo.
Ambos cuestan O(max(n, a))
con lista de adyacencia. Con matriz, O(n²): la representación vuelve a decidir.
Próxima clase: aplicaciones de DFS — aciclicidad, orden topológico, componentes conexas y puntos de articulación.

