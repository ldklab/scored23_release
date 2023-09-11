int list_find_highest_price_item_position(node *head, int *pos) {
    if (head == NULL) {
        printf("Error: list_find_highest_price_item_position\n");
        return EXIT_FAILURE;
    }
    node *curr = head;
    *pos = 0;
    float max = 0.0;
    while (curr!= NULL) {
        if (curr->price > max) {
            max = curr->price;
            *pos = *pos + 1;
        }
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}