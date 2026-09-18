Análisis y Diseño de Algoritmos II

Ingeniería de Sistemas
Facultad de Exactas - UNICEN

Biblioteca estándar de templates de C++
Standard Template Library (STL)
● Tipos de Contenedores en STL
● Iteradores en STL
● STL: contenedores list, set y map
● Algoritmos genéricos
● Invalidación de iteradores
● Iteradores y clases parametrizadas

STL de C++
STL hace un uso intensivo del mecanismo de plantillas
(templates).
●
La documentación de la STL describe los tipos de datos que
provee a través de “conceptos”.
●
Partiendo de conceptos muy generales que abarcan a todos
los contenedores (o todos los iteradores), los mismos se van
refinando hasta llegar a conceptos que especifican a un solo
tipo de datos.
●

Por ejemplo: contenedor --> secuencia --> vector

Análisis y Diseño de Algoritmos II

STL de C++
●

Los componentes que provee son:
clases de contenedores;
− iteradores para cada tipo de contenedor;
− algoritmos para manipular los datos guardados en los
contenedores.
−

●

Gracias a los iteradores los algoritmos pueden operar sobre
los datos de los contenedores sin conocer cómo están
implementados.

Análisis y Diseño de Algoritmos II

STL: Tipos de contenedores
●

●

Secuenciales: los elementos se encuentran en un orden lineal
estricto, pudiéndose insertar y eliminar elementos de posiciones
específicas: vector, deque, list, slist

Asociativos: permiten manipular a los elementos a través de una
clave (la cual una vez almacenada no puede modificarse). Las
operaciones de acceso utilizando las claves son eficientes
(O(log(n))). Los mismos a su vez se dividen en:
○
Asociativos simples: La clave es el mismo elemento que se
almacena. Esto lleva a que los elementos guardados no puedan
modificarse: set, multiset
○
Asociativos por pares: La clave y el elemento guardado son
objetos distintos, por lo que se pueden modificar los elementos:
map, multimap
Análisis y Diseño de Algoritmos II

STL: Tipos de contenedores
●

●

Asociativos no ordenados: utilizan tablas de hash para almacenar
elementos, lo que permite obtener búsquedas muy eficientes:
unordered_set, unordered_map.

Adaptadores: son restricciones sobre contenedores existentes para
modelar estructuras específicas: stack, queue, priority_queue

Análisis y Diseño de Algoritmos II

STL: Secuencias
Inserción al principio

Elem1

Inserción en una posición
intermedia

Elem2

Elem3

Elem4

Inserción al final

Elem5

Elem6

No soporta la función de búsqueda. Si queremos consultar un elemento determinado,
debemos iterar sobre toda la colección de elementos.
●
●

●
●

Las inserciones y eliminaciones en una list tienen costo O(1).
La inserción y eliminación en el final para un vector tiene costo
O(1) (sin redimensión), el resto O(n) por desplazamientos.
vector provee acceso aleatorio eficiente O(1).
La búsqueda de un elemento tiene costo O(n) (la debemos
implementar nosotros).
Análisis y Diseño de Algoritmos II

STL: Asociaciones simples
Inserción (ordenada) respecto a una comparación definida sobre el elemento

Key3

Key1

Key7

Key6

Key2

Key5

Key4

Se brinda soporte para accesos eficientes a partir del valor del elemento.
●

●

●

Las inserciones y eliminaciones en un (multi)set tienen costo
O(log(n)).
La búsqueda de un elemento tiene costo O(log(n)) (siempre
que utilicemos el mismo criterio de comparación que se usó
para la inserción).
No se permite la modificación de los elementos guardados.
Análisis y Diseño de Algoritmos II

STL: Asociaciones por pares
Inserción (ordenada) del par [Clave,Elemento], respecto a una comparación definida
sobre la clave

Key1 Elem1

Key3 Elem3
Key7 Elem5

Key2 Elem3

Key9 Elem9

Se brinda soporte para accesos eficientes a los elementos a partir del valor de la clave
●

●

●

Las inserciones y eliminaciones en un (multi)map tienen costo
O(log(n)).
La búsqueda de un elemento tiene costo O(log(n)) (siempre
que utilicemos el mismo criterio de comparación que se usó
para la inserción).
Se permite la modificación de los elementos guardados (pero
Análisis y Diseño de Algoritmos II
no la clave).

STL: Asociativos no ordenados
●

●

●

Son similares a los asociativos pero no están basados en
árboles, usan tablas de hash para mejorar la eficiencia
promedio de las búsquedas.

Acceso, Inserción y Eliminación: Presentan un costo promedio
constante O(1).
Las inserciones, eliminaciones y búsquedas en
unordered_set/unordered_map tienen un costo promedio
constante pero O(n) en el peor caso por colisiones.

Análisis y Diseño de Algoritmos II

STL: Adaptadores
Son restricciones sobre otros contenedores existentes para
proveer interfaces y comportamientos de estructuras de datos
específicas
●

●

La pila (stack) y la cola (queue) tienen costo O(1) para push,
pop y top.
La cola de prioridad / heap (priority_queue) tiene costo O(log
n) para inserción y eliminación del elemento del tope, constante
para acceso al top.

