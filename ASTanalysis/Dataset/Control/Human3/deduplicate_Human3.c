int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    node* cur = *head;
    node* prev = cur;
    
    const char* item_list[10000];
    int flag=0;

    int i=0;
    while (1){
        if(cur == NULL){
            break;
        }
        else{
            item_list[i] = cur->item_name;

        }
        for (int j=0; j<i; j++){
            if (cur->item_name == item_list[j]){
                flag=1;
            }
        }
        if(flag){
            //prev unchanged
            cur = cur->next;           
            i++;
        }
        else{
            prev = cur;
            cur = cur->next;
            i++;
        }

    }
    node* fut = cur->next;

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}