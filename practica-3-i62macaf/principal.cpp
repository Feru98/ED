#include <iostream>


#include <string>

#include "Fecha.hpp"
#include "Medicion.hpp"
#include "MonticuloMediciones.hpp"

#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

int main(){

	ed::MonticuloMediciones monticulo;

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
					std::cout << "[1] Grabar el monticulo en un fichero" << std::endl;
					ed::grabarMonticulo(monticulo);
					break;

			
			case 2: 
					std::cout << "[2] Cargar el monticulo desde un fichero" << std::endl;
					ed::cargarMonticulo(monticulo);
				break;

				//////////////////////////////////////////////////////////////////////////////


			case 3: 
					std::cout << "[3] Ver si el monticulo está vacio" << std::endl;
					if(monticulo.isEmpty())
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
				  	std::cout << "[4] Consultar datos del monticulo" << std::endl; 
					ed::calcularDatos(monticulo);
					break;

			case 5: 
				  	std::cout << "[5] Mostrar el monticulo: " << std::endl; 
					ed::imprimirMonticulo(monticulo);
					break;

			case 6: 
				  	std::cout << "[6] Imprimir el vector: " << std::endl; 
					monticulo.print();
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 7: 
					std::cout << "[7] Borrar todas las mediciones del monticulo" 
							  << std::endl;
					if(!monticulo.isEmpty()){monticulo.removeAll();}
					else{std::cout<<BIRED<< "Ya está vacio" <<RESET <<std::endl;}
					break;


			case 8: 
					std::cout << "[8] Borrar una medicion" << std::endl;
				 	if(!monticulo.isEmpty()){monticulo.remove();}
				 	else{std::cout <<BIRED<< "Ya está vacio" <<RESET<<std::endl;}
					break;


			//////////////////////////////////////////////////////////////////////////////
			case 9: 
					std::cout << "[9] Insertar una medicion" << std::endl;
			    	ed::insertar(monticulo);
					break;


			case 10:
					std::cout << "[10] Consultar una fecha" << std::endl;
				  	ed::ConsultarFecha(monticulo);
					break;
					

			case 11: 
					std::cout << "[11]Tamaño del monticulo" << std::endl;
					std::cout<<BIGREEN<<"El monticulo tiene "<<monticulo.size() <<" mediciones"<<RESET<<std::endl;
					
					break;

			case 12: 
					std::cout << "[12]Modificar la cima del monticulo" << std::endl;
					ed::modificar(monticulo);
					
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

	return 0;
}

