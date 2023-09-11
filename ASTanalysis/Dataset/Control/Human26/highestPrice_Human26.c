int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // set pos of node item with highest price to 0 if list empty
    if (head == NULL) {
        *pos = 0;
        return EXIT_SUCCESS;
    }


    node* ptr = head;
    int highest_price = 0;
    int counter = 1;
    
    // loop through list
    while(ptr != NULL) {
        // new high price found
        if (ptr->price > highest_price) {
            highest_price = ptr->price;
            *pos = counter;
        }

        ptr = ptr->next;
        counter++;
    }

    return EXIT_SUCCESS;
}