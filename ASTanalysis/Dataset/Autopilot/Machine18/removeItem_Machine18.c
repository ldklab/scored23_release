int list_remove_item_at_pos(node **head, int pos) {
  if (head == NULL) {
    printf("Error: list is empty\n");
    return EXIT_FAILURE;
  }
  node *current = *head;
  if (pos == 1) {
    node *temp = current;
    *head = current->next;
    free(temp);
  } else {
    int i = 1;
    while (current != NULL && i < pos - 1) {
      current = current->next;
      i++;
    }
    node *temp = current;
    current = current->next;
    temp->next = current->next;
    free(current);
  }
  return EXIT_SUCCESS;
}