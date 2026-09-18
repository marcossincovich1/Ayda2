#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include"../TDAGrafo/HPPs/Grafo.hpp"
using namespace std;

template <typename C>
void dfs(const Grafo<C> & grafo, int v, map<int, char> & colores, vector<int> & result){
    
    String cooler = ""
    colores[v] = 'G';

    auto adyacentes = grafo.devolver_adyacentes(v);

    for(auto const & arco : adyacentes){
        int destino = arco.devolver_destino();

        if(colores.find(destino)->second == 'B'){
            dfs(grafo, destino, colores, result);
        }
    }
    colores[v] = 'N';
    result.push_back(v);
}

template <typename C>
vector<int> orden_topologico(const Grafo<C> & grafo){

    map<int, char> colores;

    vector<int> result;
    vector<int> vertices = grafo.devolver_vertices();

    for(int v : vertices){
        colores[v] = 'B';                    
    }
     
    for(int v : vertices){
        if(colores.find(v)->second == 'B'){
            dfs(grafo, v, colores, result);
        }
    }

    reverse(result.begin(), result.end());
    
    return result;    
}

int main(){

    Grafo<unsigned int> g4;

    g4.agregar_vertice(1);        
    g4.agregar_vertice(2);
    g4.agregar_vertice(3);
    g4.agregar_vertice(4);
    g4.agregar_vertice(5);
    g4.agregar_vertice(6);
    g4.agregar_vertice(7);
    g4.agregar_vertice(8);
    g4.agregar_vertice(9);

    g4.agregar_arco(1, 7, 0);
    g4.agregar_arco(1, 4, 0);
    g4.agregar_arco(3, 5, 0);
    g4.agregar_arco(4, 2, 0);
    g4.agregar_arco(5, 1, 0);
    g4.agregar_arco(6, 9, 0);
    g4.agregar_arco(8, 1, 0);

    vector secuencia_v = orden_topologico(g4);

    for(int const & v : secuencia_v){
        printf("vertice: %d \n", v);
    }
        
    return 0;
}

template vector<int> orden_topologico(const Grafo<unsigned int> & grafo); 
