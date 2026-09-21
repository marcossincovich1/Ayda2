#include <iostream>
#include <list>
#include <map>

#include "../TDAGrafoDFS/Algoritmos.hpp"

using namespace std;

template<typename C>
bool dfs_existe_camino(const Grafo<C> & grafo, int origen, int destino, map<int, bool> & visitados, int longitud){
  
  // No se puede seguir avansando porque la longitud dada no me lo perminte
  if(longitud == 0){
    
    return (origen == destino);
    
  }

  visitados[origen] = true;
  
  auto adyacentes = grafo.devolver_adyacentes(origen);

  for(auto const & arco : adyacentes){
    
    int adyacente = arco.devolver_destino();
  
    if(!visitados[adyacente]){
      if (dfs_existe_camino(grafo, adyacente, destino, visitados, longitud - 1)) {                                                                                  
  	   visitados[origen] = false; // Desmarcamos antes de salir                                                                                                       
  	   return true;               // ¡Encontramos uno! Cortamos de inmediato                                                                                          
  	  }  
    }
  }
  visitados[origen] = false;                                                                                                                                             
  return false;   
}

template<typename C>
list<int> listaCaminos(const Grafo<C> & grafo, int destino, int longitud){

  list<int> result;
  vector<int> vertices = grafo.devolver_vertices();
  
  for(int v : vertices){

    map<int, bool> visitados;
    
    for(int u : vertices){
      visitados[u] = false;
    }

    if(dfs_existe_camino(grafo, v, destino, visitados, longitud)){
      result.push_back(v);
    }
  }
  return result;
}

int main(){

  Grafo<unsigned int> g8;
  
    for (int i = 1; i <= 5; i++) {
      g8.agregar_vertice(i);
    }
  
    // 1 -> 2 -> 3 -> 5 (camino de longitud 3 de 1 a 5)
    // 4 -> 3 -> 5      (camino de longitud 2 de 4 a 5)
    g8.agregar_arco(1, 2, 0);
    g8.agregar_arco(2, 3, 0);
    g8.agregar_arco(3, 5, 0);
    g8.agregar_arco(4, 3, 0);
  
    // Vértices con camino de longitud 2 hacia el vértice 5
    // Deberían ser el 2 (2 -> 3 -> 5) y el 4 (4 -> 3 -> 5)
    auto vertices = listaCaminos(g8, 5, 2);
  
    cout << "Vertices con camino de longitud 2 al vertice 5:" << endl;
    for(int v : vertices){
      cout << v << endl;
    }
    
    return 0;
}
