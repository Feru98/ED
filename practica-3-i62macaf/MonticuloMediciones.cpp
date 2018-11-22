/*!
	\file MonticuloMediciones.cpp
	\brief Fichero que contiene el código de las funciones de la clase MonticuloMediciones.
	\author 
	\date 
*/

//#include <vector>

#include <cassert>

#include "Medicion.hpp"

#include "MonticuloMediciones.hpp"

////////////////////////////////////////////////////////////////////

// Métodos privados de la clase MonticuloMediciones
		void ed::MonticuloMediciones::ShiftUp(int i)
		{
			#ifndef NDEBUG
		  	assert(i>=0);
		  	assert(i<size());
		  #endif //NDEBUG

			if( (i>0) and (v[i].getPrecipitacion()>v[getParent(i)].getPrecipitacion()) )
			{
				ed::Medicion aux;
				aux=v[i];
				v[i]=v[getParent(i)];
				v[getParent(i)]=aux;

				ShiftUp(getParent(i));
			}

			#ifndef NDEBUG
			if(!(v[i]==top()))
			{
				assert(v[i].getPrecipitacion()<=v[getParent(i)].getPrecipitacion());
			}
		  	if(getLeftChild(i)<size())
		  	{
		  		assert(v[i].getPrecipitacion()>=v[getLeftChild(i)].getPrecipitacion());
		  	}
		  	if(getRightChild(i)<size())
		  	{
		  		assert(v[i].getPrecipitacion()>=v[getRightChild(i)].getPrecipitacion());
		  	}
		  #endif //NDEBUG

		}

		void ed::MonticuloMediciones::ShiftDown(int i)
		{
			#ifndef NDEBUG
		  	assert(i>=0);
		  	assert(i<size());
		  #endif //NDEBUG

		  	int n = i ;
		  	int lc = getLeftChild(i);
		  	int rc = getRightChild(i);
		  	ed::Medicion a;
		  	ed::Medicion b;

		  	if(	(lc<(size())) && (v[lc].getPrecipitacion()>v[n].getPrecipitacion()) )
		  	{
		  		n=lc ;
		  	}
		  	if(	(rc<(size())) && (v[rc].getPrecipitacion()>v[n].getPrecipitacion()) )
		  	{
		  		n=rc ;
		  	}

		  	if( i != n )
		  	{

				a=getElement(i);
				b=getElement(n);

				setElement(i , b);
				setElement(n , a);


				ShiftDown(n);
		  	}

		  	
		  	#ifndef NDEBUG
		  	
			if(!(v[i]==top()))
			{
				assert(v[i].getPrecipitacion()<=v[getParent(i)].getPrecipitacion());
			}
		  	if(getLeftChild(i)<size())
		  	{
		  		assert(v[i].getPrecipitacion()>=v[getLeftChild(i)].getPrecipitacion());
		  	}
		  	if(getRightChild(i)<size())
		  	{
		  		assert(v[i].getPrecipitacion()>=v[getRightChild(i)].getPrecipitacion());
		  	}
		  	
		  #endif //NDEBUG
		  
		  		
		}

////////////////////////////////////////////////////////////////////////////////////7

// Métodos públicos de la clase MonticuloMediciones

		// COMPLETAR




