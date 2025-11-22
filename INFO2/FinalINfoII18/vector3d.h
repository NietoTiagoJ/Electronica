
class Vector3D{
	public:
		Vector3D(): x(0),y(0),z(0){};//Constructor predeterminado
		Vector3D(long a, long b, long c): x(a) , y(b), z(c) {};
		
		inline void setX(const long a);
		inline void setY(const long a);
                inline void setZ(const long a);

		inline long getX();
		inline long getY();
		inline long getZ();
		
		void imprimir();
		long productoPunto(const Vector3D v2);
		
		void productoCruz(const Vector3D v1, const Vector3D v2);
/*
		bool operator ==( Vector3D v1, Vector3D v2){
		return(v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)?1:0;
		}
		*/
	protected:
		long x,y,z;
};

