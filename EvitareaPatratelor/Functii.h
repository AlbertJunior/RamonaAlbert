#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#define min(a,b) a>b?a:b

void calculareCoordonateClick() //Ramona
{
    int i, j;
    for (i=1;i<=numarPatrateleLinie;i++)
        for (j=1;j<=numarPatrateleLinie;j++)
            if (xMouse>=patratel[i][j].x1 && xMouse<=patratel[i][j].x2 &&
                yMouse>=patratel[i][j].y1 && yMouse<=patratel[i][j].y2)
                {
                    liniePatratActual=i;
                    coloanaPatratActual=j;
                }
}

bool clickDoiJucatori(int xMouse, int yMouse) //Diana
{ // verifica daca am facut click pe butonul DoiJucatori
    bool click = 0;
    if (xMouse >= coordonataX1ButonDoiJucatori && xMouse <= coordonataX2ButonDoiJucatori &&
        yMouse >= coordonataY1ButonDoiJucatori && yMouse <= coordonataY2ButonDoiJucatori)
            click = 1;
    return click;
}
bool clickUnJucator(int xMouse, int yMouse) //Diana
{ // verific daca am facut click pe butonul UnJucator
    bool click = 0;
    if (xMouse >= coordonataX1ButonUnJucator && xMouse <= coordonataX2ButonUnJucator &&
        yMouse >= coordonataY1ButonUnJucator && yMouse <= coordonataY2ButonUnJucator)
            click = 1;
    return click;
}
bool clickDescriere(int xMouse, int yMouse) //Diana
{ // verific daca am facut click pe descriere
    bool click = 0;
    if (xMouse >= coordonataX1ButonDescriere && xMouse <= coordonataX2ButonDescriere &&
        yMouse >= coordonataY1ButonDescriere && yMouse <= coordonataY2ButonDescriere)
            click = 1;
    return click;
}
bool clickExit(int xMouse, int yMouse) //Diana
{ //verifica daca am facut click pe butonul EXIT
    bool click = 0;
    if (xMouse >= coordonataX1ButonExit && xMouse <= coordonataX2ButonExit &&
        yMouse >= coordonataY1ButonExit && yMouse <= coordonataY2ButonExit)
            click = 1;
    return click;
}
bool clickDim(int xMouse,int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim && xMouse <= coordonataX2ButonDim &&
        yMouse >= coordonataY1ButonDim && yMouse <= coordonataY2ButonDim)
            click = 1;
    return click;
}
bool clickCul(int xMouse,int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonCul && xMouse <= coordonataX2ButonCul &&
        yMouse >= coordonataY1ButonCul && yMouse <= coordonataY2ButonCul)
            click = 1;
    return click;
}
bool clickDim3(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim3 && xMouse <= coordonataX2ButonDim3 &&
        yMouse >= coordonataY1ButonDim3 && yMouse <= coordonataY2ButonDim3)
            click = 1;
    return click;
}
bool clickDim4(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim4 && xMouse <= coordonataX2ButonDim4 &&
        yMouse >= coordonataY1ButonDim4 && yMouse <= coordonataY2ButonDim4)
            click = 1;
    return click;
}
bool clickDim5(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim5 && xMouse <= coordonataX2ButonDim5 &&
        yMouse >= coordonataY1ButonDim5 && yMouse <= coordonataY2ButonDim5)
            click = 1;
    return click;
}
bool clickDim6(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim6 && xMouse <= coordonataX2ButonDim6 &&
        yMouse >= coordonataY1ButonDim6 && yMouse <= coordonataY2ButonDim6)
            click = 1;
    return click;
}
bool clickDim7(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim7 && xMouse <= coordonataX2ButonDim7 &&
        yMouse >= coordonataY1ButonDim7 && yMouse <= coordonataY2ButonDim7)
            click = 1;
    return click;
}
bool clickDim8(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim8 && xMouse <= coordonataX2ButonDim8 &&
        yMouse >= coordonataY1ButonDim8 && yMouse <= coordonataY2ButonDim8)
            click = 1;
    return click;
}
bool clickDim9(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim9 && xMouse <= coordonataX2ButonDim9 &&
        yMouse >= coordonataY1ButonDim9 && yMouse <= coordonataY2ButonDim9)
            click = 1;
    return click;
}
bool clickDim10(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonDim10 && xMouse <= coordonataX2ButonDim10 &&
        yMouse >= coordonataY1ButonDim10 && yMouse <= coordonataY2ButonDim10)
            click = 1;
    return click;
}

