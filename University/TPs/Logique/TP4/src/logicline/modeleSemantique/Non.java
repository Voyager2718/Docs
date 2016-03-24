package logicline.modeleSemantique;

import java.util.HashSet;
import java.util.Set;

public class Non extends Formule {
    private Formule formule;

    public Non(Formule f) {
        formule = f;
    }

    public String toString() {
        return "¬" + "(" + formule.toString() + ")";
    }

    public Set<String> variablesLibres() {
        Set<String> s = new HashSet<String>();
        s.addAll(formule.variablesLibres());
        return s;
    }

    @Override
    public Formule substitue(Substitution s) {
        return s.get(this.toString());
    }

    @Override
    public boolean valeur() throws VariableLibreException {
        return false;
    }
}
