 /*!
	\file MonticuloMedicionesInterfaz.hpp
	\brief Se define la interfaz del TAD MonticuloMediciones.
	\author 
	\date  
*/

#ifndef _MONTICULO_MEDICIONES_INTERFAZ_HPP
#define _MONTICULO_MEDICIONES_INTERFAZ_HPP

#include "Medicion.hpp"

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

	// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

	//!  Definición de la clase MonticuloMedicionesInterfaz
	class MonticuloMedicionesInterfaz
	{
		public:

			// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

		/*!
        \brief  Comprueba si el monticulo está vacío
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si el monticulo está vacío; false, en caso contrario
    */
			virtual bool isEmpty() const = 0;

		/*!
        \brief  Devuelve la medicion que ocupa la cima
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
        \return aux, medicion de la cima
    */
			virtual ed::Medicion top() const = 0;

			/*!
        \brief  Inserta una medicion en el monticulo
        \param medicion
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
    */
			virtual void insert(ed::Medicion medicion) = 0;

			/*!
        \brief  Inserta una medicion en el monticulo
		\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \note   Función de tipo "const": no puede modificar al objeto actual
    */
			virtual void remove() = 0;


	}; // Clase MonticuloMedicionesInterfaz

} // Espacio de nombres ed

#endif //  _MONTICULO_MEDICIONES_INTERFAZ_HPP
