int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // create new element
    node* new_node = (node*) malloc(sizeof(node));
    new_node->item_name = item_name;
    new_node->price = price;
    new_node->quantity = quantity;

    if(*head == NULL){
        // printf("first element at %p", *head);
        *head = new_node;
        return EXIT_SUCCESS;
    }
    int current_pos = 1;
    node* pointer = *head;
    while(current_pos < pos-1){
        pointer = pointer->next;
        if(pointer == NULL)
            return EXIT_FAILURE;
        
        current_pos++;
    }
    node* before = pointer;
    node* after = pointer->next;

    before->next = new_node;
    new_node->next = after;
    return EXIT_SUCCESS;
}