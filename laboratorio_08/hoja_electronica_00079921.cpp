#include <iostream>
using namespace std; 

struct node {
    int data; 
    int column_num = 0, row_num = 0;
    node *next_column, *next_row;
};

class Spreadsheet {
    private: 
        node* P; 
        int columns = 0, rows = 0; 
    public: 
        Spreadsheet();
        Spreadsheet(int, int);
        //~spreadsheet();
        void insert(); 
        void print();
        void print (node *, node *);
        float addition(); 
};

//building the basis column and row
Spreadsheet::Spreadsheet(int rows, int columns){
    //basis node
    node *aux, *c, *r;
    P = new node;

    this->rows = rows;
    this->columns = columns;
    P->column_num = 0; 
    P->row_num = 0;
    P->data = 0;
    P->next_column = P;
    P->next_row = P;

    //basis row
    aux = P;
    for (int i = 1; i <= columns; i++){
        r = new node; 
        aux->next_column = r;
        r->column_num = i;
        r->row_num = 0;
        r->data = 0;
        r->next_row = r;
        aux = aux->next_column;
    }
    aux->next_column = P;

    //basis column
    aux = P;
    for (int i = 1; i <= rows; i++){
        c = new node;
        aux->next_row = c;
        c->column_num = 0;
        c->row_num = i;
        c->data = 0;
        c->next_column = c;
        aux = aux->next_row;
    }
    aux->next_row = P;
}

// void spreadsheet::print (){
//     spreadsheet(3, 3);
//     node *jumper = P;
//     node *aux = NULL;
//     do {
//         aux = jumper;
//         print (jumper, aux);
//         cout << endl;
//         jumper = jumper->next_row;
//     } while (jumper != P);
// }

// void spreadsheet::print(node *jumper, node *aux){
//     if (jumper != aux){
//         cout << jumper->data << " ";
//         jumper = jumper->next_column;
//         print(jumper, aux);
//     }
//     else return;
// }

void Spreadsheet::print(void){
    cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    node *s = P;
    int i;

    do{
        do{
            cout << s->row_num <<',' << s->column_num << ',' << s->data << '\t';
            s = s->next_column;
        }while(s->column_num != 0);
        cout << endl;
        s = s->next_row;
    }while(s->row_num != 0);
}

int main (void){
    int rows = 5, columns = 5;
    Spreadsheet spreadsheetObject(rows, columns);
    spreadsheetObject.print();
    return 0;
}