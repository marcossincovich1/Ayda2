ANÁLISIS Y DISEÑO DE ALGORITMOS II

Grafos
Definiciones, modelado e implementación

Unidad 1 · Clase 1 | Teórico-práctico · 4 horas · cinco instancias de práctica
Sobre material de Claudia Pereira y Liliana Martínez.

CLASE 1

Cómo vamos a trabajar hoy
Bloque

Exposición

Práctica

Königsberg, relación binaria y clasificación

20 min

P1 · 10 min

Grafos dirigidos: camino, ciclo y grados

25 min

P2 · 20 min

Grafos no dirigidos y conexidad

20 min

P3 · 15 min

Modelar problemas con grafos

15 min

P4 · 15 min

Implementación: matriz y lista

25 min

P5 · 20 min

Exposición y práctica. Lo que se explica se usa enseguida. Traigan lápiz y papel: hoy se dibuja mucho.

1 · DEFINICIONES

Königsberg, 1736
La ciudad está atravesada por el río Pregel, que se
bifurca formando una isla y divide el terreno en cuatro
regiones unidas por siete puentes.

¿Se puede hacer un paseo que cruce cada puente
exactamente una vez y vuelva al punto de partida?

Mapa de Königsberg en la época de Leonhard Euler, que muestra dónde se encontraban los siete puentes (en verde claro) y las ramas del río (en celeste).

1 · DEFINICIONES

Königsberg, 1736
¿Se puede hacer un paseo que cruce cada puente
exactamente una vez y vuelva al punto de partida?

C

A

D

La abstracción de Euler
Descartar todo salvo la relación: las cuatro regiones son
vértices, los siete puentes son aristas. La forma de la ciudad,
la longitud de los puentes y el ancho del río no importan.

B

Queda un multigrafo: hay más de una arista entre el mismo
par de vértices.

4 regiones · 7 puentes · todos los grados impares

1 · DEFINICIONES

Königsberg, resuelto
Primer teorema de la teoría de grafos
Cada arista aporta 1 al grado de cada extremo, luego la suma de los grados es

gr 3

C

gr 5

A

gr 3

B

2·|E|. Consecuencia inmediata: la cantidad de vértices de grado impar es
siempre par.

Teorema (Euler, 1736)

Un multigrafo conexo admite un circuito que usa cada arista exactamente
una vez si y sólo si todo vértice tiene grado par.

D

gr 3

Idea: cada vez que el paseo entra a una región tiene que salir, y consume dos aristas
distintas. Si las usa todas, cada grado queda apareado.

Veredicto
• Königsberg tiene grados 5, 3, 3, 3: cuatro impares. El paseo no existe.
• Tampoco existe uno abierto, que no vuelva al inicio: eso exigiría exactamente 0
ó 2 vértices de grado impar.

4 regiones · 7 puentes · suma de grados = 14 = 2 × 7

1 · DEFINICIONES

Un grafo es una relación binaria
Cómo se clasifican

Relación binaria sobre un dominio V
Un conjunto de pares que es subconjunto de V × V.

Dirigidos
La relación tiene sentido. Sus elementos son arcos.

Dos caras del mismo objeto: un modelo matemático (conjunto de
pares) y una visualización (puntos unidos por líneas o flechas).

No dirigidos
La relación es simétrica. Sus elementos son aristas.

V = {1,2,3}

E = { (1,2), (1,3), (2,2) }

Rotulados
Cada arco o arista lleva un valor asociado.
1

2

(2,2) es un bucle

Multigrafos
Más de un arista entre el mismo par de vértices.
3

G = (V, E) donde V vértices, no vacío

ψ: E → V×V

PRÁCTICA 1

Modelá y escribí
a. Un grupo de ciudades conectadas por rutas directas. Dibujá el grafo y escribí V y E como conjuntos.

b. ¿Es dirigido o no dirigido? ¿Por qué?

c. Ahora modelá: una red social donde cada usuario puede seguir a otros. ¿Cambia la respuesta anterior?

d. Un mismo enunciado, ¿admite más de un modelado? Buscá un ejemplo.

⏱ 10 MINUTOS

