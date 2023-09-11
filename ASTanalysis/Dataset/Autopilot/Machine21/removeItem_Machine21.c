int list_remove_item_at_pos(node **head, int pos) {
    node *current = *head;
    node *prev = NULL;
    int i=0;
    while (current != NULL) {
        if (i+1==pos) {
            if (prev==NULL) {
                *head = current->next;
                free(current);
                return EXIT_SUCCESS;
            }
            prev->next = current->next;
            free(current);
            return EXIT_SUCCESS;
        }
        prev = current;
        current = current->next;
        i++;
    }
    return EXIT_FAILURE;
}