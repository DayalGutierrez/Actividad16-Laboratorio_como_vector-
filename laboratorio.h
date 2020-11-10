#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio
{
private:
    vector <Computadora> computadoras;
public:
    Laboratorio();
    void agregarFinal(const Computadora &c);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t pos);
    size_t size();
    void inicializar(const Computadora &c, size_t tam);
    void eliminar(size_t pos);
    void ordenar();
    Computadora* buscar(const Computadora &c);
    void borrarUltimo();

    friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c){
        l.agregarFinal(c);

        return l;
    }
};


#endif