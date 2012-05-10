package notesElevesProfesseurs;

abstract class Personne {
	protected final String nom;
	protected final String prenom;

	protected Personne() {
		nom = prenom = null;
	}

	protected Personne(String nom, String prenom) {
		this.nom = nom;
		this.prenom = prenom;
	}

	@Override
	public String toString() {
		return "(" + nom + ", " + prenom + ")";
	}
}