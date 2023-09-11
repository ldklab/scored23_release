int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (*head == NULL || pos == 0) {
        return EXIT_FAILURE;
    }
    int cur_pos = 1;
    node *cur = *head;
    while (cur->next && cur_pos < pos) {
        cur = cur->next;
        cur_pos++;
    }
    if (cur_pos == pos) {
        free(cur->item_name);
        cur->item_name = malloc(strlen(item_name) + 1);
        strcpy(cur->item_name, item_name);
        cur->price = price;
        cur->quantity = quantity;
    } else {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}