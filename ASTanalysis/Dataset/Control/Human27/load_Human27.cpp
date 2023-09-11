int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    FILE *fptr = fopen(filename, "r");
    char buf [100];
    int pos = 1;
    while(fgets(buf, 100, fptr) != NULL){
        char t[100];
        strcpy(t,buf);
        char *pt;
        pt = strtok(t, ",");
        char *name = pt;
        pt = strtok(t, ",");
        float price = atof(pt);
        pt = strtok(t, ",\n");
        int quantity = atoi(pt);

        list_add_item_at_pos(head, name, price, quantity, pos);
        pos ++;
    }


    return EXIT_SUCCESS;
}