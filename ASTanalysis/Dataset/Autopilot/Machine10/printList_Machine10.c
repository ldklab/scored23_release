int list_print(node *head) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        node *cur = head;
        char *s = malloc(MAX_ITEM_PRINT_LEN);
        if (s == NULL) {
            return EXIT_FAILURE;
        }
        printf("%s", "");
        while (cur->next != NULL) {
            list_item_to_string(cur, s);
            printf("%s", s);
            printf("\n");
            cur = cur->next;
        }
        free(s);
        return EXIT_SUCCESS;
    }
}