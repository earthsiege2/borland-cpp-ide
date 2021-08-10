Funktion CalcTest()
  Bei Fehler Weiter Nächste
  Setze Calc = HoleObjekt(Klasse:="OCCalc.Application")
  Created = FehlerNr
  Wenn FehlerNr Dann Setze Calc = ErstelleObjekt("OCCalc.Application")
  Bei Fehler GeheZu 0
  Mit Calc
    .Operand = 123
    .Op = "Ergeben"
    .Auswerten
    .Operand = 333
    .Op = "Addieren"
    .Auswerten
    .Fenster.Farbe = 123456
    .Anzeigen
    .Schalter Taste:="+10000+200000="
    .Fenster.Titel = Jetzt()
     CalcTest = Calc
    Test.Drucke CalcTest
    Test.Drucke .Matrix.Anzahl
    Für Alle Item In .Matrix
      Test.Drucke Item;
      Nächste Item
    Test.Drucke
    Test.Drucke .Fenster.Schalter.Anzahl
    Für Alle Button In .Fenster.Schalter
      Save = Button.Text
      Button.Aktivieren = Wahr
      Für i = 1 Bis 24
        j = (i Mod 4) Und (24 - i)
        Wenn ((i Mod 8) < 4) Dann
          Button.Text = Save & LZn(j)
        Sonst
          Button.Text = LZn(j) & Save
        Ende Wenn
      Nächste i
      Button.Aktivieren = Falsch
    Nächste Button
    .Akkumulator = .UntersucheFenster(Fenster:=.Fenster)
    .Anzeigen
    .Fenster.Farbe = RGB(255; 255; 0)
    Wenn Created Dann .Beenden
  Ende Mit
Ende Funktion
