package notesElevesProfesseurs.main;

import notesElevesProfesseurs.Eleve;
import notesElevesProfesseurs.Prof;
import notesElevesProfesseurs.Promotion;
import notesElevesProfesseurs.exceptions.EleveInexistant;

public class Main {
	public static void main(String[] args) {
		
		Promotion p1 = new Promotion();

		/**
		 * Créer 4 élèves et 2 professeurs.
		 */
		Eleve eleve1 = new Eleve("Jean", "Duval", 1);
		Eleve eleve2 = new Eleve("Pierre", "Pons", 2);
		Eleve eleve3 = new Eleve("Paul", "Durand", 3);
		
		Prof prof1 = new Prof("Tournesol", "Soleil");
		Prof prof2 = new Prof("La Menace", "Max");
		
		/**
		 * Ranger les élèves dans leur promotion.
		 */
		p1.add(eleve1);
		p1.add(eleve2);
		p1.add(eleve3);

		/**
		 * Mettre des notes aux élèves.
		 */
		prof1.setNote(p1, 1, 12, 0);
		prof2.setNote(p1, 1, 6, 1);
		prof1.setNote(p1, 1, 15, 7);
		
		prof1.setNote(p1, 2, 11, 0);
		prof1.setNote(p1, 2, 19, 0);

		/**
		 * Afficher tous les élèves d'une Promotion.
		 */
		
		try {
			System.out.println(p1.rechercher(1));
			System.out.println(p1.rechercher(2));
//			System.out.println(p1.rechercher(3));
//			System.out.println(p1.rechercher(4));
			System.out.println(p1);
		} catch (EleveInexistant e) {
			System.out.println(e.getMessage());
		}
//
//		try {
//			System.out.println(eleve1.moyenne());
//			System.out.println(eleve2.moyenne());
//			System.out.println(eleve3.moyenne());
//		} catch (NotesVides e) {
//			System.out.println(e.getMessage());
//		}
//
//		System.out.println();
//		System.out.println("AVANT LE TRI:\n" + Promotion.liste);
//		Prof.triEleves();
//		System.out.println("APRES LE TRI:\n" + Promotion.liste);
	}
}