bool clickInapoi(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonInapoi && xMouse <= coordonataX2ButonInapoi &&
        yMouse >= coordonataY1ButonInapoi && yMouse <= coordonataY2ButonInapoi)
            click = 1;
    return click;
}
bool clickSunet(int xMouse, int yMouse)
{
    bool click = 0;
    if (xMouse >= coordonataX1ButonSunet && xMouse <= coordonataX2ButonSunet &&
        yMouse >= coordonataY1ButonSunet && yMouse <= coordonataY2ButonSunet)
            click = 1;
    return click;
}
void afisareSunet()
{
    int lungimeButon = lungimeMax / 5;
    int inaltimeButon = inaltimeMax / 10;
    coordonataX1ButonSunet = lungimeMax-3*lungimeButon/2;
    coordonataY1ButonSunet = inaltimeMax-2*inaltimeButon;
    coordonataX2ButonSunet = lungimeMax-3*lungimeButon/2+lungimeButon/2;
    coordonataY2ButonSunet = inaltimeMax-inaltimeButon;
    if (sunetPornit==1)
        readimagefile(butonInapoi, coordonataX1ButonSunet, coordonataY1ButonSunet, coordonataX2ButonSunet, coordonataY2ButonSunet);
    else
        readimagefile(butonDescriere, coordonataX1ButonSunet, coordonataY1ButonSunet, coordonataX2ButonSunet, coordonataY2ButonSunet);
}

void afisareButonInapoi()
{
    int lungimeButon = lungimeMax / 5;
    int inaltimeButon = inaltimeMax / 10;
    coordonataX1ButonInapoi = lungimeButon/2;
    coordonataY1ButonInapoi = inaltimeMax-2*inaltimeButon;
    coordonataX2ButonInapoi = lungimeButon/2+lungimeButon;
    coordonataY2ButonInapoi = inaltimeMax-inaltimeButon;

    readimagefile(butonInapoi, coordonataX1ButonInapoi, coordonataY1ButonInapoi, coordonataX2ButonInapoi, coordonataY2ButonInapoi);
}
void afisareButoaneMeniu() //Ramona
{
    int lungimeButon = lungimeMax / 5;
    int inaltimeButon = inaltimeMax / 10;
    int distantaDintreDouaButoane = inaltimeButon / 2;
    coordonataX1ButonDoiJucatori = lungimeMax / 2 - lungimeButon / 2;
    coordonataY1ButonDoiJucatori = 2*inaltimeMax / 5 - inaltimeButon / 2;
    coordonataX2ButonDoiJucatori = lungimeMax / 2 + lungimeButon / 2;
    coordonataY2ButonDoiJucatori = 2*inaltimeMax / 5 + inaltimeButon / 2;
    //const char* butonDoiJucatori="play.jpg";
    readimagefile(buton1juc,coordonataX1ButonDoiJucatori, coordonataY1ButonDoiJucatori, coordonataX2ButonDoiJucatori, coordonataY2ButonDoiJucatori);

    coordonataX1ButonUnJucator = coordonataX1ButonDoiJucatori;
    coordonataY1ButonUnJucator = coordonataY1ButonDoiJucatori + distantaDintreDouaButoane + inaltimeButon;
    coordonataX2ButonUnJucator = coordonataX2ButonDoiJucatori;
    coordonataY2ButonUnJucator = coordonataY2ButonDoiJucatori + distantaDintreDouaButoane + inaltimeButon;
    readimagefile(buton2juc,coordonataX1ButonUnJucator, coordonataY1ButonUnJucator, coordonataX2ButonUnJucator, coordonataY2ButonUnJucator);

    coordonataX1ButonDescriere = coordonataX1ButonDoiJucatori;
    coordonataY1ButonDescriere = coordonataY1ButonUnJucator + distantaDintreDouaButoane + inaltimeButon;
    coordonataX2ButonDescriere = coordonataX2ButonDoiJucatori;
    coordonataY2ButonDescriere = coordonataY2ButonUnJucator + distantaDintreDouaButoane + inaltimeButon;
    readimagefile(butonDescriere,coordonataX1ButonDescriere, coordonataY1ButonDescriere, coordonataX2ButonDescriere, coordonataY2ButonDescriere);

    coordonataX1ButonExit = coordonataX1ButonDoiJucatori;
    coordonataY1ButonExit = coordonataY1ButonDescriere + distantaDintreDouaButoane + inaltimeButon;
    coordonataX2ButonExit = coordonataX2ButonDoiJucatori;
    coordonataY2ButonExit = coordonataY2ButonDescriere + distantaDintreDouaButoane + inaltimeButon;
    readimagefile(butonExit,coordonataX1ButonExit, coordonataY1ButonExit, coordonataX2ButonExit, coordonataY2ButonExit);

    afisareSunet();
}


