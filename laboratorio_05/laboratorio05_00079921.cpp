#include <iostream>
#include <stdio.h>
using namespace std; 

struct node{
    string data = ""; 
    node *left; 
    node *right; 
};

class List {
    private:
    node *beggining; 
    node *end;  
    public: 
    List(); 
    ~List(); 
    void pushEnd(void); 
    void pushEnd(string data, bool mark);
    void printB(void);
    void printB(node *jumper);
    void printE(void); 
    void printE(node *jumper);
    void del (void);
};

List::List(){
    beggining = NULL; 
    end = NULL; 
}

List::~List(){
    node *aux; 
    while (beggining){
        aux = beggining; 
        beggining = beggining->right; 
        delete aux; 
    }
}

void List::pushEnd(){
    string data = ""; 
    bool mark = 1;
    cout << "\nInserte el dato: "; getline (cin, data);
    pushEnd(data, mark); 
}

void List::pushEnd(string data, bool mark){

    if (mark){
        node *newNode = new node;
        newNode->data = data;

        if (!beggining){
            newNode->left = beggining; 
            newNode->right = end; 
            beggining = end = newNode; 
        } else{ 
            newNode->right = end->right; 
            end->right = newNode;
            newNode->left = end; 
            end = newNode; 
        } 
        cout << "\nDigite 1 si desea insertar otro dato. 0 si desea salir. 1/0 "; cin >> mark; 
        cin.ignore();
        if (mark){
           cout << "\nInserte el dato: "; getline(cin, data);
           pushEnd(data, mark); 
        }
    } else{
        cout << "\n-------------------------------------\n";
        cout << "\nLos datos se han insertado con exito!";
    }
}

void List::printB(){
    node *jumper = beggining; 
    if (jumper){
        cout << "\n-------------------------------------\n";
        cout << "Imprimiendo datos: \n";
        printB(jumper); 
    }
    else
        cout << "\nNo hay elementos en la lista";
}

void List::printB(node *jumper){

    if (jumper){
        cout << endl << jumper->data;
        jumper = jumper->right;
        printB(jumper);
    }
}

void List::printE(){
    node *jumper = end; 
    if (jumper){
        cout << "\n-------------------------------------\n";
        cout << "Imprimiendo datos: \n";
        printE (jumper); 
    }
    else
        cout << "\nNo hay elementos en la lista";
}

void List::printE(node *jumper){
    if (!jumper)
        return;
    else{
        cout << endl << jumper->data;
        jumper = jumper->left; 
        printE(jumper);             
    }
} 

void List::del (){
    node *jumper = beggining, *aux, *aux2 = beggining; 
    int i = 0, n = 0;
    string dataRef = "";
    bool mark = false;

    cout << "\nInserte el dato a partir del cual desea eliminar: "; getline (cin, dataRef);

    while (jumper){
        if ((jumper->data).compare(dataRef) == 0){
            mark = true; 
            i++; 
        }
        jumper = jumper->right;
    }
    jumper = beggining;
    n = i; i = 0;

    if (mark){
        for (i; i<n ; i++){
            mark = false;
            while (!mark){
            if (jumper != NULL && (jumper->data).compare(dataRef) == 0){
                mark = true;
                if (i == 0){
                    aux2 = beggining = jumper;
                    beggining->left = NULL;
                    jumper = jumper->right;
                }
                else {
                    aux2->right = jumper;
                    jumper->left = aux2;
                    aux2 = aux2->right;
                    jumper = jumper->right;
                }
            }
            else if (jumper != NULL && (jumper->data).compare(dataRef) != 0){
                aux = jumper; 
                cout << endl << jumper->data;
                jumper = jumper->right;
                delete aux;
            }
            else break;
            }
        }
    }
    else 
        cout << "\nEl dato no se encuentra en la lista";
}

int main (void){
    List object; 

    object.pushEnd();
    object.printB(); 
    object.printE();
    object.del();
    object.printB();
    return 0;
}