#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <time.h>
#include <limits.h>

#define NUMBER_OF_NODES 5

struct tree_node{
    int data;
    struct tree_node* left;
    struct tree_node* right;
};

struct stack_node_int{
    int data;
    struct stack_node_int* next;
};

struct stack_node_tree{
    struct node* data;
    struct stack_node_tree* next;
};

#pragma region Function definition

    #pragma region Tree

    struct tree_node* Load_Tree();
    int* Create_Vector_Of_Random_Numbers();
    struct tree_node* Create_Tree_From_Array(struct tree_node*, int, int*);
    void PrintInOrder(struct tree_node*);

    #pragma endregion // end Tree

    #pragma region Stack

        #pragma region Stack INT

        struct stack_node_int* Push_Int(struct stack_node_int*, int);
        int Top_Int(struct stack_node_int*);
        struct stack_node_int* Pop_Int(struct stack_node_int*);

        #pragma endregion //end Stack INT

        #pragma region Stack TREE

        struct stack_node_tree* Push_Tree(struct stack_node_tree*, struct node*);
        struct node* Top_Tree(struct stack_node_tree*);
        struct stack_node_tree* Pop_Tree(struct stack_node_tree*);

        #pragma endregion //end Stack TREE

    #pragma endregion //end Stack

#pragma endregion

#include "structures.c"
#endif
