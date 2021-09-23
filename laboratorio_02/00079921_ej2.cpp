#include <iostream>
#include <stdio.h>
using namespace std; 

struct fcCard{
	int ID = 0; 
	int marksQuantity = 0; 
};

struct client {
	string name = ""; 
	string surname = ""; 
	string DUI = ""; 
	struct fcCard card; 
	client *next; 
};

class ClientsList{
private: 
	client *beggining;

public: 
	ClientsList(void); 
	~ClientsList(); 
	void menu (void); 
	void callMenu(void);
	void begginingInsert(void);
	void begginingInsert (client data);
	void search (void);
	void search (string, client *);
};

int main (void)
{
	ClientsList myList; 
	myList.menu();  
	myList.~ClientsList(); 
	return 0; 
}

ClientsList::ClientsList(){
	beggining = NULL; 
}

ClientsList::~ClientsList(){
	client *jumper, *aux; 
	aux = NULL; 
	jumper = beggining; 

	if (!jumper)
		cout << "No hay elementos en la lista"; 
	else{
		while (jumper){
			aux = jumper; 
			jumper = jumper->next; 
			cout << "Eliminando"; 
			delete aux;
			cout << "\nNodo eliminado";
		} 
	}
}

void ClientsList::menu(){
	int n = 0; 

	cout << "\nMENU\n"; 
	cout << "\n1. Insertar en la lista. \n2. Buscar dentro de la lista. \n3. Salir." << endl; 
	cout << "\nSu opcion: "; cin >> n; cin.ignore(); 
	switch (n)
	{
		case 1: 
			begginingInsert(); 
			break; 
		case 2: 
			search(); 
			break; 
		case 3:
			cout << "\nHa salido del menu exitosamente. "; 
			break; 
		default: 
			cout << "Inserte una opcion valida: ";
			menu(); 
			break; 
	}
}

void ClientsList::begginingInsert(){
	client data;
	cout << "Nombre: "; getline(cin, data.name); 
	cout << "Apellido: "; getline (cin, data.surname); 
	cout << "DUI: "; cin >> data.DUI; 
	cout << "ID de tarjeta de cliente frecuente: "; cin >> data.card.ID; 
	cout << "Numero de sellos: "; cin >> data.card.marksQuantity; cin.ignore(); 
	begginingInsert(data);
}

// I have problems in this function...
void ClientsList::begginingInsert(client data){
	cout << "\nInsertando datos ---------------------------------------" << endl; 
	client *node = new client; 
	node->name = data.name; 
	node->surname = data.surname; 
	node->DUI = data.DUI; 
	node->card.ID = data.card.ID;
	node->card.marksQuantity = data.card.marksQuantity; 
	node->next = beggining; 
	beggining = node; 

	cout << "\nNombre: "; 
	if (getline(cin, data.name))
	{
		cout << "Apellido: "; getline (cin, data.surname); 
		cout << "DUI: "; cin >> data.DUI; 
		cout << "ID de tarjeta de cliente frecuente: "; cin >> data.card.ID; 
		cout << "Numero de sellos: "; cin >> data.card.marksQuantity; cin.ignore();
		begginingInsert(data);
	}
	else if (!getline(cin,data.name)){
		cout << "\nLos datos se insertaron con exito\n";
		menu();  
	}
}

void ClientsList::search(){
	string ref = ""; 
	client *jumper; 
	jumper = beggining; 
	cout << "\n---------- MENU DE BUSQUEDA ----------\n";
	cout << "Inserte el numero de DUI de la persona que desea buscar: "; getline(cin, ref);
	search (ref, jumper);
} 

void ClientsList::search(string ref, client *jumper){ 
	int freeProducts = 0; 
	if (jumper){
		if (jumper->DUI != ref){
			jumper = jumper->next; 
			search (ref, jumper); 
		}
		else {
			cout << "Nombre: "  << jumper->name; 
			cout << "Apellido: " << jumper->surname; 
			cout << "DUI: " << jumper->DUI; 
			cout << "Total de sellos: " << jumper->card.marksQuantity; 
			freeProducts = jumper->card.marksQuantity / 10;
			jumper->card.marksQuantity = jumper->card.marksQuantity % 10; 
			cout << "Productos gratis: " << freeProducts; 
			cout << "Nuevo total de sellos: " <<  jumper->card.marksQuantity; 
		}
	}
	else 
		cout << "\nNo hay elementos en la lista :(" << endl << endl; 
}