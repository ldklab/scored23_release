int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    int result = EXIT_SUCCESS;
    node *current = *head;
    node *prev = NULL;
    int i = 0;

    if (pos == 0) {
        current->item_name = (char *)malloc(strlen(item_name) + 1);
        strcpy(current->item_name, item_name);
        current->price = price;
        current->quantity = quantity;
    } else {
        while (i < pos) {
            prev = current;
            current = current->next;
            i++;
        }

        current->item_name = (char *)malloc(strlen(item_name) + 1);
        strcpy(current->item_name, item_name);
        current->price = price;
        current->quantity = quantity;
    }

    return result;
}