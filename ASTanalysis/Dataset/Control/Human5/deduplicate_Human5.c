int list_deduplicate(node **head) {
    node* p1;
    node* p2;
    node* dup;
    int pos = 1;
    int pos1 = 1;
    p1 = *head;
    while(p1 != NULL && p1->next != NULL) {
        p2 = p1;
        pos = pos1;
        while(p2 != NULL && p2->next != NULL) {
            if(!strcmp(p1->item_name,p2->next->item_name)) {

                dup = p2->next;
                int sum = p1->quantity + p2->next->quantity;
                p1->quantity = p1->quantity + p2->next->quantity;


                if(dup->next == NULL){
                    p2->next=NULL;
                    break;
                }
                else {
                    p2->next=p2->next->next;
                }

                free(dup);
                break;
                
            }
            else{
                p2=p2->next;
                pos++;
            }

        }
        if(p1->next==NULL) {
            break;
        }
        else {
            p1=p1->next;
        }
        pos1++;
    }

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}