void afisareButoaneAlegere()
{
    readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);
    int lungimeButon = lungimeMax / 5;
    int inaltimeButon = inaltimeMax / 10;;
    coordonataX1ButonDim = lungimeMax / 4 ;
    coordonataY1ButonDim = inaltimeMax / 2;
    coordonataX2ButonDim = lungimeMax / 4 + lungimeButon;
    coordonataY2ButonDim = inaltimeMax / 2 + inaltimeButon;
    readimagefile(butonDim,coordonataX1ButonDim, coordonataY1ButonDim, coordonataX2ButonDim, coordonataY2ButonDim);

    coordonataX1ButonCul = 3*lungimeMax / 4 - lungimeButon;
    coordonataY1ButonCul = inaltimeMax / 2;
    coordonataX2ButonCul = 3*lungimeMax / 4;
    coordonataY2ButonCul = inaltimeMax / 2 + inaltimeButon;
    readimagefile(butonCul,coordonataX1ButonCul, coordonataY1ButonCul, coordonataX2ButonCul, coordonataY2ButonCul);
}
void afisareButoaneAlegereDificultate()
{
    readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);
    readimagefile(butonEasy,coordonataX1ButonDim, coordonataY1ButonDim, coordonataX2ButonDim, coordonataY2ButonDim);
    readimagefile(butonHard,coordonataX1ButonCul, coordonataY1ButonCul, coordonataX2ButonCul, coordonataY2ButonCul);
}

