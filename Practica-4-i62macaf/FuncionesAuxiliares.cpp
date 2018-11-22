/*!
  \file   FuncionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Fernando Maestre Carmona
  \date  Mayo-2018 
*/


#include <iostream>

#include <fstream>

#include <string>

#include "FuncionesAuxiliares.hpp"

#include "macros.hpp"

#include <vector>



int ed::menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Grabar el grafo en un fichero";


	PLACE(posicion++,10);
	std::cout << "[2] Cargar el grafo desde un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Ver si el grafo está vacio";

	//////////////////////////////////////////////////////////////////////////////
	
 
	PLACE(posicion++,10);
	std::cout << "[4] Mostrar datos del grafo";

	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar arbol abarcador minimo con Kruskal";

	PLACE(posicion++,10);
	std::cout << "[6] Grabar Kruskal en un fichero";

	posicion++;

	PLACE(posicion++,10);
	std::cout << "[7] Mostrar arbol abarcador minimo con Prim";

	PLACE(posicion++,10);
	std::cout << "[8] Grabar Prim en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
	
	PLACE(posicion++,10);
	std::cout << "[9] Borrar Grafo";

	
	

	PLACE(posicion++,10);
	std::cout << "[10] Insertar Vertice";

	
	PLACE(posicion++,10);
	std::cout << "[11] Borrar Vertice";
	
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[12] Mostrar longitud del arbol mínimo";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}








void ed::cargarGrafoDeFichero(std::string const & nombreFichero, ed::Grafo & grafo) 
{
  

	std::string aux ;
	ed::Vertice vertice ;
	std::vector<float>  v;
	v.resize(2);
	std::ifstream fich(nombreFichero.c_str());

	if(fich.is_open())
	{
		grafo.removeAll();

		
		while(getline(fich, aux, ' '))
		{
		v[0]=(atoi(aux.c_str()));
		getline(fich, aux, '\n');
		v[1]=(atoi(aux.c_str()));

		vertice.setData(v);
		

		//std::cout<<"Voy a añadir"<<v[0]<<" "<<v[1]<<std::endl;
		if(!grafo.hasVertice(vertice))
		{
 	 		grafo.addVertice(vertice);
 	 	}
 	 	else
 	 	{
 	 		std::cout<<"El fichero algun vertice repetido"<<std::endl;
 	 		std::cin.ignore();
 	 	}
 	 	
 		}


 		fich.close();
		
	}
	else
	{
		std::cout<<BIRED<<"No se pudo abrir el fichero"<<RESET<<std::endl;
		std::cin.ignore();
	}
	return;

}


void ed::grabarGrafoEnFichero(std::string const & nombreFichero, 
							      ed::Grafo & grafo)
{
  
 	if(!grafo.isEmpty())
 {
 	ed::Vertice v;
 	std::vector<float> aux;
	std::ofstream fich(nombreFichero.c_str());

	if(fich.is_open() )
	{
		fich<<"Vertices:  \n";
		grafo.gotofirstVertice();
		for(int i=0 ; i<grafo.getSize(); i++)
		{
			
			v=grafo.CurrVertice();
			aux=v.getData();
			fich<<"("<<aux[0]<<","<<aux[1]<<")\n";
			grafo.nextVertice();
		
		}

		fich<<"Matriz de adyacencia:  \n";
		fich<<grafo;
	}
 }
 else
 {
 	std::cout<<BIYELLOW<<"Grafo vacio"<<RESET<<std::endl;
 	std::cin.ignore();
 }

	return;
}


void ed::cargarGrafo(ed::Grafo & grafo)
{

	std::string fichero;
	std::cout<<BIYELLOW<<"Introduzca el fichero del que quiere cargar el grafo"<<RESET<<std::endl;
	std::cin>>fichero;
	cargarGrafoDeFichero(fichero, grafo);
 		return;
}

void ed::grabarGrafo(ed::Grafo & grafo)
{

	if(!grafo.isEmpty())
	{
	std::string fichero;
	std::cout<<BIYELLOW<<"Introduzca el fichero en el que quiere grabar el grafo"<<RESET<<std::endl;
	std::cin>>fichero;
	grabarGrafoEnFichero(fichero, grafo);
	}
	else
 	{
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 	std::cin.ignore();
 	}
	return;
}

