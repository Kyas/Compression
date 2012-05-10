package notesElevesProfesseurs;

public class Evaluation {
	private Prof correcteur; 

	private final Eleve corrige; 

	private float valeur;

	public Evaluation (Prof correcteur, Eleve corrige, float valeur) { 
		this.correcteur = correcteur; 
		this.corrige = corrige; 
		this.valeur = valeur;
	}

	@Override
	public String toString() {
		return "(" + getCorrecteur() + "," + getValeur() + ")";
	}

	public Prof getCorrecteur() {
		return correcteur;
	}
	
	public Eleve getCorrige() {
		return corrige;
	}

	public float getValeur() {
		return valeur;
	}

	public void setValeur(float valeur) {
		this.valeur = valeur;
	}

	public void setCorrecteur(Prof correcteur) {
		this.correcteur = correcteur;
	}
}  