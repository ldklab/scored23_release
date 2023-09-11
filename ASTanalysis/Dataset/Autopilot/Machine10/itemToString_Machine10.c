int list_item_to_string(node *head, char *str) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        if (str == NULL) {
            return EXIT_FAILURE;
        } else {
            char *s = malloc(MAX_ITEM_PRINT_LEN);
            if (s == NULL) {
                return EXIT_FAILURE;
            }
            sprintf(s, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
            strcpy(str, s);
            free(s);
            return EXIT_SUCCESS;
        }
    }
}