int list_item_to_string(node *head, char *str) {
    // check the head and the item_name
    if (head == NULL || head->item_name == NULL) {
        return EXIT_FAILURE;
    }
    int len = snprintf(str, MAX_ITEM_PRINT_LEN, "%i * %s @ $%.2f ea", 
                       head->quantity, head->item_name, head->price);
    if (len < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}