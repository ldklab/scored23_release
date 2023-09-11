int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(head == NULL){ return EXIT_FAILURE; }
    int i = snprintf(str, MAX_ITEM_PRINT_LEN, "%u * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
    return EXIT_SUCCESS;
    //return EXIT_FAILURE;
}