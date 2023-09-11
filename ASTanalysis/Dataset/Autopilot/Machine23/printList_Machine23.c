int list_print(node *head) {
    // check if node is null
    if (head == NULL) {
        fprintf(stderr, "list_print: node is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    int pos = 1;
    node *current = head;
    while (current != NULL) {
        char item_str[MAX_ITEM_PRINT_LEN];
        list_item_to_string(current, item_str);
        printf("%d: %s\n", pos, item_str);

        pos++;
        current = current->next;
    }

    return EXIT_SUCCESS;
}