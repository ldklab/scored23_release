int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(head ==NULL){
        return EXIT_SUCCESS;
    }
    node *temp = head;
    int fd  = open(*filename,  1);
    if(fd<0){
        return EXIT_FAILURE;
    } else{
    char* str;
        while(temp!=NULL){
            str = "%s,%.2f,%d\n", temp->item_name, temp->price, temp->quantity;
            write(fd,&str, sizeof(str));
        }
    }
    
    return EXIT_SUCCESS;
}