int list_remove_item_at_pos(node **head, int pos) {
    if (head == NULL) {
        printf("Error: list_remove_item_at_pos\n");
        return EXIT_FAILURE;
    }
    node *curr = *head;
    node *prev = NULL;
    while (curr!= NULL) {
        if (pos == 0) {
            if (prev == NULL) {
                *head = curr->next;
                free(curr);
                return EXIT_SUCCESS;
            }
            prev->next = curr->next;
            free(curr);
            return EXIT_SUCCESS;
        }
        pos--;
        prev = curr;
        curr = curr->next;
    }
    printf("Error: list_remove_item_at_pos\n");
    return EXIT_FAILURE;
}