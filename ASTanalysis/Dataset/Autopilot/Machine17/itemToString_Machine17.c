int list_item_to_string(node *head, char *str) {
    if (head == NULL || str == NULL) {
        printf("Error: list_item_to_string\n");
        return EXIT_FAILURE;
    }
    char buffer[MAX_ITEM_PRINT_LEN];
    snprintf(buffer, MAX_ITEM_PRINT_LEN, "%d * %s @ $%.2f ea",
             head->quantity, head->item_name, head->price);
    strcpy(str, buffer);
    return EXIT_SUCCESS;
}