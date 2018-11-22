/*! 
   \file  Vertice.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vertice
*/


// Ficheros de cabecera
#include <iostream>

#include <stdlib.h>
#include "Vertice.hpp"


namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Vertice const &vertice)
{
	std::vector<float> v = vertice.getData();


  stream << v[0];
  stream << " ";
  stream << v[1];
  stream << "-";
  stream << vertice.getLabel();

  return stream;
}


/*
// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Fecha &fecha)
{
 // Se lee la fecha teniendo en cuenta el formato: DD-MM-AAAA
  std::string cadena;

  std::getline(stream,cadena,'-');
  fecha.setDia(atoi(cadena.c_str()));

  std::getline(stream,cadena,'-');
  fecha.setMes(atoi(cadena.c_str()));

  std::getline(stream,cadena,' ');
  fecha.setAgno(atoi(cadena.c_str()));

  return stream;
} 

*/

} // Fin del espacio de nombres ed