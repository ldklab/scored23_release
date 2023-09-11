int list_print(node *head) {
    // TODO: Implement this function, 
    node* cur;
    cur = head;
    int i = 0;
    while (cur != NULL){
        i++;
        printf("%d: %d * %s @ $%.2f ea\n",i,cur->quantity,cur->item_name,cur->price);
        cur = cur->next;
    }
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}