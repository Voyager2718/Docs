package trie;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
import java.io.FileWriter;
import java.io.IOException;

public class CompactTrie {
	private Node root;

	protected class Node {
		private List<Node> Child;
		private boolean isEnd, isWord;
		private String value;

		public Node() {
			this.Child = new ArrayList<Node>();
			this.isEnd = false;
			this.isWord = false;
			this.value = "";
		}

		public Node(String c) {
			this.Child = new ArrayList<Node>();
			this.isEnd = false;
			this.isWord = false;
			this.value = c;
		}

		public void addValue(String c) {
			this.value = c;
		}

		public void addChind(Node n) {
			this.Child.add(n);
		}

		public void setIsEnd(boolean b) {
			this.isEnd = b;
		}

		public String getValue() {
			return this.value;
		}

		public Node getChild(String c) {
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

		public int numOfSame(String s) {
			int i = 0;
			for (; i < Math.min(s.length(), this.value.length()); i++)
				if (this.value.charAt(i) != s.charAt(i))
					return i;
			return i;
		}

		public void addWord(String s) {
			if (numOfSame(s) == 0) {
				this.Child.add(new Node(s));
				this.Child.get(0).isEnd = true;
				this.Child.get(0).isWord = true;
				return;
			} else {
				if (this.isEnd) {
					String tmp = this.value;
					this.value = this.value.substring(0, this.numOfSame(s));
					this.Child.add(new Node(tmp.substring(this.numOfSame(s))));
					this.Child.add(new Node(s.substring(this.numOfSame(s))));
					this.isEnd = false;
					this.Child.get(0).isEnd = true;
					this.Child.get(0).isWord = true;
					this.Child.get(1).isEnd = true;
					this.Child.get(1).isWord = true;
				} else {
					String tmp = s.substring(this.numOfSame(s));
					this.getChild(s.substring(0, this.numOfSame(s))).addWord(
							tmp);
					;
				}
			}

		}

		public boolean containWord(String s) {
			return false;
		}

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

	public CompactTrie() {
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

	public void add(String s) throws IllegalStateException {
		if (s.length() < 1)
			throw new IllegalStateException();
		this.root.addWord(s);
	}

	public boolean contains(String s) {
		return this.root.containWord(s);
	}
}
