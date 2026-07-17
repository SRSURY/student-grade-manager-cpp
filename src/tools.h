#ifndef TOOLS_H
#define TOOLS_H
#include "materia.h"
#include <string>
#include <vector>
void validarEntradaEntero(int &value);
void validarEntradaDecimal(float &value);
void validarIndice(int &value, vector<Materia>& materias);
void validarNota(float &value);
void validarTextoTipo(string &value);
void validarCreditos(int &value);
#endif