void afisareButoaneFereastraDim() //Diana
{
    int inaltimeButon = inaltimeMax / 4;
    int lungimeButon = inaltimeButon;
    int distantaDintre2Butoane = lungimeButon / 2;

     const char* fundalButoane="fundalButoane.jpg";
     readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);

    coordonataX1ButonDim3 = (lungimeMax-4*lungimeButon-3*distantaDintre2Butoane)/2;//lungimeMax / 4 - distantaDintre2Butoane / 2 -lungimeButon;
    coordonataY1ButonDim3 = inaltimeMax / 2 - distantaDintre2Butoane / 2 - inaltimeButon;
    coordonataX2ButonDim3 = coordonataX1ButonDim3 + lungimeButon;
    coordonataY2ButonDim3 = inaltimeMax / 2 - distantaDintre2Butoane / 2;
    const char* butonDim3="butonDim3.gif";
    readimagefile(butonDim3,coordonataX1ButonDim3, coordonataY1ButonDim3, coordonataX2ButonDim3, coordonataY2ButonDim3);

    coordonataX1ButonDim4 = coordonataX1ButonDim3 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim4 = coordonataY1ButonDim3;
    coordonataX2ButonDim4 = coordonataX2ButonDim3 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim4 = coordonataY2ButonDim3;
    const char* butonDim4 ="butonDim4.gif";
    readimagefile(butonDim4,coordonataX1ButonDim4, coordonataY1ButonDim4, coordonataX2ButonDim4, coordonataY2ButonDim4);

    coordonataX1ButonDim5 = coordonataX1ButonDim4 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim5 = coordonataY1ButonDim4;
    coordonataX2ButonDim5 = coordonataX2ButonDim4 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim5 = coordonataY2ButonDim4;
    const char* butonDim5 ="butonDim5.gif";
    readimagefile(butonDim5,coordonataX1ButonDim5, coordonataY1ButonDim5, coordonataX2ButonDim5, coordonataY2ButonDim5);

    coordonataX1ButonDim6 = coordonataX1ButonDim5 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim6 = coordonataY1ButonDim5;
    coordonataX2ButonDim6 = coordonataX2ButonDim5 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim6 = coordonataY2ButonDim5;
    const char* butonDim6 ="butonDim6.gif";
    readimagefile(butonDim6,coordonataX1ButonDim6, coordonataY1ButonDim6, coordonataX2ButonDim6, coordonataY2ButonDim6);

    coordonataX1ButonDim7 = coordonataX1ButonDim3;
    coordonataY1ButonDim7 = coordonataY1ButonDim3 + inaltimeButon + distantaDintre2Butoane;
    coordonataX2ButonDim7 = coordonataX2ButonDim3;
    coordonataY2ButonDim7 = coordonataY2ButonDim3 + inaltimeButon + distantaDintre2Butoane;
    const char* butonDim7 ="butonDim7.gif";
    readimagefile(butonDim7,coordonataX1ButonDim7, coordonataY1ButonDim7, coordonataX2ButonDim7, coordonataY2ButonDim7);

    coordonataX1ButonDim8 = coordonataX1ButonDim7 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim8 = coordonataY1ButonDim7;
    coordonataX2ButonDim8 = coordonataX2ButonDim7 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim8 = coordonataY2ButonDim7;
    const char* butonDim8 ="butonDim8.gif";
    readimagefile(butonDim8,coordonataX1ButonDim8, coordonataY1ButonDim8, coordonataX2ButonDim8, coordonataY2ButonDim8);

    coordonataX1ButonDim9 = coordonataX1ButonDim8 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim9 = coordonataY1ButonDim8;
    coordonataX2ButonDim9 = coordonataX2ButonDim8 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim9 = coordonataY2ButonDim8;
    const char* butonDim9 ="butonDim9.gif";
    readimagefile(butonDim9,coordonataX1ButonDim9, coordonataY1ButonDim9, coordonataX2ButonDim9, coordonataY2ButonDim9);

    coordonataX1ButonDim10 = coordonataX1ButonDim9 + lungimeButon + distantaDintre2Butoane;
    coordonataY1ButonDim10 = coordonataY1ButonDim9;
    coordonataX2ButonDim10 = coordonataX2ButonDim9 + lungimeButon + distantaDintre2Butoane;
    coordonataY2ButonDim10 = coordonataY2ButonDim9;
    const char* butonDim10 ="butonDim10.gif";
    readimagefile(butonDim10,coordonataX1ButonDim10, coordonataY1ButonDim10, coordonataX2ButonDim10, coordonataY2ButonDim10);
}

void afisareButoaneFereastraCul() // Diana
{
    readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);
    int inaltimeButon = inaltimeMax / 4;
    int lungimeButon = inaltimeButon;
    int distantaDintre2Butoane = lungimeButon / 2;

    readimagefile(culoare1,coordonataX1ButonDim3, coordonataY1ButonDim3, coordonataX2ButonDim3, coordonataY2ButonDim3);
    readimagefile(culoare2,coordonataX1ButonDim4, coordonataY1ButonDim4, coordonataX2ButonDim4, coordonataY2ButonDim4);
    readimagefile(culoare3,coordonataX1ButonDim5, coordonataY1ButonDim5, coordonataX2ButonDim5, coordonataY2ButonDim5);
    readimagefile(culoare4,coordonataX1ButonDim6, coordonataY1ButonDim6, coordonataX2ButonDim6, coordonataY2ButonDim6);
    readimagefile(culoare5,coordonataX1ButonDim7, coordonataY1ButonDim7, coordonataX2ButonDim7, coordonataY2ButonDim7);
    readimagefile(culoare6,coordonataX1ButonDim8, coordonataY1ButonDim8, coordonataX2ButonDim8, coordonataY2ButonDim8);
    readimagefile(culoare7,coordonataX1ButonDim9, coordonataY1ButonDim9, coordonataX2ButonDim9, coordonataY2ButonDim9);
    readimagefile(culoare8,coordonataX1ButonDim10, coordonataY1ButonDim10, coordonataX2ButonDim10, coordonataY2ButonDim10);
}


