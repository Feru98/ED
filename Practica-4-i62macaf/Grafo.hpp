/*! 
   \file Grafo.hpp
   \brief Fichero de la clase Grafo
   \author Fernando Maestre Carmona
*/


#ifndef _GRAFO_HPP_
#define _GRAFO_HPP_


// Entrada y salida 
#include <iostream>
#include "macros.hpp"
#include <vector>
#include "Vertice.hpp"
#include "Lado.hpp"

// Para controlar las precondiciones y postcondiciones mediante asertos
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <limits>
// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;


#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales

// Se incluye la clase Grafo dentro del espacio de nombres de la asigantura: ed
namespace ed {

//! Definición de la clase Grafo
class Grafo
{
	
	//! \name Atributos privados de la clase Grafo
	private:

		std::vector< std::vector<float> > Matriz_;	//!<Matriz de adyacencia
		std::vector<ed::Lado> vLados_;				//!< Vector de lados
		std::vector<ed::Vertice> vVertices_;		//!< Vector de vertices

		int padre[100]; //!< Vector que guarda el padre de cada nodo, necesario para aplicar kruskal

		bool dirigido_;			//!< Indica si el grafo es dirigido o no 
		int currentv_; //!<  Entero que indica en que posicion del vector de vertices nos encontramos
		int currentl_; 	//!< Entero que indica en que posicion del vector de lados nos encontramos

	//! \name Funciones o métodos públicos de la clase Grafo
	public:

		//! \name Constructores de la clase Grafo

		/*! 
		\brief   Constructor sin argumentos
		*/
		Grafo()
		{
			Matriz_.resize(0);  
			vLados_.resize(0);	
			vVertices_.resize(0);
			dirigido_=0;

			currentv_ = -1;
			currentl_ = -1;

			
		}

		/*
		Grafo(bool dirigido)
		{
			Matriz_.resize(0);
			vLados_.resize(0);
			vVertices_.resize(0);
			dirigido_=dirigido;

			currentv_ = -1;
			currentl_ = -1;
		}
		*/

		//! \name Kruskal: funciones para usar kruskal

		/*! 
		\brief   Función que pone a cada nodo como su propio padre
		*/
		inline void makep()
		{
			for (int i = 0; i < getSize() ; ++i)
			{
				padre[i]=i;
			}
		}

		/*! 
		\brief   Función que devuelve el padre del nodo pasado por parametros
		\param 	 x: entero que representa la etiqueta de un nodo
		\return	 entero que representa la etiqueta del padre
		*/
		inline int find(int x)
		{
			if(x == padre[x])
			{
				return x;
			}
			else
			{

			 return find(padre[x]);
			}
		}

		/*! 
		\brief   Función que une a un nodo y todos los que estén conectados a el al cojunto de otro nodo
		\param 	x: entero que representa la etiqueta de un nodo
		\param  y: entero que representa la etiqueta de un nodo
		*/
		inline void unionn(int x , int y)
		{
			int a = find(x);
			int b = find(y);
			padre[a]=b;
		}

		/*! 
		\brief   Función que dice si dos nodos pertenecen al mismo conjunto en un grafo
		\param 	x: entero que representa la etiqueta de un nodo
		\param  y: entero que representa la etiqueta de un nodo
		*/
		inline bool same(int x , int y)
		{
			if(find(x)==find(y))
			{
				return true;
			}
			else return false;
		}

		//! \name Observadores: funciones de consulta de la clase Grafo


		/*! 
		\brief   Función que devuelve el tamaño del vector de vertices
		\note    Función inline
		\return  entero con el número de vertices
		*/
		inline int getSize()const{return vVertices_.size();}



		/*! 
		\brief   Función que devuelve el tamaño del vector de lados
		\note    Función inline
		\return  entero con el número de lados
		*/
		inline int lados()const{return vLados_.size();}


		/*! 
		\brief   Función que devuelve el si el grafo está vacio o no
		\note    Función inline
		\return  bool true si está vacio, false si no.
		*/
		inline bool isEmpty() const
		{
			if(getSize()==0){return true;}
			else{return false;}
		}


		/*
		inline bool isDirected() const
		{
			if(dirigido_==1){return true;}
			else{return false;}
		}
		*/

