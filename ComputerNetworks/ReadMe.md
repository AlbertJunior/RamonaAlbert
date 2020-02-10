# Tema1 RC
----
##MyShell
de Albert Ramona-Georgiana 
II A2



----
## Utilizare


Pentru compilare: make output

Pentru rulare: make execute

Pentru inceput veti alege prin ce doriti sa comunicati:

1 - pipes

2 - mkfifo (canale externe)

3 - sockets

In continuare trebuie sa va logati cu comanda:
'login : user'

Lista cu utilizatorii valizi este in fisierul users.txt. Aceasta poate fi modificata. (O puteti vizualiza cu comanda cat users.txt doar daca sunteti deja logat)

Fara a executa aceasta comanda cu succes (cu un utilizator valid) nu puteti executa decat comanda 'quit'.

Dupa ce va logati veti putea utiliza urmatoarele comenzi:

- 'myfind fisier' (aceasta va cauta recurstiv toate fisierele ce contin in nume substringul 'fisier' si va afisa cale, data modificare, creare, permisiuni
- 'mystat fisier' (acesta va cauta in directorul curent fisierul si va afisa nume, dimensiune, data motificare, create, I-node, etc)
- orice instructiune cu numar variabil de argumente (nu functioneaza instructiunile inlantuite prin pipes), cum ar fi


        -> ls -l -a
        -> cat fisier
        -> pwd
        -> users
        -> ps
        -> rm fisier
        -> mkdir numedir
        -> etc

- instructiunea 'quit' functioneaza doar dupa ce va delogati cu instructiunea 'logout'

## Date legate de implementare
Comunicarea se va face in felul urmator:

1. Parintele va citi din consola.
2. Acesta va trimite mai departe comanda SpawnerChild-ului prefixata de dimensiunea sa in bytes.
3. SC o preia si o va trimite in mod similar unui Copil facut de el.
4. Copilul o va procesa.
5. Acesta va trimite rezultatul SC-ului.
6. Acesta va calcula dimensiunea raspunsul.
7. Il va trimite Parintelui prefixat de dimensiunea sa in bytes.
8. Parintele preia dimensiunea, apoi rezultatul.
9. El poate modifica starea 'conectat' daca este cazul, poate face quit daca i se cere si conectat=false, poate afisa pur si simplu rezultatul prefixat de dimensiunea sa in bytes.

Comunicarea este implementata in totalitate prin cele 3 cai de comunicare studiate: pipes, mkfifo, sockets.

Fiecare implementata este gasita in headerele pipe.h, mkfifo.h, respectiv socket.h.


## Alte detalii
Schema tastatura->P->SC->C->SC->P->ecran

Am utilizat aceasta schema pentru a putea calculza dimensiunea in bytes a raspunsului.
Copilul cand face exec returneaza direct si nu poate transmite si dimensiunea raspunsului. Pentru a rezolva acest lucru, am introdus un SC care este intermediar.
