int list_find_highest_price_item_position(node *head, int *pos) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up temp node
	node *temp_node = head;
	int i = 0;
	float highest = 0;
	
	// traverse to end of list
	while(temp_node != NULL) {
		if(temp_node->price > highest) {
			highest = temp_node->price;
			*pos = i;
		}
		temp_node = temp_node->next;
		i++;
	}
	
	// return success
	return EXIT_SUCCESS;
}