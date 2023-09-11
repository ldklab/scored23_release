int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    struct _node node1 = {*item_name,price, quantity, NULL};
    
    // if (head[pos] == NULL){
    //     return EXIT_FAILURE;
    // }
    head[pos] = &node1;
    //head[pos]->next = NULL;
    // if (pos != 0){
    //     head[pos - 1]->next = head[pos];
    // }
    return EXIT_SUCCESS;
}