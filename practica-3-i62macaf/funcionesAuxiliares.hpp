/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 3
  \author Fernando Maestre Carmona
  \date  Mayo-2018
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "MonticuloMediciones.hpp"

// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{


	/*! 
		\brief   Función que muestra un menu de opciones por terminal 
	*/
	int menu();


	/*! 
		\brief   Función que carga el monticulo del fichero pasado por parametros 
		\param 	nombreFichero
		\param 	monticulo
	*/
	void cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo); 

	/*! 
		\brief   Función que carga el monticulo de un fichero 
		\param 	monticulo
	*/
	void cargarMonticulo(ed::MonticuloMediciones & monticulo);


	/*! 
		\brief   Función que graba el monticulo en un fichero pasado por parametros 
		\param 	nombreFichero
		\param 	monticulo
	*/
	void grabarMonticuloEnFichero (std::string const & nombreFichero, ed::MonticuloMediciones const & monticulo); 

	/*! 
		\brief   Función que graba el monticulo en un fichero 
		\param 	monticulo
	*/
	void grabarMonticulo(ed::MonticuloMediciones const & monticulo);

	/*! 
		\brief   Función que calcula la media y la suma de las precipitaciones de la mediciones del monticulo 
		\param 	monticulo
	*/
	void calcularDatos(ed::MonticuloMediciones const & monticulo);

	/*! 
		\brief   Función que imprime el monticulo por pantalla de forma ordenada 
		\param 	monticulo
	*/
	void imprimirMonticulo(ed::MonticuloMediciones const & monticulo);

	/*! 
		\brief   Función que pide al usuario por pantalla una medicion y la añade al monticulo
		\param 	monticulo
	*/
	void insertar(ed::MonticuloMediciones & monticulo);

	/*! 
		\brief   Función que busca si una fecha está en el monticulo y la imprime por pantalla
		\param 	monticulo
	*/
	void ConsultarFecha(ed::MonticuloMediciones const & monticulo);

	/*! 
		\brief   Función que permite modificar por pantalla la cima del monticulo 
		\param 	monticulo
	*/
	void modificar(ed::MonticuloMediciones & monticulo);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FuncionesAuxiliares_HPP_
#endif

