int list_item_to_string(node *head, char *str) {
	if(head->next == NULL) {
		snprintf(str, MAX_ITEM_PRINT_LEN, "%d * %s @ $%.2f ea\n", head->quantity, head->item_name, head->price);
		return EXIT_SUCCESS;
	}
	snprintf(str, MAX_ITEM_PRINT_LEN, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
	return EXIT_SUCCESS;
}