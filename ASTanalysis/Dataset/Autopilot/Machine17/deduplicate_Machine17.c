int list_deduplicate(node **head) {
    if (head == NULL) {
        printf("Error: list_deduplicate\n");
        return EXIT_FAILURE;
    }
    node *curr = *head;
    node *prev = NULL;
    while (curr!= NULL) {
        node *tmp = curr->next;
        while (tmp!= NULL) {
            if (strcmp(curr->item_name, tmp->item_name) == 0) {
                curr->quantity = curr->quantity + tmp->quantity;
                if (prev == NULL) {
                    *head = curr->next;
                } else {
                    prev->next = curr->next;
                }
                free(tmp);
                tmp = curr->next;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return EXIT_SUCCESS;
}