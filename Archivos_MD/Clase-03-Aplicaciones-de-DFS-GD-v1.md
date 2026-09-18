SEMANA 3 · UNIDAD 1 · GRAFOS

Aplicaciones del DFS
sobre grafos dirigidos
Alcance y caminos · orden topológico · componentes fuertemente conexas

Análisis y Diseño de Algoritmos II — 2.º cuatrimestre 2026

Sobre material de la cátedra de Claudia Pereira y Liliana Martínez y de Liliana Favre (clases de grafos 2025). Notación de tiempos según Cormen, 4.ª edición.

RITMO DE LA CLASE

Cómo se reparten las cuatro horas
Bloque

Exposición

Práctica

Actividad de apertura: repaso activo

—

35 min

Consolidación: d, f y los tipos de arco

15 min

—

Alcance y caminos entre dos vértices

25 min

P1 · 20 min

Orden topológico

20 min

P2 · 20 min

Corte

15 min

—

Componentes fuertemente conexas

35 min

P3 · 30 min

Cierre: del traspuesto a la simetría

10 min

—

ACTIVIDAD DE APERTURA

Un grafo, cinco preguntas

35'

Resolver con un compañero. Este grafo es el mismo que vamos a usar toda la clase: cópienlo para tenerlo a mano.

a · Recorrido en profundidad desde a, luego la adyacencia en
orden alfabético. Dibujá el árbol de exploración.
a

b

c

d

e

f

g

h

b · Anotá d[v] al entrar a v y f[v] al salir, con un único contador que
va de 1 a 16. ¿Por qué llega hasta 16?
c · Clasificá todos los arcos que no son del árbol.
d · ¿El grafo tiene ciclos? Un compañero dice que si llegás a un
vértice ya visitado, hay ciclo. ¿Tiene razón?
e · Si arrancás el recorrido desde otro vértice, ¿qué cambia y qué
no cambia?

REPASO CONSOLIDADO

d, f y los tipos de arco: lo que hoy vamos a usar
Arco (u, v)

Relación entre los tiempos de descubrimiento (o preorden) y
de finalización (o postorden)

del árbol o de
avance

d[u] < d[v] < f[v] < f[u]
p[v] = u para árbol
p[v] ≠ u para avance

cruzado

f[v] < d[u] — el de v terminó antes de que empezara el de u

de retroceso

d[v] < d[u] < f[u] < f[v] — el intervalo de u está dentro del de v

Teorema del paréntesis
Para cualquier par (u, v), los intervalos :
[ d[u] , f[u] ]

y

[ d[v] , f[v] ]

están anidados o son disjuntos. Nunca se solapan a medias.
Si están anidados → uno es descendiente del otro.
Si son disjuntos → ninguno lo es.

Teorema. G dirigido tiene un ciclo ⟺ el DFS-Forest produce algún arco
de retroceso ⟺ existe un arco (u, v) con f[u] < f[v].

Ese es el criterio operativo para separar los dos arcos que
llegan a un vértice negro:
-

si el intervalo de v está dentro del de u, es de avance;

-

si está afuera, es cruzado.

Corolario. Si G es acíclico, todo arco va de mayor a menor f. Ordenar por
f decreciente es un orden topológico.

Cormen 4.ª ed., Teorema 20.7 y sección 20.3.

1

Alcanzabilidad y caminos
¿A dónde puedo llegar, y cómo llego?

1 · Alcance y caminos

Alcance desde un conjunto de fuentes: el recolector de basura
Problema. Los objetos vivos de un programa son los
alcanzables desde un conjunto de raíces. Un objeto no
alcanzable es basura y se puede liberar.

La idea es
Un objeto puede ser alcanzable desde varias
raíces: el marcado tiene que ser global, no por
raíz.

Los objetos son vértices; las referencias entre objetos, arcos
dirigidos.

Dos objetos que se referencian entre sí, pero a
los que ya nadie apunta, son basura. Contar

