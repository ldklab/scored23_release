int list_find_highest_price_item_position(node *head, int *pos) 
{
    if(head==NULL){
        return EXIT_FAILURE;
    }
    struct node *curr=head;
    int max=0;
    int place=1
    while(curr!=NULL){
        if (curr->price >= max){
            max=curr->price;
            pos=place;
        }
        place=place+1;
        curr=curr->next;
    }

    return EXIT_SUCCESS;
}