#include <iostream>
#include <vector>
#include <string>

#include "../TDAGrafo/HPPs/Grafo.hpp"
#include "Prim.hpp"
#include "Kruskal.hpp"

using namespace std;

// Función auxiliar para agregar aristas no dirigidas
template <typename C>
void agregarAristaNoDirigida(Grafo<C>& g, int u, int v, C costo) {
    g.agregar_arco(u, v, costo);
    g.agregar_arco(v, u, costo);
}

int main() {
    // Grafo ejemplo visto en la teoría de la cátedra (Práctica 2 - TP1)
    // Vértices representados:
    // 1: A, 2: B, 3: C, 4: D, 5: E, 6: F
    Grafo<unsigned int> g;

    for (int i = 1; i <= 6; ++i) {
        g.agregar_vertice(i);
    }

    agregarAristaNoDirigida(g, 2, 3, 2u); // B - C : 2
    agregarAristaNoDirigida(g, 1, 3, 3u); // A - C : 3
    agregarAristaNoDirigida(g, 4, 6, 3u); // D - F : 3
    agregarAristaNoDirigida(g, 1, 2, 4u); // A - B : 4
    agregarAristaNoDirigida(g, 3, 5, 4u); // C - E : 4
    agregarAristaNoDirigida(g, 2, 4, 5u); // B - D : 5
    agregarAristaNoDirigida(g, 3, 4, 6u); // C - D : 6
    agregarAristaNoDirigida(g, 4, 5, 7u); // D - E : 7
    agregarAristaNoDirigida(g, 5, 6, 8u); // E - F : 8

    auto nombreVertice = [](int id) -> char {
        return static_cast<char>('A' + id - 1);
    };

    cout << "=================================================" << endl;
    cout << "   EJERCICIO 16 - ALGORITMOS DE PRIM Y KRUSKAL   " << endl;
    cout << "=================================================" << endl;

    // --- PRIM ---
    unsigned int costoPrim = 0;
    int origenPrim = 1; // Comenzamos desde el vértice A
    auto arbolPrim = prim(g, origenPrim, costoPrim);

    cout << "\n--- ALGORITMO DE PRIM (iniciando en " << nombreVertice(origenPrim) << ") ---" << endl;
    cout << "Aristas seleccionadas en el orden en que se incorporaron al arbol:" << endl;
    for (const auto& arco : arbolPrim) {
        cout << "  (" << nombreVertice(arco.devolver_origen()) << " - " 
             << nombreVertice(arco.devolver_destino()) << ") con costo " 
             << arco.devolver_costo() << endl;
    }
    cout << "Costo total del ARM (Prim): " << costoPrim << endl;

    // --- KRUSKAL ---
    unsigned int costoKruskal = 0;
    auto arbolKruskal = kruskal(g, costoKruskal);

    cout << "\n--- ALGORITMO DE KRUSKAL ---" << endl;
    cout << "Aristas seleccionadas en el orden de menor costo:" << endl;
    for (const auto& arco : arbolKruskal) {
        cout << "  (" << nombreVertice(arco.devolver_origen()) << " - " 
             << nombreVertice(arco.devolver_destino()) << ") con costo " 
             << arco.devolver_costo() << endl;
    }
    cout << "Costo total del ARM (Kruskal): " << costoKruskal << endl;

    cout << "\n=================================================" << endl;
    if (costoPrim == costoKruskal) {
        cout << " [OK] Ambos algoritmos coinciden en el costo minimo: " << costoPrim << endl;
    } else {
        cout << " [ERROR] Los costos difieren." << endl;
    }
    cout << "=================================================" << endl;

    return 0;
}
