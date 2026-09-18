Análisis y Diseño de Algoritmos II

“Caminos más cortos”
Claudia Pereira – Liliana Martinez

Camino más corto
Dado un grafo rotulado G ( V , A ) , con una función de costo c : A  R
Costo del camino p = <v0 , v1 , … , vk > (suma de los costos de los arcos en el camino)
𝑪 𝒑

=

𝑘
𝑖= 1 𝑐 ( 𝑣𝑖 − 1 , 𝑣𝑖 )

Costo del camino más corto entre u a v :

min { C ( p ) : u

p

v } si  camino entre u y v

D(u,v) =



si ∄ camino entre u y v

Camino más corto
Problema: Dado un grafo, hallar el camino más corto:
 Desde un origen dado a todos los restantes vértices del grafo
 Desde todos los vértices del grafo a un destino único

 Entre un par de vértices
 Entre todos los pares de vértices

Caminos Camino más corto
Problema: Dado un grafo, hallar el camino más corto:
 Desde un origen dado a todos los restantes vértices del grafo
 Desde todos los vértices del grafo a un destino único

 Entre un par de vértices
 Entre todos los pares de vértices

Camino más corto desde un origen
Problema:
Dado un grafo rotulado G(V,A), encontrar el “camino más corto” entre
un vértice origen y todos los restantes vértices de V.
Consideraciones:

 El costo del camino: suma de los costos de los arcos del camino
 Cada arco(u,v)/arista(u,v) posee un costo no negativo

Camino más corto desde un origen
Consideraciones:
Cada arista {u,v} /arco(u,v) posee un
costo no negativo ¿Porqué?

Supongamos que deseamos encontrar
el camino más corto desde el vértice 1
a todos los restantes vértices del grafo

Camino más corto desde un origen
Consideraciones:
Cada arista {u,v} /arco(u,v) posee un
costo no negativo ¿Porqué?

Analicemos qué pasa si en el camino:


hay un arco con costo negativo



existe un ciclo con costo positivo



existe un ciclo con costo negativo

Camino más corto desde un origen
Consideraciones:
Cada arista {u,v} /arco(u,v) posee un
costo no negativo ¿Porqué?

Analicemos qué pasa si en el camino:


hay un arco con costo negativo



existe un ciclo con costo positivo



existe un ciclo con costo negativo

Camino más corto desde un origen
Consideraciones:
Cada arista {u,v} /arco(u,v) posee un
costo no negativo ¿Porqué?

Analicemos qué pasa si en el camino:


hay un arco con costo negativo



existe un ciclo con costo positivo



existe un ciclo con costo negativo

Camino más corto desde un origen
Consideraciones:
Cada arista {u,v} /arco(u,v) posee un
costo no negativo ¿Porqué?

Analicemos qué pasa si en el camino:


hay un arco con costo negativo



existe un ciclo con costo positivo



existe un ciclo con costo negativo

Camino más corto desde un origen
Representando los caminos más cortos
Ejemplo: caminos más cortos desde el vértice origen 1 a todos los restantes vértices

G=

P (Subgrafo de G)

Camino más corto desde un origen
Representando los caminos más cortos*
El “árbol de caminos más cortos” con raíz en el origen s, es un subgrafo dirigido G’ = ( V’ , A’ ) :

 G’ forma un árbol cuya raíz es el vértice s
 V’ es el conjunto de vértices alcanzables desde s
  v  V’ , el único camino simple del s a v’ en G’
es un camino más corto de s a v en G
 el costo del camino mínimo desde el origen a v

D
1 2 3 4 …

 el predecesor de v en el camino mínimo desde el origen a v.

P
1 2 3 4 …

*Representación similar a la usada en BFS: excepto que el BFS almacena en D la distancia medida en cantidad de arcos

Camino más corto desde un origen
Representando los caminos más cortos
D 0 1 2  9 6 5 
1 2 3 4 5 6 7 8
P

- 1 1 - 6 2 3 1 2 3 4 5 6 7 8

P

- 1 1 - 2 2 3 1 2 3 4 5 6 7 8

