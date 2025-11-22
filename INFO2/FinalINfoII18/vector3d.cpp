#include <iostream>
#include "vector3d.h"

using namespace std;

inline void Vector3D::setX(const long a){  //Setea X
 this->x = a;
}

inline void Vector3D::setY(const long a){  //Setea Y
this->y = a;
} 

inline void Vector3D::setZ(const long a){ //Setea Z
this->z = a;
}

inline long Vector3D::getX(){  //Retorna X
	return this->x;
}

inline long Vector3D::getY(){  //Retorna Y
        return this->x;
}

inline long Vector3D::getZ(){  //Retorna Z
        return this->x;
}

void Vector3D::imprimir(){
  	std::cout <<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<endl;
}

long Vector3D::productoPunto(const Vector3D v2){
 return (this->x * v2.x + this->y * v2.y + this->z * v2.z );
}

void Vector3D::productoCruz(const Vector3D v1, const Vector3D v2){
	this->x = (v1.y*v2.z - v1.z * v2.y);
	this->y = (v1.z*v2.x - v1.x * v2.z);
	this->z = (v1.x*v2.y - v1.y * v2.x);
}
/*
bool Vector3D::igual operator ==(const Vector3D v1, const Vector3D v2){

return (v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)?1:0;
}*/
