int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (*head == NULL || pos1 == 0 || pos2 == 0) {
        return EXIT_FAILURE;
    }
    int cur_pos = 1;
    node *cur = *head;
    while (cur->next && cur_pos < pos1-1) {
        cur = cur->next;
        cur_pos++;
    }
    if (cur_pos == pos1-1) {
        node *temp = cur->next;
        cur->next = cur->next->next;
        cur = cur->next;
        cur_pos++;
        while (cur->next && cur_pos < pos2-1) {
            cur = cur->next;
            cur_pos++;
        }
        if (cur_pos == pos2-1) {
            node *temp2 = cur->next;
            cur->next = temp;
            temp->next = temp2->next;
            free(temp2->item_name);
            free(temp2);
        } else {
            return EXIT_FAILURE;
        }
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}