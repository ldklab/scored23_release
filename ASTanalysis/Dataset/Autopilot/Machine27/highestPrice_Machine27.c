int list_find_highest_price_item_position(node *head, int *pos) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  float highest_price = head->price;
  int highest_pos = 0;
  int i = 0;
  while (head != NULL) {
    if (head->price > highest_price) {
      highest_price = head->price;
      highest_pos = i;
    }
    head = head->next;
    i++;
  }
  *pos = highest_pos;
  return EXIT_SUCCESS;
}