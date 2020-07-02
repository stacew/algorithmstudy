struct Node
{
    int data;
    struct Node *next;
};

bool has_cycle(Node *head)
{
    int i = 0;
    Node *pTemp = head;

    while (pTemp)
    {
        pTemp = pTemp->next;
        if (++i > 100)
            return true;
    }
    return false;
}