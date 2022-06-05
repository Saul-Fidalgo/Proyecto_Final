// PROYECTO FINAL PROGRA 1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cliente.h"
#include "Puesto.h"
#include "Empleado.h"
#include "Proveedor.h"
#include "Marca.h"
#include "Producto.h"
#include "Venta.h"
#include "Compra_Detalle.h"
#include "Venta_Detalle.h"
#include "Compra.h"
#include <string>
#include <conio.h>
#include <string.h>
using namespace std;

void menu();

void ingresarPuesto();
void buscarPuesto();
void modificarPuesto();
void eliminarPuesto();

void ingresarEmpleado();
void buscarEmpleado();
void modificarEmpleado();
void eliminarEmpleado();

void ingresarCliente(string nit);
void buscarCliente();
void modificarCliente();
void eliminarCliente();

void ingresarVenta();
void buscarVenta();
void mostrarVenta();
void modificarVenta();
void eliminarVenta();

void ingresarMarca();
void buscarMarca();
void modificarMarca();
void eliminarMarca();

void ingresarProducto();
void buscarProducto();
void modificarProducto();
void eliminarProducto();

void ingresarCompra();
void MostrarCompras();
void BuscarCompras();
void ModificarCompras();
void eliminarCompras();

void IngresarProveedor();
void MostrarProveedor();
void BuscarProveedor();
void ModificarProveedor();
void EliminarProveedor();


void puestos();
void empleados();
void clientes();
void proveedores();
void marcas();
void productos();
void ventas();
void compras();





int main()
{
    menu();
}



