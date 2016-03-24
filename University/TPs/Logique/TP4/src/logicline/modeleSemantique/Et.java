package logicline.modeleSemantique;

import java.util.*;

public class Et extends Formule {
    private Formule formuleGauche;
    private Formule formuleDroite;

    public Et(Formule fg, Formule fd) {
        formuleGauche = fg;
        formuleDroite = fd;
    }

    public String toString() {
        return "(" + formuleGauche.toString() + ")" + "∧" + "(" + formuleDroite.toString() + ")";
    }

    public Set<String> variablesLibres() {
        Set<String> s = new HashSet<>();
        s.addAll(formuleGauche.variablesLibres());
        s.addAll(formuleDroite.variablesLibres());
        return s;
    }

    public Formule substitue(Substitution s) {
        return s.get(this.toString());
    }

    public boolean valeur() throws VariableLibreException {
        return true;
    }
}
