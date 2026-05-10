#include <iostream>
#include <fstream>

using namespace std;

// ===============================
// STRUCT
// ===============================
struct Producto {
    int id;
    char nombre[50];
    char categoria[30];
    int cantidad;
    float precio;
};

// ===============================
// FUNCIONES
// ===============================

void registrarProducto();
void mostrarProductos();
void menu();

// ===============================
// MAIN
// ===============================

int main() {
    menu();
    return 0;
}

// ===============================
// MENÚ
// ===============================

void menu() {
    int opcion;
    do {
        cout << "\n==============================";
        cout << "\n  SISTEMA DE PRODUCTOS";
        cout << "\n==============================";
        cout << "\n1. Registrar producto";
        cout << "\n2. Mostrar inventario";
        cout << "\n3. Salir";
        cout << "\n\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: registrarProducto(); break;
            case 2: mostrarProductos(); break;
            case 3: cout << "\nPrograma finalizado.\n"; break;
            default: cout << "\nOpcion invalida.\n";
        }
    } while(opcion != 3);
}

// ===============================
// REGISTRAR PRODUCTO
// ===============================

void registrarProducto() {
    Producto p;
    ofstream archivo("productos.dat", ios::binary | ios::app);

    if(!archivo) {
        cout << "\nError al abrir el archivo.\n";
        return;
    }

    cout << "\n========== REGISTRO DE PRODUCTO ==========";
    cout << "\nID: ";
    cin >> p.id;
    cin.ignore();

    cout << "Nombre: ";
    cin.getline(p.nombre, 50);
    cout << "Categoria: ";
    cin.getline(p.categoria, 30);
    cout << "Cantidad (Stock): ";
    cin >> p.cantidad;
    cout << "Precio: ";
    cin >> p.precio;

    archivo.write((char*)&p, sizeof(p));
    archivo.close();
    cout << "\nProducto registrado correctamente.\n";
}

// ===============================
// MOSTRAR PRODUCTOS
// ===============================

void mostrarProductos() {
    Producto p;
    ifstream archivo("productos.dat", ios::binary);
    if(!archivo) {
        cout << "\nNo hay productos registrados.\n";
        return;
    }

    cout << "\n========== INVENTARIO ==========\n";
    while(archivo.read((char*)&p, sizeof(p))) {
        cout << "\n-------------------------";
        cout << "\nID: " << p.id;
        cout << "\nNombre: " << p.nombre;
        cout << "\nCategoria: " << p.categoria;
        cout << "\nStock: " << p.cantidad;
        cout << "\nPrecio: Q" << p.precio;
        cout << "\n-------------------------\n";
    }
    archivo.close();
}