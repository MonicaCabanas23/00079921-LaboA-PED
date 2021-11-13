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
        cout << "\n\tHOJA ELECTRONICA ";
        cout << "\n1. Insertar numero \n2. Sumar una columna \n3. Imprimir \n4. Salir";
        cout << "\nSu opcion: "; cin >> option; 
        switch (option){
            case 1:
                cout << "\nDigite el numero a insertar: "; cin >> num; 
                do{
                    cout << "\nNumero de fila: "; cin >> row; 
                    cout << "\nNumero de columna: "; cin >> column; 
                } while (row > rows || row <= 0 || column > columns || column <= 0);
                insert (num, row, column);
                cout << "Dato insertado con exito! "; 
                break;
            case 2: 
                do{
                    cout << "\nColumna a sumar: "; cin >> column; 
                } while (column > columns || columns < 0);
                cout << "La suma es: " << addition (column);
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
    node *newNode = new node, *auxC, *auxR;
    auxC = auxR = P;

    for (int i = 1; i <= column_num; i++) //locating in the exact column
        auxC = auxC->next_column;
    while (auxC->next_row->row_num < row_num && auxC->next_row->row_num != 0) //positioning before the spotted row
        auxC = auxC->next_row;

    for (int i = 1; i <= row_num; i++) //locating in the exact row
        auxR = auxR->next_row;
    while (auxR->next_column->column_num < row_num && auxR->next_column->column_num != 0)
        auxR = auxR->next_column;

    if (auxR->next_column->column_num == column_num && auxC->next_row->row_num == row_num){
        auxR = auxR->next_column;
        auxR->data = data;
    }
    else {
        newNode->data = data;
        newNode->row_num = row_num;
        newNode->column_num = column_num;
        newNode->next_column = auxR->next_column;
        newNode->next_row = auxC->next_row;
        auxR->next_column = auxC->next_row = newNode;
    }
}
void Spreadsheet::print(void){
    cout << "\nLa hoja electrónica es:" << endl;
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

int Spreadsheet::addition(int column){
    node *auxC = P; 
    int addition = 0;
    
    while (auxC->column_num != column)
        auxC = auxC->next_column; 
    do {
        addition += auxC->data;
        auxC = auxC->next_row;
    } while (auxC->row_num != 0);
    return addition;
}

int main (void){
    int rows = 0, columns = 0;
    
    cout << "\nDigite el numero de filas: "; cin >> rows;
    cout << "\nDigite el numero de columnas: "; cin >> columns;
    Spreadsheet spreadsheetObject(rows, columns);
    spreadsheetObject.menu();
    return 0;
}