int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    int max = -10000;
    int max_ind;
    node* cur;
    cur->next = head;
    int i = 0;
    while (1){       
        if (cur == NULL){
            break;
        }
        if (cur->price >= max){
            max = cur->price;
            max_ind = i;
        }
        i++;
        cur = cur->next;
    }

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}