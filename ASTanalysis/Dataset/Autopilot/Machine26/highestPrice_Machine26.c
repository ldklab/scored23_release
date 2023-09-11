int list_find_highest_price_item_position(node *head, int *pos) {
    if (head == NULL) {
        *pos = 0;
        return EXIT_FAILURE;
    }
    *pos = 1;
    int cur_pos = 1;
    float max_price = head->price;
    node *cur = head->next;
    while (cur) {
        if (cur->price > max_price) {
            *pos = cur_pos+1;
            max_price = cur->price;
        }
        cur = cur->next;
        cur_pos++;
    }
    return EXIT_SUCCESS;
}