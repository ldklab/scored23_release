int list_load(node **head, char *filename) {
	node *curr = *head;
	FILE *fptr = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token, *saveptr;
	char *item_name, *price_string, *quantity_string;
	float price, quantity;
	
	if (!fptr) return EXIT_FAILURE;
	
	while ((read = getline(&line, &len, fptr)) != -1) {
		if (line[0] == '#') {
			// skip comments
			continue;
		}
		
		token = strtok_r(line, ",", &saveptr);
		item_name = token;
		token = strtok_r(NULL, ",", &saveptr);
		price_string = token;
		token = strtok_r(NULL, ",", &saveptr);
		quantity_string = token;
		
		price = atof(price_string);
		quantity = atoi(quantity_string);
		
		list_add_item_at_pos(head, item_name, price, quantity, 0);
	}
	
	fclose(fptr);
	free(line);
	
	return EXIT_SUCCESS;
}