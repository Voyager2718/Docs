package logicline.modeleSemantique;

import java.util.HashSet;
import java.util.Set;

public class Constante extends Formule {
    private boolean constante;

    public Constante(boolean b) {
        constante = b;
    }

    public String toString() {
        return constante ? "T" : "⊥";
    }

    public Set<String> variablesLibres() {
        String b;
        if (constante)
            b = "T";
        else
            b = "⊥";
        Set<String> s = new HashSet<>();
        s.add(b);
        return s;
    }

    public Formule substitue(Substitution s) {
        return null;
    }

    public boolean valeur() throws VariableLibreException {
        return true;
    }
}
