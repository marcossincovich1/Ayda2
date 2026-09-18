#include <iostream>
#include <map>
#include <list>
#include <vector>

#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

template <typename C>
struct caminoCosto {
  list<int> ruta;
  C costo;
};

template <typename C>
void caminos_simples(const Grafo<C> & grafo, int origen, int destino, C costoActual, map<int,bool> & visitados, list<int> & camActual, list<caminoCosto<C>> & caminos){

  visitados[origen] = true;
  camActual.push_back(origen);
  
  auto adyacentes = grafo.devolver_adyacentes(origen);

  if(origen == destino){
    caminoCosto<C> camino;
    camino.ruta = camActual;
    camino.costo = costoActual;
    caminos.push_back(camino);
  } else {
    for(const auto arco : adyacentes){
      int adyacente = arco.devolver_destino(); 
      C costoArco = arco.devolver_costo();
        
      if(!visitados[adyacente]){
        caminos_simples(grafo, adyacente, destino, costoArco + costoActual, visitados, camActual, caminos);
      }
    }    
  }
  camActual.pop_back();
  visitados[origen] = false;
}


template <typename C>
list<caminoCosto<C>> backtracking(const Grafo<C> & grafo, int origen, int destino){

  map<int, bool> visitados;
  vector<int> vertices = grafo.devolver_vertices();
  list<int> camActual;
  list<caminoCosto<C>> caminos;
  
  for(int v : vertices){
    visitados[v] = false;
  }

  caminos_simples(grafo, origen, destino, C(0), visitados, camActual, caminos);

  return caminos;
}

int main(){

  Grafo <unsigned int> g6;
    
  g6.agregar_vertice(1);        
  g6.agregar_vertice(2);
  g6.agregar_vertice(3);
  g6.agregar_vertice(4);
  g6.agregar_vertice(5);
  g6.agregar_vertice(6);
  g6.agregar_vertice(7);
  g6.agregar_vertice(8);

  g6.agregar_arco(1, 7, 1);
  g6.agregar_arco(1, 4, 2);
  g6.agregar_arco(4, 7, 2);
  g6.agregar_arco(2, 7, 2);
  g6.agregar_arco(3, 5, 4);
  g6.agregar_arco(4, 2, 5);
  g6.agregar_arco(5, 1, 6);
  g6.agregar_arco(8, 1, 8); 

  auto caminos = backtracking(g6, 1, 7);

  for(const auto& c : caminos) {
      cout << "Camino: ";
      for(int v : c.ruta) {
          cout << v << " ";
      }
      cout << "| Costo: " << c.costo << endl;
  }
  
  return 0;
}
