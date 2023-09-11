int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if item_name is NULL
	if(item_name == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up new node
	node *new_node = malloc(sizeof(node));
	if(new_node == NULL) {
		return EXIT_FAILURE;
	}
	new_node->item_name = strdup(item_name);
	new_node->price = price;
	new_node->quantity = quantity;
	new_node->next = NULL;
	
	// check if pos is 0
	if(pos == 0) {
		new_node->next = *head;
		*head = new_node;
		return EXIT_SUCCESS;
	}
	
	// set up temp node
	node *temp_node = *head;
	int i = 1;
	
	// traverse to pos
	while(i < pos) {
		if(temp_node->next == NULL) {
			free(new_node);
			return EXIT_FAILURE;
		}
		temp_node = temp_node->next;
		i++;
	}
	
	// set new node's next to temp node's next
	new_node->next = temp_node->next;
	
	// set temp node's next to new node
	temp_node->next = new_node;
	
	// return success
	return EXIT_SUCCESS;
}