		/*! 
		\brief   Función que devuelve el si los vertices pasados por parametros son adyacentes(conectados por un lado)
		\note    Función inline
		\param 	u: vertice
		\param  v: vertice
		\return  bool true si son adyacentes, false si no.
		*/
		inline bool adjacent(ed::Vertice u , ed::Vertice v)
		{
			ed::Lado aux;
			
			for(int i =0 ; i<lados() ; i++)
			{
				
				aux=vLados_[i];
				if( (aux.has(u)) and (v==aux.other(u))  )
				{
					return true;
				}

				
					
			}
			return false;
		}
		
		
		/*! 
		\brief   Función que devuelve el si el grafo tiene el vertice pasado por argumentos o no
		\param 	v: vertice que queremos saber si esta en el grafo o no
		\note    Función inline
		\return  bool true si v está en el grafo, false si no.
		*/
		inline bool hasVertice(ed::Vertice v)
		{
			for (int i = 0; i < getSize(); ++i)
			{
				if(v==vVertices_[i])
				{
					return true;
				}
			}
			return false;
		}


		/*! 
		\brief   Función que devuelve el si el grafo tiene el lado pasado por argumentos o no
		\param 	l: lado que queremos saber si esta en el grafo o no
		\note    Función inline
		\return  bool true si l está en el grafo, false si no.
		*/
		inline bool hasLado(ed::Lado l)
		{
			for (int i = 0; i < lados(); ++i)
			{
				if(l==vLados_[i])
				{
					return true;
				}
			}
			return false;
		}


		/*! 
		\brief   Función que devuelve el si el cursor está en un nodo del grafo
		\note    Función inline
		\return  bool true si está en el grafo, false si no.
		*/
		inline bool hasCurrVertice()const
		{
			if(currentv_>=0 && currentv_<getSize()){return true;}
			else{return false;}
		}



		/*! 
		\brief   Función que devuelve el vertice en el que se encuentra el cursor
		\note    Función inline
		\return  ed::Vertice en el que se encuentra el cursor
		*/
		inline ed::Vertice CurrVertice()const
		{
			#ifndef NDEBUG
		  	assert(hasCurrVertice());
		  #endif //NDEBUG

		  	return vVertices_[currentv_] ;

		}


		/*! 
		\brief   Función que devuelve el si el cursor está en un lado del grafo
		\note    Función inline
		\return  bool true si está en el grafo, false si no.
		*/
		inline bool hasCurrLado()const
		{
			if(currentl_>=0 && currentv_<lados()){return true;}
			else{return false;}
		}


		/*! 
		\brief   Función que devuelve el lado en el que se encuentra el cursor
		\note    Función inline
		\return  ed::Lado en el que se encuentra el cursor
		*/
		inline ed::Lado CurrLado()const
		{
			#ifndef NDEBUG
		  	assert(hasCurrLado());
		  #endif //NDEBUG

		  	return vLados_[currentl_];

		}


		/*! 
		\brief   Función que devuelve la distancia entre dos vertices pasados por parametros 
		\note    Función inline
		\param 	 u: vertice
		\param   v: vertice
		\return  resultado float
		*/
		inline float distancia(ed::Vertice u , ed::Vertice v )
		{
			float x , y , resultado ;
			std::vector<float>  aux1;
			std::vector<float>  aux2;
			aux1.resize(2);
			aux2.resize(2);
			aux1=u.getData();
			aux2=v.getData();

			x=aux2[0]-aux1[0];
			y=aux2[1]-aux1[1];


			x= pow(x,2);
			y= pow(y,2);

			resultado= x+y;

			resultado= sqrt(resultado);

			return resultado;

		}


		/*! 
		\brief   Función que devuelve la suma de los pesos de todos los lados de un grafo
		\note    Función inline
		\return  suma float
		*/
		inline float sumaPesos()
		{
			float suma=0;

			for (int i = 0; i < lados(); ++i)
			{
				suma= suma + vLados_[i].getPeso();
				
			}
			return suma;
		}

		/*! 
		\brief   Función que imprime la matriz por pantalla
		\note    Función inline
		*/
		inline void imprimirMatriz()const
		{
			
			for(int i=0; i<getSize(); i++)
			{
				for (int j = 0; j<getSize(); j++)
				{
					std::cout<<Matriz_[i][j]<<"\t";
				}
				std::cout<<"\n";
			}
			
		}


		/*! 
		\brief   Función que devuelve un elemento de la matriz de adyacencia 
		\note    Función inline
		\param 	i: entero de la fila
		\param  j: entero de la columna
		\return  elemento de la matriz
		*/
		inline float getMatriz(int i , int j)const
		{
			return Matriz_[i][j];
		}

		
		/*! 
		\brief   Función que sirve para ordenar los lados
		\note    Función inline
		\param 	 x: lado
		\param   y: lado
		\return true si el lado x es más pequeño que el y
		*/
		inline static bool sortLados(Lado x , Lado y)
		{
			return x.getPeso()<y.getPeso();
		}

