int list_find_highest_price_item_position(node *head, int *pos) {
    int max = 0;
    int curr_pos = 0;
    int i = 1;
    node *curr = head;
    while (curr != NULL) {
        if (curr->price > max) {
            max = curr->price;
            curr_pos = i;
        }
        curr = curr->next;
        i++;
    }
    *pos = curr_pos;
    return EXIT_SUCCESS;
}