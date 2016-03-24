package logicline.modeleSemantique;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Variable extends Formule {
    private String variable;

    public Variable(Formule f) {
        variable = f.toString();
    }

    public String toString() {
        return variable;
    }

    public Set<String> variablesLibres() {
        Set<String> s = new HashSet<String>();
        s.add(variable);
        return s;
    }

    public Formule substitue(Substitution s) {
        return s.get(this.toString());
    }

    public boolean valeur() throws VariableLibreException {
        return true;
    }
}
