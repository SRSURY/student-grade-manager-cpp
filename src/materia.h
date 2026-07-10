#ifndef MATERIA_H
#define MATERIA_H
#include <vector>
#include <string>
using namespace std;
struct Materia  {
    string nombre;
    float nota;
    string tipo;
    int creditos;
};
void agregarMateria(vector<Materia>& materias);
void mostrarMaterias(const vector<Materia>& materias);
float calcularPromedioSimple(const vector<Materia>& materias);
float calcularPromedioPonderado(const vector<Materia>& materias);
void editarMateria(vector<Materia>& materias);
void eliminarMateria(vector<Materia>& materias);
void guardarMaterias(const vector<Materia>& materias);
vector<Materia> cargarMaterias();
#endif