		//! \name Funciones de modificación de la clase Grafo


		/*! 
		\brief   Función que ordena los lados del grafo
		*/
		void ordenaLados();

		/*! 
		\brief   Función que aplica el algoritmo de Kruskal
		\return  grafo que representa el arbol de coste minimo
		*/
		ed::Grafo Kruskal();

		/*! 
		\brief   Función que aplica el algoritmo de Prim
		\return  grafo que representa el arbol de coste minimo
		*/
		ed::Grafo Prim();


		/*! 
		\brief Función que asigna un nuevo vertice al grafo pero no lo une con los demás
		\note  Función inline 
		\param aux: nuevo vertice
		\pre  el vertice no se encuentra en el grafo
		*/
		inline void addVerticeSinLado(ed::Vertice aux)
		{
			#ifndef NDEBUG
		  	assert(!hasVertice(aux));
		  #endif //NDEBUG
			
			aux.setLabel(getSize());
			//vVertices_.resize(getSize()+1);
			vVertices_.push_back(aux);


			int b=Matriz_.size()+1;
			Matriz_.resize(b);
			for (int a = 0; a < b; a++)
			{
				Matriz_[a].resize(b,0);
			}

		}


		/*! 
		\brief Función que asigna un nuevo vertice al grafo y lo une con todos los demás nodos
		\note  Función inline 
		\param aux: nuevo vertice
		\pre  el vertice no se encuentra en el grafo
		*/
		inline void addVertice(ed::Vertice aux)
		{
			#ifndef NDEBUG
		  	assert(!hasVertice(aux));
		  #endif //NDEBUG


			aux.setLabel(getSize());
			//vVertices_.resize(getSize()+1);
			vVertices_.push_back(aux);


			int b=Matriz_.size()+1;
			Matriz_.resize(b);
			for (int a = 0; a < b; a++)
			{
				Matriz_[a].resize(b,0);
			}

			
			ed::Lado l ;
			std::vector<ed::Vertice> v;
			v.resize(2);
			float d;

			for(int j=0 ; j<getSize() ; j++)
			{
				if(aux.getLabel() != vVertices_[j].getLabel())
				{
					v[0]=aux;
					v[1]=vVertices_[j];
				l.setData(v);
				d=distancia(aux,vVertices_[j] );
				l.setPeso(d);
				//std::cout<<d<<std::endl;
				addLado(l);
				}
			}
			//std::cout<<vLados_.size()<<std::endl;
			//std::vector<float> h = aux.getData();
			//v.resize(2);
			//std::cout<<"Añado"<<h[0]<<" "<<h[1]<<" "<<aux.getLabel()<<std::endl;

		}


		/*! 
		\brief Función que asigna un nuevo lado al grafo
		\note  Función inline 
		\param l: nuevo lado
		*/
		inline void addLado(ed::Lado l)
		{
			l.setLabel(lados());
			//vLados_.resize(lados()+1);
			vLados_.push_back(l);

			std::vector<ed::Vertice> aux = l.getData();
			float p = l.getPeso();

			Matriz_[aux[0].getLabel()][aux[1].getLabel()]= p ;
			Matriz_[aux[1].getLabel()][aux[0].getLabel()]= p ;

		}


		/*! 
		\brief Función que borra el vertice en el que se encuentra el cursor
		\note  Función inline 
		\pre 	El cursor se encuentra en un vertice
		*/
		inline void removeVertice()
		{
			#ifndef NDEBUG
		  	assert(hasCurrVertice());
		  #endif //NDEBUG

		  std::vector<ed::Vertice> v;
		  ed::Vertice aux = CurrVertice();
		  int pos=aux.getLabel();

		  for (int i = 0; i < getSize(); ++i)
		  	{
		  		
		  			Matriz_[i].resize(0);
		  		
		  	}
		  	Matriz_.resize(0); 

		  vVertices_.erase(vVertices_.begin() +pos);

		  for(int i=pos+1 ; i<getSize() ; i++)
		  {
		  	vVertices_[i].setLabel(vVertices_[i].getLabel()-1);
		  }

		  v=vVertices_;
		  int h=v.size();

		  	
		 	 
			vLados_.clear();	
			vVertices_.clear();

			for(int i=0 ; i<h ; i++)
		  {
		  		addVertice(v[i]);
		  }
		}


