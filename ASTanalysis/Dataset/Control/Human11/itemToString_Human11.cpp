int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    char *item = head->c;
    float price = head->price;
    int quan = head->quantity;
    // char *s = quan +
    sprintf(str,"%d * %s @ %.2f ea",quan,item,price);
    printf("%d * %s @ %.2f ea",quan,item,price);
    // str = s;
    return EXIT_SUCCESS;
}