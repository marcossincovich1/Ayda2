#include <iostream>
#include "Dijkstra.hpp"
#include "../TDAGrafo/HPPs/Grafo.hpp"

 

using namespace std;

int main(){

  Grafo<unsigned int> g14;

  for (int i = 1; i <= 6; i++){
    g14.agregar_vertice(i);
  }

  auto agregarRuta = [&](int u, int v, unsigned int distancia){
    g14.agregar_arco(u, v, distancia);
    g14.agregar_arco(v, u, distancia);
  };

  agregarRuta(1,2,10);
  agregarRuta(1,3,20);
  agregarRuta(1,4,40);
  agregarRuta(1,2,10);
  agregarRuta(1,2,10);
  agregarRuta(1,2,10);
  agregarRuta(1,2,10);
  agregarRuta(1,2,10);
  agregarRuta(1,2,10);

  return 0;
}
