#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <cstdlib>

#include<windows.h> // BIBLIOTECA PT MUZICA
#include<mmsystem.h> //BIBLIOTECA PT MUZICA   PlaySound(TEXT("MuzicaFundal2.wav"),NULL, SND_SYNC);
#define NMAX 20

#include "Initializari.h"
#include "Functii.h"


using namespace std;

int main()
{

    initializareFereastra();
    incarcareImagini(); //Diana
    meniu();
    closegraph();

    return 0;
}
void meniu() //Ramona
{
    int exit=0;
    readimagefile(fundalMeniu,0,0, lungimeMax, inaltimeMax);
    afisareButoaneMeniu(); //Diana
    while (exit==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickDoiJucatori(xMouse, yMouse)) //Diana
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        jocInDoi();
                    }else//Ramona
                if (clickUnJucator(xMouse, yMouse)) //Diana
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        jocCuCalculatorul(); //Impreuna
                    }else
                if (clickDescriere(xMouse, yMouse))
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        descriere();
                    }else
                if (clickExit(xMouse, yMouse)) //Diana
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        exit=1;
                    }else
                if (clickSunet(xMouse, yMouse)) //Diana
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        sunetPornit=1-sunetPornit;
                        afisareSunet();
                    }//Ramona
            }
    }
}

void jocCuCalculatorul() //Impreuna
{
    int i, j;
    stareJoc=joc2;
    pregatireIncepereJoc();
    initializareTabla(numarPatrateleLinie);
    readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);
    desenareTabla();
    while (stareJoc==joc2)///////////////////////////////
    {
        if (ismouseclick(WM_LBUTTONDOWN) && numarPiesePeTabla < (numarPatrateleLinie*numarPatrateleLinie)+1)
        {
            getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
            calculareCoordonateClick();
            if (matTabla[liniePatratActual][coloanaPatratActual]==0)
            {
                if(sunetPornit == 1)
                        PlaySound(TEXT("click1.wav"),NULL, SND_SYNC);
                matTabla[liniePatratActual][coloanaPatratActual]=1;
                readimagefile(primulJucator, patratel[liniePatratActual][coloanaPatratActual].x1,
                                           patratel[liniePatratActual][coloanaPatratActual].y1,
                                           patratel[liniePatratActual][coloanaPatratActual].x2,
                                           patratel[liniePatratActual][coloanaPatratActual].y2);
                numarPiesePeTabla++;

                if (verificarea(liniePatratActual, coloanaPatratActual)==0)
                    stareJoc=pierdere1;
                else if (numarPiesePeTabla<numarPatrateleLinie*numarPatrateleLinie)
                {
                    delay(500);
                    if (dificultatea==dificultatea1)
                        mutareCalculator1();
                    else
                        mutareCalculator2();
                    numarPiesePeTabla++;
                }
            }
        }
         if (numarPiesePeTabla >= (numarPatrateleLinie*numarPatrateleLinie) && stareJoc==joc2)
            stareJoc = remiza;
    }
    if (stareJoc==pierdere1)
    {
        colorarePierdere();
        delay(3000);
        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalCalculator, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    else if (stareJoc==pierdere2)
    {
        colorarePierdere();
        delay(3000);
        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalCastigator, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    else
    {
        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalRemiza, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    meniu();
}

void jocInDoi() //Ramona
{
    int i, j;
    stareJoc=joc1;
    int jucatorActual = 1;
    pregatireIncepereJoc();
    initializareTabla(numarPatrateleLinie);
    readimagefile(fundalButoane, 0, 0, lungimeMax, inaltimeMax);
    desenareTabla();
    while (stareJoc!=pierdere1 && stareJoc!=pierdere2 && stareJoc!=remiza)
    {
        if (ismouseclick(WM_LBUTTONDOWN) && numarPiesePeTabla < (numarPatrateleLinie*numarPatrateleLinie))
        {
            getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
            calculareCoordonateClick();
            if (matTabla[liniePatratActual][coloanaPatratActual]==0)
            {
                numarPiesePeTabla++;
                if (jucatorActual==1)
                {
                    matTabla[liniePatratActual][coloanaPatratActual]=1;

                    if (verificarea(liniePatratActual, coloanaPatratActual)==0)
                        stareJoc=pierdere1;
                    jucatorActual=2;
                }
                else
                {
                    matTabla[liniePatratActual][coloanaPatratActual]=2;
                    if (verificarea(liniePatratActual, coloanaPatratActual)==0)
                        stareJoc=pierdere2;
                    jucatorActual=1;
                }
                if(sunetPornit == 1)
                    PlaySound(TEXT("click1.wav"),NULL, SND_SYNC);

                if (jucatorActual==2)
                    readimagefile(primulJucator, patratel[liniePatratActual][coloanaPatratActual].x1,
                                           patratel[liniePatratActual][coloanaPatratActual].y1,
                                           patratel[liniePatratActual][coloanaPatratActual].x2,
                                           patratel[liniePatratActual][coloanaPatratActual].y2);
                else
                    readimagefile(alDoileaJucator, patratel[liniePatratActual][coloanaPatratActual].x1,
                                           patratel[liniePatratActual][coloanaPatratActual].y1,
                                           patratel[liniePatratActual][coloanaPatratActual].x2,
                                           patratel[liniePatratActual][coloanaPatratActual].y2);
                if (numarPiesePeTabla >= (numarPatrateleLinie*numarPatrateleLinie))
                    stareJoc = remiza;
            }
        }
    }
    if (stareJoc==pierdere1)
    {
        colorarePierdere();


        delay(3000);

        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalJuc2, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    else if (stareJoc==pierdere2)
    {
        colorarePierdere();
        delay(3000);

        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalJuc1, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    else
    {
        if(sunetPornit == 1)
                PlaySound(TEXT("game_over.wav"),NULL, SND_SYNC);
        readimagefile(fundalRemiza, 0, 0, lungimeMax, inaltimeMax);
        delay(4000);
    }
    meniu();
}
void descriere()
{
    bool inapoi=0;
    readimagefile(fundalDescriere, 0, 0, lungimeMax, inaltimeMax);
    afisareButonInapoi();
    while(inapoi==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickInapoi(xMouse, yMouse)) //Diana
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        inapoi=1;
                    } //Ramona
            }
    }
    meniu();
    //afisare poze cu detalii frumos colorata
}
void precalculareCoordonate() //Impreuna
{
    margineSuperioara = inaltimeMax / 6;
    inaltimeTablaJoc = 2 * (inaltimeMax) / 3;
    lungimeTablaJoc = inaltimeTablaJoc;
    margineStanga = (lungimeMax-lungimeTablaJoc) / 2;
    latPatratel = lungimeTablaJoc / numarPatrateleLinie ;
}

void initializareFereastra()
{
    initwindow(lungimeMax, inaltimeMax);
}

void pregatireIncepereJoc()
{
    alegereDimensiuneTablaSiCuloriJucatori(); //Impreuna
    numarPiesePeTabla = 0;
}

void alegereDimensiuneTablaSiCuloriJucatori() //Impreuna
{
    int alegere=0;
    bool alegereDimEfectuata=0;
    bool alegereCulEfectuata=0;
    afisareButoaneAlegere();
    while (alegere==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickDim(xMouse, yMouse))
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        alegereDimensiune();
                        alegereDimEfectuata=1;
                        afisareButoaneAlegere();
                    }
                else
                if (clickCul(xMouse, yMouse) && alegereDimEfectuata==1)
                    {
                        if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                        alegereCulori();alegereCulEfectuata=1;
                    }

            }
        if (alegereDimEfectuata==1 && alegereCulEfectuata==1)
            alegere=1;

    }
    if (stareJoc==joc2)
        alegereDificultate();
}

