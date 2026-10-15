#include <cstdio>
#include <iostream>
#include <map>
#include <list>

#include "Dijkstra.hpp"
#include "../TDAGrafo/HPPs/Grafo.hpp"
 
using namespace std;

enum Ciudades {
     BSAS,        
     GRAL_BELGRANO,    
     LAS_FLORES,  
     RAUCH,       
     AZUL,        
     TANDIL,
     AYACUCHO,
     SALADILLO        
};

template <typename C> // preguntar que es mejor si sacarle el const y hacer esto o modificar dijkstra?
vector<int> caminoMasCorto(Grafo<C> & grafo, int origen, int destino, int corte1, int corte2){

  bool existeArco = grafo.existe_arco(corte1, corte2);
  C costoOriginal;
  
  if(existeArco){
    costoOriginal = grafo.costo_arco(corte1, corte2);
    grafo.eliminar_arco(corte1, corte2);
    grafo.eliminar_arco(corte2, corte1);
  }

  unordered_map<int, int> predecesores;
  unordered_map<int, C> distancias;
  
  dijkstra(grafo, origen, distancias, predecesores);

  if(existeArco){
    grafo.agregar_arco(corte1, corte2, costoOriginal);
    grafo.agregar_arco(corte2, corte1, costoOriginal);
  }

  return reconstruirCaminoDijkstra(origen, destino, predecesores);  
}

int main(){

  Grafo<unsigned int> g15;
  
  int origen = TANDIL;
  int destino = BSAS;
  int corte1 = LAS_FLORES, corte2 = RAUCH;
    
  for(int i = 0; i <= 7; i ++){
    g15.agregar_vertice(i);
  }

  auto agregarRuta = [&] (int u, int v, unsigned int distancia){
    g15.agregar_arco(u, v, distancia);
    g15.agregar_arco(v, u, distancia);
  };
  
  agregarRuta(BSAS, LAS_FLORES, 10);
  agregarRuta(BSAS, SALADILLO, 40);
  agregarRuta(BSAS, GRAL_BELGRANO, 20);
  agregarRuta(SALADILLO, AZUL, 20);
  agregarRuta(LAS_FLORES, RAUCH, 30);
  agregarRuta(GRAL_BELGRANO, AYACUCHO, 20);
  agregarRuta(AZUL, TANDIL, 50);
  agregarRuta(RAUCH, TANDIL, 20);
  agregarRuta(AYACUCHO, TANDIL, 20);

  vector<int> camino = caminoMasCorto(g15, origen, destino, corte1, corte2);

  printf("El camino mas corto es: \n");
  
  for(int vertice : camino){
    printf("%d", vertice);
    if(vertice != camino.back()) printf(" -> ");  
  }
  
  return 0;
}
