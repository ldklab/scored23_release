int list_item_to_string(node *head, char *str) {
    if(!head) 
        return EXIT_FAILURE;
    if(sprintf(str, "%d * %s @ $%.2f ea\n", head->quantity, head->item_name, head->price) < 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}