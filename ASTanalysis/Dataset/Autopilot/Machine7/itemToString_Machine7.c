int list_item_to_string(node *head, char *str) {
    // check for NULL pointer
    if (head == NULL || str == NULL) return EXIT_FAILURE;

    // check for empty list
    if (head->item_name == NULL) return EXIT_SUCCESS;

    // print item_name
    char item_name[MAX_ITEM_PRINT_LEN + 1];
    strncpy(item_name, head->item_name, MAX_ITEM_PRINT_LEN);
    item_name[MAX_ITEM_PRINT_LEN] = '\0';

    // print price
    char price[20];
    sprintf(price, "%.2f", head->price);

    // print quantity
    char quantity[20];
    sprintf(quantity, "%d", head->quantity);

    // print string
    char format[] = "%d * %s @ $%s ea";
    int result = snprintf(str, MAX_ITEM_PRINT_LEN, format, quantity, item_name, price);
    if (result < 0) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}