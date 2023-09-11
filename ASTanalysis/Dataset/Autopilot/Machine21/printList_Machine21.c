int list_print(node *head) {
    node *current = head;
    int i=0;
    while (current != NULL) {
        printf("%d: %d * %s @ $%.2f ea\n", i, current->quantity, current->item_name, current->price);
        current = current->next;
        i++;
    }
    return EXIT_SUCCESS;
}