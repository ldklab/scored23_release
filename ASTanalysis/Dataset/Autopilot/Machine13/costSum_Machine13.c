int list_cost_sum(node *head, float *total) {
    *total = 0.0;
    while (head != NULL) {
        *total += head->price * (float)head->quantity;
        head = head->next;
    }
    return EXIT_SUCCESS;
}