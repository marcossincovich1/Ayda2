#include <iostream>
#include <map>
#include <vector>
#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

template <typename C>
void dfs(const Grafo<C> & grafo, map<int, char> colores, int v, bool & r){

  colores[v] = 'G';

  auto adyacentes = grafo.devolver_adyacentes(v);

  for(auto const & arco : adyacentes){

    int destino = arco.devolver_destino();

    if(colores.find(destino)->second == 'B'){
      dfs(grafo, colores, destino, r);
      // si va de gris a blanco es un arco de arbol.
    }else if(colores.find(destino)->second == 'G'){
      r = true;
      return;
      // si va de gris a gris es un arco de retroceso.
    }
    // si va de gris a negro puede ser de avance o de cruce dependiendo los tiempos de finalizacion.
  }

  colores[v] = 'N';
}

template <typename C>
bool buscarCiclo(const Grafo<C> & grafo){

  map<int, char> colores;
  bool result = false;

  vector<int> vertices = grafo.devolver_vertices();

  for(int v : vertices){
    colores[v] = 'B';
  }

  for(int v : vertices){
    if(colores.find(v)->second == 'B'){
      dfs(grafo, colores, v, result);
    }
  }

  return result;
}

int main(){

  Grafo<unsigned int> g5;
    
  g5.agregar_vertice(1);        
  g5.agregar_vertice(2);
  g5.agregar_vertice(3);
  g5.agregar_vertice(4);
  g5.agregar_vertice(5);
  g5.agregar_vertice(6);
  g5.agregar_vertice(7);
  g5.agregar_vertice(8);
  g5.agregar_vertice(9);

  g5.agregar_arco(1, 7, 0);
  g5.agregar_arco(1, 4, 0);
  g5.agregar_arco(1, 3, 0);
  g5.agregar_arco(3, 5, 0);
  g5.agregar_arco(4, 2, 0);
  g5.agregar_arco(5, 1, 0);
  g5.agregar_arco(6, 9, 0);
  g5.agregar_arco(8, 1, 0);

  bool r = buscarCiclo(g5);

  if(r == true){
    printf("El grafo tiene por lo menos un ciclo");  
  }else printf("El grafo no tiene ciclos");  
  
  return 0;
}

template bool buscarCiclo(const Grafo<unsigned int> & grafo);
