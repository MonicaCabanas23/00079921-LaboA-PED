#include <iostream>
using namespace std; 

struct data {
    int number = 0; 
    data *pointer; 
};

class Stack {
    private: 
    data *mainPointer;
    public: 
    Stack(void);
    ~Stack(void);
    void menu (void); 
    void print (void); 
    void print (data *jumper); 
    void push (int x);
    void pop (void);   
};

int main (void)
{
    Stack myList;
    
    myList.menu(); 

    return 0; 
}

void Stack::menu (){
    int n = 0, x = 0;

    do {
        cout << "\n\nMENU \n1. Insert value \n2. Delete data from the stack \n3. Show data \n4. Exit";
        cout << "\nYour option: "; cin >> n; 
        switch (n)
        {
            case 1:
                cout << "-----------------------------------";
                cout << "\nInsert the value: "; cin >> x; 
                push(x);
                break; 
            case 2: 
                pop (); 
                break; 
            case 3: 
                print(); 
                break; 
            case 4: 
                cout << "\nYou have succesfully exited form the menu\n"; 
                break; 
            default: 
                cout << "------------------------------------";
                cout << "\nInsert a valid value"; 
                break; 
        }
    } while (n != 4);
    return;
}

Stack::Stack (){
    mainPointer = NULL; 
}

Stack::~Stack(){
    data *aux;
    aux = NULL;
    cout << "Executing destructor";
    while (mainPointer)
    {
        aux = mainPointer; 
        mainPointer = mainPointer->pointer;
        delete aux; 
    }
}


void Stack::push (int x){
    data *node = new data; 
    node ->number = x; 
    node ->pointer = mainPointer; 
    mainPointer = node;
    return ;
}

void Stack::pop(){
    data *aux; 

    if (!mainPointer)
        cout << "\nThe stack is empty";
    else 
    {
        aux = mainPointer; 
        mainPointer = mainPointer->pointer; 
        delete (aux); 
    }
}

void Stack::print (){
    data *jumper;
    jumper = mainPointer; 
    print (jumper); 
}

void Stack::print(data *jumper){
    if (!jumper)
        cout << "\nThe stack is empty";
    else
    {
        cout << endl << jumper->number; 
        jumper = jumper->pointer; 
        if (jumper)
            print (jumper); 
    } 
}