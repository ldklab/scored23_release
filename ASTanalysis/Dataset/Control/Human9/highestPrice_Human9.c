int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // alter *pos
    node *curr = head;
    int i = 1;
    int highest_price = 0;
    *pos = 1;

    if (curr == NULL) {
        *pos = 0;
        printf("Need to pass in a singly linked list with items!\n")
        return EXIT_FAILURE;
    }
    // go through list
    while (curr != NULL) {
        if (highest_price < curr->price) {
            highest_price = curr->price;
            *pos = i;
        }
        curr = curr->next;
        i++;
    }
    return EXIT_SUCCESS;
}