2 · GRAFOS DIRIGIDOS

Vértices, arcos y caminos
G = (V, E)
V vértices, no vacío E relación binaria sobre V: los arcos

0

1

2

3

Camino secuencia (v₁,…,vk) con un arco vᵢ → vᵢ₊₁ para todo
i. Es simple si todos sus vértices son distintos. Su longitud
es el número de arcos: k − 1.

4

Ciclo camino de longitud 1 o más que empieza y termina en
el mismo vértice. La longitud del ciclo es la longitud del
camino. Es simple si no repite vértices, salvo el primero y el
último. Un bucle es un ciclo simple de longitud 1.

(0,1,3) camino simple, longitud 2
(0,2,0) ciclo simple, longitud 2
(0,2,1,3,2,0) ciclo no simple de longitud 5

2 · GRAFOS DIRIGIDOS

Grados
0

1

Grado de incidencia
arcos entrantes al vértice. El del grafo es
el máximo de los de sus vértices.

2

3

Grado de vecindad (o saliencia)
4

El grado decide la implementación:
con grado bajo conviene lista de adyacencia, con grado alto matriz.
Luego profundizaremos este concepto.

arcos salientes del vértice. También se
toma el máximo para el grafo.

⏱ 20 MINUTOS

PRÁCTICA 2

Sobre este grafo
b

a. Escribí V y E. Cuántos arcos tiene?
a
d

b. Listá todos los caminos simples de a a d, con su longitud.
c. Predecesores y sucesores de c.
d. Cuántos ciclos simples tiene? Listalos.

c

e. ¿Existe un camino de d a b? Justificá.

e

3 · GRAFOS NO DIRIGIDOS

Aristas, y un ciclo que cambia
Arista

Atención: el ciclo se define distinto

Un conjunto {u,v}: u y v están conectados en las dos
direcciones y son adyacentes. Un solo grado por

El camino se define igual que en dirigidos. El ciclo no: sólo tiene

vértice: la cantidad de adyacentes.

sentido el ciclo simple, un camino de longitud 3 o más que
empieza y termina en el mismo vértice sin repetir otros.

Lo que NO es un ciclo acá

Camino en un grafo no dirigido
El camino se define igual que en dirigidos.

Grado. El grado de un vértice v en un grafo no dirigido es el
número de adyacentes a v.

(u, v, u)

ir y volver por la misma arista

(v₁,…,v_k,…,v₁)

recorrer un camino y desandarlo

Si no se hace esta distinción, cuentan ciclos de longitud 2 y el test de aciclicidad
les da mal.

3 · GRAFOS NO DIRIGIDOS

Subgrafo, conexidad y componentes
Subgrafo inducido de G=(V,E) es

Grafo conexo

Componente conexa

arcos/aristas de G cuyos dos extremos

Existe un camino entre cada par

Subgrafo inducido conexo

están en V′. Los vértices determinan los

de vértices.

maximal. La división es única.

G’ = (V′,E′) con V′ ⊆ V, y E′ = TODOS los

arcos/aristas: no se eligen aparte.

Un grafo no conexo

1

4

2

5

3

1

2

4

5

3

6

6
se puede dividir de una única forma en un conjunto de componentes conexas

Definición hoy, algoritmo en la clase 3: calcular las componentes es una aplicación directa de DFS.

PRÁCTICA 3

⏱ 15 MINUTOS

Contá y compará

a. Si un grafo dirigido tiene 10 vértices, ¿cuál es el número máximo y mínimo de arcos que puede tener?
b. ¿Y si fuera no dirigido? Compará los dos resultados.
c. Dibujá un grafo no dirigido de 7 vértices con exactamente tres componentes conexas.
d. ¿Cuántos ciclos simples tiene el grafo que dibujaste? ¿Podrías dibujar uno de 7 vértices sin ningún ciclo?

4 · MODELAR CON GRAFOS

El mismo esquema, siete dominios
Modelar es decidir dos cosas: qué es un vértice y qué es un arco. Todo lo demás se descarta.
Aplicación
Mapas
Contenido web
Circuitos eléctricos
Planificación
Redes de computadoras
Software
Red social

Objeto → vértice

