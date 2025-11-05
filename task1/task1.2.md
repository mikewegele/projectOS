# Aufgabe 1–2 (myPrintf)

## Schritte zur Ausführung

```bash
  ssh andorra
```
```bash
  cd task1
  export LD_LIBRARY_PATH=/home/mi/linnert/arm/lib:$LD_LIBRARY_PATH   # sonst libmpfr.so.4 Fehler
```
```bash 
  make clean
```
```bash
  make
```
```bash
  make run
```

## Benutzte Hilfsmittel

- Dokumentation: AT91RM9200.pdf
- Quellcode für Adressen der DBGU: 
  [https://code.videolan.org/Courmisch/u-boot/-/blob/ac6dbb85b7f080d923013bff4e1d5267cb6f8a5a/include/AT91RM9200.h](https://code.videolan.org/Courmisch/u-boot/-/blob/ac6dbb85b7f080d923013bff4e1d5267cb6f8a5a/include/AT91RM9200.h)
- ChatGPT: vor allem genutzt für Befehle und Schritte zum Kompilieren in der Andorra Umgebung, da dies vom Kosten-Nutzen-Verhältnis am besten war die nötigen Commands zu generieren.

## Herausforderungen

- Gruppenarbeit: Durch den Ausstieg von Leon habe ich die Aufgabe alleine weitergeführt.
- Technische Hürden:
   - Die Hex-Ausgabe konnte nicht umgesetzt werden. Vermutlich müsste man dafür einen zusätzlichen Wrapper schreiben, um die Ausgabe umzusetzbar zu machen.

