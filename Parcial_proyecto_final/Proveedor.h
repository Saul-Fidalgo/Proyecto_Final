#pragma once
#include "Persona.h"
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
class Proveedor
{
private:
	string proveedor, nit, direccion;
	int telefono;
public:
	Proveedor() {
	}
	Proveedor(string prov, string n, string dir, int tel) {
		proveedor = prov;
		nit = n;
		direccion = dir;
		telefono = tel;
	}
	void setNit(string n) { nit = n; }
	void setTelefono(int tel) { telefono = tel; }
	void setNombres(string prov) { proveedor= prov; }
	void setDireccion(string dir) { direccion = dir; }

	string getNit() { return nit; }
	string getProveedor() { return proveedor; }
	int getTelefono() { return telefono; }
	string getDireccion() { return direccion; }

	void ingresar() {
		int q_estado;
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO proveedores(proveedor, nit, direccion, telefono) VALUES ('" + proveedor + "', '"+nit+"', '"+ direccion +"', '"+ tel +"');";
			const char* i = insertar.c_str();
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
			string consulta = "select * from proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout <<endl<< fila[0] <<" | "<< fila[1] << " |" << fila[2] << "|" << fila[3] << "| " << fila[4]  << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}
	void buscar(int idp) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idpro = to_string(idp);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where idproveedor = '"+ idpro+"' ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id| PROVEEDOR | nit | DIRECCION | TELEFONO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout<<endl << fila[0] << " | " << fila[1] << " |" << fila[2] << "|" << fila[3] << "| " << fila[4] << endl;
				}
			}
			else {
				cout << "ERROR EN LA CONECCION CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}


	void modificar(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		string tel = to_string(telefono);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE proveedores SET proveedor= '" + proveedor+ "', nit = '"+ nit +"', direccion = '"+ direccion +"', telefono = '"+ tel +"' WHERE (idproveedor = '" + idpr + "');";
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
	void eliminar(int idp) {
		int q_estado;
		string idpr = to_string(idp);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "Delete from proveedores where (idproveedor = '" + idpr + "');";
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


	bool existeproveedor(int idp) {
		int q_estado;
		int f = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idpro = to_string(idp);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from proveedores where idproveedor = '" + idpro + "' ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR EN LA CONEXION CON LA BASE DE DATOS";
			}
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

