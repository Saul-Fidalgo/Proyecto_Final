#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include<string>
using namespace std;
class Marca
{
private:
	string marca;
public:
	Marca() {
	}
	Marca(string m) {
		marca = m;
	}
	void setMarca(string m) { marca = m; }
	string getMarca() { return marca; }



	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO marcas(marca) VALUES ('" + marca + "');";
			const char* i = insertar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
	if (!q_estado) {
		cout << "Ingreso Exitoso ..." << endl;
	}
	else {
		cout << " xxx Error al Ingresar  xxx" << endl;
	}
}
		else {
		cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}
	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | Marcas" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  " << fila[1] << endl;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}
	void buscar(int idMarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idM = to_string(idMarca);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from marcas where idmarca= " + idM + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "ID | MARCAS" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  " << fila[1] << endl;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}
	void modificar(int idMarca) {
		int q_estado;
		string idm = to_string(idMarca);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE marcas SET marca= '" + marca + "' WHERE (idmarca = '" + idm + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
	}
	void eliminar(int idMarca) {
		int q_estado;
		string idm = to_string(idMarca);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Delete from marcas where (idmarca= '" + idm + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ELIMINACION EXITOSA" << endl;
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}

		cn.cerrar_conexion();
	}

	bool existemarca(int id_m) {
		int q_estado;
		int f = 0;
		string idm = to_string(id_m);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from marcas where (idmarca= '" + idm + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
		cn.cerrar_conexion();
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}
	}
};

