Hochschule Karlsruhe - Technik und Wirtschaft Stand: 26. Oktober 2018
Fakult ̈at f ̈ur Informatik und Wirtschaftsinformatik WS 18/
Prof. Dr.-Ing. Astrid Laubenheimer

```
CVLab - Labor zur Vorlesung Computer Vision
Aufgabenblatt 2 - Punktoperationen
```
Verwenden Sie zur L ̈osung der Aufgaben Ihre Bildklasse vom letzten Aufgabenblatt.

Achten Sie auf Effizienz im Sinne der Laufzeit (vermeiden Sie unn ̈otige Speicher-Allokationen,
Variablendeklarationen und Rechenoperationen insb. innerhalb von Schleifen etc.)!

Aufgabe 2.1Punktoperationen und Histogramme. Vervollst ̈andigen Sie die KlasseCMyImage
um die R ̈umpfe folgender Memberfunktionen:

```
a)void MakeBinary(int thresh): In dieser Funktion soll das Bild binarisiert werden.
Grauwerte, die kleiner oder gleich der Schwellethreshsind, sollen auf 0 gesetzt wer-
den und alle anderen auf 255.
b) void CalcHisto(CMyHisto& histo): In dieser Funktion soll das Histogramm des Bilds
erzeugt werden.
c)double CalcThreshByOtsu(): In der Funktion soll eine Schwelle zur Binarisierung nach
Otsu berechnet werden.
d) TestenSie die Funktionen dieser Aufgabe mit allen zur Verfugung gestellten Bildern. ̈
e)Freiwillige Zusatzaufgabe:Erweitern Sie Ihre Funktion zur Berechnung der Schwelle
nach Otsu um die Berechnung der Trennbarkeit nach Otsu. In welchem Testbild lassen
sich Vorder- und Hintergrund am besten (im Sinne von Otsu) trennen?
```
Aufgabe 2.2Freiwillige Zusatzaufgabe als Anregung zur Weiterarbeit zu Hause

```
a) Lesen Sie Abschnitt 3.3 aus dem Buch
”
Digital Image Processing“ von Gonzalez und
Woods bis einschließlich Abschnitt 3.3.2.
b) Implementieren Sie ein Histogramm-Matching nach Gonzalez und Woods.
```
## 1


