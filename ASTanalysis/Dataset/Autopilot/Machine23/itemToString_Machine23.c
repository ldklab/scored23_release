int list_item_to_string(node *head, char *str) {
    // check if node is null
    if (head == NULL) {
        fprintf(stderr, "list_item_to_string: node is null\n");
        return EXIT_FAILURE;
    }

    // check if string is null
    if (str == NULL) {
        fprintf(stderr, "list_item_to_string: string is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    char *item_name = head->item_name;
    float price = head->price;
    int quantity = head->quantity;

    // calculate length of string
    int length = strlen(item_name) + 18 + 2;

    // check if item name is empty
    if (item_name == NULL || strlen(item_name) == 0) {
        fprintf(stderr, "list_item_to_string: item_name is null or empty\n");
        return EXIT_FAILURE;
    }

    // check if price is less than 0
    if (price < 0) {
        fprintf(stderr, "list_item_to_string: price is negative\n");
        return EXIT_FAILURE;
    }

    // check if quantity is less than 0
    if (quantity < 0) {
        fprintf(stderr, "list_item_to_string: quantity is negative\n");
        return EXIT_FAILURE;
    }

    // check if length is greater than string length
    if (length > strlen(str)) {
        fprintf(stderr, "list_item_to_string: string not long enough\n");
        return EXIT_FAILURE;
    }

    // set up format string
    char format_str[length];
    sprintf(format_str, "%d * %s @ $%.2f ea", quantity, item_name, price);

    // copy string to buffer
    strncpy(str, format_str, strlen(format_str));

    return EXIT_SUCCESS;
}