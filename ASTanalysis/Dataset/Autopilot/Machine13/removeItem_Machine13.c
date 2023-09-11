int list_remove_item_at_pos(node **head, int pos) {
    if (pos == 1) {
        node *curr = *head;
        *head = curr->next;
        free(curr->item_name);
        free(curr);
        return EXIT_SUCCESS;
    }
    node *prev = *head;
    node *curr = *head;
    while (curr != NULL && pos > 1) {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    prev->next = curr->next;
    free(curr->item_name);
    free(curr);
    return EXIT_SUCCESS;
}