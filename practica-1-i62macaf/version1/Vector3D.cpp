/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

// OBSERVADORES

// COMPLETAR

double ed::Vector3D::modulo() const 
{
	double aux; 
	aux= sqrt(dotProduct(*this));

	#ifndef NDEBUG
	assert(std::abs(aux-sqrt(get1()*get1() + get2()*get2() + get3()*get3()))<COTA_ERROR);
	#endif //NDEBUG

	return aux ;

}

double ed::Vector3D::dotProduct(ed::Vector3D const &v) const
{
	double aux;
	aux= get1()*v.get1() + get2()*v.get2() + get3()*v.get3() ;

	#ifndef NDEBUG
	assert(std::abs(aux-(get1()*v.get1() + get2()*v.get2() + get3()*v.get3()) )<COTA_ERROR );
	#endif //NDEBUG

	return aux ;
}

double ed::Vector3D::angulo(ed::Vector3D const &v) const
{
	#ifndef NDEBUG
	assert(modulo()*v.modulo()>0);
	#endif //NDEBUG

	double aux;
	aux = acos( dotProduct(v) / (modulo() * v.modulo()) );

	#ifndef NDEBUG
	assert(std::abs(aux-acos( dotProduct(v) / (modulo() * v.modulo() )))<COTA_ERROR );
	#endif //NDEBUG

	return aux ;
	
}

double ed::Vector3D::alfa() const
{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif //NDEBUG

	ed::Vector3D v(1,0,0);
	double aux;
	aux =  angulo(v);

	#ifndef NDEBUG
	assert(std::abs(aux-angulo(v))<COTA_ERROR);
	#endif //NDEBUG

	return aux;
}

double ed::Vector3D::beta() const
{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif //NDEBUG

	ed::Vector3D v(0,1,0);
	double aux;
	aux =  angulo(v);

	#ifndef NDEBUG
	assert(std::abs(aux-angulo(v))<COTA_ERROR);
	#endif //NDEBUG

	return aux;
}

double ed::Vector3D::gamma() const
{
	#ifndef NDEBUG
	assert(modulo()>0);
	#endif //NDEBUG

	ed::Vector3D v(0,0,1);
	double aux;
	aux =  angulo(v);

	#ifndef NDEBUG
	assert(std::abs(aux-angulo(v))<COTA_ERROR);
	#endif //NDEBUG

	return aux;
}

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D const &v) const
{
	ed::Vector3D w;

	#ifndef NDEBUG
	assert(angulo(v)>0);
	
	#endif //NDEBUG


	w.set1(  get2()*v.get3() - get3()*v.get2() ) ;
	w.set2(  -get1()*v.get3() + get3()*v.get1() ) ;
	w.set3(  get1()*v.get2() - get2()*v.get1() ) ;
	

	#ifndef NDEBUG
	assert(dotProduct(w)==0);
	assert(v.dotProduct(w)==0);
	assert(std::abs(w.modulo() - (modulo() * v.modulo() * sin(angulo(v))) )<COTA_ERROR );
	#endif //NDEBUG

	return w ;

}

double ed::Vector3D::productoMixto(ed::Vector3D const &v , ed::Vector3D const &w) const
{
	double aux ;

	#ifndef NDEBUG
	assert(angulo(v)>0);
	
	#endif //NDEBUG


	aux=(dotProduct(v.crossProduct(w)));

	#ifndef NDEBUG
	assert(std::abs(aux-(dotProduct(v.crossProduct(w))))<COTA_ERROR);
	#endif //NDEBUG

	return aux; 
}




////////////////////////////////////////////////////////////////

// MODIFICADORES

// COMPLETAR

void ed::Vector3D::sumConst(double k)
{
	double a,b,c ;
	a=get1(); //old
	b=get2();
	c=get3();

	set1(a+k);
	set2(b+k);
	set3(c+k);

	#ifndef NDEBUG
	assert(
			    (std::abs(get1()-(a+k))<COTA_ERROR)
			and (std::abs(get2()-(b+k))<COTA_ERROR)
			and (std::abs(get3()-(c+k))<COTA_ERROR)
			);
	#endif //NDEBUG
}

