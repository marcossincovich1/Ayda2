Problema:

encontrar todos los caminos simples
un vértice origen y un vértice destino

Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6
1

DFS (G, origen ...) {
Marca[origen]= VISITADO;

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v,...);

}
Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

DFS (G, origen, & camino, ...) {
Marca[origen]= VISITADO;
camino.agregar(origen)

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, camino, ...);

}
Liliana Martinez - Claudia Pereira

1

camino → 1
Ady(1) = 2

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

1

2

DFS (G, origen, & camino, ...) {
Marca[origen]= VISITADO;
camino.agregar(origen)

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, camino, ...);

}
Liliana Martinez - Claudia Pereira

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, & camino, ...) {
Marca[origen]= VISITADO;
camino.agregar(origen)

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, camino, ...);

}
Liliana Martinez - Claudia Pereira

3

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, & camino, ...) {
Marca[origen]= VISITADO;
camino.agregar(origen)

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, camino, ...);

}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

3

6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, & camino, ...) {
Marca[origen]= VISITADO;
camino.agregar(origen)

for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, camino, ...);

}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

¿Pido la lista de adyacentes de 6 para continuar la exploración?

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

Si llegué al vértice destino,
1. imprimo el camino

Caminos:
1, 2, 3, 6

}
Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

Si llegué al vértice destino,
1. imprimo el camino
2. antes de volver, saco el último vértice agregado
del camino
Caminos:
1, 2, 3, 6

}
Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

Caminos:
1, 2, 3, 6

}
Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓

✓

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();

camino → 1, 2, 3, 6

3

6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

5

camino → 1, 2, 5
Ady(5) = 3, 6

No puedo avanzar porque sus dos
adyacentes están visitados

Caminos:
1, 2, 3, 6

}
Liliana Martinez - Claudia Pereira

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓
2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6
Desmarcar los vértices al volver de la recursión

Caminos:
1, 2, 3, 6

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

Caminos:
1, 2, 3, 6

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

1

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

3

6

Caminos:
1, 2, 3, 6

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

✓

1

✓

✓

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

5

3

6

camino → 1, 2, 5, 3, 6

camino → 1, 2, 5
Ady(5) = 3, 6

3

6

Caminos:
1, 2, 3, 6
1, 2, 5, 3, 6

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6

✓

✓

1

✓

✓

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

5

3

6

camino → 1, 2, 5, 3, 6

3

camino → 1, 2, 5
Ady(5) = 3, 6

6

camino → 1, 2, 5, 6

6

Caminos:
1, 2, 3, 6
1, 2, 5, 3, 6
1, 2, 5, 6

Problema: encontrar todos los caminos entre el vértice 1 y el vértice 6
1

2
camino → 1, 2, 3
Ady(3) = 6

DFS (G, origen, destino, & camino) {
Marca[origen]= VISITADO;
camino.agregar(origen)
if (origen == destino)
imprimir(camino)
else
for cada vértice v ϵ G.Ady[origen]
if Marca[v] = NO-VISITADO
DFS (G,v, destino, camino);
camino.eliminar_ultimo();
Marca[origen]= NO-VISITADO;
}
Liliana Martinez - Claudia Pereira

camino → 1, 2, 3, 6

camino → 1
Ady(1) = 2

camino → 1, 2
Ady(2) = 3, 5

5

3

6

camino → 1, 2, 5, 3, 6

3

camino → 1, 2, 5
Ady(5) = 3, 6

6

camino → 1, 2, 5, 6

6

Caminos:
1, 2, 3, 6
1, 2, 5, 3, 6
1, 2, 5, 6

