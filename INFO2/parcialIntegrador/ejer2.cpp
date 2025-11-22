#include <iostream>

using namespace std;
class Vector3d{
	public:
		inline Vector3d();
		inline Vector3d(double a, double b, double c);

		inline void setter(double a, double b, double c){
			x =a;
			y =b;
			z=c;
		}
		inline void getter(){
			cout<<x;
			cout<<y;
			cout<<z;
		}

		double productoPunto(const Vector3d a)const;

		Vector3d productoCruz(const Vector3d a)const;
		
		void imprimir();
	private:
		double x,y,z;
};

inline Vector3d::Vector3d(){
	this->x=0;
	this->y=0;
	this->z=0;
}

inline Vector3d::Vector3d(double a,double b, double c){
	this->x=a;
	this->y=b;
	this->z=c;
}
/*
inline void setter(double a,double b,double c){
	this->x = a;
	this->y = b;
	this->z = c;
} */
/*
inline void getter(){
	cout<<this->x;
	cout<<this->y;
	cout<<this->z;
}
*/
Vector3d Vector3d::productoCruz(const Vector3d a)const{
	return Vector3d(
			y * a.z - z * a.y,
			z * a.x - x * a.z,
			x * a.y - y * a.x
	);
}

double Vector3d::productoPunto(const Vector3d a)const{
	return ((x * a.x) + (y * a.y) + (z * a.z));
}
void Vector3d::imprimir(){
	cout<<"Valor X: "<<this->x<<endl;
	cout<<"valor Y: "<<this->y<<endl;
	cout<<"Valor Z: "<<this->z<<endl;
}


int main (void){
	Vector3d v0, v1(1, 2, 3), v2(3, 2, 1);

    cout << "v0 = "; v0.imprimir();
    cout << endl;
    cout << "v1 = "; v1.imprimir();
    cout << endl;
    cout << "v2 = "; v2.imprimir();
    cout << endl;

    // Producto punto o escalar
    cout << "v1 . v2 = " << v1.productoPunto(v2) << endl;

    // Producto cruz o vectorial
    Vector3d v1_cruz_v2 = v1.productoCruz(v2);
    cout << "v1 x v2 = "; v1_cruz_v2.imprimir();
    cout << endl;
	

return 0;
}
