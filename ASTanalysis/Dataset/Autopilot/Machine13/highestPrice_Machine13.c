int list_find_highest_price_item_position(node *head, int *pos) {
    *pos = 0;
    float max = 0.0;
    while (head != NULL) {
        float price = head->price * (float)head->quantity;
        if (price > max) {
            max = price;
            *pos = 1;
        } else {
            (*pos)++;
        }
        head = head->next;
    }
    return EXIT_SUCCESS;
}