#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include "../TDAGrafo/HPPs/Grafo.hpp"

// Función auxiliar para representar infinito de forma segura para cualquier tipo C
template <typename C>
C dijkstra_infinito() {
    return std::numeric_limits<C>::max();
}

/**
 * Algoritmo de Dijkstra para encontrar los caminos más cortos desde un vértice origen
 * hacia todos los demás vértices de un grafo con pesos no negativos.
 * 
 * Implementación optimizada con Min-Heap (std::priority_queue).
 * Complejidad: O((|V| + |A|) * log(|V|)).
 *
 * @param g Grafo rotulado con costos no negativos.
 * @param origen Vértice inicial desde el cual se calculan los caminos.
 * @param distancias Mapa donde se almacena la distancia mínima a cada vértice.
 * @param predecesores Mapa donde se almacena el predecesor de cada vértice en el camino mínimo.
 */
template <typename C>
void dijkstra(const Grafo<C>& g, int origen, 
              std::unordered_map<int, C>& distancias, 
              std::unordered_map<int, int>& predecesores) {
    
    const C INF = dijkstra_infinito<C>();

    for (int v : g.devolver_vertices()) {
        distancias[v] = INF;
        predecesores[v] = -1;
    }

    distancias[origen] = 0;

    std::priority_queue<std::pair<C, int>, 
                        std::vector<std::pair<C, int>>, 
                        std::greater<std::pair<C, int>>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        std::pair<C, int> tope = pq.top();
        pq.pop();

        C dist_u = tope.first;
        int u = tope.second;

        if (dist_u > distancias[u]) {
            continue;
        }

        for (const auto& arco : g.devolver_adyacentes(u)) {
            int v = arco.devolver_destino();
            C costo = arco.devolver_costo();

            if (distancias[u] != INF && distancias[u] + costo < distancias[v]) {
                distancias[v] = distancias[u] + costo;
                predecesores[v] = u;
                pq.push({distancias[v], v});
            }
        }
    }
}

/**
 * Reconstruye el camino más corto desde el origen hasta el destino utilizando
 * el mapa de predecesores generado por Dijkstra.
 *
 * @return vector con los vértices en orden secuencial (origen -> ... -> destino).
 *         Retorna un vector vacío si el destino no es alcanzable desde el origen.
 */
inline std::vector<int> reconstruirCaminoDijkstra(int origen, int destino, const std::unordered_map<int, int>& predecesores) {
    std::vector<int> camino;

    if (predecesores.find(destino) == predecesores.end() || 
        (destino != origen && predecesores.at(destino) == -1)) {
        return camino;
    }

    int actual = destino;
    while (actual != -1) {
        camino.push_back(actual);
        if (actual == origen) {
            break;
        }
        actual = predecesores.at(actual);
    }

    std::reverse(camino.begin(), camino.end());

    if (camino.empty() || camino.front() != origen) {
        return {};
    }

    return camino;
}

#endif // DIJKSTRA_HPP
