int list_deduplicate(node **head) {
    // check if node is null
    if (*head == NULL) {
        fprintf(stderr, "list_deduplicate: node is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    node *current = *head;
    node *previous = NULL;
    while (current != NULL) {
        node *next = current->next;
        if (next != NULL && strcmp(current->item_name, next->item_name) == 0) {
            current->quantity += next->quantity;
            if (previous == NULL) {
                *head = next->next;
            } else {
                previous->next = next->next;
            }
            free(next);
        } else {
            previous = current;
        }
        current = next;
    }

    return EXIT_SUCCESS;
}