package trie;

import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

public class Trie {
	private Vertex root;

	protected class Vertex {
		protected int words;
		protected int prefixes;
		protected Vertex[] edges;

		Vertex() {
			this.words = 0;
			this.prefixes = 0;
			edges = new Vertex[26];
			for (int i = 0; i < edges.length; i++)
				edges[i] = null;
		}
	}

	public Trie() {
		root = new Velrtex();
	}
}
