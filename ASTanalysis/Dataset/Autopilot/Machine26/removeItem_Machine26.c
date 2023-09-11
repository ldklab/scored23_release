int list_remove_item_at_pos(node **head, int pos) {
    if (*head == NULL || pos == 0) {
        return EXIT_FAILURE;
    }
    int cur_pos = 1;
    node *cur = *head;
    while (cur->next && cur_pos < pos-1) {
        cur = cur->next;
        cur_pos++;
    }
    if (cur_pos == pos-1) {
        node *temp = cur->next;
        cur->next = cur->next->next;
        free(temp->item_name);
        free(temp);
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}