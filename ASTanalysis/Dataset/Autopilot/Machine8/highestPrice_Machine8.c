int list_find_highest_price_item_position(node *head, int *pos) {
    int result = EXIT_SUCCESS;
    float highest_price = 0.0;
    node *current = head;
    int i = 0;

    while (current != NULL) {
        if (current->price > highest_price) {
            highest_price = current->price;
            *pos = i;
        }

        i++;
        current = current->next;
    }

    if (highest_price == 0.0) {
        result = EXIT_FAILURE;
    }

    return result;
}