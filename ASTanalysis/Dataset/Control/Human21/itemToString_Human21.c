int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriates
    sprintf(str, "%d * %s @ $%.2f ea", head->quantity, 
            head->item_name, head->price);
    return EXIT_SUCCESS;
}