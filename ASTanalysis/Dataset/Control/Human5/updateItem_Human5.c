int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    unsigned int nextpos = pos+1;
    int pos2=pos+1;
    if(pos<1)
        return EXIT_FAILURE;
    else{
        while(pos--) {
            if(pos==0){
                node * temp = (node*) malloc(sizeof(node));
                temp ->  item_name = item_name;
                temp->price = price;
                temp->quantity = quantity;
                temp->next = *head;
                *head = temp;
                list_remove_item_at_pos(head, pos2);
                return EXIT_SUCCESS;
            }
            else {
                head=&(*head)->next;
            }
        }
    }

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}