void mutareCalculator2() // Ramona
{ //strategia de castig
    int i,j;
    int nr=0;
    bool nuPierde=0;
    if (numarPatrateleLinie%2==0) // aleg strategia simetriei fata de axa verticala daca n e par
        {
            i=liniePatratActual;
            j=numarPatrateleLinie-coloanaPatratActual+1;
            matTabla[i][j]=2;
            readimagefile(alDoileaJucator, patratel[i][j].x1,patratel[i][j].y1,patratel[i][j].x2,patratel[i][j].y2);
        }
    else
    {
        if (coloanaPatratActual==numarPatrateleLinie-coloanaPatratActual+1) //daca pun pe coloana din centru, calculatorul pune
            {                                                           // aleatoriu intr o casuta libera daca acesta nu pierde
                i = rand()%numarPatrateleLinie+1;
                j = rand()%numarPatrateleLinie+1;
                while (nuPierde==0 && nr<1000)
                {
                    nr++;
                    while (matTabla[i][j]!=0)
                    {
                        i = rand()%numarPatrateleLinie+1;
                        j = rand()%numarPatrateleLinie+1;
                    }
                    matTabla[i][j]=2;
                    if (verificarea(i, j)==1) nuPierde=1;
                        else
                        {
                            matTabla[i][j]=0;
                            i = rand()%numarPatrateleLinie+1;
                            j = rand()%numarPatrateleLinie+1;
                        }
                }
                matTabla[i][j]=2;
                readimagefile(alDoileaJucator, patratel[i][j].x1,patratel[i][j].y1,patratel[i][j].x2,patratel[i][j].y2);
                if (nuPierde==0)
                {
                    if (verificarea(i, j)==0) stareJoc=pierdere2;
                }
            }
        else // daca pun pe orice alta pozitie incerc sa pun tot simetric fara de centru, dar daca nu pot pun aleatoriu fara sa piarda calculatorul
            {
                i=liniePatratActual;
                j=numarPatrateleLinie-coloanaPatratActual+1;
                int nr=0;
                while (nuPierde==0 && nr<1000)
                {
                    nr++;
                    while (matTabla[i][j]!=0)
                    {
                        i = rand()%numarPatrateleLinie+1;
                        j = rand()%numarPatrateleLinie+1;
                    }
                    matTabla[i][j]=2;
                    if (verificarea(i, j)==1)
                        nuPierde=1;
                    else {
                            matTabla[i][j]=0;
                            i = rand()%numarPatrateleLinie+1;
                            j = rand()%numarPatrateleLinie+1;
                         }
                }
                matTabla[i][j]=2;
                if(sunetPornit == 1)
                        PlaySound(TEXT("click1.wav"),NULL, SND_SYNC);
                readimagefile(alDoileaJucator, patratel[i][j].x1,patratel[i][j].y1,patratel[i][j].x2,patratel[i][j].y2);
                if (nuPierde==0)
                {
                    if (verificarea(i, j)==0) stareJoc=pierdere2;
                }
            }
    }
}

void mutareCalculator1() // Diana
{ //strategia de castig
    int i,j;
    // aleatoriu intr o casuta libera daca acesta nu pierde
    i = rand()%numarPatrateleLinie+1;
    j = rand()%numarPatrateleLinie+1;
    while (matTabla[i][j]!=0)
    {
        i = rand()%numarPatrateleLinie+1;
        j = rand()%numarPatrateleLinie+1;
    }
    matTabla[i][j]=2;
    if(sunetPornit == 1)
            PlaySound(TEXT("click1.wav"),NULL, SND_SYNC);
    readimagefile(alDoileaJucator, patratel[i][j].x1,patratel[i][j].y1,patratel[i][j].x2,patratel[i][j].y2);
    if (verificarea(i, j)==0) stareJoc=pierdere2;
}



