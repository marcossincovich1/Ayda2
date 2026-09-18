# Resolución del Ejercicio 2 - TP1 (Grafos)

A continuación se presenta la resolución de los puntos solicitados, omitiendo el punto (e) de implementación en C++ tal como fue requerido.

Para el desarrollo del ejercicio, asumimos que la exploración de los vértices y de las listas de adyacencia se realiza en **orden numérico ascendente**. 

El grafo de la figura es un **grafo no dirigido** y está compuesto por dos componentes conexas:
- **Componente 1:** Vértices {1, 2, 3, 4, 5}
- **Componente 2:** Vértices {6, 7, 8, 9}

---

### a) Bosque asociado al recorrido y tiempos de descubrimiento/finalización

Iniciamos el recorrido `DFS_Forest` partiendo del vértice 1.

**Traza del recorrido (Componente 1):**
- `DFS(1)`: `d[1] = 1`. Adyacentes: 2, 3, 4.
  - `DFS(2)`: `d[2] = 2`. Adyacentes: 1, 3, 5.
    - `DFS(3)`: `d[3] = 3`. Adyacentes: 1, 2, 5.
      - Ve a 1. Está GRIS y no es padre. -> *Arista (3,1)*.
      - Ve a 2. Es el padre, se ignora.
      - `DFS(5)`: `d[5] = 4`. Adyacentes: 2, 3.
        - Ve a 2. Está GRIS y no es padre. -> *Arista (5,2)*.
        - Ve a 3. Es el padre, se ignora.
        - Fin de 5: `f[5] = 5`.
      - Fin de 3: `f[3] = 6`.
    - Fin de 2: `f[2] = 7`.
  - Ve a 3. Está NEGRO. Ya fue explorada (es la misma arista 3-1).
  - `DFS(4)`: `d[4] = 8`. Adyacentes: 1.
    - Ve a 1. Es el padre, se ignora.
    - Fin de 4: `f[4] = 9`.
  - Fin de 1: `f[1] = 10`.

**Traza del recorrido (Componente 2):**
El siguiente vértice blanco es el 6.
- `DFS(6)`: `d[6] = 11`. Adyacentes: 7, 8.
  - `DFS(7)`: `d[7] = 12`. Adyacentes: 6, 9.
    - Ve a 6. Es el padre, se ignora.
    - `DFS(9)`: `d[9] = 13`. Adyacentes: 7, 8.
      - Ve a 7. Es el padre, se ignora.
      - `DFS(8)`: `d[8] = 14`. Adyacentes: 6, 9.
        - Ve a 6. Está GRIS y no es padre. -> *Arista (8,6)*.
        - Ve a 9. Es el padre, se ignora.
        - Fin de 8: `f[8] = 15`.
      - Fin de 9: `f[9] = 16`.
    - Fin de 7: `f[7] = 17`.
  - Ve a 8. Está NEGRO. Ya fue explorada.
  - Fin de 6: `f[6] = 18`.

**Tiempos registrados (d / f):**
- **Vértice 1:** 1 / 10
- **Vértice 2:** 2 / 7
- **Vértice 3:** 3 / 6
- **Vértice 4:** 8 / 9
- **Vértice 5:** 4 / 5
- **Vértice 6:** 11 / 18
- **Vértice 7:** 12 / 17
- **Vértice 8:** 14 / 15
- **Vértice 9:** 13 / 16

---

### b) Clasificación de las aristas del grafo

Dado que es un grafo no dirigido, consideramos la arista la primera vez que la clasificamos.

- **Aristas de Árbol (Tree edges):** (1,2), (2,3), (3,5), (1,4), (6,7), (7,9), (9,8).
- **Aristas de Retroceso (Back edges):** (3,1), (5,2), (8,6).

---

### c) Tipos de aristas en una exploración DFS

En la exploración DFS de un **grafo no dirigido**, únicamente aparecen dos tipos de aristas:
1. **Aristas de árbol:** Aquellas que conducen a vértices no descubiertos (blancos).
2. **Aristas de retroceso:** Aquellas que conectan un vértice con un ancestro (gris) que no sea su padre inmediato en el árbol DFS.

*Nota:* Las aristas de avance (forward) y cruzadas (cross) no existen en grafos no dirigidos porque cualquier arista que pudiera clasificarse como tal se descubre primero en la otra dirección (ya sea como arista de árbol o de retroceso).

---

### d) Pseudocódigo del DFS modificado

```text
DFS(G)
  Para cada vértice u en G.V
    u.color = BLANCO
    u.pi = NULO
  tiempo = 0
  Para cada vértice u en G.V
    Si u.color == BLANCO
      DFS-VISIT(G, u)

DFS-VISIT(G, u)
  tiempo = tiempo + 1
  u.d = tiempo
  u.color = GRIS
  Para cada v en G.Adj[u]
    Si v.color == BLANCO
      Imprimir "La arista (", u, ",", v, ") es de Árbol"
      v.pi = u
      DFS-VISIT(G, v)
    Sino Si v.color == GRIS y v != u.pi
      Imprimir "La arista (", u, ",", v, ") es de Retroceso"
    // Si v.color == NEGRO o (v.color == GRIS y v == u.pi), 
    // es la misma arista en sentido contrario, por lo que no se imprime.
  u.color = NEGRO
  tiempo = tiempo + 1
  u.f = tiempo
```

---

### f) Repetición cambiando el orden de los vértices

**¿Obtuvo la misma información?**
**No exactamente**. Al cambiar el orden en el que se toman los vértices (por ejemplo, iterar de mayor a menor, o procesar los adyacentes en orden descendente), obtendríamos resultados diferentes en:
1. **Los tiempos de descubrimiento y finalización:** Serán completamente distintos.
2. **La estructura del bosque DFS:** Las raíces de los árboles podrían cambiar, y el conjunto específico de aristas que forman el árbol DFS sería diferente (algunas aristas que antes eran de árbol ahora podrían ser de retroceso y viceversa).

**Sin embargo, la siguiente información sí se mantiene invariante:**
- Seguiremos encontrando exactamente **dos árboles** en el bosque DFS (ya que hay dos componentes conexas).
- Seguiremos clasificando las aristas únicamente en **aristas de árbol y de retroceso** (es una propiedad intrínseca de los grafos no dirigidos).
- La **cantidad** total de aristas de árbol será `V - C` (donde V es vértices y C componentes conexas, o sea 9 - 2 = 7) y la cantidad de aristas de retroceso será `E - (V - C)` (10 - 7 = 3).
