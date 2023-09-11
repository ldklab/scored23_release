int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(pos1 == pos2){return EXIT_SUCCESS;}
    if(pos1 > pos2){int t = pos1; pos1=pos2; pos2=t;}
    if(pos1 < 1){return EXIT_FAILURE;}
    node *p1;
    node *p2;

    node *curr = *head;
    for(int i = 1; i < pos2-1; i++){
        if (curr == NULL){
            return EXIT_FAILURE;
        }
        curr = curr->next;
    }
    p2 = curr;
    if(pos1 == 1){
        p2->next = *head;
        *head = p2;
        
    }
 
 
    curr = *head;
    for(int i = 2; i < pos1-1; i++){
        if (curr == NULL){
            return EXIT_FAILURE;
        }
        curr = curr->next;
    }
    p1 = curr;



    //if(p2->next == NULL){return EXIT_FAILURE;}
    
    if(pos2-pos1 == 1){
        node *t = p2->next->next;
        p1->next = p2->next;
        p2->next->next = p2;
        p2->next = t;
    }
    else{
        node *t = p1->next;
        p1->next = p2->next;
        p2->next = t;
        t = p1->next->next;
        p1->next->next = p2->next->next;
        p2->next->next = t;
    }
    return EXIT_SUCCESS;
}