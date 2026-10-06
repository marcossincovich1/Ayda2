#ifndef FLOYD_HPP
#define FLOYD_HPP

#include <vector>
#include <unordered_map>
#include <limits>
#include <iomanip>
#include <iostream>
#include "../TDAGrafo/HPPs/Grafo.hpp"

// Función auxiliar para representar infinito de forma segura para cualquier tipo C
template <typename C>
C floyd_infinito() {
    return std::numeric_limits<C>::max();
}

/**
 * Algoritmo de Floyd-Warshall para encontrar los caminos más cortos entre
 * TODOS los pares de vértices de un grafo.
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
           std::unordered_map<int, std::unordered_map<int, C>>& A, 
           std::unordered_map<int, std::unordered_map<int, int>>& P) {
    
    const C INF = floyd_infinito<C>();
    std::vector<int> vertices = g.devolver_vertices();

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
            P[i][j] = 0;
        }
    }

    // Bucle triple de Floyd:
    // k es el vértice pivote (posible vértice intermedio)
    for (int k : vertices) {
        for (int i : vertices) {
            for (int j : vertices) {
                if (A[i][k] != INF && A[k][j] != INF) {
                    if (A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                        P[i][j] = k;
                    }
                }
            }
        }
    }
}

/**
 * Función auxiliar recursiva para recuperar vértices intermedios a partir de la matriz P.
 */
inline void recuperarIntermedios(int i, int j, 
                                const std::unordered_map<int, std::unordered_map<int, int>>& P, 
                                std::vector<int>& ruta) {
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
std::vector<int> reconstruirCaminoFloyd(int origen, int destino,
                                        const std::unordered_map<int, std::unordered_map<int, C>>& A,
                                        const std::unordered_map<int, std::unordered_map<int, int>>& P) {
    if (A.at(origen).at(destino) == floyd_infinito<C>()) {
        return {}; // Inalcanzable
    }

    if (origen == destino) {
        return {origen};
    }

    std::vector<int> camino;
    camino.push_back(origen);
    recuperarIntermedios(origen, destino, P, camino);
    camino.push_back(destino);
    return camino;
}

// Función para imprimir la matriz de costos mínimos A
template <typename C>
void imprimirMatrizA(const std::vector<int>& vertices, const std::unordered_map<int, std::unordered_map<int, C>>& A) {
    const C INF = floyd_infinito<C>();
    std::cout << "\n--- Matriz A (Distancias Mínimas) ---\n     ";
    for (int j : vertices) {
        std::cout << std::setw(6) << j;
    }
    std::cout << "\n";

    for (int i : vertices) {
        std::cout << std::setw(4) << i << ":";
        for (int j : vertices) {
            if (A.at(i).at(j) == INF) {
                std::cout << std::setw(6) << "INF";
            } else {
                std::cout << std::setw(6) << A.at(i).at(j);
            }
        }
        std::cout << "\n";
    }
}

// Función para imprimir la matriz de predecesores intermedios P
inline void imprimirMatrizP(const std::vector<int>& vertices, const std::unordered_map<int, std::unordered_map<int, int>>& P) {
    std::cout << "\n--- Matriz P (Vértices Intermedios) ---\n     ";
    for (int j : vertices) {
        std::cout << std::setw(6) << j;
    }
    std::cout << "\n";

    for (int i : vertices) {
        std::cout << std::setw(4) << i << ":";
        for (int j : vertices) {
            std::cout << std::setw(6) << P.at(i).at(j);
        }
        std::cout << "\n";
    }
}

#endif // FLOYD_HPP
