# 2-oji-uzduotis
Testavimas

Testavimo sistemos parametrai:

1. CPU: Apple M4
2. RAM: 16GB
3. HDD: SSD

3 strategijos spartos analizė su vektoriais lyginant struct ir class:
 | Failo dydis | *struct* | *class* |
  |:---|:-------------:|:-------------:|:-------------:|
  | *1000*     | 0.0007 s | 0.0001 s |
  | *10000*    | 0.0058 s | 0.0004 s |
  | *100000*   | 0.2722 s | 0.0443 s | 
  | *1000000*  | 0.2749 s | 0.0427 s | 
  | *10000000* | 3.2691 s | 0.4789 s |

Flag analizė
  01: Vector strategija 3: 0.2982 s
  02: Vector strategija 3: 0.3025 s
  03: Vector strategija 3: 0.2887 s
