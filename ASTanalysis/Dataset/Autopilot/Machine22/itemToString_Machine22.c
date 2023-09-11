int list_item_to_string(node *head, char *str) {
	if (head == NULL) {
		strcpy(str, "Empty list");
		return EXIT_SUCCESS;
	}

	node *current = head;
	while (current != NULL) {
		char print_str[MAX_ITEM_PRINT_LEN];
		sprintf(print_str, "%d * %s @ $%.2f ea\n", current->quantity, current->item_name, current->price);
		strcat(str, print_str);
		current = current->next;
	}
	return EXIT_SUCCESS;
}