Los caminos más cortos no son únicos, por lo tanto, tampoco los árboles

Camino más corto desde un origen

Algoritmo de Dijkstra*
* Resuelve el problema para un grafo dirigido G= ( V , A ) rotulado con costos no negativos
Asume que para todo arco (u,v)  A , c (u,v)  0

Algoritmo de Dijkstra
Paso 1: inicialización

Dado G= (V,E) y sea 1 el vértice origen
S= {1} // contiene el vértice origen
Para v = 1: D[v] = 0
D

0
1

2

3

4

5

2

3

4

5

P[v] = -1

P

-1
1

D [v] : costo del camino mínimo desde el origen a v
P [v] : predecesor de v en el camino mínimo desde el origen a v

Algoritmo de Dijkstra
Paso 1: inicialización

Dado G= (V,E) y sea 1 el vértice origen
S= {1} // contiene el vértice origen
Para cada v  1: D[v]= G.Costo (1,v)
D

10



30 100

2

3

4

5

Para cada v  1: P[v]= 1

P

1

1

1

1

2

3

4

5

D [v] : costo del camino mínimo desde el origen a v
P [v] : predecesor de v en el camino mínimo desde el origen a v

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,

S= {1}
D

P

10



30 100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,

w= 2

S= {1}
D

P

10



30 100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S

w= 2

S= {1, 2}

D

P

10



30 100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

w= 2

S= {1, 2}

D

P

10



30 100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2}

w= 2

D[3] = min(D[3], D[2]+C[2, 3])= min(, 10+50)=60
D



P

10



30 100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2}

w= 2

D[3] = min(D[3], D[2]+C[2, 3])= min(, 10+50)=60
Actualizamos la D[3]

D


10

60

30 100

2

3

4

5

El predecesor de 3 ahora es 2

P

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2}

w= 2

D[4] = min(D[4], D[2]+C[2, 4])=min(30, 10 + )=30
D[4] sigue siendo la misma

D


P

10

60

30 100

2

3

4

5

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 2: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2}

w= 2

D[5] = min(D[5], D[2]+C[2, 5])=min(100, 10 + )=100
D[5] sigue siendo la misma



D

P

10

60

30 100

2

3

4

5

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,

w= 4

S= {1, 2}

D

P

10

60

30 100

2

3

4

5

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,

w= 4

S= {1, 2, 4}

D

P

10

60

30 100

2

3

4

5

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4}

w= 4

D[3] = min(D[3], D[4]+C[4, 3])= min(60, 30+20)=50
D

P

10

60

30 100

2

3

4

5

1

2

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4}

w= 4

D[3] = min(D[3], D[4]+C[4, 3])= min(60, 30+20)=50
Actualizamos la D[3]

D

10

50

30 100

2

3

4

5

El predecesor de 3 ahora es 4

P

1

4

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4}

w= 4

D[5] = min(D[5], D[4]+C[4, 5])= min(100, 30+60)=90
D

P

10

50

30 100

2

3

4

5

1

4

1

1

2

3

4

5

Algoritmo de Dijkstra
Paso 3: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4}

w= 4

D[5] = min(D[5], D[4]+C[4, 5])= min(100, 30+60)=90
Actualizamos la D[5]

D

10

50

30

90

2

3

4

5

El predecesor de 5 ahora es 4

P

1

4

1

4

2

3

4

5

Algoritmo de Dijkstra
Paso 4: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,

w= 3

S= {1, 2, 4}

D

P

10

50

30

90

2

3

4

5

1

4

1

4

2

3

4

5

Algoritmo de Dijkstra
Paso 4: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4, 3}

w= 3

D[5] = min(D[5], D[3]+C[3, 5])= min(90, 50+10)=60
D

P

10

50

30

90

2

3

4

5

1

4

1

4

2

3

4

5

Algoritmo de Dijkstra
Paso 4: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,
 v ∈ V-S: D[v] = min ( D[v], D[w] + C[w, v] )

S= {1, 2, 4, 3}

w= 3

D[5] = min(D[5], D[3]+C[3, 5])= min(90, 50+10)=60
Actualizamos la D[5]

D

10

50

30

60

