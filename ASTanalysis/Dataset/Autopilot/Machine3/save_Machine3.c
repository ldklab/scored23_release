int list_save(node *head, char *filename) {
	if(head == NULL) {
		fprintf(stderr, "Error: list_save cannot save an empty list.\n");
		return EXIT_FAILURE;
	}
	FILE *fp = fopen(filename, "w");
	if(fp == NULL) {
		fprintf(stderr, "Error: list_save cannot open %s.\n", filename);
		return EXIT_FAILURE;
	}
	node *current = head;
	while(current!= NULL) {
		fprintf(fp, "%s,%f,%d\n", current->item_name, current->price, current->quantity);
		current = current->next;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}