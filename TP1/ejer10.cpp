#include <iostream>
#include <unordered_map>
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

// Función auxiliar para agregar una arista no dirigida (ambos sentidos)
template <typename C>
void agregar_arista_no_dirigida(Grafo<C>& g, int u, int v, const C& costo = 0) {
    g.agregar_arco(u, v, costo);
    g.agregar_arco(v, u, costo);
}

// DFS estándar: recorre todos los vértices alcanzables y les asigna el ID de componente
template <typename C>
void dfs(const Grafo<C>& g, int v, unordered_map<int, bool>& visitados, int comp_id, unordered_map<int, int>& componente_de) {
    visitados[v] = true;
    componente_de[v] = comp_id;

    for (const auto& arco : g.devolver_adyacentes(v)) {
        int destino = arco.devolver_destino();
        if (!visitados[destino]) {
            dfs(g, destino, visitados, comp_id, componente_de);
        }
    }
}

// Algoritmo para encontrar componentes conectadas en un grafo no dirigido
template <typename C>
int componentesConectadas(const Grafo<C>& g, unordered_map<int, int>& componente_de) {
    unordered_map<int, bool> visitados;

    for (int v : g.devolver_vertices()) {
        visitados[v] = false;
    }

    int cantidad_componentes = 0;

    for (int v : g.devolver_vertices()) {
        if (!visitados[v]) {
            cantidad_componentes++;
            dfs(g, v, visitados, cantidad_componentes, componente_de);
        }
    }

    return cantidad_componentes;
}

int main() {
    Grafo<unsigned int> g10;
    unordered_map<int, int> componenteDe;

    // Agregamos vértices: 1, 2, 3 (componente 1), 4, 5 (componente 2), 6 (componente 3 aislada)
    for (int i = 1; i <= 6; ++i) {
        g10.agregar_vertice(i);
    }

    // Componente 1: {1, 2, 3}
    agregar_arista_no_dirigida(g10, 1, 2);
    agregar_arista_no_dirigida(g10, 2, 3);

    // Componente 2: {4, 5}
    agregar_arista_no_dirigida(g10, 4, 5);

    // Vértice 6 queda aislado (Componente 3)

    int result = componentesConectadas(g10, componenteDe);

    cout << "La cantidad de componentes conexas son: " << result << endl;

    for (const auto& par : componenteDe) {
        cout << "Vertice: " << par.first << " -> Pertenece a la componente: " << par.second << endl;
    }

    return 0;
}
