int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if(head == NULL || item_name == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = *head;
	node *new_node = malloc(sizeof(node));

	if(new_node == NULL) {
		return EXIT_FAILURE;
	}

	new_node->item_name = malloc(sizeof(char) * (strlen(item_name) + 1));
	if(new_node->item_name == NULL) {
		free(new_node);
		return EXIT_FAILURE;
	}

	strcpy(new_node->item_name, item_name);
	new_node->price = price;
	new_node->quantity = quantity;
	new_node->next = NULL;

	// check if pos is valid
	if(pos == 0) {
		return EXIT_FAILURE;
	}

	if(pos == 1) {
		if(*head == NULL) {
			*head = new_node;
		}
		else {
			new_node->next = temp;
			*head = new_node;
		}
		return EXIT_SUCCESS;
	}

	int index = 1;
	while(temp->next != NULL && index < pos - 1) {
		temp = temp->next;
		index++;
	}

	if(index == pos - 1) {
		new_node->next = temp->next;
		temp->next = new_node;
		return EXIT_SUCCESS;
	}
	else {
		return EXIT_FAILURE;
	}	
}