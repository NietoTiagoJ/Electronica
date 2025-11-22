#include <iostream>

using namespace std;

class Vector3d{
	public:
		Vector3d(): x(a),y(b),z(c);
		inline void setter();
		inline void getter();
		void productoPunto();
		void mostrar();

	private:
		double x,y,z;
};


Vector3d::Vector3d(): x(a),y(b),z(c);

inline void Vector3d::setter(double a, double b, double c){
	this->x =a;
	this->y =b;
	this->z =c;
}
inline void Vector3d::getter(){
	cout
}
void Vector3d::productoPunto(){}
void Vector3d::productoCruz(){}

void Vector3d::mostrar(){
	cout<<"X: "<< this->x << endl;
	cout<<"Y: "<< this->y << endl;
	cout<<"Z: "<< this->z << endl;
}


int main(void){
	Vector3d v0, v1(1, 2, 3), v2(3, 2, 1);

    cout << "v0 = "; v0.imprimir();
    cout << endl;
    cout << "v1 = "; v1.imprimir();
    cout << endl;
    cout << "v2 = "; v2.imprimir();
    cout << endl;

	return 0;
}