void ed::Vector3D::sumVect(ed::Vector3D const &v)
{
	double a,b,c ;
	a=get1(); //old
	b=get2();
	c=get3();

	set1(a+v.get1());
	set2(b+v.get2());
	set3(c+v.get3());

	#ifndef NDEBUG
	assert(
			    (std::abs(get1()-(a+v.get1()))<COTA_ERROR)
			and (std::abs(get2()-(b+v.get2()))<COTA_ERROR)
			and (std::abs(get3()-(c+v.get3()))<COTA_ERROR)
			);
	#endif //NDEBUG
}

void ed::Vector3D::multConst(double k)
{
	double a,b,c ;
	a=get1(); //old
	b=get2();
	c=get3();

	set1(a*k);
	set2(b*k);
	set3(c*k);

	#ifndef NDEBUG
	assert(
			    (std::abs(get1()-(a*k))<COTA_ERROR)
			and (std::abs(get2()-(b*k))<COTA_ERROR)
			and (std::abs(get3()-(c*k))<COTA_ERROR)
			);
	#endif //NDEBUG
}

void ed::Vector3D::multVect(ed::Vector3D const &v)
{
	double a,b,c ;
	a=get1(); //old
	b=get2();
	c=get3();

	set1(a*v.get1());
	set2(b*v.get2());
	set3(c*v.get3());

	#ifndef NDEBUG
	assert(
			    (std::abs(get1()-(a*v.get1()))<COTA_ERROR)
			and (std::abs(get2()-(b*v.get2()))<COTA_ERROR)
			and (std::abs(get3()-(c*v.get3()))<COTA_ERROR)
			);
	#endif //NDEBUG
}

void ed::Vector3D::Cuadrado()
{
	double a,b,c ;
	a=get1(); //old
	b=get2();
	c=get3();

	set1(pow(a,2));
	set2(pow(b,2));
	set3(pow(c,2));


}


////////////////////////////////////////////////////////////////////////////////

// OPERADORES

// COMPLETAR


bool ed::Vector3D::operator == (ed::Vector3D const &objeto) const{

bool aux;

aux =( 		(std::abs(get1() - objeto.get1()) < COTA_ERROR)
       and 	(std::abs(get2() - objeto.get2()) < COTA_ERROR)
       and 	(std::abs(get3() - objeto.get3()) < COTA_ERROR) 
       );
/*
	#ifndef NDEBUG
	assert(aux== 		(std::abs(get1() - objeto.get1()) < COTA_ERROR)
      			 and 	(std::abs(get2() - objeto.get2()) < COTA_ERROR)
      			 and 	(std::abs(get3() - objeto.get3()) < COTA_ERROR) );
	#endif //NDEBUG
	*/

return aux ;

}

ed::Vector3D & ed::Vector3D::operator=(ed::Vector3D const &objeto)
{
	set1(objeto.get1());
	set2(objeto.get2());
	set3(objeto.get3());

	#ifndef NDEBUG
	assert(
			    (std::abs(get1()-objeto.get1())<COTA_ERROR)
			and (std::abs(get2()-objeto.get2())<COTA_ERROR)
			and (std::abs(get3()-objeto.get3())<COTA_ERROR)
			);
	//assert() los vectores no pueden ser el mismo 
	#endif //NDEBUG

	return *this ;
}

ed::Vector3D & ed::Vector3D::operator+(ed::Vector3D const &objeto)const
{
	Vector3D *w = new Vector3D;

	w->set1(  get1()+objeto.get1() ) ;
	w->set2(  get2()+objeto.get2() ) ;
	w->set3(  get3()+objeto.get3() ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(w->get1()-(get1()+objeto.get1()))<COTA_ERROR)
			and (std::abs(w->get2()-(get2()+objeto.get2()))<COTA_ERROR)
			and (std::abs(w->get3()-(get3()+objeto.get3()))<COTA_ERROR)
			);
	
	#endif //NDEBUG


	return *w;
}

ed::Vector3D & ed::Vector3D::operator+()const
{
	Vector3D *w= new Vector3D;

	w->set1(  get1() ) ;
	w->set2(  get2() ) ;
	w->set3(  get3() ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(w->get1()-get1())<COTA_ERROR)
			and (std::abs(w->get2()-get2())<COTA_ERROR)
			and (std::abs(w->get3()-get3())<COTA_ERROR)
			);
	#endif //NDEBUG

	return *w ; 

}

