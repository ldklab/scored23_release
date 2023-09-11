int list_remove_item_at_pos(node **head, int pos) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        node *cur = *head;
        node *prev = NULL;
        unsigned int k = 0;
        while (cur != NULL) {
            if (k == pos) {
                if (prev != NULL) {
                    prev->next = cur->next;
                    return EXIT_SUCCESS;
                } else {
                    *head = cur->next;
                    return EXIT_SUCCESS;
                }
            } else {
                k++;
                prev = cur;
                cur = cur->next;
            }
        }
        return EXIT_FAILURE;
    }
}