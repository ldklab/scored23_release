int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* _head = head;
    if(!_head){
        return EXIT_FAILURE;
    }

    FILE* fp;
    fp = fopen(filename, "a+");

    if(!fp){
        return EXIT_FAILURE;
    }

    while(_head){
        fprintf(fp, "%s,%0.2f,%d\n",_head->item_name, _head->price, _head->quantity);
        _head = _head->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}
