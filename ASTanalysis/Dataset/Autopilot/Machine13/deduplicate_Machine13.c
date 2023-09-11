int list_deduplicate(node **head) {
    node *curr = *head;
    while (curr != NULL) {
        node *prev = curr;
        node *dup = curr->next;
        while (dup != NULL) {
            if (strcmp(curr->item_name, dup->item_name) == 0) {
                curr->quantity += dup->quantity;
                prev->next = dup->next;
                free(dup->item_name);
                free(dup);
                dup = prev->next;
            } else {
                prev = dup;
                dup = dup->next;
            }
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}