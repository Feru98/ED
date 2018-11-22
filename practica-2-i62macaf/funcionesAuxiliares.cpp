/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la provincia
  \author 
  \date   
*/

#include <iostream>
#include <string>  

// Para usar atoi
#include <stdlib.h>

#include "Provincia.hpp"

#include "Municipio.hpp"

#include "funcionesAuxiliares.hpp"


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
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

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


//////////////////////////////////////////////////////////////////////////////

void ed::comprobarProvinciaVacia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

	if(provincia.hayMunicipios())
	{
		std::cout<<"No está vacia"<<std::endl;
	}
	else
	{
		std::cout<<"Está vacia"<<std::endl;
	}

	return;
}

//////////////////////////////////////////////////////////////////////////////

void ed::cargarProvincia(ed::Provincia &provincia)
{
	 //std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::string f ;
	std::cout<<"Inserte el nombre del fichero del que desea cargar la Provincia"<<std::endl;
	std::cin>>f ;
	provincia.cargarFichero(f);

	return;
}

void ed::grabarProvincia(ed::Provincia  &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::string f ;
	std::cout<<"Inserte el nombre del fichero en el que desea meter la Provincia"<<std::endl;
	std::cin>>f ;
	provincia.grabarFichero(f);

	return;
}

//////////////////////////////////////////////////////////////////////

void ed::consultarDatosDeProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::cout<<"Provincia :"<<provincia.getNombre()<<"\n";
	std::cout<<"Codigo Provincia :"<<provincia.getCodigo()<<"\n";
	if(provincia.hayMunicipios())
	{
	std::cout<<"Número Municipios: "<<provincia.getNumeroMunicipios()<<"\n";
	std::cout<<"Hombres :"<<provincia.getTotalHombres()<<"\n";
 	std::cout<<"Mujeres :"<<provincia.getTotalMujeres()<<"\n";
 	std::cout<<"Habitantes :"<<provincia.getTotalHabitantes()<<"\n";
 	std::cout<<"\n";
 	}
	return;
}


//
void ed::mostrarMunicipiosDeProvincia(ed::Provincia & provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	provincia.escribirMunicipios();
	return;
}


////////////////////////////////////////////////////////////////////////
void ed::modificarDatosDeProvincia(ed::Provincia &provincia)
{

std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;

// QUITAR LOS COMENTARIOS CUANDO SE HAYA CODIFICADO LA CLASE Provincia


	int opcion, codigo;
	std::string nombre; 

	do{
		std::cout << BIYELLOW  << "Nombre de la provincia: "  << RESET 
				  << provincia.getNombre() << std::endl; 
		std::cout << BIYELLOW << "Código de la provincia: " << RESET
				  << provincia.getCodigo() << std::endl  << std::endl;

		std::cout << "Indique qué dato desea modificar: " << std::endl;
		std::cout << BIBLUE << "(1) Nombre " << std::endl;
		std::cout << BIBLUE << "(2) Código" << std::endl  << std::endl;
		std::cout << BIRED << "(0) Salir" << std::endl << std::endl  << std::endl;
		std::cout << BIGREEN;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    	// Se elimina el salto de línea del flujo de entrada
	    std::cin.ignore();

		std::cout << std::endl;
			
		switch(opcion)
		{
			case 0: 
					// Fin de las modificaciones
					break;
			case 1:
					std::cout << BIGREEN;
					std::cout << "Nuevo nombre de la provincia: ";
					std::cout << RESET;
					std::getline(std::cin,nombre);
					provincia.setNombre(nombre);
					break;

			case 2:
					std::cout << BIGREEN;
					std::cout << "Nuevo código de la provincia: ";
					std::cout << RESET;
					std::cin >> codigo;
					provincia.setCodigo(codigo);
					break;
			default:
					std::cout << BIRED << "Opción incorrecta:" << RESET 
							  << opcion << std::endl;
		}
	}while (opcion != 0);

	return;
}


void ed::borrarTodosLosMunicipiosDeProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	provincia.borrarTodosLosMunicipios();
	return;
}


void ed::consultarMunicipioDeProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	
	 
	std::string p;
	ed::Municipio aux;
	std::cout<<"Inserte el nombre del municipio que desea consultar "<<std::endl;
    std::cin>>p;
    std::cin.ignore();
	
	if(provincia.existeMunicipio(p)==true)
	{
		aux=provincia.getMunicipio(p);
		std::cout<<"\n existe"<<std::endl;
		aux.escribirMunicipio();
	}
	else
	{
		std::cout<<"NO existe el municipio "<<std::endl;
	}

	return;
}

void ed::insertarMunicipioEnProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	
	int codigoPostal;   
	std::string nombre; 
    int hombres;         
    int mujeres;

    std::cout<<"Inserte el codigo "<<std::endl;
    std::cin>>codigoPostal ;
    std::cout<<"Inserte el nombre "<<std::endl;
    std::cin>>nombre ;
    std::cout<<"Inserte el numero de hombres "<<std::endl;
    std::cin>>hombres ;
    std::cout<<"Inserte el numero de mujeres"<<std::endl;
    std::cin>>mujeres ;

    ed::Municipio aux(nombre, codigoPostal , hombres , mujeres);
    provincia.insertarMunicipio(aux);

	return;
}

  


void ed::borrarMunicipioDeProvincia(ed::Provincia &provincia)
{
	//std::cout << "SE DEBE COMPLETAR EL CÓDIGO DE ESTA FUNCIÓN " << std::endl;
	std::string s ;
	ed::Municipio aux;
	std::cout<<"Inserte el nombre del municipio que desea borrar"<<std::endl;
	std::cin>>s ;
	std::cin.ignore();
	if(provincia.existeMunicipio(s)==true)
	{
		provincia.borrarMunicipio(s);
		std::cout<<"Borrado "<<std::endl;
	}
	else
	{
		std::cout<<"NO existe el municipio "<<std::endl;
	}
	return;
}




