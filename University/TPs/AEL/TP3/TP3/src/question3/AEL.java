package question3;

public class AEL {
	private static int[] calculerFonctionPrefixe(String motif) {
		int[] pref = new int[motif.length()];
		pref[0] = 0;
		int k = 0;
		for (int q = 2; q < motif.length(); q++) {
			while (k > 0 && motif.charAt(k) != motif.charAt(q - 1)) {
				k = pref[k];
			}
			if (motif.charAt(k) == motif.charAt(q - 1))
				k = k + 1;
			pref[q] = k;
		}
		return pref;
	}

	private static int KMPAlgorithm(String motif, String text) {
		if (motif.length() == 0)
			return 0;
		int[] pref = new int[motif.length()];
		pref = pref(motif);
		int q = 0;
		for (int i = 0; i < text.length() - 1; i++) {
			while (q > 0 && motif.charAt(q) != text.charAt(i))
				q = pref[q];
			if (motif.charAt(q) == text.charAt(i))
				q++;
			if (q == motif.length())
				return i - motif.length() + 1;
		}
		return -1;
	}

	public static int[] pref(String motif) {
		return calculerFonctionPrefixe(motif);
	}

	public static int KMP(String motif, String text) {
		return KMPAlgorithm(motif, text);
	}

	public static void main(String args[]) {
		int[] pref = AEL.pref("abcabcaba");
		for (int i = 0; i < pref.length; i++)
			System.out.print(pref[i] + " ");
		System.out.println();
		System.out.println(KMP("abcd", "efefefefabcdefef"));
	}
}
