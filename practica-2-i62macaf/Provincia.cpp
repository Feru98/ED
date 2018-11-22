/*!	

	\file  Provincia.cpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 1.0

*/
//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <iostream>
#include <cstdlib>

// Para comprobar las pre y post condiciones
#include <cassert>

#include "Provincia.hpp"


// DEBES CODIFICAR LAS FUNCIONES DE LA CLASE Provincia

///////////////////////////////////////////////////////////////////////////////

// OSBSERVADORES

 int ed::Provincia::getTotalHombres()
 {
 	_listaMunicipios.gotoHead();
 	int total = 0 ;
 	int a=1 ;

 	while( a==1 )
 	{
 		total= total + ((_listaMunicipios.getCurrentItem()).getHombres() );

 		if(!_listaMunicipios.isLastItem())
 		{
 			_listaMunicipios.gotoNext();
 		}
 		else
 		{
 			a=0;
 		}
 	}

 	return total;
 }

 int ed::Provincia::getTotalMujeres()
 {
 	_listaMunicipios.gotoHead();
 	int total = 0 ;
 	int a=1 ;

 	while( a==1 )
 	{
 		total= total + ((_listaMunicipios.getCurrentItem()).getMujeres() );

 		if(!_listaMunicipios.isLastItem())
 		{
 			_listaMunicipios.gotoNext();
 		}
 		else
 		{
 			a=0;
 		}
 	}

 	return total;
 }

/////////////////////////////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Provincia::insertarMunicipio(ed::Municipio m)
{
	#ifndef NDEBUG
		  	assert(!existeMunicipio(m.getNombre()));
		  #endif //NDEBUG

		  	int old = getNumeroMunicipios();
		  	_listaMunicipios.insert(m);

	#ifndef NDEBUG
		  	assert(existeMunicipio(m.getNombre()));
		  	assert(getNumeroMunicipios()==old+1);
		  #endif //NDEBUG
}

void ed::Provincia::borrarMunicipio(std::string nombre)
{
	#ifndef NDEBUG
		  	assert(existeMunicipio(nombre));
		  #endif //NDEBUG

	ed::Municipio aux(nombre);
	int old = getNumeroMunicipios();

	_listaMunicipios.find(aux);
	_listaMunicipios.remove();

	#ifndef NDEBUG
		  	assert(!existeMunicipio(nombre));
		  	assert(getNumeroMunicipios()==old-1);
		  #endif //NDEBUG
}

///////////////////////////////////////////////////////////////////////////////////

// FUNCIÓN DE ESCRITURA

void ed::Provincia::escribirMunicipios()
{
if(! _listaMunicipios.isEmpty())
{

	_listaMunicipios.gotoHead();
	ed::Municipio aux;
	int a=1 ;

	std::cout<<"Provincia :"<<getNombre()<<"\n";
	std::cout<<"Codigo Provincia :"<<getCodigo()<<"\n";
	std::cout<<"Hombres :"<<getTotalHombres()<<"\n";
 	std::cout<<"Mujeres :"<<getTotalMujeres()<<"\n";
 	std::cout<<"Habitantes :"<<getTotalHabitantes()<<"\n";
 	std::cout<<"\n";
 	_listaMunicipios.gotoHead();

 	while( a==1 )
 	{
 		aux=_listaMunicipios.getCurrentItem();
 		std::cout<<"Nombre :"<<aux.getNombre()<<"\n";
 		std::cout<<"Codigo Postal :"<<aux.getCodigoPostal()<<"\n";
 		std::cout<<"Hombres :"<<aux.getHombres()<<"\n";
 		std::cout<<"Mujeres :"<<aux.getMujeres()<<"\n";
 		std::cout<<"Habitantes :"<<aux.getHabitantes()<<"\n";
 		std::cout<<"#####################################################################"<<"\n";

 		if(!_listaMunicipios.isLastItem())
 		{
 			_listaMunicipios.gotoNext();
 		}
 		else
 		{
 			a=0;
 		}
 	}

}
}


/*
void ed::Provincia::escribirMunicipios(){

if(!_listaMunicipios.isEmpty()){
ed::Municipio aux;



	std::cout<<"Provincia :"<<getNombre()<<"\n";
	std::cout<<"Codigo Provincia :"<<getCodigo()<<"\n";
	std::cout<<"Hombres :"<<getTotalHombres()<<"\n";
 	std::cout<<"Mujeres :"<<getTotalMujeres()<<"\n";
 	std::cout<<"Habitantes :"<<getTotalHabitantes()<<"\n";
 	std::cout<<"\n";
_listaMunicipios.gotoHead();
   while(!_listaMunicipios.isLastItem()){
     aux=_listaMunicipios.getCurrentItem();
     
     std::cout<<"Nombre :"<<aux.getNombre()<<"\n";
 		std::cout<<"Codigo Postal :"<<aux.getCodigoPostal()<<"\n";
 		std::cout<<"Hombres :"<<aux.getHombres()<<"\n";
 		std::cout<<"Mujeres :"<<aux.getMujeres()<<"\n";
 		std::cout<<"Habitantes :"<<aux.getHabitantes()<<"\n";
 		std::cout<<"#####################################################################"<<"\n";

     _listaMunicipios.gotoNext();}
aux=_listaMunicipios.getCurrentItem();

std::cout<<"Nombre :"<<aux.getNombre()<<"\n";
 		std::cout<<"Codigo Postal :"<<aux.getCodigoPostal()<<"\n";
 		std::cout<<"Hombres :"<<aux.getHombres()<<"\n";
 		std::cout<<"Mujeres :"<<aux.getMujeres()<<"\n";
 		std::cout<<"Habitantes :"<<aux.getHabitantes()<<"\n";
 		std::cout<<"#####################################################################"<<"\n";

}
}

*/

/////////////////////////////////////////////////////////////////////////////////////////

// OPERACIONES CON FICHEROS

bool ed::Provincia::cargarFichero(std::string nombre)
{	

	ed::Municipio aux ;
	std::string provincia;
	std::string codigo;
	std::ifstream fich(nombre.c_str());

	if(fich.is_open())
	{
		_listaMunicipios.removeAll();

		getline(fich, codigo, ' ');
		setCodigo(atoi(codigo.c_str()));
		getline(fich, provincia, '\n');
		setNombre(provincia.c_str());
/*
		while(!fich.eof() )
 	{
 		fich>>aux ;
 		insertarMunicipio(aux);
 	}
*/

		while(fich>>aux) 
 		{
 	 		insertarMunicipio(aux);
 		}


 		fich.close();
		return true;
	}
	else
	{
		return false;
	}
	
}


bool ed::Provincia::grabarFichero(std::string nombre)
{
	if(!_listaMunicipios.isEmpty())
 {
	_listaMunicipios.gotoHead();
	ed::Municipio aux ;
	std::string provincia;
	std::string codigo;
	std::ofstream fich(nombre.c_str());

	if(fich.is_open() )
	{
		fich<<getCodigo()<<' '<<getNombre()<<'\n'<<std::endl;

		while( !_listaMunicipios.isLastItem() )
 	{
 		aux=_listaMunicipios.getCurrentItem();
 		fich<<aux<<"\n" ;
 		_listaMunicipios.gotoNext();
 		
 	}
 		aux=_listaMunicipios.getCurrentItem();
 		fich<<aux ;

 		fich.close();
		return true;
	}
	else
	{
		return false;
	}
 }
 return false;
}
