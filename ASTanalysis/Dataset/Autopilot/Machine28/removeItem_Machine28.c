int list_remove_item_at_pos(node **head, int pos) {
    node *curr = *head;
    node *prev = NULL;
    int i = 1;

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    if (pos == 0) {
        *head = curr->next;
        free(curr->item_name);
        free(curr);
        return EXIT_SUCCESS;
    }

    while (curr != NULL) {
        if (i == pos) {
            prev->next = curr->next;
            free(curr->item_name);
            free(curr);
            return EXIT_SUCCESS;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    return EXIT_FAILURE;
}