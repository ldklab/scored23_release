int list_item_to_string(node *head, char *str)
{
    // TODO: Implement this function,
    if (head == NULL)
    {   str = "";
        return EXIT_FALIURE;
    }

    node *curr = head;
    while (curr != NULL)
    {
        sprintf(str, "%d * %s @ $%.2f ea", curr->quantity, curr->item_name, curr->price);
        curr = curr->next;
    }
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}