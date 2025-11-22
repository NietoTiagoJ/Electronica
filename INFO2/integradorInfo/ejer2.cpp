#include <iostream>

using namespace std;

template <typename T>

T obtenerMaximo(T a, T b){
	return ((a>b)?a:b);
}


int main (void){
	cout<<obtenerMaximo(1,2)<<endl;
	return 0;
}
