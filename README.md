# 2-oji-uzduotis
Testavimas

Testavimo sistemos parametrai:

1. CPU: Apple M4
2. RAM: 16GB
3. HDD: SSD

3 strategijos spartos analizė su vektoriais lyginant struct ir class:
 | Failo dydis | *struct* | *class* |
  |:---|:-------------:|:-------------:|
  | *1000*     | 0.0007 s | 0.0001 s |
  | *10000*    | 0.0058 s | 0.0004 s |
  | *100000*   | 0.2722 s | 0.0443 s | 
  | *1000000*  | 0.2749 s | 0.0427 s | 
  | *10000000* | 3.2691 s | 0.4789 s |

Flag analizė, vector, 3 strategija


CLASS
| Failo dydis | *1000000* | *10000000* |
  |:---|:-------------:|:-------------:|
  | *01*  | 0.0101 s | 0.3008 s | 
  | *02* | 0.0147 s | 0.2750 s |
  | *03* | 0.0225 s | 0.3221 s |

  STRUCT
  | Failo dydis | *1000000* | *10000000* |
  |:---|:-------------:|:-------------:|
  | *01*  | 0.0845 s | 1.3286 s | 
  | *02* | 0.0743 s | 1.4800 s |
  | *03* | 0.0756 s | 1.4270 s |
