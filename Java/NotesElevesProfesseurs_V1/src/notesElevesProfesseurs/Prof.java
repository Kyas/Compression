package notesElevesProfesseurs;

import java.util.ArrayList;
import java.util.Collections;

import notesElevesProfesseurs.exceptions.EleveInexistant;
import notesElevesProfesseurs.exceptions.NotesVides;

public class Prof extends Personne {

	public Prof(String nom, String prenom) {
		super(nom, prenom);
	}

	public void setNote(Promotion p, int identifiant, float valeur, int index) {
		Eleve corrige = null;
		try {
			corrige = p.rechercher(identifiant);
		} catch (EleveInexistant e) {
			System.out.println("Cet élève est inexistant");
		}
		if (corrige.getNotes()[index] == null)
			corrige.getNotes()[index] = new Evaluation(this, corrige, valeur);
		else {
			corrige.getNotes()[index].setValeur(valeur);
			corrige.getNotes()[index].setCorrecteur(this);
		}
	}

	public static void triEleves(Promotion p) {
		ArrayList<Eleve> listetriee = new ArrayList<Eleve>();
		int i, j;
		Eleve eleve1, eleve2;
		float moy1 = 0, moy2 = 0;

		for (i = 0; i < p.liste.size(); i++) {
			eleve1 = p.liste.get(i);
			try {
				moy1 = eleve1.moyenne();
				listetriee.add(eleve1);
			} catch (NotesVides e1) {
				System.out.println(e1.getMessage());
			}
		}

		for (i = 0; i < listetriee.size() - 1; i++)
			for (j = i + 1; j < listetriee.size(); j++) {
				eleve1 = listetriee.get(i);
				eleve2 = listetriee.get(j);
				try {
					moy1 = eleve1.moyenne();
					moy2 = eleve2.moyenne();
				} catch (NotesVides e) {
					System.out.println(e.getMessage());
				}

				if (moy2 > moy1) {
					listetriee.set(i, eleve2);
					listetriee.set(j, eleve1);
				}
			}

		for (i = 0; i < listetriee.size(); i++) {
			eleve1 = listetriee.get(i);
			try {
				System.out.println(eleve1.nom + " ; " + eleve1.prenom + " ; "
						+ eleve1.moyenne());
			} catch (NotesVides e) {
				System.out.println(e.getMessage());
			}
		}
	}

	public static void sort(Promotion p) {
		Collections.sort(p.liste);
	}
}