/*!	
	\file  Provincia.hpp
	\brief Definición de la clase Provincia
	\author  
	\date  
	\version 

*/

#ifndef _PROVINCIA_HPP_
#define _PROVINCIA_HPP_

// Para comprobar las pre y post condiciones
#include <cassert>

#include <string>


#include "ListaDoblementeEnlazadaOrdenadaMunicipios.hpp"


// DEBES COMPLETAR O MODIFICAR EL CÓDIGO DE LA CLASE Provincia

// DEBES COMPLETAR LOS COMENTARIOS DE DOXYGEN

// IMPORTANTE
// Se incluyen los prototipos de las funciones virtuales que hay que redefinir
// Hay que incluir los prototipos de las demás funciones


/*!	
	\namespace ed
	\brief Espacio de nombres para la Provincia Estructuras de Datos

*/
namespace ed{
/*!	

  \class Provincia
  \brief Definición de la clase Provincia

*/
class Provincia
{
	//!	\name Métodos públicos de la clase Provincia

	private:
		std::string      _nombre;     //!<  \brief Nombre de la Provincia
		int              _codigo;	  //!<  \brief Código de la Provincia

	  	ed::ListaDoblementeEnlazadaOrdenadaMunicipios _listaMunicipios; //!<  \brief Lista de municipios de la Provincia


	/////////////////////////////////////////////////////////////////////

	//!	\name  Métodos públicos de la clase Provincia

  public: 

	//!	\name Constructor
  	Provincia(std::string nombre="ninguno" , int codigo=0 )
	{
		setNombre(nombre);
		setCodigo(codigo);
	}

	/////////////////////////////////////////////////////////////////////

	//!	\name Observadores

		/*!
		\brief  Observador del nombre de la provincia
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return _nombre , string con el nombre de la provincia 
    */
	inline std::string getNombre() const {return _nombre;};

		/*!
		\brief  Observador del codigo de la provincia
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return _codigo , entero con el codigo de la provincia 
    */
  	inline int getCodigo() const {return _codigo;};

  		/*!
		\brief Indica si la privincia tiene o no municipios
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true , si hay municipios en _listaMunicipios y false si está vacia.
    */
  	inline bool hayMunicipios()const{ return !(_listaMunicipios.isEmpty()); }

  	/*!
		\brief Devuelve el número de municipios de la provincia
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return entero con el numero de municipios
    */
  	inline int getNumeroMunicipios()const {return _listaMunicipios.nItems() ;}

  	/*!
		\brief Indica si el municipio con el nombre pasado por parametros pertenece a la provincia
		\param nombre: string con el nombre del municipio a comprobar
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return true , si el municipio pertece a la provincia y false en el caso contrario 
    */
  	inline bool existeMunicipio(std::string const &nombre)
 	{
 		ed::Municipio aux(nombre);
 		return _listaMunicipios.find(aux) ;
 	}

 	/*!
		\brief Devuelve el municipio con el nombre pasado por parametros
		\param nombre: string con el nombre del municipio a buscar
		\pre existeMunicipio(nombre) == verdadero
		\note   Función inline
		\note   Función de tipo "const": no puede modificar al objeto actual
        \return Municipio con el nombre buscado 
    */
 	inline ed::Municipio getMunicipio(std::string const &nombre)
 	{
 		#ifndef NDEBUG
		  	assert(existeMunicipio(nombre));
		  #endif //NDEBUG

 		ed::Municipio aux(nombre);
 		_listaMunicipios.find(aux) ;
 		return _listaMunicipios.getCurrentItem(); 
 	}

 	/*!
		\brief Devuelve el numero de hombres en la provincia
        \return int con el numero de hombres 
    */
	 int getTotalHombres();

	 /*!
		\brief Devuelve el numero de mujeres en la provincia
        \return int con el numero de mujeres 
    */
	 int getTotalMujeres();

	/*!
		\brief Devuelve el numero de habitantes en la provincia
		\post valorDevuelto == getTotalHombres() + getTotalMujeres()
        \return int con el numero de habitantes 
    */
	 inline int getTotalHabitantes()
	 {
	 	return getTotalHombres() + getTotalMujeres() ;
	 }

	/////////////////////////////////////////////////////////////////////

	//!	\name Modificadores

	/*!
		\brief Asigna un nuevo nombre a provincia
		\param nombre: string con el nuevo nombre
		\note   Función inline
		\post getNombre() == nombre 
    */
  	inline void setNombre(std::string nombre){_nombre=nombre;};

  	/*!
		\brief Asigna un nuevo Codigo a provincia
		\param Codigo: entero con el nuevo Codigo
		\note   Función inline
		\post getCodigo() == Codigo 
    */
  	inline void setCodigo(int codigo){_codigo=codigo;};

  	/*!
		\brief Inserta un nuevo municipio en provincia
		\param m , municipio a insertar
		\pre existeMunicipio(municipio.getNombre()) == falso
		\post existeMunicipio(municipio.getNombre()) == verdadero
		\post getNumeroMunicipios() = old.getNumeroMunicipios() + 1 
    */
  	void insertarMunicipio(ed::Municipio m);

  	/*!
		\brief Borra un municipio en provincia
		\param nombre , string del nombre del municipio a borrar
		\pre existeMunicipio(municipio.getNombre()) == verdadero
		\post existeMunicipio(municipio.getNombre()) == false
		\post getNumeroMunicipios() = old.getNumeroMunicipios() - 1 
    */
  	void borrarMunicipio(std::string nombre);

  	  	/*!
		\brief Borra todos los municipios en provincia
		\note   Función inline
		\post hayMunicipios() == falso
    */
  	inline void borrarTodosLosMunicipios()
  	{
  		_listaMunicipios.removeAll();

  		#ifndef NDEBUG
		  	assert(!hayMunicipios());
		  #endif //NDEBUG
  	}


	/////////////////////////////////////////////////////////////////////

	//! \name Función de escritura de la clase Provincia

  	/*!
		\brief Escribe por pantalla la información de la provincia y de sus municipios
    */
	void escribirMunicipios();



	/////////////////////////////////////////////////////////////////////

	//! Operaciones con ficheros

	/*!
		\brief Carga los datos de una provincia desde un fichero
		\return true , si se ha realizado con exito, false en caso contrario
    */
	bool cargarFichero(std::string nombre);

	/*!
		\brief Graba los datos de una provincia en un fichero
		\return true , si se ha realizado con exito, false en caso contrario
    */
	bool grabarFichero(std::string nombre);



}; //Fin de la clase  Provincia


} // Fin del espacio de nombres ed

#endif // _PROVINCIA_HPP_
