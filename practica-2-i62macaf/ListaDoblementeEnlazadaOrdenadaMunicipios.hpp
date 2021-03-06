/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0

*/

#ifndef __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
#define __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaOrdenadaMunicipiosInterfaz.hpp"

#include "NodoDoblementeEnlazadoMunicipio.hpp"

#include "Municipio.hpp"

// DEBES ESPECIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaMunicipios 
  \brief Definición de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
	  	\n Lista doblemente enlazada de nodos de municipios ordenados alfabéticamente de forma ascendente 
*/
  class ListaDoblementeEnlazadaOrdenadaMunicipios: public ed::ListaOrdenadaMunicipiosInterfaz
  {
	//! \name  Atributos y métodos privados 

	private:
		ed::NodoDoblementeEnlazadoMunicipio *_head;    //!< \brief puntero al primer nodo de la lista
		ed::NodoDoblementeEnlazadoMunicipio *_current; //!< \brief puntero al nodo current de la lista

    // \name Observadores privados 

    inline ed::NodoDoblementeEnlazadoMunicipio * getHead() const
	{
		return this->_head;
	}

	inline ed::NodoDoblementeEnlazadoMunicipio * getCurrent() const
	{
		return this->_current;
	}

    //! \name Modificadores privados 

	inline void setHead(ed::NodoDoblementeEnlazadoMunicipio *head) 
	{
		this->_head = head;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getHead() == head);
		#endif //NDEBUG		
	}

    inline void setCurrent(ed::NodoDoblementeEnlazadoMunicipio *current) 
	{
		this->_current = current;

		#ifndef NDEBUG
			// Se comprueba la postcondición
			assert(this->getCurrent() == current);
		#endif //NDEBUG		
	}


	//! \name  Métodos públicos

	public:

	//! \name Constructores

    /*! 
		\brief Construye una lista vacía
		\note  Función inline
		\post  isEmpty() == true
	*/
	inline ListaDoblementeEnlazadaOrdenadaMunicipios()
    {
		  _head=NULL ;
		  _current=NULL ;

		  #ifndef NDEBUG
		  	assert(isEmpty());
		  #endif //NDEBUG	
	}
	
  
	//! \name Destructor 

    /*! 
		\brief Destruye una lista liberando la memoria de sus nodos
		\note Función codificada en el fichero cpp
		\post isEmpty() == true
	*/
	~ListaDoblementeEnlazadaOrdenadaMunicipios ()
     {
		  // DEBES CODIFICAR ESTA FUNCIÓN
     		removeAll();
     }


	//! \name Observadores públicos 

	/*!
		\brief  Comprueba si la lista está vacía
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true, si la lista está vacía; false, en caso contrario
    */
	inline bool isEmpty() const
	{

  		if(_head==NULL)
  		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// COMPLETAR EL RESTO DE OBSERVADORES PÚBLICOS

	/*!
		\brief  Cuenta los municipios de la lista
        \return n, número de municipios
    */
	int nItems() const;

	/*!
		\brief  Comprueba si el cursor está en el primer nodo
		\note   Función inline
		\pre 	isEmpty() == false
        \return true, si el cursor está en el primer nodo, false en caso contrario
    */
	inline bool isFirstItem() const
	{
		 #ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		if(getCurrent()==getHead())
		{
			return true ;
		}
		else
		{
			return false ;
		}
	}

	/*!
		\brief  Comprueba si el cursor está en el último nodo
		\note   Función inline
		\pre 	isEmpty() == false
        \return true, si el cursor está en el último nodo, false en caso contrario
    */
	inline bool isLastItem() const
	{
		#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		if(_current->getNext()==NULL)
		{
			return true ;
		}
		else
		{

			return false ;
		}

	}

	/*!
		\brief  Obtiene el municipio situado en el nodo actual
		\note   Función inline
		\pre 	isEmpty() == false
    */
	inline ed::Municipio const & getCurrentItem() const
	{
		#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		return getCurrent()->getItem();
	}

	/*!
		\brief  Obtiene el municipio situado en el nodo anterior
		\note   Función inline
		\pre 	isEmpty() == false
		\pre 	isFirstItem() == false
    */
	inline ed::Municipio const & getPreviousItem() const
	{
		#ifndef NDEBUG
		  	assert(!isEmpty());
		  	assert(!isFirstItem());
		  #endif //NDEBUG
		  
		NodoDoblementeEnlazadoMunicipio * aux = _current->getPrevious();
		return aux->getItem();
	}

	/*!
		\brief  Obtiene el municipio situado en el nodo anterior
		\note   Función inline
		\pre 	isEmpty() == false
		\pre 	isLastItem() == false
    */
	inline ed::Municipio const & getNextItem() const
	{
		#ifndef NDEBUG
		  	assert(!isEmpty());
		  	assert(!isLastItem());
		  #endif //NDEBUG
		  	
		NodoDoblementeEnlazadoMunicipio * aux = _current->getNext();
		return aux->getItem();
	}


    //! \name Modificadores públicos

	// COMPLETAR EL RESTO DE MODIFICADORES PÚBLICOS

	/*!
		\brief  Coloca el cursor en el primer nodo
		\pre 	isEmpty() == false
		\post 	isFirstItem() == true
    */
	void gotoHead();

	/*!
		\brief  Coloca el cursor en el último nodo
		\pre 	isEmpty() == false
		\post 	isLastItem() == true
    */
	void gotoLast();

	/*!
		\brief  Coloca el cursor en el nodo anterior
		\pre 	isEmpty() == false
		\pre 	isFirstItem() == false
    */
	void gotoPrevious();

	/*!
		\brief  Coloca el cursor en el nodo siguiente
		\pre 	isEmpty() == false
		\pre 	isLastItem() == false
    */
	void gotoNext();

	bool find(ed::Municipio const & m);

	void insert(ed::Municipio const & m);

	void remove();

	void removeAll();

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaMunicipios
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaMunicipios_HPP__