2

3

4

5

El predecesor de 5 ahora es 3

P

1

4

1

3

2

3

4

5

Algoritmo de Dijkstra
Paso 5: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,

w= 5

S= {1, 2, 4, 3}

D

P

10

50

30

60

2

3

4

5

1

4

1

3

2

3

4

5

Algoritmo de Dijkstra
Paso 5: Elegir un vértice w ∈ V - S tal que D[w] sea mínimo,
agregar w al conjunto solución S,

w= 5

S= {1, 2, 4, 3, 5}

D

P

10

50

30

60

2

3

4

5

1

4

1

3

2

3

4

5

Algoritmo de Dijkstra: pseudo-código
Dijkstra ( G( V , A) , origen ) {
// paso 1: Inicializa conjunto solución S
S = { origen };
// Inicializa distancias y predecesor
distancia [origen]= 0; predecesor[origen]= -1;

 v : v Є V

y

v ≠ origen {

distancia [v] = costo (origen, v);
predecesor[v] = origen;
}

Algoritmo de Dijkstra: pseudo-código
Mientras (V–S) ≠ Ø
// pasos 2-n: Calcula n-1 caminos mínimos
{
// Elegir un vértice w ∈ V - S tal que D[w] sea mínimo
w = ExtraerMin(V - S) : distancia[w] sea mínima
S = S U {w}; // agrega w al conjunto solución S,

 v : v Є ady (w) y v Є (V–S) //D[v]= min(D[v],D[w]+C[w,v])
Si

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

Algoritmo de Dijkstra: complejidad
Dijkstra ( G( V , A) , origen ) {

// n = |V|

// paso 1: Inicializa conjunto solución S

S = { origen };
//

Inicializa distancias y predecesor

distancia [origen]= 0; predecesor[origen]= -1;
 v : v Є V

y

v ≠ origen {

distancia [v] = costo (origen,v);

O(n)

predecesor[v] = origen;
}

Grafo implementado con matriz de adyacencia: costo (v,w) Є O(1)

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima
//recorre el arreglo “distancia” => O(n)
S = S U {w}; // agrega w al conjunto solución S,
 v : v Є ady (w) y v Є (V–S)
O(n2)
// implica recorrer toda la fila de w
Si

 O(n)

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

O(1)

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima O(n)
//recorre el arreglo “distancia”=> total de comparaciones  O(n2)
S = S U {w}; // agregar w al conjunto solución S,

O(1)

 v : v Є ady (w) y v Є (V–S)
//
Si

implica recorrer toda la fila de w

 O(n)

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima
//recorre el arreglo “distancia” => O(n)
S = S U {w};

// agregar w al conjunto solución S,

O(1)

 v : v Є ady (w) y v Є (V–S)

Si

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

O(1)

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima
S = S U {w};
 v : v Є ady (w) y v Є (V–S)
// Grafo en matriz de ady => ady(w)  O(n) (recorre toda la fila)
// el total de iteraciones Є O (n2)
Si

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

O(1)

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima
S = S U {w};
 v : v Є ady (w) y v Є (V–S)
// Grafo en lista de ady  # iteraciones= |ady(w)|
// el total de iteraciones Є O (a) (a = nro de arcos)
Si

distancia [v] > distancia [w] + costo (w,v)*
{ distancia [v]= distancia [w] + costo (w,v);
O(1)
predecesor[v] = w;
}
}
* ady(w) devuelve la lista de arcos => costo (w,v) Є O (1)
} // end Dijkstra

Algoritmo de Dijkstra: complejidad
Mientras (V–S) ≠ Ø //Calcula n-1 caminos mínimos: itera n-1 veces
{
w = ExtraerMin (V - S) : distancia[w] sea mínima
//recorre el arreglo “distancia” => O(n)
S = S U {w};

// agrega w al conjunto solución S,

O(1)

 v : v Є ady (w) y v Є (V–S)
// Grafo en matriz de ady => ady(w)  O(n)
// Grafo en lista de ady => |ady(w)|
Si

distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
}

}
} // end Dijkstra

O(n2)

O(1)

