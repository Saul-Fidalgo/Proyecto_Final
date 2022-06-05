#pragma once
#include "Persona.h"
#include "ConexionBD.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;
class Empleado : Persona
{
private:
	string direccion, dpi, fecha_nacimiento, fecha_inicio_lab, fecha_ingreso;
	int id_puesto;
public:
	Empleado() {
	}
	Empleado(string nom, string ape, string dir, int tel, string DPI, int gen, string fn, int idp, string fil, string fi) :Persona(nom, ape, gen, tel) {
		direccion = dir;
		dpi = DPI;
		fecha_nacimiento = fn;
		id_puesto = idp;
		fecha_inicio_lab = fil;
		fecha_ingreso = fi;
	}
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDpi(int DPI) { dpi = DPI; }
	void setGenero(int gen) { genero = gen; }
	void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
	void setIdPuesto(int idp) { id_puesto = idp; }
	void setFechaInicioLabores(string fil) { fecha_inicio_lab = fil; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getDpi() { return dpi; }
	int getGenero() {return genero ; }
	string getFechaNacimiento() { return fecha_nacimiento ; }
	int getIdPuesto() { return id_puesto; }
	string getFechaInicioLabores() { return fecha_inicio_lab ; }
	string getFechaIngreso() { return fecha_ingreso ; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		string g = to_string(genero);
		string ip = to_string(id_puesto);
		if (cn.getConectar()) {
			string  consulta = "INSERT INTO empleados (nombres, apellidos, direccion, telefono, DPI, genero,fecha_nacimento, idPuesto, fecha_inicio_labores, fechaingreso) VALUES ('"+nombres+"', '"+apellidos+"', '"+direccion+"', '"+t+"', '"+dpi+"', "+g+", '"+fecha_nacimiento+"', '"+ip+"', '"+fecha_inicio_lab+"', now());";
			const char* i = consulta.c_str();
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
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto ORDER BY idEmpleado; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | nombres | apellidos | direccion | telefono | dpi | genero | fecha nacimiento | puesto | inicio de labores | fecha de ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << endl;
					cout << fila[0] << " \n| " << fila[1] << " \n| " << fila[2] << " \n| " << fila[3] << " \n| " << fila[4] << " \n| " << fila[5] << " \n| " << fila[6] << " \n| " << fila[7] << " \n| " << fila[8] << " \n| " << fila[9] << " \n| " << fila[10] << endl;
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
	void buscar(int ide) {
		int q_estado;
			MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string dato = to_string(ide);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto where e.idEmpleado ="+dato+" ; ";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | nombres | apellidos | direccion | telefono | dpi | genero | fecha nacimiento | puesto | inicio de labores | fecha de ingreso" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << " | " << fila[9] << " | " << fila[10] << endl;
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
	void modificar(int idEmpleado) {
		int q_estado;
		string ide = to_string(idEmpleado);
		string t = to_string(telefono);
		string g = to_string(genero);
		string ip = to_string(id_puesto);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  consultar = "UPDATE empleados SET nombres = '"+nombres+"', apellidos = '"+apellidos+"', direccion = '"+direccion+"', telefono = '"+t+"', DPI = '"+dpi+"', genero = "+g+", fecha_nacimento = '"+fecha_nacimiento+"', idPuesto = '"+ip+"', fecha_inicio_labores = '"+fecha_inicio_lab+"', fechaingreso = now() WHERE (idEmpleado = '"+ide+"');";
			const char* i = consultar.c_str();
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
	void eliminar(int idEmpleado) {
		int q_estado;
		string ide = to_string(idEmpleado);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string  consultar = "DELETE FROM empleados WHERE idEmpleado=" + ide + ";";
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

	bool existeEmpleado(int ide) {
		int q_estado;
		int f = 0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string dato = to_string(ide);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select e.idEmpleado,e.nombres,e.apellidos,e.direccion,e.telefono,e.DPI,e.genero,e.fecha_nacimento,p.puesto,e.fecha_inicio_labores,e.fechaingreso from empleados as e inner join puestos as p on e.idPuesto = p.id_puesto where e.idEmpleado =" + dato + " ; ";
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

	void asignardatos(int idEmpleado) {
		int q_estado;
		string error = "ERROR";
		string id = to_string(idEmpleado);
		string t;
		string g;
		string idp;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM empleados where idEmpleado="+id+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					nombres = fila[1];
					apellidos = fila[2];
					direccion = fila[3];
					

				}
			}
			else {
				cout << "ERROR DE CONEXION" << endl;
			}

		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrar_conexion();
	}
};


