int list_item_to_string(node *head, char *str) {
	node *curr = head;
	char *item_name = curr->item_name;
	char *price_string = malloc(MAX_ITEM_PRINT_LEN);
	float price = curr->price;
	int quantity = curr->quantity;
	
	if (!str || !item_name || !price_string) return EXIT_FAILURE;
	
	sprintf(price_string, "%.2f", price);
	sprintf(str, "%d * %s @ $%s ea", quantity, item_name, price_string);
	
	return EXIT_SUCCESS;
}