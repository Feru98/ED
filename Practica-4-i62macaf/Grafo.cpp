/*! 
   \file  Grafo.cpp
   \brief Fichero que contiene el código de las funciones de la clase Grafo
*/


// Ficheros de cabecera
#include <iostream>


#include "Grafo.hpp"


void ed::Grafo::ordenaLados()
{
	ed::Lado aux;

	for(int j=0 ; j<lados(); j++)
	{
		for(int i=0; i<lados() ; i++)
		{
			if(vLados_[i+1].getPeso()<vLados_[i].getPeso())
			{
				aux=vLados_[i];
				vLados_[i]=vLados_[i+1];
				vLados_[i+1]=aux;
			}
		}
	}
}





ed::Grafo ed::Grafo::Prim()
{
	
	#ifndef NDEBUG
		assert(!isEmpty());
	 #endif //NDEBUG

	ed::Grafo aux;

	//vector de vertices no visitados
	std::vector<int> nu;
	//vector de vertices visitados
	std::vector<int> u;

	for(int i=0 ; i<getSize() ; i++)
	{
		aux.addVerticeSinLado(vVertices_[i]);
	} 

	//el vector de visitados contiene el primer vertice y el de no visitados todos los demás
	u.push_back(0);

	for(int i=0; i<getSize(); i++)
	{	
		nu.push_back(i+1);
	}


	//mientras el vector de no visitados no esta vacio
	while(!nu.empty()) 
	{

		ed::Lado l;
		std::vector<int>::iterator borrar;
		std::vector<ed::Vertice> v;
		v.resize(2);

		int origen = -1;
		int destino = -1;
		
		float peso = std::numeric_limits<float>::infinity();

		//cogemos el menor lado posible que una un vertice visitado y uno no visitado
		for(std::vector<int>::iterator x = nu.begin() ;  x!=nu.end() ; x++ )
		{
			for(std::vector<int>::iterator y = u.begin() ; y!=u.end(); y++ )
			{
				if(adjacent(vVertices_[*x], vVertices_[*y]))
				{

					v[0]=vVertices_[*x];
					v[1]=vVertices_[*y];
					l.setData(v);

					for(int a=0 ; a<lados() ; a++ )
					{
						if(l==vLados_[a])
						{
							l=vLados_[a];
						}
					}
					//gotoLado(l);
					//std::cout<<l.getPeso()<<" "<<peso<<std::endl;
					if(l.getPeso() < peso)
					{
						
						destino = *x;
						origen = *y;
						borrar = x;
						peso = l.getPeso();
					}
				}
			}
		}

		//insertamos el lado cogido anteriormente y borramos el vertice no visitado de su vector y lo añadimos a visitados
		if(origen != -1 && destino != -1)
		{

			v[0]=vVertices_[destino];
			v[1]=vVertices_[origen];
			l.setData(v);

			for(int a=0 ; a<lados() ; a++ )
					{
						if(l==vLados_[a])
						{
							l=vLados_[a];
						}
					}

			aux.addLado(l);

			nu.erase(borrar);
			u.push_back(destino);
		}
		//en el caso de que quedaran vertices no conectados para que no se quede en bucle infinito esperando a que se vaciara el vector de no visitados
		else
		{
			u.push_back(nu[0]);
			nu.erase(nu.begin());
		}
	}

	//aux.imprimirMatriz();

	return aux;
}




ed::Grafo ed::Grafo::Kruskal()
{
	ed::Grafo aux;
	//ordenamos los lados
	std::sort(vLados_.begin(), vLados_.end() , this->sortLados);
	
	

	for(int i=0 ; i<getSize() ; i++)
	{
		aux.addVerticeSinLado(vVertices_[i]);
	} 
	//cada nodo es su propio padre en la primera interaccion
	aux.makep();

	for(int j=0 ; j<lados(); j++)
	{
		int x=(vLados_[j].first()).getLabel();
		int y=(vLados_[j].second()).getLabel();

		//std::cout<<"etiqueta "<<x<<" "<<y<<std::endl;
		
		//comprobamos que los vertices que une el lado que vamos a añadir estan en distintos conjuntos, es decir no tienen un padre en comun.
		if(!aux.same(x,y) )
		{
			aux.addLado(vLados_[j]);
			//unimos los conjuntos
			aux.unionn(x,y);

			//std::vector<ed::Vertice> h = vLados_[j].getData();
			//std::vector<float> h1 = h[0].getData();
			//std::vector<float> h2 = h[1].getData();
			//std::cout<<"Añado "<<h1[0]<<h1[1]<<" "<<h2[0]<<h2[1]<<" "<<vLados_[j].getPeso()<<std::endl;
		}
	}

	//aux.imprimirMatriz();

	return aux;

}