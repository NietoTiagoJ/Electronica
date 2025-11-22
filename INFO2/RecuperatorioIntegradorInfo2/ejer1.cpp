
using namespace std;
#include <iostream>
#include <string>
#include <cmath>

class Punto2D{
    public:
        Punto2D();
        
        void setterX(long a);
        void setterY(long a);
        
        void getterX();
        void getterY();
        
        void imprimir();
        
        float distancia(Punto2D p2);
        float distancia();

    private:
        long x,y;
};

Punto2D::Punto2D(){
    this->x = 0;
    this->y = 0;
    
}

void Punto2D::setterX(long a){
    this->x = a;
}

void Punto2D::setterY(long a){
    this->y = a;
}

void Punto2D::getterX(){
    cout << "X :" << this->x << endl;
    
}

void Punto2D::getterY(){
    cout << "y :" << this->y << endl;
    
}

void Punto2D::imprimir(){
    
    cout << "punto en x: "<< this->x << endl;
    cout << "punto en y: "<< this->y << endl;
}


float Punto2D::distancia(Punto2D p2){
    float dist = sqrt( ((p2.x - this->x) * (p2.x - this->x)) + ((p2.y - this->y) * (p2.y - this->y))  );
    return dist;
}

float Punto2D::distancia(){
    float dist = sqrt( ((this->x)* (this->x)) + ((this->y) * (this->y)) );
    return dist;
}

int main()
{
    Punto2D p1;
    p1.setterY(1);
    p1.setterX(1);
    
    Punto2D p2;
    p2.setterY(2);
    p2.setterX(2);
    
    Punto2D p3;
    p3.setterY(3);
    p3.setterX(3);
    
    p1.imprimir();
    cout<<endl;
    p2.imprimir();
    cout<<endl;
    p3.imprimir();
    cout<<endl;
    
    cout<<p1.distancia() <<endl;
    
    cout<<p2.distancia(p3)<<endl;

    return 0;
}
