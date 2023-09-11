int list_find_highest_price_item_position(node *head, int *pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        int max = 0;
        node *cur = head;
        unsigned int k = 0;
        while (cur != NULL) {
            if (cur->price > max) {
                max = cur->price;
                *pos = k;
            }
            k++;
            cur = cur->next;
        }
        return EXIT_SUCCESS;
    }
}