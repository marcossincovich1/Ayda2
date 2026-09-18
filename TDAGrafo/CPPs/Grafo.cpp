#include <cassert>
#include "../HPPs/Grafo.hpp"
#include <list>

using namespace std;

/*
 * Arco
 */

template <typename C> Grafo<C>::Arco::Arco()
{
}

template <typename C> Grafo<C>::Arco::Arco(int origen, int destino, const C & costo)
{
    this->origen = origen;
    this->destino = destino;
    this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_origen() const
{
    return origen;
}

template <typename C> int Grafo<C>::Arco::devolver_destino() const
{
    return destino;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
    return costo;
}


/*
 * Grafo
 */


template <typename C> Grafo<C>::Grafo()
{
    cantidad_arcos = 0;
}


template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{
    this->grafo = otroGrafo.grafo;
    this->cantidad_arcos = otroGrafo.cantidad_arcos;
}

template <typename C> Grafo<C>::~Grafo()
{
}


template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
    return *this;
}


template <typename C> bool Grafo<C>::esta_vacio() const
{
    return grafo.empty();
}


template <typename C> int Grafo<C>::cantidad_vertices() const
{
    return grafo.size();
}


template <typename C> int Grafo<C>::cantidadArcos() const
{
    return this->cantidad_arcos;
}


template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
    return grafo.find(vertice) != grafo.end();
}


template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    auto it_origen = grafo.find(origen);
    
    if(it_origen != grafo.end()){

        auto it_destino = it_origen->second.find(destino);

        if(it_destino != it_origen->second.end()) return true;
    }

    return false;
}


template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{
    return grafo.at(origen).at(destino);
}


template <typename C> vector<int> Grafo<C>::devolver_vertices() const
{
    vector<int> vertices;
    vertices.reserve(cantidad_vertices());

    for(auto const& par : grafo){
        vertices.push_back(par.first);
    }

    return vertices;
}


template <typename C> vector<typename Grafo<C>::Arco> Grafo<C>::devolver_adyacentes(int origen) const
{
    auto it = grafo.find(origen);

    vector<typename Grafo<C>::Arco> adyacentes;
    
    if(it == grafo.end()) return adyacentes;

    for(auto const& par : it->second){
        adyacentes.push_back(Arco(origen, par.first, par.second));
    }

    return adyacentes;
}


template <typename C> vector<typename Grafo<C>::Arco> Grafo<C>::devolver_arcos() const
{
    vector<typename Grafo<C>::Arco> arcos;
    arcos.reserve(cantidadArcos());

    for(auto const& par_origen : grafo){
        for(auto const& par_destino : par_origen.second){
            arcos.push_back(Arco(par_origen.first, par_destino.first, par_destino.second));
        }
    }

    return arcos;
}


template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    grafo[vertice];
}

 
template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
    if(existe_vertice(vertice)){
        cantidad_arcos -= grafo.at(vertice).size();
        grafo.erase(vertice);

        for(auto & par : grafo){
            if(par.second.erase(vertice) == 1){
                cantidad_arcos--;
            }
        }
    }
}


template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    assert(existe_arco(origen, destino));

    grafo[origen][destino] = costo;
}


template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
    assert(existe_vertice(origen) && existe_vertice(destino));

    grafo[origen][destino] = costo;
    cantidad_arcos++;
}


template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
    assert(existe_vertice(origen) && existe_vertice(destino));

    if(grafo[origen].erase(destino) == 1){        
        cantidad_arcos--;
    }
    
}


template <typename C> void Grafo<C>::vaciar()
{
    grafo.clear();
    cantidad_arcos = 0;
}

template class Grafo<unsigned int>;
