int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *curr = *head;
    node *prev = NULL;
    int i = 1;

    if (head == NULL || item_name == NULL) {
        return EXIT_FAILURE;
    }

    if (pos == 0) {
        node *new = malloc(sizeof(node));
        new->item_name = malloc(strlen(item_name) * sizeof(char) + 1);
        memset(new->item_name, 0, strlen(item_name) * sizeof(char) + 1);
        strcpy(new->item_name, item_name);
        new->price = price;
        new->quantity = quantity;
        new->next = *head;
        *head = new;
        return EXIT_SUCCESS;
    }

    while (curr != NULL) {
        if (i == pos) {
            node *new = malloc(sizeof(node));
            new->item_name = malloc(strlen(item_name) * sizeof(char) + 1);
            memset(new->item_name, 0, strlen(item_name) * sizeof(char) + 1);
            strcpy(new->item_name, item_name);
            new->price = price;
            new->quantity = quantity;
            new->next = curr;
            if (prev != NULL) {
                prev->next = new;
            }
            return EXIT_SUCCESS;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    return EXIT_FAILURE;
}