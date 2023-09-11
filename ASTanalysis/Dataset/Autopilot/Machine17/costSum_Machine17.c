int list_cost_sum(node *head, float *total) {
    if (head == NULL) {
        printf("Error: list_cost_sum\n");
        return EXIT_FAILURE;
    }
    *total = 0.0;
    node *curr = head;
    while (curr!= NULL) {
        *total = *total + curr->price * curr->quantity;
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}