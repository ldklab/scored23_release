int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if (head == NULL){
        return EXIT_FAILURE;
    }

    // char* iname = head->item_name;
    // char* quantity = (char *) head->quantity ;
    // char* price = head->price;

    int res = sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);

    if (res < 0){
        return EXIT_FAILURE;
    }

    else{
        return EXIT_SUCCESS;
    }
}