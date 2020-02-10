#ifndef INITIALIZARI_H_INCLUDED
#define INITIALIZARI_H_INCLUDED
void initializareFereastra();
void meniu();
void jocInDoi();
void jocCuCalculatorul();
void descriere();
void initializareTabla(int n);
void pregatireIncepereJoc();
void precalculareCoordonate();
void alegereDimensiuneTablaSiCuloriJucatori();
void desenareTabla();
bool verificarea(int liniePatratActual, int coloanaPatratActual);
bool verificareRotatie(int i, int j);
bool verificareDreaptaSus(int i, int j);
bool verificareStangaSus(int i, int j);
bool verificareDreaptaJos(int i, int j);
bool verificareStangaJos(int i, int j);
void afisareButoaneMeniu();
void afisareButoaneAlegere();
void afisareButoaneFereastraDim();
void afisareButoaneFereastraCul();
bool clickDoiJucatori(int xMouse, int yMouse);
bool clickUnJucator(int xMouse, int yMouse);
bool clickDescriere(int xMouse, int yMouse);
bool clickExit(int xMouse, int yMouse);
bool clickDim(int xMouse,int yMouse);
bool clickCul(int xMouse,int yMouse);
bool clickDim3(int xMouse, int yMouse);
bool clickDim4(int xMouse, int yMouse);
bool clickDim5(int xMouse, int yMouse);
bool clickDim6(int xMouse, int yMouse);
bool clickDim7(int xMouse, int yMouse);
bool clickDim8(int xMouse, int yMouse);
bool clickDim9(int xMouse, int yMouse);
bool clickDim10(int xMouse, int yMouse);
void mutareCalculator();
void alegereDimensiune();
void alegereCulori();
void alegereDificultate();
void colorarePierdere();

int matTabla[NMAX][NMAX];
const int lungimeMax=getmaxwidth();
const int inaltimeMax=getmaxheight();
const int pierdere1 = 1;
const int pierdere2 = -1;
const int remiza = 2;
const int joc = 0;
const int dificultatea1 = 1;
const int dificultatea2 = 2;
const int joc1 =100;
const int joc2 =200;
int dificultatea = 0;
int numarPatrateleLinie=6;
int stareJoc=0;

int xMouse;
int yMouse;

int margineSuperioara;
int margineStanga;
int inaltimeTablaJoc;
int lungimeTablaJoc;
int latPatratel;
int coloanaPatratActual;
int liniePatratActual;
int numarPiesePeTabla;

int coordonataX1ButonDoiJucatori;
int coordonataY1ButonDoiJucatori;
int coordonataX2ButonDoiJucatori;
int coordonataY2ButonDoiJucatori;

int coordonataX1ButonUnJucator;
int coordonataY1ButonUnJucator;
int coordonataX2ButonUnJucator;
int coordonataY2ButonUnJucator;

int coordonataX1ButonDescriere;
int coordonataY1ButonDescriere;
int coordonataX2ButonDescriere;
int coordonataY2ButonDescriere;

int coordonataX1ButonExit;
int coordonataY1ButonExit;
int coordonataX2ButonExit;
int coordonataY2ButonExit;

int coordonataX1ButonDim;
int coordonataY1ButonDim;
int coordonataX2ButonDim;
int coordonataY2ButonDim;


int coordonataX1ButonCul;
int coordonataY1ButonCul;
int coordonataX2ButonCul;
int coordonataY2ButonCul;

int coordonataX1ButonDim3;
int coordonataY1ButonDim3;
int coordonataX2ButonDim3;
int coordonataY2ButonDim3;

int coordonataX1ButonDim4;
int coordonataY1ButonDim4;
int coordonataX2ButonDim4;
int coordonataY2ButonDim4;

int coordonataX1ButonDim5;
int coordonataY1ButonDim5;
int coordonataX2ButonDim5;
int coordonataY2ButonDim5;

int coordonataX1ButonDim6;
int coordonataY1ButonDim6;
int coordonataX2ButonDim6;
int coordonataY2ButonDim6;

int coordonataX1ButonDim7;
int coordonataY1ButonDim7;
int coordonataX2ButonDim7;
int coordonataY2ButonDim7;

