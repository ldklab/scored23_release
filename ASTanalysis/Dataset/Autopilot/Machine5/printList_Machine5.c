int list_print(node *head) {
	node *curr = head;
	int pos = 1;
	char *str = malloc(MAX_ITEM_PRINT_LEN * 3);
	
	if (!str) return EXIT_FAILURE;
	
	while (curr) {
		list_item_to_string(curr, str);
		printf("%d: %s\n", pos, str);
		curr = curr->next;
		pos++;
	}
	
	return EXIT_SUCCESS;
}