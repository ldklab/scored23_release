int list_find_highest_price_item_position(node *head, int *pos) {
  node *temp = head;
  // check if there is no head
  if (!head) {
    return EXIT_FAILURE;
  }
  // check if there is no next node
  if (!temp->next) {
    return EXIT_SUCCESS;
  }
  // find the highest price node
  while (temp->next) {
    if (temp->price > temp->next->price) {
      temp = temp->next;
    }
  }
  // check if there is no item_name
  if (!temp->item_name) {
    return EXIT_SUCCESS;
  }
  *pos = temp->next->next - temp->next;
  return EXIT_SUCCESS;
}