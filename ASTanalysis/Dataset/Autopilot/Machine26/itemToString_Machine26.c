int list_item_to_string(node *head, char *str) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    int ret = snprintf(str, MAX_ITEM_PRINT_LEN, "%d * %s @ $%.2f ea",
                        head->quantity, head->item_name, head->price);
    if (ret >= MAX_ITEM_PRINT_LEN) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}