int list_load(node **head, char *filename) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		return EXIT_FAILURE;
	}
	char line[MAX_ITEM_PRINT_LEN];
	while (fgets(line, MAX_ITEM_PRINT_LEN, file)) {
		char *token = strtok(line, ",");
		char *item_name = token;
		token = strtok(NULL, ",");
		float price = atof(token);
		token = strtok(NULL, ",");
		int quantity = atoi(token);
		node *new_node = malloc(sizeof(node));
		new_node->item_name = item_name;
		new_node->price = price;
		new_node->quantity = quantity;
		new_node->next = *head;
		*head = new_node;
	}
	fclose(file);
	return EXIT_SUCCESS;
}