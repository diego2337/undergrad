/*int BinaryTree::height(Node *p)
{
    int counter;
    counter = 0;
    if(p->lft == NULL && p->rgt == NULL)
    {
        p = p->parent;
        counter++;
    }
    if(p->lft == NULL && p->rgt == NULL && p->parent == NULL)
    {
        return counter;
    }
    else if(p->rgt == NULL)
    {
        p = p->lft;
        height(p);
    }
    else if(p->lft == NULL)
    {
        p = p->rgt;
        height(p);
    }
}

int BinaryTree::height2(Node *p)
{
    int counteright;
    counteright = 0;
    if(p->lft == NULL && p->rgt == NULL)
    {
        p = p->parent;
        counteright++;
    }
    if(p->lft == NULL && p->rgt == NULL && p->parent == NULL)
    {
        return counteright;
    }
    else if(p->lft == NULL)
    {
        p = p->rgt;
        height2(p);
    }
}/*