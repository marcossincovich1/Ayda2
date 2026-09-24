#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Grafo.hpp"
#include <ostream>
#include <map>

template <typename C>
class Dijkstra
{
    public:

    class Solucion {
        public:
            Solucion();
            Solucion(std::map<int, int> & distancias, std::map<int,int> & predecesores);
            virtual ~Solucion();

            const std::map<int, int> & obtener_distancias() const;
            const std::map<int, int> & obtener_predecesores() const;
        private:
            std::map<int, int> distancias;
            std::map<int, int> predecesores;

        friend std::ostream & operator << (std::ostream & salida, const Solucion & solucion) {
            salida << "Solucion Dijkstra" << std::endl;
            salida << "Distancias" << std::endl;

            std::map<int, int> distancias = solucion.obtener_distancias();
            std::map<int, int>::const_iterator it = distancias.begin();
            while (it != distancias.end()) {
                salida << "|"<< it->first << "|";
                it++;
            }
            salida << std::endl;

            it = distancias.begin();
            while (it != distancias.end()) {
                salida << "|"<< it->second << "|";
                it++;
            }
            salida << std::endl << std::endl;

            salida << "Predecesores" << std::endl;

            std::map<int, int> predecesores = solucion.obtener_predecesores();
            std::map<int, int>::const_iterator itP = predecesores.begin();
            while (itP != predecesores.end()) {
                salida << "|"<< itP->first << "|";
                itP++;
            }
            salida << std::endl;

            itP = predecesores.begin();
            while (itP != predecesores.end()) {
                salida << "|"<< itP->second << "|";
                itP++;
            }
            salida << std::endl;

            return salida;
        }
    };

    public:
        Dijkstra(const Grafo<C> & g);
        virtual ~Dijkstra();

        Solucion resolver(int origen);

    protected:

    private:
        const Grafo<C> & grafo;
};

#endif // DIJKSTRA_HPP
