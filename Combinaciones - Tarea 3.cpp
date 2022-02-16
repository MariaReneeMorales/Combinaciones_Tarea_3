#include <stdio.h> 
#include <iostream> 
#include <math.h> 
#include <string.h> 
using namespace std; 

//Nota: En mi c�digo he utilizado la Notaci�n H�ngara + Camel Case.

int main() {
	//Permite imprimir tildes, � o caracteres especiales. 
	setlocale(LC_ALL, "");
	
	//Definici�n de variables.
	string lcOpcion;
	float lnNumero1, lnNumero2, lnResultado, lnSaldo, lnValor, lnSaldoInicial, lnIngresos, lnEgresos;
	int lnCanIng, lnCanEgr;
	
	//Inicializando valores.
	lnCanIng = 0;
	lnCanEgr = 0;
	lnIngresos = 0;
	lnEgresos = 0;
	lnSaldoInicial = 5000;
	lnSaldo = lnSaldoInicial;
	lnValor = 0;
	
	//Inicio del ciclo do-while (se repite hasta que el usuario presion� "S" para salir).
	do{
		//Mostrando en pantalla el saldo actual + captura y lectura (opci�n a realizar).
		cout << " �Qu� desea hacer?" << endl << endl; 
		cout << " S = Sumar, R = Restar, M = Multiplicar, D = Dividir, F = Facturar, P = Pagar, Z = Salir" << endl << endl;
		cout << " Escoga una opci�n: ";
		cin >> lcOpcion;
		
		if (lcOpcion == "S"){
			cout << " Ingrese el primer n�mero: ";
			cin >> lnNumero1;
			cout << " Ingrese el segundo n�mero: ";
			cin >> lnNumero2;
			
			lnResultado = (lnNumero1 + lnNumero2);
			
			cout << " El resultado de " << lnNumero1 << " + " << lnNumero2 << " = " << lnResultado << endl << endl;
		}
		else if (lcOpcion == "R"){
			cout << " Ingrese el primer n�mero: ";
			cin >> lnNumero1;
			cout << " Ingrese el segundo n�mero: ";
			cin >> lnNumero2;
			
			lnResultado = (lnNumero1 - lnNumero2);
			
			cout << " El resultado de " << lnNumero1 << " - " << lnNumero2 << " = " << lnResultado << endl << endl;
		}
		else if (lcOpcion == "M"){
			cout << " Ingrese el primer n�mero: ";
			cin >> lnNumero1;
			cout << " Ingrese el segundo n�mero: ";
			cin >> lnNumero2;
			
			lnResultado = (lnNumero1 * lnNumero2);
			
			cout << " El resultado de " << lnNumero1 << " * " << lnNumero2 << " = " << lnResultado << endl << endl;
		}	
		else if (lcOpcion == "D"){
			cout << " Ingrese el primer n�mero: ";
			cin >> lnNumero1;
			cout << " Ingrese el segundo n�mero: ";
			cin >> lnNumero2;
			
			lnResultado = (lnNumero1 / lnNumero2);
			
			if (lnNumero2 == 0){
				cout << " El resultado de " << lnNumero1 << " / " << lnNumero2 << " = Math Error..." << endl << endl;
			}
			else{
				cout << " El resultado de " << lnNumero1 << " / " << lnNumero2 << " = " << lnResultado << endl << endl;
			}
		}
		else if (lcOpcion == "F"){
			//Captura y lectura de datos (valor dado).
			cout << " Nota: Su saldo actual es de: USD " << lnSaldo << endl << endl;
			cout << " Ingrese la cantidad: USD "; 
			cin >> lnValor;
					
			//Suma (nuevos ingresos).
			lnSaldo = lnSaldo + lnValor;
					
			//Conteo n de facturas + n ingresos.
			lnCanIng = lnCanIng + 1;
			lnIngresos = lnIngresos + lnValor;
		}
		else if (lcOpcion == "P"){
			//Captura y lectura de datos (valor dado).
			cout << " Nota: Su saldo actual es de: USD " << lnSaldo << endl << endl;
			cout << " Ingrese la cantidad: USD "; 
			cin >> lnValor;
					
			//Condici�n (evitando que se proceda si el monto es < saldo actual).
			if (lnValor > lnSaldo){
				cout << " Su saldo es insuficiente";
				cout << endl;
			}
			else {
				//Resta (pagos trabajadores).
				lnSaldo = lnSaldo - lnValor;
						
				//Conteo n de pagos + n egresos.
				lnCanEgr = lnCanEgr + 1;
				lnEgresos = lnEgresos + lnValor;
			}
		}
		cout << "----------------------------------------------------------------------------------------------------------" << endl;
	} while (lcOpcion == "S" || lcOpcion == "R" || lcOpcion == "M" || lcOpcion == "D" || lcOpcion == "F" || lcOpcion == "P");
 
	//T�tulo. 
	cout << endl << endl;
	cout << "===================" << endl;
	cout << " �Resumen del D�a!" << endl;
	cout << "===================" << endl << endl; 
		
	//Impresi�n de datos.
	cout << " Saldo inicial: USD " << lnSaldoInicial << endl;
	cout << " (+) " << lnCanIng << " Facturas por USD " << lnIngresos << endl;
	cout << " (-) " << lnCanEgr << " Pagos por USD " << lnEgresos << endl;
	cout << " Saldo final: USD " << lnSaldo;
	
	return 0;
}
