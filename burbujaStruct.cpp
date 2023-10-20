#include <stdio.h>
#include <iostream>
using namespace std;

struct Persona{
	int dni;
	string nombre;
	string apellido;
	int edad;
};
int main(){
	struct Persona p;
	p.dni=1;
	p.nombre = "esteban";
	p.apellido = "aguero";
	p.edad = 20;

	struct Persona p1;
	p1.dni=20;
	p1.nombre = "mauro";
	p1.apellido = "banegas";
	p1.edad = 25;	
	
	struct Persona p2;
	p2.dni=7;
	p2.nombre = "tomas";
	p2.apellido = "perez";
	p2.edad = 19;	
	
	struct Persona p3;
	p3.dni=0;
	p3.nombre = "daniel";
	p3.apellido = "vildoza";
	p3.edad = 21;	
	
	struct Persona v[] = {p, p1, p2, p3};
	
	int n, aux, b;
	
	n = sizeof(v) / sizeof(v[0]);
	//ordenar de forma ascendente
	do{
		b=0;
		for(int i=0; i<n-1; i++){
			if(v[i].dni>v[i+1].dni){
				aux = v[i].dni;
				v[i].dni = v[i+1].dni;
				v[i+1].dni = aux;
				b=1;
			}
		}
	}while(b==1);
	
	for(int i=0; i<n; i++){
		printf("v[%d] = %d \n", i, v[i].dni);
	}
	
	return 0;
}
