int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *curr = *head;
    int i = 1;

    if (head == NULL || item_name == NULL) {
        return EXIT_FAILURE;
    }

    while (curr != NULL) {
        if (i == pos) {
            curr->item_name = realloc(curr->item_name, strlen(item_name) * sizeof(char) + 1);
            memset(curr->item_name, 0, strlen(item_name) * sizeof(char) + 1);
            strcpy(curr->item_name, item_name);
            curr->price = price;
            curr->quantity = quantity;
            return EXIT_SUCCESS;
        }
        curr = curr->next;
        i++;
    }
    return EXIT_FAILURE;
}