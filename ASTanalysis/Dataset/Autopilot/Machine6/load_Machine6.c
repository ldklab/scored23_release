int list_load(node **head, char *filename) {
	if (*head == NULL) {
		list_init(head);
	}
	node *current = *head;
	FILE *file = fopen(filename, "r");
	if (!file) {
		fprintf(stderr, "Couldn't open file!");
		return EXIT_FAILURE;
	}
	char *line = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
	if (!line) {
		fprintf(stderr, "Not enough memory!");
		return EXIT_FAILURE;
	}
	while (fgets(line, MAX_ITEM_PRINT_LEN, file) != NULL) {
		node *new = malloc(sizeof(node));
		if (!new) {
			fprintf(stderr, "Not enough memory!");
			return EXIT_FAILURE;
		}
		char *token[3];
		int i = 0;
		char *next = line;
		while (next[i] != '\n') {
			token[i] = next;
			i++;
			next = next + 1;
		}
		token[i] = next;
		i++;
		new->item_name = malloc(sizeof(char) * (strlen(token[0]) - 1));
		if (!new->item_name) {
			fprintf(stderr, "Not enough memory!");
			return EXIT_FAILURE;
		}
		strcpy(new->item_name, token[0]);
		new->price = strtod(token[1], NULL);
		new->quantity = atoi(token[2]);
		new->next = NULL;
		current->next = new;
		current = new;
	}
	fclose(file);
	return EXIT_SUCCESS;
}