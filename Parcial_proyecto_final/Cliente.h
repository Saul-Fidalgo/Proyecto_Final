#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;
class Cliente : Persona
{
	//atributos
private: string nit,fecha_ingreso,correo_electronico;
	   //constructor
public:
	Cliente() {
	}
	Cliente(string nom, string ape, int gen, int tel, string n,string fi,string c) :Persona(nom, ape, gen, tel) {
		nit = n;
		correo_electronico = c;
		fecha_ingreso = fi;
	}
	//METODOS
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setApellidos(string ape) { apellidos = ape; }

	void setGenero(int gen) { genero = gen; }

	void setTelefono(int tel) { telefono = tel; }
	void setNombres(int nom) { nombres = nom; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }
	void setCorreoElectronico(string c) { correo_electronico = c; }

	//get (mostrar)

	string getNit() { return nit; }

	string getNombres() { return nombres; }

	string getApellidos() { return apellidos; }

	int getGenero() { return genero; }

	int getTelefono() { return telefono; }
	
	string getFechaingreso() { return fecha_ingreso; }
	string getCorreoElectronico() { return correo_electronico; }


	//metodo
	void ingresar() {
		int q_estado;
		string t = to_string(telefono);
		string g = to_string(genero);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string ingresar = "INSERT INTO clientes (nombres, apellidos, nit, genero, telefono, correo_electronico, fechaingreso) VALUES ('" + nombres + "', '" + apellidos + "', '" + nit + "', " + g + ", '" + t + "', '" + correo_electronico + "', now());";
			const char* i = ingresar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
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
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id, nombres ,apellidos, nit, genero, telefono,correo electronico,fecha ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << fila[1] << " |" << fila[2] << "\t|" << fila[3] << "\t| "<<fila[4] << " \t|" << fila[5] << "\t|" << fila[6] << "|" << fila[7] << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
	void buscar(int idc) {
		int q_estado;
		string id_c = to_string(idc);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM clientes where idCliente="+id_c+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id, nombres ,apellidos, nit, genero, telefono,correo electronico,fecha ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << fila[1] << " |" << fila[2] << "\t|" << fila[3] << "\t| " << fila[4] << " \t|" << fila[5] << "\t|" << fila[6] << "|" << fila[7] << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}
			
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
	void buscarXnit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT nombres,apellidos,nit,correo_electronico FROM clientes where nit="+nit+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << fila[1] << " |" << fila[2] << "\t|" << fila[3] << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}
			
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificar(int id_c) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string t = to_string(telefono);
		string g = to_string(genero);
		string idc = to_string(id_c);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE clientes SET nombres = '"+nombres+"', apellidos = '"+apellidos+"', nit = '"+nit+"', genero = "+g+", telefono = '"+t+"', correo_electronico = '"+correo_electronico+"', fechaingreso = now() WHERE (idCliente = '"+idc+"');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {

				cout << "MODIFICACION EXISTOSA" << endl;
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}

		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar(int id_c) {
		int q_estado;
		string idc = to_string(id_c);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  consultar = "DELETE FROM clientes WHERE idCliente=" + idc + ";";
			const char* i = consultar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	bool existexnit() {
		int q_estado;
		int f = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			resultado = mysql_store_result(cn.getConectar());
			string consulta = "SELECT idCliente FROM clientes where nit=" + nit + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool existexid(int idc) {
		int q_estado;
		int f = 0;
		string id_c = to_string(idc);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			resultado = mysql_store_result(cn.getConectar());
			string consulta = "SELECT * FROM clientes where idCliente=" + id_c + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS" << endl;
			}
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
		if (f == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	string asignardatos() {
		int q_estado;
		string error = "ERROR";
		string t;
		string g;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM clientes where nit=" + nit + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					nombres = fila[1];
					apellidos = fila[2];
					correo_electronico = fila[6];
					fecha_ingreso = fila[7];
					return fila[0];
				}
			}
			else {
				return error;
			}

		}
		else {
			return error;
		}
		cn.cerrar_conexion();
	}
};
