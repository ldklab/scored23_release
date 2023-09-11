int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if item_name is NULL
	if(item_name == NULL) {
		return EXIT_FAILURE;
	}
	
	// check if pos is 0
	if(pos == 0) {
		*head = malloc(sizeof(node));
		(*head)->item_name = strdup(item_name);
		(*head)->price = price;
		(*head)->quantity = quantity;
		(*head)->next = NULL;
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
	
	// set temp node's item_name to item_name
	temp_node->item_name = strdup(item_name);
	
	// set temp node's price to price
	temp_node->price = price;
	
	// set temp node's quantity to quantity
	temp_node->quantity = quantity;
	
	// return success
	return EXIT_SUCCESS;
}