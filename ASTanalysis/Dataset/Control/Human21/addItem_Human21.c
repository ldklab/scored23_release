int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* link = (node*) malloc(sizeof(node));
    node* current = *head;
    unsigned int counter = 0;

    link->item_name = item_name;
    link->price = price;
    link->quantity = quantity;
    link->next = NULL;

    if(current == NULL){
        current = link;
    }
    else{
        while(counter < pos){
            current = current->next;
            counter++;
        }
        current->next = link;
    }
    return EXIT_SUCCESS;
}