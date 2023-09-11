int list_print(node *head) {
    int i = 1;
    while(1==1) {
        if(head!=NULL) {
            char tempstr[32];
            list_item_to_string(head, tempstr);
            printf("%i: %s\n",i,tempstr);
        }
        head = head->next;
        i++;
        if(head == NULL) {
            return EXIT_SUCCESS;
        }

    }

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}