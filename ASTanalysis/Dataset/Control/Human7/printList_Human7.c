int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(head== NULL){
        return EXIT_FAILURE;
    }
    int i =1;
    node *temp = head;
    while(temp!= NULL){
        printf('%d: %d * %s @ $%.2f ea\n', i,temp->quantity,temp->item_name,temp->price);
        temp=temp->next;
        i++;
    }
    return EXIT_SUCCESS;
}