#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>  // Para _getch()
#include <windows.h>  // Para SetConsoleCursorPosition()

using namespace std;

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Estructura que define un vehículo
struct Vehiculo {
    int numFactura;
    string placa;
    string marca;
    string modelo;
    int tipoVehiculo;
    int tipoLavado;
    int precio;
};

// Función para calcular el precio según el tipo de vehículo y lavado
int calcularPrecio(int tipoVehiculo, int tipoLavado) {
    if (tipoVehiculo == 1) {
        return tipoLavado == 1 ? 3000 : 5000;
    } else if (tipoVehiculo == 2) {
        return tipoLavado == 1 ? 5000 : 7000;
    } else {
        return tipoLavado == 1 ? 7000 : 12000;
    }
}

// Función para mostrar el menú principal

void mostrarMenu() {
    system("cls"); // Limpiar la pantalla
    cout << "Menu Principal\n";
    cout << "1- Ingresar Datos Vehiculos\n";
    cout << "2- Ver Estadisticas Vehiculos Lavados segun tipo de Vehiculo\n";
    cout << "3- Ver Estadisticas Vehiculos Lavados segun tipo de Lavado\n";
    cout << "4- Ver Grafico Vehiculos Lavados por Tipo de Vehiculo\n";
    cout << "5- Ver Grafico Vehiculos Lavados por Tipo de Lavado\n";
    cout << "6- Salir\n";
    cout << "Seleccione una opcion: ";
}

// Función para ingresar datos de vehículos

void ingresarDatosVehiculos(vector<Vehiculo>& vehiculos) {
    char continuar;
    int numFactura = vehiculos.size() + 1;
    do {
        system("cls");
        Vehiculo v;
        v.numFactura = numFactura++;
        // Pedir datos al usuario
        cout << "Ingrese el numero de placa: ";
        cin >> v.placa;
        cout << "Ingrese la marca del vehiculo: ";
        cin >> v.marca;
        cout << "Ingrese el modelo del vehiculo: ";
        cin >> v.modelo;
        // Validar y pedir tipo de vehículo
        do {
            cout << "Ingrese el tipo de vehiculo (1=Sencillo, 2=4x4, 3=Microbus o Camion): ";
            cin >> v.tipoVehiculo;
        } while (v.tipoVehiculo < 1 || v.tipoVehiculo > 3);
        // Validar y pedir tipo de lavado
        do {
            cout << "Ingrese el tipo de lavado (1=Solo Lavado, 2=Lavado, Aspirado y Encerado): ";
            cin >> v.tipoLavado;
        } while (v.tipoLavado < 1 || v.tipoLavado > 2);
        // Calcular precio según tipo de vehículo y lavado
        v.precio = calcularPrecio(v.tipoVehiculo, v.tipoLavado);
        // Mostrar datos ingresados y precio a pagar
        system("cls");
        cout << "Numero de factura: " << v.numFactura << endl;
        cout << "Numero de placa: " << v.placa << endl;
        cout << "Marca: " << v.marca << endl;
        cout << "Modelo: " << v.modelo << endl;
        cout << "Tipo de vehiculo: " << v.tipoVehiculo << endl;
        cout << "Tipo de lavado: " << v.tipoLavado << endl;
        cout << "Precio a pagar: " << v.precio << " colones" << endl;
        // Agregar vehículo al vector de vehículos
        vehiculos.push_back(v);
        // Preguntar si desea ingresar otro vehículo
        cout << "Desea ingresar otro vehiculo? (S/N): ";
        cin >> continuar;
        
    } while (continuar == 'S' || continuar == 's');
}
// Función para ver estadísticas por tipo de vehículo

void verEstadisticasVehiculos(vector<Vehiculo>& vehiculos) {
    system("cls");
    int cantSencillos = 0, cant4x4 = 0, cantMicrobus = 0;
    int dineroSencillos = 0, dinero4x4 = 0, dineroMicrobus = 0;
     // Calcular cantidad y dinero recaudado por tipo de vehículo
   
    for (size_t i = 0; i < vehiculos.size(); ++i) {
        if (vehiculos[i].tipoVehiculo == 1) {
            cantSencillos++;
            dineroSencillos += vehiculos[i].precio;
        } else if (vehiculos[i].tipoVehiculo == 2) {
            cant4x4++;
            dinero4x4 += vehiculos[i].precio;
        } else {
            cantMicrobus++;
            dineroMicrobus += vehiculos[i].precio;
        }
    }
     // Mostrar estadísticas
   
    cout << "Cantidad de Vehiculos Tipo Sencillos: " << cantSencillos << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo Sencillos: " << dineroSencillos << endl;
    cout << "Cantidad de Vehiculos Tipo 4x4: " << cant4x4 << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo 4x4: " << dinero4x4 << endl;
    cout << "Cantidad de Vehiculos Tipo Microbus o Camion: " << cantMicrobus << endl;
    cout << "Dinero Recaudado por Vehiculos Tipo Microbus o Camion: " << dineroMicrobus << endl;
    cout << "<Pulse tecla para volver al menu>" << endl;
    _getch(); // Esperar a que el usuario presione una tecla para continuar
}
// Función para ver estadísticas por tipo de lavado

