int list_item_to_string(node *head, char *str) {
	// If head is empty, return an empty string
	if (head == NULL) {
		str[0] = '\0';
		return EXIT_SUCCESS;
	}

	// If head has only one node
	if (head->next == NULL) {
		sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
		return EXIT_SUCCESS;
	}

	// If head has multiple nodes
	node *current = head;
	char str_curr[MAX_ITEM_PRINT_LEN];
	while (current != NULL) {
		sprintf(str_curr, "%d * %s @ $%.2f ea\n", current->quantity, current->item_name, current->price);
		strcat(str, str_curr);
		current = current->next;
	}

	return EXIT_SUCCESS;
}