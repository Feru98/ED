/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 2
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Provincia.hpp"


// SE DEBEN INCLUIR LOS COMENTARIOS DE DOXYGEN DE CADA FUNCIÓN

namespace ed
{

  int menu();

	///////////////////////////////////////////////////////////////////


  	/*!
		\brief  Comprueba si la provincia tiene o no algún municipio
		\param provincia
    */
	void comprobarProvinciaVacia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Carga la provincia desde un fichero que pide al usuario
		\param provincia
    */
	void cargarProvincia(ed::Provincia & provincia);

	/*!
		\brief  Carga la provincia en un fichero que pide al usuario
		\param provincia
    */
	void grabarProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Muestra por pantalla los datos de la provincia pasada por parametros
		\param provincia
    */
	void consultarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Muestra por pantalla los municipios de la provincia pasada por parametros
		\param provincia
    */
	void mostrarMunicipiosDeProvincia(ed::Provincia & provincia);

	///////////////////////////////////////////////////////////////////

	/*!
		\brief Muestra un menu que permite al usuario modificar los datos de la provincia pasada por parametros
		\param provincia
    */
	void modificarDatosDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Borra todos los municipios de la provincia pasada por parametros
		\param provincia
    */
	void borrarTodosLosMunicipiosDeProvincia(ed::Provincia & provincia);


	///////////////////////////////////////////////////////////////////

	/*!
		\brief  Muestra el municipio pedido al usuario por pantalla si este existe en la provincia pasada por parametros
		\param provincia
    */
	void consultarMunicipioDeProvincia(ed::Provincia & provincia);

	/*!
		\brief  Inserta un municipio pedido por pantalla al usuario en la provincia pasada por parametros
		\param provincia
    */
	void insertarMunicipioEnProvincia(ed::Provincia & provincia);

	/*!
		\brief  Borra un municipio pedido por pantalla al usuario en la provincia pasada por parametros
		\param provincia
    */
	void borrarMunicipioDeProvincia(ed::Provincia & provincia);


} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