Algoritmo de Dijkstra: complejidad
Dijkstra ( G( V , A) , origen ) {

Sea n= |V|

S = { origen }; distancia [origen]= 0; predecesor[origen]= -1;
 v : v Є V

y

v ≠ origen {

distancia [v]= costo (origen,v);

predecesor[v] = origen;}

O(n)

}
Mientras (V–S) ≠ Ø

// paso 2-n: Calcula n-1 caminos mínimos

{ w = ExtraerMin(V - S) : distancia[w] sea mínima

//recorre el arreglo o(n)

S = S U {w};
 v : v Є ady (w) y v Є (V–S)
Si

distancia [v] > distancia [w] + costo (w,v)

{

distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;

}
}
} // end Dijkstra

O(n2)

Algoritmo de Dijkstra: complejidad
Si el grafo es ralo podemos mejorar el algoritmo:
La operación ExtraerMin es costosa
Recorre el arreglo distancia O(n)
¿cómo reducir el costo de la operación ExtraerMin?
Utilización de un HEAP

Algoritmo de Dijkstra: complejidad
Solución: heap mínimo
Heap: registrar los pares:
(distancia[v], v)

D

P

10



30

100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra: complejidad
Solución: heap mínimo
Heap: registrar los pares:
(distancia[v], v)

Heap *

10

2

100

1

5

30

2

4
3

∞

3
4

Representación de arreglo, donde para cada nodo i, 1  i <= n
• padre (i)

está en  i/2 

si i ≠ 1

• hijo izq (i) está en 2*i

si 2*i  n

• hijo der (i) está en 2*i+1

si 2*i+1  n

D

P

10



30

100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra: complejidad
Solución: heap mínimo

Heap *

10

2

100

1

5
2

30

4
3

∞

3

D

4
P

* Costo de extraerMin es O(log n)

10



30

100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra: complejidad
Solución: heap mínimo

Heap *

10

2

100

1
Puntero al Heap **

5

30

2
1

4

∞

3
1
2

4
3

3

D

4
3
4

2
5

P

10



30

100

2

3

4

5

1

1

1

1

2

3

4

5

* Costo de extraerMin es O(log n)
** Almacena la posición de cada vértice en el heap  costo de actualizar la distancia al origen es O(1)

Algoritmo de Dijkstra: complejidad
Elegir un vértice w ∈ V - S
tal que D[w] sea mínimo =>

Extraer del heap

Heap *

10

2

100

1
Puntero al Heap **

5

30

2
1

4

∞

3
1
2

4
3

3

D

4
3
4

2
5

P

10



30

100

2

3

4

5

1

1

1

1

2

3

4

5

Algoritmo de Dijkstra
vértice 2
Extraer del heap

Algoritmo de Dijkstra
vértice 2
Extraer del heap

Algoritmo de Dijkstra
vértice 2
Extraer del heap

O ( log(n) )

Algoritmo de Dijkstra
• Extraer del heap  w= vértice 2

