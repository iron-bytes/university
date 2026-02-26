#include <stdio.h>
#include <stdlib.h>

#include "../asd_library/structures.h"

int RecursiveAlgo_21_1_22(struct tree_node*, int);

int main(){
    struct tree_node* root = Load_Tree();

    int result1 = RecursiveAlgo_21_1_22(root, 5);
    printf("\nResult1 = %d", result1);

    return 0;
}

#pragma region Esame 21/1/22
// function which was named but not defined
int G(int i){
    return i*i+1;
}

int RecursiveAlgo_21_1_22(struct tree_node* T, int i){
    int a,z;

    a = G(i);
    if(T == NULL){
        return a;
    }
    else{
        z = RecursiveAlgo_21_1_22(T->left , 2*i);
        a = z + i*(T->data) + a;
        z = a + RecursiveAlgo_21_1_22(T->right, (2*i)+1);
        return 3*z;
    }
}

#pragma endregion