int coordonataX1ButonDim8;
int coordonataY1ButonDim8;
int coordonataX2ButonDim8;
int coordonataY2ButonDim8;

int coordonataX1ButonDim9;
int coordonataY1ButonDim9;
int coordonataX2ButonDim9;
int coordonataY2ButonDim9;

int coordonataX1ButonDim10;
int coordonataY1ButonDim10;
int coordonataX2ButonDim10;
int coordonataY2ButonDim10;


int coordonataX1ButonInapoi;
int coordonataY1ButonInapoi;
int coordonataX2ButonInapoi;
int coordonataY2ButonInapoi;

int coordonataX1ButonSunet;
int coordonataY1ButonSunet;
int coordonataX2ButonSunet;
int coordonataY2ButonSunet;

const char* patratelLiber = "fundalButon3.jpg";
const char* culoare1 = "bila1.gif";
const char* culoare2 = "bila2.gif";
const char* culoare3 = "bila3.gif";
const char* culoare4 = "bila4.gif";
const char* culoare5 = "bila5.gif";
const char* culoare6 = "bila6.gif";
const char* culoare7 = "bila7.gif";
const char* culoare8 = "bila8.gif";
 const char* fundalButoane="fundalButoane.jpg";
  const char* butonDim="butonDim.gif";
  const char* butonCul="butonCul.gif";
  const char* buton1juc="buton2juc.gif";
  const char* buton2juc="buton1juc.gif";
  const char* butonExit="butonExit.gif";
  const char* butonDescriere="butonDescriere.gif";
  const char* butonInapoi="butonInapoi.gif";
  const char* butonEasy="butonEasy.gif";
  const char* butonHard="butonHard.gif";
const char* fundalRemiza="remiza.jpg";
const char* fundalJuc1="juc1.jpg";
const char* fundalJuc2="juc2.jpg";
const char* fundalCalculator="calculatorul.jpg";
const char* fundalCastigator="castigator.jpg";
const char* fundalMeniu="fundalMeniu.jpg";
const char* fundalDescriere="descriere.jpg";

const char* primulJucator;
const char* alDoileaJucator;

bool sunetPornit = 1;/////////////////////////////////////

struct coordonatePatratele
{
    int x1, y1, x2, y2;
}patratel[NMAX][NMAX];

struct pierzatori
{
    int x, y;
} pierzator1, pierzator2, pierzator3, pierzator4;

void incarcareImagini() //Diana
{
     const char* incarcare2 = "incarcare2.jpg";
      const char* incarcare3 = "incarcare3.jpg";
       const char* incarcare4 = "incarcare4.jpg";
        const char* incarcare5 = "incarcare5.jpg";
         const char* incarcare6 = "incarcare6.jpg";
          const char* incarcare7 = "incarcare7.jpg";
           const char* incarcare8 = "incarcare8.jpg";
            const char* incarcare9 = "incarcare9.jpg";
             const char* incarcare10 = "incarcare10.jpg";
              const char* incarcare11 = "incarcare11.jpg";
               const char* incarcare12 = "incarcare12.jpg";

    readimagefile(incarcare2,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare3,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare4,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare5,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare6,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare7,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare8,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare9,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare10,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare11,0,0, lungimeMax, inaltimeMax);delay(10);
    readimagefile(incarcare12,0,0, lungimeMax, inaltimeMax);delay(10);

    const char* fundalIntro1 = "fundalIntro7.jpg";
    const char* fundalIntro2 = "fundalIntro6.jpg";
    const char* fundalIntro3 = "fundalIntro5.jpg";
    const char* fundalIntro4 = "fundalIntro4.jpg";
    const char* fundalIntro5 = "fundalIntro3.jpg";
    const char* fundalIntro6 = "fundalIntro2.jpg";
    const char* fundalIntro7 = "fundalIntro1.jpg";
    const char* fundalIntro8 = "fundalIntro.jpg";
    readimagefile(fundalIntro1,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro2,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro3,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro4,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro5,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro6,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro7,0,0, lungimeMax, inaltimeMax);delay(5);
    readimagefile(fundalIntro8,0,0, lungimeMax, inaltimeMax);delay(5);
    delay(1000);

}



#endif // INITIALIZARI_H_INCLUDED
