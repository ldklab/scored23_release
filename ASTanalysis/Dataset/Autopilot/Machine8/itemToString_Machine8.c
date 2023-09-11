int list_item_to_string(node *head, char *str) {
    int result = EXIT_SUCCESS;

    if (head == NULL) {
        strcpy(str, "The list is empty.");
    } else {
        int item_name_len = strlen(head->item_name);
        int price_len = snprintf(NULL, 0, "%.2f", head->price);
        int quantity_len = snprintf(NULL, 0, "%d", head->quantity);
        int total_len = item_name_len + price_len + quantity_len + 12;

        if (total_len > MAX_ITEM_PRINT_LEN) {
            result = EXIT_FAILURE;
            strcpy(str, "The item name is too long.");
        } else {
            int printed = snprintf(str, total_len, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);

            if (printed != total_len) {
                result = EXIT_FAILURE;
                strcpy(str, "The string was not filled completely.");
            }
        }
    }

    return result;
}