		/*! 
		\brief Función que borra todos los vertices del grafo
		\note  Función inline
		\post  El grafo está vacio
		*/
		inline void removeAll()  
		{
		  	gotofirstVertice();
		  	while(!isEmpty())
		  	{
		  	removeVertice();
		  	//nextVertice(); las etiquetas pasan a ser -1 por lo tanto no hace falta
		  	}
		  	
		  	
		  	#ifndef NDEBUG
		  	assert(isEmpty());
		  #endif //NDEBUG
		  
		}


		
		/*! 
		\brief Función que borra el lado en el que se encuentra el cursor
		\note  Función inline 
		\pre 	El cursor se encuentra en un lado
		*/
		inline void removeLado()
		{
			#ifndef NDEBUG
		  	assert(hasCurrLado());
		  #endif //NDEBUG

		  	ed::Lado aux = CurrLado();
		  	int pos = aux.getLabel();

		  	std::vector<ed::Vertice> v = aux.getData();

			Matriz_[v[0].getLabel()][v[1].getLabel()]= 0 ;
			Matriz_[v[1].getLabel()][v[0].getLabel()]= 0 ;


		  vLados_.erase(vLados_.begin() + pos);

		  for(int i=pos+1 ; i<lados() ; i++)
		  {
		  	vLados_[i].setLabel(vLados_[i].getLabel()-1);
		  }
		}


		/*! 
		\brief Función que mueve el cursor al vertice pasado por parametros
		\param v: vertice
		\note  Función inline 
		\pre 	El grafo contiene el vertice
		\post   Los datos del vertice actual y el pasado por argumentos deben ser los mismos
		*/
		inline void gotoVertice(ed::Vertice v)
		{
			#ifndef NDEBUG
		  	assert(hasVertice(v));
		  #endif //NDEBUG

		  	for (int i = 0; i < getSize(); ++i)
			{
				if(v==vVertices_[i])
				{
					currentv_=vVertices_[i].getLabel();
				}
			}


			#ifndef NDEBUG
		  	assert(CurrVertice().getData()==v.getData());
		  #endif //NDEBUG
		}


		/*! 
		\brief Función que mueve el cursor al primer elemento
		\note  Función inline 
		\pre 	El grafo no está vacio
		*/
		inline void gotofirstVertice()
		{
			if(!isEmpty())
			{
				currentv_=0;
			}

			
		}

		/*! 
		\brief Función que mueve el cursor al siguiente elemento
		\note  Función inline 
		\pre 	El cursor se encuentra en un vertice
		*/
		inline void nextVertice()
		{
			#ifndef NDEBUG
		  	assert(hasCurrVertice());
		  #endif //NDEBUG

		  	currentv_++;
		}



		/*! 
		\brief Función que mueve el cursor al lado pasado por parametros
		\param l: lado
		\note  Función inline 
		\pre 	El grafo contiene el lado
		\post   Los datos del lado actual y el pasado por argumentos deben ser los mismos
		*/
		inline void gotoLado(ed::Lado l)
		{
			#ifndef NDEBUG
		  	assert(hasLado(l));
		  #endif //NDEBUG

			currentl_=l.getLabel();

			/*
			#ifndef NDEBUG
		  	assert(CurrLado().getData()==l.getData());
		  #endif //NDEBUG
		  */
		}


		/*! 
		\brief Función que mueve el cursor al primer lado
		\note  Función inline 
		\pre 	El grafo no está vacio
		*/
		inline void gotofirstLado()
		{
			if(!isEmpty())
			{
				currentl_=0;
			}

			
		}


		/*! 
		\brief Función que mueve el cursor al siguiente elemento
		\note  Función inline 
		\pre 	El cursor se encuentra en un lado
		*/
		inline void nextLado()
		{
			#ifndef NDEBUG
		  	assert(hasCurrLado());
		  #endif //NDEBUG

		  	currentl_++;
		}
		

		/*!
  		\brief     Sobrecarga del operador de salida o escritura "<<"
		\param     f Flujo de salida
		\param     g grafo pasado como referencia constante
    */
		friend std::ostream &operator<<(std::ostream &f, const Grafo &g)
		{
			for(int i=0; i < g.getSize() ; i++)
			{
				for(int j=0; j < g.getSize() ; j++)
				{
					f<<g.getMatriz(i,j)<<"\t";
				}

				f<<"\n";
			}

			return f;	
		}

};





} //end namespace ed

#endif