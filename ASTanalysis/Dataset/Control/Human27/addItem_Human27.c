int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    node *nnode = malloc(sizeof(node));
    nnode->item_name = item_name;
    nnode->price = price;
    nnode->quantity = quantity;
    if(pos == 1){
        nnode->next = *head;
    }
    else{
        node *curr = *head;
        for(unsigned int i = 2; i < pos; i++){
            if (curr == NULL){
                return EXIT_FAILURE; //list shorter than pos
            }
            curr = curr->next;
        }
        nnode->next = curr->next;
        curr->next = nnode;
    }
    *head = nnode;
    return EXIT_SUCCESS;
}