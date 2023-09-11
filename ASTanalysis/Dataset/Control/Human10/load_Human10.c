int list_load(node **head, char *filename)
{
    list_init(head);

    FILE* fileptr = NULL;
    char* line;
    size_t size = MAX_ITEM_PRINT_LEN;

    if((fileptr = fopen(filename, "r")) == NULL) {
        return EXIT_FAILURE;
    }

    char* item_name;
    float price;
    int quantity;
    int pos = 1;

    while (getline(&line, &size, fileptr) != -1) {
        item_name = strtok(line, ",");
        char* str = (char*)malloc(strlen(item_name));
        strcpy(str,item_name);
        price = atof(strtok(NULL, ","));
        quantity = atoi(strtok(NULL, ","));
        list_add_item_at_pos(head, str, price, quantity, pos);
        pos++;
    }

    return EXIT_SUCCESS;
}