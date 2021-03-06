#include <iostream> 
using namespace std; 

struct data {
    int id = 0; 
    string name = "";
    string surname= "";
};

struct node {
    struct data data; 
    node *left; 
    node *right;
};

class Tree {
    private: 
        node *P; 
    public: 
        Tree(); 
        void add (data); 
        void add (data, node **);
        void in_order ();
        void in_order (node *);
        void pre_order ();
        void pre_order (node *);
        void post_order ();
        void post_order (node *); 
};

Tree::Tree(void) {P = NULL;}

void Tree::add (data data){
    node **t = &P; 
    add (data, &P);
}

void Tree::add (data data, node **t){
    if (!(*t)){
        *t = new node; 
        (*t)->data = data;
        (*t)->left = (*t)->right = NULL; 
    }
    else if (data.id < (*t)->data.id)
        add (data, &((*t)->left));
    else if (data.id > (*t)->data.id)
        add (data, &((*t)->right));
}

void Tree::in_order (){ //LNR
    node *t = P; 
    if (t){
        cout << "\n\nImprimiendo en In Order ";
        in_order (t);
    }
    else 
        cout << "\nNo hay datos en el arbol ";
}

void Tree::in_order (node *t){
    if (t){
        in_order (t->left);
        cout << endl << t->data.id << " " << t->data.name << " " << t->data.surname; 
        in_order (t->right);
    }
    else return;
}

void Tree::pre_order(){ // NLR
    node *t = P; 
    if (t){
        cout << "\n\nImprimiendo en Pre Order ";
        pre_order (t);
    }
    else 
        cout << "\nNo hay datos en el arbol ";
}

void Tree::pre_order(node *t){
    if (t){
        cout << endl << t->data.id << " " << t->data.name << " " << t->data.surname;
        pre_order(t->left);
        pre_order(t->right);
    }
    else return;
} 

void Tree::post_order(){
    node *t = P;
    if (t){
        cout << "\n\nImprimiendo en Post Order ";
        post_order (t);
    }
    else 
        cout << "\nNo hay datos en el arbol ";
}

void Tree::post_order(node *t){
    if (t){
        post_order(t->left);
        post_order(t->right);
        cout << endl << t->data.id << " " << t->data.name << " " << t->data.surname;
    }
    else return;
}

int main (void){
    data data;
    Tree object;
    bool exit = false;
    char answer;

    while (!exit){
        cout << "\nDigita los datos: ";
        cout << "\nID del estudiante: "; cin >> data.id; cin.ignore();
        cout << "Nombre: "; getline (cin, data.name); 
        cout << "Apellido: "; getline (cin, data.surname);
        object.add(data);
        cout << "\nDeseas continuar? S/n "; cin >> answer; 
        if (answer == 'n')
            exit = true; 
    }
    object.in_order();
    object.pre_order();
    object.post_order();
    return 0;
}