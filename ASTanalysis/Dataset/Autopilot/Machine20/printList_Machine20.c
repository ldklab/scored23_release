int list_print(node *head) {
	int status = EXIT_FAILURE;
	if (head != NULL) {
		int pos = 1;
		node *current = head->next;
		while (current != NULL) {
			char print_str[MAX_ITEM_PRINT_LEN];
			list_item_to_string(current, print_str);
			printf("%d: %s\n", pos, print_str);
			current = current->next;
			pos++;
		}
		status = EXIT_SUCCESS;
	}
	return status;
}