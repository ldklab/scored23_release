int list_find_highest_price_item_position(node *head, int *pos) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  node *current = head;
  int i = 1;
  float max = 0;
  while (current!= NULL) {
    if (current->price > max) {
      max = current->price;
      *pos = i;
    }
    current = current->next;
    i++;
  }
  return EXIT_SUCCESS;
}