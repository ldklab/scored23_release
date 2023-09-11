int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // pos must be an integer >= 1
    if (pos < 1) {
        return EXIT_FAILURE;
    }

    int counter = 1;
    node* ptr = *head;

    // loop until ptr points to item or ptr reaches end of list
    while(ptr != NULL && counter < pos) {
        ptr = ptr->next;
        counter++;
    }

    // end of list, ptr is NULL, cannot modify non-existing item
    if (ptr == NULL) {
        return EXIT_FAILURE;
    }

    // update existing item
    free(ptr->item_name);
    ptr->item_name = malloc(strlen(item_name) + 1);
    strcpy(ptr->item_name, item_name);
    ptr->price = price;
    ptr->quantity = quantity;

    return EXIT_SUCCESS;
}