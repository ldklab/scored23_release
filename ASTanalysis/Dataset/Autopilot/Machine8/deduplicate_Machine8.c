int list_deduplicate(node **head) {
    int result = EXIT_SUCCESS;
    node *current = *head;
    node *prev = NULL;
    node *next = NULL;

    while (current != NULL) {
        next = current->next;

        while (next != NULL) {
            if (strcmp(current->item_name, next->item_name) == 0) {
                current->quantity += next->quantity;
                current->price += next->price;
                free(next);
                next = current->next;
            } else {
                prev = next;
                next = next->next;
            }
        }

        current = current->next;
    }

    return result;
}