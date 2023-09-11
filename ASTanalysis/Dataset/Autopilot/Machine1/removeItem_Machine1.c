int list_remove_item_at_pos(node **head, int pos) {
    // check the list
    if (*head == NULL) {
        return EXIT_FAILURE;
    }
    // check the pos
    if (pos == 0) {
        return EXIT_FAILURE;
    }
    // if the pos is 1, remove the head
    if (pos == 1) {
        node *temp = (*head)->next;
        free((*head)->item_name);
        free(*head);
        *head = temp;
        return EXIT_SUCCESS;
    }
    // else, remove the tail
    node *tail = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (tail->next == NULL) {
            return EXIT_FAILURE;
        }
        tail = tail->next;
    }
    node *temp = tail->next->next;
    free(tail->next->item_name);
    free(tail->next);
    tail->next = temp;
    return EXIT_SUCCESS;
}