int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  // Check if pos is 0
  if (pos == 0) {
    return EXIT_FAILURE;
  }

  // Else pos is not 0
  else {
    // Check if pos is 1
    if (pos == 1) {
      node *temp;
      temp = malloc(sizeof(node));
      temp->item_name = malloc(strlen(item_name) + 1);
      strcpy(temp->item_name, item_name);
      temp->price = price;
      temp->quantity = quantity;
      temp->next = *head;
      *head = temp;
      return EXIT_SUCCESS;
    }
    // Else pos is not 1
    else {
      // Call list_add_item_at_pos on head->next and add the result
      list_add_item_at_pos(&((*head)->next), item_name, price, quantity, pos - 1);
      return EXIT_SUCCESS;
    }
  }
}