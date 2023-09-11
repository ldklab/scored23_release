int list_print(node *head) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    int pos = 1;
    while (head) {
        char buf[MAX_ITEM_PRINT_LEN];
        list_item_to_string(head, buf);
        printf("%d: %s\n", pos, buf);
        head = head->next;
        pos++;
    }
    return EXIT_SUCCESS;
}