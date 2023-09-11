int list_item_to_string(node *head, char *str) {
    int res = sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
    if(res < 0)
        return EXIT_FAILURE;
    // TODO: Implements this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}