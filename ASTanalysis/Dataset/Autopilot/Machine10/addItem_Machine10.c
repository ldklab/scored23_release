int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        if (pos == 0) {
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL) {
                return EXIT_FAILURE;
            }
            new_node->item_name = malloc(strlen(item_name) + 1);
            if (new_node->item_name == NULL) {
                return EXIT_FAILURE;
            }
            new_node->price = price;
            new_node->quantity = quantity;
            new_node->next = *head;
            *head = new_node;
            return EXIT_SUCCESS;
        } else {
            node *cur = *head;
            node *new_node = malloc(sizeof(node));
            if (new_node == NULL) {
                return EXIT_FAILURE;
            }
            new_node->item_name = malloc(strlen(item_name) + 1);
            if (new_node->item_name == NULL) {
                return EXIT_FAILURE;
            }
            new_node->price = price;
            new_node->quantity = quantity;
            new_node->next = NULL;
            unsigned int k = 0;
            while (cur != NULL) {
                if (k == pos) {
                    new_node->next = cur->next;
                    cur->next = new_node;
                    return EXIT_SUCCESS;
                } else {
                    k++;
                    cur = cur->next;
                }
            }
            return EXIT_FAILURE;
        }
    }
}