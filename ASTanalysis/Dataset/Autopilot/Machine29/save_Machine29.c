int list_save(node *head, char *filename) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	if (filename == NULL) {
		return EXIT_FAILURE;
	}

	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		return EXIT_FAILURE;
	}
	node *current = head;
	while (current != NULL) {
		// char *item_name, float price, int quantity, node *next
		fprintf(file, "%s,%f,%d\n", current->item_name, current->price, current->quantity);
		current = current->next;
	}
	fclose(file);
	return EXIT_SUCCESS;
}