int list_deduplicate(node **head) {
    if (*head == NULL) {
        return EXIT_FAILURE;
    }

    int i = 1;
    node *current = *head;
    while (current != NULL) {
        int j = i + 1;
        node *current2 = current->next;
        while (current2 != NULL) {
            if (strcmp(current->item_name, current2->item_name) == 0) {
                current->quantity += current2->quantity;
                list_remove_item_at_pos(head, j);
            } else {
                j++;
            }
            current2 = current2->next;
        }
        i++;
        current = current->next;
    }
    return EXIT_SUCCESS;
}