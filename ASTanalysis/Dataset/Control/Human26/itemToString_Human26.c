int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // cannot print NULL node
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    // store formatted string in str
    int len = sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
    if (len < 0) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}