int list_item_to_string(node *head, char *str) {
    if (head != NULL) {
        sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
    }
    return EXIT_SUCCESS;
}