int list_print(node *head) {
    node *temp = head;
    int pos1;
    pos1 = 0;
    while(temp!=NULL){
        pos1++;
        printf("%d: %d * %s @ $%.2f ea",pos1, temp->quantity, temp->item_name, temp->price);
        temp = temp->next;
    }
    return EXIT_SUCCESS;
}