/*!
	\file MonticuloMediciones.hpp
	\brief Se define el TAD MonticuloMediciones.
	\author Fernando Maestre Carmona
	\date  Mayo-2018
*/

#ifndef _MONTICULO_MEDICIONES_HPP
#define _MONTICULO_MEDICIONES_HPP

#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMedicionesInterfaz.hpp"

#include "macros.hpp"


// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

namespace ed
{

// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

//!  Definición de la clase MonticuloMediciones
class MonticuloMediciones : public MonticuloMedicionesInterfaz
{
	private:

		//! \name Atributos privados de la clase MonticuloMediciones

		ed::Medicion v[366];
		int size_ ;


		//! \name Métodos privados de la clase MonticuloMediciones

		/*! 
		\brief   Función que devuelve una medicion del monticulo
		\note    Función inline
		\param	i :número entero
		\return  v[i] : medicion i del monticulo
		\pre     i >=0
		\pre     i < size()
	*/
		inline ed::Medicion getElement(int i) const 
		{
			#ifndef NDEBUG
		  	assert(i>=0);
		  	assert(i<size());
		  #endif //NDEBUG

			return v[i];
		};
		
		/*! 
		\brief   Función que devuelve un entero índice del hijo izquierdo del índice recibido. 
		\note    Función inline
		\param	i :número entero
		\return  aux : entero indice del hijo izquierdo
		\pre     i >=0
		\post	aux==(2*i)+1
	*/
		inline int getLeftChild(int i)
		{
			#ifndef NDEBUG
			assert(i>=0);
		  #endif //NDEBUG

			int aux = (2*i)+1;

			#ifndef NDEBUG
		 	assert(aux==(2*i)+1);
		  #endif //NDEBUG

			return aux;
		};


		/*! 
		\brief   Función que devuelve un entero índice del hijo derecho del índice recibido. 
		\note    Función inline
		\param	i :número entero
		\return  aux : entero indice del hijo derecho
		\pre     i >=0
		\post	aux==(2*i)+2
	*/
		inline int getRightChild(int i)
		{
			#ifndef NDEBUG
			assert(i>=0);
		  #endif //NDEBUG

			int aux = (2*i)+2;

			#ifndef NDEBUG
		 	assert(aux==(2*i)+2);
		  #endif //NDEBUG

			return aux;
		};

		/*! 
		\brief   Función que devuelve un entero índice del padre del índice recibido. 
		\note    Función inline
		\param	i :número entero
		\return  aux : entero indice del padre
		\pre     i >=0
		\post	aux==(i-1)/2
	*/
		inline int getParent(int i)
		{
		#ifndef NDEBUG
			assert(i>=1);
		  #endif //NDEBUG

			int aux=(i-1)/2;

		#ifndef NDEBUG
			assert(aux==(i-1)/2);
		  #endif //NDEBUG

			return aux;
		};

		/*! 
		\brief   Función que comprueba si la medicion pasada por parametros ya se encuentra en el monticulo
		\note    Función inline
		\param	medicion
		\return  true, si la medicion se encuentra en el monticulo
	*/
		inline bool has(ed::Medicion medicion)
		{
			for(int i=0 ; i<366 ; i++)
			{
				if(v[i]==medicion){return true;}
			}
			return false;
		}


		/*! 
		\brief  El elemento indicado por el índice es subido en el montículo hasta que se verifica la ordenación de máximos
		\param	i :número entero
		\pre    (i >= 0 )  
		\pre	(i < size())
		\post	Si no es la cima, el elemento actual es menor o igual que su padre
		\post 	Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.
	*/
		void ShiftUp(int i);


		/*! 
		\brief  El elemento indicado por el índice es bajado en el montículo hasta que se verifica la ordenación de máximos
		\param	i :número entero
		\pre    (i >= 0 )  
		\pre	(i < size())
		\post	Si no es la cima, el elemento actual es menor o igual que su padre
		\post 	Si tiene hijo izquierdo, el elemento actual es mayor o igual que él y, además, si tiene hijo derecho, es mayor o igual que él.
	*/
		void ShiftDown(int i);


		/*! 
		\brief Función que asigna un nuevo valor a una medicion del monticulo
		\note  Función inline 
		\param medicion: nuevo valor del elemento v[i] del monticulo
		\param i : entero
		\pre     i >=0
		\pre     i < size()
		\post  El elemento v[i] del monticulo debe tener el valor de "medicion"
	*/
		inline void setElement(int i , ed::Medicion medicion)
		{
			#ifndef NDEBUG
		  	assert(i>=0);
		  	assert(i<size());
		  #endif //NDEBUG

			v[i]=medicion;

			#ifndef NDEBUG
		  	assert(getElement(i) == medicion);
		  #endif //NDEBUG
		};

	  /////////////////////////////////////////////////////////////////////////////////////

	//! \name Métodos públicos de la clase MonticuloMediciones
	public:

		//! \name Constructor

		/*! 
		\brief     Constructor que crea un monticulo de Mediciones con un vector acotado      
		\note      Función inline
		\post      El monticulo contiene 0 elementos
	*/
		inline MonticuloMediciones()
		{
			/*ed::Medicion * aux = new ed::Medicion();
			v[0]= *aux;*/
			size_=0;

			#ifndef NDEBUG
		  	assert(size()==0);
		  #endif //NDEBUG
		}


