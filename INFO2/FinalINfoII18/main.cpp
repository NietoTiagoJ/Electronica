#include <iostream>
#include "vector3d.h"
using namespace std;

int main(){

	Vector3D v1;
	Vector3D v2(1,1,-1);
	Vector3D v3(2,-2,2);
	
	v1.imprimir();
	v2.imprimir();
	v3.imprimir();
	
	cout << v2.productoPunto(v3)<<endl;
	
	v1.productoCruz(v2,v3);
	v1.imprimir();
	
return 0;
}