void verEstadisticasLavados(vector<Vehiculo>& vehiculos) {
    system("cls");
    int cantSoloLavado = 0, cantCompleto = 0;
    int dineroSoloLavado = 0, dineroCompleto = 0;
    // Calcular cantidad y dinero recaudado por tipo de lavado
    for (size_t i = 0; i < vehiculos.size(); ++i) {
        if (vehiculos[i].tipoLavado == 1) {
            cantSoloLavado++;
            dineroSoloLavado += vehiculos[i].precio;
        } else {
            cantCompleto++;
            dineroCompleto += vehiculos[i].precio;
        }
    }
    // Mostrar estadísticas
    cout << "Cantidad de Vehiculos con solo Lavado: " << cantSoloLavado << endl;
    cout << "Dinero Recaudado por Vehiculos con solo Lavado: " << dineroSoloLavado << endl;
    cout << "Promedio Dinero Recaudado por Vehiculos con solo Lavado: " 
         << (cantSoloLavado ? dineroSoloLavado / cantSoloLavado : 0) << endl;
    cout << "Cantidad de Vehiculos con Lavado, Aspirado y Encerado: " << cantCompleto << endl;
    cout << "Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " << dineroCompleto << endl;
    cout << "Promedio Dinero Recaudado por Vehiculos con Lavado, Aspirado y Encerado: " 
         << (cantCompleto ? dineroCompleto / cantCompleto : 0) << endl;
    cout << "<Pulse tecla para volver al menu>" << endl;
    _getch(); // Esperar a que el usuario presione una tecla para continuar
}
// Función para mostrar gráfico de vehículos por tipo

void verGraficoVehiculos(vector<Vehiculo>& vehiculos) {
    system("cls");
    int cantSencillos = 0, cant4x4 = 0, cantMicrobus = 0;
    // Contar vehículos por tipo
    for (size_t i = 0; i < vehiculos.size(); ++i) {
        if (vehiculos[i].tipoVehiculo == 1) {
            cantSencillos++;
        } else if (vehiculos[i].tipoVehiculo == 2) {
            cant4x4++;
        } else {
            cantMicrobus++;
        }
    }
    // Mostrar gráfico de barras
    cout << "*******Grafico Vehiculos por Tipo*******" << endl;
    cout << "Sencillos       ";
    for (int i = 0; i < cantSencillos; ++i) {
        cout << char(219); // Carácter especial para las barras (ASCII extendido)
    }
    cout << endl;

    cout << "4x4             ";
    for (int i = 0; i < cant4x4; ++i) {
        cout << char(219); // Carácter especial para las barras (ASCII extendido)
    }
    cout << endl;

    cout << "Microbus/Camion ";
    for (int i = 0; i < cantMicrobus; ++i) {
        cout << char(219); // Carácter especial para las barras (ASCII extendido)
    }
    cout << endl;

    cout << "<Pulse cualquier tecla para salir>" << endl;
    _getch(); // Esperar a que el usuario presione una tecla para continuar
}

void verGraficoLavados(vector<Vehiculo>& vehiculos) {
    system("cls");
    int cantSoloLavado = 0, cantCompleto = 0;
    // Contar vehículos por tipo de lavado
    for (size_t i = 0; i < vehiculos.size(); ++i) {
        if (vehiculos[i].tipoLavado == 1) {
            cantSoloLavado++;
        } else {
            cantCompleto++;
        }
    }
    
    cout << "*******Grafico Ventas Entradas por Sala*******" << endl;
    cout << "Sencillo        " << string(cantSoloLavado, char(219)) << " " << cantSoloLavado << endl;
    cout << "Lavado, Aspirado y Encerado " << string(cantCompleto, char(219)) << " " << cantCompleto << endl;

    cout << "<Pulse tecla para volver al menu>" << endl;
    _getch();
}

int main() {
    vector<Vehiculo> vehiculos;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ingresarDatosVehiculos(vehiculos);
                break;
            case 2:
                verEstadisticasVehiculos(vehiculos);
                break;
            case 3:
                verEstadisticasLavados(vehiculos);
                break;
            case 4:
                verGraficoVehiculos(vehiculos);
                break;
            case 5:
                verGraficoLavados(vehiculos);
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);
    
    return 0;
}

