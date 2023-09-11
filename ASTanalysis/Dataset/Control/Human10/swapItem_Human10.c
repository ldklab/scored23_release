int list_swap_item_positions(node **head, int pos1, int pos2) {
    node* n = *head;
    node* pos1_parent = NULL;
    node* pos2_parent = NULL;

    if (pos1 < 1 || pos2 < 1) return EXIT_FAILURE;
    if (pos1 == pos2) return EXIT_SUCCESS;

    pos1 = (pos1 < pos2) ? pos1 : pos2;
    pos2 = (pos2 < pos1) ? pos1 : pos2;

    int counter = 1;
    while(n != NULL) {
        if (counter == pos1-1) {
            pos1_parent = n;
        }
        if (counter == pos2-1) {
            pos2_parent = n;
        }
        n = n->next;
        counter++;
    }

    if (pos2_parent == NULL) return EXIT_FAILURE;

    node* node1 = NULL;
    node* node2 = pos2_parent->next;

    if (pos1_parent == NULL) {
        node1 = *head;
        *head = node2;
    }
    else {
        node1 = pos1_parent->next;
        pos1_parent->next = node2;
    }

    pos2_parent->next = node1;

    node* temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;

    return EXIT_SUCCESS;
}