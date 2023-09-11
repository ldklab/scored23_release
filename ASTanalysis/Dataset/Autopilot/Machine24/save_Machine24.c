int list_save(node *head, char *filename) {
	FILE *fp = fopen(filename, "w");
	if (!fp) {
		printf("[ERROR] cannot open file %s\n", filename);
		return EXIT_FAILURE;
	}

	node *curr = head;
	while (curr) {
		// generate string
		char str[MAX_ITEM_PRINT_LEN];
		list_item_to_string(curr, str);
		fprintf(fp, "%s\n", str);
		curr = curr->next;
	}

	fclose(fp);

	return EXIT_SUCCESS;
}