bool verificarea(int liniePatratActual, int coloanaPatratActual) //Diana
{
    bool esteCorect=1;
    if (verificareDreaptaSus(liniePatratActual, coloanaPatratActual)==0) esteCorect=0;
    if (verificareStangaSus(liniePatratActual, coloanaPatratActual)==0) esteCorect=0;
    if (verificareDreaptaJos(liniePatratActual, coloanaPatratActual)==0) esteCorect=0;
    if (verificareStangaJos(liniePatratActual, coloanaPatratActual)==0) esteCorect=0;
    if (verificareRotatie(liniePatratActual, coloanaPatratActual)==0) esteCorect=0;
    return esteCorect;
}

void initializareTabla(int n) //Impreuna
{
    int i, j;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            matTabla[i][j]=0;
    precalculareCoordonate();
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            {
                patratel[i][j].x1 = margineStanga + latPatratel*(j-1) + j - 1;
                patratel[i][j].y1 = margineSuperioara + latPatratel*(i-1) + i - 1;
                patratel[i][j].x2 = margineStanga + latPatratel*j + j - 1;
                patratel[i][j].y2 = margineSuperioara + latPatratel*i + i - 1;
            }
    }

}
bool verificareRotatie(int i, int j)
{
    bool corect=1, gasit=0;
    int lin, col, lin1, col1;
    int pion1X, pion2X, pion1Y, pion2Y;
    int disLin, disCol;
    int pion=matTabla[i][j];
    for(lin1=1;lin1<=numarPatrateleLinie;lin1++)
        for(col1=1;col1<=numarPatrateleLinie;col1++)
            for (lin=1;lin<=numarPatrateleLinie;lin++)
                for (col=1;col<=numarPatrateleLinie;col++)
                {
                    if(matTabla[lin1][col1] == pion){
                        pion1X = lin1;
                        pion1Y = col1;
                        }
                        else
                        continue;
                    if(matTabla[lin][col] == pion){
                        pion2X = lin;
                        pion2Y = col;
                        }
                        else
                        continue;
                    if (pion1X!=pion2X && pion1Y!=pion2Y)
                    {
                        if (pion1Y<pion2Y)
                        {
                            disLin=pion2X-pion1X;
                            disCol=pion2Y-pion1Y;
                            if (matTabla[pion1X+disCol][pion1Y-disLin]==pion &&
                                matTabla[pion2X+disCol][pion2Y-disLin]==pion)
                                {
                                    corect=0;
                                    pierzator1.x=pion1X;
                                    pierzator1.y=pion1Y;
                                    pierzator2.x=pion2X;
                                    pierzator2.y=pion2X;
                                    pierzator3.x=pion1X+disCol;
                                    pierzator3.y=pion1Y-disLin;
                                    pierzator4.x=pion2X+disCol;
                                    pierzator4.y=pion2Y-disLin;
                                }
                        }
                        else
                            if (pion1Y>pion2Y)
                            {
                                disLin=pion2X-pion1X;
                                disCol=pion1Y-pion2Y;
                                if (matTabla[pion1X+disCol][pion1Y+disLin]==pion &&
                                    matTabla[pion2X+disCol][pion2Y+disLin]==pion)
                                   {
                                        corect=0;
                                        pierzator1.x=pion1X;
                                        pierzator1.y=pion1Y;
                                        pierzator2.x=pion2X;
                                        pierzator2.y=pion2Y;
                                        pierzator3.x=pion1X+disCol;
                                        pierzator3.y=pion1Y+disLin;
                                        pierzator4.x=pion2X+disCol;
                                        pierzator4.y=pion2Y+disLin;
                                    }
                            }
                    }
                }
    return corect;
}

