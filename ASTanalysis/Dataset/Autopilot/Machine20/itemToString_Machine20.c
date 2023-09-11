int list_item_to_string(node *head, char *str) {
	int status = EXIT_FAILURE;
	if (head != NULL && str != NULL) {
		sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
		status = EXIT_SUCCESS;
	}
	return status;
}