		//! \name Observadores

		/*
		inline ed::Medicion getElement(int i) const 
		{
			#ifndef NDEBUG
		  	assert(i>=0);
		  	assert(i<size());
		  #endif //NDEBUG

			return v[i];
		};
		*/


		/*! 
		\brief   Función que devuelve si el monticulo está vacio
		\note    Función inline 
		\return  true, si el monticulo está vacio 
	*/
		inline bool isEmpty() const
		{
			if(size()==0){return true;}
			return false;			
		}

		/*! 
		\brief   Función que devuelve el número de elementos del monticulo monticulo 
		\note    Función inline 
		\return  size_ : tamaño del monticulo 
	*/
		inline int size() const
		{
			return size_ ;
		}

		/*! 
		\brief   Función que devuelve la Medicion que es la cima del monticulo
		\note    Función inline 
		\return aux, medicion en la cima
		\pre 	isEmpty()==false
		\post 	aux==getElement(0)
	*/
		inline ed::Medicion top() const
		{
			#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		  	ed::Medicion aux = v[0];
			return aux;

			#ifndef NDEBUG
		  	assert(aux==getElement(0));
		  #endif //NDEBUG
		}

		////////////////////////////////////////////////////////////

		//! \name Operaciones de modificación

		// COMPLETAR EL CÓDIGO E INCLUIR LOS COMENTARIOS DE DOXYGEN

		/*! 
		\brief   Función que inserta una nueva medicion en el monticulo
		\note    Función inline 
		\param 	medicion
		\pre     La medicion no se encuentra en el monticulo
		\post    isEmtpy() == falso
		\post 	has(medición) == verdadero
	*/
		inline void insert(ed::Medicion medicion)
		{
			if(has(medicion))
			{
				std::cout<<BIYELLOW<<"Esa fecha ya se encuentra en el Monticulo"<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}
			if(size()<366)
			{
			size_++;
			setElement(size()-1 , medicion);
			ShiftUp(size()-1);
			

			#ifndef NDEBUG
		  	assert(!isEmpty());
		  	assert(has(medicion));
		  #endif //NDEBUG

			}
			else
			{
				//vector lleno
				std::cout<<BIRED<<"Vector lleno"<<RESET<<std::endl;
				std::cin.ignore();
			}
		}


		/*! 
		\brief   Función que borra la medicion que ocupa la cima
		\note    Función inline 
		\pre     El monticulo no está vacio 
	*/
		inline void remove()
		{
			#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

			v[0]=v[size()-1];
			size_-- ;

			//si solo queda un elemento no lo tiene que ordenar
			if(size()>1)
			{
			ShiftDown(0);
			}
		}

		/*! 
		\brief   Función que borra todas las mediciones del monticulo
		\note    Función inline 
		\post	isEmpty()==true;	
	*/
		inline void removeAll()
		{
			while(size()>0)
			{
				remove();
			}

			#ifndef NDEBUG
		  	assert(isEmpty());
		  #endif //NDEBUG
		}


		/*! 
		\brief   Función que modifica la medicion que ocupa la cima del monticulo
		\note    Función inline 
		\param 	medicion
		\pre   isEmtpy() == falso
		\post 	has(medición) == verdadero
	*/
		inline void modify(ed::Medicion medicion)
		{
			#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		  	if(has(medicion))
			{
				std::cout<<BIYELLOW<<"Esa fecha ya se encuentra en el Monticulo"<<RESET<<std::endl;
				std::cin.ignore();
				return;
			}

			v[0]=medicion;
			ShiftDown(0);

				std::cout<<BIGREEN<<"Cima modificada"<<RESET<<std::endl;
				std::cin.ignore();

			#ifndef NDEBUG
		  	assert(has(medicion));
		  #endif //NDEBUG
		}



		//! \name Operadores
   
		// COMPLETAR
 		
 		/*! 
		\brief     Operador de asignación: operador que "copia" una monticulo en otro
		\attention Se sobrecarga el operador de asignación "="
		\note      Función inline
		\param     aux: objeto de la clase MonticuloMediciones pasado como referencia constante
		\pre       El objeto es distinto del objeto actual
	*/
 		inline MonticuloMediciones & operator=(MonticuloMediciones const &aux)
		{

			if (this != &aux) 
		{
			for(int i=0 ; i<366 ; i++)
			{
				setElement(i , aux.getElement(i));
			}

		}
		return *this ;
		}
		

		//! \name Función de escritura

		// COMPLETAR

		/*! 
		\brief   Función que imprime las mediciones tal y como están ordenadas en el vector
		\note    Función inline 
	*/
		inline void print()
		{	
			int c=0;
			if(!isEmpty())
			{
				for(int i=0 ; i<size() ; i++)
				{
					v[i].escribirMedicion();
					c++;
					if(c==35)
					{
						c=0;
						std::cin.ignore();
					}
				}
			}
			else
			{
				std::cout<<BIRED<<"El vector está vacio"<<RESET<<std::endl;
			}

		}

	}; // Clase MonticuloMediciones

} // Espacio de nombres ed


#endif // _MONTICULO_MEDICIONES_HPP
