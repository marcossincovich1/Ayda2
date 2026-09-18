#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <vector>
#include <unordered_map>
using namespace std;

template <typename C> class Grafo
{
public:
    /**
     * Representa un arco en un grafo dirigido.
     * Se define como una clase inmutable (no puede ser modificada).
    **/
	class Arco
	{
	public:
		Arco();
		Arco(int origen, int destino, const C & costo);
		int devolver_origen() const;
		int devolver_destino() const;
		const C & devolver_costo() const;
	private:
		int origen;
		int destino;
		C costo;
	}; // class Arco

public:
	// NOTA: Dependiendo de la implementaci�n puede ser necesario incluir otras funciones constructuras
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de v�rtices es cero
	bool esta_vacio() const;

	int cantidad_vertices() const;
	int cantidadArcos() const;

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const C & costo_arco(int origen, int destino) const;

	//A partir de la versi�n C++11 con RVO no se copian los elementos
	//se construyen directamente en el lugar de la memoria de la variable
	//que espera el retorno.
	vector<int> devolver_vertices() const;

	vector<Arco> devolver_adyacentes(int origen) const;

  vector<Arco> devolver_arcos() const;

	void agregar_vertice(int vertice);

	// POST CONDICION: Para todo v�rtice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(int origen, int destino, const C & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(int origen, int destino, const C & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	void vaciar();

private:

	 unordered_map<int, unordered_map<int, C>> grafo;	
	
	 int cantidad_arcos;
};

#endif // GRAFO_HPP
