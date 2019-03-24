#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printQueue(); 
int hash();
void show();

struct head{
    struct node * first;
    int size;
    struct node * last;
};

struct node{
    int data;
    struct node * link;
};

int main() {

    int iter;
    int mod;
    int size;
    int* keys;

    scanf("%d", &iter);


    for(int i = 0; i < iter ; i++){

        int* keys;

        scanf("%d %d", &mod, &size);

        keys = malloc(sizeof(int) * size);


        for(int j = 0; j < size ; j++){
            scanf("%d", &keys[j]);
        }



        struct head * roots = (struct head *)malloc(sizeof(struct head) * mod);


        for (int j = 0; j < size; ++j){
            
            struct node * newnode;
            newnode = (struct node *)malloc(sizeof(struct node));

            newnode->data = keys[j];
            int pos = hash(mod, keys[j]);

            if(roots[pos].first == NULL){
                roots[pos].first = newnode;
                roots[pos].last = newnode;

            }else{
                roots[pos].last->link = newnode;
                roots[pos].last = newnode;

            }

        }

        for (int j = 0; j < mod; j++){
            printf("%d -> ", j);
            printQueue(roots[j].first);
        }

        printf("\n");


    }


    return 0;

}


int printQueue(struct node * root){

    struct node * temp = root;

    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->link;
    }
    printf("\\ \n");
    return 1;
    

}


int hash(int modulator, int key){
	int address;
	address = key % modulator;
	return address;
}



