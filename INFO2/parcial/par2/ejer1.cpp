#include <iostream>
#include <string>

using namespace std;

class Producto{
    public:    
        Producto();
        Producto(string n);
        Producto(string n, int c, float p);
	Producto(string n, int c);

       void Producto::mostrarDetalles();
    private:
        string nombre;
        int codigo;
        float precio;;
};


Producto::Producto(){}

Producto::Producto(string n){
    this->nombre = n;
}

Producto::Producto(string n, int c){
    this->nombre = n;
    this->codigo = c;
}
Producto::Producto(string n, int c, float p){
    this->nombre = n;
    this->codigo = c;
    this->precio = p;
}


void Producto::mostrarDetalles(){
    cout<<this->nombre<<endl;
    cout<<this->codigo<<endl;
    cout<<this-<precio<<endl;
}

int main(){
    Producto coca;
    Producto pepsi;
    Producto galleta;

    coca.Producto("coca");
    pepsi.Producto("Pepsi",12412);
    galleta.Producto("Galleta", 12414, 1241);


    coca.MostrarDetalles;
    pepsi.MostrarDetalles;
    galleta.MostrarDetalles;

    return 0;
}




