#include <iostream>
#include "menu.h"
#include "materia.h"
using namespace std;

void menu(){
    int option;
    cin >> option;
    do{
        cout << "Bienvenido al Gestor de Notas"<< endl;
        cout << "Que deseas hacer: " << endl;
        cout << "1. Agregar Materia" << endl;
        cout << "2. Mostrar Materias" << endl;
        cout << "3. Calcular Promedio Simple" << endl;
        cout << "4. Calcular Promedio Ponderado (creditos)" << endl;
        cout << "5. Editar Materia" << endl;
        cout << "6. Eliminar Materia" << endl;
        cout << "7. Guardar y Salir" << endl;
        
        switch(option){
            case 1:
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
        }
        
    }while(option != 7);
}