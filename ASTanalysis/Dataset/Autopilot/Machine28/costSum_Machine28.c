int list_cost_sum(node *head, float *total) {
    float sum = 0;
    node *curr = head;
    while (curr != NULL) {
        sum += curr->price * curr->quantity;
        curr = curr->next;
    }
    *total = sum;
    return EXIT_SUCCESS;
}