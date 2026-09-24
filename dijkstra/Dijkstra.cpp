#include "Dijkstra.hpp"

#include <map>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#include <ostream>

using namespace std;

//Clase Solucion
template <typename C>
Dijkstra<C>::Solucion::Solucion()
{
}

template <typename C>
Dijkstra<C>::Solucion::Solucion(map<int, int> & distancias, map<int,int> & predecesores)
{
    this->distancias = distancias;
    this->predecesores = predecesores;
}

template <typename C>
Dijkstra<C>::Solucion::~Solucion()
{
}

template <typename C>
const map<int, int> & Dijkstra<C>::Solucion::obtener_distancias() const
{
    return this->distancias;
}

template <typename C>
const map<int, int> & Dijkstra<C>::Solucion::obtener_predecesores() const
{
    return this->predecesores;
}

//Clase Solucion


//Clase Dijkstra

template <typename C>
Dijkstra<C>::Dijkstra(const Grafo<C> & g) : grafo(g)
{
}

template <typename C>
Dijkstra<C>::~Dijkstra()
{
}

template <typename C>
typename Dijkstra<C>::Solucion Dijkstra<C>::resolver(int origen)
{
    map<int, int> distancias;
    map<int, int> predecesores;

    set<int> S;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;

    //Paso 0: inicialización
    vector<int> vertices = grafo.devolver_vertices();
    vector<int>::iterator it = vertices.begin();
    while (it != vertices.end()) {
        distancias[*it] = INT_MAX;
        predecesores[*it] = -1;
        it++;
    }
    distancias[origen] = 0;
    q.push(make_pair(0, origen));

    while (!q.empty()) {
        //Vertice de distancia minima.
        int u = q.top().second;
        q.pop();
        //u no está en S
        if (S.find(u) == S.end()) {
            S.insert(u);
            vector<typename Grafo<C>::Arco> ady = grafo.devolver_adyacentes(u);
            typename vector<typename Grafo<C>::Arco>::iterator itAdy = ady.begin();

            while (itAdy != ady.end()) {
                int v = itAdy->devolver_destino();
                C costo = itAdy->devolver_costo();

                //Relajar (u)
                if (distancias[v] > distancias[u] + costo) {
                    distancias[v] = distancias[u] + costo;
                    predecesores[v] = u;
                    q.push(make_pair(distancias[v], v)); //Actualizar min heap
                }
                itAdy++;
            }
        }
    }

    return Solucion(distancias, predecesores);
}

template class Dijkstra<int>;
