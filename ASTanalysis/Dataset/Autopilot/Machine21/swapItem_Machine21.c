int list_swap_item_positions(node **head, int pos1, int pos2) {
    node *current = *head;
    node *prev = NULL;
    int i=0;
    while (current != NULL) {
        if (i+1==pos1) {
            if (prev==NULL) {
                *head = current->next;
                current->next = *head;
                *head = current;
                return EXIT_SUCCESS;
            }
            prev->next = current->next;
            current->next = *head;
            *head = current;
            return EXIT_SUCCESS;
        }
        if (i+1==pos2) {
            if (prev==NULL) {
                *head = current->next;
                current->next = *head;
                *head = current;
                return EXIT_SUCCESS;
            }
            prev->next = current->next;
            current->next = *head;
            *head = current;
            return EXIT_SUCCESS;
        }
        prev = current;
        current = current->next;
        i++;
    }
    return EXIT_FAILURE;
}