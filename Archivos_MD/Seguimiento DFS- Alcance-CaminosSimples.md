Búsqueda de caminos simples
en grafos
(tips para resolver los ejercicios del 6 al 9 del práctico de grafos)

Liliana Martinez - Claudia Pereira

Alcance: vértices alcanzables desde un vértice dado
¿qué vértices son alcanzables desde 1?

Liliana Martinez - Claudia Pereira

Alcance: vértices alcanzables desde un vértice dado

✓

¿qué vértices son alcanzables desde 1?
1

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}
Liliana Martinez - Claudia Pereira

Padre

Null

Null

Null

Null

Null

Null

Null

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

¿qué vértices son alcanzables desde 1?
1

2

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}
Liliana Martinez - Claudia Pereira

Padre

Null

1

Null

Null

Null

Null

Null

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿qué vértices son alcanzables desde 1?
1

2
3
DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}
Padre
Liliana Martinez - Claudia Pereira

Null

1

2

Null

Null

Null

Null

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿qué vértices son alcanzables desde 1?

✓

1

2
3
DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

Padre
Liliana Martinez - Claudia Pereira

Null

1

2

Null

Null

3

Null

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿qué vértices son alcanzables desde 1?

✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

7

Padre
Liliana Martinez - Claudia Pereira

Null

1

2

Null

Null

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿qué vértices son alcanzables desde 1?

✓
✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

7

Padre
Liliana Martinez - Claudia Pereira

5

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿qué vértices son alcanzables desde 1?

✓
✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

Árbol de exploración del recorrido
en profundidad a partir del vértice 1

7

Padre
Liliana Martinez - Claudia Pereira

5

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿existe un camino entre el vértice 1 y el vértice 4?

✓
✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

7

Padre
Liliana Martinez - Claudia Pereira

5

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿existe un camino entre el vértice 1 y el vértice 4?

✓
✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

No, porque 4 no está dentro de los
vértices alcanzables en el recorrido
en profundidad a partir del vértice 1

6

7

Padre
Liliana Martinez - Claudia Pereira

5

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿existe un camino entre el vértice 1 y el vértice 6?

✓
✓

1

✓

2
3

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

6

Sí, porque 6 está dentro de los
vértices alcanzables en el recorrido
en profundidad a partir del vértice 1

7

Padre
Liliana Martinez - Claudia Pereira

5

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

Alcance: vértices alcanzables desde un vértice dado

✓

✓

✓

¿existe un camino entre el vértice 1 y el vértice 6?

✓
✓

1

✓

2

DFS (G, origen) {
Marca[origen]= VISITADO;
for cada vértice v ϵ G.Adyacentes[origen]
if Marca[v] = NO-VISITADO
{
Padre[v]= origen;
DFS (G,v);
}
}

3

5

6

Recupero el camino recorriendo
los predecesores del vértice
destino hasta llegar a la raíz del
árbol
6→3→2→ 1

7

Padre
Liliana Martinez - Claudia Pereira

¿Cuál es el camino entre 1 y 6?

Null

1

2

Null

2

3

6

1

2

3

4

5

6

7

