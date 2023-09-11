int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    int mind, maxd;
    if (pos1<=pos2){mind = pos1; maxd = pos2;}
    else {mind = pos2; maxd = pos1;}

    node* min = *head;
    node* max = *head;
    node* temp = *head;
    int i=1;

    while (temp != NULL){        
        if(i==mind){
            max = temp;
            for (int j=i; j<maxd; j++){
                max = max->next;}
            temp = min;
            min->next = max->next;
            max->next = temp->next;          
        }
        i++;
        temp = temp->next;
    }
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}