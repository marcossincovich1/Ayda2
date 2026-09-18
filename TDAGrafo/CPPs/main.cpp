#include <iostream>
#include "../HPPs/Grafo.hpp"

using namespace std;

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	vector<int> vertices;
	vertices = grafo.devolver_vertices();
	vector<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << endl;
		// Recorremos todos los adyacentes de cada vertice
		vector<typename Grafo<C>::Arco> adyacentes;
		adyacentes = grafo.devolver_adyacentes(*v);
		typename vector<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_destino() << " (" << ady->devolver_costo() << ")" << endl;
			ady++;
		}
		v++;
	}

	vector<typename Grafo<C>::Arco> arcos;
	arcos = grafo.devolver_arcos();
	salida << "Todos los arcos: " << endl;
	typename vector<typename Grafo<C>::Arco>::iterator ady = arcos.begin();
    while (ady != arcos.end()) {
        salida << " (" << ady->devolver_origen() << ", " << ady->devolver_destino() << ", "  << ady->devolver_costo() << ")" << endl;
        ady++;
    }
	return salida;
}



int main()
{
    Grafo<int> g;

	// Cargamos un grafo dirigido
	// Primero los v�rtices
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	g.agregar_vertice(7);
	// Luego los arcos
	g.agregar_arco(1, 2, 2);
	g.agregar_arco(1, 3, 1);
	g.agregar_arco(2, 4, 1);
	g.agregar_arco(2, 3, 4);
	g.agregar_arco(3, 4, 4);
	g.agregar_arco(3, 5, 5);
	g.agregar_arco(2, 5, 3);
	g.agregar_arco(5, 6, 1);
	g.agregar_arco(4, 6, 2);

	// Mostramos el grafo
	cout << "Estructura del grafo:\n" << g << "(" << g.cantidad_vertices()
        << " vertices, " << g.cantidadArcos() << " arcos)" << endl;
    return 0;
}
