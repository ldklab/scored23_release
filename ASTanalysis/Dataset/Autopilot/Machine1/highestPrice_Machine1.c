int list_find_highest_price_item_position(node *head, int *pos) {
    // check the list
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    // check the head
    if (head->next == NULL) {
        if (pos != NULL) {
            *pos = 1;
        }
        return EXIT_SUCCESS;
    }
    // find the position with the highest single price
    node *tail = head;
    float highest_price = head->price;
    (*pos) = 1;
    for (int i = 1; tail != NULL; i++) {
        if (tail->price > highest_price) {
            highest_price = tail->price;
            (*pos) = i + 1;
        }
        tail = tail->next;
    }
    return EXIT_SUCCESS;
}