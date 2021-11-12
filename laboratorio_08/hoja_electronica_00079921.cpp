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
        Spreadsheet(int, int);
        //~spreadsheet();
        void menu ();
        void insert(int, int, int); 
        void print();
        void print (node *, node *);
        int addition(int); 
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

void Spreadsheet::menu(){
    int option = 0, num = 0, row = 0, column = 0;
    bool keep = true; 

    while (keep){
        cout << "\tHOJA ELECTRONICA ";
        cout << "\n1. Insertar numero \n2.Sumar una columna \n3. Imprimir \n4. Salir";
        cout << "\nSu opcion: "; cin >> option; 
        switch (option){
            case 1:
                cout << "\nDigite el numero a insertar: "; cin >> num; 
                cout << "\nNumero de fila: "; cin >> row; 
                cout << "\nNumero de columna: "; cin >> column; 
                insert (num, row, column);
                cout << "Dato insertado con exito! "; 
                break;
            case 2: 
                cout << "\nColumna a sumar: "; cin >> column; 
                //cout << "La suma es: " << addition (column);
                break; 
            case 3: 
                print();
                break; 
            case 4: 
                keep = false; 
                cout << "\nSaliendo...";
                break;
            default: 
                cout << "\nOpcion no valida ";
                break;   
        }
    }
    cout << "\nHa salido exitosamente del menu! ";
}
void Spreadsheet::insert(int data, int row_num, int column_num){
    node *newNode = new node, *aux_columns, *aux_rows;
    aux_columns = aux_rows = P;

    newNode->data = data;
    newNode->row_num = row_num;
    newNode->column_num = column_num;

    for (int i = 1; i <= column_num; i++) //locating in the exact column
        aux_columns = aux_columns->next_column;
    cout << "\nnumero de columna en la que se encuentra: " << aux_columns->column_num;
    while (aux_columns->next_row->row_num < row_num && aux_columns->next_row->row_num != 0) //positioning before the spotted row
        aux_columns = aux_columns->next_row;

    for (int i = 1; i <= row_num; i++) //locating in the exact row
        aux_rows = aux_rows->next_row;
    cout << "\nnumero de fila en la que se encuentra: " << aux_rows->row_num;
    while (aux_rows->next_column->column_num < row_num && aux_rows->next_column->column_num != 0)
        aux_rows = aux_rows->next_column;

    newNode->next_column = aux_rows->next_column;
    newNode->next_row = aux_columns->next_row;
    aux_rows->next_column = aux_columns->next_row = newNode;
}
void Spreadsheet::print(void){
    cout << "La hoja electrónica es:" << endl;
    node *s = P;
    int i;

    do{
        do{  //priniting rows first
            cout << s->row_num << ',' << s->column_num << ',' << s->data << '\t'; 
            s = s->next_column;     
        }while(s->column_num != 0);
        cout << endl;
        s = s->next_row;
    }while(s->row_num != 0);
}

int main (void){
    int rows = 5, columns = 5;
    Spreadsheet spreadsheetObject(rows, columns);
    spreadsheetObject.menu();
    return 0;
}