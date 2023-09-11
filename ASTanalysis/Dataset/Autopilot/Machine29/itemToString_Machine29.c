int list_item_to_string(node *head, char *str) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	if (str == NULL) {
		return EXIT_FAILURE;
	}
	char price[MAX_ITEM_PRINT_LEN];
	sprintf(price, "%.2f", head->price);
	snprintf(str, MAX_ITEM_PRINT_LEN, "%d * %s @ $%s ea", head->quantity, head->item_name, price);
	return EXIT_SUCCESS;
}