#include <iostream>
#include <vector>
#include <unordered_map>
#include "Floyd.hpp"
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

/**
 * Ejercicio 13:
 * Encuentra la ciudad más cercana a todas las demás (centro / mediana del grafo),
 * minimizando la suma total de distancias hacia el resto de las ciudades.
 *
 * @param g Grafo con el mapa carretero y distancias (pesos no negativos).
 * @return El id del vértice elegido como nueva capital, o -1 si el grafo está vacío/desconectado.
 */
template <typename C>
int encontrarCapital(const Grafo<C>& g) {
    unordered_map<int, unordered_map<int, C>> A;
    unordered_map<int, unordered_map<int, int>> P;

    // Calculamos distancias mínimas entre todos los pares usando Floyd-Warshall
    floyd(g, A, P);

    vector<int> vertices = g.devolver_vertices();
    if (vertices.empty()) return -1;

    const C INF = floyd_infinito<C>();
    int mejorCiudad = -1;
    C menorSumaDistancias = INF;

    // Evaluamos cada ciudad como candidata
    for (int i : vertices) {
        C sumaActual = 0;
        bool alcanzaATodas = true;

        for (int j : vertices) {
            if (i != j) {
                if (A[i][j] == INF) {
                    alcanzaATodas = false; // No puede llegar a j
                    break;
                }
                sumaActual += A[i][j];
            }
        }

        // Si conecta con todas y la suma es mejor que la anterior, actualizamos
        if (alcanzaATodas && sumaActual < menorSumaDistancias) {
            menorSumaDistancias = sumaActual;
            mejorCiudad = i;
        }
    }

    return mejorCiudad;
}

int main() {
    // Grafo no dirigido para rutas bidireccionales
    Grafo<unsigned int> mapaCarretero;

    for (int i = 1; i <= 5; ++i) {
        mapaCarretero.agregar_vertice(i);
    }

    // Definición de tramos de ruta (bidireccionales)
    auto agregarRuta = [&](int u, int v, unsigned int distancia) {
        mapaCarretero.agregar_arco(u, v, distancia);
        mapaCarretero.agregar_arco(v, u, distancia);
    };

    agregarRuta(1, 2, 10);
    agregarRuta(1, 3, 40);
    agregarRuta(2, 4, 20);
    agregarRuta(1, 5, 20);
    agregarRuta(3, 4, 30);
    agregarRuta(2, 5, 20);
    agregarRuta(3, 5, 20);
    agregarRuta(4, 5, 20);

    int capital = encontrarCapital(mapaCarretero);

    cout << "=== EJERCICIO 13 ===" << endl;
    if (capital != -1) {
        cout << "La ciudad elegida para trasladar la Capital es: " << capital << endl;
    } else {
        cout << "No fue posible determinar una capital (grafo desconectado o vacio)." << endl;
    }

    return 0;
}
