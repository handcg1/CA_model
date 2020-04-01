/*
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 10
#define GENERATION 10

bool done = false;

int cells[SIZE][SIZE];


/* 
* Queue Implementation 
*/

struct node {
    int value;
    struct node *next;
};
typedef struct node node;

// queue struct
struct queue {

    int node_count;
    node *front;
    node *rear;

};
typedef struct queue queue;

/*
 * initialize queue.
 */
struct queue* initialize_queue()
{
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    queue -> front = queue -> rear = NULL;
    return queue;
}

/*
 * check if queue is empty.
 */
bool empty_queue(queue *queue)
{
    return queue->rear == NULL && queue->front == NULL;
}

struct node* new_node(int num)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node)); 
    tmp->value = num; 
    tmp->next = NULL; 
    return tmp; 
}

/*
 * add an element to queue.
 */
void enqueue(queue *queue, int num)
{

    struct node *tmp = new_node(num);


  if (queue->rear == NULL) { 
        queue->front = queue->rear = tmp; 
        return; 
    } 
 
    queue->rear->next = tmp; 
    queue->rear = tmp;

    queue->node_count++;
}

/*
 * remove an element from queue.
 */
void dequeue(queue *queue)
{
    if (empty_queue(queue)) {
        printf("ERROR: Attempting to delete an element from an empty queue.\n");
    }

    struct node* tmp = queue->front;

    queue->front = queue->front->next; 

    queue->node_count--;

    free(tmp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

void print_queue(queue *queue)
{
    printf("Queue: ");

    struct node *current_node = queue->front;

    while(current_node != NULL)
    {

        printf("%d ", current_node->value);
        current_node = current_node-> next; 
    }
    
}

// INITIALIZE EACH CELL TO 0 OR 1
void initialize() {

    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < SIZE; j++) {

               cells[i][j] = (rand() % (11 - 10 + 1) + 10) - 10;  

        }

    }

}
/*
// COMPUTE NEXT GENERATION OF CELL
int[][] update() {

    int next_step[SIZE][SIZE] = new int[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            next_step[i][j] = check_neighbors(
    
        }

    }


}
*/


void print() {

    printf("\n");
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            printf(" %d ", cells[x][y]);
   
       }
    printf("\n");
    }

}




int main(int argc, char* argv[])
{

    struct queue *test = initialize_queue();
    enqueue(test, 4);
    enqueue(test,9);
    enqueue(test,10);
    enqueue(test,-2);
    dequeue(test);

    print_queue(test);
    // test = malloc(sizeof(queue));
   // initialize_queue(test);

   //enqueue(test,3);
   //enque(test,6);

 //  printf("test %d\n", test[1]);

    

    
    //TODO: READ IN SIZE FROM COMMAND LINE
   // cells = new int[SIZE][SIZE];
    initialize();

    print();
    // clean up and return
    return (EXIT_SUCCESS);
}

