package notesElevesProfesseurs.main;

import notesElevesProfesseurs.Eleve;
import notesElevesProfesseurs.Prof;
import notesElevesProfesseurs.Promotion;
import notesElevesProfesseurs.exceptions.EleveInexistant;

public class Main {
	public static void main(String[] args) {
		
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
		Promotion.liste.add(eleve1);
		Promotion.liste.add(eleve2);
		Promotion.liste.add(eleve3);

		/**
		 * Mettre des notes aux élèves.
		 */
		prof1.setNote(1, 12, 0);
		prof2.setNote(1, 6, 1);
		prof1.setNote(1, 15, 7);
		
		prof1.setNote(2, 11, 0);
		prof1.setNote(2, 19, 0);

		/**
		 * Afficher tous les élèves d'une Promotion.
		 */
		
		try {
			System.out.println(Promotion.rechercher(1));
			System.out.println(Promotion.rechercher(2));
			System.out.println(Promotion.rechercher(3));
			System.out.println(Promotion.rechercher(4));
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

