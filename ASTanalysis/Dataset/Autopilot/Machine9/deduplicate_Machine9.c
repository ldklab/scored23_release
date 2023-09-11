int list_deduplicate(node **head) {
  node *temp = *head;
  // check if there is no head
  if (!head) {
    return EXIT_FAILURE;
  }
  // check if there is no next node
  if (!temp->next) {
    return EXIT_SUCCESS;
  }
  // check if there is no item_name
  if (!temp->item_name) {
    return EXIT_SUCCESS;
  }
  // de-duplicate the list
  while (temp->next) {
    if (strcmp(temp->item_name, temp->next->item_name) == 0) {
      temp->quantity += temp->next->quantity;
      temp->next = temp->next->next;
    } else {
      temp = temp->next;
    }
  }
  return EXIT_SUCCESS;
}