Un DFS desde cada raíz marca los alcanzables. Los que quedan

referencias no los detecta; el recorrido sí.

blancos al terminar son la basura.
Los algoritmos de recolección basados en
Complejidad es O(n + a): se recorre una sola vez y se saltean los
vértices ya marcados.

trazado y alcanzabilidad pueden detectar
ciclos inaccesibles, a diferencia del conteo de
referencias puro.

1 · Alcance y caminos

¿Existe camino de s a v? Y si existe, ¿cuál es?
La idea. El recorrido ya responde si existe ese camino: v es

Un camino, o el camino más corto

alcanzable si el DFS desde s lo descubre. Para devolver el

El DFS devuelve UN camino: el que quedó

camino alcanza con guardar, para cada vértice, desde quién
se lo descubrió.

en su árbol de exploración. No hay ninguna
garantía de que sea el más corto.

padre[v]: un arreglo que se completa al descubrir v. Es el árbol
de exploración guardado en O(n).

El BFS devuelve el camino con MENOS
ARCOS, porque descubre los vértices por

El camino se reconstruye hacia atrás, de v a s, y se da vuelta.

niveles de distancia creciente.

Complejidad es O(longitud del camino).
Mismo arreglo padre[], mismo costo,
distinta respuesta. Cuál se usa lo decide el
Buscar el camino cuesta lo mismo que recorrer: O(n+ a).

enunciado, no la costumbre.

1 · Alcance y caminos

Seguimiento: camino de a hasta f
Con DFS

Con BFS

a

b

c

d

a

b

c

d

e

f

g

h

e

f

g

h

v

b

c

g

f

v

b

c

e

f

padre[v]

a

b

c

g

padre[v]

a

b

b

b

a→b→c→g→f

cuatro arcos

a→b→f

dos arcos

El mismo grafo, el mismo origen, el mismo destino y la misma complejidad O(n + a) en los dos casos.

PRÁCTICA 1

Alcance y caminos
Un servidor mantiene documentos con enlaces dirigidos entre ellos. Hay un conjunto de documentos raíz.

a · Escribí el algoritmo que devuelve los documentos no alcanzables desde ninguna raíz. Complejidad.
b · Ahora hay que devolver, para un documento dado, la secuencia de enlaces que hay que seguir desde una
raíz. ¿Qué agregás al algoritmo de a?
c · El sistema quiere mostrar «a tres clics de distancia». ¿Sirve el mismo recorrido? Justificá.
d · Mostrá un caso donde el DFS devuelva un camino de longitud n−1 y exista uno de longitud 1.

20'

2

Orden topológico
El resultado que ya teníamos calculado sin darnos cuenta.

2 · Orden topológico

Un orden lineal donde todo arco apunta hacia adelante
Definición. Un orden topológico de un grafo dirigido

Prog.

acíclico (DAG) es una ordenación lineal de todos sus vértices
Algor.

tal que, para todo arco (u, v) del grafo, u aparece antes que
v en esa ordenación.

Estr.

M. L.

Teoría

Existe si y sólo si el grafo dirigido es acíclico (o DAG).
Un ciclo obliga a que un vértice esté antes que sí mismo.
ORDEN-TOPOLOGICO (G)
1. Llamar al DFS(G) para calcular los tiempos de finalización de cada vértice
2. Una vez que el vértice ha finalizado, insertarlo en el frente de una lista vinculada.
3. Retornar la lista vinculada de vértices

Un orden válido:
Progr. · Estr. · Algor. · Teoría · M. L.

Complejidad es O(n + a)
No es único: cuando dos vértices no están relacionados por ningún camino, su orden relativo es libre.
Cormen 4.ª ed., sección 20.4.

PRÁCTICA 2

TP1, ejercicio 4

20'

Un proceso industrial tiene tareas con precedencias: cada arco (u, v) significa que u debe completarse antes de que empiece v.
a · Dar un orden de ejecución válido usando el DFS. Mostrá los f que lo

