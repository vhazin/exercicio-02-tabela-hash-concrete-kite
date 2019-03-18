#include <stdio.h>
#include <stdlib.h>

int* getInpiut();
int hashFunction();
void show();


struct node{
	int data;
	struct node * link;
};


int main() {

    int iterrations;
    int mod;
    int size;
    int* keys;
    struct node* addresses;

    scanf("%d", &iterrations);


    for(int i = 0; i < iterrations ; i++){

    	keys = getInpiut();
    	mod = keys[0];
    	size = keys[1];

    	addresses = (struct node*)malloc(sizeof(struct node) * mod);

    	for(int j = 2; j < size; j++){

    		int pos;
    		pos = hashFunction(mod, keys[j]);

    		if(addresses[pos].data == 0){
    			addresses[pos].data = keys[j];
    		}else{
    			
    			struct node *temp = (struct node*)malloc(sizeof(struct node));
    			if(addresses[pos].link == NULL){
    				addresses[pos].link = temp;
    				temp->data = keys[j];
    			}else{
    				struct node *p;
    				p = addresses[pos].link;
    				while(p->link != NULL){
    					p = p->link;
    				}
    				p->link = temp;
    				p->data = keys[j];
    			}

    		}

    	}

    	show(mod, addresses);
    }

    free(addresses);
    free(keys);

    return 0;

}


int* getInpiut() {
	int exit[2];
	int* keys;

	scanf("%d %d", &exit[0], &exit[1]);

	keys = malloc(sizeof(int) * exit[1] + 2);

	keys[0] = exit[0];
	keys[1] = exit[1];

	for(int i = 0; i < exit[1] ; i++){
		scanf("%d", &keys[i + 2]);
	}

	return keys;
}

int hashFunction(int modulator, int key){
	int address;
	address = key % modulator;
	return address;
}

void show(int size, struct node* addresses){

		for(int j = 0; j < size; j++){

    		if(addresses[j].data == 0){
    			printf("%d -> \\ \n",j);
    		}else{
    			if(addresses[j].link == NULL){
    				printf("%d -> %d -> \\ \n", j, addresses[j].data);
    			}else{
    				struct node *temp = addresses[j].link;
    				printf("%d -> %d ->", j, addresses[j].data);

    				while(temp != NULL){
    					printf(" %d ->",temp->data);
    					temp = temp -> link;
    				}

    				printf("\\ \n");
    				scanf("");
    			}
    		}

    	}

}


