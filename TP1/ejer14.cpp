#include <iostream>
#include <list>
#include <algorithm>
#include "Dijkstra.hpp"
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

int main(){

  Grafo<unsigned int> g14;

  int puerto = 7;
  vector<int> ciudades;

  for (int i = 1; i <= 7; i++){
    g14.agregar_vertice(i);
    if (i != puerto) {
      ciudades.push_back(i);
    }
  }

  auto agregarRuta = [&](int u, int v, unsigned int distancia){
    g14.agregar_arco(u, v, distancia);
    g14.agregar_arco(v, u, distancia);
  };
  
  agregarRuta(1,2,10);
  agregarRuta(1,3,20);
  agregarRuta(1,4,40);
  agregarRuta(3,4,50);
  agregarRuta(4,5,60);
  agregarRuta(4,6,70);
  agregarRuta(6,5,30);

  // El vertice 7 es el puerto entonces el camino al puerto tendria que ser pasando por el vertice 4 o el 6.
  agregarRuta(4,7,20);
  agregarRuta(6,7,40);

  unordered_map<int, unsigned int> distancias;
  unordered_map<int, int> predecesores;

  // ejecuto dijkstra desde el puerto
  dijkstra(g14, puerto, distancias, predecesores);

  list<vector<int>> caminosAlPuerto;

  for(int ciudad : ciudades){

    vector<int> camino = reconstruirCaminoDijkstra(puerto, ciudad, predecesores);

    reverse(camino.begin(), camino.end());
    caminosAlPuerto.push_back(camino);
  }

  cout << "--- Rutas minimas hacia el puerto (" << puerto << ") ---" << endl;
  for (const auto& camino : caminosAlPuerto) {
      cout << "Ruta: ";
      for (size_t i = 0; i < camino.size(); ++i) {
          cout << camino[i] << (i + 1 < camino.size() ? " -> " : "");
      }
      cout << " (Costo total: " << distancias[camino.front()] << ")\n";
  }
    
  return 0;
}