bool verificareDreaptaSus(int i, int j) //Diana
{
    int k;
    bool corect=1;
    int pion=matTabla[i][j];
    int laturaMin= min(numarPatrateleLinie-j, i-1);
    for (k=1;k<=laturaMin;k++) // merg pe dimensiuni de la 1 la laturaMin
        {
            if (matTabla[i-k][j]==pion &&
                matTabla[i-k][j+k]==pion &&
                matTabla[i][j+k]==pion)
                    {
                        corect=0;
                        pierzator1.x=i;
                        pierzator1.y=j;
                        pierzator2.x=i-k;
                        pierzator2.y=j;
                        pierzator3.x=i-k;
                        pierzator3.y=j+k;
                        pierzator4.x=i;
                        pierzator4.y=j+k;
                    }
        }
    return corect;
}
bool verificareStangaSus(int i, int j) //Diana
{
    int k;
    bool corect=1;
    int pion=matTabla[i][j];
    int laturaMin= min(j-1, i-1);
    for (k=1;k<=laturaMin;k++)
        {
            if (matTabla[i-k][j]==pion &&
                matTabla[i-k][j-k]==pion &&
                matTabla[i][j-k]==pion)
                    {
                        corect=0;
                        pierzator1.x=i;
                        pierzator1.y=j;
                        pierzator2.x=i-k;
                        pierzator2.y=j;
                        pierzator3.x=i-k;
                        pierzator3.y=j-k;
                        pierzator4.x=i;
                        pierzator4.y=j-k;
                    }
        }
    return corect;
}
bool verificareDreaptaJos(int i, int j) //Diana
{
    int k;
    bool corect=1;
    int pion=matTabla[i][j];
    int laturaMin= min(numarPatrateleLinie-i, numarPatrateleLinie-j);
    for (k=1;k<=laturaMin;k++)
        {
            if (matTabla[i][j+k]==pion &&
                matTabla[i+k][j+k]==pion &&
                matTabla[i+k][j]==pion)
                    {
                        corect=0;
                        pierzator1.x=i;
                        pierzator1.y=j;
                        pierzator2.x=i;
                        pierzator2.y=j+k;
                        pierzator3.x=i+k;
                        pierzator3.y=j+k;
                        pierzator4.x=i+k;
                        pierzator4.y=j;
                    }
        }
    return corect;
}
bool verificareStangaJos(int i, int j) //Diana
{
    int k;
    bool corect=1;
    int pion=matTabla[i][j];
    int laturaMin= min(numarPatrateleLinie-i, j-1);
    for (k=1;k<=laturaMin;k++)
        {
            if (matTabla[i][j-k]==pion &&
                matTabla[i+k][j-k]==pion &&
                matTabla[i+k][j]==pion)
                    {
                        corect=0;
                        pierzator1.x=i;
                        pierzator1.y=j;
                        pierzator2.x=i;
                        pierzator2.y=j-k;
                        pierzator3.x=i+k;
                        pierzator3.y=j-k;
                        pierzator4.x=i+k;
                        pierzator4.y=j;
                    }
                     ///////////////////////////////////////////////////////
        }
    return corect;
}

