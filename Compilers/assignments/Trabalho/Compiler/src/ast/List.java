package ast;

import java.util.LinkedList;
import java.util.Iterator;

public class List<T extends GenericNode>
{
    private LinkedList<T> nodes = new LinkedList<T>();
	
    public void add(T node)
    {
        nodes.add(node);
    }

    public boolean isEmpty()
    {
        return nodes.isEmpty();
    }

    public int size()
    {
        return nodes.size();
    }

    public Iterator<T> iterator()
    {
        return nodes.iterator();
    }
}