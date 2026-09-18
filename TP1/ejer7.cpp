#include <iostream>
#include <list>
#include <algorithm>
#include <map>

#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

template <typename C>
bool dfs(const Grafo<C> & grafo, map<int, bool> & visitados, map<int, char> & colores, int origen, int destino, list<int> & camino_result){

  if(colores[origen] == 'R'){ return false;}

  visitados[origen] = true;
  camino_result.push_back(origen);

  auto adyacentes = grafo.devolver_adyacentes(origen);

  if(origen == destino){ return true;}
  
  for(auto const & arco : adyacentes){

    int adyacente = arco.devolver_destino();

    if(!visitados[adyacente] && colores.find(destino)->second != 'R'){
      if(dfs(grafo, visitados, colores, adyacente, destino, camino_result)){return true; }
    }
  }
  camino_result.pop_back();
  return false;   
}

template<typename C>
list<int> camino(const Grafo<C> & grafo, int v1, int v2, list<int> vertices_rojos){

  list<int> result;
  map<int, char> colores;
  vector<int> vertices = grafo.devolver_vertices(); 
  map<int, bool> visitados;
  
  for(int v : vertices){
    
    auto it = find(vertices_rojos.begin(), vertices_rojos.end(), v);
      
    if(it != vertices_rojos.end()){
        colores[v] = 'R';
    }else{
       colores[v] = 'V';
    }
    visitados[v] = false;
  }

  if(colores.find(v1)->second != 'R' && colores.find(v2)->second != 'R'){
    dfs(grafo, visitados, colores, v1, v2, result);
  }
  
  return result;  
}

int main(){

  Grafo<unsigned int> g7;
  list<int> vertices_rojos;
  
  g7.agregar_vertice(1);        
  g7.agregar_vertice(2);
  g7.agregar_vertice(3);
  g7.agregar_vertice(4);
  g7.agregar_vertice(5);

  g7.agregar_arco(1, 2, 0);
  g7.agregar_arco(1, 3, 0);
  g7.agregar_arco(2, 4, 0);
  g7.agregar_arco(3, 5, 0);
  g7.agregar_arco(5, 4, 0);

  vertices_rojos.push_back(2);

  auto result = camino(g7, 1, 4, vertices_rojos);

  for(int v : result){
    printf("%d \n", v);
  }
   
  return 0;
}
