#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype> 
#include <limits>
#include "tools.h"

using namespace std;
void validarEntradaEntero(int &value){
    while(true){
        if(cin >> value){
            break;
        }else{
            cout << "Error: Eso no es un numero. Intenta de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void validarEntradaDecimal(float &value){
    while(true){
        if(cin >> value){
            break;
        }else{
            cout << "Error: Eso no es un numero. Intenta de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void validarIndice(int &value, vector<Materia>& materias){
    while(true){
        if(value <= materias.size() && value > 0){
            break;
        }else{
            cout << "Error: Ese indice no se encuentra. Intenta de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validarEntradaEntero(value);
        }
    }
}
void validarNota(float &value){
    while(true){
        if(value >= 0.0 && value <= 5.0){
            break;
        }else{
            cout << "Error: Ese nota no es valida. Intenta de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validarEntradaDecimal(value);
        }
    } 
}
void validarCreditos(int &value){
    while(true){
        if(value >= 1){
            break;
        }else{
            cout << "Error: Ese credito no es valido. Intenta de nuevo.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            validarEntradaEntero(value);
        }
    } 
}
void pasarMinuscula(string &value){
    transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
        return tolower(c);
    });
}
void validarTextoTipo(string &value){
    while(true){
        pasarMinuscula(value);
        if(value == "universidad" || value == "colegio"){
            break;
        }else{
            cout << "Error: Ese nombre no es valido. Intenta de nuevo.\n";
            getline(cin, value);
        }
    } 
}
