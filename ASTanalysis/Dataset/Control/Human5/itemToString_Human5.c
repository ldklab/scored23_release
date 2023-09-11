int list_item_to_string(node *head, char *str) {

    if(sprintf(str, "%i * %s @ $%.2f ea", head->quantity, head->item_name, head->price))
        return EXIT_SUCCESS;

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}