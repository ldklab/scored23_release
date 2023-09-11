int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    *pos = 0;
    int index = 0;
    int max = 0;
    struct _node *curr = head;
    while(curr != NULL){
        if(curr->price > max){
            max = curr->price;
            *pos = index;
        }
        index++;
    }
    return EXIT_FAILURE;
}