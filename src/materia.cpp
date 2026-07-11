#include <iostream>
#include <vector>
#include <fstream>
#include "materia.h"
using namespace std;

void agregarMateria(vector<Materia>& materias){
    cin.ignore();
    Materia m;
    cout << "Ingresa el Nombre de la Materia: ";
    getline(cin, m.nombre);
    cout << "Ingresa la Nota de la Materia: ";
    cin >> m.nota;
    cout << "Ingresa el Tipo de la Materia (Universidad o Colegio): "; 
    cin >> m.tipo;
    if(m.tipo == "Universidad" || m.tipo == "universidad"){
        cout << "Cuantos Creditos tiene la Materia: ";
        cin >> m.creditos;
    }else{
        m.creditos = 0;
    }
    materias.push_back(m);
}
void mostrarMaterias(const vector<Materia>& materias){
    for(const Materia& m : materias){
        if(m.tipo == "Universidad" || m.tipo == "universidad"){
            cout << "Materia: " << m.nombre << " | Nota: " << m.nota
                 << " | Tipo: " << m.tipo << " | Creditos: " << m.creditos << endl;
        } else {
            cout << "Materia: " << m.nombre << " | Nota: " << m.nota
                 << " | Tipo: " << m.tipo << endl;
        }
    }
}
float calcularPromedioSimple(const vector<Materia>& materias){
    float promedio = 0;
    if(materias.size() == 0){
        return 0;
    }
    for(const Materia& m : materias){
        promedio += m.nota;
    }
    return promedio / materias.size();
}
float calcularPromedioPonderado(const vector<Materia>& materias){
    float promedio = 0;
    int creditosTotal = 0;
    if(materias.size() == 0){
        return 0;
    }
    for(const Materia& m : materias){
        promedio += m.nota * m.creditos;
        creditosTotal += m.creditos;
    }
    if(creditosTotal == 0){
        return 0;
    }
    return promedio / creditosTotal;
}
void editarMateria(vector<Materia>& materias){
    for(int i = 0; i < materias.size(); i++){
        cout << materias[i].nombre << endl;
    }
    int indice,op;
    cout << "¿Que Materia deseas Editar?" << endl;
    cin >> indice;
    indice -= 1;
    do{
       cout << "1. Nombre " << endl;
       cout << "2. Nota " << endl;
       cout << "3. Tipo " << endl;
       cout << "4. Creditos " << endl;
       cout << "5. Cancelar " << endl;
       cin >> op;

       switch(op){
        case 1: {
            cin.ignore();
            string newName;
            getline(cin, newName);
            materias[indice].nombre = newName;
            break;
        }
        case 2: {
            float newNote;
            cin >> newNote;
            materias[indice].nota = newNote;
            break;
        }
        case 3: {
            string newTipo;
            cin >> newTipo;
            materias[indice].tipo = newTipo;
            break;
        }
        case 4: {
            int newCredito;
            cin >> newCredito;
            materias[indice].creditos = newCredito;
            break;
        }
        case 5: {
            
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
            break;
       }
    }while(op != 5);
    
}
void eliminarMateria(vector<Materia>& materias){
    for(int i = 0; i < materias.size(); i++){
        cout << materias[i].nombre << endl;
    }
    int indice,op;
    cout << "¿Que Materia deseas Eliminar?" << endl;
    cin >> indice;
    indice -= 1;
    cout << "Confirmas Eliminar esta Materia? (1/0):";
    cin >> op;
    if(op == 1){
        materias.erase(materias.begin() + indice);
        cout << "Se Elimino con Exito";
    }else{
        cout << "No se Elimino la Materia";
    }
    
}
void guardarMaterias(const vector<Materia>& materias){
    ofstream archivo("materias.txt");
    for(const Materia& m : materias){
        archivo << m.nombre << ",";
        archivo << m.nota << ",";
        if(m.tipo == "Universidad" || m.tipo == "universidad"){
            archivo << 1 << ",";
        }else{
            archivo << 0 << ",";
        }
        archivo << m.creditos << ",";
        archivo << m.tipo << endl;
    }
    archivo.close();
}
vector<Materia> cargarMaterias(){
    ifstream archivo("materias.txt");
    vector<Materia> materias;
    string nombre, notaTexto, tipoTexto, creditosTexto, tipoNumTexto;
    while(getline(archivo, nombre, ',')){
        getline(archivo, notaTexto, ',');
        getline(archivo, tipoNumTexto, ',');
        getline(archivo, creditosTexto, ',');
        getline(archivo, tipoTexto, '\n');
        Materia m;
        m.nombre = nombre;
        m.nota = stof(notaTexto);        
        m.creditos = stoi(creditosTexto); 
        m.tipo = tipoTexto;
        materias.push_back(m);
    }
    archivo.close();
    return materias;
}