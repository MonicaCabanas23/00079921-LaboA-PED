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
	//~ClientsList(); 
	void menu (void); 
	void callMenu(void);
	void begginingInsert(void);
	void search (void);
	void search (string, client *);
};

int main (void)
{
	ClientsList myList; 
	myList.menu();  
	//myList.~ClientsList(); 
	return 0; 
}

ClientsList::ClientsList(){
	beggining = NULL; 
}
/*
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
*/
void ClientsList::menu(){
	int n = 0; 
    do {
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
			cout << "\nHa salido del menu exitosamente. " << endl; 
			break; 
		default: 
			cout << "Inserte una opcion valida: " << endl;
			break; 
	    }
    }
    while(n != 3);
}

void ClientsList::begginingInsert(){
    client data;

	    cout << "\nNombre: "; getline(cin, data.name);
		cout << "Apellido: "; getline (cin, data.surname); 
		cout << "DUI: "; cin >> data.DUI; 
		cout << "ID de tarjeta de cliente frecuente: "; cin >> data.card.ID; 
		cout << "Numero de sellos: "; cin >> data.card.marksQuantity; cin.ignore();
        cout << "\nInsertando datos ---------------------------------------" << endl; 
	    client *node = new client; 
	    node->name = data.name; 
	    node->surname = data.surname; 
	    node->DUI = data.DUI; 
	    node->card.ID = data.card.ID;
	    node->card.marksQuantity = data.card.marksQuantity; 
	    node->next = beggining; 
	    beggining = node; 
	
    cout << "\nLos datos se insertaron con exito\n";
    return;
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
			cout << "\nNombre: "  << jumper->name; 
			cout << "\nApellido: " << jumper->surname; 
			cout << "\nDUI: " << jumper->DUI; 
			cout << "\nTotal de sellos: " << jumper->card.marksQuantity; 
			freeProducts = jumper->card.marksQuantity / 10;
			jumper->card.marksQuantity = jumper->card.marksQuantity % 10; 
			cout << "\nProductos gratis: " << freeProducts; 
			cout << "\nNuevo total de sellos: " <<  jumper->card.marksQuantity << endl; 
		}
	}
	else 
		cout << "\nNo hay elementos en la lista :(" << endl << endl; 
} 