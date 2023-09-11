int list_item_to_string(node *head, char *str) {
	if(head == NULL || str == NULL) {
		return EXIT_FAILURE;
	}

	if(head->quantity == 0) {
		strcpy(str, "");
	}
	else {
		sprintf(str, "%d * %s @ $%.2f ea", 
							head->quantity, 
							head->item_name, 
							head->price);
	}
	return EXIT_SUCCESS;
}