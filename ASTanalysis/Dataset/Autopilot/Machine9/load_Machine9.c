int list_load(node **head, char *filename) {
  FILE *fp;
  if ((fp = fopen(filename, "r")) == NULL) {
    return EXIT_FAILURE;
  }
  char *str = malloc(MAX_ITEM_PRINT_LEN * sizeof(char));
  while (fgets(str, MAX_ITEM_PRINT_LEN, fp)) {
    char *p_char = str;
    unsigned int i = 0;
    node *temp = *head;
    while (*p_char != ',') {
      p_char++;
      i++;
    }
    *p_char = '\0';
    p_char++;
    char *p_char2 = p_char;
    while (*p_char2 != ',') {
      p_char2++;
      i++;
    }
    *p_char2 = '\0';
    p_char2++;
    float price = atof(p_char);
    int quantity = atoi(p_char2);
    list_add_item_at_pos(head, str, price, quantity, i);
  }
  free(str);
  fclose(fp);
  return EXIT_SUCCESS;
}