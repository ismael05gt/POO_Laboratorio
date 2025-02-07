#include <iostream>
using namespace std;
class Animal
{
protected:
	string nombre;
	int edad;

public:
	Animal(string n,int e):nombre(n),edad(e){}
	virtual void hacersonido() {
		cout << "hace un sonido desconocido." << endl;
	}
};
class perro :public Animal
{
public:
	perro(string n, int e) : Animal(n, e) {}
	void hacersonido() override {
		cout << nombre << " dice: Guau!" << endl;
	}
};
class Automovil
{
private:
	string marca;
	int velocidad;
public:
	Automovil(string m, int v):marca(m),velocidad(v){}
	void acelerar() {
		velocidad += 10;
		cout << "El automóvil " << marca << " ahora va a " << velocidad << " km/h." << endl;

	}

};
//cpp
//CopiarEditar
class Persona {
private:
	string nombre;
	int edad;
public:
	Persona(string n, int e) : nombre(n), edad(e) {}
	void saludar() {
		cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << endl;
	}
};
//Función main()
int main() {
	perro miPerro("Rex", 5);
	miPerro.hacersonido();
	Automovil miCoche("Toyota", 60);
	miCoche.acelerar();
	Persona persona1("Carlos", 30);
	persona1.saludar();
	return 0;
}
