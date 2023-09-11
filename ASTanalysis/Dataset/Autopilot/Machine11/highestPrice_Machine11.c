int list_find_highest_price_item_position(node *head, int *pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    int i = 1;
    int max_price_pos = 1;
    node *current = head;
    while (current != NULL) {
        if (current->price >= head->price) {
            max_price_pos = i;
        }
        i++;
        current = current->next;
    }
    *pos = max_price_pos;
    return EXIT_SUCCESS;
}