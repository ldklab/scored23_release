int list_swap_item_positions(node **head, int pos1, int pos2) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  node *current = *head;
  if (pos1 == 1) {
    node *temp = current;
    current->quantity = current->quantity + current->next->quantity;
    current->price = current->price + current->next->price;
    current = current->next;
    *head = current->next;
    current->next = temp;
    current->next->next = NULL;
  } else {
    int i = 1;
    while (current != NULL && i < pos1 - 1) {
      current = current->next;
      i++;
    }
    node *temp = current;
    current = current->next;
    temp->next = current->next;
    current->next = temp;
    current->next->next = NULL;
  }
  return EXIT_SUCCESS;
}