int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    //pos=pos-1;
    // if(pos<1) return EXIT_FAILURE;
    // if(pos>CURR_LEN+1) return EXIT_FAILURE;
    printf("%s", item_name);
    CURR_LEN+=1;
    struct _node *nodeX = (struct _node*)malloc(sizeof (struct _node));
    nodeX->c = item_name; // *(nodeX).c
    nodeX->price = price;
    nodeX->quantity = quantity;
    // struct _node *head_c = *head;
    
    printf("\nCreated");
    if(pos==1)
    {
        printf("\n1");
        nodeX->next = *head;
        printf("\nChecked");
        *head = nodeX;
        printf("\nUpdated");
        printf("\n%s",(*head)->c);
    }
    // else{
        
    //     for(int i=1;i<pos-1;i++){
    //         head_c= head_c->next;
    //     }
    //     if(head_c->next!=NULL){
    //         nodeX->next = head_c->next;
    //     }
    //     else {
    //         nodeX->next = NULL;
    //     }
    //     // nodeX->next = head_c->next->next;
    //     head_c->next = nodeX;
    // }
    return EXIT_SUCCESS;
}