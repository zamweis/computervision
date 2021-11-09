Hochschule Karlsruhe - Technik und Wirtschaft Stand: 28. April 2017
Fakult ̈at f ̈ur Informatik und Wirtschaftsinformatik SS 17
Prof. Dr.-Ing. Astrid Laubenheimer

```
CVLab - Labor zur Vorlesung Computer Vision
Aufgabenblatt 3 - Filtertechniken
```
Verwenden Sie zur L ̈osung der Aufgaben Ihre Bildklasse vom letzten Aufgabenblatt. Legen
Sie zus ̈atzlich die DateiQuickSort.cppin das Projektverzeichnis und f ̈ugen Sie die Datei dem
Projekt hinzu. Als Testmaterial stehen Ihnen weitere Bilder unterBildmaterialFilter.zip
zur Verf ̈ugung.

Aufgabe 3.1Gl ̈attungsfilter.

```
a) Implementieren Sie eine Memberfunktion CMyImage::MeanFilter(const CMyImage&
source, int sizeX = 3, int sizeY = 3), die einen Mittelwertfilter der Gr ̈oßesizeX
xsizeYauf das als Parameter ̈ubergebene Bild anwendet. Greifen Sie dabei direkt auf
den Speicher zu (ohne Getter-Funktion) und vermeiden Sie jede unn ̈otige Rechenopera-
tionen innerhalb von Schleifen.
```
```
b) Testen Sie die Funktion f ̈ur die Bilder FlowerNoise.bmp und
FlowerSaltAndPepper.bmp.
```
```
c) Implementieren Sie eine MemberfunktionCMyImage::MedianFilter(const CMyImage&
source, int sizeX = 3, int sizeY = 3), die einen Medianfilter der Gr ̈oßesizeXx
sizeYauf das als Parameter ̈ubergebene Bild anwendet.
```
```
d) Vergleichen Sie die Ergebnisse mit denen des Mittelwertfilters an Hand der Bilder
FlowerNoise.bmpundFlowerSaltAndPepper.bmp.
```
```
e) Vergleichen Sie die Laufzeit der beiden Funktionen, ggf. durch mehrfache Anwendung
und mit verschiedenen Filtergr ̈oßen. Die Zeitmessung k ̈onnen Sie realisieren, wie auf
dem ersten Aufgabenblatt beschrieben.
```
```
f) Freiwillige Zusatzaufgabe:Implementieren Sie eine weitere Variante des Mittelwert-
filters f ̈ur die Gr ̈oße 3x3, indem Sie mit drei Zeigern arbeiten:
```
```
const unsigned char∗ p1 = s o u r c e. GetData ( ) ;
const unsigned char∗ p2 = p1 + mwidth ;
const unsigned char∗ p3 = p2 + mwidth ;
unsigned char∗ pDest = mpData + mwidth + 1 ;
//....
f o r (i n t i = 0 ; i < noRowsToProcess ; i ++)
{
```
.... =.... / 9. 0 ;
∗pDest =.... ;
}

```
g)Freiwillige Zusatzaufgabe:Optimieren Sie die Berechnung weiter in einer neuen Funk-
tion wie folgt: Berechnen Sie zun ̈achst die Summen zeilenweise fur das ganze Bild und ̈
speichern das Ergebnis in einen Zwischenspeicher. Berechnen Sie daraus spaltenweise die
gesuchten Mittelwerte und tragen Sie diese dann in das endg ̈ultige Ergebnisbild ein.
```
Aufgabe 3.2Freiwillige Zusatzaufgabe:Mittelwert-Differenz-Filter.

```
a) Implementieren Sie eine Funktion zur Berechnung des Gradientenbetragsbilds mit Hilfe
der Mittelwert-Differenz-Filter in x- und y-Richtung.
```
## 1


