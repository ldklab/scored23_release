int list_remove_item_at_pos(node **head, int pos) {
    if (pos <= 0) {
        return EXIT_FAILURE;
    }

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    node *prev = NULL;
    node *current = *head;
    int i = 1;
    while (current != NULL && i < pos) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}