void menu() {
    int Menu;

    do {

        system("Color f");//amarillo lineas

        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            ***************************************** \n");
        printf("            *        BIENVENIDO AL PROGRAMA         * \n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - PUESTOS                   *\n");
        printf("            *2*         - EMPLEADOS                 *\n");
        printf("            *3*         - CLIENTES                  *\n");
        printf("            *4*         - PROVEEDORES               *\n");
        printf("            *5*         - MARCAS                    *\n");
        printf("            *6*         - PRODUCTOS                 *\n");
        printf("            *7*         - VENTAS                    *\n");
        printf("            *8*         - COMPRAS                   *\n");
        printf("            *9*         - SALIR                     *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);


        switch (Menu) {
        case 1:
            puestos();
            break;
        case 2:
            empleados();
            break;
        case 3:
            clientes();
            break;
        case 4:
            proveedores();
            break;
        case 5:
            marcas();
            break;
        case 6:
            productos();
            break;
        case 7:
            ventas();
            break;
        case 8:
            compras();
            break;
        }

    } while (Menu != 9);
}

void puestos() {
    Puesto p = Puesto();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA  DE PUESTOS        *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarPuesto();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarPuesto();
            system("pause");
            break;
        case 3:
            system("cls");
            p.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarPuesto();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarPuesto();
            system("pause");
            break;
        }
    } while (Menu != 6);

}
void empleados() {
    Empleado e = Empleado();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE EMPLEADOS       *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarEmpleado();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarEmpleado();
            system("pause");
            break;
        case 3:
            system("cls");
            e.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarEmpleado();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarEmpleado();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void clientes() {
    string nit;
    Cliente c = Cliente();
    int Menu = 0;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA  DE CLIENTES       *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");

        switch (Menu) {
        case 1:
            system("cls");
            cout << "INGRESE NIT DEL CLIENTE ";
            cin >> nit;
            bool existe;
            c.setNit(nit);
            existe = c.existexnit();
            if (existe == false) {
                ingresarCliente(nit);
            }
            else {
                cout << "ESTE NIT YA EXISTE" << endl;
            }
            system("pause");
            break;
        case 2:system("cls");
            buscarCliente();
            system("pause");
            break;
        case 3:
            system("cls");
            c.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarCliente();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarCliente();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void proveedores() {
    int opc;
    Proveedor pv = Proveedor();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE PROVEEDORES     *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            IngresarProveedor();
            system("pause");
            break;
        case 2:
            system("cls");
            BuscarProveedor();
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarProveedor();
            system("pause");
            break;
        case 4:
            system("cls");
            ModificarProveedor();
            system("pause");
            break;
        case 5:
            system("cls");
            EliminarProveedor();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void marcas() {
    int opc;
    Marca m = Marca();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE MARCAS          *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarMarca();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarMarca();
            system("pause");
            break;
        case 3:
            system("cls");
            m.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarMarca();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarMarca();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void productos() {
    int opc;
    Producto pr = Producto();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE PROVEEDOR       *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarProducto();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarProducto();
            system("pause");
            break;
        case 3:
            system("cls");
            pr.mostrar();
            system("pause");
            break;
        case 4:
            system("cls");
            modificarProducto();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarProducto();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void ventas() {
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE VENTAS         *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarVenta();
            system("pause");
            break;
        case 2:
            system("cls");
            buscarVenta();
            system("pause");
            break;
        case 3:
            system("cls");
            mostrarVenta();
            system("pause");
            break;
        case 4:

            system("cls");
            modificarVenta();
            system("pause");
            break;


        case 5:
            system("cls");
            eliminarVenta();
            system("pause");
            break;
        }
    } while (Menu != 6);
}
void compras() {
    Compra cp = Compra();
    Compra_Detalle cdt = Compra_Detalle();
    int Menu;
    do {
        system("cls");
        printf("\n\n                    %c", 169);
        printf(" Copyrigh 2022 by Grupo 3\n");
        printf("            *****************************************\n");
        printf("            *              TABLA DE COMPRAS         *\n");
        printf("            *       Que opcion desea gestionar      *\n");
        printf("            ***************************************** \n");
        printf("            *1*         - INGRESAR REGISTROS        *\n");
        printf("            *2*         - BUSCAR REGISTRO           *\n");
        printf("            *3*         - MOSTRAR EL LISTADO        *\n");
        printf("            *4*         - MODIFICAR UN REGISTRO     *\n");
        printf("            *5*         - ELIMINAR UN REGISTRO      *\n");
        printf("            *6*         - REGRESAR                  *\n");
        printf("            ***************************************** \n");
        printf("            ***       Seleccione una opcion:     ");
        scanf_s("%d", &Menu);
        switch (Menu) {
        case 1:
            system("cls");
            ingresarCompra();
            system("pause");
            break;
        case 2:
            system("cls");
            BuscarCompras();
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarCompras();
            system("pause");
            break;
        case 4:

            system("cls");
            ModificarCompras();
            system("pause");
            break;
        case 5:
            system("cls");
            eliminarCompras();
            system("pause");
            break;
        }
    } while (Menu != 6);
}

void ingresarPuesto() {
    string puesto;
    cout << "Ingrese el puesto ";
    cin.ignore();
    getline(cin, puesto);
    Puesto p = Puesto(puesto);
    p.ingresar();
}
void buscarPuesto() {
    int idpues;
    bool existe;
    cout << "Ingrese el No de ID que desea buscar ";
    cin >> idpues;
    Puesto p = Puesto();
    existe = p.existepuesto(idpues);
    if (existe == true) {
        p.buscar(idpues);
    }
    else {
        cout << "EL ID BUSCADO NO EXISTE U NO ES VALIDO" << endl;
    }
}
void modificarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DEL PUESTO ";
    cin >> idp;
    Puesto p = Puesto();
    existe = p.existepuesto(idp);
    if (existe == true) {
        p.buscar(idp);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            cout << "INGRESE EL NUEVO NOMBRE DEL PUESTO " << endl;
            cin.ignore();
            getline(cin, puesto);
            p = Puesto(puesto);
            p.modificar(idp);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
    }
    else {
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS" << endl;
    }
}
void eliminarPuesto() {
    int idp;
    string puesto;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DEL PUESTO ";
    cin >> idp;
    Puesto pues = Puesto();
    existe = pues.existepuesto(idp);
    if (existe == true) {
        pues.buscar(idp);
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            pues.eliminar(idp);
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarEmpleado() {
    Puesto pu = Puesto();
    string nombres, apellidos, direccion, dpi, fecha_nacimiento, fecha_inicio_lab, mf;
    int id_puesto, telefono, genero = -1;
    bool existe;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE NOMBRES ";
    cin.ignore();
    getline(cin, nombres);
    cout << "INGRESE APELLIDOS ";
    getline(cin, apellidos);
    cout << "INGRESE LA DIRECCION DE DOMICILIO ";
    getline(cin, direccion);
    cout << "INGRESE TELEFONO ";
    cin >> telefono;
    cout << "INGRESE SU DPI ";
    cin.ignore();
    getline(cin, dpi);
    cout << "INGRESE SU GENERO [M/F] ";
    do {
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                cout << "INGRESE SU GENERO [M/F] ";
            }
        }
    } while (genero != 0 && genero != 1);
    cout << "INGRESE LA FECHA DE NACIMIENTO [AÑO-MES-DIA] ";
    cin.ignore();
    getline(cin, fecha_nacimiento);
    cout << "ASIGNE EL PUESTO POR MEDIO DEL ID " << endl;
    do {
        pu.mostrar();
        cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
        cin >> id_puesto;
        existe = pu.existepuesto(id_puesto);
    } while (existe == false);
    cout << "INGRESE LA FECHA DE INICIO DE LABORES [AÑO-MES-DIA] ";
    cin.ignore();
    getline(cin, fecha_inicio_lab);
    Empleado e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_lab, "");
    e.ingresar();
}
void buscarEmpleado() {
    Empleado e = Empleado();
    bool existe;
    int ide;
    cout << "INGRESE EL ID DEL EMPLEADO A BUSCAR ";
    cin >> ide;
    existe = e.existeEmpleado(ide);
    if (existe == true) {
        e.buscar(ide);
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarEmpleado() {
    Empleado e = Empleado();
    Puesto pu = Puesto();
    string nombres, apellidos, direccion, dpi, fecha_nacimiento, fecha_inicio_lab, mf;
    int id_puesto, telefono, genero = -1;
    bool existeE, existe;
    int ide;
    char respuesta;
    cout << "INGRESE EL ID DEL EMPLEADO A MODIFICAR ";
    cin >> ide;
    existeE = e.existeEmpleado(ide);
    if (existeE == true) {
        e.buscar(ide);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N]";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "INGRESE NOMBRES ";
            cin.ignore();
            getline(cin, nombres);

            cout << "INGRESE APELLIDOS ";
            getline(cin, apellidos);

            cout << "INGRESE LA DIRECCION DE DOMICILIO ";
            getline(cin, direccion);

            cout << "INGRESE TELEFONO ";
            cin >> telefono;

            cout << "INGRESE SU DPI ";
            cin.ignore();
            getline(cin, dpi);

            cout << "INGRESE SU GENERO [M/F] ";
            do {
                cin >> mf;
                if (mf == "M" || mf == "m") {
                    genero = 0;
                }
                else {
                    if (mf == "F" || mf == "f") {
                        genero = 1;
                    }
                    else {
                        cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                        cout << "INGRESE SU GENERO [M/F] ";
                    }
                }
            } while (genero != 0 && genero != 1);

            cout << "INGRESE LA FECHA DE NACIMIENTO [AÑO-MES-DIA] ";
            cin.ignore();
            getline(cin, fecha_nacimiento);

            cout << "ASIGNE EL PUESTO POR MEDIO DEL ID " << endl;
            do {
                pu.mostrar();
                cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
                cin >> id_puesto;
                existe = pu.existepuesto(id_puesto);
            } while (existe == false);

            cout << "INGRESE LA FECHA DE INICIO DE LABORES [AÑO-MES-DIA] ";
            cin.ignore();
            getline(cin, fecha_inicio_lab);
            e = Empleado(nombres, apellidos, direccion, telefono, dpi, genero, fecha_nacimiento, id_puesto, fecha_inicio_lab, "");
            e.modificar(ide);
        }
        else {
            cout << "MODIFICACION CANCELADA" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void eliminarEmpleado() {
    Empleado e = Empleado();
    bool existe;
    int ide;
    char respuesta;
    cout << "SI YA SE HA GENERADO OPERACIONES CON ESTE EMPLEADO NO PODRA SER ELIMINADA DEL REGISTRO" << endl;
    cout << "INGRESE EL ID DEL EMPLEADO A BUSCAR ";
    cin >> ide;
    existe = e.existeEmpleado(ide);
    if (existe == true) {
        e.buscar(ide);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            e.eliminar(ide);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }

}

void ingresarCliente(string nit) {
    Cliente c = Cliente();
    string correo_electronico, nombres, apellidos, mf;
    int telefono, genero = -1;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE NOMBRES ";
    cin.ignore();
    getline(cin, nombres);
    cout << "INGRESE APELLIDOS ";
    getline(cin, apellidos);
    cout << "INGRESE TELEFONO ";
    cin >> telefono;
    cout << "INGRESE SU GENERO [M/F] ";
    do {
        cin >> mf;
        if (mf == "M" || mf == "m") {
            genero = 0;
        }
        else {
            if (mf == "F" || mf == "f") {
                genero = 1;
            }
            else {
                cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                cout << "INGRESE SU GENERO [M/F] ";
            }
        }
    } while (genero != 0 && genero != 1);
    cout << "INGRESE SU CORREO ELECTRONICO ";
    cin.ignore();
    getline(cin, correo_electronico);
    c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
    c.ingresar();
}
void buscarCliente() {
    Cliente c = Cliente();
    bool existe;
    int idc, opcion;
    cout << "BUSCAR CLIENTE POR MEDIO DE: " << endl;
    cout << "[1] ID CLIENTE" << endl;
    cout << "[2] NIT" << endl;
    cin >> opcion;
    if (opcion == 1)
    {
        cout << "INGRESE ID DEL CLIENTE ";
        cin >> idc;
        existe = c.existexid(idc);
        if (existe == true) {
            c.buscar(idc);
        }
        else {
            cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
        }
    }
    if (opcion == 2) {
        string nit;
        cout << "INGRESE NIT DEL CLIENTE ";
        cin >> nit;
        c.setNit(nit);
        existe = c.existexnit();
        if (existe == true) {
            string idc = c.asignardatos();
            int idcliente = stoi(idc);
            c.buscar(idcliente);
        }
        else {
            cout << "ESTE NIT NO ESTA EN LA BASE DE DATOS" << endl;
        }
    }
    if (opcion != 2 && opcion != 1) {
        cout << "ESCOJA UNA ACCION CORRECTA" << endl;
    }
}
void modificarCliente() {
    Cliente c = Cliente();
    char respuesta;
    string correo_electronico, nombres, apellidos, mf, nit;
    int telefono, idc, genero = -1;
    bool existe;
    cout << "INGRESE ID DEL REGISTRO A MODIFICAR ";
    cin >> idc;
    existe = c.existexid(idc);
    if (existe == true) {
        c.buscar(idc);
        cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
            cout << "INGRESE NIT ";
            cin.ignore();
            getline(cin, nit);
            cout << "INGRESE NOMBRES ";
            getline(cin, nombres);
            cout << "INGRESE APELLIDOS ";
            getline(cin, apellidos);
            cout << "INGRESE TELEFONO ";
            cin >> telefono;
            cout << "INGRESE SU GENERO [M/F] ";
            do {
                cin >> mf;
                if (mf == "M" || mf == "m") {
                    genero = 0;
                }
                else {
                    if (mf == "F" || mf == "f") {
                        genero = 1;
                    }
                    else {
                        cout << "PORFAVOR INGRESE UNA OPCION VALIDA " << endl;
                        cout << "INGRESE SU GENERO [M/F] ";
                    }
                }
            } while (genero != 0 && genero != 1);
            cout << "INGRESE SU CORREO ELECTRONICO ";
            cin.ignore();
            getline(cin, correo_electronico);
            c = Cliente(nombres, apellidos, genero, telefono, nit, "", correo_electronico);
            c.modificar(idc);
        }
        else {
            cout << "HA DETENIDO LA MODIFICACION DE FORMA EXISTOSA " << endl;
        }
    }
    else {
        cout << "ESTE ID NO ESTA EN LA BASE DE DATOS" << endl;
    }


}
void eliminarCliente() {
    Cliente c = Cliente();
    bool existe;
    int idc;
    char respuesta;
    cout << "SI YA SE HA GENERADO UNA VENTA CON ESTE CLIENTE NO PODRA SER ELIMINADA DEL REGISTRO" << endl;
    cout << "INGRESE EL ID DEL CLIENTE A ELIMINAR ";
    cin >> idc;
    existe = c.existexid(idc);
    if (existe == true) {
        c.buscar(idc);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            c.eliminar(idc);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}

bool existeSerie(char ide) {
    int q_estado;
    char coso;
    int f = 0;
    ConexionBD cn = ConexionBD();
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    string dato = "";
    dato += ide;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT serie FROM  ventas  where serie = '" + dato + "';";
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

    if (f >= 1) {
        return true;
    }
    else {
        return false;
    }
}

int n_venta(char serie) {
    if (existeSerie(serie) == true) {
        int q_estado;
        string dato = "";
        dato += serie;
        ConexionBD cn = ConexionBD();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string consulta = "select nofactura from ventas Where serie = '" + dato + "' order by nofactura desc  limit 1;";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                int numero = 0;
                while (fila = mysql_fetch_row(resultado)) {
                    numero = atoi((fila[0])) + 1;
                }
                return numero;
                system("pause");
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
    else
    {
        return 1;
    }

};
void mostrarProdutosVenta() {
    int q_estado;
    ConexionBD cn = ConexionBD();
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        string consulta = "SELECT idProducto,producto FROM productos;";
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            cout << "id | producto " << endl;
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << "\t" << fila[1] << endl;
            }
        }
        else {
            cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
        }

        cn.cerrar_conexion();
    }
}

void ingresarVenta() {
    char serie, respuesta;
    int no_factura, id_empleado;
    string  id_cliente;
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    Empleado e = Empleado();
    Cliente c = Cliente();
    Producto p = Producto();
    int id_venta, id_producto;
    string cantidad;
    float precio_unitario;
    bool existe;
    int opcion;
    float subtotal;
    float total = 0;


    cout << "GENERANDO UNA NUEVA FACTURA DE VENTA" << endl;
    cout << "INGRESE ID DEL EMPLEADO QUE ATIENDE ";
    cin >> id_empleado;
    existe = e.existeEmpleado(id_empleado);
    if (existe == true) {
        e.asignardatos(id_empleado);
        string ne = e.getNombres(); //revisar si estos datos no los muestra luego
        string ae = e.getApellidos();
        string nit;
        cout << "BIENVENIDO(A) DE NUEVO " << ne << "   " << ae << endl;
        cout << "DESEA AGREGAR NIT O GENERAR COMO CONSUMIDOR FINAL" << endl;
        cout << "[1] NIT" << endl;
        cout << "[2] CF" << endl;
        cin >> opcion;
        if (opcion == 1) {
            int i = 0;
            cout << "PORFAVOR INGRESE SU NIT ";
            cin >> nit;
            do {
                c.setNit(nit);
                existe = c.existexnit();
                if (existe == false) {
                    cout << "REDIRIGIENDO AL REGISTRO DE CLIENTES..." << endl;
                    ingresarCliente(nit);
                }
                if (existe == true) {
                    i = 1;
                }
            } while (i == 0);
            id_cliente = c.asignardatos();
            if (id_cliente == "ERROR") {
                cout << "NO SE ENCONTRO DICHO REGISTRO";
                id_cliente = "10";
            }
            else
            {
                c.buscarXnit();
            }

        }
        else {
            id_cliente = "10";
        }
        cout << "INGRESE SERIE ";
        cin >> serie;
        no_factura = n_venta(serie);
        v.setNoFactura(no_factura);
        v.setSerie(serie);
        system("cls");
        cout << "Factura: " << serie << no_factura << endl;
        string idventa;
        existe = v.existeVenta();
        if (existe == false) {
            v = Venta(no_factura, serie, "", id_cliente, id_empleado, "");
            v.ingresar();
            idventa = v.asignardatos();
            cout << "----------------------------------------------------" << endl;
            mostrarProdutosVenta();
            cout << "----------------------------------------------------" << endl;

            if (idventa != "ERROR") {
                do {
                    id_venta = stoi(idventa);
                    cout << "AÑADA ID DE UN PRODUCTO ";
                    cin >> id_producto;
                    cout << "AÑADA CANTIDAD: ";
                    cin >> cantidad;
                    int cant = stoi(cantidad);

                    string precioventa;
                    precioventa = p.returnPV(id_producto);
                    if (precioventa == "ERROR") {
                        cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                        cin >> precio_unitario;
                    }
                    else {
                        cout << "EL PRECIO ES " << precioventa << endl;
                        precio_unitario = stoi(precioventa);
                    }
                    vd = Venta_Detalle(id_venta, id_producto, cantidad, precio_unitario);
                    vd.ingresar();
                    subtotal = cant * precio_unitario;
                    total = total + subtotal;
                    cout << "DESEA AGREGAR OTRO PRODUCTO [S/N] ";
                    cin >> respuesta;
                } while (respuesta == 'S' || respuesta == 's');
                cout << "       EL TOTAL ES Q." << total << endl;
                cout << endl << "---------------------------------------" << endl;
                cout << "Presione una tecla para continuar";
                system("cls");
                Venta_Detalle vd = Venta_Detalle();
                int factura;
                char serie;
                string id_venta;
                bool existe;
                existe = v.existeVenta();
                if (existe == true) {
                    v.buscar();
                    id_venta = v.asignardatos();
                    if (id_venta != "ERROR") {
                        int idv = stoi(id_venta);
                        vd.setIdVenta(idv);
                        vd.buscar();
                    }
                    else {
                        cout << "ERROR AL GENERAR LA FACTURA" << endl;
                    }
                }
                else {
                    cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
                }
            }
            else
            {
                cout << "SE GENERO UN ERROR DE IMPREVISTO" << endl;
            }
        }
        else {
            cout << "ESTA FACTURA YA EXISTE" << endl;;
        }

    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}

void buscarVenta() {
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura;
    char serie;
    string id_venta;
    bool existe;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA BUSCAR " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA" << endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }

}
void mostrarVenta() {
    cout << "LISTADO DE VENTAS REALIZADAS " << endl;
    Venta v = Venta();
    v.mostrar();
}
void modificarVenta() {
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    Producto p = Producto();
    int  idvd, idproducto, factura;
    float precio;
    char serie, respuesta;
    string id_venta, cantidad, fechafactura;
    bool existe;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA LA BUSQUEDA " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            int i = 0;
            cout << "SEGURO QUIERES MODIFICAR ESTA FACTURA [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                do {
                    i = 0;
                    char r, ser;
                    int fact;
                    cout << "DESEA ALTERAR EL NO DE FACTURA [S/N]" << endl;
                    cin >> r;
                    if (r == 'S' || r == 's') {
                        cout << "INGRESE NO DE FACTURA ";
                        cin >> fact;
                        cout << "DESEA ALTERAR LA SERIE DE LA FACTURA [S/N]" << endl;
                        cin >> r;
                        if (r == 'S' || r == 's') {
                            cout << "INGRESE SERIE  " << endl;
                            cin >> ser;
                            v.setNoFactura(fact);
                            v.setSerie(ser);
                            existe = v.existeVenta();
                        }
                        else {
                            v.setNoFactura(fact);
                            v.setSerie(serie);
                            existe = v.existeVenta();
                        }

                        if (existe == true) {
                            i = 1;
                            cout << "YA EXISTE EN LA BASE DE DATOS" << endl;
                        }
                        else {
                            i = 0;
                            v.modificarSerie(id_venta);
                            v.modificarNoFactura(id_venta);
                        }
                    }
                    else {
                        cout << "DESEA ALTERAR LA SERIE [S/N] " << endl;
                        cin >> r;
                        if (r == 'S' || r == 's') {
                            cout << "INGRESE SERIE  " << endl;
                            cin >> ser;
                            v.setSerie(ser);
                            v.setNoFactura(factura);
                            existe = v.existeVenta();
                            if (existe == true) {
                                i = 1;
                                cout << "YA EXISTE EN LA BASE DE DATOS" << endl;
                            }
                            else {
                                i = 0;
                                v.modificarSerie(id_venta);
                            }
                        }

                    }
                } while (i == 1);

                cout << "DESEA ALTERAR LA FECHA DE LA FACTURA [S/N] ";
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    int res;
                    cout << "[1] DESEA INGRESAR MANUALMENTE" << endl;
                    cout << "[2] DESEA INGRESAR LA FECHA ACTUAL" << endl;
                    cin >> res;
                    if (res == 1) {
                        string ff;
                        cout << "INGRESE FECHA DE FACTURA [ANIO-MES-DIA] ";
                        cin >> ff;
                        fechafactura = "'" + ff + "'";
                    }
                    else {
                        fechafactura = "now()";

                    }
                    v.setFechaFactura(fechafactura);
                    v.modificarFechaFactura(id_venta);
                }
                cout << "DESEA MODIFICAR EL ID DEL CLIENTE [S/N]" << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    bool existecliente;
                    Cliente c = Cliente();
                    int idc;
                    do {
                        cout << "INGRESE ID DEL CLIENTE ";
                        cin >> idc;
                        existecliente = c.existexid(idc);
                        if (existecliente == true) {
                            string id_cliente;
                            id_cliente = to_string(idc);
                            v.setIdCliente(id_cliente);
                            v.modificarIdCliente(id_venta);
                        }
                    } while (existecliente == false);
                }
                cout << "DESEA MODIFICAR AL EMPLEADO [S/N] " << endl;
                cin >> respuesta;
                int ide;
                bool existeempleado;
                Empleado e = Empleado();
                if (respuesta == 'S' || respuesta == 's') {
                    do {
                        cout << "INGRESE EL ID DEL EMPLEADO ";
                        cin >> ide;
                        existeempleado = e.existeEmpleado(ide);
                        if (existeempleado == true) {
                            v.setIdEmpleado(ide);
                            v.modificarIdEmpleado(id_venta);
                        }
                    } while (existeempleado == false);
                }
                cout << "----------------------------------------" << endl << endl;
                cout << "DESEA AGREGAR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                cin >> respuesta;
                do {
                    int r;
                    cout << "[1] MODIFICAR UN PRODUCTO " << endl;
                    cout << "[2] INGRESAR OTRO PRODUCTO" << endl;
                    int res;
                    cin >> res;
                    bool existevd;
                    bool existeP;
                    if (res == 1) {
                        cout << "INGRESE ID DEL DETALLE A MODIFICAR ";
                        cin >> idvd;
                        existevd = vd.existeVD(idvd);
                        if (existevd == true) {
                            vd.buscarEspecifico(idvd);
                            cout << "INGRESE ID DEL PRODUCTO " << endl;
                            cin >> idproducto;
                            existeP = p.existeProducto(idproducto);
                            if (existeP == true) {
                                cout << "INGRESE CANTIDAD " << endl;
                                cin >> cantidad;
                                string precioventa;
                                precioventa = p.returnPV(idproducto);
                                if (precioventa == "ERROR") {
                                    cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                    cin >> precio;
                                }
                                else {
                                    cout << "EL PRECIO UNITARIO ES " << precioventa << endl;
                                    precio = stoi(precioventa);
                                }
                                vd.setIdProducto(idproducto);
                                vd.setCantidad(cantidad);
                                vd.setPrecioUnitario(precio);
                                vd.modificar(idvd);
                            }
                            else {
                                cout << "ID DEL PRODUCTO NO VALIDO" << endl;
                            }
                        }
                        else {
                            cout << "ESTE ID POR VENTA DETALLE NO EXISTE " << endl;
                        }
                    }
                    if (res == 2) {
                        cout << "INGRESE ID DEL PRODUCTO " << endl;
                        cin >> idproducto;
                        existeP = p.existeProducto(idproducto);
                        if (existeP == true) {
                            cout << "INGRESE CANTIDAD " << endl;
                            cin >> cantidad;
                            string precioventa;
                            precioventa = p.returnPV(idproducto);
                            if (precioventa == "ERROR") {
                                cout << "ERROR AL HALLAR EL PRECIO DEL PRODUCTO INGRESELO MANUALMENTE ";
                                cin >> precio;
                            }
                            else {
                                cout << "EL PRECIO UNITARIO ES " << precioventa << endl;
                                precio = stoi(precioventa);
                            }
                            int idv = stoi(id_venta);
                            vd.setIdVenta(idv);
                            vd.setIdProducto(idproducto);
                            vd.setCantidad(cantidad);
                            vd.setPrecioUnitario(precio);
                            vd.ingresar();
                        }
                        else {
                            cout << "ESTE PRODUCTO NO EXISTE EN LA BASE DE DATOS " << endl;
                        }

                    }
                    system("pause");
                    system("cls");
                    v.buscar();
                    id_venta = v.asignardatos();
                    if (id_venta != "ERROR") {
                        int idv = stoi(id_venta);
                        vd.setIdVenta(idv);
                        vd.buscar();
                    }
                    else {
                        cout << "ERROR AL GENERAR LA FACTURA" << endl;
                    }
                    cout << "DESEA AÑADIR PRODUCTOS O MODIFICAR LOS YA REGISTRADOS EN LA VENTA [S/N] ";
                    cin >> respuesta;
                } while (respuesta == 'S' || respuesta == 's');
            }
            else {
                cout << "MODIFICACION DETENIDA" << endl;
            }
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA" << endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }
}
void eliminarVenta() {
    Venta v = Venta();
    Venta_Detalle vd = Venta_Detalle();
    int factura, opcion, idvd;
    char serie, respuesta;
    string id_venta;
    bool existe, existevd;
    cout << "INGRESE LA SIGUIENTE INFORMACION PARA BUSCAR Y BORRAR " << endl;
    cout << "INGRESE EL NUMERO DE FACTURA ";
    cin >> factura;
    cout << "INGRESE LA SERIE ";
    cin >> serie;
    v.setNoFactura(factura);
    v.setSerie(serie);
    existe = v.existeVenta();
    if (existe == true) {
        v.buscar();
        id_venta = v.asignardatos();
        if (id_venta != "ERROR") {
            int idv = stoi(id_venta);
            vd.setIdVenta(idv);
            vd.buscar();
            cout << "[1] BORRAR FACTURA POR COMPLETO " << endl;
            cout << "[2] BORRAR PRODUCTOS DE LA FACTURA" << endl;
            cin >> opcion;
            cout << "SEGURO DE ELIMINAR MEDIANTE ESTA OPCION [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                if (opcion == 1) {
                    int ivd = stoi(id_venta);
                    vd.eliminar(idv);
                    v.eliminar(id_venta);
                }
                if (opcion == 2) {
                    cout << "INGRESE ID DEL DETALLE A ELIMINAR ";
                    cin >> idvd;
                    existevd = vd.existeVD(idvd);
                    if (existevd == true) {
                        vd.buscarEspecifico(idvd);
                        cout << "SEGURO DE ELIMINAR ESTE DATO [S/N] ";
                        cin >> respuesta;
                        if (respuesta == 'S' || respuesta == 's') {
                            vd.eliminarEspecifico(idvd);
                        }
                        else {
                            cout << "SE HA DETENDIO LA ELIMINACION " << endl;
                        }
                    }
                    else {
                        cout << "NO SE ENCONTRO DICHO REGISTRO " << endl;
                    }
                }
            }
        }
        else {
            cout << "ERROR AL GENERAR LA FACTURA" << endl;
        }
    }
    else {
        cout << "ESTA FACTURA NO ESTA EN LA BASE DE DATOS" << endl;
    }
}

