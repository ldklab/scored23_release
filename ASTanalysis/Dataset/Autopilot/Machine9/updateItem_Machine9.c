int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
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
  while (i < pos) {
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
  if (!item_name) {
    return EXIT_SUCCESS;
  }
  // update item_name
  free(temp->item_name);
  temp->item_name = malloc(strlen(item_name) + 1);
  strcpy(temp->item_name, item_name);
  // update price
  temp->price = price;
  // update quantity
  temp->quantity = quantity;
  return EXIT_SUCCESS;
}