int list_print(node *head) {
    node *curr = head;
    int i = 1;
    while (curr != NULL) {
        char *str = malloc(MAX_ITEM_PRINT_LEN * sizeof(char));
        list_item_to_string(curr, str);
        printf("%d: %s\n", i, str);
        curr = curr->next;
        i++;
        free(str);
    }
    return EXIT_SUCCESS;
}