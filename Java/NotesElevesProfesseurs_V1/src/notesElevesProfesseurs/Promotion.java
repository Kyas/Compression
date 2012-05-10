package notesElevesProfesseurs;

import java.util.ArrayList;

import notesElevesProfesseurs.exceptions.EleveInexistant;

public class Promotion {
	public static final ArrayList<Eleve> liste = new ArrayList<Eleve> (); 

	public static Eleve rechercher(int identifiant) throws EleveInexistant {
		Eleve e = null;
		boolean trouve = false;
		int i = 0;

		while (i < liste.size() && !trouve) {
			e = liste.get(i);
			if (e.getIdentifiant() == identifiant)
				trouve = true;
			i++;
		}

		if (!trouve) {
			throw new EleveInexistant("Pas d'élève avec l'identifiant " + ++i
					+ " dans la collection");
		} else {
			return e;
		}
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		int i;
		sb.append("Coucou");
		for(i=0; i < liste.size(); i++) {
			sb.append(liste.get(i)).append("\n");
		}
		return sb.toString();
	}
}