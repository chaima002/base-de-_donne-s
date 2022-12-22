#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;// pour eviter le conflits des mots 
//fonction crypté
string crypte(string mots_a_crypte) {
    int x, y, i, j, k, n; string s=mots_a_crypte;
    n = 1;
    int a[10][10]; int f = 4;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = f;
            f = f - 1;
        }
    }
    int temp = (n - s.size() % n) % n;
    for (i = 0; i < temp; i++) {
        s += 'x';
    } k = 0;
    string ans = "";
    while (k < s.size()) {
        for (i = 0; i < n; i++) {
            int sum = 0;
            int temp = k;
            for (j = 0; j < n; j++) {
                sum += (a[i][j] % 26 * (s[temp++] - 'a') % 26) % 26;
                sum = sum % 26;
            } ans += (sum + 'a');
        }   k += n;
    } return  ans;

}

// fonction clean screan
void clearScean()
{
    system("cls");
}
//classes 
class facteur
{
public:
   
    void ajouter(string file,int id, string nom, string prenom, int age, string zone);
    void supprimer(string file,int Line_to_Erase);
    void modiffier(string file, int Line_to_Erase, string word);

private:
   static int id;// donner 
    string nom;
    string prenom;
    int age;
    string zone;



};
class habitant {
public:

    void ajouter(string file, int id, string nom, string prenom, int age, string zone);
    void supprimer(string file, int Line_to_Erase);
    void modiffier(string file,int Line_to_Erase, string word);

private:
    static int id;// donner 
    string nom;
    string prenom;
    int age;
    string zone;

};
class recommande {

   
public:
    int idFacteur;
    int idHabitant;
    string contenu;
    string type;
    recommande(int x, int z, string c);
    void ajouter(string file, int idFacteur, int idHabitants, string contenu, string type);
    void supprimer(string file, int Line_to_Erase);
    
};
 recommande::recommande(int x, int z, string c) { idFacteur = x; idHabitant = z; contenu = c; }
class coli : public recommande {
public:
    string contenu_du_la_lettre;
  
   

};
class lettre : public recommande {
   
public:
    string objet;
    void ajouterL(string file, int idFacteur, int idHabitants, string contenu);
    void supprimerL(string file, int Line_to_Erase);
    

};

class zone {
private:
    string zoneGeo;
public:
    zone( string z) {zoneGeo = z; }

};



//...............................

//..............................
void facteur::ajouter(string file,int id, string nom, string prenom, int age, string zone) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << id << ",";
        myfile << nom << ",";
        myfile << prenom << ",";
        myfile << age << ",";
        myfile << zone << " \n";

        myfile.close();

    }
}
//........................................
void facteur::supprimer(string file,int Line_to_Erase) {
    std::string Buffer = "         \n"; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile(file); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}
//.................................
void facteur::modiffier(string file,int Line_to_Erase, string word) {
    std::string Buffer =crypte( word); //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile("a.txt"); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
};

//..............................
void habitant::ajouter(string file, int id, string nom, string prenom, int age, string zone) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << id << ",";
        myfile << nom << ",";
        myfile << prenom << ",";
        myfile << age << ",";
        myfile << zone << " \n";

        myfile.close();

    }
}
//........................................
void habitant::supprimer(string file, int Line_to_Erase) {
    std::string Buffer = "         \n"; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile(file); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}
//.................................
void habitant::modiffier(string file,int Line_to_Erase, string word) {
    std::string Buffer = crypte(word); //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile("a.txt"); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
};
//..........................................................................................................................
void recommande::ajouter(string file, int idFacteur,int idHabitant, string zone, string type) {
    fstream myfile;
    myfile.open(file, ios::out | ios::app); // write
    if (myfile.is_open())
    {
        myfile << idFacteur << ",";
        myfile << idHabitant << ",";
        myfile << type << ",";
        myfile << contenu << " \n";


        myfile.close();

    }
}
//........................................
void recommande::supprimer(string file, int Line_to_Erase) {
    std::string Buffer = "         \n"; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(file);
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if (Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile(file); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}

//la classe main
int main() {
    int val, age, id, i; string fileName, nom, prenom, zone, mod, filehabitant, filerecommande; facteur fac1; habitant hab1; int idfac;
   
    cout << "saisir un fichier pour sauvegarder la table facteur dedans"; 
    cin >> fileName;  clearScean();
    cout << "saisir un fichier poursauvegarder la table habitant dedans";
    cin >> filehabitant;  clearScean();
    cout << "saisir un fichier pour sauvegarder la table recommandé dedans";
    cin >> filerecommande;  clearScean();


    cout << "pour ajouter un facteur cliquer sur : 1, un habitant : 2";
    cin >> val;
    switch (val) {
    case 1:

        cout << "enter le nom , prénom , age ,id, nom du zone ";
        cin >> nom >> prenom >> age >> id >> zone;
        fac1.ajouter(fileName, id, crypte(nom), crypte(prenom), age, crypte(zone));
        cout << "pour supprimer un facteur cliquer sur:1 ou modifier un facteur cliquer sur:2";
        cin >> val;
        switch (val) {
        case 1:

            cout << "enter le id de facteur qui tu veut supprimer ";
            cin >> i;
            fac1.supprimer(fileName, i);
            break;
        case 2:
            cout << "enter le id de facteur qui tu veut le modifier et les informations à modifier nom,prénom,age,id,nom du zone ";
            cin >> i >> mod;
            fac1.modiffier(fileName,i, mod);

            break;

        }



        break;
       case 2:
        cout << "enter le nom , prénom , age ,id, nom du zone ";
        cin >> nom >> prenom >> age >> id >> zone;
        hab1.ajouter(filehabitant, id, crypte(nom), crypte(prenom), age, crypte(zone));
        int vv;
        cout << "si vous voulez ajouter un colis cliquez sur :1  une lettre :2";
        cin >> vv;
            if (vv == 1)
            {
                cout << "donner id de facteur,l'objet"; cin >> idfac >> nom;
                recommande c(idfac, id, nom); c.ajouter(filerecommande, idfac, id, crypte(nom), "coli");
                cout << "pour supprimer un coli entrer la ligne"; cin >> i;
                c.supprimer(filerecommande, i);

            }; if (vv == 2) {
                cout << "donner le id de facteur,l'objet"; cin >> idfac >> nom;
                recommande l(idfac, id, nom); l.ajouter(filerecommande, idfac, id, crypte(nom),"lettre");
                cout << "pour supprimer une lettre entrer la ligne"; cin >> i;
                    l.supprimer(filerecommande, i);
            }
            cout << "pour supprimer un habitant cliquer sur:1 ou modifier un habitant cliquer sur:2";
            cin >> val;
            switch (val) {
            case 1:

                cout << "enter le id de habitant qui tu veut le supprimer ";
                cin >> i;
                hab1.supprimer(filehabitant, i);
                break;
            case 2:
                cout << "enter le id d'habitant qui tu veut le modifier et les informations à modifier nom,prénom,age,id,nom du zone(les info séparé par ,) ";
                cin >> i >> mod;
                hab1.modiffier(filehabitant,i, mod);

                break;
            }

        break;


    }
    clearScean();
}