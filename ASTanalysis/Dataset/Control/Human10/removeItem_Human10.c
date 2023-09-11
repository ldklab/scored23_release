int list_remove_item_at_pos(node **head, int pos)
{    
    node* n = *head;
    int counter = 1;

    if (pos == 1) {
        *head = n->next;
        free(n);
        return EXIT_SUCCESS;
    }

    while (n != NULL) {
        if (counter == pos-1) {
            node* next_node = n->next;
            n->next = next_node->next;
            free(next_node);
            return EXIT_SUCCESS;
        }
        n = n->next;
        counter++;
    }

    return EXIT_FAILURE;
}