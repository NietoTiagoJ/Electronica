#ifndef	HORA_H
#define HORA_H

class Hora{
        public:
		Hora();
		void set(int h, int m, int s);
		void setHora(int h);
		void setMinutos(int m);
		void setSegundos(int s);
       		void setCurrentTime(); 

		void get();
	private:
                int hora,minutos,segundos;
};


#endif
