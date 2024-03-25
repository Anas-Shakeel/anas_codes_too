#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct node
{
    int data;
    struct node *next;
} node;

// Function Prototypes
node *neighbors(int array[], int array_len, int index, int count);
void free_list(node *list);

int main(void)
{
    // Array initialization
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = (int)(sizeof(arr) / sizeof(int));

    // Find the neighbors (returns address to linked list)
    node *list = neighbors(arr, len, 7, 2);
    if (list == NULL)
    {
        printf("`neighbors`: Invalid args passed.");
        return 1;
    }

    // Traverse the linked-list and print the neighbors
    node *cursor = list;
    while (cursor != NULL)
    {
        printf("%i\n", cursor->data);
        cursor = cursor->next;
    }

    // Free the linked-list (to avoid memory leaks)
    free_list(list);
    return 0;
}

node *neighbors(int array[], int array_len, int index, int count)
{
    // Count must not be greater than index
    if ((count > index) || ((index + count + 1) > array_len))
    {
        return NULL;
    }

    // Find neighbors
    node *list = NULL;
    for (int i = 1; i <= count; i++)
    {
        // Store the Right neighbor in the node
        node *node_right = malloc(sizeof(node));
        node_right->data = array[index + i];
        node_right->next = list; // Point to list

        // Store the Left neighbor in the node
        node *node_left = malloc(sizeof(node));
        node_left->data = array[index - i];
        node_left->next = node_right; // Point to node_right
        list = node_left;
    }

    return list;
}

void free_list(node *list)
{
    // Traverse the linked-list and free every node
    node *cursor = list;
    while (cursor != NULL)
    {
        // Set the temp to cursor
        node *temp = cursor;
        cursor = cursor->next;
        // Free temp
        free(temp);
    }
}

// Neighbors in 1D array
/*
Find x neighbors in an array

neighbors(array[], x_neighbors, index)
    array     : is the array in which to find the neighbors
    array_len : is the length of the array
    count     : is the number of neighbors to find
    index     : is the index of the value of which to find the neighbors

 */
