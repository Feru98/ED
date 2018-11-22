/*!
  \file   FuncionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 4
  \author Fernando Maestre Carmona
  \date  Junio-2018
*/

#ifndef _FuncionesAuxiliares_HPP_
#define _FuncionesAuxiliares_HPP_

#include "Grafo.hpp"

namespace ed
{


	/*! 
		\brief   Función que muestra un menu de opciones por terminal 
	*/
	int menu();

	/*! 
		\brief   Función que carga el grafo del fichero pasado por parametros 
		\param 	nombreFichero
		\param 	grafo
	*/
	void cargarGrafoDeFichero(std::string const & nombreFichero, ed::Grafo & grafo);


	/*! 
		\brief   Función que graba el grafo en un fichero pasado por parametros 
		\param 	nombreFichero
		\param 	grafo
	*/
	void grabarGrafoEnFichero(std::string const & nombreFichero, ed::Grafo & grafo);

	/*! 
		\brief   Función que carga el grafo de un fichero 
		\param 	grafo
	*/
	void cargarGrafo(ed::Grafo & grafo);


	/*! 
		\brief   Función que graba el grafo en un fichero 
		\param 	grafo
	*/
	void grabarGrafo(ed::Grafo & grafo);


	/*! 
		\brief   Función que imprime el grafo por pantalla
		\param 	grafo
	*/
	void imprimirGrafo(ed::Grafo & grafo);

	/*! 
		\brief   Función que aplica el algoritmo de prim al grafo pasado por parametros y lo muestra por pantalla
		\param 	grafo
	*/
	void prim(ed::Grafo & grafo);

	/*! 
		\brief   Función que aplica el algoritmo de prim al grafo pasado por parametros y lo graba en un fichero
		\param 	grafo
	*/
	void primFichero(ed::Grafo & grafo);

	/*! 
		\brief   Función que aplica el algoritmo de kruskal al grafo pasado por parametros y lo muestra por pantalla
		\param 	grafo
	*/
	void kruskal(ed::Grafo & grafo);

	/*! 
		\brief   Función que aplica el algoritmo de kruskal al grafo pasado por parametros y lo graba en un fichero
		\param 	grafo
	*/
	void kruskalFichero(ed::Grafo & grafo);

	/*! 
		\brief   Función que permite insertar un vertice pedido por pantalla al usuario
		\param 	grafo
	*/
	void insertarVertice(ed::Grafo & grafo);

	/*! 
		\brief   Función que permite borrar un vertice pedido por pantalla al usuario
		\param 	grafo
	*/
	void borrarVertice(ed::Grafo & grafo);

	/*! 
		\brief   Función que muestra la longitud del arbol abarcador minimo
		\param 	grafo
	*/
	void longitudArbol(ed::Grafo & grafo);


} //fin namespace ed

// Fin de _FuncionesAuxiliares_HPP_
#endif