#ifndef PRIM_HPP
#define PRIM_HPP

#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

/**
 * Algoritmo de Prim para encontrar un Árbol de Recubrimiento de Costo Mínimo (ARM / MST).
 * 
 * Estrategia:
 * - Hace crecer un único árbol comenzando desde un vértice inicial.
 * - En cada iteración, selecciona la arista de costo mínimo que conecta un vértice ya
 *   incluido en el árbol con uno que todavía no pertenece a él.
 * - Utiliza una cola de prioridad (Min-Heap) para seleccionar eficientemente la arista más barata.
 * 
 * Complejidad: O((|V| + |A|) * log(|V|)) con Min-Heap y lista de adyacencia.
 *
 * @param g Grafo conexo y no dirigido.
 * @param origen Vértice inicial desde donde comienza a crecer el árbol.
 * @param costoTotal Variable de salida donde se acumula la suma de los costos del ARM.
 * @return vector con los arcos que conforman el árbol de recubrimiento mínimo.
 */
template <typename C>
vector<typename Grafo<C>::Arco> prim(const Grafo<C>& g, int origen, C& costoTotal) {

    vector<typename Grafo<C>::Arco> arm;
    costoTotal = 0;

    vector<int> vertices = g.devolver_vertices();
    if (vertices.empty() || !g.existe_vertice(origen)) {
        return arm;
    }

    // Marca de vértices visitados (que ya forman parte del árbol en construcción)
    unordered_map<int, bool> enArbol;
    for (int v : vertices) {
        enArbol[v] = false;
    }

    // Min-Heap de tuplas: <costo, origen_arco, destino_arco>
    // Ordena de menor a mayor costo automáticamente por ser std::greater.
    typedef tuple<C, int, int> AristaCandidata;
    priority_queue<AristaCandidata, vector<AristaCandidata>, greater<AristaCandidata>> pq;

    // Marcamos el vértice inicial como parte del árbol
    enArbol[origen] = true;

    // Insertamos en el heap todas las aristas que salen del vértice origen
    for (const auto& ady : g.devolver_adyacentes(origen)) {
        pq.push({ady.devolver_costo(), origen, ady.devolver_destino()});
    }

    const size_t cantidadVertices = vertices.size();

    // Un árbol libre de N vértices tiene exactamente N - 1 aristas
    while (!pq.empty() && arm.size() < cantidadVertices - 1) {
        auto [costo, u, v] = pq.top();
        pq.pop();

        // Si el extremo destino 'v' ya está en el árbol, tomar esta arista formaría un ciclo
        if (enArbol[v]) {
            continue;
        }

        // Incorporamos el vértice 'v' y la arista (u, v) al árbol
        enArbol[v] = true;
        arm.push_back(typename Grafo<C>::Arco(u, v, costo));
        costoTotal += costo;

        // Agregamos al heap todas las aristas incidentes a 'v' hacia vértices fuera del árbol
        for (const auto& ady : g.devolver_adyacentes(v)) {
            int vecino = ady.devolver_destino();
            if (!enArbol[vecino]) {
                pq.push({ady.devolver_costo(), v, vecino});
            }
        }
    }

    return arm;
}

/**
 * Sobrecarga de conveniencia de Prim:
 * Si no se especifica el vértice origen, toma el primer vértice disponible del grafo.
 */
template <typename C>
vector<typename Grafo<C>::Arco> prim(const Grafo<C>& g, C& costoTotal) {
    
    vector<int> vertices = g.devolver_vertices();
    
    if (vertices.empty()) {
        costoTotal = 0;
        return {};
    }
    
    return prim(g, vertices.front(), costoTotal);
}

#endif // PRIM_HPP
