int list_cost_sum(node *head, float *total) {
    node *current = head;
    float f = 0.0;
    while (current != NULL) {
        f += current->quantity*current->price;
        current = current->next;
    }
    *total = f;
    return EXIT_SUCCESS;
}