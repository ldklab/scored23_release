int list_print(node *head) {
    if(head==NULL){
        return EXIT_FAILURE;
    }
    struct node *curr=head;
    int pos=0;
    while(curr!=NULL){
        pos=pos+1;
        printf("%d: %d * %s @ $%.2f ea\n", pos, curr->quantity,curr->item_name,curr->price);
        curr=curr->next;
    }

    return EXIT_SUCCESS;
}