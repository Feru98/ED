/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares para el programa principal de la práctica 1
  \author Fernando Maestre Carmona
  \date  Mayo-2018 
*/


#include <iostream>

#include <fstream>

#include <string>

#include "funcionesAuxiliares.hpp"
          
#include "MonticuloMediciones.hpp"

#include "Medicion.hpp"

#include "macros.hpp"


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
	std::cout <<  "[1] Grabar el monticulo en un fichero";


	PLACE(posicion++,10);
	std::cout << "[2] Cargar el monticulo desde un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Ver si el monticulo está vacio";

	//////////////////////////////////////////////////////////////////////////////
	
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos del monticulo";

	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar el monticulo";

	PLACE(posicion++,10);
	std::cout << "[6] Imprimir el vector";

	posicion++;

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todas las mediciones del monticulo";

	PLACE(posicion++,10);
	std::cout << "[8] Borrar una medicion";

	//////////////////////////////////////////////////////////////////////////////
	

	PLACE(posicion++,10);
	std::cout << "[9] Insertar una medicion";

	posicion++;

	PLACE(posicion++,10);
	std::cout << "[10] Consultar una fecha";

	PLACE(posicion++,10);
	std::cout << "[11] Tamaño del monticulo";

	PLACE(posicion++,10);
	std::cout << "[12] Modificar la cima del monticulo";

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






void ed::cargarMonticuloDeFichero(std::string const & nombreFichero, ed::MonticuloMediciones & monticulo) 
{
  // COMPLETAR

	std::string aux ;
	ed::Fecha fecha ;
	ed::Medicion medicion;
	std::ifstream fich(nombreFichero.c_str());

	if(fich.is_open())
	{
		monticulo.removeAll();

		
		while(getline(fich, aux, '-'))
		{
		fecha.setDia(atoi(aux.c_str()));
		getline(fich, aux, '-');
		fecha.setMes(atoi(aux.c_str()));
		getline(fich, aux, ' ');
		fecha.setAgno(atoi(aux.c_str()));
		getline(fich, aux, '\n');
		medicion.setPrecipitacion(atof(aux.c_str()));

		medicion.setFecha(fecha);


 	 	monticulo.insert(medicion);
 	 	
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


void ed::grabarMonticuloEnFichero(std::string const & nombreFichero, 
							      ed::MonticuloMediciones const & monticulo)
{
  
 	if(!monticulo.isEmpty())
 {
	ed::MonticuloMediciones copia= monticulo ;
	std::ofstream fich(nombreFichero.c_str());

	if(fich.is_open() )
	{
		while(!copia.isEmpty())
		{
			fich<<copia.top();
			copia.remove();
		
		}
	}
 }
 else
 {
 	std::cout<<BIYELLOW<<"Monticulo vacio"<<RESET<<std::endl;
 	std::cin.ignore();
 }

	return;
}

 
void ed::cargarMonticulo(ed::MonticuloMediciones & monticulo)
{

	std::string fichero;
	std::cout<<BIYELLOW<<"Introduzca el fichero del que quiere cargar el monticulo"<<RESET<<std::endl;
	std::cin>>fichero;
	cargarMonticuloDeFichero(fichero, monticulo);
 		return;
}

void ed::grabarMonticulo(ed::MonticuloMediciones const & monticulo)
{

	if(!monticulo.isEmpty())
	{
	std::string fichero;
	std::cout<<BIYELLOW<<"Introduzca el fichero en el que quiere grabar el monticulo"<<RESET<<std::endl;
	std::cin>>fichero;
	grabarMonticuloEnFichero(fichero, monticulo);
	}
	else
 	{
 	std::cout<<BIRED<<"Monticulo vacio"<<RESET<<std::endl;
 	std::cin.ignore();
 	}
	return;
}


void ed::imprimirMonticulo(ed::MonticuloMediciones const & monticulo)
{

 	if(!monticulo.isEmpty())
 {
	ed::MonticuloMediciones copia= monticulo ;
	
		while(!copia.isEmpty())
		{
			std::cout<<copia.top().getFecha()<<" "<<copia.top().getPrecipitacion()<<std::endl;
			copia.remove();
		
		}
	
 }
 else
 {
 	std::cout<<BIRED<<"Monticulo vacio"<<RESET<<std::endl;
 }

	return;
}


void ed::calcularDatos(ed::MonticuloMediciones const & monticulo)
{
	float suma=0;
 	float media;

 	if(!monticulo.isEmpty())
 	{
 	
	ed::MonticuloMediciones copia= monticulo ;
	
		while(!copia.isEmpty())
		{
			suma= suma + copia.top().getPrecipitacion() ;
			copia.remove();
		
		}
		media = suma/monticulo.size();
 		std::cout<<BIYELLOW<<"Suma de precipitaciones: "<<suma<<RESET<<std::endl;
 		std::cout<<BIYELLOW<<"Media de precipitaciones: "<<media<<RESET<<std::endl;
	
 	}
 	else
 	{
 		std::cout<<BIRED<<"Monticulo vacio"<<RESET<<std::endl;
 	}

 

	return;
}


void ed::insertar(ed::MonticuloMediciones & monticulo)
{
	ed::Medicion aux;
	
	do{
		std::cout<<BIBLUE<<"Introduzca una fecha correcta"<<RESET<<std::endl;
		aux.leerMedicion();
	}while(!aux.getFecha().esCorrecta());

	monticulo.insert(aux);

	return;
}

void ed::ConsultarFecha(ed::MonticuloMediciones const & monticulo)
{

	ed::Fecha fecha;
	ed::Medicion medicion;

	if(monticulo.isEmpty())
 	{
 		std::cout<<BIRED<<"Monticulo vacio"<<RESET<<std::endl;
 		
 		return;
 	}

	do{
		std::cout<<BIBLUE<<"Introduzca una fecha correcta"<<RESET<<std::endl;
		fecha.leerFecha();
	}while(!fecha.esCorrecta());

		medicion.setFecha(fecha);

		ed::MonticuloMediciones copia= monticulo ;
	
		while(!copia.isEmpty())
		{
			if(copia.top().getFecha()==fecha)
			{
				std::cout<<BIGREEN<<"La fecha está en el Monticulo"<<RESET<<std::endl;
				std::cin.ignore();
				copia.top().escribirMedicion();
				return;
			}
			copia.remove();
		
		}
		std::cout<<BIRED<<"La fecha no está en el Monticulo"<<RESET<<std::endl;
		std::cin.ignore();
		

	

	return;
}


void ed::modificar(ed::MonticuloMediciones & monticulo)
{
	ed::Medicion medicion;

	if(monticulo.isEmpty())
 	{
 		std::cout<<BIRED<<"Monticulo vacio"<<RESET<<std::endl;
 		
 		return;
 	}

	do{
		std::cout<<BIBLUE<<"Introduzca una fecha correcta"<<RESET<<std::endl;
		medicion.leerMedicion();
	}while(!medicion.getFecha().esCorrecta());


	monticulo.modify(medicion);

	return;
}
