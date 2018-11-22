/*! 
   \file Lado.hpp
   \brief Fichero de la clase Lado
   \author Fernando Maestre Carmona
*/


#ifndef _LADO_HPP_
#define _LADO_HPP_


// Entrada y salida 
#include <iostream>
#include "macros.hpp"
#include "Vertice.hpp"
#include <vector>

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales

// Se incluye la clase Lado dentro del espacio de nombres de la asigantura: ed
namespace ed {

//! Definición de la clase Lado
class Lado
{
	
	//! \name Atributos privados de la clase Lado
	private:

		std::vector<ed::Vertice> l; //!< Vector con los dos vertices que une el lado
		int label_;		//!< Etiqueta que identifica el lado
		float peso_;	//!< Peso del lado
		

	//! \name Funciones o métodos públicos de la clase Lado
	public:

		//! \name Constructores de la clase Lado

		/*! 
		\brief   Constructor sin argumentos
		*/
		Lado()
		{
			l.resize(2);
		}

		//! \name Observadores: funciones de consulta de la clase Lado


		/*! 
		\brief   Función que devuelve un vector con los vertices que une el lado
		\note    Función inline
		\return  l_ Vector de vertices
	*/
		inline std::vector<ed::Vertice> getData()const{return l;}const

		/*! 
		\brief   Función que devuelve la etiqueta del lado
		\note    Función inline
		\return  lebel_ entero
	*/
		inline int getLabel()const{return label_;}const

	/*! 
		\brief   Función que devuelve el peso
		\note    Función inline
		\return  peso_ entero
	*/
		inline float getPeso()const{return peso_;}const

	/*! 
		\brief   Función que devuelve true si el lado contiene el vertice pasado por argumentos
		\param aux Vertice
		\note    Función inline
		\return  true bool
	*/
		inline bool has(ed::Vertice aux)const
		{
			if(aux==l[0]){return true;};
			if(aux==l[1]){return true;};

			return false;
		}


		/*! 
		\brief   Función que devuelve el otro vertice que no es el pasado por argumentos en un lado
		\param aux Vertice
		\note    Función inline
		\return  Vertice
		\pre tiene que contener el vertice pasado por parametros
	*/
		inline ed::Vertice other(ed::Vertice aux)const
		{
			assert( (aux==l[0]) or (aux==l[1])  );

			if(aux==l[0]){return l[1];}
			//if(aux==l[1])
			else{return l[0];}

		}

		/*! 
		\brief   Función que devuelve el primer vertice del lado
		\note    Función inline
		\return  Vertice
	*/
		inline ed::Vertice first()const{return l[0];};

		/*! 
		\brief   Función que devuelve el segundo vertice del lado
		\note    Función inline
		\return  Vertice
	*/
		inline ed::Vertice second()const{return l[1];};


		//! \name Funciones de modificación de la clase Lado


		/*! 
		\brief Función que asigna un nuevo valor a los datos del lado
		\note  Función inline 
		\param v: vector con los dos vertices del lado
	*/
		inline void setData(std::vector<ed::Vertice> v )
		{
			l[0] = v[0];
			l[1] = v[1];

			/*
			#ifndef NDEBUG
				assert((abs(l[0] - v[0])) < COTA_ERROR);
				assert((abs(l[1] - v[1])) < COTA_ERROR);
			#endif
			*/
		}


		/*! 
		\brief Función que asigna un nuevo valor a la etiqueta del lado
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


		/*! 
		\brief Función que asigna un nuevo peso al lado
		\note  Función inline 
		\param peso: nuevo valor 
		\post  el valor de peso_ debe ser igual al de peso
	*/
		inline void setPeso(float peso)
		{
			peso_ = peso;

			#ifndef NDEBUG
				assert(getPeso() == peso);
			#endif

		}



	//! \name Operadores



		/*! 
		\brief     Operador de igualdad: compara si dos lados son iguales
		\attention Se sobrecarga el operador de asignación "=="
		\note      Función inline
		\param     objeto: Lado pasado como referencia constante
	*/
		inline bool operator == (Lado const &objeto)const
	{
	  return (
            	  ( this->getData() == objeto.getData() ) 
              //and ( this->getLabel() == objeto.getLabel() )
              //and  ( this->getPeso() == objeto.getPeso() )
             );
	}




	/*! 
		\brief     Operador de asignación: operador que "copia" un lado en otro
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\param     objeto de la clase vertice pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
		\post      Los atributos deben tener los valores de los atributos del objeto pasado como argumento
	*/
	inline Lado & operator=(Lado const &objeto)
	{

		// Se comprueba que no sean el mismo objeto
		if (this != &objeto) 
		{
			this->setData(objeto.getData());
			this->setLabel(objeto.getLabel());
			this->setPeso(objeto.getPeso());

			#ifndef NDEBUG
	  		// Se comprueba la postcondición
			assert(this->l == objeto.getData());
			assert(this->label_ == objeto.getLabel());
			#endif //NDEBUG
		}

		return *this;
	}
		

};//fin de la clase lado





} //end namespace ed

#endif