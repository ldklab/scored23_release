int list_print(node *head) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if item_name is NULL
	if(head->item_name == NULL) {
		return EXIT_FAILURE;
	}
	
	// print first node
	printf("%d: %d * %s @ $%0.2f ea\n", 1, head->quantity, head->item_name, head->price);
	
	// print rest of nodes
	node *temp_node = head->next;
	int pos = 2;
	while(temp_node != NULL) {
		// check if item_name is NULL
		if(temp_node->item_name == NULL) {
			return EXIT_FAILURE;
		}
		
		// print node
		printf("%d: %d * %s @ $%0.2f ea\n", pos, temp_node->quantity, temp_node->item_name, temp_node->price);
		
		// move to next node
		temp_node = temp_node->next;
		pos++;
	}
	
	// return success
	return EXIT_SUCCESS;
}