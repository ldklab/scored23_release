int list_remove_item_at_pos(node **head, int pos) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if pos is 0
	if(pos == 0) {
		if((*head)->next == NULL) {
			free(*head);
			*head = NULL;
			return EXIT_SUCCESS;
		}
		
		node *temp_node = (*head)->next;
		free(*head);
		*head = temp_node;
		return EXIT_SUCCESS;
	}
	
	// set up temp node
	node *temp_node = *head;
	int i = 1;
	
	// traverse to pos
	while(i < pos) {
		if(temp_node->next == NULL) {
			return EXIT_FAILURE;
		}
		temp_node = temp_node->next;
		i++;
	}
	
	// check if next node is NULL
	if(temp_node->next == NULL) {
		return EXIT_FAILURE;
	}
	
	// set temp node's next to next node's next
	temp_node->next = temp_node->next->next;
	
	// return success
	return EXIT_SUCCESS;
}