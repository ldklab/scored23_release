int list_cost_sum(node *head, float *total) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    float sum = 0;
    node *current = head;
    while (current != NULL) {
        sum += current->price * current->quantity;
        current = current->next;
    }
    *total = sum;
    return EXIT_SUCCESS;
}