• S= S  { 2 }
• Actualizar las distancias D
D[3]= min (D[3], D[2] + costo (2,3)= 60

P[3] = 2
• Modificar el Heap
modifica y reorganiza (si es necesario)
Heap [Puntero al Heap [3]] = D[3]

Algoritmo de Dijkstra: pseudo-código
Dijkstra ( G( V , A) , origen ) {
// paso 1: Inicializa conjunto solución S O(1)
S = { origen };
//
Inicializa distancias y predecesor O(n)
distancia[origen]=0; predecesor[origen]= -1;
 v : v Є V y v ≠ origen {
distancia [v] = costo (origen,v);
predecesor[v] = origen;
}
Heap h;
h.construir(distancia); // construye el heap con todos los pares
//
( distancia (v),v)  v : v ≠ origen
// O(n log n) si agrega de a un par por vez
// O(n) si lo construye a partir de todos los pares

Algoritmo de Dijkstra: pseudo-código
Mientras (V–S) ≠ Ø
{
w = h.elemento();
h.eliminar();

// pasos 2-n: Calcula n-1 caminos mínimos
// extraer mínimo O(log n)

S = S U {w};
// agrega w al conjunto solución S
 v : v Є ady (w) y v Є (V–S)
//D[v]= min(D[v],D[w]+C[w,v])
Si distancia [v] > distancia [w] + costo (w,v)
{ distancia [v]= distancia [w] + costo (w,v);
predecesor[v] = w;
h.modificar (distancia[v], v) // O(log n)
}
}
} // end Dijkstra

Algoritmo de Dijkstra: complejidad
Grafo en lista de adyacencia y utilizando un heap mínimo:
Dado G = (V,A), n= |V| , a= |A|
Calcula n-1 caminos mínimos
inicialización

h.eliminar(w)

actualizar los adyacentes de w

Algoritmo de Dijkstra: complejidad
Grafo en lista de adyacencia y utilizando un heap mínimo:
Dado G = (V,A), n= |V| , a= |A|
Calcula n-1 caminos mínimos
inicialización

T(n,a) <= c1 n

+

h.eliminar(w)
n−1
i=1

c2. log n +

actualizar los adyacentes de w

c3 𝑎𝑖 log n

Algoritmo de Dijkstra: complejidad
Grafo en lista de adyacencia y utilizando un heap mínimo:
Dado G = (V,A), n= |V| , a= |A|
Calcula n-1 caminos mínimos
inicialización

T(n,a) <= c1 n
c1 n

+

h.eliminar(w)
n−1
i=1

c2. log n +

+ c2 (n-1) log n

+

actualizar los adyacentes de w

c3 𝑎𝑖 log n
c3 log n

n−1
i=1 𝑎𝑖

Algoritmo de Dijkstra: complejidad
Grafo en lista de adyacencia y utilizando un heap mínimo:
Dado G = (V,A), n= |V| , a= |A|
Calcula n-1 caminos mínimos
inicialización

T(n,a) <= c1 n
c1 n

+

h.eliminar(w)
n−1
i=1

c2. log n +

+ c2 (n-1) log n

+

actualizar los adyacentes de w

c3 𝑎𝑖 log n
c3 log n

n−1
i=1 𝑎𝑖

(

n−1
i=1 𝑎𝑖 < |A| = 𝑎 )

Algoritmo de Dijkstra: complejidad
Grafo en lista de adyacencia y utilizando un heap mínimo:
Dado G = (V,A), n= |V| , a= |A|
Calcula n-1 caminos mínimos
inicialización

T(n,a) <= c1 n

+

h.eliminar(w)
n−1
i=1

c2. log n +

actualizar los adyacentes de w

c3 𝑎𝑖 log n

c1 n

+ c2 (n-1) log n

+

c3 log n

n−1
i=1 𝑎𝑖

c1 n

+ c2 (n-1) log n

+

c3 log n

𝑎

T(n,a) ϵ O (max (n log n, 𝑎 log n) )

Algoritmo de Dijkstra: complejidad
Implementaciones:
Grafo implementado con:
 Matriz de adyacencia
 Arreglos para almacenar las Distancias y Padre
Grafo implementado con:
 Lista de Adyacencia
 Arreglos para almacenar las Distancias y Padre
 Heap para almacenar las distancias ordenadas

O(n2)

O(max (n log n, a log n))

G. Densos

G. no densos

Algoritmo de Dijkstra
Algoritmo de Dijkstra está basado en la técnica de diseño greedy.
Elementos de la estrategia greedy:
 Propiedad de la elección greedy: Una solución globalmente óptima puede ser alcanzada haciendo
elecciones (greedy) localmente óptimas.
 Subestructura óptima : un problema exhibe una subestructura óptima si una solución óptima al problema
contiene soluciones óptimas para los subproblemas.

Un subcamino del camino mínimo entre dos vértices es también un camino mínimo:
Dado un grafo dirigido, rotulado G= ( V , E ), con una función de peso w : E  R,
sea p= <v1, v2, …, vk> el camino más corto de ir del vértice 1 al vértice k, entonces,
 i, j, 1<=i<=j<=k, sea pij= <vi, vi+1, …, vj> un subcamino p desde el vértice i al vértice j,
Luego pij es el camino mínimo entre el vértice i y el vértice j

Algoritmo de Dijkstra: ¿Porqué funciona?
Dijkstra: Calcula el camino más corto desde un vértice
origen (s) a todos los restantes vértices del Grafo.

La esencia del algoritmo:
Descubre la distancia mínima del origen a los otros
vértices según su distancia de menor a mayor.
Es decir, los más cercanos primero.
En la etapa intermedia en la ejecución del algoritmo:

• S contiene vértices a los cuales ya se ha calculado la distancia mínima al vértice origen
• V-S contiene los vértices a los cuales se han registrado las longitudes del camino especial más corto
(camino que comienza en el origen, atraviesa sólo los vértices calculados)

Algoritmo de Dijkstra: ¿Porqué funciona?
Probaremos por inducción sobre k que cuando hay k vértices calculados:

a)

 u  S, D[u] = distancia mínima al origen y el camino mínimo consiste sólo de vértices en S

