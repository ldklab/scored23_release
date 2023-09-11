int list_deduplicate(node **head) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up temp node
	node *temp_node = *head;
	
	// traverse list
	while(temp_node->next != NULL) {
		if(strcmp(temp_node->item_name, temp_node->next->item_name) == 0) {
			temp_node->quantity += temp_node->next->quantity;
			node *temp_node2 = temp_node->next;
			temp_node->next = temp_node->next->next;
			free(temp_node2);
		}
		else {
			temp_node = temp_node->next;
		}
	}
	
	// return success
	return EXIT_SUCCESS;
}
