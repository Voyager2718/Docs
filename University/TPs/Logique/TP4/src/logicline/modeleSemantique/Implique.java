package logicline.modeleSemantique;

import java.util.Set;

public class Implique extends Formule {
    private Formule formuleGauche;
    private Formule formuleDroite;

    public Implique(Formule fg, Formule fd) {
        formuleGauche = fg;
        formuleDroite = fd;
    }

    public String toString() {
        return "(" + formuleGauche.toString() + ")" + "⇒" + "(" + formuleDroite.toString() + ")";
    }

    public Formule supprImplications() {
        return new Et(
                new Ou(new Non(formuleGauche.supprImplications()), formuleDroite.supprImplications()),
                new Ou(formuleGauche.supprImplications(), new Non(formuleDroite.supprImplications()))
        );
    }

    public Set<String> variablesLibres() {
        return null;
    }

    public Formule substitue(Substitution s) {
        return null;
    }

    public boolean valeur() throws VariableLibreException {
        return true;
    }
}
