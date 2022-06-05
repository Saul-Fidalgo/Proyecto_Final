#pragma once
#include <iostream>
using namespace std;
class Persona
{
protected: string nombres, apellidos;
		 int telefono=0,genero=0;
		 //constructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, int gen, int tel) {
		nombres = nom;
		apellidos = ape;
		genero = gen;
		telefono = tel;
	}
};

