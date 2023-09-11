int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    float highP = 0;
    node *curr = head;
    int currPos = 1;
    while(curr){
        if(highP<curr->price){
            *pos=currPos;
            highP = curr->price;
        } 
        currPos+1;
        curr=curr->next;
    }
    
    return EXIT_SUCCESS;
}