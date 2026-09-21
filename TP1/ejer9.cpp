#include <iostream>
#include <map>
#include <list>

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

template <typename C>
list<caminosPosibles> caminosAlternativos(const Grafo<C> & grafo, int origen, int destino){
  
}

int main(){

  Grafo<unsigned int> g9;

  g9.agregar_vertice(BSAS);
  g9.agregar_vertice(CAÑUELAS);
  g9.agregar_vertice(LAS_FLORES);
  g9.agregar_vertice(RAUCH);
  g9.agregar_vertice(AZUL);
  g9.agregar_vertice(TANDIL);
  g9.agregar_vertice(AYACUCHO);
  g9.agregar_vertice(SALADILLO);

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
  
  return 0;
}
