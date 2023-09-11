int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(head == NULL){
        return EXIT_SUCCESS;
    }
    sprintf(str, "%d * %s @ $%0.2f ea", head->quantity, head->item_name, head->price);
    // if(!){
    //     return EXIT_FAILURE;
    // }
    return EXIT_SUCCESS;
}