int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    //printf("HMMM");
    node* item;
    //node* temp = &(*head);
    
    item->item_name = item_name;
    item->price = price;
    item->quantity = quantity;
    //unsigned int counter = 0;
    if (*head == NULL){
        *head = item;
        return EXIT_SUCCESS;
    }
    while(pos > 1){
        *head = (*head)->next;
        
        //printf("Counter: %d\n", counter);
        pos--;
    }
    item->next = (*head)->next;
    (*head)->next =  item;
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}