int list_item_to_string(node *head, char *str) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if str is NULL
	if(str == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if item_name is NULL
	if(head->item_name == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if str is of sufficient length
	if(strlen(head->item_name) + (int)((head->price*100.0) + .5) + 20 > MAX_ITEM_PRINT_LEN) {
		return EXIT_FAILURE;
	}
	
	// create string
	sprintf(str, "%d * %s @ $%0.2f ea", head->quantity, head->item_name, head->price);
	
	// return success
	return EXIT_SUCCESS;
}