justifican.

b · Encontrá otro orden topológico distinto. ¿Por qué pueden existir
varios? ¿Qué vértices pueden intercambiar su posición?

c · Se agrega una precedencia y el proceso deja de poder ejecutarse.
¿Cómo lo detectás, y cómo mostrás cuáles son las tareas involucradas?

d · Con dos máquinas, las tareas independientes pueden ejecutarse en
paralelo. ¿El orden topológico sigue siendo la respuesta? ¿Qué le falta?

3

Componentes fuertemente conexas
Dos recorridos y un grafo traspuesto.

3 · Componentes fuertemente conexas

La relación «ir y volver» parte el grafo en bloques
Definición. Un componente fuertemente conexo de un grafo

a

b

c

d

e

f

g

h

dirigido es un conjunto maximal de vértices tal que, para todo
par (u, v) , existe un camino de u a v y un camino de v a u .

Cada vértice pertenece a exactamente una componente.

Si contraemos cada componente a un solo vértice obtenemos
el grafo reducido, y el grafo reducido siempre es acíclico: si

cd

tuviera un ciclo, esas componentes serían una sola.

abe
Sobre el grafo reducido, que es un DAG, vuelve a tener
sentido el orden topológico.

h
fg

grafo reducido: siempre es un DAG

3 · Componentes fuertemente conexas

El algoritmo: dos recorridos y el grafo traspuesto
1

DFS sobre G. Calcular f[v] para todos los vértices.
La idea de usar el grafo traspuesto
G y Gᵀ tienen exactamente las mismas componentes:

2

3

Construir Gᵀ. El mismo grafo con todos los arcos invertidos.

invertir todos los arcos no cambia quién alcanza a

O(n + a) , grafo representado con listas de adyacencia.

quién en los dos sentidos.

DFS sobre Gᵀ. Recorrer los vértices en orden decreciente de f.
El vértice de mayor f pertenece a una componente

4

Leer el resultado. Cada árbol del bosque de exploración de Gᵀ
es una componente fuertemente conexa.

Complejidad total O(n + a)
Dos recorridos DFS y una trasposición del grafo.

fuente del grafo reducido. Al invertir los arcos, esa
fuente pasa a ser sumidero.

Y desde un sumidero el recorrido no puede escaparse:
se queda justo dentro de la componente.

Cormen 4.ª ed., sección 20.5.

3 · Componentes fuertemente conexas

Seguimiento sobre el grafo de ocho vértices
Paso 1 · DFS sobre G — ya lo hicieron en la apertura

Paso 3 · DFS sobre Gᵀ en ese orden

1/16

2/15

3/12

4/7

Arranque

Árbol obtenido en Gᵀ Componente

a

b

c

d

a

a, e, b

{a, b, e}

c

c, d

{c, d}

g

g, f

{f, g}

h

h

{h}

e

f

g

h

13/14

9/10

8/11

5/6

Los vértices b, e, d, f no llegan a encabezar ningún árbol:
cuando les toca el turno ya están negros, porque el
recorrido anterior los absorbió.

f decreciente:
a(16) b(15) e(14) c(12) g(11) f(10) d(7) h(6)

El orden de arranque garantiza que ninguna componente se
derrame sobre otra.

3 · COMPONENTES FUERTEMENTE CONEXAS

De los árboles de Gᵀ a las componentes: cómo se recuperan
Cada árbol del bosque de exploración de Gᵀ define una componente: sus vértices son los del árbol, y sus arcos
son los arcos de G que tienen inicio y fin dentro de ese conjunto.
a

b

Numerar los árboles del bosque de Gᵀ → arreglo comp[v]

c

Los arcos que sobran son de cruce: comp[u] ≠ comp[v]

v

a

b

c

d

e

f

g

h

arco de G

en el grafo reducido

