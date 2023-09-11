int list_remove_item_at_pos(node **head, int pos) {
    if (*head == NULL) {
        return EXIT_FAILURE;
    }

    int i = 1;
    node *prev = NULL;
    node *current = *head;
    while (current != NULL) {
        if (i == pos) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->item_name);
            free(current);
            return EXIT_SUCCESS;
        }
        i++;
        prev = current;
        current = current->next;
    }
    return EXIT_FAILURE;
}