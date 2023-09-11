int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    printf("Entered1");
    int pos = 0;
    struct _node *curr = head;
    printf("Entered2");
    while(curr){
        printf("Entered");
        char *s;
        list_item_to_string(curr,s);
        printf("%d: %s\n",pos,s);
        curr=curr->next;
        pos++;
    }
    return EXIT_SUCCESS;
}