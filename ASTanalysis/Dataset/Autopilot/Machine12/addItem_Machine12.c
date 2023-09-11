int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
  if (head == NULL || item_name == NULL || item_name[0] == '\0' || quantity <= 0) {
    return EXIT_FAILURE;
  }
  if (pos == 0) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
    strcpy(new_node->item_name, item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = *head;
    *head = new_node;
    return EXIT_SUCCESS;
  }
  node *curr = *head;
  int i = 1;
  for (i = 1; i < pos; i++) {
    if (curr->next == NULL) {
      break;
    }
    curr = curr->next;
  }
  node *new_node = (node *)malloc(sizeof(node));
  new_node->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
  strcpy(new_node->item_name, item_name);
  new_node->price = price;
  new_node->quantity = quantity;
  new_node->next = curr->next;
  curr->next = new_node;
  return EXIT_SUCCESS;
}