void ed::imprimirGrafo(ed::Grafo & grafo)
{
	

 	if(!grafo.isEmpty())
 {
		ed::Vertice v;
 		std::vector<float> aux;
		
		std::cout<<"Vertices: "<<std::endl;
		grafo.gotofirstVertice();
		for(int i=0 ; i<grafo.getSize(); i++)
		{
			v=grafo.CurrVertice();
			aux=v.getData();
			std::cout<<"("<<aux[0]<<","<<aux[1]<<")"<<std::endl;
			grafo.nextVertice();	
		}
		
		std::cout<<"\n Matriz de adyacencia: "<<std::endl;
		grafo.imprimirMatriz();
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}

void ed::prim(ed::Grafo & grafo)
{

 	if(!grafo.isEmpty())
 {
 	ed::Grafo g;
	g=grafo.Prim();
	imprimirGrafo(g);
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}

void ed::primFichero(ed::Grafo & grafo)
{

 	if(!grafo.isEmpty())
 {
 	ed::Grafo g;
	g=grafo.Prim();
	grabarGrafo(g);
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}


void ed::kruskal(ed::Grafo & grafo)
{

 	if(!grafo.isEmpty())
 {
 	ed::Grafo g;
	g=grafo.Kruskal();
	imprimirGrafo(g);
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}



void ed::kruskalFichero(ed::Grafo & grafo)
{

 	if(!grafo.isEmpty())
 {
 	ed::Grafo g;
	g=grafo.Kruskal();
	grabarGrafo(g);
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}


void ed::insertarVertice(ed::Grafo & grafo)
{
	ed::Vertice aux;
	std::vector<float> v;
	v.resize(2);
	
		std::cout<<BIBLUE<<"Introduzca la primera coordenada del vertice"<<RESET<<std::endl;
		std::cin>>v[0];
		std::cin.ignore();
		std::cout<<BIBLUE<<"Introduzca la segunda coordenada del vertice"<<RESET<<std::endl;
		std::cin>>v[1];
		std::cin.ignore();

		aux.setData(v);

		if(grafo.hasVertice(aux))
		{
			std::cout<<BIRED<<"El vertice ya se encuentra en el grafo"<<RESET<<std::endl;
		}
		else
		{
			grafo.addVertice(aux);
		}
	

	return;
}


void ed::borrarVertice(ed::Grafo & grafo)
{
	if(!grafo.isEmpty())
	{
	ed::Vertice aux;
	std::vector<float> v;
	v.resize(2);
	
		std::cout<<BIBLUE<<"Introduzca la primera coordenada del vertice"<<RESET<<std::endl;
		std::cin>>v[0];
		std::cin.ignore();
		std::cout<<BIBLUE<<"Introduzca la segunda coordenada del vertice"<<RESET<<std::endl;
		std::cin>>v[1];
		std::cin.ignore();

		aux.setData(v);

		if(!grafo.hasVertice(aux))
		{
			std::cout<<BIRED<<"El vertice no se encuentra en el grafo"<<RESET<<std::endl;
		}
		else
		{
			grafo.gotoVertice(aux);
			grafo.removeVertice();
		}
	}
	else
	{
		std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
	}
	

	return;
}



void ed::longitudArbol(ed::Grafo & grafo)
{
	if(!grafo.isEmpty())
 {
 	float x;
 	float y;

 	ed::Grafo a;
 	ed::Grafo b;
	a=grafo.Kruskal();
	b=grafo.Prim();

	x=a.sumaPesos();
	y=b.sumaPesos();

	std::cout<<BIBLUE<<"La longitud del arbol minimo aplicando el algoritmo de kruscal sería: "<<x<<RESET<<std::endl;
	std::cout<<BIBLUE<<"La longitud del arbol minimo aplicando el algoritmo de prim sería: "<<y<<RESET<<std::endl;
	
	
 }
 else
 {
 	std::cout<<BIRED<<"Grafo vacio"<<RESET<<std::endl;
 }

	return;
}

