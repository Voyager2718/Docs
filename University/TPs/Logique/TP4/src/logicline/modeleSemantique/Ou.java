package logicline.modeleSemantique;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Ou extends Formule {
    private Formule formuleGauche;
    private Formule formuleDroite;

    public Ou(Formule fg, Formule fd) {
        formuleGauche = fg;
        formuleDroite = fd;
    }

    public String toString() {
        return "(" + formuleGauche.toString() + ")" + "∨" + "(" + formuleDroite.toString() + ")";
    }

    public Set<String> variablesLibres() {
        Set<String> s = new HashSet<String>();
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