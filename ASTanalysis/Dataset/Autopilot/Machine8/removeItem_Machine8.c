int list_remove_item_at_pos(node **head, int pos) {
    int result = EXIT_SUCCESS;
    node *prev = NULL;
    node *current = *head;
    int i = 0;

    if (pos == 0) {
        *head = current->next;
    } else {
        while (i < pos) {
            prev = current;
            current = current->next;
            i++;
        }

        prev->next = current->next;
    }

    free(current);

    return result;
}