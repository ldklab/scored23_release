int list_item_to_string(node *head, char *str) {
    node *temp = head;
    sprintf(str, "%d * %s @ $%.2f ea",temp->quantity, temp->item_name, temp->price);
    // temp = head;
    // while(temp!=NULL){
    //     if(strcmp(temp->item_name,str)){
            
    //         break;
    //     }
    //     temp = temp->next;
    //}
    return EXIT_SUCCESS;
}