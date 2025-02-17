#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Vehiculo
{
private:
	string marca;
	string modelo;
	double precio;
public:
	Vehiculo(string marca, string modelo, double precio) {
		this->marca = marca;
		this->modelo = modelo;
		this->precio = precio;
	}
	void mostrarinfo() {
		cout << "Marca: " << marca;
		cout << " Modelo: " << modelo;
		cout << " Precio: " << precio<<endl;
	}
	void getMarca(string marca) {
		this->marca = marca;
	}
	void getModelo(string modelo) {
		this->modelo = modelo;
	}
	void getPrecio(double precio) {
		this->precio = precio;
	}
};
class Automovil : public Vehiculo {
private:
	int puertas;
public:
	Automovil(string marca, string modelo, double precio, int puertas) : Vehiculo(marca, modelo, precio) {
		this->puertas = puertas;
	}
	void mostrarinfo() {
		Vehiculo::mostrarinfo();
		cout << "Puertas: " << puertas << endl;
	};
};
class Motocicleta : public Vehiculo {
private:
	int cilindraje;
public:
	Motocicleta(string marca, string modelo, double precio, int cilindraje) : Vehiculo(marca, modelo, precio) {
		this->cilindraje = cilindraje;
	}
	void mostrarinfo() {
		Vehiculo::mostrarinfo();
		cout << "Cilindraje: " << cilindraje << endl;
	};
};
class Camioneta: public Vehiculo
{
private:
	string capacidadCarga;

public:
	Camioneta(string marca, string modelo, double precio, string capacidadCarga) : Vehiculo(marca, modelo, precio) {
		this->capacidadCarga = capacidadCarga;
	}
	void mostrarinfo() {
		Vehiculo::mostrarinfo();
		cout << "Capacidad de carga: " << capacidadCarga << endl;
	};
};
int main()
{
	vector<Vehiculo*> vehiculos;
	vehiculos.push_back(new Automovil("Toyota", "Corolla", 20000, 4));
	vehiculos.push_back(new Motocicleta("Honda", "CBR", 10000, 250));
	vehiculos.push_back(new Camioneta("Mazda", "BT-50", 30000, "1 tonelada"));
	for (int i = 0; i < vehiculos.size(); i++) {
		vehiculos[i]->mostrarinfo();
	}
	return 0;
}