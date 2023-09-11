int list_find_highest_price_item_position(node *head, int *pos) {
    node *current = head;
    int i=0, j=0;
    float max_price=0.0;
    while (current != NULL) {
        float f = current->price;
        if (f>=max_price) {
            max_price = f;
            j=i;
        }
        current = current->next;
        i++;
    }
    *pos = j;
    return EXIT_SUCCESS;
}