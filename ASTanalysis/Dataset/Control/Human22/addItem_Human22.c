int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    struct _node* new = (node *) malloc(sizeof(node));
    strcpy(new->item_name, item_name);
    new->price = price;
    new->quantity = quantity;

    if (pos == 1){
        new->next = *head;
        head = &new;
        return EXIT_SUCCESS;
    }

    struct _node* curr = *head;
    
    for (int i = 1; i < pos; i++){
        // if we are about to go out of bound, break
        if (! curr->next){
            break;
        }
        curr = curr->next;
    }

    curr->next = new;
    return EXIT_SUCCESS;
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}