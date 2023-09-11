int list_print(node *head) {
    int pos = 1;
    node * current = head;
    while (current != NULL)
    {
        printf("%d: %d * %s @ $%f ea\n", pos, current->quantity, current->item_name, current->price);
        current = current->next;
        pos++;
    }
    return EXIT_SUCCESS;
}