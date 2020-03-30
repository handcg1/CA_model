/*
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define SIZE 10
#define GENERATION 10


int cells[SIZE][SIZE];
bool done = false;

/* 
* Queue Implementation 
*/

struct node {

    int value;
    struct node *next;
   // int time; -> for keeping track of the times?
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
void initialize_queue(queue *new_queue)
{
    new_queue->node_count = 0;
    new_queue->front = NULL;
    new_queue->rear = NULL;
}

/*
 * check if queue is empty.
 */
bool empty_queue(queue *queue)
{
    return queue->rear == NULL && queue->front == NULL;
}

/*
 * add an element to queue.
 */
void enqueue(queue *queue, int num)
{
    node *new_node = malloc(sizeof(node));
    new_node->value = num;
    new_node->next = NULL;
    if (empty_queue(queue)) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->node_count++;
}

/*
 * remove an element from queue.
 */
int dequeue(queue *queue)
{
    if (empty_queue(queue)) {
        printf("ERROR: Attempting to delete an element from an empty queue.\n");
        return(EXIT_FAILURE);
    }
    node *node_to_delete;
    node_to_delete = queue->front;
    int node_value = node_to_delete->value;
    queue->front = queue->front->next;
    queue->node_count--;
    free(node_to_delete);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return node_value;
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
    //TODO: READ IN SIZE FROM COMMAND LINE
   // cells = new int[SIZE][SIZE];
    initialize();

    print();
    // clean up and return
    return (EXIT_SUCCESS);
}

