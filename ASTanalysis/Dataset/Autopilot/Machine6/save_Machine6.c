int list_save(node *head, char *filename) {
	if (head == NULL) {
		fprintf(stderr, "Empty list!");
		return EXIT_FAILURE;
	}
	FILE *file = fopen(filename, "w");
	if (!file) {
		fprintf(stderr, "Couldn't open file!");
		return EXIT_FAILURE;
	}
	char *str = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
	if (!str) {
		fprintf(stderr, "Not enough memory!");
		return EXIT_FAILURE;
	}
	node *current = head->next;
	while (current != NULL) {
		sprintf(str, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
		fputs(str, file);
		current = current->next;
	}
	fclose(file);
	return EXIT_SUCCESS;
}