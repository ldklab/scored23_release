int list_cost_sum(node *head, float *total) {
    *total = 0;
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    while (head) {
        *total += head->price * head->quantity;
        head = head->next;
    }
    return EXIT_SUCCESS;
}