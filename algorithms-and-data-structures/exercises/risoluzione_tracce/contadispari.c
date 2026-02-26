#include <stdio.h>
#include <stdlib.h>
#include "../asd_library/structures.h"

int contadispari(Node* T){
    int ret = 0;
    if(T != NULL){
        ret = contadispari(T -> left);
        printf("\n\nAnalizzando: %d", T -> data);
        if((T -> data % 2) == 1){
            ret = ret + 1;
        }
        ret = ret + contadispari(T -> right);
    }
    return ret;
}

int contadispari_iterativo_v2(Node* T){
    Node* CT = T;
    Node* Last_T = NULL;

    StackInt* ST_R = NULL;
    StackNode* ST_T = NULL;

    int ret = 0;

    while(ST_T != NULL || CT != NULL){
        if (CT != NULL){
            ret = 0;
            //ST_R = Push_Int(ST_R, ret);
            ST_T = Push_Tree(ST_T, CT);
            CT = CT -> left;
        }
        else{
            CT = Top_Tree(ST_T);

            if(Last_T != CT -> right && CT -> right != NULL){ // era sceso a sx, scendere a dx
                ret = Top_Int(ST_R);
                ST_R = Pop_Int(ST_R);
                if(CT -> data % 2 == 1){
                    ret++;
                }
                CT = CT -> right;
            }
            else{
                if(CT -> right == NULL){ //era sceso a sx, impossibile scendere a dx, terminare chiamata ricorsiva
                    ret = Top_Int(ST_R);
                    ST_R = Pop_Int(ST_R);
                    if(CT -> data % 2 == 1){
                        ret++;
                    }
                    ST_T = Pop_Tree(ST_T);
                    ST_R = Push_Int(ST_R, ret);
                    Last_T = CT;
                    CT = NULL;
                }
                else if(Last_T == CT -> right){ // era sceso a dx, terminare chiamata ricorsiva
                    ret += Top_Int(ST_R);
                    ST_T = Pop_Tree(ST_T);
                    ST_R = Push_Int(ST_R, ret);
                    Last_T = CT;
                    CT = NULL;
                }
            }
        }
    }
    return ret;
}

#pragma region Version 1
/*
** Version 1 works fine but does not match 1:1 what happens in
** the recursive version, because there's no stack for 'ret'
*/
int contadispari_iterativo_v1(Node* T){
    Node* CT = T;
    Node* Last_T = NULL;

    StackNode* ST_T = NULL;
    int ret = 0;

    while(ST_T != NULL || CT != NULL){
        if (CT != NULL){
            ST_T = Push_Tree(ST_T, CT);
            CT = CT -> left;
        }
        else{
            CT = Top_Tree(ST_T);

            if(Last_T != CT -> right && CT -> right != NULL){
                if(CT -> data % 2 == 1){
                    ret++;
                }
                CT = CT -> right;
            }
            else{
                if(CT -> right == NULL){
                    if(CT -> data % 2 == 1){
                        ret++;
                    }
                    ST_T = Pop_Tree(ST_T);
                    Last_T = CT;
                    CT = NULL;
                }
                else if(Last_T == CT -> right){
                    ST_T = Pop_Tree(ST_T);
                    Last_T = CT;
                    CT = NULL;
                }
            }
        }
    }
    return ret;
}

#pragma endregion

int main(void){
    printf("=== CONTA DISPARI ===\n\n");

    Node* T = NULL;
    T = Load_Tree();

    printf("\n\nIn order:\n\n");
    PrintInOrder(T);

    int result = contadispari(T);
    printf("\n\nResult (recursive call): %d\n", result);

    result = contadispari_iterativo_v1(T);
    printf("\n\nResult (iterative call [V1]): %d\n", result);

    result = contadispari_iterativo_v2(T);
    printf("\n\nResult (iterative call [V2]): %d\n", result);

    return 0;
}