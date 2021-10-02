#include <iostream>
using namespace std; 

struct data{
    int x = 0; 
    data *next; 
};

class Queue {
    private: 
    data *beggining; 
    data *rear; 
    public: 
    Queue (void); 
    ~Queue (void);
    void menu (void); 
    void enqueue (int x); 
    void dequeue (void);
    void dequeue (data *jumper, data *aux); 
    void print (void);  
    void print (data *jumper); 
};

int main (void) 
{
    Queue myQueue; 

    myQueue.menu(); 

    return 0; 
}

Queue::Queue(){
    beggining = NULL;
    rear = beggining; 
}

Queue::~Queue(){
    data *aux;
    aux = NULL;
    cout << "Executing destructor";
    while (beggining)
    {
        aux = beggining; 
        beggining = beggining->next;
        delete aux; 
    }
}

void Queue::menu (){
    int x = 0, n = 0; 

    do{
        cout << "\n--------------------------------------------";
        cout << "\n\nMENU \n1. Insert value \n2. Delete data from the queue \n3. Show data \n4. Exit";
        cout << "\nYour option: "; cin >> n; 
        switch (n)
        {
            case 1:
                cout << "-----------------------------------";
                cout << "\nInsert the value: "; cin >> x; 
                enqueue(x); 
                break; 
            case 2:
                dequeue(); 
                break; 
            case 3: 
                print(); 
                break; 
            case 4: 
                cout << "\nYou have succesfully exited from the menu\n\n"; 
                break; 
            default: 
                cout << "------------------------------------";
                cout << "\nInsert a valid value"; 
                break; 
        } 
    } while(n != 4);
}

void Queue::enqueue(int x){
    cout << "Inserting..."; 
    data *node = new data;
    node->x = x;

    //if there is no elemnts in the list, then, for inserting a new node, all we need is to set beggining to 
    //the new node (since there is no any other) 
    //and rear to the same node (since this is the first and last node of the queue).
    if (rear == NULL)
    {  
        node->next = rear; 
        beggining = rear = node;   
    }

    //if rear is not pointing to NULL, then all we need is to set node->next to rear->next (NULL)
    //since rear is always pointing to the last item of the list. So there is no need of using a 'jumper' pointer
    else
    {
        node->next = rear->next;
        rear->next = node; 
        rear = rear->next; //moving 'rear' to the last node of the list
    } 
}

void Queue::dequeue(){
    data *jumper = beggining; 
    data *aux = NULL;
    dequeue(jumper, aux);
}

void Queue::dequeue(data *jumper, data *aux){

    if (rear)
    {
        while (jumper->next)
        {
            aux = jumper;
            jumper = jumper->next;     
        }

        if (aux)
        {
            rear = aux;
            rear->next = jumper->next; 
            cout << "\nTo delete:" << jumper->x; 
            delete jumper;
        }
        else
        {
            beggining = aux;
            rear = beggining; 
            cout << "\nTo delete:" << jumper->x;
            delete jumper;
        } 
    }
    else
        cout << "\nThe queue is empty"; 
}

void Queue::print (){
    data *jumper; 
    jumper = beggining; 
    print(jumper); 
}

void Queue::print(data *jumper){
    if (!jumper)
        cout << "\nThe queue is empty";
    else
    {
        cout << endl << jumper->x; 
        jumper = jumper->next; 
        if (jumper)
            print (jumper); 
    } 
}