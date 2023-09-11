int list_find_highest_price_item_position(node *head, int *pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    node *current = head;
    int cur_pos = 1;
    int highest_price_pos = 1;
    float highest_price = current->price;
    while (current != NULL) {
        if (current->price > highest_price) {
            highest_price_pos = cur_pos;
            highest_price = current->price;
        }
        current = current->next;
        cur_pos++;
    }

    *pos = highest_price_pos;
    return EXIT_SUCCESS;
}