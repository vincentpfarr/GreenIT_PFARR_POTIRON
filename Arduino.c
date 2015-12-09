// le potentiom�tre, branch� sur la broche analogique 0
const int potar = 0;
//variable pour stocker la valeur lue apr�s conversion
int valeurLue;
//on convertit cette valeur en une tension
float tension;
float puissance;
float intensite;
void setup()
{
    //on se contente de d�marrer la liaison s�rie
    Serial.begin(9600);
}

void loop()
{
    //on convertit en nombre binaire la tension lue en sortie du potentiom�tre
    valeurLue = analogRead(potar);
    
    //on traduit la valeur brute en tension (produit en croix)
    tension = valeurLue * 3.0 / 1023;    
    intensite = (tension / 0.2) /10 ; 
    puissance = 5 * (tension / 0.2);
    
    //on affiche la valeur lue sur la liaison s�rie
    Serial.print("valeurLue = ");
    Serial.println(valeurLue);
    
    //on affiche la tension calcul�e
    Serial.print("Tension = ");
    Serial.print(tension,5);
    Serial.println(" V");

     Serial.print("Intensite = ");
    Serial.print(intensite,5);
    Serial.println(" mA");

    Serial.print("Puissance = ");
    Serial.print(puissance,5);
    Serial.println(" W");
    
    //on saute une ligne entre deux affichages
    Serial.println();
    //on attend une demi-seconde pour que l'affichage ne soit pas trop rapide
    delay(500);
}
