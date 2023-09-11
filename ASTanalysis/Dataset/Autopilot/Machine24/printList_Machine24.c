int list_print(node *head) {
	// check if no list
	if (!head) {
		printf("[ERROR] list is empty\n");
		return EXIT_FAILURE;
	}

	// iterate through list and print to stdout
	int i = 1;
	node *curr = head;
	while (curr) {
		char str[MAX_ITEM_PRINT_LEN];
		list_item_to_string(curr, str);
		printf("%d: %s\n", i, str);
		curr = curr->next;
		i++;
	}

	return EXIT_SUCCESS;
}