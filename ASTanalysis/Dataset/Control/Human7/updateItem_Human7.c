int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i=1;
    node *temp = *head;
    if(pos == 1){
        temp->item_name=item_name;
        temp->price = price;
        temp->quantity = quantity;
    }else {
        for(i =1; i< pos; i++){
            if(temp == NULL){
                return EXIT_FAILURE;
            }
            temp = temp->next;
        }

        temp->item_name=item_name;
        temp->price = price;
        temp->quantity = quantity;
    }
    return EXIT_SUCCESS;
}