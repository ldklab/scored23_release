int list_swap_item_positions(node **head, int pos1, int pos2) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up temp node
	node *temp_node = (*head);
	int i = 0;
	
	// traverse to pos1
	while(i < pos1) {
		if(temp_node->next == NULL) {
			return EXIT_FAILURE;
		}
		temp_node = temp_node->next;
		i++;
	}
	
	// set up temp node2
	node *temp_node2 = (*head);
	i = 0;
	
	// traverse to pos2
	while(i < pos2) {
		if(temp_node2->next == NULL) {
			return EXIT_FAILURE;
		}
		temp_node2 = temp_node2->next;
		i++;
	}
	
	// swap temp node and temp node2
	node *temp_node3 = temp_node->next;
	temp_node->next = temp_node2->next;
	temp_node2->next = temp_node3;
	
	// return success
	return EXIT_SUCCESS;
}