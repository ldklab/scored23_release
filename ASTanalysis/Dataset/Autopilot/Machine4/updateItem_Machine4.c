int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  // Check if pos is 0
  if (pos == 0) {
    return EXIT_FAILURE;
  }

  // Else pos is not 0
  else {
    // Check if pos is 1
    if (pos == 1) {
      (*head)->item_name = malloc(strlen(item_name) + 1);
      strcpy((*head)->item_name, item_name);
      (*head)->price = price;
      (*head)->quantity = quantity;
      return EXIT_SUCCESS;
    }
    // Else pos is not 1
    else {
      // Call list_update_item_at_pos on head->next and update the result
      list_update_item_at_pos(&((*head)->next), item_name, price, quantity, pos - 1);
      return EXIT_SUCCESS;
    }
  }
}