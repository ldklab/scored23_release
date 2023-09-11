int list_print(node *head) {
	node *cur_node = head;
	int i = 1;
	while (cur_node != NULL) {
		char str[MAX_ITEM_PRINT_LEN];
		if (list_item_to_string(cur_node, str) == EXIT_FAILURE) {
			return EXIT_FAILURE;
		}
		printf("%d: %s\n", i, str);
		cur_node = cur_node->next;
		i++;
	}
	return EXIT_SUCCESS;
}