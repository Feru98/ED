/*!
	\file   ListaDoblementeEnlazadaOrdenadaMunicipios.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Municipios
	\author  
	\date  
	\version 1.0
*/

// Para comprobar las pre y post-condiciones
#include <cassert>

#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"
#include "NodoDoblementeEnlazadoMunicipio.hpp"
#include "NodoMunicipioInterfaz.hpp"
#include "Municipio.hpp"

// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE ListaDoblementeEnlazadaOrdenadaMunicipios

//Observadores


	int ed::ListaDoblementeEnlazadaOrdenadaMunicipios::nItems() const
	{
		int n=0;
		if(isEmpty())
		{
			return 0;
		}
		ed::NodoDoblementeEnlazadoMunicipio * iterador;
		iterador= getHead();
		while(iterador->getNext()!=NULL)
		{
			iterador=iterador->getNext();
			n++;
		}
		n++;
		return n ;
	}

	


//Modificadores

	void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoHead()
	 {
	 	#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		  setCurrent(getHead());

		  	#ifndef NDEBUG	
		  	assert(isFirstItem());
		  #endif //NDEBUG
	 }


	 void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoLast()
	 {
	 	#ifndef NDEBUG
		  	assert(!isEmpty());
		  #endif //NDEBUG

		  	while(!isLastItem())
		  	{
		  		setCurrent( getCurrent()->getNext() ) ;
		    }

		  	#ifndef NDEBUG	
		  	assert(isLastItem());
		  #endif //NDEBUG
	 }


	 void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoPrevious()
	 {
	 	#ifndef NDEBUG
		  	assert(!isEmpty());
		  	assert(!isFirstItem());
		  #endif //NDEBUG

		  	setCurrent( getCurrent()->getPrevious() ) ;
	 }


	 void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::gotoNext()
	 {
	 	#ifndef NDEBUG
		  	assert(!isEmpty());
		  	assert(!isLastItem());
		  #endif //NDEBUG

		  	setCurrent( getCurrent()->getNext() ) ;
	 }

	 bool ed::ListaDoblementeEnlazadaOrdenadaMunicipios::find(ed::Municipio const & m)
	 {
	 	if(isEmpty())
	 	{
	 		return false;
	 	}
	 	gotoHead();
	 	int a = 1;
	 	ed::Municipio aux ;

	 	while(a==1)
	 	{
	 		aux=getCurrentItem();
	 		if(aux==m)
	 		{
	 			#ifndef NDEBUG
		  	assert(getCurrentItem()==m); 	
		  #endif //NDEBUG

	 			return true ;
	 		}
	 		if(!(aux<m))
	 		{
	 			#ifndef NDEBUG
		  		assert( (m<getCurrentItem()) or (isLastItem()) ) ; 	
		 	 	#endif //NDEBUG

	 			return false;
	 		}
	 		else
	 		{
	 		
	 			if(!isLastItem())
	 			{
	 				gotoNext();
	 			}
	 			else
	 			{
	 				a=0;
	 			}
	 		}
	 	}

	 	#ifndef NDEBUG
		  		assert( (m<getCurrentItem()) or (isLastItem()) ) ; 	
		 	 	#endif //NDEBUG

	 	return false;
	 }


	 void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::insert(ed::Municipio const & m)
	 {
	 	#ifndef NDEBUG
		  	assert(!find(m)); 	
		  #endif //NDEBUG

		find(m);
		int old= nItems();
	 	ed::Municipio aux ;
	 	ed::NodoDoblementeEnlazadoMunicipio * nodo = new ed::NodoDoblementeEnlazadoMunicipio(m, NULL , NULL) ;

	 	//usar el find para que deje el cursor en su sitio y ahorrarse el while 
	 	//hacer 4 condiciones después,una si esta vacia, una para insertar antes de la head, otra al final 
	 	//y por ultimo en medio de dos cosas
	 	//el find nos encuentra uno mas grande, asi que vamos al anterior para insertarlo a continuación
	 	
	 	

	 	if(isEmpty())
	 	{
	 		setCurrent(nodo);
	 		setHead(nodo);
	 		_current->setNext(NULL);
	 		_current->setPrevious(NULL);

	 	}
	 	
	 	else if(isFirstItem())  
	 	{
	 		if( m<getCurrentItem() )
	 		{
	 		//insertar en la cabeza
	 		//1 nodo->siguiente debe apuntar a Lista.
			//2 nodo->anterior apuntará a Lista->anterior.
			//3 Lista->anterior debe apuntar a nodo
	 			//std::cout<<getCurrentItem()<<std::endl;
			nodo->setNext( _current );
			//nodo->setPrevious(_current->getPrevious());
			_current->setPrevious(nodo);
			setHead(nodo);

			gotoHead();
			//std::cout<<"La cabeza es"<<getHead()->getItem()<<"Y el siguiente item es"<<getHead()->getNext()->getItem()<<std::endl;
			}

			else
			{
			
	 		_current->setNext(nodo);
	 		nodo->setPrevious(_current);

	 		setCurrent(nodo);

			}


	 	}


	 	else if(isLastItem() && (getCurrentItem()<m ))
	 	{
	 		
	 		//insertar al final

    		//nodo->siguiente debe apuntar a Lista->siguiente (NULL).
    		//Lista->siguiente debe apuntar a nodo.
    		//nodo->anterior apuntará a Lista.

	 		nodo->setNext( NULL );
	 		_current->setNext(nodo);
	 		nodo->setPrevious(_current);

    		gotoLast();

	 	}
	 	else
	 	{
	 		ed::NodoDoblementeEnlazadoMunicipio * aux;
	 		
	 		//insertar en medio

	 		nodo->setNext( getCurrent() );
	 		aux=getCurrent()->getPrevious();
	 		_current->setPrevious(nodo);
	 		nodo->setPrevious( aux );
	 		aux->setNext(nodo);

	 		setCurrent(nodo);
	 	}

	 	#ifndef NDEBUG
		  	assert(getCurrentItem()==m); 
		  	assert(nItems()== old + 1); 	
		  #endif //NDEBUG
	 }


void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::remove()
{
	#ifndef NDEBUG
		  	assert(!isEmpty()); 	
		  #endif //NDEBUG


	if(nItems()==1)
	{
		delete getCurrent();
		setCurrent(NULL);
		setHead(NULL);
	}
	else if(isFirstItem())
	{
		setHead(getHead()->getNext());
		delete getCurrent();
		setCurrent(getHead());
		getCurrent()->setPrevious(NULL);
		
	}
	else if(isLastItem())
	{
		setCurrent(getCurrent()->getPrevious() );
		delete getCurrent()->getNext();
		getCurrent()->setNext(NULL);
	}
	else
	{    
	getCurrent()->getNext()->setPrevious(getCurrent()->getPrevious());
	gotoNext();
	delete getCurrent()->getPrevious()->getNext();
	getCurrent()->getPrevious()->setNext(getCurrent());                   

	}
}

void ed::ListaDoblementeEnlazadaOrdenadaMunicipios::removeAll()
{
	if(!isEmpty())
	{
	gotoHead() ;
	ed::NodoDoblementeEnlazadoMunicipio * aux = getCurrent();
	
	while(aux != NULL)
	{
		aux= getCurrent()->getNext() ;
		delete getCurrent();
		setCurrent(aux);

	}
	setHead(NULL);
	setCurrent(NULL);

	#ifndef NDEBUG
		  	assert(isEmpty()); 	
		  #endif //NDEBUG
	}
}