b)  u  V-S, D[u] = distancia mínima por un camino especial de s a u o  si no existe camino.

Caso base:
a) Para k=1 S ={s} y D(s) = 0 (distancia mínima)

b)  v  V – {s}
D(v) = costo del arco s -> v, si existe arco
D(v) =  , si el arco s -> v no existe

Satisface a y b

Algoritmo de Dijkstra: ¿Porqué funciona?
Probaremos por inducción sobre k que cuando hay k vértices calculados:
a)  u  S, D[u] = distancia mínima al origen y el camino mínimo consiste sólo de vértices en S
b)  u  V-S, D[u] = distancia mínima por un camino especial de s a u o  si no existe camino.

Asumamos que a) y b) se cumplen después de haber calculado la distancia mínima de k vértices.

En el paso k+1 incorporamos el vértice v a S porque D[v] ≤ D[u]  u en {V-S} ( a) se cumple)
Supongamos que a) no se cumple (D[v] no es mínimo)
=> el costo de v puede ser mejorado a partir de otro
camino especial que va desde s a otro vértice u.
Los costos son positivos, si v fue elegido entonces
D(v) ≤ D(u) => D(v) ≤ D(u) + c(u,v)

Contradice la suposición, luego a) se cumple para v.
a) Se cumple para k+1

Algoritmo de Dijkstra: ¿Porqué funciona?
Probaremos por inducción sobre k que cuando hay k vértices calculados:
a)  u  S, D[u] = distancia mínima al origen y el camino mínimo consiste sólo de vértices en S
b)  u  V-S, D[u] = distancia mínima por un camino especial de s a u o  si no existe camino.

Ahora queda probar que b) se cumple cuando
agregamos v al conjunto de vértices ya calculados.
 uV–S:
• el penúltimo vértice del camino de s a u puede ser
v u otro vértice w
• la distancia de u será la mínima distancia del
camino especial que resulte de pasar por v o w.

Luego, b) se cumple para k+1

Caminos más corto
Problema: Dado un grafo, hallar el camino más corto:
 Desde un origen dado a todos los restantes vértices del grafo
 Desde todos los vértices del grafo a un destino único

 Entre un par de vértices
 Entre todos los pares de vértices

Caminos más corto
Problema: Dado un grafo, hallar el camino más corto:
 Desde un origen dado a todos los restantes vértices del grafo
 Desde todos los vértices del grafo a un destino único

 Entre un par de vértices
 Entre todos los pares de vértices

Caminos más corto
Problema: Dado un grafo, hallar el camino más corto:
 Desde un origen dado a todos los restantes vértices del grafo
 Desde todos los vértices del grafo a un destino único

 Entre un par de vértices
 Entre todos los pares de vértices

¿Cómo hallar el camino más corto
entre cada par de vértices?
Dado un grafo G= (V, A), con una función de costo f: A -> R definida sobre sus
arcos (rotulado con costos reales), encontrar el camino de mínimo costo*
entre cada par de vértices
Algoritmo de Floyd
Programación dinámica
*El costo de un camino es la suma de los rótulos de los arcos que lo componen

