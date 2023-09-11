int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    node* cur = *head;
    node* prev = NULL;
    for (int i=1; i<pos; i++){
        prev = cur;
        cur = cur->next;
    }
    node* new_node = malloc(sizeof(node));
    if (pos==1){
        
        new_node->next = *head;
        *head = new_node;
        new_node->price = price;
        new_node->quantity = quantity;
        new_node->item_name = item_name;
        return EXIT_SUCCESS;
    }
    new_node->next = prev->next;
    prev->next = new_node;
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->item_name = item_name;
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}