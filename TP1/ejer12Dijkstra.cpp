#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

// Función auxiliar para representar infinito de forma segura para cualquier tipo C
template <typename C>
C infinito() {
    return numeric_limits<C>::max();
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
              unordered_map<int, C>& distancias, 
              unordered_map<int, int>& predecesores) {
    
    const C INF = infinito<C>();

    // Paso 1: Inicialización
    // Para todo vértice v en V: distancias[v] = INF, predecesores[v] = -1
    for (int v : g.devolver_vertices()) {
        distancias[v] = INF;
        predecesores[v] = -1;
    }

    // La distancia al origen es 0
    distancias[origen] = 0;

    // Min-heap de pares (distancia_acumulada, vertice)
    // Con std::greater el elemento de menor distancia queda en la cima (top)
    priority_queue<pair<C, int>, vector<pair<C, int>>, greater<pair<C, int>>> pq;
    pq.push({0, origen});

    // Paso 2: Iteración y relajación de aristas
    while (!pq.empty()) {
        pair<C, int> tope = pq.top();
        pq.pop();

        C dist_u = tope.first;
        int u = tope.second;

        // Si la distancia extraída es mayor a la ya registrada, es una entrada obsoleta
        if (dist_u > distancias[u]) {
            continue;
        }

        // Relajamos todas las aristas salientes del vértice u
        for (const auto& arco : g.devolver_adyacentes(u)) {
            int v = arco.devolver_destino();
            C costo = arco.devolver_costo();

            // Condición de relajación: D[v] > D[u] + costo(u, v)
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
 * @param origen Vértice inicial.
 * @param destino Vértice final deseado.
 * @param predecesores Mapa de predecesores devuelto por dijkstra.
 * @return vector con los vértices en orden secuencial (origen -> ... -> destino).
 *         Retorna un vector vacío si el destino no es alcanzable desde el origen.
 */
vector<int> reconstruirCamino(int origen, int destino, const unordered_map<int, int>& predecesores) {
    vector<int> camino;

    // Si el destino no está registrado o no tiene predecesor (y no es el origen), no hay camino
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

    reverse(camino.begin(), camino.end());

    // Verificación de seguridad: el camino debe comenzar en el origen
    if (camino.empty() || camino.front() != origen) {
        return {};
    }

    return camino;
}

int main() {
    Grafo<unsigned int> g;

    for (int i = 1; i <= 5; ++i) {
        g.agregar_vertice(i);
    }

    g.agregar_arco(1, 2, 10);
    g.agregar_arco(1, 4, 30);
    g.agregar_arco(1, 5, 100);
    g.agregar_arco(2, 3, 50);
    g.agregar_arco(3, 5, 10);
    g.agregar_arco(4, 3, 20);
    g.agregar_arco(4, 5, 60);

    int origen = 1;
    unordered_map<int, unsigned int> distancias;
    unordered_map<int, int> predecesores;

    dijkstra(g, origen, distancias, predecesores);

    cout << "=== Algoritmo de Dijkstra (Vértice Origen: " << origen << ") ===" << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int v : g.devolver_vertices()) {
        cout << "Vértice " << v << ": ";
        if (distancias[v] == infinito<unsigned int>()) {
            cout << "Inalcanzable" << endl;
        } else {
            cout << "Distancia mínima = " << distancias[v] 
                 << " | Predecesor = " << predecesores[v] 
                 << " | Camino: ";
            
            vector<int> camino = reconstruirCamino(origen, v, predecesores);
            for (size_t i = 0; i < camino.size(); ++i) {
                cout << camino[i];
                if (i + 1 < camino.size()) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
