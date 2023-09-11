int list_cost_sum(node *head, float *total) {
    // check for NULL pointer
    if (head == NULL || total == NULL) return EXIT_FAILURE;

    // check for empty list
    if (head->item_name == NULL) return EXIT_SUCCESS;

    // initialize total_cost
    float total_cost = 0.0;

    // calculate total_cost
    node *current = head;
    while (current->next != NULL) {
        total_cost += current->price * current->quantity;
        current = current->next;
    }
    total_cost += current->price * current->quantity;

    *total = total_cost;
    return EXIT_SUCCESS;
}