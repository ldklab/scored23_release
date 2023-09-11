int list_remove_item_at_pos(node **head, int pos) {
    node *curr, *prev;
    int i;
    
    // check for invalid inputs
    if (head == NULL) return EXIT_FAILURE;
    
    // check if the list is empty
    if (*head == NULL) return EXIT_FAILURE;
    
    // check if the position is past the size of the list
    if (pos == 0) {
        curr = *head;
        *head = curr->next;
        free(curr);
        return EXIT_SUCCESS;
    }
    
    curr = *head;
    for (i = 1; i < pos; i++) {
        if (curr->next == NULL) return EXIT_FAILURE;
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
    free(curr);
    
    return EXIT_SUCCESS;
}