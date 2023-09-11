int list_cost_sum(node *head, float *total)
{
    float total = 0;
    while (head != NULL) {
        total += *head->price * head->quantity;
    }

    return EXIT_SUCCESS;
}