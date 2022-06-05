#pragma once
#include <iostream>
#include "ConexionBD.h"
#include <mysql.h>
#include <string>
using namespace std;
class Compra_Detalle
{
private:
	int id_compra,id_producto,cantidad;
	float precio_costo_unitario;
public:
	Compra_Detalle() {
	}
	Compra_Detalle(int idc, int idp, int cant, float pcu) {
		id_compra = idc;
		id_producto = idp;
		cantidad = cant;
		precio_costo_unitario = pcu;
	}
	void setIdCompra(int idc) { id_compra = idc; }
	void setIdProducto(int idp) { id_producto = idp; }
	void setCantidad(int cant) { cantidad = cant; }
	void setPrecioCostoUnitario(float pcu) { precio_costo_unitario = pcu; }

	int getIdCompra() { return id_compra; }
	int getIdProducto() { return id_producto; }
	int getCantidad() { return cantidad; }
	float getPrecioCostoUnitario() { return precio_costo_unitario; }

	void ingresar() {
		int q_estado;
		string idc = to_string(id_compra);
		string idp = to_string(id_producto);
		string cant = to_string(cantidad);
		string pcu = to_string(precio_costo_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "INSERT INTO compras_detalle (idcompra, idproducto, cantidad, precio_costo_unitario) VALUES ('" + idc+ "', '" + idp + "', '" + cant+ "', '"+ pcu+"');";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "INGRESO EXITOSO..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar xxx" << endl;
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
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompras inner join productos as p on cd.idproducto=p.idProducto  ;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | NO ORDEN COMPRA | PRODUCTO | DESCRIPCION | CANTIDAD | PRECIO UNITARIO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] <<" | "<<fila[5] << endl;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}

			cn.cerrar_conexion();
		}
	}
	void buscar(int idcd) {
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string idcompra_d = to_string(idcd);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompras inner join productos as p on cd.idproducto=p.idProducto  where cd.idcompras_detalle = '"+idcompra_d +"';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | NO ORDEN COMPRA | PRODUCTO | DESCRIPCION | CANTIDAD | PRECIO UNITARIO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << endl;
				}
			}
			else {
				cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
			}
			cn.cerrar_conexion();
		}
	}
	void modificar(int idcd) {
		int q_estado;
		string idcompra_d = to_string(idcd);
		string idc = to_string(id_compra);
		string idp = to_string(id_producto);
		string cant = to_string(cantidad);
		string pcu = to_string(precio_costo_unitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "UPDATE compras_detalle SET idcompra = '" + idc+ "', idproducto= '" + idp + "', cantidad= '" + cant+ "', precio_costo_unitario = '"+ pcu+"' where idcompras_detalle = '" + idcompra_d + "'";
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
	void eliminar(int idcd) {
		int q_estado;
		string idc_d = to_string(idcd);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "DELETE FROM compras_detalle WHERE idcompras_detalle = '" + idc_d + "'";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				cout << "ELIMINADO EXITOSO..." << endl;
			}
			else {
				cout << " xxx ERROR AL ELIMINAR xxx" << endl;
			}
		}
		else {
			cout << "error de conexion" << endl;
		}
		cn.cerrar_conexion();
	}


	bool ExisteComp_det(int idcd) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		int f = 0;
		string idcompra_d = to_string(idcd);
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT cd.idcompras_detalle,c.no_orden_compra,p.producto,p.descripcion,cd.cantidad,cd.precio_costo_unitario FROM compras_detalle as cd inner join compras as c on cd.idcompra=c.idcompras inner join productos as p on cd.idproducto=p.idProducto  where cd.idcompras_detalle = '" + idcompra_d + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "id | NO ORDEN COMPRA | PRODUCTO | DESCRIPCION | CANTIDAD | PRECIO UNITARIO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					f++;
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
	}
};

