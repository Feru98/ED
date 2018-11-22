/*! 
   \file principal.cpp
   \brief Fichero principal
   \author Fernando Maestre Carmona
*/

#include <iostream>
#include <cstdlib>
#include <string>

#include "FuncionesAuxiliares.hpp"
#include "Grafo.hpp"
#include "Lado.hpp"
#include "Vertice.hpp"
#include "macros.hpp"


/*! 
		\brief   Programa principal de la práctica 4: Grafo
		\return  int
*/
int main()
{
	ed::Grafo grafo;

	int opcion;

	do{
		// Se elige la opción del menún
		opcion = ed::menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

		// Se ejecuta la opción del menú elegida
		switch(opcion)
		{
			case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;

		   ///////////////////////////////////////////////////////////////////

			case 1: 
					std::cout << "[1] Grabar el grafo en un fichero" << std::endl;
					grabarGrafo(grafo);
					break;

			
			case 2: 
					std::cout << "[2] Cargar el grafo desde un fichero" << std::endl;
					cargarGrafo(grafo);
				break;

				//////////////////////////////////////////////////////////////////////////////


			case 3: 
					std::cout << "[3] Ver si el grafo está vacio" << std::endl;
					if(grafo.isEmpty())
					{
						std::cout <<BIRED<< "Está vacio" <<RESET<<std::endl;	
					}
					else
					{
						std::cout <<BIGREEN<< "No está vacio" <<RESET<<std::endl;
					}
					break;

			//////////////////////////////////////////////////////////////////////////////


			case 4: 
				  	std::cout << "[4] Mostrar datos del grafo" << std::endl; 
					if(grafo.isEmpty())
					{
						std::cout <<BIRED<< "Está vacio" <<RESET<<std::endl;	
					}
					else
					{
						imprimirGrafo(grafo);
					}
					break;

			case 5: 
				  	std::cout << "[5] Mostrar arbol abarcador minimo con Kruskal" << std::endl; 
					kruskal(grafo);
					break;

			case 6: 
				  	std::cout << "[6] Grabar Kruskal en un fichero" << std::endl; 
					kruskalFichero(grafo);
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 7: 
					std::cout << "[7] Mostrar arbol abarcador minimo con Prim" 
							  << std::endl;
					prim(grafo);
					break;


			case 8: 
					std::cout << "[8] Grabar Prim en un fichero" << std::endl;
				 	primFichero(grafo);
					break;

					
			//////////////////////////////////////////////////////////////////////////////
			case 9: 
					std::cout << "[9] Borrar Grafo" << std::endl;
			    	grafo.removeAll();
					break;

					
			case 10:
					std::cout << "[11] Insertar Vertice" << std::endl;
				  	insertarVertice(grafo);
					break;
					
					
			case 11: 
					std::cout << "[11] Borrar vertice" << std::endl;
					borrarVertice(grafo);
					
					break;
					
			case 12: 
					std::cout << "[12] Mostrar longitud del arbol mínimo" << std::endl;
					longitudArbol(grafo);
					
					break;
				
			//////////////////////////////////////////////////////////////////////////////
			default:
				std::cout << BIRED;
				std::cout << "Opción incorrecta ";
				std::cout << RESET;
				std::cout << "--> ";
			  	std::cout << ONIRED;
				std::cout << opcion << std::endl;
				std::cout << RESET;
     }
  
    if (opcion !=0)
    {
		PLACE(25,1);
		std::cout << "Pulse ";
		std::cout << BIGREEN;
		std::cout << "ENTER";
		std::cout << RESET;
		std::cout << " para mostrar el ";
		std::cout << INVERSE;
		std::cout << "menú"; 
		std::cout << RESET;

		// Pausa
		std::cin.ignore();

		std::cout << CLEAR_SCREEN;
    }
	  }while(opcion!=0);














	/* 	Prueba basica antes de que existiera el menu
	ed::Grafo g;
	std::string f="vertices.txt";

	ed::cargarGrafoDeFichero(f , g);
	ed::imprimirGrafo(g);
	ed::kruskal(g);
	ed::prim(g);
	

	*/

	return 0;
}