#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;
class Venta_Detalle
{
private:
	int id_venta, id_producto;
	string cantidad;
	float precio_unitario;
public:
	Venta_Detalle() {
	}
	Venta_Detalle(int idv, int idp, string cant, float pu) {
		id_venta = idv;
		id_producto = idp;
		cantidad = cant;
		precio_unitario = pu;
	}
	void setIdVenta(int idv) { id_venta = idv; }
	void setIdProducto(int idp) { id_producto = idp; }
	void setCantidad(string cant) { cantidad = cant; }
	void setPrecioUnitario(float pu) { precio_unitario = pu; }

	int getIdVenta() { return id_venta; }
	int getIdProducto() { return id_producto; }
	string getCantidad() { return cantidad; }
	float getPrecioUnitario() { return precio_unitario; }
	void ingresar() {
		int q_estado;
		string id_v = to_string(id_venta);
		string id_p = to_string(id_producto);
		string p_u = to_string(precio_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string insertar = "INSERT INTO ventas_detalle (idVenta, idProducto, cantidad, precio_unitario) VALUES ('" + id_v + "', '" + id_p + "', '" + cantidad + "', '" + p_u + "');";
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

	void buscar() {
		int q_estado;
		int total = 0;
		int precio;
		string dato = "0";
		string id_v = to_string(id_venta);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idVenta=" + id_v + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | PRODUCTO | MARCA | DESCRIPCION  | CANTIDAD | PRECIO UNITARIO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << endl;
					dato = fila[5];
					precio = stoi(dato);
					total = total + precio;
				}

				cout << endl<< "EL TOTAL A PAGAR ES " << total<<endl;
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

	void buscarEspecifico(int id_vd) {
		int q_estado;
		string id_ventadetalle = to_string(id_vd);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT vd.idventas_detalle,p.producto,m.marca,p.descripcion,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where vd.idventas_detalle =" + id_ventadetalle + ";";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | PRODUCTO | MARCA | DESCRIPCION  | CANTIDAD | PRECIO UNITARIO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << endl;
					
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

	void modificar(int idve) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id_p = to_string(id_producto);
		string p_u = to_string(precio_unitario);
		string id_ve = to_string(idve);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE ventas_detalle SET  `idProducto` = '" + id_p + "', `cantidad` = '" + cantidad + "', `precio_unitario` = '" + p_u + "' WHERE (idventas_detalle=" + id_ve + ");";
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
	void eliminar(int idve) {
		int q_estado;
		string id_ve = to_string(idve);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas_detalle WHERE idVenta=" + id_ve + ";";
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

	void eliminarEspecifico(int idve) {
		int q_estado;
		string id_ve = to_string(idve);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM ventas_detalle WHERE idventas_detalle=" + id_ve + ";";
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
	bool existeVD(int idve) {
		int q_estado;
		int f=0;
		string id_ve = to_string(idve);
		string id_v = to_string(id_venta);
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT vd.idventas_detalle,v.nofactura,v.serie,v.fechafactura,p.producto,m.marca,p.descripcion,p.imagen,vd.cantidad,vd.precio_unitario FROM ventas_detalle as vd inner join ventas as v on vd.idVenta=v.idVenta inner join productos as p on vd.idProducto=p.idProducto inner join marcas as m on p.idMarca=m.idMarca where  vd.idventas_detalle=" + id_ve + "  and vd.idVenta="+id_v+";";
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

