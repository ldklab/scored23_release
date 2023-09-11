int list_print(node *head) {
    node *curr = head;
    int i = 0;
    char item_str[MAX_ITEM_PRINT_LEN];
    
    while (curr != NULL) {
        i++;
        list_item_to_string(curr, item_str);
        printf("%d: %s\n", i, item_str);
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}