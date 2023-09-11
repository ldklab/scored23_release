int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(pos1>pos2){
        int x = pos1;
        pos1 = pos2;
        pos2 = x;
    }
    if(pos1<0||pos2>CURR_LEN) return EXIT_FAILURE;
    node *node1=NULL;
    node *node2=NULL;
    node *curr = *head;
    for(int i=0;i<pos2+1;i++){
        if(i==pos1){
            node1=curr;
        }
        else if (i==pos2)
        {
            char *x = node1->c;
            float y = node1->price;
            int z = node1->quantity;
            node1->c = node2->c;
            node1->price = node2->price;
            node1->quantity = node2->quantity;
            node2->c = x;
            node2->price = y;
            node2->quantity = z;
            break;
        }
        else{
            curr=curr->next;
        } 
        
    }
    return EXIT_SUCCESS;
}