void ingresarMarca() {
    string marca;
    cout << "INGRESE NOMBRE DE LA MARCA ";
    cin.ignore();
    getline(cin, marca);
    Marca m = Marca(marca);
    m.ingresar();
}
void buscarMarca() {
    int idm;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA A BUSCAR ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
    }
    else {
        cout << "NO SE ENCONTRO EL ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarMarca() {
    int idm;
    string marca;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] " << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            cout << "INGRESE EL NUEVO NOMBRE DE LA MARCA " << endl;
            cin.ignore();
            getline(cin, marca);
            m = Marca(marca);
            m.modificar(idm);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
    }
    else {
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS" << endl;
    }
}
void eliminarMarca() {
    int idm;
    string marca;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DE LA MARCA ";
    cin >> idm;
    Marca m = Marca();
    existe = m.existemarca(idm);
    if (existe == true) {
        m.buscar(idm);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR UNA MARCA SI HAY PRODUCTOS ASIGNADOS A ESTE" << endl;
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            m.eliminar(idm);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}

void ingresarProducto() {
    Producto p = Producto();
    Marca m = Marca();
    string producto, descripcion, imagen;
    int id_marca, existencia;
    float p_c, p_v;
    int idm;
    bool existe;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    cout << "INGRESE  PRODUCTO :" << endl;
    cin.ignore();
    getline(cin, producto);
    cout << "ASIGNE LA MARCA POR MEDIO DEL ID " << endl;
    do {
        m.mostrar();
        cout << endl << "ASIGNE UN VALOR VALIDO ---> ";
        cin >> id_marca;
        existe = m.existemarca(id_marca);
    } while (existe == false);

    cout << "INGRESE LA DESCRIPCION: " << endl;
    cin.ignore();
    getline(cin, descripcion);
    cout << "INGRESE LA IMAGEN (ejemplo.png): " << endl;
    getline(cin, imagen);
    cout << "INGRESE EL PRECIO COSTO: " << endl;
    cin >> p_c;
    cout << "INGRESE SU PRECIO VENTA: " << endl;
    cin >> p_v;
    cout << "INGRESE LAS EXISTENCIAS: " << endl;
    cin >> existencia;
    p = Producto(producto, id_marca, descripcion, imagen, p_c, p_v, existencia, "");
    p.ingresar();
}
void buscarProducto() {
    Producto p = Producto();
    bool existe;
    int idp;
    cout << "INGRESE EL ID DEL PRODUCTO A BUSCAR ";
    cin >> idp;
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void modificarProducto() {
    Producto p = Producto();
    bool existe;
    int idp;
    cout << "INGRESE EL ID DEL PRODUCTO A MODIFICAR ";
    cin >> idp;
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
        char respuesta;
        cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            cout << "DESEA MODIFICAR EL NOMBRE DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string producto;
                cout << "INGRESE NUEVO PRODUCTO ";
                cin >> producto;
                p.setProducto(producto);
                p.modificarProducto(idp);
            }

            cout << "DESEA MODIFICAR EL EL ID DE LA MARCA [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                int idMarca;
                Marca m = Marca();
                bool exM;
                do {
                    cout << "INGRESE NUEVO ID DE MARCA EXISTENTE ";
                    cin >> idMarca;
                    exM = m.existemarca(idMarca);
                    if (exM == true) {
                        p.setIdMarca(idMarca);
                        p.modificarIdMarca(idp);
                    }
                    else {
                        cout << "NO SE ENCONTRO DICHO ID VUELVA A PROBAR";
                        cout << "DESEA VER LAS MARCAS DISPONIBLES [S/N] ";
                        cin >> respuesta;
                        if (respuesta == 'S' || respuesta == 's') {
                            m.mostrar();
                        }
                    }
                } while (exM == false);
            }
            cout << "DESEA MODIFICAR LA DESCRIPCION DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string descripcion;
                cout << "INGRESE NUEVA DESCRIPCION ";
                cin >> descripcion;
                p.setDescripcion(descripcion);
                p.modificarDescripcion(idp);
            }
            cout << "DESEA MODIFICAR IMAGEN DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                string imagen;
                cout << "INGRESE NUEVA IMAGEN ";
                cin >> imagen;
                p.setImagen(imagen);
                p.modificarImagen(idp);
            }
            cout << "DESEA MODIFICAR EL PRECIO DE COSTO DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                float preciocosto;
                cout << "INGRESE NUEVO PRECIO DE COSTO ";
                cin >> preciocosto;
                p.setPrecioCosto(preciocosto);
                p.modificarPrecioCosto(idp);
            }
            cout << "DESEA MODIFICAR EL PRECIO DE VENTA DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                float precioventa;
                cout << "INGRESE NUEVO PRECIO DE VENTA ";
                cin >> precioventa;
                p.setPrecioVenta(precioventa);
                p.modificarPrecioVenta(idp);
            }
            cout << "DESEA MODIFICAR LAS EXISTENCIAS DEL PRODUCTO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                int existencia;
                cout << "INGRESE NUEVO VALOR DE EXISTENCIAS ";
                cin >> existencia;
                p.setExistencia(existencia);
                p.modificarExistencia(idp);
            }

        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