Conexión → arco o arista

4 · MODELAR CON GRAFOS

El mismo esquema, siete dominios
Modelar es decidir dos cosas: qué es un vértice y qué es un arco. Todo lo demás se descarta.
Aplicación

Objeto → vértice

Conexión → arco o arista

Mapas

Intersección o ciudad

Rutas

Contenido web

Página

Link

Circuitos eléctricos

Dispositivo

Cables

Planificación

Tarea

Restricciones de precedencia

Redes de computadoras

Sitio

Conexiones

Software

Método

Llamada

Red social

Persona

Amistad o seguimiento

Cuál es dirigido y cuál no lo es, es la primera pregunta del modelado. Amistad es simétrica; seguimiento no.

PRÁCTICA 4

⏱ 15 MINUTOS

Modelá estos tres enunciados
a. Una red social donde cada usuario sigue a otros. Se quiere saber si existe una cadena de seguimientos entre dos
personas.
b. Un conjunto de materias con sus correlativas. Se quiere saber en qué orden se pueden cursar.

c. Un tablero de ajedrez y un caballo. Se quiere saber en cuántos movimientos llega de una casilla a otra.

d. Para cada uno: ¿vértices? ¿arcos o aristas? ¿dirigido, rotulado, acíclico?

5 · IMPLEMENTACIÓN

Matriz y lista de adyacencia
Matriz de adyacencia

Lista de adyacencia

Una matriz n × n donde la posición (u,v) indica si existe el arco.
0

1

2

3

0

0

1

1

0

1

0

0

0

1

2

1

1

0

0

3

0

0

1

0

Un arreglo de n posiciones; cada una guarda la lista de sucesores
de ese vértice.
0

→ 1 → 2

1

→ 3

2

→ 0 → 1

3

→ 2

Las dos representan el mismo grafo. Si es rotulado, la matriz guarda el rótulo y la lista lo guarda junto al vecino.

5 · IMPLEMENTACIÓN

Espacio y costo de cada operación
Matriz de adyacencia
Espacio
Buscar el arco (u,v)
Hallar sucesores de u
Hallar predecesores de v
Conviene para

Lista de adyacencia

5 · IMPLEMENTACIÓN

Espacio y costo de cada operación
Matriz de adyacencia

Lista de adyacencia

Espacio

n × n, sin importar cuántos arcos haya

n vértices más a arcos; 2a si no es dirigido

Buscar el arco (u,v)

O(1)

O(sucesores de u); en promedio O(a/n)

Hallar sucesores de u

O(n) — recorrer la fila

O(sucesores de u); en promedio O(a/n)

Hallar predecesores de v

O(n) — recorrer la columna

O(a) — recorrer todas las listas

Conviene para

Grafos densos: a tiende a n²

Grafos ralos: a es del orden de n

Sobre O(a/n): si a ≈ n² ⟹ O(n); si a es del orden de n ⟹ O(1).

La fila incómoda: hallar predecesores con listas es caro. Si hace falta, se
guarda el grafo traspuesto.

PRÁCTICA 5

⏱ 20 MINUTOS

Implementá y contá

a. Representá el grafo de la Práctica 2 con lista de adyacencia y con matriz de adyacencia.
b. Repetilo suponiendo que fuera no dirigido. ¿Qué cambia en cada representación?
c. Contá cuántas operaciones cuesta hallar los predecesores de un vértice en cada una. Verificá que coincida con la
tabla.
d. Para un grafo de 1000 vértices y 3000 aristas, estimá el espacio de cada representación. ¿Cuál elegirías?

SÍNTESIS

Lo que hay que llevarse
Un grafo es una relación binaria
y se escribe como conjunto de pares o se dibuja: son la misma cosa.

El ciclo se define distinto según el tipo
en no dirigidos hace falta longitud 3 o más.

Modelar es elegir vértice y arco
y esa elección no es única: distintas elecciones dan distintos algoritmos.

La representación cambia la complejidad
matriz para densos, lista para ralos, y los predecesores son el caso incómodo.

Próxima clase: recorridos DFS y BFS — cómo responder «¿existe un camino?» sin mirar todos los caminos.

