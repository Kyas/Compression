package notesElevesProfesseurs;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

import notesElevesProfesseurs.exceptions.*;

public class Eleve extends Personne implements Comparable<Eleve> {
	static final int NB_EVALUATIONS = 10;

	private final Evaluation notes[] = new Evaluation[NB_EVALUATIONS];

	private final int identifiant;

	public Eleve(String nom, String prenom, int identifiant) {
		super(nom, prenom);
		this.identifiant = identifiant;
	}

	public float moyenne() throws NotesVides {
		int nombreNotes = 0;

		float somme = 0;

		int i = 0;
		while (i < 10) {
			if (getNotes()[i] != null) {
				somme += getNotes()[i].getValeur();
				nombreNotes++;
			}
			i++;
		}

		if (nombreNotes == 0) {
			throw new NotesVides(super.toString() + " n'a pas de notes!");

		} else {
			return somme / nombreNotes;
		}
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();

		sb.append(super.toString()).append(" id: ").append(identifiant)
				.append(" notes: ");
		if(this.getNotes() != null) {
			try {
				sb.append(Arrays.toString(getNotes())).append(" Moyenne: ").append(this.moyenne());
			} catch (NotesVides e) {
				System.err.println(super.toString() + " n'a pas de notes !");
			}
		}
		return sb.toString();
	}

	public Set<Prof> getCorrecteurs() {
		Set<Prof> liste = new HashSet<Prof>();

		for (int i = 0; i < getNotes().length; i++) {
			if (getNotes()[i] != null)
				liste.add(getNotes()[i].getCorrecteur());
		}
		return liste;
	}

	@Override
	public int compareTo(Eleve eleve) {
		float moyenne1 = 0;
		float moyenne2 = 0;

		try {
			moyenne1 = this.moyenne();
			moyenne2 = eleve.moyenne();
		} catch (NotesVides e) {
			e.getMessage();
		}

		if (moyenne1 > moyenne2)
			return -1;
		if (moyenne1 == moyenne2)
			return 0;
		return 1;
	}

	public Evaluation[] getNotes() {
		return notes;
	}

	public int getIdentifiant() {
		return identifiant;
	}
}