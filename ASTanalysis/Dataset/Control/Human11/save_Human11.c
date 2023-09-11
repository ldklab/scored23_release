int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    FILE *ftr;
    ftr = fopen("./saveFile.txt",'w');
    *filename = "saveFile.txt";
    node *curr = head;
    while(curr){
        fprintf(ftr,"%s,%f,%d\n",curr->c,curr->price,curr->quantity);
        curr=curr->next;
    }
    fclose(ftr);
    return EXIT_SUCCESS;
}