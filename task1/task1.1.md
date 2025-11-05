# Betriebssysteme WiSe 2025/26 Übungsblatt 1

## Aufgabe 1-1 (Architekturen)

Vorhandene Betriebssystementwürfen können grob in zwei Klassen eingeteilt werden:
- die Makrokernarchitektur,
- die Mikrokernarchitektur.


Diskutieren Sie beide Architekturansätze unter Zuhilfenahme mindestens folgender Quellen:
- J. Liedtke, Toward real µ-kernels, Communications of the ACM, 39(9):70--77,
  September 1996,
  https://citeseerx.ist.psu.edu/pdf/64f7ffba964343a3fc91f870672459b619988d6c
- C. Maeda, B.N. Bershad, Networking performance for microkernels, Proceedings of
  Third Workshop on Workstation Operating Systems, 13:154 – 159, April 1992
  https://citeseerx.ist.psu.edu/pdf/4d5811e818391a007616b1ae881b1738d643e630

Betriebssysteme können in die beiden Architekturansätze Makrokernel (bzw. monolithische Kernel) und Microkernel (µ-Kernel) unterteilt werden.

## Makrokernel

Bei einem Makrokernel ist der Großteil der Betriebssystemfunktionen im Kernel selbst integriert. Dazu gehören neben den grundlegenden Mechanismen wie Scheduling, Speicherverwaltung und Interrupt Handling auch höhere Dienste.  

## Microkernel

Der Microkernel-Ansatz verfolgt das Ziel, den Kernel möglichst klein zu halten. Jochen Liedtke beschreibt in *“Toward Real µ-Kernels”* (1996), dass der Kernel nur das beinhalten sollte, was "mandatory and common to all other software" ist. Dazu gehören also Dinge wie Prozess-Scheduling, virtuellen Speicher und Interprozesskommunikation (IPC).  
Andere Komponenten – etwa Dateisysteme, Netzwerke oder Gerätetreiber – laufen als User-Level-Server außerhalb des Kernels.

Der Nachteil ist, dass durch den häufigeren Wechsel zwischen Kernelspace und Userspace zusätzliche Latenzen entstehen können.

## Was machen beide Paper?

Liedtke argumentiert in seinem Paper, dass die schlechte Performance früherer Mikrokernel nicht durch das Konzept selbst, sondern durch ineffiziente Implementierungen verursacht wurde. Er zeigt dass durch eine weiterentwicklung mit dem "Second-Generation µ-Kernel" eine vergleichbare Performance zu monolithischen Systemen erreichbar ist.

Maeda und Bershad untersuchten in *“Networking Performance for Microkernels”* (1992), ob Netzwerkdienste auf User-Level trotzdem effizient sein können. Sie kamen zu dem Ergebnis, dass gut implementierte User-Level-Server nahezu die gleiche Performance wie Kernel-Implementierungen erreichen können.
