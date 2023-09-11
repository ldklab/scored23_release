int list_cost_sum(node *head, float *total)
{
    float sum = 0;

    while (head != NULL) {
        sum += head->price * head->quantity;
        head = head->next;
    }

    *total = sum;

    return EXIT_SUCCESS;
}