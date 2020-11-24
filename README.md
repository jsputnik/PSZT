# Algorytm genetyczny

# Treść zadania
MM.AG3 Podział kart na 2 stosy
Masz N kart z wartościami od 1 do N. Przy pomocy algorytmu genetycznego należy podzielić je na dwa stosy, gdzie suma wartości kart na pierwszym stosie ma wartość jak najbliższą do A, a iloczyn wartości kart na drugim stosie jak najbliższa wartości B. WE: liczba kart N, suma kart A, iloczyn kart B, satysfakcjonujący poziom dopasowania w %. WY: podział kart na stosy z wynikami działań.

# Ocena przystosowania
Max (dopasowanie A, dopasowanie B)\
Dopasowanie A = |aspiracjaA - sumaA| / aspiracjaA\
Dopasowanie B = |aspiracjaB - iloczynB| / aspiracjaB

# Zastosowane selekcje:
- losowa
- turniejowa

# Zastosowane krzyżowania
-	Jednopunktowe z tym samym punktem krzyżowania dla wszystkich osobników
- Jednopunktowe z losowym punktem krzyżowania dla każdej krzyżowanej pary
- Dwupunktowe z tymi samymi punktami krzyżowania dla wszystkich osobników
- Dwupunktowe z losowymi punktami krzyżowania dla każdej krzyżowanej pary

# Zastosowana sukcesja
- generacyjna

# Domyślne ustawienia
Domyślnie są ustawione:
- selekcja turniejowa
- krzyżowanie dwupunktowe z losowymi punktami krzyżowania dla każdej krzyżowanej pary\
\
Ewentualnych zmian selekcji/krzyżowań należy dokonywac w kodzie


