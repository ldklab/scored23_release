int list_deduplicate(node **head) {
    // check for NULL pointer
    if (head == NULL) return EXIT_FAILURE;

    // check for empty list
    if (*head == NULL) return EXIT_SUCCESS;

    node *current = *head;
    node *previous = NULL;
    while (current != NULL) {
        node *next = current->next;
        while (next != NULL) {
            if (strcmp(current->item_name, next->item_name) == 0) {
                current->price += next->price;
                current->quantity += next->quantity;
                current->next = next->next;
                free(next);
                next = current->next;
            } else {
                previous = current;
                current = next;
                next = next->next;
            }
        }
        previous = current;
        current = current->next;
    }

    return EXIT_SUCCESS;
}