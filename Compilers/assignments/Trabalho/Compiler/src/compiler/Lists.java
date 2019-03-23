package compiler;

import java.util.Iterator;
import java.util.LinkedList;

public class Lists<T extends Token>
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
