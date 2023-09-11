int list_save(node *head, char *filename) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        if (filename == NULL) {
            return EXIT_FAILURE;
        } else {
            FILE *f = fopen(filename, "w+");
            if (f == NULL) {
                return EXIT_FAILURE;
            } else {
                node *cur = head;
                while (cur != NULL) {
                    fprintf(f, "%s,%.2f,%d\n", cur->item_name, cur->price, cur->quantity);
                    cur = cur->next;
                }
                fclose(f);
                return EXIT_SUCCESS;
            }
        }
    }
}