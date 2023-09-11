int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  if (head == NULL || item_name == NULL || item_name[0] == '\0' || quantity <= 0) {
    return EXIT_FAILURE;
  }
  node *curr = *head;
  int i = 1;
  for (i = 1; i < pos; i++) {
    if (curr->next == NULL) {
      return EXIT_FAILURE;
    }
    curr = curr->next;
  }
  free(curr->item_name);
  curr->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
  strcpy(curr->item_name, item_name);
  curr->price = price;
  curr->quantity = quantity;
  return EXIT_SUCCESS;
}