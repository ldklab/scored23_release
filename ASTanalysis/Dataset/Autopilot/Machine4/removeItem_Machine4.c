int list_remove_item_at_pos(node **head, int pos) {
  // Check if pos is 0
  if (pos == 0) {
    return EXIT_FAILURE;
  }

  // Else pos is not 0
  else {
    // Check if pos is 1
    if (pos == 1) {
      node *temp;
      temp = *head;
      *head = (*head)->next;
      free(temp);
      return EXIT_SUCCESS;
    }
    // Else pos is not 1
    else {
      // Call list_remove_item_at_pos on head->next and remove the result
      list_remove_item_at_pos(&((*head)->next), pos - 1);
      return EXIT_SUCCESS;
    }
  }
}