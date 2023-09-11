int list_print(node *head) {
	if (head == NULL) {
		printf("empty list\n");
		return EXIT_SUCCESS;
	}
	node *current = head->next;
	char *str = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
	int i = 0;
	if (!str) {
		fprintf(stderr, "Not enough memory!");
		return EXIT_FAILURE;
	}
	while (current != NULL) {
		char *name = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
		char *price = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
		char *quantity = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
		if (!name || !price || !quantity) {
			fprintf(stderr, "Not enough memory!");
			return EXIT_FAILURE;
		}
		sprintf(name, "%s", current->item_name);
		sprintf(price, "%.2f", current->price);
		sprintf(quantity, "%d", current->quantity);
		char *toPrint = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);
		if (!toPrint) {
			fprintf(stderr, "Not enough memory!");
			return EXIT_FAILURE;
		}
		strcat(toPrint, quantity);
		strcat(toPrint, " * ");
		strcat(toPrint, name);
		strcat(toPrint, " @ $");
		strcat(toPrint, price);
		strcat(toPrint, " ea");
		strcat(str, toPrint);
		strcat(str, "\n");
		free(toPrint);
		current = current->next;
	}
	printf("%s", str);
	free(str);
	return EXIT_SUCCESS;
}