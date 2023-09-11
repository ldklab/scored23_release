int list_load(node **head, char *filename) {
	FILE *fp = fopen(filename, "r");
	if (!fp) {
		printf("[ERROR] cannot open file %s\n", filename);
		return EXIT_FAILURE;
	}

	char str[MAX_ITEM_PRINT_LEN];
	node *curr = *head;
	while (fgets(str, MAX_ITEM_PRINT_LEN, fp)) {
		// get item name
		char *item_name = strtok(str, ",");
		// get price
		char *price = strtok(NULL, ",");
		// get quantity
		char *quantity = strtok(NULL, ",");
		// skip newline
		char *newline = strtok(NULL, "\n");

		// create new node
		if (!(curr = (node *)malloc(sizeof(node)))) {
			printf("[ERROR] malloc failed\n");
			fclose(fp);
			return EXIT_FAILURE;
		}
		curr->next = NULL;
		curr->item_name = strdup(item_name);
		curr->price = strtof(price, NULL);
		curr->quantity = atoi(quantity);

		// add to end
		if (*head == NULL) {
			*head = curr;
		} else {
			node *tmp = *head;
			while (tmp->next) {
				tmp = tmp->next;
			}
			tmp->next = curr;
		}
	}

	fclose(fp);

	return EXIT_SUCCESS;
}