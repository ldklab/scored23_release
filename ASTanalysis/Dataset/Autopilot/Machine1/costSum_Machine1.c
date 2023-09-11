int list_cost_sum(node *head, float *total) {
    // check the list
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    // check the head
    if (head->next == NULL) {
        *total = head->price * head->quantity;
        return EXIT_SUCCESS;
    }
    // calculate the sum
    node *tail = head;
    float sum = head->price * head->quantity;
    while (tail->next != NULL) {
        sum = sum + tail->next->price * tail->next->quantity;
        tail = tail->next;
    }
    *total = sum;
    return EXIT_SUCCESS;
}