Algoritmo de Floyd
Programación dinámica
Se aplica a problemas de optimización
Elementos de la prog. dinámica:
• Subestructura óptima:
Si una solución óptima al problema contiene soluciones óptimas a subproblemas.
Si el camino del vértice i al vértice j es óptimo y k es un nodo del camino mínimo entre i y j,
entonces el subcamino que va de i a k y el subcamino que va de k a j son óptimos

• Solapamiento de problemas
El cálculo de la solución óptima implica resolver muchas veces un mismo subproblema.
Caminos mínimos entre distintos pares de vértices pueden contener los mismos subcaminos

Algoritmo de Floyd
¿ Cuáles son los subproblemas menores para los que se calculará la solución
óptima ?
• Caminos de longitud 1 , caminos directos
• Caminos de hasta longitud 2, el camino mínimo entre dos vértices directo o
pasando por el vértice 1
• Caminos mínimos entre dos vértices directo o pasando por el vértice 1 o
pasando por el vértice 2
• Caminos mínimos entre cada par de vértices, directos o pasando por los
vértices, 1, 2 y 3
• ….
• Caminos mínimos entre dos vértices, directos o pasando por cualquiera de los
vértices del grafo.

Algoritmo de Floyd
Floyd almacena las distancias de los caminos más cortos entre cada par de vértices en
una matriz A de n x n (suponemos los vértices numerados de 1 a n) (n = |V|)
• Estado Ao: Costo de los caminos directos entre cada par de vértices
• Estado A1:

Costo de los caminos mínimos entre dos vértices, directos o pasando por el vértice 1

• Estado A2 : Costo de los caminos mínimos entre dos vértices, directos o pasando por el vértice 1
o pasando por el vértice 2
•…
• Estado Ak:

Costo del camino mínimo entre dos vértices, suponiendo que sólo podemos
pasar por los vértices 1, 2, … k-1, k.

•…

• Estado An : Costo de los caminos mínimos entre dos vértices, directos, o pasando por cualquiera
de los restantes vértices
Ak El subíndice k denota el valor de la matriz A después de la k-ésima iteración, no indica existencia de n matrices
distintas.

Algoritmo de Floyd
En la k-ésima iteración se aplica la siguiente fórmula para calcular Ak.
Ak-1 [ i , j ]
Ak [ i , j ] = mín
Ak-1 [ i , k ] + Ak-1 [ k , j ]

Después de la k-ésima iteración A[i,j] tendrá por valor la longitud más pequeña de cualquier camino que
vaya de i a j y que no pase por un vértice con mayor número que k.

Algoritmo de Floyd
Para recuperar el camino mínimo entre dos vértices, Floyd utiliza una matriz P

0 el camino más corto de i a j es directo o no existe camino
P [i,j] =
k vértice intermedio que permitió a Floyd encontrar el camino mínimo.

Algoritmo de Floyd

Estado Ao de la matriz: Caminos directos

Ao [i,j]=

0

si i = j

costo (i,j)

si (i,j)  E



si (i,j)  E

Algoritmo de Floyd

Estado A1 de la matriz: Caminos mínimos entre dos vértices directos o pasando por el vértice 1 (pivote)
i,j |ij i,j 1
Ak [ i , j ] = mín (Ak-1 [ i , j ], Ak-1 [ i , k ] + Ak-1 [ k , j ] )

Algoritmo de Floyd

Estado A1 de la matriz: Caminos mínimos entre dos vértices directos o pasando por el vértice 1 (pivote)
i,j |ij i,j 1
Ak [ i , j ] = mín (Ak-1 [ i , j ], Ak-1 [ i , k ] + Ak-1 [ k , j ] )

A1 [2,3] = mín (A0 [2,3], A0 [2,1] + A0[1,3] )=
mín (



,

3

+

5

)=8

Algoritmo de Floyd

Estado A1 de la matriz: Caminos mínimos entre dos vértices directos o pasando por el vértice 1 (pivote)
i,j |ij i,j 1
Ak [ i , j ] = mín (Ak-1 [ i , j ], Ak-1 [ i , k ] + Ak-1 [ k , j ] )

