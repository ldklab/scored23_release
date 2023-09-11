int list_remove_item_at_pos(node **head, int pos) {
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  if (pos == 0) {
    node *curr = *head;
    *head = curr->next;
    free(curr->item_name);
    free(curr);
    return EXIT_SUCCESS;
  }
  node *curr = *head;
  int i = 1;
  for (i = 1; i < pos; i++) {
    if (curr->next == NULL) {
      return EXIT_FAILURE;
    }
    curr = curr->next;
  }
  node *temp = curr->next;
  curr->next = temp->next;
  free(temp->item_name);
  free(temp);
  return EXIT_SUCCESS;
}