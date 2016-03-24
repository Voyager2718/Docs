package logicline.modeleSemantique;

import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Equivalence extends Formule {
    private Formule formuleGauche;
    private Formule formuleDroite;

    public Equivalence(Formule fg, Formule fd) {
        formuleGauche = fg;
        formuleDroite = fd;
    }

    public String toString() {
        return "(" + formuleGauche.toString() + ")" + "⇔" + "(" + formuleDroite.toString() + ")";
    }

    public Set<String> variablesLibres() {
        Set<String> s = new HashSet<String>();
        s.addAll(formuleGauche.variablesLibres());
        s.addAll(formuleDroite.variablesLibres());
        return s;
    }

    public Formule supprImplications() {
        return new Et(
                new Ou(new Non(formuleGauche.supprImplications()), formuleDroite.supprImplications()),
                new Ou(formuleGauche.supprImplications(), new Non(formuleDroite.supprImplications()))
        );
    }

    public Formule substitue(Substitution s) {
        return s.get(this.toString());
    }

    public boolean valeur() throws VariableLibreException {
        return true;
    }
}
