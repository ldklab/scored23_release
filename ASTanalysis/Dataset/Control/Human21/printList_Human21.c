int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    unsigned int pos = 1;
    node* current = head;

    while(current->next != NULL){
        printf("%d: %d * %s @ $%.2f ea\n", pos, 
        current->quantity, current->item_name, current->price);
        current = current->next;
        pos +=1;
    }
    
    return EXIT_SUCCESS;
}