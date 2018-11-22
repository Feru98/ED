/*! 
   \file  Medicion.cpp
   \brief Fichero que contiene el código de las funciones de la clase Medicion
*/


// Ficheros de cabecera
#include <iostream>

// atoi, atof
#include <stdlib.h>

#include "Medicion.hpp"


// COMPLETAR

void ed::Medicion::escribirMedicion()const
{
	std::cout << getFecha().getDia() << "-" 
            << getFecha().getMes() << "-"
            << getFecha().getAgno() << " "
            << getPrecipitacion() << std::endl;
}
void ed::Medicion::leerMedicion()
{
  ed::Fecha fecha ;
	double dia, mes, agno;
	float precipitacion ;

  std::cout << "\n Lectura de una Medicion" << std::endl;

  std::cout << " Día --> ";
  std::cin >> dia;

  std::cout << " Mes --> ";
  std::cin >> mes;

  std::cout << " Año --> ";
  std::cin >> agno;

  std::cout << " Precipitacion --> ";
  std::cin >> precipitacion;

 
  fecha.setDia(dia);
  fecha.setMes(mes);
  fecha.setAgno(agno);
  setFecha(fecha);
  setPrecipitacion(precipitacion);
 

 
}

////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{

// Sobrecarga del operador de salida
ostream &operator<<(ostream &stream, ed::Medicion const &medicion)
{

  stream << medicion.getFecha().getDia();
  stream << "-";
  stream << medicion.getFecha().getMes();
  stream << "-";
  stream << medicion.getFecha().getAgno();
  stream << " ";
  stream << medicion.getPrecipitacion();
  stream << "\n";

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Medicion &medicion)
{
 	std::string cadena;

  std::getline(stream,cadena,'-');
  medicion.getFecha().setDia(atoi(cadena.c_str()));

  std::getline(stream,cadena,'-');
  medicion.getFecha().setMes(atoi(cadena.c_str()));

  std::getline(stream,cadena,' ');
  medicion.getFecha().setAgno(atoi(cadena.c_str()));

  std::getline(stream,cadena,' ');
  medicion.setPrecipitacion(atof(cadena.c_str()));

  return stream;
} 

} // Fin del espacio de nombres ed
