int list_cost_sum(node *head, float *total) {
    // check if node is null
    if (head == NULL) {
        fprintf(stderr, "list_cost_sum: node is null\n");
        return EXIT_FAILURE;
    }

    // check if string is null
    if (total == NULL) {
        fprintf(stderr, "list_cost_sum: total is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    float sum = 0.0;
    node *current = head;
    while (current != NULL) {
        sum += current->price * current->quantity;
        current = current->next;
    }

    *total = sum;

    return EXIT_SUCCESS;
}