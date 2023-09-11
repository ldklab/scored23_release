int list_load(node **head, char *filename) {
    FILE *fp = fopen(filename,"r");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    char line[MAX_ITEM_PRINT_LEN+1];
    while (fgets(line, MAX_ITEM_PRINT_LEN, fp)) {
        int i=0;
        int pos1 = 0, pos2 = 0;
        char *item_name = NULL;
        float price = 0.0;
        int quantity = 0;
        while (line[i]!=',' && line[i]!=0) {
            i++;
        }
        if (line[i]==0) {
            break;
        }
        item_name = line;
        i++;
        while (line[i]!=',' && line[i]!=0) {
            i++;
        }
        if (line[i]==0) {
            break;
        }
        pos1 = i+1;
        float f = atof(&line[i+1]);
        i=0;
        while (line[i]!=0) {
            i++;
        }
        if (line[i]==0) {
            break;
        }
        pos2 = i;
        quantity = atoi(&line[pos1]);
        price = f;
        list_add_item_at_pos(head, item_name, price, quantity, pos2);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}