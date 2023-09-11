int list_print(node *head) {
    struct _node *curr = head;
    int counter = 1;
    while (!(curr == NULL)){
        printf("%d: %d * %s @ $%.2f ea\n", counter, curr->quantity, curr->item_name, curr->price);
        counter += 1;
        curr = curr->next;
    }
    return EXIT_SUCCESS;
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}