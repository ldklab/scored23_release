int list_print(node *head) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	int pos = 1;
	node *current = head;
	while (current != NULL) {
		char str[MAX_ITEM_PRINT_LEN];
		if (list_item_to_string(current, str) == EXIT_FAILURE) {
			return EXIT_FAILURE;
		}
		printf("%d: %s\n", pos, str);
		current = current->next;
		pos += 1;
	}
	return EXIT_SUCCESS;
}