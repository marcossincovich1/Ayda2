Análisis y Diseño de Algoritmos II

Ingeniería de Sistemas
Facultad de Exactas - UNICEN

Grafos
● Concepto de grafo
● TDA Grafo
● Alternativas de implementación
○ Lista de listas
○ Matriz
● Detalles de implementación

Grafo como modelo (1)
Arcos

●

b

a

c
e

d
h

f

g
h

Vértices
Análisis y Diseño de Algoritmos II

Considerar al grafo
como un modelo
(matemático,
algorítmico) para la
resolución de
problemas:
− ¿Qué
representan los
vértices?
− ¿Qué
representan los
arcos?

Grafo como modelo (2)
Costoxy
x

y

Costoyx
●

●

En el caso general la transición de un nodo a sus adyacentes
tiene asociado un costo.
Las conexiones entre nodos pueden ser unidireccionales (grafo
dirigido) o bidireccionales (grafo no dirigido).

Análisis y Diseño de Algoritmos II

Grafo como modelo (3)
●

Tipos de problemas que podemos resolver sobre un modelo de
grafo:
− Relacionados con caminos:
● Problema del viajante.
● Camino/Ciclo Hamiltoniano.
● Caminos más cortos.
● Árboles de recubrimientos mínimos.
− Coloreo de vértices.
− Cobertura de vértices.
− Búsqueda (DFS, BFS, heurística, ...).

Análisis y Diseño de Algoritmos II

Grafo como TDA (1)
●

●

●

Estructura de datos que nos permite manejar:
− Un conjunto de vértices: V
− Un conjunto de arcos con peso: E / Ei=(Vorigen,Vdestino,Costo)
Debemos definir una interfaz (lo más independiente posible de
la estructura interna) para:
− Agregar, eliminar y consultar la existencia de los vértices.
− Agregar, eliminar y consultar el costo y la existencia de los
arcos.
− Permitir el acceso a todos los vértices y todos los arcos.
− Permitir el acceso a los adyacentes de un vértice dado.
Siempre que respetemos la interfaz, podemos optar entre
diversas representaciones internas.
Análisis y Diseño de Algoritmos II

Interfaz TDA Grafo
template <typename C> class Grafo {
public:
bool esta_vacio() const;
int cantidad_vertices() const;
int cantidad_arcos() const;

void agregar_vertice(int vertice);
void eliminar_vertice(int vertice);
bool existe_vertice(int vertice) const;
void agregar_arco(int origen, int destino, const C & costo);
void eliminar_arco(int origen, int destino);
bool existe_arco(int origen, int destino) const;
const C & costo_arco(int origen, int destino) const;
vector<int> devolver_vertices() const;
vector<Arco<C> > devolver_adyacentes(int origen) const;
vector<Arco<C> > devolver_arcos() const;
};
Análisis y Diseño de Algoritmos II

Clase TDA Arco
template <typename C> class Grafo {
public:
class Arco {
public:
Arco();
Arco(int origen, int destino, const C & costo);
int devolver_origen() const;
int devolver_destino() const;
const C & devolver_costo() const;
private:
int origen;
int destino;
C costo;
};
};

Análisis y Diseño de Algoritmos II

Implementación interna: listas de
adyacencia
a

Listas de adyacencia:

b,cab

b

a,cba

c,cbc

c

b,ccb

d,ccd

d

b,cdb

c,cdc

e

b,ceb

f,cef

f

e,cfe

g

h,cgh

i,cgi

d,cbd

● Cada vértice tiene asociado
una estructura de lista con los
pares (Vdestino,Costo)
● La intención es optimizar la
utilización del espacio en el
caso de los grafos que no
están “muy conectados”.
● La consulta de si existe un arco
requiere una búsqueda en lista
de adyacentes.
● En el caso de un grafo de
enteros, la estructura principal
de los vértices puede ser un
arreglo o una lista.

Análisis y Diseño de Algoritmos II

Implementación interna:matriz de
adyacencia
a
a

b

c

d

e

f

g

Matriz de adyacencia:
●

cab

●
b

cba

cbc

c

ccb

d

cdb

e

ceb

f
g

cbd

cbe

ccd
cdc

cef
cfe

●
●

Los costos de los arcos existentes
se guardan en una matriz.
Consideraciones:
− ¿qué valor utilizar cuando no
existe la conexión?
→ indicar el valor por defecto en
el constructor
→ o asociar un bool a cada
celda
− ¿qué pasa si hay que agregar o
eliminar vértices?
→ utilizar un arreglo auxiliar
para indicar la existencia
La consulta de la existencia de un
arco es rápida.
Si el grafo no está “muy conectado”
queda mucha memoria reservada sin
utilizar.

Análisis y Diseño de Algoritmos II

Información asociada a los vértices
●

●

¿Cómo mantener la información relacionada a los vértices
cuando los mismos son estructuras complejas?
Dos posibilidades:
− Modificar la interfaz del grafo para que el mismo pueda
almacenar vértices de cualquier tipo. (descartamos esta
opción)
− Mantener la interfaz del grafo y guardar la información de
los vértices fuera del mismo, utilizando los enteros como
identificadores.

Análisis y Diseño de Algoritmos II

Tarea propuesta
Utilizando la implementación provista (matriz de
adyacentes) comenzar a implementar los algoritmos
propuestos en el práctico N° 1.

Consultas: laboratorio.ayda@alumnos.exa.unicen.edu.ar
Licencia creative commons
Atribución-Compartir Obras Derivadas Igual 2.5 Argentina

http://creativecommons.org/licenses/by-sa/2.5/ar/

