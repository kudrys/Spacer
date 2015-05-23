# Spacer
Po gorach

Spacer po górach

Celem zadania jest znalezienie najkrótszej trasy przez dany teren. Teren podzielony jest na pola. Każde pole ma pewną wysokość, wyrażoną nieujemną liczbą całkowitą. Przejście na pole o wysokości A z pola o wysokości B zajmuje:
A - B + 1 minut, jeżeli A > B,
1 minutę, jeżeli A ≤ B.
Możemy przechodzić tylko na pola sąsiadujące ze sobą jednym z boków, czyli z danego pola możemy przejść na co najwyżej cztery sąsiednie. Nie możemy opuścić terenu opisanego przez mapę.

W obszarze może znajdować się pewna liczba wyciągów. Wyciąg umożliwia dotarcie z jego punktu startowego wyciągu do punktu docelowego wyciągu (jest jednokierunkowy). Skorzystanie z wyciągu zajmuje pewną liczbę minut. Dodatkowo, wyciągi kursują w określonych minutach -- jeżeli znajdujemy się w polu startowym wyciągu w minucie 8 i wiemy, że punktem docelowym wyciągu jest (12, 12), kursuje on co 5 minut i skorzystanie z niego zajmuje 3 minuty, to w punkcie (12, 12) będziemy w 13 minucie (13 = 8 + 2 + 3; 2 minuty oczekiwania plus trzy minuty jazdy).

Rozwiązanie zadania nie wymaga korzystania z liczb przekraczających zakres typu int.
Wejście

Na wejściu podane będą kolejno:
szerokość i wysokość mapy
pozycja startowa (kolumna i wiersz)
pozycja docelowa (kolumna i wiersz)
liczba wyciągów
opis wyciągów – dla każdego wyciągu kolejno:
pozycja startowa (kolumna i wiersz),
pozycja docelowa (kolumna i wiersz),
czas trwania podróży w minutach,
minuty odjazdu – z wyciągu można skorzystać w minutach będących wielokrotnością tej wartości,
wysokości kolejnych pól mapy.
Wszystkie wartości są nieujemne.
Wyjście

Na wyjście należy wypisać najkrótszy czas, jaki potrzebny jest na dotarcie z punktu startowego do punktu docelowego.
Przykład

Wejście
9 8 0 0 8 7 0
0 0 0 0 0 0 0 0 8 
0 9 9 9 9 9 9 9 0 
0 1 0 1 0 0 0 9 0 
0 9 0 0 0 1 0 9 0 
0 9 1 1 1 1 0 9 0 
0 9 0 0 0 0 0 9 0 
0 9 9 9 9 1 9 9 0 
8 0 0 0 0 0 0 0 0 


Wyjście
18

Wejście
9 9 0 0 8 8 5
0 1 2 0 5 2
0 1 2 0 1 3
2 0 4 0 3 7
4 1 8 8 20 11
4 2 8 8 10 12
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0
0 9 0 9 0 9 0 9 0

Wyjście
22
Komentarz do drugiego testu:
Robimy krok w dół (1 minuta). Tu mamy do dyspozycji dwa wyciągi, jeden odchodzi co 2 minuty, drugi co 3. Wybieramy ten drugi, i choć czekamy dłużej (2 minuty), do w (2, 0) będziemy szybciej – w 4. minucie. Tu czekamy kolejne 3 minuty na wyciąg do (4, 0) i docieramy tam w 10. minucie. Robimy dwa kroki w dół do (4, 2). Docieramy tam w 12 minucie, wsiadamy do wyciągu i w (8, 8) jesteśmy po 22 minutach.
Testy

Tutaj.
Numeracja jest przesunięta o jeden w stosunku do tego, co jest prezentowane przez system. Testy 0-10 – poprawnościowe (50%). Testy 11-15 – wydajnościowe (30%). Testy 16-19 – obsługa wyciągów (20%). 

