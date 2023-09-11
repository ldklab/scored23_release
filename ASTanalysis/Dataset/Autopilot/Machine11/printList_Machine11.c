int list_print(node *head) {
    int i = 1; 
    while (head != NULL) {
        char line[MAX_ITEM_PRINT_LEN];
        list_item_to_string(head, line);
        printf("%d: %s\n", i, line);
        i++;
        head = head->next;
    }
    return EXIT_SUCCESS;
}