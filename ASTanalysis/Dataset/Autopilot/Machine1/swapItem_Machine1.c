int list_swap_item_positions(node **head, int pos1, int pos2) {
    // check the list
    if (*head == NULL) {
        return EXIT_FAILURE;
    }
    // check the pos
    if (pos1 == 0 || pos2 == 0) {
        return EXIT_FAILURE;
    }
    // if the pos is 1, swap the head
    if (pos1 == 1 && pos2 == 1) {
        node *tail = *head;
        for (int i = 1; i < pos2 - 1; i++) {
            if (tail->next == NULL) {
                return EXIT_FAILURE;
            }
            tail = tail->next;
        }
        node *temp = *head;
        *head = tail->next;
        tail->next = temp;
        return EXIT_SUCCESS;
    }
    // else, swap the tail
    node *tail1 = *head;
    for (int i = 1; i < pos1 - 1; i++) {
        if (tail1->next == NULL) {
            return EXIT_FAILURE;
        }
        tail1 = tail1->next;
    }
    node *tail2 = *head;
    for (int i = 1; i < pos2 - 1; i++) {
        if (tail2->next == NULL) {
            return EXIT_FAILURE;
        }
        tail2 = tail2->next;
    }
    node *temp = tail1->next;
    tail1->next = tail2->next;
    tail2->next = temp;
    return EXIT_SUCCESS;
}