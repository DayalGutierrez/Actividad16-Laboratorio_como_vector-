#include "laboratorio.h"
#include <fstream>
#include <algorithm>

using namespace std;

Laboratorio::Laboratorio()  {}

void Laboratorio::agregarFinal(const Computadora & c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(12) << "Sistema op";
    cout << setw(12) << "Procesador";
    cout << setw(10) << "GB de RAM" << endl;
    for (size_t i = 0; i < computadoras.size(); i++)
    {
        Computadora &c = computadoras[i];
        cout << c;
        //cout << "Nombre: " << c.getNombre() << endl;
        //cout << "Sistema operativo: " << c.getSistemaOp() << endl;
        //cout << "Procesador: " << c.getProcesador() << endl;
        //cout << "GB de memoria RAM: " << c.getMemoriaRAM() << endl;
    }

    
    
}

void Laboratorio::respaldar_tabla()
{
    ofstream archivo("Computadoras_tabla.txt");
    if (archivo.is_open()){
        archivo << left;
        archivo << setw(12) << "Nombre";
        archivo << setw(12) << "Sistema op";
        archivo << setw(12) << "Procesador";
        archivo << setw(10) << "GB de RAM" << endl;
        for (size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar()
{
    ofstream archivo("Computadoras.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c.getNombre() << endl;
            archivo << c.getSistemaOp() << endl;
            archivo << c.getProcesador() << endl;
            archivo << c.getMemoriaRAM() << endl;
            
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){
    ifstream archivo("Computadoras.txt");
    if (archivo.is_open()){
        string temp;
        int GB;
        Computadora c;

        while (true)
        {
            getline(archivo, temp);
            if (archivo.eof()){
                break;
            }
            c.setNombre(temp);

            getline(archivo, temp);
            c.setSistemaOp(temp);

            getline(archivo, temp);
            c.setProcesador(temp);

            getline(archivo, temp);
            GB = stoi(temp);
            c.setMemoriaRAM(GB);

            agregarFinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos){
    computadoras.insert(computadoras.begin() + pos, c);
}

size_t Laboratorio::size(){
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t tam){
    computadoras = vector<Computadora>(tam, c);
}

void Laboratorio::eliminar(size_t pos){
    computadoras.erase(computadoras.begin()+pos);
}

void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c){
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }    
}

void Laboratorio::borrarUltimo(){
    computadoras.pop_back();
}