void eliminarProducto() {
    Producto p = Producto();
    bool existe;
    int idp;
    char respuesta;
    cout << "INGRESE EL ID DEL PRODUCTO A ELIMINAR ";
    cin >> idp;
    existe = p.existeProducto(idp);
    if (existe == true) {
        p.buscar(idp);
        cout << "SEGURO QUE QUIERES ELIMINAR ESTE REGISTRO [S/N] ";
        cin >> respuesta;
        if (respuesta == 'S' || respuesta == 's') {
            p.eliminar(idp);
        }
        else {
            cout << "SE HA DETENIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO EXISTE ESTE ID EN LA BASE DE DATOS" << endl;
    }
}
int n_compra() {
    string consulta = "select no_orden_compra from compras order by no_orden_compra desc limit 1;";
    int q_estado;
    string dato = "";
    ConexionBD cn = ConexionBD();
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    cn.abrir_conexion();
    if (cn.getConectar()) {
        const char* c = consulta.c_str();
        q_estado = mysql_query(cn.getConectar(), c);
        if (!q_estado) {
            resultado = mysql_store_result(cn.getConectar());
            int numero = 0;
            while (fila = mysql_fetch_row(resultado)) {
                numero = atoi((fila[0])) + 1;
            }

            return numero;
            system("pause");

        }
        else {
            cout << "ERROR AL BUSCAR LA INFORMACION";
        }
    }
    else {
        cout << "ERROR AL CONECTAR CON LA BASE DE DATOS";
    }
    cn.cerrar_conexion();
    return 1;
};

void ingresarCompra() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    Proveedor p = Proveedor();
    Producto pr = Producto();
    string  f_o;
    int idcd, id_c, idproducto, idproveedor, idcompra, no_or_c, cant;
    float precio_costo;
    bool existe;
    cout << "INGRESE LOS DATOS QUE SE LE SOLICITA " << endl;
    no_or_c = n_compra();
    cout << "NUMERO DE COMPRA #" << no_or_c << endl;
    cin.ignore();

    cout << "INGRESE EL ID DEL PROVEEDOR DE LOS PROVEEDORES SIGUIENTES" << endl;
    p.mostrar();
    cin >> idproveedor;
    cout << "INGRESE LA FECHA DE ORDEN" << endl;
    cin.ignore();
    getline(cin, f_o);
    cout << "INGRESE EL ID DE COMPRA" << endl;
    cin >> idcompra;
    cout << "INGRESE EL ID PRODUCTO DE LOS PRODUCTOS SIGUIENTES: " << endl;
    pr.mostrar();
    cin.ignore();
    cin >> idproducto;
    cout << "INGRESE LA CANTIDAD DE COMPRAS" << endl;
    cin.ignore();
    cin >> cant;
    cout << "INGRESE EL PRECIO COSTO UNITARIO: " << endl;
    cin.ignore();
    cin >> precio_costo;
    Compra compra = Compra(no_or_c, idproveedor, f_o, "");
    compra.ingresar();
    Compra_Detalle compra_detalle = Compra_Detalle(idcompra, idproducto, cant, precio_costo);
    compra_detalle.ingresar();

}

