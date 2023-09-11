int list_print(node *head) {
    int count = 1;
    char str[MAX_ITEM_PRINT_LEN];
    while (head != NULL) {
        list_item_to_string(head, str);
        printf("%d: %s\n", count, str);
        count++;
        head = head->next;
    }
    return EXIT_SUCCESS;
}