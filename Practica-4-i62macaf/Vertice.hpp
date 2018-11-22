/*! 
   \file Vertice.hpp
   \brief Fichero de la clase Vertice
    \author Fernando Maestre Carmona
*/


#ifndef _VERTICE_HPP_
#define _VERTICE_HPP_


// Entrada y salida 
#include <iostream>
#include "macros.hpp"
#include <vector>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales

// Se incluye la clase Vertice dentro del espacio de nombres de la asigantura: ed
namespace ed {

//! Definición de la clase Vertice
class Vertice
{
	
	//! \name Atributos privados de la clase Vertice
	private:
		
		std::vector<float>  v_; //!< Vector con la posicion x e y del vertice
		int label_;	//!< Etiqueta que identidica el vertice

	//! \name Funciones o métodos públicos de la clase Vertice
	public:

		//! \name Constructores de la clase Vertice

		/*! 
		\brief   Constructor sin argumentos
		*/
		Vertice()
		{
			v_.resize(2);
		}

		//! \name Observadores: funciones de consulta de la clase Vertice


		/*! 
		\brief   Función que devuelve el dato x e y del vertice
		\note    Función inline
		\return  v_ Vector de floats
	*/
		inline  std::vector<float> getData()const{ return  v_;} 

		/*! 
		\brief   Función que devuelve la etiqueta del vertice
		\note    Función inline
		\return  label_ entero
	*/
		inline  int getLabel()const{return label_;}



		//! \name Funciones de modificación de la clase Vertice

		/*! 
		\brief Función que asigna un nuevo valor a los datos del vertice
		\note  Función inline 
		\param v: nuevo valor 
		\post  los valores de x e y deben tener el valor de v[0] y v[1]
	*/
		inline void setData(std::vector<float> v)
		{
			v_[0] = v[0];
			v_[1] = v[1];

			#ifndef NDEBUG
				assert((abs(v_[0] - v[0])) < COTA_ERROR);
				assert((abs(v_[1] - v[1])) < COTA_ERROR);
			#endif
		}


		/*! 
		\brief Función que asigna un nuevo valor a la etiqueta del vertice
		\note  Función inline 
		\param label: nuevo valor 
		\post  el valor de label_ debe ser igual al de label
	*/
		inline void setLabel(int label)
		{
			label_ = label;

			#ifndef NDEBUG
				assert(getLabel() == label);
			#endif

		}



		//! \name Operadores



		/*! 
		\brief     Operador de igualdad: compara si dos vertices son iguales
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     objeto: Vertice pasado como referencia constante
	*/
		inline bool operator == (Vertice const &objeto)const
	{
	  return (
            	  ( this->getData() == objeto.getData() ) 
              //and ( this->getLabel() == objeto.getLabel() )
             );
	}




	/*! 
		\brief     Operador de asignación: operador que "copia" un vertice en otro
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\param     objeto de la clase vertice pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		\post      Los atributos deben tener los valores de los atributos del objeto pasado como argumento
	*/
	inline Vertice & operator=(Vertice const &objeto)
	{

		// Se comprueba que no sean el mismo objeto
		if (this != &objeto) 
		{
			this->setData(objeto.getData());
			this->setLabel(objeto.getLabel());

			#ifndef NDEBUG
	  		// Se comprueba la postcondición
			assert(this->v_ == objeto.getData());
			assert(this->label_ == objeto.getLabel());
			#endif //NDEBUG
		}

		return *this;
	}

}; //Fin de la clase Vertice



	/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\param     stream Flujo de salida
		\param     vertice pasado como referencia constante
    */
ostream &operator<<(ostream &stream, ed::Vertice const &vertice);

} //end namespace ed

#endif