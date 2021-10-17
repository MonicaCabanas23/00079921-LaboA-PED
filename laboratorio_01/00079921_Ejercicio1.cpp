/*Realizar la multiplicación de dos números enteros en forma de suma recursiva*/
#include <iostream>
using namespace std; 

int recursiveAddition (int, int); 

int main (void){
    int n1 = 0, n2 = 0; 

    cout << "\nInserte n1: "; cin >> n1; 
    cout << "\nInserte n2: "; cin >> n2; 
    cout << recursiveAddition(n1,n2);
    return 0; 
}

int recursiveAddition (int n1, int n2){
    if (n2 > 0) //Conditional for avoiding unnecessary addition
        return n1 + recursiveAddition(n1, n2-1);
    else if (n2 < 0)
        return -n1 + recursiveAddition (n1, n2+1);  
    else if (n2 == 0 or n1 == 0)
        return 0; //Our basis case
    
}