comp[v]

1

1

2

2

1

3

3

4

b→c

C1 → C2

b→f e→f

C1 → C3

c→g

C2 → C3

Cada componente: los vértices del árbol y sus arcos internos

C1

{ a, b, e }

a→b, b→e, e→a

d→h

C2 → C4

C2

{ c, d }

c→d, d→c

g→h

C3 → C4

C3

{ f, g }

f→g, g→f

C4

{h}

sin arcos internos

d El grafo reducido, que siempre es un DAG
C2

Recuperar las componentes y armar el grafo reducido es una
pasada más sobre los arcos: no cambia el orden, O(n + a).

C1

C4
C3

PRÁCTICA 3

TP1, ejercicio 11
Sobre el grafo dirigido de la práctica del comienzo del clase, con listas de adyacencia en orden creciente.
a · Ejecutá el paso 1 y listá los vértices por f decreciente.
b · Construí el grafo traspuesto y ejecutá el paso 3. Indicá las componentes fuertemente conexas.
c · Dibujá el grafo reducido y verificá que es acíclico.
d · ¿Cuál es la mínima cantidad de arcos que hay que agregar al grafo original para que todo él sea una única
componente fuertemente conexa? Justificá mirando el grafo reducido, no el grafo original.

30'

PREGUNTAS DE CONTROL

El recorrido de un grafo dirigido, ¿es un árbol o un bosque?
El grafo es…
dirigido, fuertemente conexo
dirigido, no fuertemente conexo
no dirigido, conexo
no dirigido, no conexo

a · ¿puede ser un árbol?

b · ¿se asocia a un bosque?

c · ¿es siempre un único árbol?

PREGUNTAS DE CONTROL

El recorrido de un grafo, ¿es un árbol o un bosque?
El grafo es…

a · ¿puede ser un árbol?

b · ¿se asocia a un bosque?

c · ¿es siempre un único árbol?

dirigido, fuertemente conexo

Sí · desde cualquier vértice se alcanzan todos

Sí · un bosque de un solo árbol

Sí · no depende del arranque

dirigido, no fuertemente conexo

Sí · puede haber un vértice que alcance a todos

Sí · uno o más árboles

No · depende del vértice de
arranque

no dirigido, conexo

Sí

Sí · un bosque de un solo árbol

Sí · no depende del arranque

no dirigido, no conexo

No · nunca

Sí · un árbol por cada componente conexa

No · nunca

El caso que sorprende: la fila 2, columna a

En no dirigidos eso no puede pasar
Alcanzar es simétrico: el árbol que arranca en v cubre

desde a → un único árbol
a

b

c

desde c → dos árboles: { c } y { a, b }

No es fuertemente conexo y, aun así, un solo recorrido puede cubrirlo entero. Lo
que decide no es la conectividad: es desde dónde arrancás.

exactamente la componente de v, ni un vértice más ni uno
menos.
Por eso la cantidad de árboles del bosque es igual a la cantidad
de componentes conexas, siempre, y no depende del arranque.

CIERRE ·

Del grafo traspuesto a la simetría
Todo lo de hoy vivió de una asimetría: que v sea alcanzable desde u no dice nada sobre si u es alcanzable desde v. Por eso hicieron
falta cuatro tipos de arco, tres colores y un grafo traspuesto.

La semana que viene la relación pasa a ser simétrica: G = Gᵀ.
Para la clase que viene

Desaparecen los arcos de avance y los cruzados. Desaparece la distinción entre alcanzar y

Traigan resuelto el ítem d de la práctica 3. Y

ser alcanzado: las componentes se calculan con un solo recorrido, sin trasponer el grafo.

repasen el BFS con el arreglo padre[]: la clase 4
arranca desde ahí para llegar a caminos mínimos

Y los caminos dejan de medirse en cantidad de arcos: las aristas van a pesar, y ahí el BFS
deja de alcanzar.

con pesos.

