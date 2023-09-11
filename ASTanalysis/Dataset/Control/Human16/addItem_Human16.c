int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i = 1;

    node* _head = *head;
    node* _prev = NULL;
    while(_head && i < pos){
        i++;
        _prev = _head;
        _head = _head->next;
    }

    node* new_node = (struct _node*) malloc(sizeof(struct _node));
    new_node->item_name = item_name;
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;

    if(_prev){
        _prev->next = new_node;
    }
    new_node->next = _head;

    if(pos==1){
        *head = new_node;
    }

    return EXIT_SUCCESS;
}