void desenareTabla() //Ramona
{
    int i, j;

    for (i=1;i<=numarPatrateleLinie;i++)
        for (j=1;j<=numarPatrateleLinie;j++)
            if (matTabla[i][j]==0)
                readimagefile(patratelLiber,patratel[i][j].x1, patratel[i][j].y1, patratel[i][j].x2, patratel[i][j].y2);
            else if (matTabla[i][j]==1)
                readimagefile(primulJucator,patratel[i][j].x1, patratel[i][j].y1, patratel[i][j].x2, patratel[i][j].y2);
            else
                readimagefile(alDoileaJucator,patratel[i][j].x1, patratel[i][j].y1, patratel[i][j].x2, patratel[i][j].y2);

}
void colorarePierdere()
{
    setcolor(RED);
    bar(patratel[pierzator1.x][pierzator1.y].x1-5, patratel[pierzator1.x][pierzator1.y].y1-5,
        patratel[pierzator1.x][pierzator1.y].x1+5, patratel[pierzator1.x][pierzator1.y].y2+5);

    bar(patratel[pierzator1.x][pierzator1.y].x1-5, patratel[pierzator1.x][pierzator1.y].y1-5,
        patratel[pierzator1.x][pierzator1.y].x2+5, patratel[pierzator1.x][pierzator1.y].y1+5);

    bar(patratel[pierzator1.x][pierzator1.y].x2-5, patratel[pierzator1.x][pierzator1.y].y1-5,
        patratel[pierzator1.x][pierzator1.y].x2+5, patratel[pierzator1.x][pierzator1.y].y2+5);

    bar(patratel[pierzator1.x][pierzator1.y].x1-5, patratel[pierzator1.x][pierzator1.y].y2-5,
        patratel[pierzator1.x][pierzator1.y].x2+5, patratel[pierzator1.x][pierzator1.y].y2+5);


    bar(patratel[pierzator2.x][pierzator2.y].x1-5, patratel[pierzator2.x][pierzator2.y].y1-5,
        patratel[pierzator2.x][pierzator2.y].x1+5, patratel[pierzator2.x][pierzator2.y].y2+5);

    bar(patratel[pierzator2.x][pierzator2.y].x1-5, patratel[pierzator2.x][pierzator2.y].y1-5,
        patratel[pierzator2.x][pierzator2.y].x2+5, patratel[pierzator2.x][pierzator2.y].y1+5);

    bar(patratel[pierzator2.x][pierzator2.y].x2-5, patratel[pierzator2.x][pierzator2.y].y1-5,
        patratel[pierzator2.x][pierzator2.y].x2+5, patratel[pierzator2.x][pierzator2.y].y2+5);

    bar(patratel[pierzator2.x][pierzator2.y].x1-5, patratel[pierzator2.x][pierzator2.y].y2-5,
        patratel[pierzator2.x][pierzator2.y].x2+5, patratel[pierzator2.x][pierzator2.y].y2+5);


    bar(patratel[pierzator3.x][pierzator3.y].x1-5, patratel[pierzator3.x][pierzator3.y].y1-5,
        patratel[pierzator3.x][pierzator3.y].x1+5, patratel[pierzator3.x][pierzator3.y].y2+5);

    bar(patratel[pierzator3.x][pierzator3.y].x1-5, patratel[pierzator3.x][pierzator3.y].y1-5,
        patratel[pierzator3.x][pierzator3.y].x2+5, patratel[pierzator3.x][pierzator3.y].y1+5);

    bar(patratel[pierzator3.x][pierzator3.y].x2-5, patratel[pierzator3.x][pierzator3.y].y1-5,
        patratel[pierzator3.x][pierzator3.y].x2+5, patratel[pierzator3.x][pierzator3.y].y2+5);

    bar(patratel[pierzator3.x][pierzator3.y].x1-5, patratel[pierzator3.x][pierzator3.y].y2-5,
        patratel[pierzator3.x][pierzator3.y].x2+5, patratel[pierzator3.x][pierzator3.y].y2+5);


    bar(patratel[pierzator4.x][pierzator4.y].x1-5, patratel[pierzator4.x][pierzator4.y].y1-5,
        patratel[pierzator4.x][pierzator4.y].x1+5, patratel[pierzator4.x][pierzator4.y].y2+5);

    bar(patratel[pierzator4.x][pierzator4.y].x1-5, patratel[pierzator4.x][pierzator4.y].y1-5,
        patratel[pierzator4.x][pierzator4.y].x2+5, patratel[pierzator4.x][pierzator4.y].y1+5);

    bar(patratel[pierzator4.x][pierzator4.y].x2-5, patratel[pierzator4.x][pierzator4.y].y1-5,
        patratel[pierzator4.x][pierzator4.y].x2+5, patratel[pierzator4.x][pierzator4.y].y2+5);

    bar(patratel[pierzator4.x][pierzator4.y].x1-5, patratel[pierzator4.x][pierzator4.y].y2-5,
        patratel[pierzator4.x][pierzator4.y].x2+5, patratel[pierzator4.x][pierzator4.y].y2+5);
}


#endif // FUNCTII_H_INCLUDED
