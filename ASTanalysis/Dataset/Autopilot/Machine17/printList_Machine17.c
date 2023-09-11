int list_print(node *head) {
    if (head == NULL) {
        printf("Error: list_print\n");
        return EXIT_FAILURE;
    }
    int i = 0;
    while (head != NULL) {
        char buffer[MAX_ITEM_PRINT_LEN];
        snprintf(buffer, MAX_ITEM_PRINT_LEN, "%d: %s\n", i, head->item_name);
        printf("%s", buffer);
        i++;
        head = head->next;
    }
    return EXIT_SUCCESS;
}