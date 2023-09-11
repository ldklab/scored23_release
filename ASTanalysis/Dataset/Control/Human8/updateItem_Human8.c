int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(pos<0){
        return EXIT_FAILURE; 
    }

    node* curr = *head;
    int n = 1;
    while(curr){
        if(n==pos){
            // node* newnode = malloc(sizeof(node));
            curr->item_name = item_name;
            curr->price = price;
            curr->quantity = quantity;
            // newnode->next= curr->next;

            // curr->next = newnode;
            return EXIT_SUCCESS;
            // break;
        }

        else{
            curr = curr->next;
            n += 1;
        }

    }

    return EXIT_FAILURE;
}