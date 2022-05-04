#pragma once

#include<iostream>
#include<string>
#include<mysql.h>
#include "ConexionBD2.h"

using namespace std;

class Estudiante {
private:
	string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero, telefono;

public:
	Estudiante() {

	}
	Estudiante(string cn, string name, string lastname, string adress, string correo, string fn, string gn, string tel) {
		nombres = name;
		apellidos = lastname;
		email = correo;
		fecha_nacimiento = fn;
		genero = gn;
		direccion = adress;
		telefono = tel;
	}


	//Metodos set y get

	void setCarnet(string cn) { carnet = cn; }
	void setNombres(string name) { nombres = name; }
	void setApellidos(string lastname) { apellidos = lastname; }
	void setAdress(string Adress) { direccion = Adress; }
	void setTel(string tel) { telefono = tel; }
	void setFechaN(string fn) { fecha_nacimiento = fn; }
	void setGenero(string gn) { genero = gn; }
	void setEmail(string correo) { email = correo; }

	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getFechaN() { return fecha_nacimiento; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	string setTel() { return telefono; }


	void leer() {
		system("cls");
		int q_estado;
		ConexionBD2 cn = ConexionBD2();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "\t\tEstudiantes" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID de estudiante: " << fila[0] << endl;
					cout << "Carnet: " << fila[1] << endl;
					cout << "Nombres: " << fila[2] << endl;
					cout << "Apellidos: " << fila[3] << endl;
					cout << "Direccion: " << fila[4] << endl;
					cout << "Telefono: " << fila[5] << endl;
					cout << "Genero: " << fila[6] << endl;
					cout << "Email: " << fila[7] << endl;
					cout << "Fecha de nacimiento: " << fila[8] << endl;
					cout << "____________________________________________" << endl;
				}
			}
		}
		cout << "____________________________________________" << endl;
		cn.cerrar_conexion();
		system("pause");
	}


	void ingresar() {
		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string insertar = "INSERT INTO `db_empresa`.`estudiantes` (`carnet`,`nombres`,`apellidos`,`direccion`,`telefono`,`genero`,`email`,`fecha_nacimiento`) VALUES('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (q_estado) {
				system("cls");
				cout << "Ingreso exitoso" << endl;
				system("pause");
			}
		}
		else {
			system("cls");
			cout << "Hubo un error al ingresar los datos" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}


	void eliminar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "DELETE from estudiantes where id_estudiante = " + id_p1 + "";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Eliminacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}

	void actualizar(int id_p) {

		int q_estado;
		ConexionBD2 cn = ConexionBD2();

		cn.abrir_conexion();

		if (cn.getConectar()) {
			string id_p1 = to_string(id_p);
			string eliminar = "UPDATE `db_empresa`.`estudiantes` SET `carnet` = '" + carnet + "' , `nombres` = '" + nombres + "', `apellidos` = '" + apellidos + "' , `direccion` = '" + direccion + "' , `telefono` = '" + telefono + "', `genero` = " + genero + ", `email` = '" + email + "' , `fecha_nacimiento` = '" + fecha_nacimiento + "' WHERE `id_estudiante` = '" + id_p1 + "';";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				system("cls");
				cout << "Actualizacion exitosa" << endl;
			}
		}
		else {
			system("cls");
			cout << "Hubo un error a la hora de eliminar el registro deseado" << endl;
			system("pause");
		}
		cn.cerrar_conexion();
		system("pause");
	}



};

