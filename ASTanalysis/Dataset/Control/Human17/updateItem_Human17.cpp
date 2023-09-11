int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    struct node *ptr;

    for(i=0,ptr=head;i<pos-1;i++){
        ptr=ptr->next;
        if(ptr==NULL)
        {
            return EXIT_FAILURE;
        }
    }
    &ptr->item_name=item_name;
    &ptr->price=price;
    &ptr->quantity=quantity;

    return EXIT_SUCCESS;
}