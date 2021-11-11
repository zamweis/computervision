Hochschule Karlsruhe - Technik und Wirtschaft Stand: 17. November 2017

Fakult ̈at f ̈ur Informatik und Wirtschaftsinformatik WS 17/

Prof. Dr.-Ing. Astrid Laubenheimer


### CVLab - Labor zur Vorlesung Computer Vision


## Aufgabenblatt 4 - Differenz- und RGB-Farbbilder


Zur Lösung der Aufgaben steht ein Framework (Visual Studio 2012) und ein Archiv mit
Bildmaterial zur Verfugung. Das Framework enthält eine Teilimplementierung einer Elternklasse CMyTypeImage und wieder eine Klasse CMyHisto. Die Klasse CMyTypeImage ist eine
template-Klasse, sodass die Klasse fur verschiedene Datentypen verwendet werden kann. Von ¨
der Klasse sind Ausprägungen fur die Datentypen ¨ unsigned char, float und int abgeleitet.


![class uml](class.png?raw=true "Class UML")


Zum Lesen und Schreiben von Bildern benötigen Sie die Klassen CMyCharImage und
CMyTypeImage. Die Klasse CMyCharImage verfugt ¨ uber Lese- und Schreibfunktionen, die für
Grauwerbilder (ein Kanal) und Farbbilder (drei Kanäle) implementiert sind.

##### Beachten Sie die Kommentare uber den bereits bestehenden Funktionsdeklarationen im Header

#### Aufgabe 4.1 Filteroperationen.

a) Vorbereitung: Implementieren Sie die Funktion CMyTypeImage< T >::CopyChannel(),
mit der aus einem mehrkan¨aligen Bild ein einzelner Kanal in ein neues Bild kopiert
werden kann, so dass Sie die Kan¨ale separat bearbeiten, abspeichern und betrachten
können.

b) Implementieren Sie eine Funktion CMyCharImage::ApplyMeanFilter(const
CMyCharImage& sourceImage), die einen 5x5-Mittelwertfilter auf ein einkan¨aliges
Bild sourceImage anwendet (wenn das Bild mehr Kan¨ale hat, kann false zuruck ¨
gegeben werden). Implementieren Sie den Filter separiert, also mit einer Instanz
CMyIntImage als Zwischenergebnis.

c) Freiwillige Zusatzaufgabe: Implementieren Sie den Filter auch fur Bilder mit mehr ¨
als einem Kanal.

## Aufgabe 4.2 Farbbildsegmentierung im RGB-Raum.

a) Implementieren Sie den Rumpf der Memberfunktion CMyCharImage::ApplyThresh().
Die Funktion soll die ubergebene Schwelle auf den als Parameter ¨ ubergebenen Kanal ¨
anwenden. Das Ergebnisbild soll nur einen Kanal besitzen und nur die Werte 0 und 255
enthalten.

b) Experimentieren Sie mit dem Bild Rose.bmp und versuchen Sie einen geeigneten Kanal
und eine geeignete Schwelle zu finden, um die Rose vom Hintergrund zu trennen.
