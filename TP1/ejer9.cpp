#include <iostream>
#include <map>
#include <list>
#include <string>

#include "../TDAGrafo/HPPs/Grafo.hpp"

using namespace std;

enum Ciudades {
     BSAS,        
     CAÑUELAS,    
     LAS_FLORES,  
     RAUCH,       
     AZUL,        
     TANDIL,
     AYACUCHO,
     SALADILLO        
};

struct caminosPosibles{
  list<int> camino;
};

bool esTramoCortado(int origen, int destino, int cortado1, int cortado2){
  return (origen == cortado1 && destino == cortado2) || (destino == cortado1 && origen == cortado2);
}

template <typename C>
void  dfs(const Grafo<C> & grafo, int origen, int destino, int corte1, int corte2, map<int, bool> &  visitados, list<int> & camActual, list<caminosPosibles> & caminos){

  visitados[origen] = true;
  camActual.push_back(origen);

  if(origen == destino){
    
    caminosPosibles ruta;
    ruta.camino = camActual;
    caminos.push_back(ruta);
    
  }else{

    auto adyacentes = grafo.devolver_adyacentes(origen);
    for(const auto arco : adyacentes){
      int adyacente = arco.devolver_destino();

      if((!visitados[adyacente]) && !esTramoCortado(origen, adyacente, corte1, corte2)){
        dfs(grafo, adyacente, destino, corte1, corte2, visitados, camActual, caminos);
      }
    }
  }

  camActual.pop_back();
  visitados[origen] = false; 
}

template <typename C>
list<caminosPosibles> caminosAlternativos(const Grafo<C> & grafo, int corte1, int corte2, int origen, int destino){

  map<int, bool> visitados;
  vector<int> vertices = grafo.devolver_vertices();
  list<caminosPosibles> caminos;
  list<int> camActual;

  for(int v : vertices){
    visitados[v] = false;
  }

  dfs(grafo, origen, destino, corte1, corte2, visitados, camActual, caminos);

  return caminos; 
}

int main(){

  Grafo<unsigned int> g9;

  const vector<string> nombreCiudad = {    
     "BSAS",        
     "CAÑUELAS",    
     "LAS_FLORES",  
     "RAUCH",       
     "AZUL",        
     "TANDIL",
     "AYACUCHO",
     "SALADILLO"
  };

  g9.agregar_vertice(BSAS);
  g9.agregar_vertice(CAÑUELAS);
  g9.agregar_vertice(LAS_FLORES);
  g9.agregar_vertice(RAUCH);
  g9.agregar_vertice(AZUL);
  g9.agregar_vertice(TANDIL);
  g9.agregar_vertice(AYACUCHO);
  g9.agregar_vertice(SALADILLO);

  g9.agregar_arco(BSAS, CAÑUELAS, 0);
  g9.agregar_arco(CAÑUELAS, BSAS, 0);
  g9.agregar_arco(TANDIL, AZUL, 0);
  g9.agregar_arco(AZUL, TANDIL, 0);
  g9.agregar_arco(TANDIL, RAUCH, 0);
  g9.agregar_arco(RAUCH, TANDIL, 0);
  g9.agregar_arco(TANDIL, AYACUCHO, 0);
  g9.agregar_arco(AYACUCHO, TANDIL, 0);
  g9.agregar_arco(AZUL, SALADILLO, 0);
  g9.agregar_arco(SALADILLO, AZUL, 0);
  g9.agregar_arco(RAUCH, LAS_FLORES, 0);
  g9.agregar_arco(LAS_FLORES, RAUCH, 0);
  g9.agregar_arco(AYACUCHO, CAÑUELAS, 0);
  g9.agregar_arco(CAÑUELAS, AYACUCHO, 0);
  g9.agregar_arco(SALADILLO, CAÑUELAS, 0);
  g9.agregar_arco(CAÑUELAS, SALADILLO, 0);
  g9.agregar_arco(LAS_FLORES, CAÑUELAS, 0);
  g9.agregar_arco(CAÑUELAS, LAS_FLORES, 0);

  int corte1 = LAS_FLORES, corte2 = RAUCH;

  auto result = caminosAlternativos(g9, corte1, corte2, BSAS, TANDIL);

  for(const auto & c : result){
    printf("Camino: ");
    for(int v : c.camino){
      printf("%s", nombreCiudad[v].c_str());
      if(v != c.camino.back()){
        printf(" -> ");
      }
    }
    printf("\n");
  }
    
  return 0;
}
