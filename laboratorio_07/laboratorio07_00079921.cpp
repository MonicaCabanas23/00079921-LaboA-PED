#include <iostream>
using namespace std; 

struct studentData {
    int ID = 0; 
    string name = ""; 
    string major = ""; 
};

struct node {
    studentData data ; 
    node *sig; 
};

class studentsClass {
    private:  
       node *beginning; 
    public: 
        studentsClass (void); 
        ~studentsClass(void);
        void menu (void);
        void enqueue (studentData data);
        void print (void);
        void print (node *p);
        void del (int IDReference); 
};

studentsClass::studentsClass(){
    beginning = NULL; 
}

studentsClass::~studentsClass(){
    node *p = beginning;
    node *aux; 
    do {
        aux = p; 
        p = p->sig; 
        delete aux; 
    } while (p->sig != beginning);
}

void studentsClass::menu(){
    int option = 0; 
    bool flag = 1;
    studentData data; 

    while (flag){
        cout << "\n-----------------------------\nMENU";
        cout << "\n1. Insertar en la cola \n2. Imprimir \n3. Eliminar \n4. Salir ";
        cout << "\nSu Opcion: "; cin >> option; cin.ignore();
        switch (option){
            case 1: 
                cout << "\n----------------------\n";
                cout << "Nombre: "; getline (cin, data.name);
                cout << "ID: "; cin >> data.ID; cin.ignore();
                cout << "Carrera: "; getline (cin, data.major);
                enqueue(data); 
                cout << "\nDatos insertados con exito! ";
                break; 
            case 2: 
                cout << "\n----------------------\n";
                if (beginning){
                    cout << "Imprimiendo... ";
                    print ();
                }
                else 
                    cout << "\nNo hay elementos en la lista.";
                break; 
            case 3: 
                cout << "Inserte el ID del estudiante a eliminar: "; cin >> data.ID;
                del (data.ID);
                break; 
            case 4: 
                flag = 0;
                cout << "Saliendo...";
                break; 
            default:
                cout << "\nOpcion no valida, vuelva a intentarlo. ";
                break; 
        }
    }
    cout << "\nHa salido exitosamente del menu! ";
}

void studentsClass::enqueue(studentData data){
    node *p;
    node *newNode = new node; 
    newNode->data.name = data.name;
    newNode->data.ID = data.ID; 
    newNode->data.major = data.major; 

    if (!beginning){
        beginning = newNode;
        newNode->sig = beginning;
    }
    else{
        p = beginning;
        while (p && p->sig != beginning){
            p = p->sig;
        }
        p->sig = newNode;
        newNode->sig = beginning;
    }
}

void studentsClass::print(){
    node *p = beginning; 

    if (beginning){
        cout << "\nID: " << p->data.ID; 
        cout << " Nombre: " << p->data.name;
        cout << " Carrera: " << p->data.major;
        p = p->sig;
        print (p);
    }
}

void studentsClass::print(node *p){
    if (p != beginning){
        cout << "\nID: " << p->data.ID; 
        cout << " Nombre: " << p->data.name;
        cout << " Carrera: " << p->data.major; 
        if (p->sig == beginning)
            cout << "\nEl siguiente de " << p->data.name << " es ";
        p = p->sig;
        print (p);
    }
    else {
        if (p->sig == beginning)
            cout << "\nEl siguiente de " << p->data.name << " es ";
        cout << p->data.name;
        return;
    }
}

void studentsClass::del (int idReference){
    node *p = beginning, *aux = NULL; 
    if (!beginning)
        cout << "La lista esta vacia ";
    else {
        do {
            aux = p; 
            p = p->sig;
        } while (p->data.ID != idReference && p != beginning);
        if (p->data.ID == idReference){
            if (p == beginning && p->sig != beginning){
                aux->sig = beginning->sig;
                delete beginning;
                beginning = aux->sig;
            }
            else if (p == beginning && p->sig == beginning){
                delete beginning;
                beginning = NULL;
            }
            else {
                aux->sig = p->sig;
                delete p;
            }
            cout << "\nElemento eliminado exitosamente!";
        }
        else 
            cout << "\nEl elemento no existe en la lista";
    }
}

int main (void){
    studentsClass student;
    student.menu();
    return 0; 
}