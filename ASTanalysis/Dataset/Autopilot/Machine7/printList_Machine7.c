int list_print(node *head) {
    // check for NULL pointer
    if (head == NULL) return EXIT_FAILURE;

    // check for empty list
    if (head->item_name == NULL) return EXIT_SUCCESS;

    // print list until last node
    int pos = 0;
    node *current = head;
    while (current->next != NULL) {
        char str[MAX_ITEM_PRINT_LEN + 1];
        list_item_to_string(current, str);
        printf("%d: %s\n", pos, str);
        current = current->next;
        pos++;
    }

    // print last node
    char str[MAX_ITEM_PRINT_LEN + 1];
    list_item_to_string(current, str);
    printf("%d: %s\n", pos, str);

    return EXIT_SUCCESS;
}