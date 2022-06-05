#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;
class Venta
{
private:
	char serie;
	int no_factura,id_empleado;
	string fecha_factura, fecha_ingreso, id_cliente;
public:
	Venta() {
	}
	Venta(int nf, char s, string ff, string idc, int ide, string fi) {
		no_factura = nf;
		serie = s;
		fecha_factura = ff;
		id_cliente = idc;
		id_empleado = ide;
		fecha_ingreso = fi;
	}
	void setNoFactura(int nf) { no_factura = nf; }
	void setSerie(char s) { serie = s; }
	void setFechaFactura(string ff) { fecha_factura = ff; }
	void setIdCliente(string idc) { id_cliente = idc;}
	void setIdEmpleado(int ide) { id_empleado = ide; }
	void setFechaIngreso(string fi) { fecha_ingreso = fi; }

	int getNoFactura() { return no_factura; }
	char getSerie() { return serie; }
	string getFechaFactura() { return fecha_factura; }
	string getidCliente() { return id_cliente; }
	int getIdEmpleado() { return id_empleado; }
	string getFechaIngreso() { return fecha_ingreso; }

	void ingresar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string nf = to_string(no_factura);
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string insertar = "INSERT INTO ventas (nofactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES ('"+nf+"', '"+serie+"', now(), "+id_cliente+",'"+id_e+"' , now());";
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
		int q_estado2;
		string id_v;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		MYSQL_ROW fila2;
		MYSQL_RES* resultado2;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta,v.nofactura,v.serie,v.fechafactura,concat(c.nombres,' ',c.apellidos) cliente,c.nit,concat(e.nombres,' ',e.apellidos) empleado,p.puesto,v.fechaingreso from ventas as v inner join clientes as c on v.idCliente=c.idCliente inner join empleados as e on v.idEmpleado=e.idEmpleado inner join puestos as p on e.idPuesto=p.id_puesto ;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | FACTURA | SERIE | FECHA |CLIENTE | NIT | EMPLEADO | PUESTO | FECHA INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0]<< " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << " | " << fila[8] << endl;
					cout << "___________________________________________" << endl;
					id_v = fila[0];
					string consulta2 = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idVenta=" + id_v + " order by vd.idVenta ;";
					const char* c2 = consulta2.c_str();
					q_estado2 = mysql_query(cn.getConectar(), c2);
					if (!q_estado2) {
						resultado2 = mysql_store_result(cn.getConectar());
						cout << "id | PRODUCTO | MARCA | DESCRIPCION  | CANTIDAD | PRECIO UNITARIO" << endl;
						while (fila2 = mysql_fetch_row(resultado2)) {
							cout << fila2[0] << " | " << fila2[1] << " | " << fila2[2] << " | " << fila2[3] << " | " << fila2[4] << " | " << fila2[5] << " | " << endl;
						}
						cout << "- - - - - - - - - - - - - - -" << endl << endl;
					}

				}
				cout << "---------------------------------------------" << endl;
			}
			else {
				cout << "ERROR AL MOSTRAR EL LISTADO";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
			cn.cerrar_conexion();
	}
	void buscar() {
		int q_estado;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.nofactura = " + n_f + " and v.serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID: " << fila[0]<<"    FACTURA NO: "<<fila[1]<<" SERIE: "<<fila[2]<<"                FECHA: "<<fila[3]<<endl ;
					cout << "CLIENTE: " << fila[4] << " NIT: " << fila[5] << endl;
					cout << "ATIENDE: " << fila[6] << " - " << fila[7] << endl;
				}
			}
			else {
				cout << "ERROR AL BUSCAR LA INFORMACION";
			}
		}
		else {
			cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
		}
			cn.cerrar_conexion();
		
	}

	void modificarNoFactura(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string n_f = to_string(no_factura);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET nofactura = '" + n_f + "' WHERE (idVenta='" + idv + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificarSerie(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string sr = to_string(serie);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET  serie = '" + sr + "'  WHERE (idVenta='" + idv + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificarFechaFactura(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET  fechafactura = " + fecha_factura + " WHERE (idVenta='" + idv + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificarIdCliente(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET idCliente = '"+id_cliente+"' WHERE (idVenta = '"+idv+"');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void modificarIdEmpleado(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string id_e = to_string(id_empleado);
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas SET idEmpleado = '" + id_e + "' WHERE (idVenta='" + idv + "');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Actualizar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}


	void eliminar(string idv) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas WHERE idVenta="+idv+";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Eliminar  xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	bool existeVenta() {
		int q_estado;
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		int f = 0;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT v.idVenta, v.nofactura, v.serie, v.fechafactura, concat(c.nombres, ' ', c.apellidos) cliente, c.nit, concat(e.nombres, ' ', e.apellidos) empleado, p.puesto, v.fechaingreso from ventas as v inner join clientes as c on v.idCliente = c.idCliente inner join empleados as e on v.idEmpleado = e.idEmpleado inner join puestos as p on e.idPuesto = p.id_puesto where v.nofactura = " + n_f + " and v.serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				
				while (fila = mysql_fetch_row(resultado)) {
					f++;
				}
			}
			else {
				cout << "ERROR AL BUSCAR LA INFORMACION";
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

	string asignardatos() {
		int q_estado;
		string error = "ERROR";
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idVenta from ventas where nofactura=" + n_f + " and serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					return fila[0];
					fecha_factura = fila[1];
					id_cliente = fila[2];
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

	string obteneridemp() {
		int q_estado;
		string error = "ERROR";
		string n_f = to_string(no_factura);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select idEmpleado from ventas where nofactura=" + n_f + " and serie = '" + serie + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
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