void alegereDificultate() //Impreuna
{
    int alegere=0;
    afisareButoaneAlegereDificultate();
    while (alegere==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickDim(xMouse, yMouse))
                {
                    if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                    alegere=1;
                    dificultatea=dificultatea1;
                }
                else
                if (clickCul(xMouse, yMouse))
                {
                    if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                    alegere=1;
                    dificultatea=dificultatea2;
                }
            }
    }
}

void alegereDimensiune() //Impreuna
{
    int alegere=0;
    afisareButoaneFereastraDim();
    while (alegere==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickDim3(xMouse, yMouse))
                    {numarPatrateleLinie=3;alegere=1;}
                else
                if (clickDim4(xMouse, yMouse))
                    {numarPatrateleLinie=4;alegere=1;}
                else
                if (clickDim5(xMouse, yMouse))
                    {numarPatrateleLinie=5;alegere=1;}
                else
                if (clickDim6(xMouse, yMouse))
                    {numarPatrateleLinie=6;alegere=1;}
                else
                if (clickDim7(xMouse, yMouse))
                    {numarPatrateleLinie=7;alegere=1;}
                else
                if (clickDim8(xMouse, yMouse))
                    {numarPatrateleLinie=8;alegere=1;}
                else
                if (clickDim9(xMouse, yMouse))
                    {numarPatrateleLinie=9;alegere=1;}
                else
                if (clickDim10(xMouse, yMouse))
                    {numarPatrateleLinie=10;alegere=1;}
            }
    }
    if(sunetPornit == 1)
        PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
}

void alegereCulori() //Impreuna
{
    int alegereJucatorUnu=0;
    int alegereJucatorDoi=0;
    afisareButoaneFereastraCul();
    while (alegereJucatorUnu==0 || alegereJucatorDoi==0)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
            {
                if(sunetPornit == 1)
                            PlaySound(TEXT("click2.wav"),NULL, SND_SYNC);
                getmouseclick(WM_LBUTTONDOWN, xMouse, yMouse);
                if (clickDim3(xMouse, yMouse))
                    {primulJucator=culoare1;alegereJucatorUnu=1;}
                else
                if (clickDim4(xMouse, yMouse))
                    {primulJucator=culoare2;alegereJucatorUnu=1;}
                else
                if (clickDim5(xMouse, yMouse))
                    {primulJucator=culoare3;alegereJucatorUnu=1;}
                else
                if (clickDim6(xMouse, yMouse))
                    {primulJucator=culoare4;alegereJucatorUnu=1;}
                else
                if (clickDim7(xMouse, yMouse))
                    {alDoileaJucator=culoare5;alegereJucatorDoi=1;}
                else
                if (clickDim8(xMouse, yMouse))
                    {alDoileaJucator=culoare6;alegereJucatorDoi=1;}
                else
                if (clickDim9(xMouse, yMouse))
                    {alDoileaJucator=culoare7;alegereJucatorDoi=1;}
                else
                if (clickDim10(xMouse, yMouse))
                    {alDoileaJucator=culoare8;alegereJucatorDoi=1;}
            }
    }

}
