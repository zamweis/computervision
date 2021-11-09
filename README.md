Hochschule Karlsruhe - Technik und Wirtschaft Stand: 19. Oktober 2018
Fakult ̈at f ̈ur Informatik und Wirtschaftsinformatik WS 18/
Prof. Dr.-Ing. Astrid Laubenheimer

```
CVLab - Labor zur Vorlesung Computer Vision
Aufgabenblatt 1 - Digitale Bilder
```
Zur L ̈osung der Aufgaben steht ein Framework (Visual Studio 2010 und 2012) und ein Ar-
chiv mit Bildmaterial zur Verf ̈ugung. Das Framework enth ̈alt eine Teilimplementierung einer
KlasseCMyImageund eine KlasseCMyHisto. Die ̈ubrigen Dateien enthalten Hilfsfunktionen
f ̈ur die Ein- und Ausgabe von Bildmaterial.

Die KlasseCMyImageist eine Implementierung f ̈ur 8-Bit Grauwertbilder und verf ̈ugt ̈uber eine
Lese- und eine Schreibfunktion f ̈ur das Windows-Bitmap-Formatbmp. Beachten Sie, dass die
Lese- und Schreibfunktionnur f ̈ur Grauwertbilderimplementiert sind.

Aufgabe 1.1Digitale Bilder.Vervollst ̈andigen Sie die KlasseCMyImageum die Rumpfe ̈
folgender Memberfunktionen:

```
a)void Resize(int width, int height): In der FunktionResizesoll mitmallocoder
callocSpeicher fur die Bildgr ̈ ̈oßewidthmalheightallokiert werden. Alle Pixel sollen
mit dem Wert 0 initialisiert werden. F ̈ur den Fall, dass kein Speicher ben ̈otigt wird (width
* height = 0) soll der ZeigermpDataaufNULLgesetzt werden.
```
```
b) bool IsEmpty(): Geben Sietruezur ̈uck, wennmpData == NULList.
```
```
c)void Copy(const CMyImage& toCopy): Kopieren Sie das Bild toCopyunter Verwen-
dung von Ihrer Resize-Funktion undmemcpy.
```
```
d) void SetPixel()undunsigned char GetPixel(): Setter und Getter f ̈ur die Grauwer-
te einzelner Pixel. Zugriff auf einzelne Pixel an der Positionposmit
```
```
mpData[pos]
```
```
oder
∗(mpData+pos)
```
Aufgabe 1.2Pr ̈asenz- oder Hausaufgabe:Vergleichen Sie die ben ̈otigte Rechenzeit zur
Invertierung eines großen Bilds (z.B.Kap.bmp) mit der Punktoperation

```
f(q) = 255−q,
```
wenn a)SetPixel()undGetPixel()verwendet werden mit b) dem direkten Zugriff via
Pointer (siehe Tafel).

1. Zeit mit Setter und Getter:
2. Zeit mit direktem Zugriff:
3. Faktor:

Die Zeitmessung k ̈onnen Sie wie folgt realisieren:
#include <time.h>
clockt start, finish;
start = clock();

// do something

finish = clock();
double myTimeInSec = (double)(finish - start) / CLOCKSPERSEC;

## 1


