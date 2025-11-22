#include <stdio.h>

int n=0 ;
void setNegado(unsigned int *a, int invertir){

*a ^= (1<<invertir);
if(a==NULL){
	return -1;
}else{
	return 1;
}

}

int main (void){
setNegado(135135,1);
printf("%d \n",n);
return 0;
}
