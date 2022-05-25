#ifndef STRUCTURES_C
#define STRUCTURES_C

#pragma region Tree

struct tree_node* Load_Tree(){
    int* vector_of_random_numbers = Create_Vector_Of_Random_Numbers();
    struct tree_node* root = Create_Tree_From_Array(NULL, 0, vector_of_random_numbers);

    return root;
}

int* Create_Vector_Of_Random_Numbers(){
    int* array = malloc(NUMBER_OF_NODES * sizeof(int));
    int iterator;
    srand(time(0));

    printf("%s","Elements in the tree (breadth order): ");
    for(iterator = 0 ; iterator < NUMBER_OF_NODES ; ++iterator){
        array[iterator] = rand()%100;
        printf(" %d " , array[iterator]);
    }

    return array;
}

struct tree_node* Create_Tree_From_Array(struct tree_node* root, int index, int* vector_of_random_numbers){
    if(index < NUMBER_OF_NODES){
        root = malloc(sizeof(struct tree_node));
        root->data = vector_of_random_numbers[index];
        root->left = NULL;
        root->right = NULL;

        root->left = Create_Tree_From_Array(root->left, 2*index+1, vector_of_random_numbers);
        root->right = Create_Tree_From_Array(root->right, 2*index+2, vector_of_random_numbers);

        return root;
    }
}

void PrintInOrder(struct tree_node* root){
    if(root != NULL){
        PrintInOrder(root->left);
        printf(" %d " , root->data);
        PrintInOrder(root->right);
    }
}
#pragma endregion

#pragma region Stack

    #pragma region Stack INT

    struct stack_node_int* Push_Int(struct stack_node_int* s, int value){
        struct stack_node_int* newnode = malloc(sizeof(struct stack_node_int));
        newnode->data = value;
        newnode->next = s;
        return newnode;
    }

    int Top_Int(struct stack_node_int* s){
        if(s == NULL) 
            return INT_MIN;
        else
            return s->data;
    }

    struct stack_node_int* Pop_Int(struct stack_node_int* s){
        if(s == NULL)
            return NULL;
        else{
            struct stack_node_int* next = s->next;
            free(s);
            return next;
        }
    }

    #pragma endregion // end Stack INT

    #pragma region Stack TREE

    struct stack_node_tree* Push_Tree(struct stack_node_tree* s, struct node* value){
        struct stack_node_tree* newnode = malloc(sizeof(struct stack_node_tree));
        newnode->data = value;

        newnode->next = s;
        return newnode;
    }

    struct node* Top_Tree(struct stack_node_tree* s){
        if(s == NULL) 
            return NULL;
        else
            return s->data;
    }

    struct stack_node_tree* Pop_Tree(struct stack_node_tree* s){
        if(s == NULL)
            return NULL;
        else{
            struct stack_node_tree* next = s->next;
            free(s);
            return next;
        }
    }

    #pragma endregion // end stack TREE

#pragma endregion // end Stack
#endif