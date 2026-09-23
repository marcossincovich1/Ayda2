#include <iostream> 
#include <stack>                                                                                                                                                               
#include <unordered_map>                                                                                                                                                       
#include "../TDAGrafo/HPPs/Grafo.hpp"                                                                                                                                          
                                                                                                                                                                               
using namespace std;                                                                                                                                                           
                                                                                                                                                                               
// 1. DFS para ordenar por tiempo de finalización                                                                                                                              
template <typename C>                                                                                                                                                          
void dfs1(const Grafo<C>& g, int v, unordered_map<int, bool>& visitados, stack<int>& pila) {                                                                                   
    visitados[v] = true;                                                                                                                                                       
    for (const auto& arco : g.devolver_adyacentes(v)) {                                                                                                                        
        int destino = arco.devolver_destino();                                                                                                                                 
        if (!visitados[destino]) {                                                                                                                                             
            dfs1(g, destino, visitados, pila);                                                                                                                                 
        }                                                                                                                                                                      
    }                                                                                                                                                                          
    pila.push(v); // Se apila al finalizar (postorden)                                                                                                                         

}                                                                                                                                                                              
                                                                                                                                                                               
// 2. Función para obtener el grafo traspuesto                                                                                                                                 
template <typename C>                                                                                                                                                          
Grafo<C> obtenerTraspuesto(const Grafo<C>& g) {                                                                                                                                
    Grafo<C> gt;                                                                                                                                                               
    for (int v : g.devolver_vertices()) {                                                                                                                                      
        gt.agregar_vertice(v);                                                                                                                                                 
    }                                                                                                                                                                          
    for (const auto& arco : g.devolver_arcos()) {                                                                                                                              
        // Se invierte: destino -> origen                                                                                                                                      
        gt.agregar_arco(arco.devolver_destino(), arco.devolver_origen(), arco.devolver_costo());                                                                               
    }                                                                                                                                                                          
    return gt;                                                                                                                                                                 
}                                                                                                                                                                              
                                                                                                                                                                               
// 3. DFS sobre el traspuesto para marcar la componente                                                                                                                        
template <typename C>                                                                                                                                                          
void dfs2(const Grafo<C>& gt, int v, unordered_map<int, bool>& visitados, int comp_id, unordered_map<int, int>& componente_de) {                                               
    visitados[v] = true;                                                                                                                                                       
    componente_de[v] = comp_id;                                                                                                                                                
    for (const auto& arco : gt.devolver_adyacentes(v)) {                                                                                                                       
        int destino = arco.devolver_destino();                                                                                                                                 
        if (!visitados[destino]) {                                                                                                                                             
            dfs2(gt, destino, visitados, comp_id, componente_de);                                                                                                              
        }                                                                                                                                                                      
    }                                                                                                                                                                          
}                                                                                                                                                                              
  
// 4. Algoritmo principal de Kosaraju
template <typename C>
int componentesFuertementeConectadas(const Grafo<C>& g, unordered_map<int, int>& componente_de) {
    stack<int> pila;
    unordered_map<int, bool> visitados;
  
    for (int v : g.devolver_vertices()) {
        visitados[v] = false;
    }
  
    // Paso 1: DFS en G
    for (int v : g.devolver_vertices()) {
        if (!visitados[v]) {
            dfs1(g, v, visitados, pila);
        }
    }
  
    // Paso 2: Construir G^T
    Grafo<C> gt = obtenerTraspuesto(g);
  
    // Reiniciar visitados para G^T
    for (int v : gt.devolver_vertices()) {
        visitados[v] = false;
    }
  
    // Paso 3: DFS en G^T según el orden de la pila
    int cantidad_componentes = 0;
    while (!pila.empty()) {
        int v = pila.top();
        pila.pop();
  
        if (!visitados[v]) {
            cantidad_componentes++;
            dfs2(gt, v, visitados, cantidad_componentes, componente_de);
        }
    }
  
    return cantidad_componentes;
}

int main(){

    Grafo <unsigned int> g11;
    unordered_map <int, int> componenteDe;

    g11.agregar_vertice(1);     
    g11.agregar_vertice(2);     
    g11.agregar_vertice(3);     
    g11.agregar_vertice(4);     
    g11.agregar_vertice(5);     

    g11.agregar_arco(1, 2, 0);    
    g11.agregar_arco(1, 3, 0);    
    g11.agregar_arco(1, 4, 0);    
    g11.agregar_arco(3, 4, 0);    
    g11.agregar_arco(2, 4, 0);    
    g11.agregar_arco(4, 5, 0);
    g11.agregar_arco(4, 1, 0);

    int result = componentesFuertementeConectadas(g11, componenteDe);

    printf("La cantidad de componentes conexa son: %d", result);

    for(const auto & par : componenteDe){        
        cout << "Vertice: " << par.first << " -> Pertenece a la componente: " << par.second << endl;
    }
    
    return 0;   
}