Análisis y Diseño de Algoritmos II

STL – Iteradores: Interfaz general (1)
●

●

●

●

Un iterador es cualquier objeto capaz de referenciar a
elementos de un contenedor y proveer operadores para iterar
entre ellos.
La interfaz general es la misma sin importar a qué contenedor
quiera acceder el iterador.
Distintos tipos: entrada/salida, avance, bidireccional y acceso
aleatorio.
Definición
− TipoContenedor::iterator nombreIterador;
− TipoContenedor::const_iterator nombreIterador;

Análisis y Diseño de Algoritmos II

STL – Iteradores: Interfaz general (2)
●

Utilización
− Avanzar iterador al siguiente elemento: ++it, it++
− Acceder al valor de un elemento: *it
− Cuando los elementos almacenados son instancias de
alguna clase, también es válido:
● it->atributo
● it->método()

Análisis y Diseño de Algoritmos II

STL – Iteradores: Interfaz general (3)
−

Inicializar iterador:
it = contenedor.begin();

−

Consultar si un iterador llegó al final de la secuencia:
if (it != contenedor.end()) {
// El iterador referencia un elemento válido

} else {
}

// El iterador llegó al final

Análisis y Diseño de Algoritmos II

STL – Contenedores: list
●

Declaración

#include "list"
using namespace std;
list<TipoDato> lista;
list<TipoDato>::iterator iterador;

●

Operaciones
−

Modificadoras:
● Agregar al principio: lista.push_front(dato)
● Agregar al final: lista.push_back(dato)
● Agregar antes de una posición: lista.insert(iterador, dato)
● Eliminar el elemento en una posición: lista.erase(iterador)
● Eliminar un elemento: lista.remove(dato)

Análisis y Diseño de Algoritmos II

STL – Contenedores: list
●

Operaciones
−

Consultoras y búsquedas:
● Sacar del principio: lista.pop_front()
● Sacar del final: lista.pop_back()
● Obtener un elemento particular: ... no existe una función de
soporte para búsquedas. Hay que iterar sobre los
elementos.

−

Además las lista tienen funciones para: vaciar, intercambiar,
ordenar, fusionar, comparar, eliminar elementos repetidos,
insertar rangos de elementos, etc.

Análisis y Diseño de Algoritmos II

STL – Contenedores: set
●

Declaración

#include "set"
using namespace std;
set<TipoDato> conjunto;
set<TipoDato>::iterator iterador;

●

Operaciones
−

Modificadoras:
● Agregar un elemento: conjunto.insert(dato)
● Eliminar un elemento: conjunto.erase(dato)
● Eliminar el elemento en una posición:
conjunto.erase(iterador)

Análisis y Diseño de Algoritmos II

STL - Contenedores: set
●

Operaciones
− Consultoras y búsquedas:
Obtener una referencia a la posición de un elemento:
iterador = conjunto.find(dato)
●

−

●

Además el tipo set tiene funciones para: vaciar, intercambiar,
comparar, insertar rangos de elementos, búsqueda por rangos,
etc.

El tipo multiset es la versión del set que soporta elementos/claves
repetidos.

Análisis y Diseño de Algoritmos II

STL – Contenedores: map
●

Declaración:

#include "map"
using namespace std;
map<TipoClave,TipoDato> mapa;
map<TipoClave,TipoDato>::iterator iterador;

●

Operaciones
−

Modificadoras:
● Agregar un elemento: mapa[clave] = dato
● Eliminar un elemento: mapa.erase(clave)
● Eliminar el elemento en una posición: mapa.erase(iterador)

Alternativa: mapa.insert( pair<tipoClave,tipoDato>(clave, dato) )

Análisis y Diseño de Algoritmos II

STL – Contenedores: map
●

Operaciones
−

Consultoras y búsquedas:
● Obtener una referencia a la posición de un elemento:
iterador = mapa.find(clave)
(tener en cuenta que los elementos guardados son pares

[clave,dato], por lo tanto los iteradores son referencias a los
mismos)

−

●

Además el tipo map tiene funciones para: vaciar, intercambiar,
comparar, insertar rangos de elementos, búsqueda por rangos,
etc.

El tipo multimap es la versión del map que soporta claves repetidas.

Análisis y Diseño de Algoritmos II

STL: Ejemplo
Primera alternativa para la clase Punto como clave para un map, operador <
class Punto {
public:
Punto(int x, int y) { this->x = x; this->y = y;
int getX() const { return x; }
int getY() const { return y; }
void setX(int x) { this->x = x; }
void setY(int y) { this->y = y; }
bool operator < (const Punto & p) const {
if (x < p.x) { return true; }
else if (x > p.x) { return false; }
else { return y < p.y; } }
private:
int x, y;
};

}

ostream & operator << (ostream & stream, const Punto & punto) {
return stream << "(" << punto.getX() << "," << punto.getY() <<
")";
}
Análisis y Diseño de Algoritmos II

