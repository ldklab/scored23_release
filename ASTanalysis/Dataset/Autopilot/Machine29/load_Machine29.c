int list_load(node **head, char *filename) {
	if (filename == NULL) {
		return EXIT_FAILURE;
	}

	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		return EXIT_FAILURE;
	}
	char line[MAX_ITEM_PRINT_LEN];
	unsigned int line_num = 1;
	while (fgets(line, MAX_ITEM_PRINT_LEN, file) != NULL) {
		// item_name,price,quantity\n 
		char *item_name = strtok(line, ",");
		if (item_name == NULL) {
			fclose(file);
			return EXIT_FAILURE;
		}
		char *price_string = strtok(NULL, ",");
		if (price_string == NULL) {
			fclose(file);
			return EXIT_FAILURE;
		}
		float price = atof(price_string);
		char *quantity_string = strtok(NULL, ",");
		if (quantity_string == NULL) {
			fclose(file);
			return EXIT_FAILURE;
		}
		int quantity = atoi(quantity_string);
		if (list_add_item_at_pos(head, item_name, price, quantity, line_num) == EXIT_FAILURE) {
			fclose(file);
			return EXIT_FAILURE;
		}
		line_num += 1;
	}
	fclose(file);
	return EXIT_SUCCESS;
}