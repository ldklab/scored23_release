int list_print(node *head) {
    int counter = 1;
    while (head != NULL) {
        printf("%d: %d * %s @ $%.2f ea\n", counter, head->quantity, head->item_name, head->price);
        head = head->next;
        counter++;
    }
    return EXIT_SUCCESS;
}