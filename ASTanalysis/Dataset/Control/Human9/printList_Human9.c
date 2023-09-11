int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = head;
    int pos = 1;
    if (curr == NULL) {
        print("Need to pass in a singly linked list!\n");
        return EXIT_FAILURE;
    }
    while (curr != NULL) {
        printf("%i: %i * %s @ $%.2f ea\n", pos, head->quantity, head->item_name, head->price);
        curr = curr->next;
        pos++;
    }
    return EXIT_SUCCESS;
}