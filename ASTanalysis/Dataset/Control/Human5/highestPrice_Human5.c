int list_find_highest_price_item_position(node *head, int *pos) 
{

    int curr = 1;
    int high = 1;
    float val = 0;
    while(head != NULL) {
        if(head->price >val) {
            val = head->price;
            high = curr;
        }
        curr++;
        head=head->next;
    }
    *pos = high;

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}