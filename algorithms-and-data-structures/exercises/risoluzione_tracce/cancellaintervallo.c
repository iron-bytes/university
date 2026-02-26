#include <stdio.h>
#include <stdlib.h>

#include "../asd_library/structures.h"

Node* CancellaIntervallo(Node* T, int a, int b){
    if(T != NULL){
        if(T -> data < a){
            T -> right = CancellaIntervallo(T -> right, a, b);     
        }
        else if(T -> data > b){
            T -> left = CancellaIntervallo(T -> left, a, b);
        }
        else{
            T -> left = CancellaIntervallo(T -> left, a, b);
            T -> right = CancellaIntervallo(T -> right, a, b);
            T -> data = -1; // cancellaroot
        }    
    }
    return T;
}

int main(void){
    Node* T = Load_Tree();

    printf("\n\nIN ORDER:\n\n ");
    PrintInOrder(T);
    T = CancellaIntervallo(T, 10, 50);
    printf("\n\n IN ORDER AFTER OPERATION: \n\n");
    PrintInOrder(T);    
    return 0;
}
