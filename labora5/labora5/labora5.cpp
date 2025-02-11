#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Producto
{
private:
	string nombre;
	int codigo;
	float precio;
	int stock;
public:
	Producto(string nom, int cod, float prec, int stk) {
		nombre = nom;
		codigo = cod;
		precio = prec;
		stock = stk;

	}
	void mostrar() {
		cout << "Código: " << codigo << ", Producto: " << nombre << ", Precio: Q" << precio << ", Stock: " << stock << endl;
	}
	int obtenerCodigo() {
		return codigo;
	}
	int obtenerStock() {
		return stock;
	}
	void actualizarStock(int cantidad) {
		if (cantidad > stock) {
			cout << "No hay suficicente stock disponible." << endl;
		}
		else {
			stock -= cantidad;
			cout << "Stock actualizado. Nuevo Stock: " << stock << endl;
		}


	}
	float obtenerValor() {
		return stock * precio;
	}
};
//fUNCIONES PARA GESTIONAR EL INVENTARIO
void agragarProducto(vector<Producto>& inventario) {
	string nombre;
	int codigo, stock;
	float precio;
	cout << "Ingrese el nombre del producto: ";
	cin >> ws;
	cin.ignore();
	getline(cin, nombre);
	cout << "Ingrese el código del producto: ";
	cin >> codigo;
	cout << "Ingrese el precio del producto: ";
	cin >> precio;
	cout << "Ingrese el stock del producto: ";
	cin >> stock;
	inventario.push_back(Producto(nombre, codigo, precio, stock));
}
void mostrarInventario(vector<Producto>& inventario) {
	if (inventario.empty()) {
		cout << "No hay productos en el inventario." << endl;
		return;
	}
	for (Producto& producto : inventario) {
		producto.mostrar();
	}
}
void buscarProducto(vector<Producto>& inventario) {
	int codigo;
	cout << "Ingrese el código del producto a buscar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Producto encontrado." << endl;
			producto.mostrar();
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void actualizarStock(vector<Producto>& inventario) {
	int codigo, cantidad;
	cout << "Ingrese el código del producto a actualizar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Ingrese la cantidad a aumentar: ";
			cin >> cantidad;
			producto.actualizarStock(cantidad);
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void calcularValorTotal(vector<Producto>& inventario) {
	float total = 0;
	for (Producto& producto : inventario) {
		total += producto.obtenerValor();
	}
	cout << "El valor total del inventario es: Q" << total << endl;
}//hola como estas espero que bien
int main() {
	vector<Producto> inventario;
	int opcion;
	do {
		cout << "1. Agregar producto" << endl;
		cout << "2. Mostrar inventario" << endl;
		cout << "3. Buscar producto" << endl;
		cout << "4. Actualizar stock" << endl;
		cout << "5. Calcular valor total" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			agragarProducto(inventario);
			break;
		case 2:
			mostrarInventario(inventario);
			break;
		case 3:
			buscarProducto(inventario);
			break;
		case 4:
			actualizarStock(inventario);
			break;
		case 5:
			calcularValorTotal(inventario);
			break;
		case 6:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opción inválida." << endl;
			break;
		}
	} while (opcion != 6);
	return 0;
}