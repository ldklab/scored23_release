int list_item_to_string(node *head, char *str) {
    char item_name[MAX_ITEM_PRINT_LEN];
    char price[MAX_ITEM_PRINT_LEN];
    char quantity[MAX_ITEM_PRINT_LEN];
    char *ret_str;
    int num_char;
    
    if (head == NULL) return EXIT_FAILURE;
    
    // extract the item name
    ret_str = strstr(head->item_name, " ");
    if (ret_str == NULL) return EXIT_FAILURE;
    
    num_char = ret_str - head->item_name;
    if (num_char >= MAX_ITEM_PRINT_LEN) return EXIT_FAILURE;
    
    strncpy(item_name, head->item_name, num_char);
    item_name[num_char] = '\0';
    
    // extract the price
    sprintf(price, "%.2f", head->price);
    
    // extract the quantity
    sprintf(quantity, "%d", head->quantity);
    
    sprintf(str, "%s %s @ $%s ea", quantity, item_name, price);
    
    return EXIT_SUCCESS;
}