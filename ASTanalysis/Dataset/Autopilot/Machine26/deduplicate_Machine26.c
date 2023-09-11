int list_deduplicate(node **head) {
    if (*head == NULL) {
        return EXIT_FAILURE;
    }
    node *cur = *head;
    node *prev = cur;
    while (cur->next) {
        if (strcmp(cur->item_name, cur->next->item_name) == 0) {
            cur->quantity += cur->next->quantity;
            node *temp = cur->next;
            cur->next = cur->next->next;
            free(temp->item_name);
            free(temp);
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return EXIT_SUCCESS;
}