STL: Ejemplo
Segunda alternativa para la clase Punto como clave para un map, clase externa
con operador ()
class Punto {
public:
Punto(int x, int y) { this->x = x; this->y = y;
}
int getX() const { return x; }
int getY() const { return y; }
void setX(int x) { this->x = x; }
void setY(int y) { this->y = y; }
private:
int x, y;
};
ostream & operator << (ostream & stream, const Punto & punto) {
return stream << "(" << punto.getX() << "," << punto.getY() <<
")"; }
class ComparadorPunto {
public:
bool operator () (const Punto & p1, const Punto & p2) const {
if (p1.getX() < p2.getX()) { return true; }
else if (p1.getX() > p2.getX()) { return false; }
else { return p1.getY() < p2.getY(); }
}
Análisis y Diseño de Algoritmos II
};

STL: Ejemplo
map<Punto,list<int>,ComparadorPunto> elementosPorPunto;
list<int> lista1;
lista1.push_back(1);
elementosPorPunto[Punto(1,1)] = lista1;
elementosPorPunto[Punto(1,2)] = lista1;
elementosPorPunto[Punto(1,2)].push_back(2);
lista1.push_back(3);
elementosPorPunto[Punto(1,3)] = lista1;
map<Punto,list<int>,ComparadorPunto>::iterator it =
elementosPorPunto.begin();

while (it != elementosPorPunto.end()) {
cout << it->first << "\n";
mostrarLista(it->second);
it++;
Análisis y Diseño de Algoritmos II
}

(1,1) -> [1]
(1,2) -> [1,2]
(1,3) -> [1,3]

STL: Ejemplo
int x,y;
cin>>x;
cin>>y;
Punto p(x,y);

map<Punto,list<int>,ComparadorPunto>::iterator it =
elementosPorPunto.find(p);
if (it != elementosPorPunto.end()) {
cout << "Punto Encontrado: " << it->first << "\n";
mostrarLista(it->second);
} else {
cout << "No se encontró el punto: " << p;
}

Análisis y Diseño de Algoritmos II

STL: Algoritmos genéricos
template<typename InputIterator>
void imprimirElementos(InputIterator inicio, InputIterator fin) {
InputIterator it = inicio;
while (it != fin) {
cout << *it << "\n";
it++;
}
}

// Ahora no importa si almacenamos los puntos en un list o en un set.
imprimirElementos(puntos.begin(), puntos.end());

Análisis y Diseño de Algoritmos II

STL: Asociativos no ordenados
●

En el caso de querer usar una clase propia como clave para un
contenedor asociativo no ordenado es necesario:
− Implementar el operador de comparación para resolver
colisiones:
bool operator == (const Punto & p1) const;
− Proveer una función de hash que transforme una instancia
de nuestra clase en un número.
Investigar en caso de ser necesario

Análisis y Diseño de Algoritmos II

STL: Invalidación de iteradores (1)
●

●

vector:
− Cambio en la capacidad.
− Tanto la inserción como el borrado de un elemento invalida
los iteradores a partir de ese elemento.

list / set / map:
− Las inserciones no invalidan iteradores.
− Las eliminaciones no invalidan los iteradores en otras
posiciones. Sólo se invalidan los que referencian al
elemento eliminado.

Análisis y Diseño de Algoritmos II

STL: Invalidación de iteradores (2)
●

Ejemplo de eliminación sin invalidación:

map<Punto,list<int>,ComparadorPunto>::iterator it =
elementosPorPunto.begin();
map<Punto,list<int>,ComparadorPunto>::iterator itToDel;
while (it != elementosPorPunto.end())
{
if (it->second.size() == 0)
{
itToDel = it;
it++;
elementosPorPunto.erase(itToDel);
} else {
it++;
}
}

Análisis y Diseño de Algoritmos II

Iteradores y clases parametrizadas
●

Ejemplo, iterador a lista parametrizada con C:
template <typename C>
void A<C>::funcion()
{
list<C>::iterator it; //Error: no lo reconoce como un tipo.
}

●

Es necesario utilizar la palabra reservada typename:
template <typename C>
void A<C>::funcion()
{
typename list<C>::iterator it;
}

●

●

Los nombres que dependen de un parámetro template, se
denominan nombres dependientes, ya que solo se conocen
cuando se instancia la clase parametrizada.
La palabra reservada typename le indica al compilador que un
nombre dependiente es un tipo de datos, sin ella el compilador
la interpreta como un nombre sin tipo.
Análisis y Diseño de Algoritmos II

Enlaces
●

Standard Template Library (STL)
C++https://en.cppreference.com/

●

●

cplusplus.com (algo más amigable pero no tan actualizado)
− http://www.cplusplus.com/

Análisis y Diseño de Algoritmos II

Tarea propuesta
● Analizar las opciones de la biblioteca STL.
● Elegir una estructura apropiada para el TDA
Grafo utilizando los contenedores de la biblioteca
STL.
● Completar la implementación del TDA Grafo.

Consultas: laboratorio.ayda@alumnos.exa.unicen.edu.ar
Licencia creative commons
Atribución-Compartir Obras Derivadas Igual 2.5 Argentina

http://creativecommons.org/licenses/by-sa/2.5/ar/

