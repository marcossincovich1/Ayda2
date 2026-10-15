#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

/**
 * TDA UNION-FIND (Conjuntos Disjuntos / Disjoint Set Union).
 * 
 * Mantiene una colección de conjuntos disjuntos sobre los identificadores de vértices.
 * Incluye las dos optimizaciones estándar explicadas en la cátedra:
 * 1. Unión por rango / altura (Union by Rank): para mantener los árboles balanceados.
 * 2. Compresión de caminos (Path Compression): aplana la estructura durante las búsquedas.
 * 
 * Complejidad amortizada por operación: O(α(n)), prácticamente O(1).
 */
class UnionFind {
private:
    unordered_map<int, int> padre;
    unordered_map<int, int> rango;
    int cantidad_conjuntos;

public:
    UnionFind() : cantidad_conjuntos(0) {}

    /**
     * Inicializa un conjunto disjunto para un nuevo elemento.
     */
    void make_set(int v) {
        if (padre.find(v) == padre.end()) {
            padre[v] = v;
            rango[v] = 0;
            cantidad_conjuntos++;
        }
    }

    /**
     * Devuelve el representante (raíz) del conjunto al que pertenece el elemento v.
     * Aplica compresión de caminos.
     */
    int find_set(int v) {
        if (padre.find(v) == padre.end()) {
            return -1;
        }
        if (v == padre[v]) {
            return v;
        }
        return padre[v] = find_set(padre[v]);
    }

    /**
     * Une los conjuntos que contienen a u y a v utilizando unión por rango.
     * @return true si pertenecían a conjuntos distintos y fueron unidos;
     *         false si ya pertenecían al mismo conjunto (formarían un ciclo).
     */
    bool union_set(int u, int v) {
        int raiz_u = find_set(u);
        int raiz_v = find_set(v);

        if (raiz_u == -1 || raiz_v == -1 || raiz_u == raiz_v) {
            return false;
        }

        // El árbol de menor rango se engancha bajo la raíz del de mayor rango
        if (rango[raiz_u] < rango[raiz_v]) {
            padre[raiz_u] = raiz_v;
        } else if (rango[raiz_u] > rango[raiz_v]) {
            padre[raiz_v] = raiz_u;
        } else {
            padre[raiz_v] = raiz_u;
            rango[raiz_u]++;
        }

        cantidad_conjuntos--;
        return true;
    }

    int devolver_cantidad_conjuntos() const {
        return cantidad_conjuntos;
    }
};

/**
 * Algoritmo de Kruskal para encontrar un Árbol de Recubrimiento de Costo Mínimo (ARM / MST).
 * 
 * Estrategia:
 * - Considera inicialmente a cada vértice como un árbol trivial aislado (un bosque).
 * - Ordena todas las aristas del grafo de menor a mayor costo.
 * - Recorre las aristas ordenadas: si una arista une dos componentes distintas, se agrega al ARM
 *   y se fusionan los conjuntos (usando el TDA Union-Find).
 * - Si ambos extremos ya están en la misma componente, se descarta para evitar ciclos.
 * 
 * Complejidad: O(|A| * log(|A|)), dominada por el ordenamiento de las aristas.
 *
 * @param g Grafo conexo y no dirigido.
 * @param costoTotal Variable de salida donde se acumula la suma de los costos del ARM.
 * @return vector con los arcos que conforman el árbol de recubrimiento mínimo.
 */
template <typename C>
vector<typename Grafo<C>::Arco> kruskal(const Grafo<C>& g, C& costoTotal) {
    
    vector<typename Grafo<C>::Arco> arm;
    costoTotal = 0;

    vector<int> vertices = g.devolver_vertices();
    if (vertices.empty()) {
        return arm;
    }

    // Inicializamos el TDA Union-Find con todos los vértices
    UnionFind uf;
    for (int v : vertices) {
        uf.make_set(v);
    }

    // Obtenemos todas las aristas del grafo
    vector<typename Grafo<C>::Arco> aristas = g.devolver_arcos();

    // Ordenamos las aristas ascendentemente por costo
    sort(aristas.begin(), aristas.end(), [](const typename Grafo<C>::Arco& a1, const typename Grafo<C>::Arco& a2) {
        return a1.devolver_costo() < a2.devolver_costo();
    });

    const size_t cantidadVertices = vertices.size();

    // Recorremos las aristas ordenadas
    for (const auto& arista : aristas) {
        int u = arista.devolver_origen();
        int v = arista.devolver_destino();

        // Si u y v pertenecen a conjuntos distintos, no forman ciclo
        if (uf.union_set(u, v)) {
            arm.push_back(arista);
            costoTotal += arista.devolver_costo();

            // Criterio de corte temprano: el árbol libre ya tiene |V| - 1 aristas
            if (arm.size() == cantidadVertices - 1) {
                break;
            }
        }
    }

    return arm;
}

#endif // KRUSKAL_HPP
