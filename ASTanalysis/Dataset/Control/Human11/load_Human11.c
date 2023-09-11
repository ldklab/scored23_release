int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    FILE *ftr;
    char *line;
    char *token;
    node *curr = *head;
    while(curr->next){
        curr = curr->next;
    }
    ftr = fopen(*filename,'r');
    while(fgets(line,100,ftr)){
        struct _node *newNode = (struct _node*)malloc(sizeof (struct _node));
        token = strtok(line," ");
        int num =1;
        while(token){
            if(num==1){
                newNode->c = token;
                num+=1;
            }
            else if (num==2)
            {
                newNode->price = atof(token);
                num+=3;
            }
            else{
                newNode->quantity=atoi(token);
            }
        }
        num = 1;
        curr->next = newNode;
        curr = curr->next;
    }
    fclose(ftr);
    return EXIT_SUCCESS;
}