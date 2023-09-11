int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* _head = *head;
    while(_head && _head->next){
        _head = _head->next;
    }
    FILE* fp;
    fp = fopen(filename, "r");

    if(!fp){
        return EXIT_FAILURE;
    }

    char line[100];

    while(fgets(line, 100, fp) != NULL){
        char* tmp;
        node* new_node = (struct _node*) malloc(sizeof(struct _node));
        tmp = strtok(line,",");
        new_node->item_name = (char*)malloc(strlen(tmp)+1);
        strcpy(new_node->item_name, tmp);

        tmp = strtok(NULL,",");
        new_node->price = atof(tmp);

        tmp = strtok(NULL,",");
        new_node->quantity = atoi(tmp);

        new_node->next = NULL;
        if(_head)
            _head->next = new_node;
        _head = new_node;
        if(*head == NULL){
            *head = new_node;
        }
    }
    fclose(fp);
    return EXIT_SUCCESS;
}