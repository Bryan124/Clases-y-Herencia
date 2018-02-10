#include <iostream>
#include <string>
using namespace std;

class Cuenta {
private:
	int saldo;

public:
	Cuenta(int);
	void abonar(int);
	void cargar(int);
	int obtenerSaldo();
};
Cuenta::Cuenta(int sald) {
	if (sald > 0)
		this -> saldo = sald;
	else{
		this -> saldo = 0;
		cout << "El saldo inicial no era valido!" << endl;
	}
}
void Cuenta::abonar(int abona) {
	saldo = saldo + abona;
}
void Cuenta::cargar(int retira) {
	if (retira <= saldo)
		saldo = saldo - retira;
	else
		cout << "El monto a cargar excede el saldo de la cuenta!" << endl;
}
int Cuenta::obtenerSaldo() {
	return saldo;
}

class Factura {
private:
	string num = "", desc = "";
	int cant, precio;

public:
	Factura(string, string, int, int);
	void setNum(string);
	void setDesc(string);
	void setCant(int);
	void setPrecio(int);

	string getNum();
	string getDesc();
	int getCant();
	int getPrecio();

	int ObtenerMonto();

};
Factura::Factura(string n, string d, int c, int p) {
	this->num = n;
	this->desc = d;
	if (c < 0)
		this->cant = 0;
	else
		this->cant = c;
	if (p < 0)
		this->precio = 0;
	else
		this->precio = p;
	
}
void Factura::setNum(string nu) {
	this->num = nu;
}
void Factura::setDesc(string de) {
	this->desc = de;
}
void Factura::setCant(int ca) {
	this->cant = ca;
}
void Factura::setPrecio(int pr) {
	this->precio = pr;
}
string Factura::getNum() {
	return num;
}
string Factura::getDesc() {
	return desc;
}
int Factura::getCant() {
	return cant;
}
int Factura::getPrecio() {
	return precio;
}
int Factura::ObtenerMonto() {
	return cant * precio;
}

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int, int, int);
	void setDia(int);
	void setMes(int);
	void setAnio(int);

	int getDia();
	int getMes();
	int getAnio();

	string ObtenerFecha();
};
Fecha::Fecha(int d, int m, int a) {
	if (d >= 1 && d <= 31)
		this->dia = d;
	else
		this->dia = 1;
	if (m >= 1 && m <= 12)
		this->mes = m;
	else
		this->mes = 1;
	this->anio = a;
}
void Fecha::setDia(int d) {
	this->dia = d;
}
void Fecha::setMes(int m) {
	this->mes = m;
}
void Fecha::setAnio(int a) {
	this->anio = a;
}
int Fecha::getDia() {
	return dia;
}
int Fecha::getMes() {
	return mes;
}
int Fecha::getAnio() {
	return anio;
}
string Fecha::ObtenerFecha() {
	string d2 = to_string(dia);
	string m2 = to_string(mes);
	string a2 = to_string(anio);
	string f = d2 + " / " + m2 + " / " + a2;
	return f;
}

class Paquete {
private:
	string nombre1 = "", direccion1 = "", ciudad1 = "", estado1 = "";
	string nombre2 = "", direccion2 = "", ciudad2 = "", estado2 = "";
	int codigo1, codigo2, pesok, preciok;

public:
	Paquete(string,string,string,string,int,string,string,string,string,int,int,int);
    int calcularCosto();
};
Paquete::Paquete(string n1, string d1, string c1, string e1, int cc1, string n2, string d2, string c2, string e2, int cc2, int pk, int pkk) {
	this->nombre1 = n1;
	this->direccion1 = d1;
	this->ciudad1 = c1;
	this->estado1 = e1;
	this->codigo1 = cc1;
	this->nombre2 = n2;
	this->direccion2 = d2;
	this->ciudad2 = c2;
	this->estado2 = e2;
	this->codigo2 = cc2;
	if (pk >= 0)
		this->pesok = pk;
	else
		this->pesok = 0;
	if (pkk >= 0)
		this->preciok = pkk;
	else
		this->preciok = 0;
}
int  Paquete::calcularCosto() {
	int precio = pesok * preciok;
	return precio;
}
class PaqueteDosDias : Paquete {
public:
	int cuotafija;
	PaqueteDosDias(string, string, string, string, int, string, string, string, string, int, int, int, int);
	int calcularCosto();
};
PaqueteDosDias::PaqueteDosDias(string n1, string d1, string c1, string e1, int cc1, string n2, string d2, string c2, string e2, int cc2, int pk, int pkk, int cuota): Paquete(n1, d1, c1, e1, cc1, n2, d2, c2, e2, cc2, pk, pkk) {
	this->cuotafija = cuota;

}
int PaqueteDosDias::calcularCosto() {
	int tmpp = Paquete::calcularCosto();
	return cuotafija + tmpp;
}
class PaqueteNocturno : Paquete {
public:
	int cuotaextra;
	PaqueteNocturno(string, string, string, string, int, string, string, string, string, int, int, int, int);
	int calcularCosto();
};
PaqueteNocturno::PaqueteNocturno(string n1, string d1, string c1, string e1, int cc1, string n2, string d2, string c2, string e2, int cc2, int pk, int pkk, int cuotaex) : Paquete(n1, d1, c1, e1, cc1, n2, d2, c2, e2, cc2, pk, pkk) {
	this->cuotaextra = cuotaex;
}
int PaqueteNocturno::calcularCosto() {
	int temppp = Paquete::calcularCosto();
	return cuotaextra * temppp;
}