ed::Vector3D & ed::Vector3D::operator-(ed::Vector3D const &objeto)const
{
	Vector3D *w = new Vector3D;

	w->set1(  get1()-objeto.get1() ) ;
	w->set2(  get2()-objeto.get2() ) ;
	w->set3(  get3()-objeto.get3() ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(w->get1()-(get1()-objeto.get1()))<COTA_ERROR)
			and (std::abs(w->get2()-(get2()-objeto.get2()))<COTA_ERROR)
			and (std::abs(w->get3()-(get3()-objeto.get3()))<COTA_ERROR)
			);
	#endif //NDEBUG


	return *w;
}

ed::Vector3D & ed::Vector3D::operator-()const
{
	Vector3D *w= new Vector3D;

	w->set1(  -get1() ) ;
	w->set2(  -get2() ) ;
	w->set3(  -get3() ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(w->get1()+get1())<COTA_ERROR)
			and (std::abs(w->get2()+get2())<COTA_ERROR)
			and (std::abs(w->get3()+get3())<COTA_ERROR)
			);
	#endif //NDEBUG

	return *w ; 

}

double & ed::Vector3D::operator*(ed::Vector3D const &objeto)const
{
	double *aux=new double ;

	*aux= (get1()*objeto.get1()  +  get2()*objeto.get2()  + get3()*objeto.get3() ) ;

	#ifndef NDEBUG
	assert(
			 std::abs(*aux-(get1()*objeto.get1()  + get2()*objeto.get2()  + get3()*objeto.get3() )<COTA_ERROR) );

			
	#endif //NDEBUG


	return  *aux;
}

ed::Vector3D & ed::Vector3D::operator*(double const &k)const
{
	Vector3D *w = new Vector3D;

	w->set1(  get1()*k ) ;
	w->set2(  get2()*k ) ;
	w->set3(  get3()*k ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(w->get1()-(get1()*k))<COTA_ERROR)
			and (std::abs(w->get2()-(get2()*k))<COTA_ERROR)
			and (std::abs(w->get3()-(get3()*k))<COTA_ERROR)
			);
	
	#endif //NDEBUG


	return *w;
}

ed::Vector3D & ed::Vector3D::operator^(ed::Vector3D const &objeto)const
{
	Vector3D *w = new Vector3D;

	*w=crossProduct(objeto);


	#ifndef NDEBUG
	assert(dotProduct(*w) == 0 and objeto.dotProduct(*w)==0 );
	assert(std::abs(w->modulo()-(modulo()* objeto.modulo()*sin(angulo(objeto))))<COTA_ERROR);

	#endif //NDEBUG



	return *w;
}





////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

// COMPLETAR

	void ed::Vector3D::leerVector3D()
	{
		double a,b,c ;
		std::cout<< "primera coordenada"<<std::endl;
		std::cin>>a;
		std::cout<< "segunda coordenada"<<std::endl;
		std::cin>>b;
		std::cout<< "tercera coordenada"<<std::endl;
		std::cin>>c;
		set1(a);
		set2(b);
		set3(c);
	}

	void ed::Vector3D::escribirVector3D() const 
	{
		std::cout<<"("<<get1()<<","<<get2()<<","<<get3()<<")"<<std::endl;
	}

////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D & operator* (double k, ed::Vector3D const & objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	vectorResultado->set1(  objeto.get1()*k ) ;
	vectorResultado->set2(  objeto.get2()*k ) ;
	vectorResultado->set3(  objeto.get3()*k ) ;

	#ifndef NDEBUG
	assert(
			    (std::abs(vectorResultado->get1()-(objeto.get1()*k))<COTA_ERROR)
			and (std::abs(vectorResultado->get2()-(objeto.get2()*k))<COTA_ERROR)
			and (std::abs(vectorResultado->get3()-(objeto.get3()*k))<COTA_ERROR)
			);
	
	#endif //NDEBUG


	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{

	std::cout << "(";
  stream << objeto.get1();
  stream << ", ";
  stream << objeto.get2();
  stream << ", ";
   stream << objeto.get3();
  std::cout << ")";

 

  return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
  
  double n;

  stream >> n;
  objeto.set1(n);

  stream >> n;
  objeto.set2(n);

  stream >> n;
  objeto.set3(n);


  return stream;
} 

} // Fin del espacio de nombres ed
