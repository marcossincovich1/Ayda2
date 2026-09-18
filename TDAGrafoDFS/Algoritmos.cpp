#include "Algoritmos.hpp"
#include "../TDAGrafo/HPPs/Grafo.hpp"

#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename C>
void dfs_forest(const Grafo<C> & grafo)
{
    map<int, char> colores;

    vector<int> vertices = grafo.devolver_vertices();

    //Inicializar en blanco cada vertice
    vector<int>::iterator it = vertices.begin();
    while (it != vertices.end()) {
        int vertice = *it;
        colores[vertice] = 'B';
        it++;
    }

    it = vertices.begin();
    while (it != vertices.end()) {
        int vertice = *it;
        if (colores.find(vertice)->second == 'B')
            dfs(grafo, vertice, colores);

        it++;
    }
}
   
template<typename C>
void dfs(const Grafo<C> & grafo, int vertice, map<int, char> & colores)
{
    cout << vertice << endl;
    colores[vertice] = 'G';

    vector<typename Grafo<C>::Arco> adyacentes = grafo.devolver_adyacentes(vertice);
    typename vector<typename Grafo<C>::Arco>::iterator itA = adyacentes.begin();
    while (itA != adyacentes.end()) {
        typename Grafo<C>::Arco arco = *itA;
        int destino = arco.devolver_destino();
        if (colores.find(destino)->second == 'B')
            dfs(grafo, destino, colores);
        itA++;
    }

    colores[vertice] = 'N';
}

template void dfs_forest(const Grafo<unsigned int> & grafo);
