int list_cost_sum(node *head, float *total) {
    int result = EXIT_SUCCESS;
    node *current = head;
    *total = 0.0;

    while (current != NULL) {
        *total += (current->price * current->quantity);
        current = current->next;
    }

    return result;
}