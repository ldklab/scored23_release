int list_deduplicate(node **head) {
    node *curr = *head;
    node *prev = NULL;
    while (curr != NULL) {
        node *check = curr->next;
        prev = curr;
        while (check != NULL) {
            if (strcmp(curr->item_name, check->item_name) == 0) {
                curr->quantity += check->quantity;
                prev->next = check->next;
                free(check->item_name);
                free(check);
                check = prev->next;
            } else {
                check = check->next;
                prev = prev->next;
            }
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}