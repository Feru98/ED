/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR   1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D
{
  //! \name Atributos privados de la clase Vector3D
   private: 

	double vec[3];


   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D


/*! @fn Vector3D()
 	 @brief Constructor del vector3D sin argumentos, crea un Vector3D nulo
 	 @post (get1()==0) and (get2()==0) and (get3()==0) */
	Vector3D()
	{
		set1(0);
		set2(0);
		set3(0);

		#ifndef NDEBUG
		assert((get1()==0) and (get2()==0) and (get3()==0));
		#endif //NDEBUG
	}

/*! @fn Vector3D(double x , double y , double z)
 	 @brief Constructor del vector3D con parametros ,crea un Vector3D con los nuevos valores
 	 @param x primera coordenada del nuevo vector  
 	 @param y segunda coornada del nuevo vector 
 	 @param z tercera coordenada del nuevo vector
 	 @post (get1()==x) and (get2()==y) and (get3()==z) */
	Vector3D(double x , double y , double z)
	{
		set1(x);
		set2(y);
		set3(z);

		#ifndef NDEBUG
		assert(		(std::abs(get1()-x)<COTA_ERROR) 
				and (std::abs(get2()-y)<COTA_ERROR)
				and (std::abs(get3()-z)<COTA_ERROR)
			  );
		#endif //NDEBUG
	}
	/*! 
 	 @brief Constructor de copia ,crea un nuevo Vector3D a partir de otro
 	 @param v Nuevo vector  
 	 @post (get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3()) */
	Vector3D(ed::Vector3D & v)
	{
		set1(v.get1());
		set2(v.get2());
		set3(v.get3());

		#ifndef NDEBUG
		assert(		(std::abs(get1()-v.get1())<COTA_ERROR) 
				and (std::abs(get2()-v.get2())<COTA_ERROR)
				and (std::abs(get3()-v.get3())<COTA_ERROR)
			  );
		#endif //NDEBUG
	}

	//! \name Observadores: funciones de consulta de Vector3D

	// COMPLETAR

 /*! @fn inline double get1() const
 	 @brief Observador del primer elemento del vector3D
 	 @return x_ es la primera componente v1 del vector3D */
	inline double get1() const {return vec[0];};

/*! @fn inline double get2() const
 	 @brief Observador del segundo elemento del vector3D
 	 @return y_ es la segunda componente v2 del vector3D */
	inline double get2() const {return vec[1];};

	/*! @fn inline double get3() const
 	 @brief Observador del tercer elemento del vector3D
 	 @return z_ es la tercera componente v3 del vector3D */
	inline double get3() const {return vec[2];};


	/*! 
 	 @fn double modulo() const 
 	 @brief Calcula el modulo del vector
 	 @return aux variable que guarda el resultado
 	 @post aux == sqrt ( get1()*get1() + get2()*get2() + get3()*get3() )  
 	 */
	double modulo() const ;

	/*! 
 	 @fn  double dotProduct(ed::Vector3D const &v) const
 	 @brief Calcula el producto escalar del vector con otro vector v
 	 @param v segundo vector
 	 @return aux variable que guarda el resultado
 	 @post aux == get1() * v.get1() + get2() * v.get2() + get3() * v.get3()
 	 */
	double dotProduct(ed::Vector3D const &v) const ;

	/*! 
 	 @fn  double angulo(ed::Vector3D const &v) const
 	 @brief Devuelve el ángulo entre el vector actual y vector pasado como argumento
 	 @param v segundo vector
 	 @pre modulo() * v.modulo() > 0
 	 @return aux variable que guarda el resultado
 	 @post aux == acos( dotProduct(v) / (modulo() * v.modulo()) )
 	 */
	double angulo(ed::Vector3D const &v) const ;

	/*! 
 	 @fn  double alfa() const
 	 @brief Calcula el ángulo del vector con el eje X
 	 @pre modulo() > 0
 	 @return aux variable que guarda el resultado
 	 @post aux == angulo(Vector3D(1,0,0))
 	 */
	double alfa() const ;

	/*! 
 	 @fn  double beta() const
 	 @brief Calcula el ángulo del vector con el eje Y
 	 @pre modulo() > 0
 	 @return aux variable que guarda el resultado
 	 @post aux == angulo(Vector3D(0,1,0))
 	 */
	double beta() const ;

	/*! 
 	 @fn  double gamma() const
 	 @brief Calcula el ángulo del vector con el eje Z
 	 @pre modulo() > 0
 	 @return aux variable que guarda el resultado 
 	 @post aux == angulo(Vector3D(0,0,1))
 	 */
	double gamma() const ;

	/*! 
 	 @fn ed::Vector3D crossProduct(ed::Vector3D const &v) const
 	 @brief Calcula el producto vectorial de dos vectores 
 	 @param v segundo vector
 	 @return w Vector3D resultado del producto vectorial
 	 @post dotProduct(w) == 0
 	 @post v.dotProduct(w) == 0
 	 @post w.modulo() ==modulo() * v.modulo() * sin(angulo(v))
 	 */
	ed::Vector3D crossProduct(ed::Vector3D const &v) const;

	/*! 
 	 @fn double productoMixto(ed::Vector3D const &v , ed::Vector3D const &w) const
 	 @brief Devuelve el resultado de calcular el producto escalar del vector actual con el vector obtenido al calcular el producto vectorial de otros dos vectores.
 	 @param v segundo vector para calcular el producto vectorial
 	 @param w tercer vector para calcular el producto vectorial
 	 @return aux variable que guarda el resultado 
 	 @post aux == dotProduct(v.crossProduct(w))
 	 */
	double productoMixto(ed::Vector3D const &v , ed::Vector3D const &w) const;


	//! \name Modificadores: funciones de modificación de Vector3D

	// COMPLETAR

 /*! 
 	 @brief Modificador del primer elemento del vector3D,  
 	 @param  x nuevo valor asignado a la primera coordenada del vector
 	 @post get1()== x */
	inline void set1(double x){vec[0]=x;};

/*! 
 	 @brief Modificador del segundo elemento del vector3D,  
 	 @param  y nuevo valor asignado a la segunda coordenada del vector
 	 @post get2()== y */	
	inline void set2(double y){vec[1]=y;};

/*! 
 	 @brief Modificador del tercer elemento del vector3D,  
 	 @param  z nuevo valor asignado a la tercera coordenada del vector
 	 @post get3()== z */	
	inline void set3(double z){vec[2]=z;};

/*! 
 	 @brief Modificador que suma cada componente del vector con una constante   
 	 @param  k constante
 	 @post (get1() == old.get1() + k)
 	 @post (get2() == old.get2() + k)
 	 @post (get3() == old.get3() + k)
 	 */	
	void sumConst(double k);

/*! 
 	 @brief Modificador que suma el vector con otro  
 	 @param  v segundo Vector3D
 	 @post (get1() == old.get1() + v.get1())
 	 @post (get2() == old.get2() + v.get2())
 	 @post (get3() == old.get3() + v.get3())
 	 */	
	void sumVect(ed::Vector3D const &v);

/*! 
 	 @brief Modificador que multiplica cada componente del vector con una constante   
 	 @param  k constante
 	 @post (get1() == old.get1() * k)
 	 @post (get2() == old.get2() * k)
 	 @post (get3() == old.get3() * k)
 	 */	
	void multConst(double k);

/*! 
 	 @brief Modificador que multiplica el vector con otro  
 	 @param  v segundo Vector3D
 	 @post (get1() == old.get1() * v.get1())
 	 @post (get2() == old.get2() * v.get2())
 	 @post (get3() == old.get3() * v.get3())
 	 */	
	void multVect(ed::Vector3D const &v);

	/*! 
 	 @brief Modificador que eleva al cuadrado el vector
 	 */
	void Cuadrado();

    //! \name Operadores de la clase
   
	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*! 
 	 @brief Operador que iguala el vector actual a otro 
 	 @param  objeto segundo Vector3D 
 	 @post (get1() == v.get1())
 	 @post (get2() == v.get2())
 	 @post (get3() == v.get3())
 	 */	
	Vector3D & operator=(Vector3D const &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*! 
 	 @brief Operador que compara el vector actual con otro  
 	 @param  objeto segundo Vector3D a comparar
 	 @return aux variable que guarda el resultado
 	 @post aux==(get1() == objeto.get1())
 	 @post aux==(get2() == objeto.get2())
 	 @post aux==(get3() == objeto.get3())
 	 */	
	bool operator == (Vector3D const &objeto) const;

	// COMPLETAR EL RESTO DE OPERADORES
	/*! 
 	 @brief Operador que devuelve otro vector que es la suma del actual y otro
 	 @param  objeto segundo Vector3D 
 	 @return w Vector3D que guarda la suma de objeto y el vector actual
 	 @post w.get1()==(get1() + objeto.get1())
 	 @post w.get2()==(get2() + objeto.get2())
 	 @post w.get3()==(get3() + objeto.get3())
 	 */	
	Vector3D & operator+(Vector3D const &objeto)const;

	/*! 
 	 @brief Operador que devuelve otro vector que es la copia del actual  
 	 @return w Vector3D que es una copia del vector actual
 	 @post w.get1()==get1() 
 	 @post w.get2()==get2() 
 	 @post w.get3()==get3() 
 	 */	
	Vector3D & operator+()const;

	/*! 
 	 @brief Operador que devuelve otro vector que es la diferencia del actual y otro
 	 @param  objeto segundo Vector3D 
 	 @return w Vector3D que guarda la diferencia del vector actual y objeto
 	 @post w.get1()==(get1() - objeto.get1())
 	 @post w.get2()==(get2() - objeto.get2())
 	 @post w.get3()==(get3() - objeto.get3())
 	 */	
	Vector3D & operator-(Vector3D const &objeto)const;

	/*! 
 	 @brief Operador que devuelve otro vector que es el opuesto del actual  
 	 @return w Vector3D que es el opuesto del vector actual
 	 @post w.get1()== -get1() 
 	 @post w.get2()== -get2() 
 	 @post w.get3()== -get3() 
 	 */	
	Vector3D & operator-()const;


	/*! 
 	 @brief Operador que devuelve el producto escalar del vector actual con otro vector
 	 @param  objeto segundo Vector3D
 	 @return aux variable que guarda el resultado
 	 @post aux==((get1() * objeto.get1()) + (get2() * objeto.get2()) + (get3() * objeto.get3()))
 	 */	
	double & operator*(Vector3D const &objeto)const ;

	/*! 
 	 @brief Operador que devuelve otro vector que se obtiene multiplicando cada una de las coordenadas del vector actual por una constante
 	 @param  k constante
 	 @return w Vector3D resultado
 	 @post w.get1()==(get1() * k)
 	 @post w.get2()==(get2() * k)
 	 @post w.get3()==(get3() * k)
 	 */	
	Vector3D & operator*(double const &k)const;

	/*! 
 	 @brief Operador que calcula el producto vectorial de dos vectores 
 	 @param objeto segundo vector
 	 @return w Vector3D resultado del producto vectorial
 	 @post dotProduct(w) == 0
 	 @post objeto.dotProduct(w) == 0
 	 @post w.modulo() ==modulo() * objeto.modulo() * sin(angulo(objeto))
 	 */
	Vector3D & operator^(Vector3D const &objeto)const;

	//! \name Funciones lectura y escritura de la clase Vector3D

	/*! 
 	 @brief Lee desde el teclado las componentes del vector
 	 */
	void leerVector3D();

	/*! 
 	 @brief Escribe por pantalla las componentes del vector
 	 */
	void escribirVector3D()const;

	// COMPLETAR

}; // Fin de la definición de la clase Vector3D


//////////////////////////////////////////////////////////////////////////////////////

//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*! 
 	 @brief Operador que calcula otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector
 	 @param objeto vector
 	 @param k constante
 	 @return vectorResultado Vector3D resultado del producto 
 	 @post (vectorResultado.get1() == objeto.get1() * k) and (vectorResultado.get2() == objeto.get2() * k) and (vectorResultado.get3() == objeto.get3() * k)
 	 */
    Vector3D & operator* (double k, Vector3D const & objeto);


	// COMPLETAR COMENTARIOS DE DOXYGEN
	/*! 
 	 @brief Lee desde el flujo de entrada las componentes del vector objetos separadas por espacios
 	 */
    istream &operator>>(istream &stream, Vector3D &objeto);

	// COMPLETAR COMENTARIOS DE DOXYGEN  
	  /*! 
 	 @brief Escribe en el flujo de salida las componentes del vector “v”
 	 */
	ostream &operator<<(ostream &stream, Vector3D const &objeto);


} // \brief Fin de namespace ed.

//  _VECTOR3D_HPP_
#endif 
