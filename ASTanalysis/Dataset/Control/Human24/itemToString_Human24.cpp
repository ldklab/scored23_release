int list_item_to_string(node *head, char *str) {
    strcat(str,head->quantity);
    strcat(str," * ");
    strcat(str,head->item_name);
    strcat(str," @ $");
    strcat(str,head->price);
    strcat(str," ea");
    return EXIT_SUCCESS;s
}