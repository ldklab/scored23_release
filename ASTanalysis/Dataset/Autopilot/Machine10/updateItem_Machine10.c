int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        node *cur = *head;
        unsigned int k = 0;
        while (cur != NULL) {
            if (k == pos) {
                cur->item_name = malloc(strlen(item_name) + 1);
                if (cur->item_name == NULL) {
                    return EXIT_FAILURE;
                }
                strcpy(cur->item_name, item_name);
                cur->price = price;
                cur->quantity = quantity;
                return EXIT_SUCCESS;
            } else {
                k++;
                cur = cur->next;
            }
        }
        return EXIT_FAILURE;
    }
}