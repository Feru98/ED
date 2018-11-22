
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	/*! 
 	 @fn void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w)
 	 @brief Pide al usuario por pantalla rellenar los parametros de tres vectores
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 @param w tercer Vector3D
 	 */
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w)
 	 @brief Muestra al usuario por pantalla los parametros de tres vectores
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 @param w tercer Vector3D
 	 */
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);


	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v)
 	 @brief Muestra al usuario por pantalla el resultado de aplicar los obsevadores de la clase Vector3D en dos vectores
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 */
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k)
 	 @brief Muestra al usuario por pantalla el resultado de aplicar los modificadores de la clase Vector3D en dos vectores
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 @param k constante
 	 */
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v)
 	 @brief Muestra al usuario por pantalla el resultado del producto escalar de dos vectores usando ambas la función dotProduct() y el operador *
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 */
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v)
 	 @brief Muestra al usuario por pantalla el resultado del producto vectorial de dos vectores usando ambas la función crossProduct() y el operador ^
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 */
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w)
 	 @brief Muestra al usuario por pantalla el resultado del producto mixto con tres vectores 
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 @param w tercer Vector3D
 	 */
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	/*! 
 	 @fn void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k) 
 	 @brief Muestra al usuario por pantalla el uso de operadores de la clase Vector3D 
 	 @param u primer Vector3D
 	 @param v segundo Vector3D
 	 @param w tercer Vector3D
 	 @param k constante
 	 */
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);

	/*! 
 	 @fn  void cuadrado(ed::Vector3D &u)
 	 @brief Muestra al usuario por pantalla el uso de operadores de la clase Vector3D 
 	 */
	void cuadrado(ed::Vector3D &u);



} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

