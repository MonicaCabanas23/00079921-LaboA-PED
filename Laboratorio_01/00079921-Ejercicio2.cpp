/*Realizar una lista simplemente enlaza con la forma que gusten, ya sea insertando al inicio o al
final (pila o cola), la lista representará una colección de libros donde deberá guardarse el id y
nombre de cada libro, para este ejercicio se deberán insertar libros e imprimirlos de forma
recursiva.*/

#include <iostream>
#include <stdio.h>
using namespace std; 

struct data {
    int ID = 0; 
    string name = "";
};

struct book {
    struct data bookData; 
    book* next; 
} data; 

class bookList{
    private: 
    book *begginingP;
    public: 
    bookList(void);
    void jumperInitializer (void);
    void begginingInsert (void); 
    void begginingInsert(string, int);
    void print (book *);
};

int main (void){
    bookList myList;

    myList.begginingInsert(); 
    myList.jumperInitializer();
    return 0; 
}

bookList::bookList(){
    begginingP = NULL; 
}

void bookList::begginingInsert()
{
    //Asking for the first time the data so we can create the new node and repeat it recursively in the next function
    cout << "\nDATOS DEL LIBRO: " << endl;
    cout << "Nombre: "; getline(cin, data.bookData.name); 
    cout << "ID: "; cin >> data.bookData.ID; cin.ignore();    
    begginingInsert(data.bookData.name, data.bookData.ID);
}

void bookList::begginingInsert(string name, int ID)
{
    //Receaiving the data and creating the node
    book *nw = new book;   
    nw->bookData.name = name;
    nw->bookData.ID = ID; 
    nw ->next = begginingP;
    begginingP = nw; 
    //Repeating the process
    cout << "\nDATOS DEL LIBRO: " << endl;
    cout << "Nombre: ";
    //If the user decides to keep on inserting more data, we´ll repeat the process   
    if (getline(cin, data.bookData.name))
    {
        cout << "ID: "; cin >> data.bookData.ID; cin.ignore();     
        begginingInsert(data.bookData.name, data.bookData.ID); //Repeating the process with the new data
    }    
    return;
}

void bookList::jumperInitializer(void){
    book *jumper; 
    jumper = begginingP; //Initializing our 'jumper', which is pointing to the first node of the list
    //Printing the data inside of the first node
    cout << "\n\nImprimiendo datos: ........................................................ \n"; 
    cout << "\nNombre: " << jumper->bookData.name;
    cout << "\nID: " << jumper->bookData.ID << endl;
    print (jumper->next); 
    return; 
}

void bookList::print(book *jumper){ 
    if (jumper){ //if our jumper hasn´t arrived to NULL yet we´ll keep on the process
        cout << "\nNombre: " << jumper->bookData.name;
        cout << "\nID: " << jumper->bookData.ID << endl;
        print (jumper->next); //Reapiting recursivily untill our jumper reaches NULL
    }
    return; 
}
