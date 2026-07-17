#include <iostream>
#include <vector>
#include <iomanip>
#include "menu.h"
#include "materia.h"
#include "tools.h"
using namespace std;

void menu(){
    int option;
    
    vector<Materia> materias;
    materias = cargarMaterias();
    do{
        cout << "\nBienvenido al Gestor de Notas"<< endl;
        cout << "Que deseas hacer: " << endl;
        cout << "1. Agregar Materia" << endl;
        cout << "2. Mostrar Materias" << endl;
        cout << "3. Calcular Promedio Simple" << endl;
        cout << "4. Calcular Promedio Ponderado (creditos)" << endl;
        cout << "5. Editar Materia" << endl;
        cout << "6. Eliminar Materia" << endl;
        cout << "7. Guardar y Salir" << endl;
        validarEntradaEntero(option);
        switch(option){
            case 1:
                agregarMateria(materias);
                break;
            case 2:
                mostrarMaterias(materias);
                break;
            case 3:
                if(materias.size() == 0){
                    cout << "No hay materias agregadas aun.\n";
                }else{
                    cout << "El Promedio es: " << setprecision(2) << calcularPromedioSimple(materias) << endl;
                }
                
                break;
            case 4:
                if(materias.size() == 0){
                    cout << "No hay materias agregadas aun.\n";
                }else{
                    cout <<  "El Promedio es: " << setprecision(2) << calcularPromedioPonderado(materias) << endl;
                }
                break;
            case 5:
                editarMateria(materias);
                break;
            case 6:
                eliminarMateria(materias);
                break;
            case 7:
                guardarMaterias(materias);
                break;
            default: 
                cout << "Error KaseO.\n";
        }
        
    }while(option != 7);
}