int list_item_to_string(node *head, char *str) {
	// check if no list
	if (!head) {
		printf("[ERROR] list is empty\n");
		return EXIT_FAILURE;
	}

	// check if head is NULL
	if (!head->item_name || !head->price || !head->quantity) {
		printf("[ERROR] invalid node\n");
		return EXIT_FAILURE;
	}

	// generate string
	sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
	str[MAX_ITEM_PRINT_LEN] = 0;

	return EXIT_SUCCESS;
}