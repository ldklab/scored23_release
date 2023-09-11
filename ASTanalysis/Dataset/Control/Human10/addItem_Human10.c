int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    node* n = *head;
    node* new_node = NULL;
    int counter = 1;

    if (pos == 1) {
        new_node = malloc(sizeof(struct _node));
        new_node->item_name = item_name;
        new_node->price = price;
        new_node->quantity = quantity;
        new_node->next = n;
        *head = new_node;
        return EXIT_SUCCESS;
    }

    while (n != NULL) {
        if (counter == pos-1) {
            new_node = malloc(sizeof(struct _node));
            new_node->item_name = item_name;
            new_node->price = price;
            new_node->quantity = quantity;
            new_node->next = n->next;
            n->next = new_node;
            return EXIT_SUCCESS;
        }
        n = n->next;
        counter++;
    }
    return EXIT_FAILURE;
}