int main() {
	int d, m, a;
	int act,act1 = 0,n1 = 0,n2 = 0;
	int opcion, opcion2, saldo, trans;
	int r1, rr2, yy1, yy2;
	string e1, e2, e3, e4, ee1, ee2, ee3, ee4;
	string nu = "", de = "";
	string act2 = "";

	do {
		cout << "**** MENU ****" << "\n1.Cuenta" << "\n2.Factura"<< "\n3.Fecha" << "\n4.Paquetes" << "\n5.Salir" << endl;
		cin >> opcion;
		switch (opcion){
		case 1:
		{
			cout << "Ingrese un saldo inicial: " << endl;
			cin >> saldo;
			Cuenta c1 = Cuenta(saldo);
			do {
				
				cout << "**** MENU DE CUENTA ****" << "\n1.Abonar" << "\n2.Cargar" << "\n3.Obtener Saldo" << "\n4.Salir" << endl;
				cin >> opcion2;
				switch (opcion2) {
				case 1:
					cout << "Ingrese la cantidad que desea abonar: " << endl;
					cin >> trans;
					c1.abonar(trans);
					break;
				case 2:
					cout << "Ingrese la cantidad que desea cargar: " << endl;
					cin >> trans;
					c1.cargar(trans);
					break;
				case 3:
					act = c1.obtenerSaldo();
					cout << "El saldo actual es de: " << act << endl;
					break;
				}
			} while (opcion2 != 4);
		}
			break;

		case 2:
		{
			cout << "Ingrese el numero de pieza: " << endl;
			cin >> nu;
			cout << "Ingrese la descripcion del item: " << endl;
			cin >> de;
			cout << "Ingrese la cantidad de items: " << endl;
			cin >> n1;
			cout << "Ingrese el precio del item: " << endl;
			cin >> n2;
			Factura f1 = Factura(nu, de, n1, n2);
			act1 = f1.ObtenerMonto();
			cout << "El monto total de su factura es: " << act1 << endl;
		}
			break;

		case 3:
		{
			cout << "Ingrese el Dia: " << endl;
			cin >> d;
			cout << "Ingrese el Mes: " << endl;
			cin >> m;
			cout << "Ingrese el Anio: " << endl;
			cin >> a;
			Fecha f2 = Fecha(d, m, a);
			act2 = f2.ObtenerFecha();
			cout << "La Fecha ingresada es: " << act2 << endl;
		}
			break;

		case 4:
		{
			cout << "Ingrese el nombre del que envia: " << endl;
			cin >> e1;
			cout << "Ingrese la direccion de donde envia: " << endl;
			cin >> e2;
			cout << "Ingrese la ciudad de donde lo envia: " << endl;
			cin >> e3;
			cout << "Ingrese el estado de donde envia: " << endl;
			cin >> e4;
			cout << "Ingrese el codigo postal: " << endl;
			cin >> r1;
			cout << "Ingrese el nombre del que recibe el paquete: " << endl;
			cin >> ee1;
			cout << "Ingrese la direccion donde lo recibe: " << endl;
			cin >> ee2;
			cout << "Ingrese la ciudad donde lo envia: " << endl;
			cin >> ee3;
			cout << "Ingrese el estado donde lo envia: " << endl;
			cin >> ee4;
			cout << "Ingrese el codigo postal donde lo envian: " << endl;
			cin >> rr2;
			cout << "Ingrese el peso del paquete: " << endl;
			cin >> yy1;
			cout << "Ingrese el precio por peso: " << endl;
			cin >> yy2;
			Paquete g1 = Paquete(e1, e2, e3, e4, r1, ee1, ee2, ee3, ee4, rr2, yy1, yy2);
			PaqueteDosDias g2 = PaqueteDosDias(e1, e2, e3, e4, r1, ee1, ee2, ee3, ee4, rr2, yy1, yy2, 50);
			PaqueteNocturno g3 = PaqueteNocturno(e1, e2, e3, e4, r1, ee1, ee2, ee3, ee4, rr2, yy1, yy2, 50);
			int ny = g1.calcularCosto();
			int nyy = g2.calcularCosto();
			int nyyy = g3.calcularCosto();

			cout << "El costo normal del paquete es: " << ny << endl;
			cout << "El costo de paquete dos dias es:" << nyy << endl;
			cout << "El costo de paquete nocturno es: " << nyyy << endl;
		}
		break;

		}
	} while (opcion != 5);
	system("pause");
}