A1 [3,2] = mín (A0 [3,2], A0 [3,1] + A0[1,2] )=
mín (

2 ,



)=2

Algoritmo de Floyd

Estado A2 de la matriz:
Caminos mínimos entre dos vértices
directo o pasando por el vértice 1 o pasando por el vértice 2

Algoritmo de Floyd

Estado A2 de la matriz:
Caminos mínimos entre dos vértices
directo o pasando por el vértice 1 o pasando por el vértice 2
A2 [1,3] = mín (A1 [1,3], A1 [1,2] + A1[2,3] )= mín ( 5 , 8+8) = 5

Algoritmo de Floyd

Estado A2 de la matriz:
Caminos mínimos entre dos vértices
directo o pasando por el vértice 1 o pasando por el vértice 2
A2 [3,1] = mín (A1 [3,1], A1 [3,2] + A1[2,1] )= mín (  , 2 + 3 ) = 5

Algoritmo de Floyd

Estado A3 de la matriz:
Caminos mínimos entre dos vértices,
directos o
pasando por el vértice 1 o
pasando por el vértice 2 o
pasando por el vértice 3

Algoritmo de Floyd
void Floyd (float A [][M], float C [][M], unsigned int P[][M],
unsigned int n) {
unsigned int i,j,k;
// inicialización A0
for (i =1; i <= n; i++)
for (j=1; j<= n; j++)
{
A[i][j] = C[i][j];
P[i][j] = 0;
}

// 0 si i==j

Algoritmo de Floyd
for (k=1; k <= n; k++) // calcula Ak
for( i=1; i <= n; i++)
for (j=1; j<=n; j++) {
if (A[i][k] + A[k][j] < A[i][j])
{
A[i][j] = A[i][k] + A[k][j];
P[i][j] = k;
}

} // end Floyd

Complejidad temporal O(n3)

Algoritmo de Floyd
Si existe camino entre dos vértices :
¿ Cómo recuperar el camino mínimo entre dos vértices i y j ?
void camino (unsigned int P[][M], unsigned int i, unsigned int j) {
unsigned int k= P[i][j];
if (k>0)
// k == 0 => el camino mín e/ i y j es directo
{
// k > 0 =>
i ---> k --->j
camino (P,i,k);
cout << k;
camino (P, k, j);
}
} // imprime los vértices intermedios entre i y j

Algoritmo de Warshall
El algoritmo de Floyd puede especializarse para determinar si existe un camino
entre cada para de vértices i y j.

Se desea encontrar una matriz A
A(i, j)= 1

si existe un camino entre i y j y

A(i, j)= 0

si no existe camino

Algoritmo de Warshall

Algoritmo de Warshall

Para k  1,
Ak (i, j) = Ak-1 (i, j) or ( Ak-1(i,k) and Ak-1(k, j) )

Algoritmo de Warshall

Para k  1,
Ak (i, j) = Ak-1 (i, j) or ( Ak-1(i,k) and Ak-1(k, j) )

Ejercicios
1. Modifique el algoritmo de Dijkstra, para que además de calcular los caminos más
cortos, calcule la “cantidad de caminos más cortos” entre el vértice origen y cada
uno de los restantes vértices del grafo. (Por ejemplo para el grafo de la figura, hay 2
caminos con el mismo costo para ir de 1 a 5. )
Muestre (paso a paso) como trabaja el

algoritmo para resolver el problema,
utilizando para grafo de la figura y
tomando como origen el vértice 1.

Ejercicios
Localizar el centro de un grafo dirigido.
Dado G= (V,E) , si v  V, la excentricidad de v es max w en V {camino mínimo entre w y v}
El centro de G es un vértice de mínima excentricidad
Ejemplo:

Para el grafo

las excentricidades son:

Vértice excentricidad
1

2
6
3
8
4
5
5
7

Luego: el centro del grafo es el vértice 4

Bibliografía

•

Aho, A; Hopcroft,J y Ullman, J. Estructuras de datos y algoritmos.
Addison Wesley

•

Cormen, T.; Lieserson, C.; Rivest, R.; Stein, C. Introduction to Algorithms.

(Third edition). The MIT Press.

