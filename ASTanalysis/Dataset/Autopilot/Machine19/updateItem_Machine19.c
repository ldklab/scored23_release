int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if(head == NULL || item_name == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = *head;
	if(pos == 0) {
		return EXIT_FAILURE;
	}

	int index = 1;
	while(temp->next != NULL && index < pos - 1) {
		temp = temp->next;
		index++;
	}

	if(index == pos - 1) {
		if(temp->next == NULL) {
			return EXIT_FAILURE;
		}
		else {
			if(temp->next->item_name != NULL) {
				free(temp->next->item_name);
			}
			temp->next->item_name = malloc(sizeof(char) * (strlen(item_name) + 1));
			temp->next->price = price;
			temp->next->quantity = quantity;
			return EXIT_SUCCESS;
		}
	}
	else {
		return EXIT_FAILURE;
	}
}