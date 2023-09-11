int list_print(node *head) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    int pos = 1;
    node *current = head;
    while (current != NULL) {
        float price_rounded = (float) (int) (current->price * 100) / 100.0;
        printf("%d: %d * %s @ $%.2f ea\n", pos, current->quantity, 
            current->item_name, price_rounded);
        pos++;
        current = current->next;
    }

    return EXIT_SUCCESS;
}