package trie;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.io.FileWriter;
import java.io.IOException;

/**
 * 
 * @author YANG and Zingoucai
 *
 */
public class Trie {
	private Node root;

	/**
	 * The node of a trie.
	 * 
	 */
	protected class Node {
		private List<Node> Child;
		private boolean isEnd, isWord;
		private char value;

		public Node() {
			this.Child = new ArrayList<Node>();
			this.isEnd = false;
			this.isWord = false;
			this.value = 0;
		}

		public Node(char c) {
			this.Child = new ArrayList<Node>();
			this.isEnd = false;
			this.isWord = false;
			this.value = c;
		}

		public void addValue(char c) {
			this.value = c;
		}

		public void addChild(Node n) {
			this.Child.add(n);
		}

		public void setIsEnd(boolean b) {
			this.isEnd = b;
		}

		public char getValue() {
			return this.value;
		}

		/**
		 * 
		 * @param c
		 * @return the node that the value is equal to c
		 */
		public Node getChild(char c) {
			for (Iterator<Node> iter = this.Child.iterator(); iter.hasNext();) {
				Node tmpNode = iter.next();
				if (tmpNode.getValue() == c)
					return tmpNode;
			}
			return null;
		}

		public boolean getIsEnd() {
			return this.isEnd;
		}

		public boolean getIsWord() {
			return this.isWord;
		}

		/**
		 * The function to add a value.
		 * 
		 * @param s
		 */
		public void addWord(String s) {
			Node tmp = this.getChild(s.charAt(0));
			if (s.length() == 1) {
				if (tmp == null) {
					this.Child.add(new Node(s.charAt(0)));
					this.Child.get(0).isEnd = true;
					this.Child.get(0).isWord = true;
					return;
				} else
					tmp.isWord = true;
			} else {
				if (tmp == null) {
					this.isEnd = false;
					this.Child.add(new Node(s.charAt(0)));
					this.getChild(s.charAt(0)).addWord(s.substring(1));
				} else {
					this.getChild(s.charAt(0)).addWord(s.substring(1));
				}
			}
		}

		/**
		 * return if a String s is saved in the trie.
		 * 
		 * @param s
		 * @return
		 */
		public boolean containWord(String s) {
			if (s.length() == 1)
				if (this.isWord == true)
					return true;
				else
					return false;
			else if (this.getChild(s.charAt(0)) == null)
				return false;
			else
				this.getChild(s.charAt(0)).containWord(s.substring(1));
			return false;
		}

		/**
		 * The function to print dot.
		 * 
		 * @param i
		 * @param writer
		 *            :The FileWriter.
		 * @return
		 */
		public int print(Integer i, FileWriter writer) {
			try {
				int i2 = i;
				if (this.isWord)
					writer.write((i + 1) + " [style=filled,color=blue];\n");
				else
					writer.write((i + 1) + " [style=filled,color=pink];\n");

				for (Iterator<Node> iter = this.Child.iterator(); iter
						.hasNext();) {
					Node tmp = iter.next();
					writer.write(i + "->" + (i + 1) + " [label=\""
							+ tmp.getValue() + "\"];\n");
					i = tmp.print(++i, writer);
					if (i2 < this.Child.size())
						writer.write(i2 + "->" + (i + 1) + " [label=\""
								+ tmp.getValue() + "\"];\n");
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			return i;
		}
	}

	/**
	 * Initialize with just a root.
	 */
	public Trie() {
		root = new Node();
	}

	public void print() {
		try {
			FileWriter writer = new FileWriter("dot.dot", true);
			writer.write("digraph G{\n");
			this.root.print(0, writer);
			writer.write("}");
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * If the length of String is smaller than 1, throw IllegalStateException.
	 * @param s
	 * @throws IllegalStateException
	 */
	public void add(String s) throws IllegalStateException {
		if (s.length() < 1)
			throw new IllegalStateException();
		this.root.addWord(s);
	}

	/**
	 * Return if a String is saved in the trie.
	 * @param s
	 * @return
	 */
	public boolean contains(String s) {
		return this.root.containWord(s);
	}
}
