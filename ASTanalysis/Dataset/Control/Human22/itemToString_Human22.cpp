int list_item_to_string(node *head, char *str) {
    sprintf(str, "%d * %s @ $%.2f ea\n", head->quantity, head->item_name, head->price);
    return EXIT_SUCCESS;
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}