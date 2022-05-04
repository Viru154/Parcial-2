
#include <iostream>
#include <string>
#include "estudiante.h"

using namespace std;

Estudiante p;

void getData();
void deleteid();
void actualizar();

//Funcion principal
int main()
{
	int op;

	Estudiante p;

	do {
		system("cls");
		system("color 4f");
		cout << "---- 1.Agregar estudiante" << endl;
		cout << "---- 2.Leer Expediente" << endl;
		cout << "---- 3.Actualizar datos" << endl;
		cout << "---- 4.Eliminar datos" << endl;
		cout << "---- 0.Salir del programa " << endl;
		cout << "Ingrese la opcion que desea realizar: ";
		cin >> op;

		switch (op) {
		case 1: getData(); break;
		case 2: p.leer(); break;
		case 3: actualizar(); break;
		case 4: deleteid(); break;
		case 0: break;
		default: cout << "La opcion que ingreso no existe, intentelo de nuevo" << endl; break;

		}
	} while (op != 0);

	system("pause");
	return 0;
}

void getData() {
	system("cls");
	string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero, telefono;


	cout << "Ingrese el carnet del estudiante: ";
	cin.ignore();
	getline(cin, carnet);
	cout << "Ingrese los nombres del estudiante: ";
	getline(cin, nombres);
	cout << "Ingrese los apellidos del estudiante: ";
	getline(cin, apellidos);
	cout << "Ingrese la direccion del estudiante: ";
	getline(cin, direccion);
	cout << "Ingrese el email del estudiante: ";
	getline(cin, email);
	cout << "Ingrese la fecha de nacimiento del estudiante (YY MM DD): ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese el genero del estudiante (TRUE/FALSE): ";
	getline(cin, genero);
	cout << "Ingrese el telefono del estudiante: ";
	getline(cin, telefono);

	Estudiante s = Estudiante(carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero, telefono);
	s.ingresar();
}

void deleteid() {
	system("cls");
	int id;
	Estudiante s;
	cout << "Ingrese le id que desea eleminar: ";
	cin >> id;

	s.eliminar(id);
}

void actualizar() {
	system("cls");
	int id;
	string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero, telefono;

	cout << "Ingrese el ID del estudiante que desea actualizar: ";
	cin >> id;

	cout << "Ingrese el nuevo carnet del estudiante: ";
	getline(cin, carnet);
	cout << "Ingrese los nuevos nombres del estudiante: ";
	getline(cin, nombres);
	cout << "Ingrese los nuevos apellidos del estudiante: ";
	getline(cin, apellidos);
	cout << "Ingrese la nueva direccion del estudiante: ";
	getline(cin, direccion);
	cout << "Ingrese el nuevo email del estudiante: ";
	getline(cin, email);
	cout << "Ingrese la nueva fecha de nacimiento del estudiante (año,mes,dia): ";
	getline(cin, fecha_nacimiento);
	cout << "Ingrese el nuevo genero del estudiante (0/1): ";
	getline(cin, genero);
	cout << "Ingrese el nuevo telefono del estudiante: ";
	getline(cin, telefono);

	Estudiante s = Estudiante(carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero, telefono);
	s.actualizar(id);
}