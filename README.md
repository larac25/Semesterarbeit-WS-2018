# Semesterarbeit-WS-2018
Semesterarbeit für den Kurs C++ Programmieren 1

05.04.2018:

Schriftliche Beschreibung der Semesterarbeit — C++

In der vorliegenden Arbeit wurde Stufe 1 der Semesterarbeit erfolgreich umgesetzt und Stufe 2 teilweise umgesetzt. Ich habe als konkreten Anwendungsfall einen Modekatalog gewählt. Es gibt eine dtd-Datei, eine xml-Datei und eine txt-Datei.
In der xml-Datei sind verschiedene Artikel aufgeführt. Jeder Artikel hat eine ID (als Attribut), sowie mehrere Kind-Elemente (Kategorie, Name, Farbe, Preis).
Die txt-Datei enthält Metadaten zu den einzelnen Artikeln. Man erhält dort Informationen über den Lagerbestand und die Größe des Kleidungsstücks.
Mein Programm enthält eine Menüführung mit verschiedenen Optionen. Man kann sich die txt-Datei ausgeben lassen. Außerdem kann man sich die xml-Datei ausgeben lassen. Und entsprechend den Anforderungen von Stufe 1, kann man die Daten beider Dateien (xml und txt) in eine gemeinsame xml-Datei konvertieren. Das Programm steht danach weiterhin zur Verfügung und wird erst beendet, wenn man die Option „exit“ wählt.
Außerdem gibt es noch die Option „help“. Es wird dann ein kurzer beschreibender Text zum Programm ausgegeben.
Eine weitere Option ist „suchen“. Diese Funktionalität gehört bereits zu Stufe 2. Ich konnte sie jedoch leider nicht ganz fertigstellen, sodass sie nur teilweise funktioniert. Das Programm lässt sich aber einwandfrei ausführen.

Mein Projekt ist in verschiedene Header und Quelldateien aufgeteilt. In der main.cpp befindet sich lediglich das Menü des Programms. Der txt-Parser besteht aus dem txt.h (Header) und der textlib.cpp (Quelldatei). Den Parser habe ich mit einem switch case umgesetzt. Dieser switch case ist in der parsetxt-Methode enthalten. Dazu gibt es noch eine druckeTxt-Methode. Den txt-Parser habe ich komplett eigenständig entwickelt.
Der xml-Parser ist etwas komplexer. Ich habe dabei den Parser aus der Vorlesung (Beispiel 10, Sitzung ??) als Grundlage genommen. Anschließend habe ich ihn erweitert und angepasst. Dazu gehört att.h (Attribute Header), attlib.cpp (Attribute Quelldatei), token.h (Token Header) und tokenlib.cpp (Token Quelldatei).
Zum konvertieren der Daten habe ich die druckeToken Methode implementiert. Diese verbindet die txt-Daten mit den xml-Daten und schreibt sie in eine neue Datei.
Außerdem habe ich eine suche Methode definiert. Diese benutze ich, um dem User eine Suche zu ermöglichen. Der eingegeben Suchbegriff wird von einem string in ein char array umgewandelt und anschließend mit dem Inhalt von Token durch ein strcmp verglichen. Leider konnte ich diese Funktionalität nicht mehr ganz aussahbeiten, sodass zwar die richtigen Tags ausgeben werden, jedoch nicht der ganze Datensatz zu dem gesuchten Artikel.

Zum besseren Verständnis und zum Nachvollziehen meiner einzelnen Schritte ist mein Code mit Kommentaren versehen.

------------------------------------------------------------------------------------------------------------------------------------------

21.01.2018
Projektidee:
In meinem Anwendungsfall handelt es sich um einen Lagerbestand von einem Modegeschäft. Das Geschäft verkauft unterschiedliche Produkte, zum Beispiel Kleider, Hosen und Oberteile. In meiner dtd Datei habe ich festgelegt, dass ein Artikel jeweils eine ID, eine Kategorie, einen Namen, eine Farbe und einen Preis enthält. So konnte ich in der xml Datei dann aufschreiben, dass es zum Beispiel einen Artikel mit der ID 100 gibt. Dieser hat die Kategorie „Oberteile“ und den Namen „T- shirt“. Außerdem die Farbe „rot“ und den Preis „15.00“. Nach diesem Schema habe ich eine Liste mit verschiedenen Produkten erstellt.
Meine txt Datei habe ich dann so aufgebaut, dass daraus ersichtlich werden kann, welchen Artikel es in welcher Größe (34, 36, 38) noch wie oft im Lager gibt. Es sollte also möglich werden, dass nach einem Artikel gesucht werden kann und geprüft werden kann, wie oft dieser noch in den jeweiligen Konfektionsgrößen vorhanden ist. Im weiteren Verlauf sollte das Programm dann auch einfache Rechnungen durchführen können. Zum Beispiel anzeigen, wie viele Artikel einer Kategorie insgesamt im Lager sind, oder wie viele Artikel es in einer bestimmten Konfektionsgröße gibt.
