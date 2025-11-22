#include <iostream>
#include <cmath>

using namespace std;

class Punto2D{
	public:
		//Constructores
		Punto2D(): x(0),y(0) {};
		Punto2D(float a, float b): x(a), y(b){};
		
		void setX(float a);
		void setY(float a);

		void imprimir();

		float distancia();
		float distancia(Punto2D p2);

	protected:
		float x,y;
};
void Punto2D::setX(float a ){
	this->x = a;
}
void Punto2D::setY(float a){
	this->y = a;
}

void Punto2D::imprimir(){
	cout<<"("<<this->x<<","<<this->y<<")";
}

float Punto2D::distancia(){
	return sqrt( (this->x * this->x) + (this->y * this->y));
}

float Punto2D::distancia(Punto2D p2){
	return ( this->distancia() - p2.distancia() );
}

//Hasta aca anda todo


class Vector2D{
	public:
		Vector2D(): p1() , p2() {};
		Vector2D(Punto2D p1,Punto2D p2): p1(p1) , p2(p2) {};

		void imprimir();
		float modulo();

	private:
		Punto2D p1,p2;
};

void Vector2D::imprimir(){

	cout<<"Vector: ";
	this->p1.imprimir();
	cout<<"-->";
       	this->p2.imprimir();
}

float Vector2D::modulo(){
return this->p2.distancia() - this->p1.distancia();
}

class Punto3D: public Punto2D{
	public:
		Punto3D(): Punto2D(),z(0){};//en Punto2D() esta definido x e y por la herecia
		Punto3d(float a, float b, float c): Punto2D(a,b), z(c){};
		
		void setZ(float a);
		float getZ();
	protected:
		float z;
};

/*Punto3D(): x(0),y(0),z(0){};
 * Punto3d(float a, float b, float c): x(a),y(b), z(c){};
 *
 Punto3d(float a, float b, float c){
 	this->x =a;
	this->y =b;
 	this->z =c;
 }
 */

void Punto3d::setZ(float a){
	this->z = a;
}

float Punto3D::get>(){
	return this->z;
}

int main(){
	
	Punto2D p1(1,1);
	Punto2D p2(2,2);

	p1.imprimir();
	cout<<endl;
	cout<<p1.distancia()<<endl;

	Vector2D v1(p1, p2);
	
	v1.imprimir();
	cout<<endl;
	cout<<v1.modulo()<<endl;	
	return 0;
}