void MostrarCompras() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    c.mostrar();
    cout << "---------------" << endl;
    cd.mostrar();

}

void BuscarCompras() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    bool existe;
    int idcompra, idcd, opcion;
    cout << "INGRESE QUE DESEA BUSCAR EN COMPRAS: " << endl;
    cout << "[1] COMPRA" << endl;
    cout << "[2] DETALLE DE LA COMPRA" << endl;
    cin >> opcion;
    if (opcion == 1)
    {
        cout << "INGRESE ID DE LA COMPRA" << endl;
        cin >> idcompra;
        existe = c.ExisteCompra(idcompra);
        if (existe == true) {
            c.buscar(idcompra);
        }

    }
    if (opcion == 2) {
        cout << "INGRESE EL ID DE LA COMPRA DETALLE " << endl;
        cin >> idcd;
        existe = cd.ExisteComp_det(idcd);
        if (existe == true) {
            cd.buscar(idcd);
        }
    }
    if (opcion != 2 && opcion != 1) {
        cout << "ESCOJA UNA ACCION CORRECTA" << endl;
    }
}
void ModificarCompras() {
    Compra c = Compra();
    Compra_Detalle cd = Compra_Detalle();
    Proveedor p = Proveedor();
    Producto pr = Producto();
    string  f_o;
    char respuesta;
    int idcd, id_c, idproducto, idproveedor, idcompra, no_or_c, cant, opcion;
    float precio_costo;
    bool existe;
    cout << "INGRESE QUE OPCION DESEA: " << endl;
    cout << "[1] MODIFICAR LAS COMPRAS" << endl;
    cout << "[2] MODIFICAR EL DETALLE DE LA COMPRA" << endl;
    cin >> opcion;
    if (opcion == 1) {
        cout << "INGRESE EL ID DE LA COMPRA A MODIFICAR: " << endl;
        cin >> id_c;
        existe = c.ExisteCompra(id_c);
        if (existe == true) {
            c.buscar(id_c);
            cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                cout << "DESEA MODIFICAR EL NO DE ORDEN DE COMPRA [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE EL NUEVO NO DE ORDEN: " << endl;
                    cin.ignore();
                    cin >> no_or_c;
                }
                cout << "DESEA MODIFICAR EL ID DEL PROVEEDOR [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE EL NUEVO ID DEL PROVEEDOR: " << endl;
                    p.mostrar();
                    cin >> idproveedor;
                    cin.ignore();


                }
                cout << "DESEA MODIFICAR LA FECHA ORDEN [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE LA FECHA DE INGRESO: " << endl;
                    cin.ignore();
                    cin >> f_o;
                }
                Compra c = Compra(no_or_c, idproveedor, f_o, "");
                c.modificar(id_c);
            }

        }
    }

    if (opcion == 2) {
        cout << "INGRESE EL ID DE LA COMPRA DETALLE A MODIFICAR: " << endl;
        cin >> idcd;
        existe = cd.ExisteComp_det(idcd);
        if (existe == true) {
            cd.buscar(idcd);
            cout << "SEGURO QUE QUIERES MODIFICAR ESTE REGISTRO [S/N] ";
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                cout << "DESEA MODIFICAR EL ID COMPRA [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE EL NUEVO ID DE COMPRA: " << endl;
                    cin.ignore();
                    cin >> idcompra;
                }
                cout << "DESEA MODIFICAR EL ID DEL PRODUCTO [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE EL NUEVO ID DEL PRODUCTO DE LOS SIGUIENTES: " << endl;
                    pr.mostrar();
                    cin >> idproducto;
                    cin.ignore();
                }
                cout << "DESEA MODIFICAR LA CANTIDAD [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE LA NUEVA CANTIDAD: " << endl;
                    cin.ignore();
                    cin >> cant;
                }
                cout << "DESEA MODIFICAR EL PRECIO UNITARIO [S/N] " << endl;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "INGRESE EL PRECIO UNITARIO: " << endl;
                    cin.ignore();
                    cin >> precio_costo;
                }
                Compra_Detalle cd = Compra_Detalle(idcompra, idproducto, cant, precio_costo);
                cd.modificar(idcd);
            }

        }
    }
}
void eliminarCompras() {
    int idcompra, idcompra_d, opcion;
    char respuesta;
    string id_venta;
    bool existe, existecd;
    cout << "INGRESE QUE OPCION DESEA: " << endl;
    cout << "[1] BORRAR COMPRAS" << endl;
    cout << "[2] BORRAR DETALLE DE LA COMPRA" << endl;
    cin >> opcion;

    if (opcion == 1) {
        cout << "INGRESE EL ID DE LA COMPRA" << endl;
        cin >> idcompra;
        Compra c = Compra();
        existe = c.ExisteCompra(idcompra);
        if (existe == true) {
            c.buscar(idcompra);
            cout << "RECUERDE QUE NO PUEDE ELIMINAR UNA COMPRA SI YA SE HA ASIGNADO" << endl;
            cout << "SEGURO DE ELIMINAR LA COMPRA [S/N] " << endl;
            cin >> respuesta;
            if (respuesta == 'S' || respuesta == 's') {
                c.eliminar(idcompra);
            }
            else {
                cout << "SE INTERRUMPIO LA ELIMINACION" << endl;
            }
        }

    }

    if (opcion == 2) {
        cout << "INGRESE EL ID DE LA COMPRA DETALLE" << endl;
        cin >> idcompra_d;
        Compra_Detalle  cd = Compra_Detalle();
        existecd = cd.ExisteComp_det(idcompra_d);
        if (existecd == true) {
            cd.buscar(idcompra_d);
            cout << "SEGURO DE ELIMINAR LA COMPRA [S/N] " << endl;
            cin >> respuesta;
            if ((respuesta == 'S' || respuesta == 's')) {
                cd.eliminar(idcompra_d);
            }
            else {
                cout << "SE INTERRUMPIO LA ELIMINACION" << endl;
            }
        }
        else {
            cout << "ERROR AL INGRESAR LA BASE DE DATOS" << endl;
        }

    }

}

