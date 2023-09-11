int list_print(node *head) {
    int result = EXIT_SUCCESS;

    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        node *current = head;
        int printed = 0;

        while (current != NULL) {
            char str[MAX_ITEM_PRINT_LEN];
            int item_name_len = strlen(current->item_name);
            int price_len = snprintf(NULL, 0, "%.2f", current->price);
            int quantity_len = snprintf(NULL, 0, "%d", current->quantity);
            int total_len = item_name_len + price_len + quantity_len + 12;

            if (total_len > MAX_ITEM_PRINT_LEN) {
                result = EXIT_FAILURE;
                break;
            } else {
                int printed = snprintf(str, total_len, "%d * %s @ $%.2f ea", current->quantity, current->item_name, current->price);

                if (printed != total_len) {
                    result = EXIT_FAILURE;
                    break;
                }

                printf("%s\n", str);
            }

            current = current->next;
        }
    }

    return result;
}