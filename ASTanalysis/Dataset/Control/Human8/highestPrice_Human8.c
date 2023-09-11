int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    float maxtillnow = head->price;

    node* curr = head->next;
    int n=2;
    while(curr){
        if(curr->price > maxtillnow){
            maxtillnow = curr->price;
            *pos = n;
        }

        curr = curr->next;
        n += 1;
    }

    return EXIT_SUCCESS;
}