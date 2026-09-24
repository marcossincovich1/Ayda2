#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <iomanip>
#include <algorithm>
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

// Función auxiliar para representar infinito de forma segura para cualquier tipo C
template <typename C>
C infinito() {
    return numeric_limits<C>::max();
}

/**
 * Algoritmo de Floyd-Warshall para encontrar los caminos más cortos entre
 * TODOS los pares de vértices de un grafo.
 * 
 * Aplica Programación Dinámica calculando estados sucesivos Ak:
 *   Ak[i][j] = min( Ak-1[i][j], Ak-1[i][k] + Ak-1[k][j] )
 *
 * Complejidad temporal: O(|V|^3)
 *
 * @param g Grafo rotulado con costos.
 * @param A Matriz resultado de distancias mínimas: A[i][j] es el costo mínimo de i a j.
 * @param P Matriz de recuperación de caminos: P[i][j] almacena el vértice intermedio k
 *          que permitió optimizar el camino, o 0 si el camino es directo / no existe.
 */
template <typename C>
void floyd(const Grafo<C>& g, 
           unordered_map<int, unordered_map<int, C>>& A, 
           unordered_map<int, unordered_map<int, int>>& P) {
    
    const C INF = infinito<C>();
    vector<int> vertices = g.devolver_vertices();

    // Estado A0 y P0: Inicialización con caminos directos
    for (int i : vertices) {
        for (int j : vertices) {
            if (i == j) {
                A[i][j] = 0;
            } else if (g.existe_arco(i, j)) {
                A[i][j] = g.costo_arco(i, j);
            } else {
                A[i][j] = INF;
            }
            P[i][j] = 0; // 0 indica camino directo o sin camino
        }
    }

    // Bucle triple de Floyd:
    // k es el vértice pivote (posible vértice intermedio)
    for (int k : vertices) {
        for (int i : vertices) {
            for (int j : vertices) {
                // Verificamos que existan caminos i -> k y k -> j para evitar desbordamiento (overflow)
                if (A[i][k] != INF && A[k][j] != INF) {
                    if (A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                        P[i][j] = k; // k es el vértice que mejoró el camino de i a j
                    }
                }
            }
        }
    }
}

/**
 * Función auxiliar recursiva para recuperar vértices intermedios a partir de la matriz P.
 * Corresponde a la función `camino(P, i, j)` de las diapositivas de la cátedra:
 * Si P[i][j] = k > 0, entonces el camino pasa por k: i -> ... -> k -> ... -> j.
 */
void recuperarIntermedios(int i, int j, 
                         const unordered_map<int, unordered_map<int, int>>& P, 
                         vector<int>& ruta) {
    int k = P.at(i).at(j);
    if (k > 0) {
        recuperarIntermedios(i, k, P, ruta);
        ruta.push_back(k);
        recuperarIntermedios(k, j, P, ruta);
    }
}

/**
 * Reconstruye la ruta completa de vértices entre cualquier par (origen, destino).
 *
 * @return vector con los vértices ordenados secuencialmente: [origen, ..., destino].
 *         Retorna un vector vacío si el destino no es alcanzable desde el origen.
 */
template <typename C>
vector<int> reconstruirCaminoFloyd(int origen, int destino,
                                   const unordered_map<int, unordered_map<int, C>>& A,
                                   const unordered_map<int, unordered_map<int, int>>& P) {
    if (A.at(origen).at(destino) == infinito<C>()) {
        return {}; // Inalcanzable
    }

    if (origen == destino) {
        return {origen};
    }

    vector<int> camino;
    camino.push_back(origen);
    recuperarIntermedios(origen, destino, P, camino);
    camino.push_back(destino);
    return camino;
}

// Función para imprimir la matriz de costos mínimos A
template <typename C>
void imprimirMatrizA(const vector<int>& vertices, const unordered_map<int, unordered_map<int, C>>& A) {
    const C INF = infinito<C>();
    cout << "\n--- Matriz A (Distancias Mínimas) ---\n     ";
    for (int j : vertices) {
        cout << setw(6) << j;
    }
    cout << "\n";

    for (int i : vertices) {
        cout << setw(4) << i << ":";
        for (int j : vertices) {
            if (A.at(i).at(j) == INF) {
                cout << setw(6) << "INF";
            } else {
                cout << setw(6) << A.at(i).at(j);
            }
        }
        cout << "\n";
    }
}

// Función para imprimir la matriz de predecesores intermedios P
void imprimirMatrizP(const vector<int>& vertices, const unordered_map<int, unordered_map<int, int>>& P) {
    cout << "\n--- Matriz P (Vértices Intermedios) ---\n     ";
    for (int j : vertices) {
        cout << setw(6) << j;
    }
    cout << "\n";

    for (int i : vertices) {
        cout << setw(4) << i << ":";
        for (int j : vertices) {
            cout << setw(6) << P.at(i).at(j);
        }
        cout << "\n";
    }
}

int main() {
    Grafo<unsigned int> g;

    // Vértices 1 al 5 (el mismo grafo utilizado en la teoría y en Dijkstra)
    for (int i = 1; i <= 5; ++i) {
        g.agregar_vertice(i);
    }

    // Arcos dirigidos con sus costos:
    g.agregar_arco(1, 2, 10);
    g.agregar_arco(1, 4, 30);
    g.agregar_arco(1, 5, 100);
    g.agregar_arco(2, 3, 50);
    g.agregar_arco(3, 5, 10);
    g.agregar_arco(4, 3, 20);
    g.agregar_arco(4, 5, 60);

    unordered_map<int, unordered_map<int, unsigned int>> A;
    unordered_map<int, unordered_map<int, int>> P;

    floyd(g, A, P);

    vector<int> vertices = g.devolver_vertices();
    sort(vertices.begin(), vertices.end()); // Ordenamos para una visualización clara

    cout << "=========================================================" << endl;
    cout << "             ALGORITMO DE FLOYD-WARSHALL                 " << endl;
    cout << "=========================================================" << endl;

    imprimirMatrizA(vertices, A);
    imprimirMatrizP(vertices, P);

    cout << "\n--- Caminos Mínimos Recuperados Entre Todos los Pares ---" << endl;
    for (int i : vertices) {
        for (int j : vertices) {
            if (i != j) {
                cout << i << " -> " << j << ": ";
                if (A[i][j] == infinito<unsigned int>()) {
                    cout << "No existe camino" << endl;
                } else {
                    cout << "Costo = " << setw(3) << A[i][j] << " | Ruta: ";
                    vector<int> ruta = reconstruirCaminoFloyd(i, j, A, P);
                    for (size_t k = 0; k < ruta.size(); ++k) {
                        cout << ruta[k];
                        if (k + 1 < ruta.size()) {
                            cout << " -> ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}
