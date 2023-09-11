int list_item_to_string(node *head, char *str) {
    snprintf(str,"%d * %c @%f ea",head->quantity,head ->item_name,head ->price);
    return EXIT_SUCCESS;
}