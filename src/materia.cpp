#include <iostream>
#include <vector>
#include <fstream>
#include "materia.h"
#include "tools.h"
using namespace std;

void agregarMateria(vector<Materia>& materias){
    cin.ignore();
    Materia m;
    cout << "Ingresa el Nombre de la Materia: ";
    getline(cin, m.nombre);
    cout << "Ingresa la Nota de la Materia: ";
    validarEntradaDecimal(m.nota);
    validarNota(m.nota);
    cout << "Ingresa el Tipo de la Materia (Universidad o Colegio): "; 
    cin.ignore();
    getline(cin, m.tipo);
    validarTextoTipo(m.tipo);
    if(m.tipo == "universidad"){
        cout << "Cuantos Creditos tiene la Materia: ";
        validarEntradaEntero(m.creditos);
        validarCreditos(m.creditos);
    }else{
        m.creditos = 0;
    }
    materias.push_back(m);
    guardarMaterias(materias);
}
void mostrarMaterias(const vector<Materia>& materias){
    for(const Materia& m : materias){
        if(m.tipo == "universidad"){
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
        return 0.0;
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
        return 0.0;
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
    if(materias.size() == 0){
        cout << "No hay ninguna materia agregada.\n";
        return;
    }
    for(int i = 0; i < materias.size(); i++){
        cout << i+1 <<". " << materias[i].nombre << endl;
    }
    int indice,op;
    cout << "¿Que Materia deseas Editar?" << endl;
    validarEntradaEntero(indice);
    validarIndice(indice,materias);
    indice -= 1;
    do{
       cout << "1. Nombre " << endl;
       cout << "2. Nota " << endl;
       cout << "3. Tipo " << endl;
       cout << "4. Creditos " << endl;
       cout << "5. Cancelar " << endl;
       validarEntradaEntero(op);

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
            validarEntradaDecimal(newNote);
            validarNota(newNote);
            materias[indice].nota = newNote;
            break;
        }
        case 3: {
            cin.ignore();
            string newTipo;
            getline(cin, newTipo);
            validarTextoTipo(newTipo);
            materias[indice].tipo = newTipo;
            if(newTipo == "universidad"){
                cout << "Ingresar creditos de la nueva materia: ";
                int nuevosCreditos;
                validarEntradaEntero(nuevosCreditos);
                validarCreditos(nuevosCreditos);
                materias[indice].creditos = nuevosCreditos;
            }else{
                materias[indice].creditos = 0;
            }
            break;
        }
        case 4: {
            int newCredito;
            validarEntradaEntero(newCredito);
            validarCreditos(newCredito);
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
    guardarMaterias(materias);
}
void eliminarMateria(vector<Materia>& materias){
    if(materias.size() == 0){
        cout << "No hay ninguna materia agregada.\n";
        return;
    }
    for(int i = 0; i < materias.size(); i++){
        cout << i+1 <<". " << materias[i].nombre << endl;
    }
    int indice,op;
    cout << "¿Que Materia deseas Eliminar?" << endl;
    validarEntradaEntero(indice);
    validarIndice(indice,materias);
    indice -= 1;
    cout << "Confirmas Eliminar esta Materia? (1/0): ";
    validarEntradaEntero(op);
    if(op == 1){
        materias.erase(materias.begin() + indice);
        cout << "Se Elimino con Exito\n";
    }else{
        cout << "No se Elimino la Materia\n";
    }
    guardarMaterias(materias);
}
void guardarMaterias(const vector<Materia>& materias){
    ofstream archivo("materias.txt");
    if(!archivo){
        cout << "El archivo no se abrio correctamente\n";
        return;
    }
    for(const Materia& m : materias){
        archivo << m.nombre << ",";
        archivo << m.nota << ",";
        if(m.tipo == "universidad"){
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
    if(!archivo){
        cout << "No hay historial previo, empezando de cero.\n";
        return vector<Materia>();
    }
    vector<Materia> materias;
    string nombre, notaTexto, tipoTexto, creditosTexto, tipoNumTexto;
    while(getline(archivo, nombre, ',')){
        getline(archivo, notaTexto, ',');
        getline(archivo, tipoNumTexto, ',');
        getline(archivo, creditosTexto, ',');
        getline(archivo, tipoTexto, '\n');
        Materia m;
        m.nombre = nombre;
        try{
            m.nota = stof(notaTexto);        
            m.creditos = stoi(creditosTexto); 
        }catch(...){
            cout << "Linea corrupta para \"" << nombre << "\", se omitio.\n";
            continue;
        }
        m.tipo = tipoTexto;
        materias.push_back(m);
    }
    archivo.close();
    return materias;
}