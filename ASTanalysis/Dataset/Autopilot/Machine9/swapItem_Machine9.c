int list_swap_item_positions(node **head, int pos1, int pos2) {
  node *temp = *head;
  unsigned int i = 0;
  // check if there is no head
  if (!head) {
    return EXIT_FAILURE;
  }
  // check if there is no item_name
  if (!temp) {
    return EXIT_SUCCESS;
  }
  while (i < pos1) {
    // check if there is no next node
    if (!temp->next) {
      return EXIT_SUCCESS;
    }
    temp = temp->next;
    i++;
  }
  // check if there is no next node
  if (!temp->next) {
    return EXIT_SUCCESS;
  }
  // check if there is no item_name
  if (!temp->item_name) {
    return EXIT_SUCCESS;
  }
  node *temp1 = temp;
  node *temp2 = temp;
  while (i < pos2) {
    // check if there is no next node
    if (!temp2->next) {
      return EXIT_SUCCESS;
    }
    temp2 = temp2->next;
    i++;
  }
  // check if there is no next node
  if (!temp2->next) {
    return EXIT_SUCCESS;
  }
  // check if there is no item_name
  if (!temp2->item_name) {
    return EXIT_SUCCESS;
  }
  temp1->next = temp2->next;
  temp2->next = temp;
  temp = temp2;
  return EXIT_SUCCESS;
}