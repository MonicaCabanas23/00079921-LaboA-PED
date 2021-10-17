#include <iostream>
using namespace std;

struct node {
    int number = 0; 
    node *right;
    node *left; 
};

class List {
    private:
    node *beggining;
    node *end; 
    public: 
    List (void);
    ~List (void);
    void menu (void);
    void enqueue (int number);
    void insertAfter (int number, int numberRef);
    void del (int numberRef);
    void printReverse (void);
    void printReverse (node *jumper);
};

List::List (){
    beggining = NULL; 
    end = NULL; 
}

List::~List(){
    node *jumper = beggining, *aux; 
    while (jumper){
        aux = jumper; 
        jumper = jumper->right; 
        delete aux;
    }
}

void List::menu(){
    int number = 0, option = 0, reference = 0;
    node *jumper = beggining, *aux;
    bool flag = false;
    do {
        cout << "\n------------------------------------------------------\n \nMENU";
        cout << "\n1. Insertar en la cola. \n2. Insertar despues de un numero dado."; 
        cout << "\n3. ELiminar. \n4. Imprimir al reverso. \n5. Salir.";
        cout << "\nSu opcion: "; cin >> option; 
        switch (option){
            case 1:
                cout << "\n------------------------------------------------------\n";
                cout << "\nDigite el numero a insertar: "; cin >> number;
                enqueue(number); 
            break; 
            case 2:
                cout << "\n------------------------------------------------------\n";
                cout << "\nDigite el numero despues del que desea insertar: "; cin >> reference;
                cout << "\nDigite el numero a insertar: "; cin >> number;
                insertAfter (number, reference);
            break; 
            case 3:
                cout << "\n------------------------------------------------------\n";
                if (beggining){
                    cout << "\nDigite el numero a eliminar: "; cin >> reference; 
                    del (reference);
                }
                else 
                    cout << "\nLa lista esta vacia";
            break; 
            case 4:
                cout << "\n------------------------------------------------------\n";
                printReverse(); 
            break; 
            case 5:
                cout << "\n------------------------------------------------------\n";
                cout << "\nHa salido exitosamente del menu! \n"; 
            break; 
            default:
                cout << "\n------------------------------------------------------\n";
                cout << "\nOpcion no valida. \nInserte de nuevo"; 
            break; 
        }
    }while (option != 5);
}

void List::enqueue(int number){
    node *newNode = new node;
    newNode->number = number;

    if (!beggining){
        newNode->right = end;
        newNode->left = beggining; 
        beggining = end = newNode;    
    }
    else {
        newNode->right = NULL;
        newNode->left = end; 
        end->right = newNode; 
        end = end->right;
    }
}

void List::insertAfter(int number, int numberRef){ 
    node *jumper = beggining; 
    int i = 0;

    while (jumper){
        if (jumper && jumper->number == numberRef){
            node *newNode = new node; 
            newNode->number = number;
            newNode->right = jumper->right;
            newNode->left = jumper; 
            if (!jumper->right){
                jumper->right = end = newNode; 
                jumper = NULL;
            } else {
                jumper->right->left = newNode;
                jumper->right = newNode;
                jumper = jumper->right->right;
            }
            i++;
        } 
        else if (jumper && jumper->number!= numberRef)
            jumper = jumper->right;
    }

    if (i == 0 && !jumper){
        cout << "\nEl dato de referencia no se encontro. Se insertara al final. ";
        enqueue (number);
    }

    if (!beggining){
        node *newNode = new node; 
        newNode->number = number;
        newNode->right = end; 
        newNode->left = beggining; 
        beggining = end = newNode; 
    }

    cout << "\nSe ha insertado el dato con exito! ";
}

void List::del (int numberRef){
    node *jumper = beggining, *aux;
    int i = 0;
    while (jumper){
        if (jumper && jumper->number == numberRef){
            aux = jumper; 
            if (jumper == beggining){ //if the node we are looking for is at the beggining
                if (jumper->right){
                    jumper->right->left = NULL;
                    jumper = beggining = beggining->right;
                }
                else 
                    jumper = beggining = end = NULL;
            }
            else if (jumper == end){
                jumper->left->right = NULL;
                end = end->left;
                jumper = NULL;
            }
            else {
                if (jumper->right) //for avoiding segmentation faults
                    jumper->right->left = jumper->left;    
                jumper->left->right = jumper->right;
                jumper = jumper->right;
            }
            delete aux;
            i++;
        } else if (jumper && jumper->number != numberRef)
            jumper = jumper->right;
    }

    if (i == 0 && !jumper){
        cout << "\nEl elemento digitado no existe en la lista.";
    }
    if (i > 0)
        cout << "\nElemento eliminado exitosamente!";
}

void List::printReverse(){
    node *jumper = end;
    if (jumper){
        cout << "\nImprimiendo datos: \n"; 
        printReverse(jumper);
    } else {
        cout << "\nNo hay datos en la lista. ";
        return;
    }
}

void List::printReverse(node *jumper){
    if (jumper){
        cout << jumper->number << endl; 
        jumper = jumper->left; 
        printReverse(jumper);
    } else return;
}