void IngresarProveedor() {
    Proveedor p = Proveedor();
    string prov, nit, dir;
    int idproveedor, tel;
    cout << "INGRESE NOMBRE DEL PROVEEDOR: " << endl;
    cin.ignore();
    getline(cin, prov);
    cout << "INGRESE EL NIT DEL PROVEEDOR: " << endl;
    cin.ignore();
    getline(cin, nit);
    cout << "INGRESE LA DIRECCION DEL PROVEEDOR : " << endl;
    cin.ignore();
    getline(cin, dir);
    cout << "INGRESE EL TELEFONO DEL PROVEEDOR: " << endl;
    cin.ignore();
    cin >> tel;
    p = Proveedor(prov, nit, dir, tel);
    p.ingresar();
}

void MostrarProveedor() {
    Proveedor p = Proveedor();
    cout << "PROVEEDORES EXISTENTES: " << endl;
    p.mostrar();
}

void BuscarProveedor() {
    Proveedor p = Proveedor();
    int idproveedor;
    bool existe;
    cout << "INGRESE EL PROVEEDOR A BUSCAR: " << endl;
    cin >> idproveedor;
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        p.buscar(idproveedor);
    }
}

void ModificarProveedor() {
    Proveedor p = Proveedor();
    string prov, nit, dir;
    int idproveedor, tel;
    bool existe;
    char respuesta;
    cout << "INGRESE EL ID DEL PROVEEDOR A MODIFICAR: " << endl;
    cin >> idproveedor;
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        p.buscar(idproveedor);
        cout << "SEGURO QUE QUIERE MODIFICAR ESTE REGISTRO [S/N] " << endl;
        cin >> respuesta;
        cin.ignore();
        if ((respuesta == 's') || (respuesta == 'S')) {
            cout << "INGRESE EL NUEVO NOMBRE DEL PROVEEDOR " << endl;
            getline(cin, prov);
            cin.ignore();
            cout << "INGRESE EL NUEVO NIT DEL PROVEEDOR " << endl;

            getline(cin, nit);
            cin.ignore();
            cout << "INGRESE LA NUEVA DIRECCION DEL PROVEEDOR " << endl;

            getline(cin, dir);
            cin.ignore();
            cout << "INGRESE EL NUEVO TELEFONO DEL PROVEEDOR " << endl;
            cin >> tel;
            cin.ignore();
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA MODIFICACION" << endl;
        }
        Proveedor p = Proveedor(prov, nit, dir, tel);
        p.modificar(idproveedor);
    }
    else {
        cout << "EL ID QUE INGRESO NO ESTA REGISTRADO EN LA BASE DE DATOS" << endl;
    }

}
void EliminarProveedor() {
    Proveedor p = Proveedor();
    int idproveedor;
    char respuesta;
    bool existe;
    cout << "INGRESE EL ID DEL PROVEEDOR A ELIMINAR" << endl;
    cin >> idproveedor;
    existe = p.existeproveedor(idproveedor);
    if (existe == true) {
        p.buscar(idproveedor);
        cout << "RECUERDE QUE NO PUEDE ELIMINAR PROVEEDORES SI SE HAN ASIGNADO A OTRAS TABLAS" << endl;
        cout << "SEGURO QUE QUIERE ELIMINAR ESTE REGISTRO [S/N]" << endl;
        cin >> respuesta;
        if ((respuesta == 's') || (respuesta == 'S')) {
            p.eliminar(idproveedor);
        }
        else
        {
            cout << "SE HA INTERRUMPIDO LA ELIMINACION" << endl;
        }
    }
    else {
        cout << "NO SE HA ENCONTRADO EL ID EN LA BASE DE DATOS" << endl;
    }
}