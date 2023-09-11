int list_cost_sum(node *head, float *total) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        node *cur = head;
        *total = 0;
        while (cur != NULL) {
            *total += cur->price * cur->quantity;
            cur = cur->next;
        }
        return EXIT_SUCCESS;
    }
}