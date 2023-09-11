int list_cost_sum(node *head, float *total) {
  node *temp = head;
  // check if there is no head
  if (!head) {
    return EXIT_FAILURE;
  }
  // check if there is no item_name
  if (!temp) {
    return EXIT_SUCCESS;
  }
  *total = 0.0;
  // calculate the total cost
  while (temp) {
    *total += (temp->price * temp->quantity);
    temp = temp->next;
  }
  return EXIT_SUCCESS;
}