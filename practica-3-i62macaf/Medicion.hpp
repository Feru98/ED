/*! 
   \file Medicion.hpp
   \brief Fichero de la clase Medicion: medición de una estación meteorológica 
*/

#ifndef _MEDICION_HPP_
#define _MEDICION_HPP_

// Entrada y salida 
#include <iostream>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>

// Definición de la clase Fecha
#include "Fecha.hpp"
#include <cstdlib>


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación de números reales


// Se incluye la clase Medicion dentro del espacio de nombres de la asigantura: ed
namespace ed {

//!  Definición de la clase Medicion 
class Medicion
{
  //! \name Atributos privados de la clase Medicion
   private: 

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

   		ed::Fecha fecha_ ;
   		float precipitacion_ ;


   //! \name Funciones o métodos públicos de la clase Medicion
   public:

	//! \name Constructores de la clase Medicion


   		/*! 
		\brief     Constructor que crea una Medicion con parametros
		\attention Función sobrecargada        
		\note      Función inline
	 	\warning   Los parámetros tienen valores por defecto
		\param     fecha valor por defecto: 1,1,1
		\param     precipitacion valor por defecto: 0.0
		\post      La fecha y la precipitación deben ser iguales a las instroducidas
	*/
		inline Medicion(ed::Fecha fecha=Fecha(1,1,1) , float precipitacion=0.0)
		{
			

			setFecha(fecha);
			setPrecipitacion(precipitacion);

			#ifndef NDEBUG
		  	assert(std::abs((getPrecipitacion() - precipitacion)<COTA_ERROR) );
		  	assert(getFecha() ==fecha);
		  #endif //NDEBUG
		}


		/*! 
		\brief     Constructor de copia que crea una Medicion con otra medicion
		\attention Función sobrecargada        
		\note      Función inline
		\param     medicion
		\post      La fecha y la precipitación deben ser iguales a las de la medicion pasada como parametro
	*/
		inline Medicion(Medicion const &medicion)
		{
			setFecha(medicion.getFecha());
			setPrecipitacion(medicion.getPrecipitacion());

			#ifndef NDEBUG
		  	assert(std::abs((getPrecipitacion() - medicion.getPrecipitacion())<COTA_ERROR) );
		  	assert(getFecha() == medicion.getFecha());
		  #endif //NDEBUG
		}

	//! \name Observadores: funciones de consulta de la clase Medicion
		
		/*! 
		\brief   Función que devuelve la fecha de una medicion
		\note    Función inline 
		\return  fecha_ 
		\pre     Ninguna
		\post    Ninguna
	*/
		inline ed::Fecha getFecha() const {return fecha_;};

		/*! 
		\brief   Función que devuelve la precipitacion de una medicion
		\note    Función inline 
		\return  precipitacion_
		\pre     Ninguna
		\post    Ninguna
	*/
		inline float getPrecipitacion() const {return precipitacion_;};

	//! \name Funciones de modificación de la clase Medicion


		/*! 
		\brief Función que asigna un nuevo valor a la fecha de una medicion
		\note  Función inline 
		\param fecha: nuevo valor de la fecha_
		\post  El atributo fecha_ de la Medicion debe tener el valor de "fecha"
	*/
		inline void setFecha(ed::Fecha fecha)
		{
			fecha_=fecha;

			#ifndef NDEBUG
		  	assert(getFecha() ==fecha);
		  #endif //NDEBUG
		};


		/*! 
		\brief Función que asigna un nuevo valor a la precipitacion de una medicion
		\note  Función inline 
		\param precipitacion: nuevo valor de la precipitacion_
		\post  El atributo precipitacion_ de la Medicion debe tener el valor de "precipitacion"
	*/
		inline void setPrecipitacion(float precipitacion)
		{
			#ifndef NDEBUG
		  	assert(precipitacion >= 0.0);		  	
		  #endif //NDEBUG

			precipitacion_=precipitacion;


			#ifndef NDEBUG
		  	assert(std::abs((getPrecipitacion() - precipitacion)<COTA_ERROR) );
		  #endif //NDEBUG
		};

	//! \name Operadores
   		

   		/*! 
		\brief     Operador de igualdad: compara si dos mediciones son iguales (por la fecha)
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     medicion: objeto de la clase Medicion pasado como referencia constante
		\return 	true, si son iguales
	*/
		inline bool operator == (Medicion const &medicion) const
		{
	  		return (
            	   getFecha() == medicion.getFecha()  
              //and ( std::abs((getPrecipitacion() - medicion.getPrecipitacion())<COTA_ERROR) )
             );
		}


		/*! 
		\brief     Operador de asignación: operador que "copia" una medicion en otra medicion
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\param     medicion: objeto de la clase Medicion pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		\post      Los atributos fecha_ y precipitacion_ deben tener los valores de los atributos del objeto pasado como argumento
	*/
		inline Medicion & operator=(Medicion const &medicion)
		{

			if (this != &medicion) 
		{
			setFecha(medicion.getFecha());
			setPrecipitacion(medicion.getPrecipitacion());
			

			#ifndef NDEBUG
	  		// Se comprueba la postcondición
			assert(getFecha() == medicion.getFecha());
			assert(std::abs((getPrecipitacion() - medicion.getPrecipitacion())<COTA_ERROR));
			#endif //NDEBUG
		}

		return *this;
		};


	//! \name Funciones de lectura y escritura de la clase Medicion

		/*! 
		\brief Escribe por pantalla los valores de los atributos de una Medicion
	*/
		void escribirMedicion()const;

		/*! 
		\brief   Lee desde el teclado los nuevos valores de los atributos de una Medicion
	*/
		void leerMedicion();



}; // Fin de la definición de la clase Medicion


   //! \name Funciones externas de la clase Medicion: sobrecarga de los operadores de flujo

		/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\param     stream Flujo de salida
		\param     medicion pasada como referencia constante
    */
		ostream &operator<<(ostream &stream, Medicion const &medicion);

		/*!
  		\brief     Sobrecarga del operador de entrada o lectura ">>"
		\param     stream Flujo de entrada
		\param     medicion pasada como referencia
    */
		istream &operator>>(istream &stream, ed::Medicion &medicion);


} // \brief Fin de namespace ed.

//  _MEDICION_HPP_
#endif 
