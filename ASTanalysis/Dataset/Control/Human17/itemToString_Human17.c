int list_item_to_string(node *head, char *str) {
    while(*head !=NULL){
        head=&(*head)->next;
    }

    *head=malloc(sizeof(node));
    if(*head==NULL)
        return EXIT_FAILURE;
    (*head)->str =malloc(strlen(str)+1);
    if((*head)->item_name==NULL)
        return EXIT_FAILURE;
    strcpy((*head)->item_name,str);
    return EXIT_SUCCESS;
}