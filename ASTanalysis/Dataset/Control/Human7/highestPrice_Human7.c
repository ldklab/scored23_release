int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int highest = -1;
    int i = 1;
    node *temp = head;
    while(temp!=NULL){
        if(temp->price>highest){
            highest=temp->price;
            *pos =i;
        }
        temp = temp->next;
        i++;
    }
    return EXIT_SUCCESS;
}